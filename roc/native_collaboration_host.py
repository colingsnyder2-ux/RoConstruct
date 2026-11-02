"""Host-owned recovery catalog, fenced cross-PC leases and independent native-body rechecks."""
import json
import re
import threading
import time
import uuid
from pathlib import Path

from roc import integration, native_recovery as recovery, native_sweep as sweep, worker, native_methods

TTL = 120
SCHEMA = '''
CREATE TABLE IF NOT EXISTS native_method_leases(
 target TEXT PRIMARY KEY,id TEXT UNIQUE,user TEXT,worker TEXT,expires REAL,state TEXT,packet TEXT);
CREATE TABLE IF NOT EXISTS native_recovery_uploads(
 id TEXT PRIMARY KEY,lease TEXT UNIQUE,user TEXT,model TEXT,state TEXT,record TEXT,created REAL,receipt TEXT);
CREATE TABLE IF NOT EXISTS native_recovery_verified(target TEXT PRIMARY KEY,signature TEXT);
'''


def integration_busy(db, now):
    return {row[0] for row in db.execute(
        "SELECT j.value FROM integration_claims c,json_each(c.addresses) j "
        "WHERE c.client=? AND (c.state='submitted' OR (c.state='claimed' AND c.expires>?))",
        (integration.CLIENT,now))}


