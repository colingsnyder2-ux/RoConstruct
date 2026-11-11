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
if extra_receipt:
    for receipt in extra_receipt.split(os.pathsep):
        rows = json.loads(Path(receipt).read_text())
        for row in rows.get('selected', []):
            path = Path(row['object']).resolve()
            digest = row.get('object_sha256')
            if digest and (not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != digest):
                raise ValueError('selected object hash mismatch: ' + str(path))
            extra.append(path)
    if not all(path.is_file() for path in extra):
        raise ValueError('missing selected native provider object')
    shell += extra
shell = sorted(set(path.resolve() for path in shell))
# byte-exact server analogs relinked under their real names (rename.py)
_ren = json.load(open(rebuild.ROOT / 'work/native-client/link/rename.json')) if (rebuild.ROOT / 'work/native-client/link/rename.json').exists() else {}
# engine-ABI: a renamed 2008 body of an engine class (RBX::) assumes 2008 layouts the linked 2007 engine lacks
shell += sorted(p for p in (rebuild.ROOT / 'work/native-client/link/renamed').glob('*.obj')
                if not (os.environ.get('ROC_ENGINE_ABI') == '1' and '@RBX@@' in _ren.get(p.stem, {}).get('symbol', '@RBX@@')))
engine = sorted((ws / 'out/RbxgsApp/linked').glob('*.obj'))

# One owner per strong definition: the engine wins over a native shell object; between two shell objects the
# first (sorted) keeps it. Losers get a stripped copy (definition -> undefined external) in link/stripped/.
_sc = {}
exec(open(rebuild.ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read().split('def archive_symbols')[0], _sc)
strong = lambda p: {n for n, k in _sc['symbols'](p.read_bytes()).items() if k == 'strong'}
defined = lambda p: {n for n, k in _sc['symbols'](p.read_bytes()).items() if k != 'undef'}
owned = set().union(*(defined(p) for p in engine))
STRIP = OUT / 'stripped'
STRIP.mkdir(exist_ok=True)
kept, stripped_report, skipped_report = [], {}, {}
for p in shell:
    mine = defined(p)
    drop = mine & owned
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
                         + ['/NODEFAULTLIB:' + l for l in rebuild.VENDOR_AUTOLINK] + ['/NODEFAULTLIB:../../../../../tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib'], OUT)
(OUT / 'link.txt').write_text(text, encoding='utf-8')
unres = sorted(set(rebuild.unresolved_symbols(text)))
dups = sorted(set(re.findall(r'error LNK2005:\s*(.*?)\s+already defined in', text)))
print('exit', code, 'shell objs', len(shell), 'engine objs', len(engine), 'unresolved', len(unres), 'duplicates', len(dups))
json.dump({'link_exit_code': code, 'unresolved': unres, 'duplicates': dups,
           'skipped_duplicate_analogs': len(skipped_report),
           'selected_providers': [str(path.relative_to(rebuild.ROOT)).replace('\\', '/') for path in extra]},
          open(OUT / 'probe.json', 'w'), indent=1)
grp = collections.Counter(re.sub(r'^\?+\$?|@.*$', '', s.split('@')[1] if s.startswith('?') and '@' in s else s)[:40] for s in unres)
for k, v in grp.most_common(40):
    print(' ', v, k)
