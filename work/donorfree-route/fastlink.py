"""python fastlink.py [OBJ...]: ~1 min relink for fixes that only ADD or REPLACE objects (nameinit.obj, a rebuilt
tmplinst lib, one reconverted object): reruns lld once on the last full link's final response file
(linkexp/qt.final.rsp, conflict fixes already applied) instead of quicktest.py's stub regeneration (~4 min).
Given objects go FIRST; /FORCE:MULTIPLE keeps the first definition, so a new real definition beats the stub of the same
name. Undefined symbols (the fix needs NEW names) -> exit 1: run quicktest.py instead. Copies to run/RobloxQT.exe."""
import os, re, shutil, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
LLD = r'C:\Program Files\LLVM\bin\lld-link.exe'
t0 = time.time()
src = H / 'linkexp/qt.final.rsp'
lines = src.read_text().splitlines()
extra = ['"%s"' % Path(a).resolve() for a in sys.argv[1:]]
norm = lambda l: os.path.normcase(l.strip('"'))
ex = {norm(e) for e in extra}
lines = [l for l in lines if norm(l) not in ex and not l.upper().startswith('"/FORCE:MULTIPLE')]
first = next((i for i, l in enumerate(lines) if l.lower().endswith(('.obj"', '.lib"'))), len(lines))
lines = lines[:first] + extra + ['"/FORCE:MULTIPLE"'] + lines[first:]
rsp = H / 'linkexp/fast.rsp'
rsp.write_text('\n'.join(lines) + '\n')
run_rsp = rsp
if os.environ.get('QT_SHARD_LIBS') == '1':   # opt-in, as in lld_link.py: converted-object runs as /WHOLEARCHIVE shards
    try:
        import shard_libs
        run_rsp, _st = shard_libs.write_sharded_rsp(lines, H / 'linkexp/fast.sharded.rsp', H / 'linkexp/shards')
        print('fastlink: shards %s' % _st)
    except Exception as _e:
        print('fastlink: sharding skipped (loose link):', _e); run_rsp = rsp
r = subprocess.run([LLD, '@' + str(run_rsp)], capture_output=True, text=True, errors='replace')
und = sorted(set(re.findall(r'undefined symbol: (\S+)', r.stdout + r.stderr)))
if und or not (H / 'linkexp/qt.exe').exists():
    print('fastlink: %d undefined (e.g. %s) -> run quicktest.py' % (len(und), und[:3]) if und else (r.stdout + r.stderr)[-800:])
    sys.exit(1)
mp = H / 'linkexp/qt.map'
if mp.exists():
    _t = mp.read_text(errors='replace')
    _t2 = re.sub(r'(?<=\s)0{8}([0-9a-f]{8})(?=\s)', r'\1', _t)
    if run_rsp != rsp:   # sharded link: map owners back to the member names a loose link shows
        import shard_libs
        _t2 = shard_libs.unshard_map_text(_t2)
    if _t2 != _t:   # (unchanged text: no second full write)
        mp.write_text(_t2)
    del _t, _t2
import xcudedup   # repeated .CRT$XCU initializers ran twice (see xcudedup.py)
xcudedup.dedup(str(H / 'linkexp/qt.exe'), str(mp))
shutil.copy(H / 'linkexp/qt.exe', H / 'run/RobloxQT.exe')
print('fastlink: lld exit %d in %.0fs (%d objects first) -> run/RobloxQT.exe' % (r.returncode, time.time() - t0, len(extra)))
