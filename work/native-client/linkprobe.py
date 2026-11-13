"""Link probe for the native 2008 client: native shell objects (work/native-client/obj) + the rbxgs-app engine
objects + its dependency libs + XTP/Scintilla + MFC 9.0 (mfc90 import lib, mfcs90 helper) as a Windows exe.
Prints unresolved externals grouped by name prefix and duplicate definitions. No P6 / RobloxShell / Player."""
import re, sys, collections, json, struct, hashlib
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild

client = '2008-06'
ws = rebuild.workspace(client)
OUT = rebuild.ROOT / 'work/native-client/link'
OUT.mkdir(parents=True, exist_ok=True)
import os
OBJ = 'work/native-client/obj-engine-abi' if os.environ.get('ROC_ENGINE_ABI') == '1' else 'work/native-client/obj'
shell = sorted(p for p in (rebuild.ROOT / OBJ).glob('*.obj') if 'Trial' not in p.name)
experimental = OUT / 'engine-abi-experimental.json'
# Selector compiles trial providers into shared ABI cache.  Keep every trial out
# of link until its direct byte proof receipt explicitly adds it back below.
if os.environ.get('ROC_ENGINE_ABI') == '1' and experimental.is_file():
    trial = set(json.loads(experimental.read_text()).get('stems', []))
    shell = [p for p in shell if p.stem not in trial]
extra_receipt = os.environ.get('ROC_LINK_EXTRA', '')
extra = []
selection_provenance = {'providers': 0, 'hash_pinned': 0, 'with_proof_receipt': 0,
                        'without_proof_receipt': 0}
if extra_receipt:
    for receipt in extra_receipt.split(os.pathsep):
        rows = json.loads(Path(receipt).read_text())
        for row in rows.get('selected', []):
            path = Path(row['object']).resolve()
            digest = row.get('object_sha256')
            if digest and (not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != digest):
                raise ValueError('selected object hash mismatch: ' + str(path))
            selection_provenance['providers'] += 1
            selection_provenance['hash_pinned'] += bool(digest)
            selection_provenance['with_proof_receipt'] += bool(row.get('proof_receipt'))
            selection_provenance['without_proof_receipt'] += not bool(row.get('proof_receipt'))
            extra.append(path)
    if not all(path.is_file() for path in extra):
        raise ValueError('missing selected native provider object')
    shell += extra
shell = sorted(set(path.resolve() for path in shell))
# byte-exact server analogs relinked under their real names (rename.py)
_ren = json.load(open(rebuild.ROOT / 'work/native-client/link/rename.json')) if (rebuild.ROOT / 'work/native-client/link/rename.json').exists() else {}
# engine-ABI: a renamed 2008 body of an engine class (RBX::) assumes 2008 layouts the linked 2007 engine lacks
def acceptable_analog(path):
    source = rebuild.ROOT / 'src/2008-06' / (path.stem + '.cpp')
    if not source.is_file():
        return False
    text = source.read_text(errors='replace')
    return not re.search(r'\bstruct\s+[BS]_func_[0-9a-fA-F]{8}\b', text)

shell += sorted(p for p in (rebuild.ROOT / 'work/native-client/link/renamed').glob('*.obj')
                if acceptable_analog(p) and not (os.environ.get('ROC_ENGINE_ABI') == '1' and '@RBX@@' in _ren.get(p.stem, {}).get('symbol', '@RBX@@')))
engine = sorted((ws / 'out/RbxgsApp/linked').glob('*.obj'))
if os.environ.get('ROC_SHELL_WINS'):  # shortcut: engine definitions a shell object replaces (stripped copies of the engine objects)
    _wins = set(json.load(open(os.environ['ROC_SHELL_WINS'])))
    _sdir = OUT / 'engine-stripped'; _sdir.mkdir(exist_ok=True); _eng2 = []
    from roc.rebuild import coff_externals as _ce
    for _e in engine:
        _raw = _e.read_bytes(); _hit = {n for n, d in _ce(_raw).items() if d} & _wins
        if _hit:
            (_sdir / _e.name).write_bytes(rebuild.strip_symbols(_raw, drop=_hit)); _eng2.append(_sdir / _e.name)
        else:
            _eng2.append(_e)
    engine = _eng2

