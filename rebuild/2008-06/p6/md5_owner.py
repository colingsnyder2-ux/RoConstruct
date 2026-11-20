"""Replace only ContentProvider's MD5 implementation with proven native C++."""
from collections import Counter
import hashlib
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))

from roc import libs, match, rebuild
from script_context_owner import sha, references, data_symbols
from captured_inputs import freeze


def prove(folder):
    folder = Path(folder).resolve()
    if folder.exists() and any(folder.iterdir()):
        raise RuntimeError('choose an empty native MD5 proof directory')
    folder.mkdir(parents=True, exist_ok=True)
    recorder = ROOT / 'rebuild/2008-06/tests/record_native_misc_leaves.py'
    command = [sys.executable, str(recorder), '--out', str(folder)]
    run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    (folder / 'matching.log').write_text(run.stdout + run.stderr)
    if run.returncode:
        raise RuntimeError('native MD5 matching failed; inspect ' + str(folder / 'matching.log'))
    receipt = json.loads((folder / 'receipt.json').read_text())
    for row in receipt['methods']:
        if ('MD5HasherImpl@' not in row['symbol'] and '?create@MD5Hasher@' not in row['symbol']) or not row.get('local_eh'):
            continue
        command = [sys.executable, str(ROOT / 'rebuild/2008-06/tests/audit_native_eh_graph.py'),
                   str(folder / 'NativeMD5Hasher.obj'), row['address'], row['symbol'],
                   '--output', str(folder / ('eh-' + row['address'] + '.json'))]
        run = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
        if run.returncode:
            raise RuntimeError('native MD5 exception graph failed: ' + row['address'] + ': ' + run.stderr[-800:])


