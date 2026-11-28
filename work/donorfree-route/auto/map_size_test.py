"""Regression: XML lowercase size must reach the Part size setter after opening a place."""
import os
import re
import sys
import tempfile
import time
from pathlib import Path
import frida

root = Path(__file__).resolve().parents[1]
exe = Path(sys.argv[1] if len(sys.argv) > 1 else root / 'run/RobloxQT.exe').resolve()
if exe.name.lower() == 'robloxorig.exe':
    setter = 0x59db90
else:
    pattern = re.compile(r'^\s*0001:[0-9a-f]+\s+\?setPartSizeXml@PartInstance@RBX@@\S+\s+([0-9a-f]{8})\s', re.I)
    setter = next(int(m.group(1), 16) for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines() if (m := pattern.match(line)))
xml = '''<roblox version="4"><Item class="Workspace"><Properties><string name="Name">Workspace</string></Properties><Item class="Part"><Properties><string name="Name">SizeProbe</string><bool name="Anchored">true</bool><token name="FormFactor">2</token><Vector3 name="size"><X>112</X><Y>0.4</Y><Z>496</Z></Vector3></Properties></Item></Item></roblox>'''
with tempfile.TemporaryDirectory(prefix='roc_size_test_') as folder:
    place = Path(folder) / 'size.rbxl'
    place.write_text(xml, encoding='utf-8')
    device = frida.get_local_device()
    device.on('output', lambda *args: None)
    pid = device.spawn([str(exe), str(place)], cwd=str(exe.parent), stdio='pipe')
    session = device.attach(pid)
    values = []
    script = session.create_script('''Interceptor.attach(ptr('%s'), {onEnter(a) { this.obj = this.context.ecx; const p = a[0]; this.value = [p.readFloat(), p.add(4).readFloat(), p.add(8).readFloat()]; }, onLeave() { const p = this.obj.add(0x2c4).readPointer().add(4); send({input: this.value, actual: [p.readFloat(), p.add(4).readFloat(), p.add(8).readFloat()]}); }});''' % hex(setter))
    script.on('message', lambda message, data: values.append(message['payload']) if message.get('type') == 'send' else None)
    script.load()
    device.resume(pid)
    try:
        deadline = time.monotonic() + 40
        while time.monotonic() < deadline and not any(abs(v['actual'][0]-112) < .01 and abs(v['actual'][1]-.4) < .01 and abs(v['actual'][2]-496) < .01 for v in values):
            time.sleep(.2)
    finally:
        try:
            device.kill(pid)
        except frida.ProcessNotFoundError:
            pass
    passed = any(abs(v['actual'][0]-112) < .01 and abs(v['actual'][1]-.4) < .01 and abs(v['actual'][2]-496) < .01 for v in values)
    print('PASS' if passed else 'FAIL', exe.name, 'serialized size setter', values)
    sys.exit(0 if passed else 1)
