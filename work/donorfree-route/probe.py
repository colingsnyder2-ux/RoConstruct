"""python probe.py [secs]: debugger probe of run/RobloxQT.exe (File->New), no relink. First real fault; also breaks in
RobloxCrashReporter::ProcessException (the client's own crash dialog hid AVs from SECOND_CHANCE_ONLY). Stops PROBE_IDLE s
after the last command when nothing crashes. Writes auto/qt_probe.txt."""
import os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
secs = sys.argv[1] if len(sys.argv) > 1 else '40'
_m = re.search(r'^\s*\S+\s+\?ProcessException@RobloxCrashReporter@@\S*\s+([0-9a-f]{8})\s', (H / 'linkexp/qt.map').read_text(errors='replace'), re.M)
import hashlib, json as _j
_h = hashlib.md5((H / 'run/RobloxQT.exe').read_bytes()).hexdigest() + '|' + secs + '|' + os.environ.get('POSTCMD', '0xE100')
_hf = H / 'auto/probe_hash.json'
if not os.environ.get('PROBE_FORCE') and _hf.exists() and _j.loads(_hf.read_text()).get('h') == _h and (H / 'auto/qt_probe.txt').exists():
    print('probe: exe unchanged since the last probe, reusing auto/qt_probe.txt')
    _out = (H / 'auto/qt_probe.txt').read_text(errors='replace')
    for l in _out.splitlines():
        if l.startswith(('exception', 'ENTRY hit', 'crash after', 'NO CRASH')):
            print(l[:170])
    sys.exit(0)
penv = dict(os.environ, FASTFWD='0', ROC_IE_ALLOW='1', ROC_PROBE_VISIBLE='1', SECOND_CHANCE_ONLY='1', POSTCMD=os.environ.get('POSTCMD', '0xE100'),
            BPIMP='_invalid_parameter_noinfo,_purecall,abort,_invoke_watson,_crt_debugger_hook,_amsg_exit', PROBE_IDLE=os.environ.get('PROBE_IDLE', '12'))
if _m and not os.environ.get('BPENTRY'):
    penv.update(BPENTRY=_m.group(1), ENTRY_MEM='**esp+4')   # [ExceptionRecord]: code, flags, record, ADDRESS (+0xc)
p = subprocess.run([sys.executable, str(H.parents[1] / 'work/native-client/shortcut/crashsite.py'), str(H / 'run/RobloxQT.exe'),
                    str(H / 'linkexp/qt.map'), secs], capture_output=True, text=True, env=penv, cwd=H)
(H / 'auto/qt_probe.txt').write_text(p.stdout + p.stderr)
_hf.write_text(_j.dumps({'h': _h}))
for l in p.stdout.splitlines():
    if l.startswith(('FASTFWD', 'exception', 'ENTRY hit', 'process exited', 'C++ throw', '   mem ')):
        print(l[:170])
st = [l for l in p.stdout.splitlines() if l.startswith('  stack ')]
for l in list(dict.fromkeys(st))[:8]:
    print(l[:150])
if not any(l.startswith(('exception', 'ENTRY hit', 'process exited')) for l in p.stdout.splitlines()):
    print('NO CRASH in %ss' % secs)
