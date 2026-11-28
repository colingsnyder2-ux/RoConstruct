"""python lldprof.py [--shards] [--repeat N] [--no-map] [--env roc] [RSP] [EXTRA LLD ARGS...]: time one lld-link run on a copy of
the last final response file (default linkexp/qt.final.rsp) with /time, writing linkexp/prof.exe/.map so the real link
outputs are untouched. Prints lld's own phase timings, plus counts of objects/libs/aliases and the flags in use.
--shards: the same link with quicktest's converted-object runs packed as /WHOLEARCHIVE shards (shard_libs.py; the first
run builds them, later runs reuse them) -- compare "Input File Reading" and the total with a plain run.
--repeat N: N runs (the first one warms the OS file cache; later ones show the steady state).
--no-map: drop /MAP (how much the map costs; quicktest itself needs it).
--env roc: run lld with lld_link.py's LIB/INCLUDE environment (roc.rebuild); default: the caller's environment, as
before."""
import os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
LLD = r'C:\Program Files\LLVM\bin\lld-link.exe'
args = sys.argv[1:]
shards = '--shards' in args
nomap = '--no-map' in args
repeat = 1
if '--repeat' in args:
    repeat = int(args[args.index('--repeat') + 1])
    del args[args.index('--repeat'):args.index('--repeat') + 2]
envroc = False
if '--env' in args:
    envroc = args[args.index('--env') + 1] == 'roc'
    del args[args.index('--env'):args.index('--env') + 2]
args = [a for a in args if a not in ('--shards', '--no-map')]
src = Path(args[0]) if args else H / 'linkexp/qt.final.rsp'
L = src.read_text().splitlines()
out = []
for l in L:
    if l.startswith('"/OUT:'):
        l = '"/OUT:%s"' % (H / 'linkexp/prof.exe')
    elif l.startswith('"/MAP:'):
        if nomap:
            continue
        l = '"/MAP:%s"' % (H / 'linkexp/prof.map')
    out.append(l)
extra = [a for a in args[1:]]
rsp = H / 'linkexp/prof.rsp'
rsp.write_text('\n'.join(out + ['"/time"'] + extra) + '\n')
if shards:
    import shard_libs
    t = time.time()
    rsp, st = shard_libs.write_sharded_rsp(rsp.read_text().splitlines(), H / 'linkexp/prof.sharded.rsp', H / 'linkexp/shards_prof')
    print('shards: %s in %.1fs' % (st, time.time() - t))
objs = [l for l in L if l.lower().endswith('.obj"')]
libs = [l for l in L if l.lower().endswith('.lib"')]
flags = [l for l in L if l.startswith('"/') and 'alternatename' not in l.lower() and '/include' not in l.lower()]
print('objects %d, libs %d, aliases %d' % (len(objs), len(libs), sum(1 for l in L if 'alternatename' in l.lower())))
print('flags:', ' '.join(f.strip('"') for f in flags)[:600])
ENV = None   # default: the caller's environment (unchanged behaviour)
if envroc:
    try:
        sys.path.insert(0, str(H.parents[1]))
        from roc import rebuild
        ENV = rebuild.env(rebuild.toolchain(21022))
    except Exception as e:   # noqa: BLE001
        print('roc.rebuild environment unavailable (%s): using the current environment' % e)
for k in range(repeat):
    t = time.time()
    r = subprocess.run([LLD, '@' + str(rsp)], capture_output=True, text=True, errors='replace', env=ENV)
    print('lld exit %d in %.1fs%s' % (r.returncode, time.time() - t, '' if repeat == 1 else ' (run %d/%d)' % (k + 1, repeat)))
    if k == repeat - 1:
        for l in (r.stdout + r.stderr).splitlines():
            if not any(w in l.lower() for w in ('warning', 'undefined symbol', '>>>')):
                print('  ' + l[:140])
