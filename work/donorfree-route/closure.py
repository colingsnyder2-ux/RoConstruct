"""python closure.py [--rounds N]: convert mined 100% analogs for the File->New path and everything they call, until closed.
Round: rename.py (ROC_RENAME_DEFINED = symbols the donor-free link defines, plus the set) -> every func_<addr> a converted
object references that is not converted yet and has a 100% analog joins the set -> repeat. Unnamed or link-undefined
callees are func_<addr>; addresses without an analog stay unresolved (stub, or an LLM draft via auto_aliases).
Then: python renamed_link.py && python boot.py renamed/results.json --full"""
import json, os, re, shutil, subprocess, sys
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
R = H / 'renamed'
rounds = int(sys.argv[sys.argv.index('--rounds') + 1]) if '--rounds' in sys.argv else 6
ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))


def analog(a):
    p = ROOT / 'src/2008-06' / (a + '.cpp')
    return p.exists() and p.read_text(errors='replace').startswith('// from server: 100%')


amap = json.load(open(R / 'addrmap.json'))
for rnd in range(1, rounds + 1):
    (R / 'addrmap.json').write_text(json.dumps(amap, indent=0))
    subprocess.run([sys.executable, str(H / 'defined_now.py')], capture_output=True)   # names the link defines NOW (not ever)
    if rnd == 1 and '--incremental' not in sys.argv:   # earlier conversions stay valid as the set grows (new jobs only add func_ names): convert only new ones later
        shutil.rmtree(R / 'obj', ignore_errors=True)
        (R / 'rename.json').unlink(missing_ok=True)
    env = dict(os.environ, ROC_ADDRMAP=str(R / 'addrmap.json'), ROC_RENAME_OUT=str(R / 'obj'), ROC_RENAME_JSON=str(R / 'rename.json'),
               ROC_RENAME_PLACEHOLDER='1', ROC_RENAME_DEFINED=str(R / 'defined.json'), ROC_RENAME_KEEP_HELPERS='1')
    _tried = json.load(open(R / 'rename.json')) if (R / 'rename.json').exists() else {}
    _sel = sorted(v['exact'][0] for v in amap.values() if v['exact'][0] not in _tried)   # never retry recorded failures (was ~140 serial compiles per round)
    if _sel:   # 16 parallel rename.py processes, each with its own result file, merged after (was serial)
        procs = []
        for k_ in range(16):
            part = _sel[k_::16]
            if part:
                e_ = dict(env, ROC_RENAME_JSON=str(R / ('rename_c%d.json' % k_)))
                (R / ('rename_c%d.json' % k_)).unlink(missing_ok=True)
                procs.append((k_, part, subprocess.Popen([sys.executable, str(ROOT / 'work/native-client/rename.py')] + part, env=e_, cwd=ROOT,
                                                         stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)))
        merged = json.load(open(R / 'rename.json')) if (R / 'rename.json').exists() else {}
        for k_, part, p_ in procs:
            p_.wait()
            try:
                got = json.load(open(R / ('rename_c%d.json' % k_)))
                merged.update({a: got[a] for a in part if a in got})
            except Exception:
                pass
        (R / 'rename.json').write_text(json.dumps(merged, indent=1))
    res = json.load(open(R / 'rename.json'))
    have = {v['exact'][0] for v in amap.values()}
    new = set()
    for r in res.values():
        for tgt in (r.get('renamed') or {}).values():
            m = re.fullmatch(r'func_([0-9a-f]{8})', tgt)
            if m and m.group(1) not in have and analog(m.group(1)):
                new.add(m.group(1))
    ok = sum(1 for r in res.values() if r.get('status') == 'renamed')
    print('round %d: %d jobs, %d converted, %d new callees with analogs' % (rnd, len(amap), ok, len(new)), flush=True)
    if not new:
        break
    for a in sorted(new):
        amap['func_' + a] = {'exact': [a]}