# One owner per strong definition: the engine wins over a native shell object; between two shell objects the
# first (sorted) keeps it. Losers get a stripped copy (definition -> undefined external) in link/stripped/.
_sc = {}
exec(open(rebuild.ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read().split('def archive_symbols')[0], _sc)
strong = lambda p: {n for n, k in _sc['symbols'](p.read_bytes()).items() if k == 'strong'}
defined = lambda p: {n for n, k in _sc['symbols'](p.read_bytes()).items()
                     if (k == 'strong' if os.environ.get('ROC_STRONG_OWN') == '1' else k != 'undef')}  # shortcut: weak aliases own nothing
owned = set().union(*(defined(p) for p in engine))
STRIP = OUT / 'stripped'
STRIP.mkdir(exist_ok=True)
kept, stripped_report, skipped_report = [], {}, {}
_seen_dup = set()
if os.environ.get('ROC_DEDUPE'):  # engine definitions of the reported duplicates win over shell copies
    _dupset = set(json.load(open(os.environ['ROC_DEDUPE'])))
    for _e in engine:
        _seen_dup |= {n for n, k in _sc['symbols'](_e.read_bytes()).items() if k != 'undef'} & _dupset
for p in shell:
    mine = defined(p)
    drop = mine & owned
    if os.environ.get('ROC_DEDUPE'):  # shortcut: symbols the link reported as multiply defined; the first object keeps each
        _dup = set(json.load(open(os.environ['ROC_DEDUPE'])))
        _sc_all = {n for n, k in _sc['symbols'](p.read_bytes()).items() if k != 'undef'} & _dup
        drop |= {n for n in _sc_all if n in _seen_dup}
        _seen_dup |= _sc_all
    if os.environ.get('ROC_SHELL_WINS'):  # shortcut: only the glue object keeps these definitions
        if p.name != 'LockFix.obj':
            drop |= {n for n, k in _sc['symbols'](p.read_bytes()).items() if k != 'undef'} & _wins
            mine = mine - _wins
        else:
            drop -= _wins
    if p.name == 'stubs.obj':
        drop = set()  # shortcut stubs (work/native-client/shortcut): strong definitions must beat weak aliases
    if mine and mine <= owned and p.parent.name == 'renamed':
        raw = p.read_bytes()
        nsec, optsz = struct.unpack_from('<H', raw, 2)[0], struct.unpack_from('<H', raw, 16)[0]
        sections = [struct.unpack_from('<8sIIIIIIHHI', raw, 20 + optsz + 40 * k) for k in range(nsec)]
        initializers = any(s[0].startswith((b'.CRT', b'.tls')) and s[3] for s in sections)
        if not initializers:
            skipped_report[str(p.relative_to(rebuild.ROOT))] = sorted(mine)
            continue
    if drop:
        (STRIP / p.name).write_bytes(rebuild.strip_symbols(p.read_bytes(), drop=drop))
        stripped_report[p.name] = sorted(drop)
        p = STRIP / p.name
    owned |= mine
    kept.append(p)
shell = kept
json.dump(stripped_report, open(OUT / 'stripped.json', 'w'), indent=1)
json.dump(skipped_report, open(OUT / 'skipped-duplicate-analogs.json', 'w'), indent=1)
spec = rebuild.load_module(client, 'rbxgs-app')
libs, pending = [], list(spec['depends'])
while pending:
    d = rebuild.load_module(client, pending.pop(0))
    lib = ws / 'out' / d['name'] / 'linked' / 'linked.lib'
    if lib not in libs:
        libs.append(lib); pending += d.get('depends', [])
libs += [ws / 'out/XTP/linked/linked.lib', ws / 'out/Scintilla/linked/linked.lib']
mfc = rebuild.ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/lib'
fmod = rebuild.ROOT / 'tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib'
libs += [fmod, rebuild.mfc_import_lib(client), mfc / 'mfcs90.lib', mfc / 'atls.lib']
system = ['kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib', 'ole32.lib', 'oleaut32.lib', 'uuid.lib',
          'comdlg32.lib', 'comctl32.lib', 'ws2_32.lib', 'winmm.lib', 'opengl32.lib', 'glu32.lib', 'imagehlp.lib',
          'version.lib', 'wininet.lib', 'dbghelp.lib', 'psapi.lib', 'shlwapi.lib', 'urlmon.lib', 'oledlg.lib', 'msimg32.lib',
          'sensapi.lib']
rsp = OUT / 'link.rsp'
rsp.write_text('\n'.join('"%s"' % p for p in shell + engine + libs) + '\n')
code, text = rebuild.run(rebuild.toolchain(), 'link', ['/nologo', '/SUBSYSTEM:WINDOWS', '/MACHINE:X86', '/MAP:Roblox2008.map',
                                                       '/OUT:Roblox2008.exe', '@' + str(rsp)] + system
                         + ([os.environ['ROC_LINK_RES']] if os.environ.get('ROC_LINK_RES') else [])  # original exe resources (pe_to_res.py)
                         + ['/NODEFAULTLIB:' + l for l in rebuild.VENDOR_AUTOLINK] + ['/NODEFAULTLIB:../../../../../tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib'], OUT)
(OUT / 'link.txt').write_text(text, encoding='utf-8')
unres = sorted(set(rebuild.unresolved_symbols(text)))
dups = sorted(set(re.findall(r'error LNK2005:\s*(.*?)\s+already defined in', text)))
print('exit', code, 'shell objs', len(shell), 'engine objs', len(engine), 'unresolved', len(unres), 'duplicates', len(dups))
json.dump({'link_exit_code': code, 'unresolved': unres, 'duplicates': dups,
           'skipped_duplicate_analogs': len(skipped_report),
           'selection_provenance': selection_provenance,
           'linked_section_bytes': None,
           'selected_providers': [str(path.relative_to(rebuild.ROOT)).replace('\\', '/') for path in extra]},
          open(OUT / 'probe.json', 'w'), indent=1)
grp = collections.Counter(re.sub(r'^\?+\$?|@.*$', '', s.split('@')[1] if s.startswith('?') and '@' in s else s)[:40] for s in unres)
for k, v in grp.most_common(40):
    print(' ', v, k)