class Host:
    def __init__(self, promotions, start=False, server=None):
        self.server=server or worker.load_settings().get('server','http://127.0.0.1:8765')
        self.promotions=promotions
        self.root=promotions.root
        self.store=promotions.store
        self.directory=self.root/'work/native-recovery-server'
        self.catalog_lock=threading.Lock()
        self.cached=None
        self.cache_key=None
        self.wake=threading.Event()
        self.stop=threading.Event()
        with self.store.lock,self.store.db as db:
            db.executescript(SCHEMA)
            db.execute("UPDATE native_recovery_uploads SET state='queued' WHERE state='verifying'")
        if start:
            threading.Thread(target=self.loop,daemon=True).start()

    def catalog(self):
        with self.catalog_lock:
            for attempt in range(3):
                try:return self._catalog()
                except ValueError as error:
                    if not str(error).startswith('Native inputs changed') or attempt==2:raise

    def _catalog(self):
        manifest=self.root/'work/native-recovery/tasks.json'
        blocker_manifest=self.root/'work/native-recovery/blockers.json'
        inputs={str(p):[p.stat().st_size,p.stat().st_mtime_ns] for scope in recovery.SCOPES
                for p in (self.root/recovery.NATIVE/scope).rglob('*') if p.is_file() and p.suffix in ('.cpp','.h','.hpp','.inl')}
        for p in [* (self.root/recovery.NATIVE/'tests').glob('Native*.cpp'),
                  * (self.root/recovery.NATIVE/'tests').glob('record_native_*.py'),manifest,blocker_manifest,
                  self.root/recovery.NATIVE/'out/native-names.json',self.root/'work/2008-06/functions.jsonl']:
            if p.exists():inputs[str(p)]=[p.stat().st_size,p.stat().st_mtime_ns]
        canonical=self.promotions.source_root
        registry=self.promotions.overlay
        if registry.exists():inputs[str(registry)]=[registry.stat().st_size,registry.stat().st_mtime_ns]
        project_registry=self.root/'rebuild/2008-06/patches/rbxgs-client.json'
        if project_registry.exists():inputs[str(project_registry)]=[project_registry.stat().st_size,project_registry.stat().st_mtime_ns]
        key=integration.digest(inputs)
        if key!=self.cache_key:
            blockers=json.loads(blocker_manifest.read_text(encoding='utf-8')) if blocker_manifest.exists() else []
            if not isinstance(blockers,list) or len(blockers)>64:raise ValueError('Invalid native blocker manifest')
            for blocker in blockers:
                if not isinstance(blocker,dict) or set(blocker)!={'class_name','status','reason','evidence'} or \
                        any(not isinstance(value,str) for value in blocker.values()) or \
                        not re.fullmatch(r'[A-Za-z_]\w*(?:::\w+)*',blocker['class_name']) or \
                        blocker['status'] not in ('needs-layout-owner','needs-linkage','needs-codegen','needs-evidence') or \
                        not 1<=len(blocker['reason'])<=2000 or \
                        not re.fullmatch(r'work/[\w./-]+\.json',blocker['evidence']) or '..' in Path(blocker['evidence']).parts:
                    raise ValueError('Invalid native blocker record')
            files={Path(p).relative_to(self.root).as_posix():Path(p).read_text(encoding='utf-8-sig')
                   for p in inputs if Path(p).suffix in ('.cpp','.h','.hpp','.inl')}
            names_path=self.root/recovery.NATIVE/'out/native-names.json'
            names=json.loads(names_path.read_text()) if names_path.exists() else {}
            texts={p:t for p,t in files.items() if '/tests/' not in p and '/native-classes/accepted/' not in p}
            tasks=recovery.nominations(self.root,texts,names)
            patches=json.loads(registry.read_text(encoding='utf-8')) if registry.exists() else {}
            canonical_headers={rel:integration.overlay_text(canonical/'tools/rbxgs/Client',rel,patches,workspace=canonical)
                               for rel in patches if Path(rel).suffix in ('.h','.hpp','.inl')}
            canonical_revision=integration.digest(canonical_headers)
            if manifest.exists():
                extra=json.loads(manifest.read_text(encoding='utf-8'))
                if not isinstance(extra,list):raise ValueError('Host task manifest must be a list')
                from roc.native_collaboration import seed_missing
                for task in extra:
                    if task.get('include_profile')!='accepted':continue
                    name=task.get('canonical_file','')
                    if not re.fullmatch(r'App/[\w-]+/[\w-]+\.cpp',name) or Path(name).name.startswith('roc_'):
                        raise ValueError('Accepted recovery needs a genuine canonical C++ unit')
                    rel=(recovery.NATIVE/'native-classes/accepted'/name).as_posix()
                    if task.get('file')!=rel:raise ValueError('Accepted recovery source path differs from canonical unit')
                    text=integration.overlay_text(canonical/'tools/rbxgs/Client',name,patches,workspace=canonical)
                    if task.get('method') not in native_methods.methods(text):raise ValueError('Accepted recovery method missing from canonical source')
                    seed_missing(self.root,{rel:text})
                    files[rel]=(self.root/rel).read_text(encoding='utf-8-sig')
                tasks+=extra
            headers={p:recovery.digest(t.encode()) for p,t in files.items() if Path(p).suffix in ('.h','.hpp','.inl')}
            project=json.loads(project_registry.read_text(encoding='utf-8')) if project_registry.exists() else {}
            probe_headers={rel[len('App/include/'):]:integration.overlay_text(self.root/'tools/rbxgs/Client',rel,project,workspace=self.root)
                           for rel in project if rel.startswith('App/include/') and Path(rel).suffix in ('.h','.hpp','.inl')}
            probe_revision=integration.digest(probe_headers)
            analysis=self.root/'work/2008-06/functions.jsonl'
            if analysis.exists():
                from roc import match
                functions=match._functions_at(analysis,analysis.stat().st_mtime_ns,analysis.stat().st_size)
                tasks=[t for t in tasks if t.get('addr') in functions]
            seen=set();clean=[]
            for task in tasks:
                task=dict(task)
                if task.get('include_profile','owner')=='owner' and task['file'] in {
                        (recovery.NATIVE/'native-classes'/name).as_posix() for name in recovery.MFC_CONVERSION_UNITS}:
                    task['include_profile']='owner-mfc-conversion'
                path=recovery.native_path(self.root,task['file'])
                text=files.get(task['file'])
                method=task.get('method')
                if text is None or not re.fullmatch('[0-9a-f]{8}',task.get('addr','')):continue
                if method not in native_methods.methods(text) and not task.get('add_method'):continue
                if '(' in method and (not isinstance(task.get('expected_symbol'),str) or sweep.symbol_method(task['expected_symbol'])!=method.split('(',1)[0]):
                    raise ValueError('Overloaded recovery task needs an explicit matching MSVC symbol')
                if path.suffix!='.cpp' and not task.get('translation_unit'):
                    if '(' in method:continue  # An overload needs an owner-established consuming translation unit.
                    unit=None if method not in sweep.methods(text) else next((p for p,t in files.items() if p.endswith('.cpp') and re.search(r'#include\s*[<"][^>"\n]*'+re.escape(path.name)+r'[>"]',t)),None)
                    if not unit:
                        symbol=names.get(task['addr'],{}).get('symbol','')
                        parts=symbol.split('@')
                        if len(parts)<4 or not parts[0].startswith('?') or parts[1]!=method.split('::')[0]:continue
                        scopes=[]
                        for name in parts[1:]:
                            if not name:break
                            if not re.fullmatch(r'\w+',name):break
                            scopes.append(name)
                        qualified='::'.join(reversed(scopes))
                        header=Path(task['file']).relative_to(recovery.NATIVE/'native-headers').as_posix() if '/native-headers/' in task['file'] else path.name
                        unit=(recovery.NATIVE/'tests'/('NativeRecovery'+integration.digest([task['file'],method])[:16]+'.cpp')).as_posix()
                        files[unit]='#include "'+header+'"\n' + \
                            'template<class T> struct NativeRecoverySink { static T value; };\n' + \
                            'template<class T> T NativeRecoverySink<T>::value;\n' + \
                            'template<class T> void nativeRecoveryKeep(T value){NativeRecoverySink<T>::value=value;}\n' + \
                            'void nativeRecoveryProbe(){nativeRecoveryKeep(&'+qualified+'::'+method.split('::')[-1]+');}\n'
                    task['translation_unit']=unit
                if task.get('translation_unit') and task['translation_unit'] not in files:continue
                target=integration.digest([task['file'].casefold(),method,task['addr']])
                if target in seen:continue
                seen.add(target)
                context=[canonical_revision] if task.get('include_profile')=='accepted' else [headers,probe_revision]
                task.update(target=target,signature=integration.digest([text,context,task.get('include_profile','owner'),files.get(task.get('translation_unit')),task.get('expected_symbol')]),scope='method-body-only',class_name=method.split('(',1)[0].rsplit('::',1)[0])
                clean.append(task)
            # Prefer bodies that can use the existing independent integration route.
            mappings={}
            tree=canonical/'tools/rbxgs/Client'
            sources={p.relative_to(tree).as_posix() for p in tree.glob('App/*/*.cpp')}
            sources.update(p for p in patches if p.startswith('App/') and p.endswith('.cpp'))
            sources.update(p.relative_to(tree).as_posix() for p in (tree/'App/include').rglob('*') if p.suffix in ('.h','.hpp','.inl'))
            sources.update(p for p in patches if p.startswith('App/include/') and Path(p).suffix in ('.h','.hpp','.inl'))
            for rel in sorted(sources):
                for method in native_methods.methods(integration.overlay_text(tree,rel,patches,workspace=canonical)):
                    mappings.setdefault(method,[]).append(rel)
            for task in clean:
                paths=mappings.get(task['method'],[])
                task['integration_mapping']=paths[0] if len(paths)==1 else None
            clean.sort(key=lambda t:(not bool(t['integration_mapping']),len(files[t['file']][slice(*native_methods.methods(files[t['file']]).get(t['method'],(0,len(files[t['file']]))))]),t['file'],t['method']))
            if any(not Path(p).exists() or [Path(p).stat().st_size,Path(p).stat().st_mtime_ns]!=stamp for p,stamp in inputs.items()):
                raise ValueError('Native inputs changed while publishing; refresh catalog')
            self.cached=dict(revision=integration.digest(files),files=files,tasks=clean,blockers=blockers,probe_headers=probe_headers,probe_revision=probe_revision,
                canonical_headers=canonical_headers,canonical_revision=canonical_revision,
                classes=sorted({t['class_name'] for t in clean}),layout_policy='owner-only; no invented fields',lease_seconds=TTL)
            self.cache_key=key
        with self.store.lock:
            busy=list(self.store.db.execute("SELECT target,json_extract(packet,'$.task.addr') FROM native_method_leases WHERE (state='claimed' AND expires>?) OR state='submitted'",(time.time(),)))
            busy_targets={r[0] for r in busy};busy_addresses={r[1] for r in busy}
            busy_addresses.update(integration_busy(self.store.db,time.time()))
            verified=dict(self.store.db.execute('SELECT target,signature FROM native_recovery_verified'))
            integrated={r[0] for r in self.store.db.execute('SELECT addr FROM integration_credit WHERE client=?',(integration.CLIENT,))}
        progress=self.promotions.directory/'progress-native.json'
        if progress.exists():integrated.update(json.loads(progress.read_text(encoding='utf-8'))['addresses'])
        tasks=[dict(t,available=t['target'] not in busy_targets and t['addr'] not in busy_addresses and verified.get(t['target'])!=t['signature'],
                    integration_state='integrated' if t['addr'] in integrated else 'unintegrated') for t in self.cached['tasks']]
        tasks.sort(key=lambda t:(t['integration_state']=='integrated',not bool(t['integration_mapping']),t.get('include_profile')!='accepted'))
        return dict(self.cached,tasks=tasks)

    def claim(self,user,body):
        worker_id=body.get('worker')
        if not isinstance(worker_id,str) or not 1<=len(worker_id)<=120:raise ValueError('Worker identity required')
        catalog=self.catalog()
        task=next((t for t in catalog['tasks'] if t['target']==body.get('target') and t['signature']==body.get('signature')),None)
        if task is None:raise ValueError('Unknown or changed target; refresh catalog')
        if '(' in task['method'] and 'signature-v1' not in body.get('method_selectors',[]):
            return dict(claimed=False,reason='worker-update-required')
        if task.get('include_profile','owner')!='owner' and task['include_profile'] not in body.get('include_profiles',[]):
            return dict(claimed=False,reason='worker-update-required')
        packet=dict(task=task,original=catalog['files'][task['file']])
        with self.store.lock,self.store.db as db:
            db.execute('BEGIN IMMEDIATE')
            now=time.time()
            if task['addr'] in integration_busy(db,now):return dict(claimed=False,reason='integration-busy')
            busy=db.execute("SELECT 1 FROM native_method_leases WHERE ((state='claimed' AND expires>?) OR state='submitted') AND json_extract(packet,'$.task.addr')=? LIMIT 1",(now,task['addr'])).fetchone()
            if busy:return dict(claimed=False,reason='address-busy')
            old=db.execute('SELECT expires,state FROM native_method_leases WHERE target=?',(task['target'],)).fetchone()
            done=db.execute('SELECT signature FROM native_recovery_verified WHERE target=?',(task['target'],)).fetchone()
            if old and (old[1]=='submitted' or old[0]>now and old[1]=='claimed') or done and done[0]==task['signature']:
                return dict(claimed=False)
            count=db.execute("SELECT COUNT(*) FROM native_method_leases WHERE user=? AND state='claimed' AND expires>?",(user,now)).fetchone()[0]
            if count>=50:return dict(claimed=False,reason='contributor-limit')
            identifier=uuid.uuid4().hex
            db.execute('INSERT OR REPLACE INTO native_method_leases VALUES(?,?,?,?,?,?,?)',
                (task['target'],identifier,user,worker_id,now+TTL,'claimed',json.dumps(packet)))
        return dict(claimed=True,lease=identifier,expires=now+TTL,worker=worker_id,task=task)

    def lease(self,user,body,db,live=True):
        row=db.execute('SELECT target,id,user,worker,expires,state,packet FROM native_method_leases WHERE id=?',(body.get('lease'),)).fetchone()
        if not row or row[2:4]!=(user,body.get('worker')) or live and (row[4]<=time.time() or row[5]!='claimed'):
            raise ValueError('Recovery lease expired, replaced or belongs to another worker')
        return row

    def renew(self,user,body,release=False):
        with self.store.lock,self.store.db as db:
            row=self.lease(user,body,db)
            db.execute('UPDATE native_method_leases SET expires=?,state=? WHERE id=?',
                (0 if release else time.time()+TTL,'released' if release else 'claimed',row[1]))
        return dict(released=release,renewed=not release)

    def submit(self,user,body):
        candidate=body.get('candidate');model=body.get('model');check_only=body.get('check_only',False)
        if not isinstance(model,str) or not 1<=len(model)<=120:raise ValueError('Actual model identity required')
        if type(check_only) is not bool or not check_only and (not isinstance(candidate,str) or len(candidate.encode())>2*1024*1024):raise ValueError('Candidate too large or invalid')
        with self.store.lock,self.store.db as db:
            old=db.execute('SELECT id,state,user FROM native_recovery_uploads WHERE lease=?',(body.get('lease'),)).fetchone()
            if old:
                saved=json.loads(db.execute('SELECT record FROM native_recovery_uploads WHERE id=?',(old[0],)).fetchone()[0])
                if old[2]!=user or saved.get('lease_worker')!=body.get('worker'):raise ValueError('Recovery upload belongs to another worker')
                return dict(job=old[0],state=old[1],exact_credits=0)
            row=self.lease(user,body,db)
            record=json.loads(row[6]);task=record['task']
            if not check_only:recovery.method_change(record['original'],candidate,task['method'],task.get('add_method',False))
            record.update(candidate_text=candidate,check_only=check_only,model=model,user=user,lease_worker=row[3])
            identifier=uuid.uuid4().hex
            db.execute('INSERT INTO native_recovery_uploads VALUES(?,?,?,?,?,?,?,NULL)',
                (identifier,row[1],user,model,'queued',json.dumps(record),time.time()))
            db.execute("UPDATE native_method_leases SET state='submitted',expires=0 WHERE id=?",(row[1],))
        from roc.agent_inbox import record as inbox
        inbox('native-recovery-upload',user,model,inbox=self.root/'work/agent-inbox',source=candidate,addr=task['addr'],verified=False,job=identifier)
        self.wake.set()
        return dict(job=identifier,state='queued',exact_credits=0)

    def status(self,identifier):
        if not isinstance(identifier,str) or not re.fullmatch('[0-9a-f]{32}',identifier):raise ValueError('Invalid recovery job')
        with self.store.lock:
            row=self.store.db.execute('SELECT state,receipt FROM native_recovery_uploads WHERE id=?',(identifier,)).fetchone()
        if not row:raise ValueError('Unknown recovery job')
        return dict(job=identifier,state=row[0],receipt=json.loads(row[1]) if row[1] else None,exact_credits=0)

    def take(self):
        with self.store.lock,self.store.db as db:
            row=db.execute("SELECT id,record FROM native_recovery_uploads WHERE state='queued' ORDER BY created LIMIT 1").fetchone()
            if row:db.execute("UPDATE native_recovery_uploads SET state='verifying' WHERE id=?",(row[0],))
        return (row[0],json.loads(row[1])) if row else None

    def verify(self,identifier,record):
        from roc import match,native_refs
        task=record['task'];folder=self.directory/identifier
        path=folder/'candidate.cpp';path.parent.mkdir(parents=True,exist_ok=True)
        if not record['check_only']:path.write_text(record['candidate_text'],encoding='utf-8')
        api=worker.Api(self.server,integration.native_token() or worker.load_settings().get('token'))
        try:
            context=sweep.native_context({},api);base=self.promotions.baseline()
            matcher=sweep.Matcher(set(match._functions('2008-06')))
            from roc.native_collaboration import materialize_probe_headers,materialize_canonical_headers
            published=self.catalog()
            probe_context=materialize_probe_headers(published,folder/'context')
            if probe_context:context.probe_includes=[probe_context]
            context.accepted_headers=materialize_canonical_headers(published,folder/'canonical-context')
            def prove(snapshot,rel):
                unit=task.get('translation_unit')
                if unit and Path(unit).name.startswith('NativeRecovery'):
                    from roc.native_collaboration import snapshot_path
                    probe=self.catalog()['files'].get(unit)
                    if probe is None:raise ValueError('Header consumer changed; refresh assignment')
                    target=snapshot_path(snapshot,unit)
                    target.parent.mkdir(parents=True,exist_ok=True)
                    target.write_text(probe,encoding='utf-8')
                revision='canonical_revision' if task.get('include_profile')=='accepted' else 'probe_revision'
                if self.catalog().get(revision)!=published.get(revision):
                    raise ValueError('Probe declarations changed; candidate retained for fresh verification')
                result=recovery.compile_probe(snapshot,rel,context,matcher,{task['addr']},task['method'],translation_unit=task.get('translation_unit'),include_profile=task.get('include_profile','owner'),expected_symbol=task.get('expected_symbol'))
                if self.catalog().get(revision)!=published.get(revision):
                    raise ValueError('Probe declarations changed during compilation; candidate retained')
                if result.get('target_exact'):
                    refs=native_refs.import_checks(Path(result['object']).read_bytes(),result['symbol'],task['addr'])
                    result['references']=refs
                    if any(r['status']=='incorrect_symbol_reference' for r in refs):raise ValueError('Incorrect imported callee')
                    # Ordinal-only imports cannot be established by masking operand bytes.
                    if any(r['status']=='unresolved' and r['symbol'].startswith('__imp_') for r in refs):raise ValueError('Unresolved imported callee requires owner reference review')
                return result
            if record['check_only']:
                recovery.copy_sources(self.root,folder/'baseline')
                proof=prove(folder/'baseline',task['file'])
                if not proof.get('ok') or not proof.get('target_exact'):raise ValueError('Host baseline is not exact')
                receipt=dict(state='already-exact',proof=proof,exact_credits=0)
            else:
                merged=recovery.merge(self.root,folder/'fresh',task['file'],record['original'],record['candidate_text'],task['method'],prove,folder/'receipt.json',task.get('add_method',False))
                staged=dict(record,candidate=str(path),baseline=[],proof=merged['proof'])
                try:submission=recovery.stage_submission(staged,context,base,folder/'submission',print,recheck=False)
                except Exception as error:submission=dict(state='pending-verification',reason=str(error))
                # The contributor's private Integrator resumes canonical preflight/submission.
                receipt=dict(state='merged',merge=merged,submission=submission,exact_credits=0)
            current=next((t for t in self.catalog()['tasks'] if t['target']==task['target']),None)
            if current:
                with self.store.lock,self.store.db as db:db.execute('INSERT OR REPLACE INTO native_recovery_verified VALUES(?,?)',(task['target'],current['signature']))
            return receipt
        finally:api.close()

    def process(self,job):
        identifier,record=job
        try:receipt=self.verify(identifier,record)
        except Exception as error:receipt=dict(state='retained',reason=str(error)[:2000],exact_credits=0)
        with self.store.lock,self.store.db as db:
            db.execute('UPDATE native_recovery_uploads SET state=?,receipt=? WHERE id=?',(receipt['state'],json.dumps(receipt),identifier))
            db.execute("UPDATE native_method_leases SET state='complete',expires=0 WHERE id=(SELECT lease FROM native_recovery_uploads WHERE id=?)",(identifier,))
        return dict(job=identifier,record=record,receipt=receipt)

    def notify(self,rows):
        from roc import agent_inbox,integration_notify,reports
        gains=[r for r in rows if r['receipt']['state']=='merged' and r['receipt']['merge']['state']=='merged']
        if not gains:return
        lines=[]
        for row in gains:
            record=row['record'];task=record['task']
            agent_inbox.record('native-recovery',record['user'],record['model'],inbox=self.root/'work/agent-inbox',addr=task['addr'],job=row['job'],local_exact=True,exact_credits=0)
            lines.append('`%s` | `%s` | %s | %s'%(task['addr'],task['method'],record['user'],record['model']))
        payload=dict(embeds=[dict(title='RoConstruct Native Recovery',description=('\n'.join(lines)+'\n\nHost-rechecked native source merges. Report only; **0 integration credits**. Runtime/link gates and accepted submissions remain required.')[:4096],color=0x22C55E)])
        url=integration_notify.server_mines_webhook()
        if url:reports._post(url,payload)

    def loop(self):
        while not self.stop.is_set():
            rows=[]
            for _ in range(10):
                job=self.take()
                if not job:break
                rows.append(self.process(job))
            try:self.notify(rows)
            except Exception as error:print('Native recovery report failed:',error)
            if not rows:self.wake.wait(2);self.wake.clear()
