"""Unaccepted discoveries: durable notifications, never integration credit."""
import json
import urllib.parse
import urllib.request
from pathlib import Path

from roc.integration import atomic_json
from roc.integration_notify import owned_payload
from roc.integration_site import coverage, owned_inventory, readable
from roc.reports import server_mines_webhook


def record(root, before, report, user, model='compiler replay', public_root=None, log=print):
    root, public_root = Path(root), Path(public_root or root)
    if not before or report.get('module', '').casefold() == 'codegenanalogs':
        return {'discovered': 0, 'sent': 0}
    proof = public_root / 'work/integration/progress-native.json'
    native = set(json.loads(proof.read_text())['addresses']) if proof.exists() else set()
    previous = set(before.get('owned_addrs', []))
    if public_root != root:
        previous.update(owned_inventory(public_root))
    state_path = root / 'work/integration/owned-notifications.json'
    state = json.loads(state_path.read_text()) if state_path.exists() else {'sent': [], 'pending': {}}
    seen = set(state['sent'])
    fresh = sorted(set(report.get('owned_addrs', [])) - previous - native - seen)
    symbols = root / 'rebuild/2008-06/out' / report['module'] / report.get('owned_symbols_file', 'owned-symbols.json')
    names = json.loads(symbols.read_text()) if symbols.exists() else {}
    for address in fresh:
        owner = next(iter(names.get(address, [])), {})
        state['pending'][address] = {'addr': address, 'name': readable(owner.get('symbol', address)),
            'module': report['module'], 'user': user, 'model': model}
    atomic_json(state_path, state)
    url = server_mines_webhook()
    if not url:
        log('Nearly integrated: %d new owned exacts; webhook pending (not configured)' % len(fresh))
        return {'discovered': len(fresh), 'sent': 0, 'pending': len(state['pending'])}
    groups = None
    if proof.exists() and (public_root / 'work/2008-06/functions.jsonl').exists():
        import sqlite3
        owned = owned_inventory(public_root)
        owned.update(owned_inventory(root))
        owned.update({a: {'module': report['module']} for a in report.get('owned_addrs', [])})
        db = sqlite3.connect((public_root / 'work/server.db').as_uri() + '?mode=ro', uri=True)
        try:
            scores = dict(db.execute("SELECT addr,score FROM funcs WHERE client='2008-06'"))
        finally:
            db.close()
        groups, _ = coverage(public_root, scores, native, owned)
    rows = [row for _, row in sorted(state['pending'].items()) if row['user'] == user and row['model'] == model]
    sent = 0
    for start in range(0, len(rows), 6):
        batch = rows[start:start+6]
        destination = urllib.parse.urlsplit(url)
        query = dict(urllib.parse.parse_qsl(destination.query))
        query['wait'] = 'true'
        target = urllib.parse.urlunsplit(destination._replace(query=urllib.parse.urlencode(query)))
        request = urllib.request.Request(target, json.dumps(owned_payload(user, model, batch, groups)).encode(),
            {'Content-Type': 'application/json', 'User-Agent': 'RoConstruct-Native/1.0'}, method='POST')
        try:
            with urllib.request.urlopen(request, timeout=15) as response:
                receipt = json.loads(response.read() or b'{}')
            if not receipt.get('id'):
                raise ValueError('Webhook response omitted message ID')
        except (OSError, ValueError):
            log('Nearly integrated webhook pending; retained %d discoveries' % len(state['pending']))
            break
        for row in batch:
            state['pending'].pop(row['addr'], None)
            seen.add(row['addr'])
        state['sent'] = sorted(seen)
        state['last_message_id'] = receipt['id']
        atomic_json(state_path, state)
        sent += len(batch)
    return {'discovered': len(fresh), 'sent': sent, 'pending': len(state['pending'])}
