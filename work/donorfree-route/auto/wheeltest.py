"""Compare real mouse-wheel input in the viewport and Explorer (requires interactive desktop).

Run only when no other client tests are active. Physical mode temporarily moves the cursor
and foregrounds each spawned client; it restores cursor and foreground on exit. Message
mode sends timed WM_MOUSEWHEEL messages without foregrounding the client. It verifies
delivery and responsiveness only; it cannot verify DirectInput or physical scrolling.
"""
import argparse, ctypes, ctypes.wintypes as w, json, os, subprocess, time
from pathlib import Path
import frida

ROOT = Path(__file__).resolve().parent.parent
user = ctypes.WinDLL('user32', use_last_error=True)
ENUM = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
ULONG_PTR = ctypes.c_size_t


class MouseInput(ctypes.Structure):
    _fields_ = [('dx', w.LONG), ('dy', w.LONG), ('data', w.DWORD),
                ('flags', w.DWORD), ('time', w.DWORD), ('extra', ULONG_PTR)]


class InputUnion(ctypes.Union):
    _fields_ = [('mouse', MouseInput)]


class Input(ctypes.Structure):
    _anonymous_ = ('value',)
    _fields_ = [('type', w.DWORD), ('value', InputUnion)]


user.GetForegroundWindow.restype = w.HWND
user.GetAncestor.argtypes = [w.HWND, w.UINT]
user.GetAncestor.restype = w.HWND
user.WindowFromPoint.argtypes = [w.POINT]
user.WindowFromPoint.restype = w.HWND
user.IsChild.argtypes = [w.HWND, w.HWND]
user.IsChild.restype = w.BOOL
user.SendMessageTimeoutW.argtypes = [w.HWND, w.UINT, w.WPARAM, w.LPARAM, w.UINT, w.UINT, ctypes.POINTER(ULONG_PTR)]
user.SendMessageTimeoutW.restype = w.LPARAM
user.SendInput.argtypes = [w.UINT, ctypes.POINTER(Input), ctypes.c_int]
user.SendInput.restype = w.UINT


def class_name(hwnd):
    buf = ctypes.create_unicode_buffer(128)
    user.GetClassNameW(hwnd, buf, len(buf))
    return buf.value


def windows(pid, parent=None):
    result = []
    def collect(hwnd, _):
        owner = w.DWORD(); user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner))
        if owner.value == pid and user.IsWindowVisible(hwnd):
            result.append(hwnd)
        return True
    callback = ENUM(collect)
    if parent:
        user.EnumChildWindows(parent, callback, 0)
    else:
        user.EnumWindows(callback, 0)
    return result


def title(hwnd):
    buf = ctypes.create_unicode_buffer(256)
    user.GetWindowTextW(hwnd, buf, len(buf))
    return buf.value


def responsive(hwnd):
    result = ULONG_PTR()
    return bool(user.SendMessageTimeoutW(hwnd, 0, 0, 0, 2, 1500, ctypes.byref(result)))


def send_wheel_messages(hwnd, point, process):
    delivered = 0
    position = ctypes.c_int32((point.x & 0xffff) | ((point.y & 0xffff) << 16)).value
    for delta in (120, -120) * 6:
        reply = ULONG_PTR()
        wheel = (delta & 0xffff) << 16
        if not user.SendMessageTimeoutW(hwnd, 0x20a, wheel, position, 2, 1500, ctypes.byref(reply)):
            break
        delivered += 1
        if process.poll() is not None: break
        time.sleep(.15)
    return delivered


def select_target(main, pid, target):
    children = windows(pid, main)
    if target == 'explorer':
        return next((h for h in children if class_name(h) == 'SysTreeView32'), None)
    views = []
    for hwnd in children:
        r = w.RECT(); user.GetClientRect(hwnd, ctypes.byref(r))
        if class_name(hwnd).startswith('Afx:') and r.right >= 200 and r.bottom >= 150:
            views.append((r.right * r.bottom, hwnd))
    return max(views)[1] if views else None


