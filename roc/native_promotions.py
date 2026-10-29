"""Quarantined declaration/build-unit packets; only host review queues authoritative verification."""
import json
import re
import time
import uuid
from pathlib import Path

from roc import integration


def validate(packet, root, baseline):
    if not isinstance(packet, dict) or packet.get('client') != '2008-06':
        raise ValueError('Declaration packet must name native client 2008-06')
    if packet.get('base_revision') != baseline['revision']:
        raise ValueError('Declaration packet baseline changed; rebase evidence first')
    if not isinstance(packet.get('model'), str) or not 1 <= len(packet['model']) <= 120:
        raise ValueError('Actual writer model required')
    if not isinstance(packet.get('evidence'), str) or len(packet['evidence']) < 20:
        raise ValueError('RTTI/allocation/source/ABI evidence notes required')
    targets = packet.get('targets')
    known = {r['addr'] for r in json.loads((root/'rebuild/2008-06/manifests/functions.json').read_text()) if r.get('score') == 100}
    if not isinstance(targets, list) or not targets or not set(targets) <= known:
        raise ValueError('Packet needs known exact-mined target witnesses')
    types = packet.get('declarations', [])
    if not isinstance(types, list):
        raise ValueError('Declarations must be a list')
    abi_path = root/'rebuild/2008-06/manifests/abi-evidence.json'
    abi = json.loads(abi_path.read_text()) if abi_path.exists() else {}
    for row in types:
        if not isinstance(row, dict) or not re.fullmatch(r'RBX::(?:\w+::)*\w+', row.get('name', '')):
            raise ValueError('Declaration needs a real RBX type name')
        sizes = {int(s, 16) for s in abi.get(row['name'], {}).get('alloc_sizes', {})}
        if type(row.get('size')) is not int or row['size'] <= 0 or sizes and sizes != {row['size']}:
            raise ValueError('Missing or conflicting binary allocation evidence for ' + row['name'])
        if not sizes:
            # Embedded/non-allocated types need owner-reviewed native instructions, not a made-up allocation.
            from roc import match
            sites = row.get('binary_sites')
            if not isinstance(sites, list) or not sites or not row.get('size_derivation'):
                raise ValueError('Embedded type needs binary instruction sites and size derivation: '+row['name'])
            base, image = match._image('2008-06')
            for site in sites:
                if not re.fullmatch('[0-9a-fA-F]{8}', site.get('address', '')) or not re.fullmatch('[0-9a-fA-F]{16,512}', site.get('bytes', '')):
                    raise ValueError('Invalid ABI instruction witness')
                expected = bytes.fromhex(site['bytes'])
                offset = int(site['address'], 16)-base
                if offset < 0 or bytes(image[offset:offset+len(expected)]) != expected:
                    raise ValueError('ABI instruction witness does not match installed client')
        if (not row.get('evidence') or not isinstance(row.get('header'), str)
                or not row['header'].startswith('App/include/') or not re.fullmatch(r'[A-Za-z0-9_./-]+', row['header'])):
            raise ValueError('Declaration header and evidence reference required')
    # This exception applies only to quarantined packet data and host-approved exact contents.
    integration.validate_patches(packet.get('patches'), [row['name'].split('::')[-1] for row in types])
    for row in types:
        if row['header'] not in packet['patches'] or not row['header'].endswith(('.h', '.hpp')):
            raise ValueError('Declaration header must be included in packet patches')
        definitions = '\n'.join(new for _, new in packet['patches'][row['header']])
        if not re.search(r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?' + re.escape(row['name'].split('::')[-1]) + r'\b', definitions):
            raise ValueError('Packet does not define its declared type')
    return packet


def receive(promotions, user, packet):
    validate(packet, promotions.root, promotions.baseline())
    key = integration.digest(packet)
    with promotions.store.lock, promotions.store.db as db:
        db.execute('INSERT OR IGNORE INTO integration_type_proposals VALUES(?,?,?,?,?,?)',
                   (key, user, json.dumps(packet), 'needs-owner-review', None, time.time()))
    integration.atomic_json(promotions.directory/'type-proposals'/(key+'.json'), dict(user=user, packet=packet))
    return dict(id=key, state='needs-owner-review', verified=False, credits=0)


def queue(promotions, identifier, reviewed_hash):
    """Local host command only. Reviewed bytes still pass all server code/data/runtime/ABI gates."""
    if not re.fullmatch('[0-9a-f]{64}', identifier) or reviewed_hash != identifier:
        raise ValueError('Review packet contents and supply its exact --reviewed-sha256')
    with promotions.store.lock:
        saved = promotions.store.db.execute('SELECT user,packet,state,job FROM integration_type_proposals WHERE id=?', (identifier,)).fetchone()
    if not saved:
        raise ValueError('Declaration packet not found')
    user, content, state, job = saved
    packet = json.loads(content)
    if integration.digest(packet) != reviewed_hash:
        raise ValueError('Declaration packet changed after review')
    validate(packet, promotions.root, promotions.baseline())
    with promotions.store.lock, promotions.store.db as db:
        db.execute('BEGIN IMMEDIATE')
        current = db.execute('SELECT job FROM integration_type_proposals WHERE id=?', (identifier,)).fetchone()[0]
        if current:
            status = db.execute('SELECT state FROM integration_jobs WHERE id=?', (current,)).fetchone()[0]
            if status == 'rejected':
                db.execute("UPDATE integration_jobs SET state='queued',phase='solo',updated=? WHERE id=?", (time.time(),current))
                db.execute("UPDATE integration_type_proposals SET state='queued' WHERE id=?", (identifier,))
                promotions.wake.set()
                return dict(id=current, state='queued', retry=True, verified=False)
            return dict(id=current, state='already-queued')
        job, now = uuid.uuid4().hex, time.time()
        db.execute('INSERT INTO integration_jobs VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)',
            (job, '[]', 'type-promotion:'+identifier, user, packet['model'],
             ', '.join(r['name'] for r in packet.get('declarations', [])) or 'Native build unit',
             packet['base_revision'], json.dumps(packet['patches']), 'TYPE-PROMOTION:'+identifier+'\n'+packet['evidence'],
             'queued', 'solo', now, now, '{}'))
        db.execute("UPDATE integration_type_proposals SET state='queued',job=? WHERE id=?", (job, identifier))
    promotions.wake.set()
    return dict(id=job, packet=identifier, state='queued', verified=False)


def check_result(promotions, job, result, dropped=(), candidate=None):
    if not job.get('evidence', '').startswith('TYPE-PROMOTION:'):
        return
    identifier = job['evidence'].splitlines()[0].split(':', 1)[1]
    with promotions.store.lock:
        saved = promotions.store.db.execute('SELECT packet,job FROM integration_type_proposals WHERE id=?', (identifier,)).fetchone()
    if not saved or saved[1] != job['id'] or dropped:
        raise ValueError('Declaration promotion lost its reviewed packet or a required patch')
    packet = json.loads(saved[0])
    if integration.digest(packet) != identifier:
        raise ValueError('Reviewed declaration packet hash mismatch')
    sizes = {r['class']: r for r in result['size']['rows']}
    for declaration in packet.get('declarations', []):
        row = sizes.get(declaration['name'].split('::')[-1])
        if row and (row['2008'] != declaration['size'] or row['rbxgs'] != declaration['size']):
            raise ValueError('Promoted declaration did not pass independent binary-derived sizeof gate')
        if not row and (candidate is None or not declaration.get('binary_sites')):
            raise ValueError('Promoted declaration needs an independent sizeof probe')
    if candidate is not None and packet.get('declarations'):
        probe_types(Path(candidate), packet['declarations'])
    if not set(packet['targets']) <= set(result['report']['owned_addrs']):
        raise ValueError('Promoted declaration did not reproduce every cited module witness')


def probe_types(candidate, declarations):
    """Compile sizeof assertions inside the immutable candidate with its actual native ABI settings."""
    from roc.integration_verify import run
    source = '#define private public\n#define protected public\n'
    source += ''.join('#include "%s"\n' % row['header'][len('App/include/'):] for row in declarations)
    source += ''.join('typedef char rocApprovedSize%d[(sizeof(%s)==%d)?1:-1];\n' % (i,row['name'],row['size'])
                      for i,row in enumerate(declarations))
    folder = candidate/'work/type-probe'
    folder.mkdir(parents=True, exist_ok=True)
    (folder/'probe.cpp').write_text(source)
    code = ("from pathlib import Path; from roc import libs,rebuild; "
            "r=libs.RECIPES['rbxgs']; tree,ov=rebuild.build_overlay('2008-06','RbxgsApp',rebuild.load_module('2008-06','rbxgs-app').get('overlay')); "
            "incs=[ov/'App/include',ov/'App',tree/'App/include',tree/'App']+[libs._case_path(libs.LIBS/p) for p in r.get('include',[]) if p!='WINSDK']; "
            "p=Path('work/type-probe/probe.cpp'); result=rebuild.compile_direct('2008-06',[p],p.parent,incs,r.get('defines',''),'/O2 /Ob2 /Oy /GF /GS- /EHsc /MD'); "
            "ok,msg=result[str(p)]; print(msg); raise SystemExit(0 if ok else 1)")
    run(candidate, ['-c', code], candidate/'integration-type-size.log')


def main(args):
    from roc import worker
    if args.action == 'submit':
        settings = worker.load_settings()
        packet = json.loads(Path(args.packet).read_text(encoding='utf-8-sig'))
        api = worker.Api(settings['server'], integration.native_token() or settings.get('token'))
        try:
            print(json.dumps(api.call('/v1/integration/type-proposals', dict(user=settings['user'], packet=packet)), indent=1))
        finally:
            api.close()
        return
    root = integration.ROOT
    if not (root/'work/server.db').is_file():
        raise ValueError('Owner review commands run only in the server checkout')
    from roc import server
    store = server.Store(root/'work/server.db', 1)
    promotions = integration.Promotions(store, root)
    try:
        if args.action == 'list':
            with store.lock:
                rows = store.db.execute('SELECT id,user,state,job FROM integration_type_proposals ORDER BY created').fetchall()
            print(json.dumps([dict(zip(('id','user','state','job'), row)) for row in rows], indent=1))
        elif args.action == 'inspect':
            with store.lock:
                row = store.db.execute('SELECT packet FROM integration_type_proposals WHERE id=?', (args.packet,)).fetchone()
            if not row:
                raise ValueError('Declaration packet not found')
            print(row[0])
        else:
            print(json.dumps(queue(promotions, args.packet, args.reviewed_sha256), indent=1))
    finally:
        store.db.close()


def register(cmd):
    cmd('native-promote', main, 'submit declaration/build-unit evidence packets; host inspect/queue only',
        (['action'], dict(choices=['submit','list','inspect','queue'])),
        (['packet'], dict(nargs='?')), (['--reviewed-sha256'], {}))
