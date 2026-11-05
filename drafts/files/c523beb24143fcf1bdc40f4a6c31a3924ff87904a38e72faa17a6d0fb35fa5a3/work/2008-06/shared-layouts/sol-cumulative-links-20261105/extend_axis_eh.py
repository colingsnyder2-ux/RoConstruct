"""Conditional cross-object EH evidence using already supplied exact providers.

The canonical auditor and its failure receipt remain unchanged. This sidecar does
not establish linked selection, indirect callee ABI, or runtime safety.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys
import contextlib
import io

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import match
from native_check_runner import analyze_object

sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
archive = ROOT / 'work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib'
assert sha(archive) == '5e468dd4a346f252ce853c68ee416f1df833eddb23c0ab80e15194c623d19f4c'
blob = archive.read_bytes()
offset, found = 8, []
while offset < len(blob):
    header = blob[offset:offset + 60]
    assert header[58:] == b'`\n'
    size = int(header[48:58])
    raw = blob[offset + 60:offset + 60 + size]
    if hashlib.sha256(raw).hexdigest() == 'a63464692c019673bc9d22850bcf5763274c96f63790357bf3fa6102387310c1':
        found.append((offset, raw))
    offset += 60 + size + (size & 1)
assert len(found) == 1
mega = HERE / 'actual-MegaDragger.obj'
mega.write_bytes(found[0][1])
original = ROOT / 'clients/2008-06/Roblox.exe'
assert sha(original) == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
axis = ROOT / 'work/2008-06/native-check-runs/20261105-131546-668ff08d/unit-000/candidate.obj'
mouse = ROOT / 'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/NativeMouseCommandFull.obj'
irenderable = ROOT / 'work/2008-06/shared-layouts/sol-irenderable-20261105/run/unit-000/candidate.obj'
assert sha(axis) == 'e9f53666cd11d3c15c7985b8b24c11821d448840c2df2d3d66f28dda6bdbac7c'
assert sha(mouse) == 'b3f271ca190c956215c6b7d4b60e2a76eeb1e7b638bfcc0007ce06cdfdf24307'
assert sha(irenderable) == '42444b399d06567d75cbed1cbde50660d8d672753602d84959cc7b3e1957dbe7'
checks = []
for path, address, symbol in (
        (mega, '0060e700', '??1MegaDragger@RBX@@QAE@XZ'),
        (mouse, '00615780', '??1MouseCommand@RBX@@UAE@XZ'),
        (irenderable, '0047d410', '??1IRenderable@RBX@@QAE@XZ')):
    report = analyze_object({'checks': [{'addr': address, 'symbol': symbol}], 'ranges': [], 'layouts': []}, path)
    assert report['checks'][0]['status'] == 'exact'
    assert not report['checks'][0]['data_errors']
    checks.append({'object': str(path), 'sha256': sha(path), 'analysis': report})

# Verify the original direct call from the exact auto_ptr body before supplying
# its MegaDragger identity to the conditional derivative.
raw = axis.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
functions = {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
auto = next(name for name in functions if name.startswith('??1?$auto_ptr@VMegaDragger@RBX@@'))
body, refs = functions[auto]
base, image = match._image('2008-06')
original_auto = image[0x00640540-base:0x00640540-base+len(body)]
assert match.exact_match(original_auto, [], body, refs)
start, section = definitions[auto]
table = sections[section]
anchors = []
for index in range(table[7]):
    position, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*index)
    delta = position - start
    if 0 <= delta < len(body)-3 and kind == 20:
        target = (0x00640540 + delta + 4 + struct.unpack_from('<i', original_auto, delta)[0]) & 0xffffffff
        anchors.append({'offset': delta, 'symbol': symbols[symbol_index][0], 'original_target': hex(target),
                        'zero_addend': struct.unpack_from('<i', body, delta)[0] == 0})
assert any(row['symbol'] == '??1MegaDragger@RBX@@QAE@XZ' and row['original_target'] == '0x60e700'
           and row['zero_addend'] for row in anchors)

auditor = ROOT / 'rebuild/2008-06/tests/audit_native_eh_graph.py'
failure = ROOT / 'work/2008-06/shared-layouts/sol-axis-ctor-20261105/eh.json'
failure_hash = sha(failure)
assert failure_hash == '3257ed3c403876bc92ed50a2ebcca8c19ca9689940b51d0ec7b083ca7ffbbff0'
source = auditor.read_text()
original_auditor_hash = sha(auditor)
assert source.count('ROOT=Path(__file__).resolve().parents[3]') == 1
source = source.replace('ROOT=Path(__file__).resolve().parents[3]', 'ROOT=Path.cwd()')
weak_line = "alias=weak[symbol];assert alias['search_characteristic']==2,alias"
assert source.count(weak_line) == 1
source = source.replace(weak_line, "raise AssertionError(('unproved selected weak LIBRARY fallback',symbol,weak[symbol]))")
marker = 'try:walk(handler,bindings[handler])'
assert source.count(marker) == 1
source = source.replace(marker, "bind('??1MouseCommand@RBX@@UAE@XZ',0x615780)\nbind('??1MegaDragger@RBX@@QAE@XZ',0x60e700)\n" + marker)
derivative = HERE / 'conditional-axis-mega-auditor.py'
derivative.write_text(source)
graphs = []
for path, address, symbol, output in (
        (axis, '00640560', '??0AxisMoveTool@RBX@@QAE@PAVWorkspace@1@@Z', 'axis-cleanup-graph.json'),
        (mega, '0060e700', '??1MegaDragger@RBX@@QAE@XZ', 'mega-cleanup-graph.json')):
    sys.argv = [str(derivative), str(path), address, symbol, '--output', str(HERE / output)]
    with contextlib.redirect_stdout(io.StringIO()):
        try:
            exec(compile(source, str(derivative), 'exec'), {'__file__': str(derivative), '__name__': '__main__'})
        except AssertionError:
            pass
    graph = json.loads((HERE / output).read_text())
    graphs.append({'object': str(path), 'address': address, 'nodes': len(graph['events']), 'errors': graph['errors'],
                   'receipt': str(HERE / output)})
assert sha(auditor) == original_auditor_hash and sha(failure) == failure_hash
report = {'scope': __doc__, 'actual_archive': str(archive), 'archive_sha256': sha(archive),
          'mega_member_offset': found[0][0], 'mega_member_sha256': sha(mega),
          'original_auto_ptr_direct_anchors': anchors, 'actual_provider_checks': checks,
          'graphs': graphs,
          'supplied_external_bindings': {'??1MouseCommand@RBX@@UAE@XZ': '00615780',
                                         '??1MegaDragger@RBX@@QAE@XZ': '0060e700'},
          'preserved_generic_failure_sha256': failure_hash, 'canonical_auditor_unchanged': True,
          'remaining': ['Indirect weak control-block destroy type/ABI and complete producer coverage',
                        'Any graph external/weak bindings listed as errors',
                        'Actual selected PE/RTTI/import/weak LIBRARY resolution and loaded SxS runtime',
                        'Strict constructor string-IAT call at offset78 remains indirect proof failure'],
          'compiles': 0, 'links': 0, 'executed': False, 'activation': False}
(HERE / 'axis-mega-eh-continuation.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'graphs': graphs, 'actual_members_unchanged': True, 'compiles': 0, 'links': 0}))