def run(exe, target, mode):
    exe = os.path.abspath(exe)
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    events, faults, session = [], [], None
    result = {'exe': exe, 'target': target, 'input_mode': mode}
    try:
        session = frida.attach(p.pid)
        script = session.create_script('''
            for (const name of ['DispatchMessageA', 'DispatchMessageW']) {
              const fn = Module.findExportByName('user32.dll', name);
              if (fn) Interceptor.attach(fn, {onEnter(args) {
                try { const msg = args[0]; if (msg.add(4).readU32() === 0x20a)
                  send({kind:'wheel', hwnd:msg.readPointer().toString(), data:msg.add(8).readU32()});
                } catch (e) {}
              }});
            }
            Process.setExceptionHandler(function(d) {
              if (d.type !== 'access-violation') return false;
              let stack = []; try { stack = Thread.backtrace(d.context, Backtracer.ACCURATE).slice(0, 16).map(p => p.toString()); } catch (e) {}
              send({kind:'fault', pc:d.context.pc.toString(), address:d.memory ? d.memory.address.toString() : '?', stack});
              return false;
            });
        ''')
        def on_message(message, _):
            data = message.get('payload', {})
            if data.get('kind') == 'wheel': events.append(data)
            elif data.get('kind') == 'fault': faults.append(data)
        script.on('message', on_message); script.load()
        deadline = time.monotonic() + 30; main = None
        while time.monotonic() < deadline and p.poll() is None:
            main = next((h for h in windows(p.pid) if class_name(h).startswith('Afx:')), None)
            if main: break
            time.sleep(.25)
        if not main:
            result['status'] = 'no main window'; return result
        user.PostMessageW(main, 0x111, 0xe100, 0)
        deadline = time.monotonic() + 15
        while time.monotonic() < deadline and p.poll() is None and '[Place1]' not in title(main):
            time.sleep(.25)
        if '[Place1]' not in title(main):
            result['status'] = 'File New incomplete'; return result
        time.sleep(3)
        target_window = select_target(main, p.pid, target)
        if not target_window:
            result['status'] = 'target missing'; return result
        rect = w.RECT(); user.GetClientRect(target_window, ctypes.byref(rect))
        point = w.POINT(rect.right // 2, rect.bottom // 2)
        user.ClientToScreen(target_window, ctypes.byref(point))
        if mode == 'message':
            delivered = send_wheel_messages(target_window, point, p)
            time.sleep(2)
            result.update(delivered=delivered, faults=faults, wheel_messages=events,
                          limitation='Simulated WM_MOUSEWHEEL; DirectInput and camera motion are not verified.')
            if p.poll() is not None:
                result['status'] = 'exit 0x%08X' % (p.returncode & 0xffffffff)
            elif delivered != 12 or not responsive(main):
                result['status'] = 'message delivery timed out or window unresponsive'
            else:
                result['status'] = 'ok'
            return result
        user.SetForegroundWindow(main); time.sleep(.5)
        if user.GetAncestor(user.GetForegroundWindow(), 2) != user.GetAncestor(main, 2):
            result['status'] = 'foreground unavailable'; return result
        user.SetCursorPos(point.x, point.y); time.sleep(.25)
        result['window_under_cursor'] = hex(user.WindowFromPoint(point) or 0)
        for flags in (0x0002, 0x0004):
            event = Input(); event.type = 0
            event.mouse = MouseInput(0, 0, 0, flags, 0, 0)
            if user.SendInput(1, ctypes.byref(event), ctypes.sizeof(event)) != 1:
                result['status'] = 'focus click injection failed'; return result
        time.sleep(.5)
        if p.poll() is not None:
            result.update(status='crash before wheel 0x%08X' % (p.returncode & 0xffffffff), faults=faults)
            return result
        events.clear(); sent = 0
        for delta in (120, -120) * 6:
            event = Input(); event.type = 0
            event.mouse = MouseInput(0, 0, delta & 0xffffffff, 0x0800, 0, 0)
            sent += user.SendInput(1, ctypes.byref(event), ctypes.sizeof(event))
            time.sleep(.15)
            if p.poll() is not None: break
        time.sleep(2)
        result.update(sent=sent, wheel_messages=events, faults=faults)
        if p.poll() is not None:
            result['status'] = 'exit 0x%08X' % (p.returncode & 0xffffffff)
        elif sent != 12:
            result['status'] = 'input injection incomplete'
        elif not responsive(main):
            result['status'] = 'window unresponsive'
        elif not any(int(event['hwnd'], 16) == target_window or user.IsChild(target_window, int(event['hwnd'], 16)) for event in events):
            result['status'] = 'inconclusive: no wheel message reached target'
        else:
            result['status'] = 'ok'
        return result
    finally:
        if p.poll() is None: p.kill()
        if session:
            try: session.detach()
            except frida.InvalidOperationError: pass


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--target', choices=('explorer', 'viewport', 'both'), default='both')
    parser.add_argument('--input', choices=('physical', 'message'), default='physical',
                        help='physical SendInput or simulated timed WM_MOUSEWHEEL messages')
    parser.add_argument('--exe', default=str(ROOT / 'run/RobloxQT.exe'))
    parser.add_argument('--orig', default=str(ROOT / 'run/RobloxOrig.exe'))
    args = parser.parse_args()
    cursor = w.POINT(); user.GetCursorPos(ctypes.byref(cursor)); previous = user.GetForegroundWindow()
    rows = []
    try:
        for target in (('explorer', 'viewport') if args.target == 'both' else (args.target,)):
            for exe in (args.orig, args.exe):
                row = run(exe, target, args.input); rows.append(row)
                print(args.input, target, Path(exe).name, row['status'], flush=True)
    finally:
        if args.input == 'physical':
            user.SetCursorPos(cursor.x, cursor.y)
            if previous: user.SetForegroundWindow(previous)
        (ROOT / 'auto/wheeltest.json').write_text(json.dumps(rows, indent=2))
    return 0 if rows and all(row['status'] == 'ok' for row in rows) else 1


if __name__ == '__main__':
    raise SystemExit(main())