def build(snapshot, output, tc, archive, proof):
    proof = Path(proof).resolve()
    if not (proof / 'receipt.json').is_file():
        prove(proof)
    receipt = json.loads((proof / 'receipt.json').read_text())
    inputs = {str(ROOT / name): value for name, value in receipt['sources'].items()}
    inputs.update(receipt['dependencies'])
    inputs.update({str(Path(__file__)): sha(__file__), str(archive): sha(archive)})
    if any(not Path(p).is_file() or sha(p) != value for p, value in inputs.items()):
        raise RuntimeError('MD5 matching proof inputs changed; refresh proof first')
    native = proof / 'NativeMD5Hasher.obj'
    raw = native.read_bytes()
    if sha(native) != receipt['objects'][native.name]:
        raise RuntimeError('MD5 proven object changed')
    inputs[str(native)] = sha(native)
    for address in ('0055c540', '0055c800', '0055c740', '0055e320', '0055c8b0'):
        path = proof / ('eh-' + address + '.json')
        eh = json.loads(path.read_text())
        if eh['errors'] or not eh['primary_body_exact'] or eh['object_sha256'] != sha(native) or eh['original_sha256'] != sha(ROOT / 'clients/2008-06/Roblox.exe'):
            raise RuntimeError('MD5 exception graph proof missing/stale: ' + address)
        inputs[str(path)] = sha(path)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    checks = [('0055c540', '??0MD5HasherImpl@'), ('0055c800', '?addData@MD5HasherImpl@'),
              ('0055c740', '?addData@MD5HasherImpl@'), ('0055c6a0', '?addData@MD5HasherImpl@'),
              ('0055c710', '?toString@MD5HasherImpl@'), ('0055e320', '?c_str@MD5HasherImpl@'),
              ('0055c8b0', '?create@MD5Hasher@')]
    selected = []
    for address, prefix in checks:
        rows = [r for r in receipt['methods'] if int(r['address'], 16) == int(address, 16) and r['symbol'].startswith(prefix)]
        if len(rows) != 1 or not rows[0].get('exact'):
            raise RuntimeError('MD5 proof missing exact method: ' + address)
        name = rows[0]['symbol']
        body, relocs = bodies[name]
        target, mask, _ = match.target('2008-06', address)
        _, errors = match.data_check('2008-06', address, target, match.coff_data_refs(raw, name))
        if not set(mask) <= set(relocs) or not match.exact_match(target, mask, body, relocs) or errors:
            raise RuntimeError('MD5 original body/data mismatch: ' + address)
        selected.append(dict(address=address, symbol=name))
    layout = proof / 'NativeMiscLeavesLayout.obj'
    if sha(layout) != receipt['objects'][layout.name]:
        raise RuntimeError('MD5 layout object changed')
    size = next(body for name, body, _ in match.coff_functions(layout.read_bytes()) if name.startswith('?nativeMD5HasherImplSize@@'))
    if size != b'\xb8\x28\0\0\0\xc3':
        raise RuntimeError('MD5 original allocation/layout mismatch')
    inputs[str(layout)] = sha(layout)
    folder = output / 'md5-owner'
    folder.mkdir()
    module = snapshot / 'RbxgsApp'
    source, flags, captured, recovered = freeze(module / 'layer-rbxgs/ContentProvider.command.json', module, snapshot, folder)
    inputs.update(captured)
    text = source.read_text()
    start = text.index('\tclass MD5HasherImpl : public MD5Hasher')
    factory = text.index('\tMD5Hasher* MD5Hasher::create()', start)
    end = text.index('\n\t}', factory) + len('\n\t}')
    # Delete the genuine old class and its factory from captured SOURCE only.
    # Every other provider must remain byte/relocation/data identical below.
    for name, content in [('Baseline', text), ('ContentProvider', text[:start] + text[end:])]:
        path = folder / (name + '.cpp')
        path.write_text(content)
        code, log = rebuild.run(tc, 'cl', flags + ['/Fo' + name + '.obj', str(path)], folder)
        (folder / (name + '.log')).write_text(log)
        if code:
            raise RuntimeError('MD5 retained-provider compile failed: ' + log[-1000:])
    members = list(libs.archive_members(archive))
    original = next(data for name, data in members if name == 'ContentProvider.obj')
    baseline = (folder / 'Baseline.obj').read_bytes()
    remainder = (folder / 'ContentProvider.obj').read_bytes()
    def functions(data):
        return {name: (body, refs) for name, body, refs in match.coff_functions(data)}
    a, b, c = functions(original), functions(baseline), functions(remainder)
    def equal(left, right):
        return match.exact_match(left[0], left[1], right[0], right[1])
    if set(a) != set(b) or any(not equal(a[n], b[n]) for n in a) or references(original) != references(baseline) or data_symbols(original) != data_symbols(baseline):
        raise RuntimeError('MD5 captured baseline does not reproduce original archive member')
    ra, rc = references(original), references(remainder)
    da, dc = data_symbols(original), data_symbols(remainder)
    if set(c) - set(a) or any(not equal(a[n], c[n]) or ra[n] != rc[n] for n in c):
        raise RuntimeError('MD5 owner split changed a retained body/callee')
    if set(dc) - set(da) or any(dc[n] != da[n] for n in dc):
        raise RuntimeError('MD5 owner split changed retained data')
    # This native object supplies all public MD5 methods/factory; an unresolved
    # discarded private helper causes the ordinary link to fail, never a stub.
    target = folder / 'linked.lib'
    code, log = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(target), str(archive), 'ContentProvider.obj'], folder)
    (folder / 'librarian.log').write_text(log)
    if code:
        raise RuntimeError('MD5 source replacement librarian failed: ' + log[-1000:])
    def inventory(rows):
        return Counter((name, hashlib.sha256(data).hexdigest()) for name, data in rows)
    before, after = inventory(members), inventory(libs.archive_members(target))
    if list((before - after).elements()) != [('ContentProvider.obj', hashlib.sha256(original).hexdigest())] or list((after - before).elements()) != [('ContentProvider.obj', hashlib.sha256(remainder).hexdigest())]:
        raise RuntimeError('MD5 archive replacement changed another member')
    if any(not Path(p).is_file() or sha(p) != value for p, value in inputs.items()):
        raise RuntimeError('MD5 owner inputs changed during source replacement')
    (folder / 'receipt.json').write_text(json.dumps(dict(inputs=inputs, recovered=recovered, native_object_sha256=sha(native),
        archive_sha256=sha(target), retained_bodies=len(c), retained_named_data=len(dc), unchanged_other_members=len(members)-1,
        original_checks=selected, layout_size=40, removed_definitions=sorted(set(a)-set(c)),
        scope='Source ownership and original code/data/layout checks; final selected map and runtime tests still required.'), indent=2))
    return target, native
