"""Capture exceptions from one -script client run.

python codex_script_crash_capture.py EXE --lua FILE [SECS]
"""
import json
import os
import subprocess
import sys
import time
from pathlib import Path

import frida
import ieclean

H = Path(__file__).parent
args = sys.argv[1:]
exe = os.path.abspath(next((a for i, a in enumerate(args) if a.lower().endswith('.exe') and (i == 0 or args[i - 1] != '--orig')), str(H / 'run/RobloxQT.exe')))
lua = Path(args[args.index('--lua') + 1]) if '--lua' in args else H / 'feature_test.lua'
secs = float(args[-1]) if len(args) > 1 and args[-1].replace('.', '', 1).isdigit() else 90.0
code = '\n'.join(l.split('--')[0].strip() for l in lua.read_text().splitlines() if l.split('--')[0].strip())

ieclean.clean()
p = subprocess.Popen([exe, '-script', code], cwd=os.path.dirname(exe))
session = frida.attach(p.pid)
exceptions = []
script = session.create_script("""
const started = Date.now();
Process.setExceptionHandler(function (e) {
    let module = Process.findModuleByAddress(e.address);
    let record = {
        type: e.type,
        address: e.address.toString(),
        module: module ? module.name : null,
        moduleOffset: module ? e.address.sub(module.base).toString() : null,
        eip: e.context.eip.toString(), esp: e.context.esp.toString(),
        eax: e.context.eax.toString(), ecx: e.context.ecx.toString(),
        edx: e.context.edx.toString(), esi: e.context.esi.toString(),
        atMs: Date.now() - started
    };
    try {
        record.exceptionCode = e.context.esp.readU32().toString(16);
        if (record.exceptionCode === 'e06d7363') {
            let info = e.context.esp.add(28).readPointer();
            let types = info.add(12).readPointer();
            let type = types.add(4).readPointer().add(4).readPointer();
            record.cppType = type.add(8).readCString();
        }
    } catch (_) {}
    try {
        record.stack = Thread.backtrace(e.context, Backtracer.ACCURATE)
            .map(x => DebugSymbol.fromAddress(x).toString());
    } catch (_) {}
    send(record);
    return false;
});
""")

def on_message(message, data):
    payload = message.get('payload') if isinstance(message, dict) else None
    if payload is not None:
        exceptions.append(payload)
        print('EXCEPTION', json.dumps(payload), flush=True)
    else:
        print('FRIDA', message, flush=True)

script.on('message', on_message)
script.load()
t0 = time.time()
while time.time() - t0 < secs and p.poll() is None:
    time.sleep(0.5)
code_exit = p.poll()
print('exit=%s after %.1fs exceptions=%d' % (
    ('%#x' % (code_exit & 0xffffffff)) if code_exit is not None else 'alive',
    time.time() - t0, len(exceptions)), flush=True)
try:
    script.unload()
    session.detach()
except Exception:
    pass
if p.poll() is None:
    p.kill()
    p.wait()
out = H / 'auto/codex_script_crash_capture.json'
out.write_text(json.dumps({'exe': exe, 'lua': str(lua), 'secs': secs,
                           'exit': code_exit, 'exceptions': exceptions}, indent=1))
print('wrote', out, flush=True)
