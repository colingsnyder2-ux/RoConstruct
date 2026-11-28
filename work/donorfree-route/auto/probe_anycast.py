"""Trace reflection-to-Lua conversion calls for focused feature failures."""
import os, re, time
from pathlib import Path
import capstone, frida, pefile

root = Path(__file__).resolve().parent.parent
symbols = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = line.split()
    if len(p) >= 4 and re.fullmatch(r'[0-9a-fA-F]{8}', p[2]):
        symbols[p[1]] = int(p[2], 16)
push = symbols['func_005aba50']
throw = symbols['_fn_0040a3f0']
anycast = symbols['func_00491690']
pe = pefile.PE(str(root / 'run/RobloxQT.exe'))
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
targets = set()
for i in md.disasm(pe.get_data(push-pe.OPTIONAL_HEADER.ImageBase, 0x700), push):
    if i.mnemonic == 'call' and i.operands[0].type == capstone.x86.X86_OP_IMM:
        target = i.operands[0].imm
        if 0x401000 <= target < 0x8c0000:
            targets.add(target)
exe = str(root / 'run/RobloxQT.exe')
source = (root / 'auto/focus_features.lua').read_text()
pid = frida.spawn([exe, '-script', source], cwd=os.path.dirname(exe))
session = frida.attach(pid)
js = '''
const start = START, end = END;
for (const address of TARGETS) {
  try { Interceptor.attach(ptr(address), {onEnter() {
    const ret = this.returnAddress.toUInt32();
    if (ret >= start && ret < end) send({target: address, ret});
  }}); } catch (e) { send({error: e.toString(), address}); }
}
Interceptor.attach(ptr(THROW), {onEnter() {
  send({throw: true, ret: this.returnAddress.toString(), stack: Thread.backtrace(this.context, Backtracer.FUZZY).slice(0, 12).map(x => x.toString())});
}});
Interceptor.attach(ptr(ANYCAST + 0x35), {onEnter() {
  try { send({actual_type: this.context.eax.add(8).readCString()}); } catch (e) { send({actual_type_error: e.toString()}); }
}});
'''
js = js.replace('START', str(push)).replace('END', str(push+0x700)).replace('TARGETS', str(sorted(targets))).replace('THROW', str(throw)).replace('ANYCAST', str(anycast))
script = session.create_script(js)
script.on('message', lambda m, _: print('TRACE', m.get('payload') or m, flush=True))
script.load(); frida.resume(pid); time.sleep(12); frida.kill(pid)
