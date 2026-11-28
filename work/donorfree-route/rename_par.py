"""python rename_par.py [N]: run rename.py over every job in renamed/addrmap.json in N parallel processes (default 4), fresh;
merges the per-chunk results into renamed/rename.json. Donor-free mode (ROC_RENAME_DEFINED = renamed/defined.json)."""
import json, os, shutil, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
ROOT = H.parents[1]
R = H / 'renamed'
n = int(sys.argv[1]) if len(sys.argv) > 1 and sys.argv[1].isdigit() else 4
amap = json.load(open(R / 'addrmap.json'))
subprocess.run([sys.executable, str(H / 'defined_now.py')], capture_output=True)   # names the link defines NOW (not ever)
addrs = sorted(v['exact'][0] for v in amap.values())
RETRY = sys.argv[sys.argv.index('--retry') + 1] if '--retry' in sys.argv else None   # e.g. --retry compile: only those failures
old = json.load(open(R / 'rename.json')) if (R / 'rename.json').exists() else {}
HAS = sys.argv[sys.argv.index('--has') + 1].encode() if '--has' in sys.argv else None   # --has BYTES: only analogs whose compiled object contains BYTES
ONLY = sys.argv[sys.argv.index('--addrs') + 1] if '--addrs' in sys.argv else None   # --addrs FILE.json: reconvert just these
if HAS:   # e.g. --has __unwindfunclet$ : reconvert only what a converter fix can change
    _src = ROOT / 'work/native-client/rename'
    _sel = []
    for a in addrs:
        try:
            _f = next((d / (a + '.obj') for d in (_src, R / 'obj_full', R / 'obj') if (d / (a + '.obj')).exists()), _src / (a + '.obj'))
            if HAS in _f.read_bytes():   # compiled-analog cache can miss objects (stub_exact jobs): fall back to ours
                _sel.append(a)
        except OSError:
            pass
    _ss = set(_sel)
    addrs = [a for a in addrs if a in _ss and (old.get(a) or {}).get('status') == 'renamed']
    RETRY = RETRY or 'has'
elif ONLY:
    _o = set(json.load(open(ONLY))); addrs = [a for a in addrs if a in _o]; RETRY = RETRY or 'addrs'
elif RETRY:
    addrs = [a for a in addrs if (old.get(a) or {}).get('status') == RETRY]
else:
    shutil.rmtree(R / 'obj', ignore_errors=True)
# whole library units per worker (Sky.cpp holds 252 analogs): with ROC_UNIT_MEMO each worker expands a unit once.
# Largest groups first onto the least-loaded worker keeps the chunks even
import re as _re
_grp = {}
for a in addrs:
    try:
        with open(ROOT / 'src/2008-06' / (a + '.cpp'), errors='replace') as _f:
            _m = _re.search(r'//\s*roc-lib:\s*(\S+\s+\S+)', _f.read(4096))
    except OSError:
        _m = None
    _grp.setdefault(_m.group(1) if _m else a, []).append(a)
_parts = [[] for _ in range(n)]
for _g in sorted(_grp.values(), key=len, reverse=True):
    min(_parts, key=len).extend(_g)
_psets = [set(p_) for p_ in _parts]
procs = []
for k in range(n):
    part = _parts[k]
    env = dict(os.environ, ROC_ADDRMAP=str(R / 'addrmap.json'), ROC_RENAME_OUT=str(R / 'obj'), ROC_RENAME_JSON=str(R / ('rename_%d.json' % k)),
               ROC_RENAME_PLACEHOLDER='1', ROC_UNIT_MEMO='1', ROC_RENAME_DEFINED=str(R / 'defined.json'), ROC_RENAME_KEEP_HELPERS='1')
    (R / ('rename_%d.json' % k)).unlink(missing_ok=True)
    procs.append(subprocess.Popen([sys.executable, str(ROOT / 'work/native-client/rename.py')] + part, env=env, cwd=ROOT,
                                  stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL))
for p in procs:
    p.wait()
res = dict(old) if RETRY else {}
for k in range(n):
    if not (R / ('rename_%d.json' % k)).exists():
        continue
    for a, r in json.load(open(R / ('rename_%d.json' % k))).items():
        if a in _psets[k] or a not in res:
            res[a] = r
# workers that died (memory, hard crash) leave addresses without a result: retry those once with fewer processes
_seen = set()
for k in range(n):
    if (R / ('rename_%d.json' % k)).exists():
        _seen |= set(json.load(open(R / ('rename_%d.json' % k))))
_lost = [a for a in addrs if a not in _seen]
if _lost and not os.environ.get('ROC_RENAME_RETRY'):
    print('%d addresses lost by dead workers: retrying with 4 processes' % len(_lost), flush=True)
    (R / 'rename.json').write_text(json.dumps(res, indent=1))
    (R / 'lost_addrs.json').write_text(json.dumps(_lost))
    subprocess.run([sys.executable, str(H / 'rename_par.py'), '4', '--addrs', str(R / 'lost_addrs.json')], env=dict(os.environ, ROC_RENAME_RETRY='1'))
    res = json.load(open(R / 'rename.json'))
(R / 'rename.json').write_text(json.dumps(res, indent=1))
from collections import Counter
print(Counter(r.get('status') for a, r in res.items() if a in set(addrs)))
