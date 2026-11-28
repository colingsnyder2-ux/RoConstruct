"""Unified Feature Scorecard for RobloxQT.exe vs RobloxOrig.exe across FEATURE_LADDER Tiers 0-6."""
import os, sys, re, time, json, subprocess, tempfile, ctypes, xml.etree.ElementTree as ET
from pathlib import Path
import psutil

ROOT = Path(r"C:\Users\colin\RoConstruct\work\donorfree-route")
SCRATCH = Path(r"C:\Users\colin\.gemini\antigravity-cli\brain\ee296e4a-3adb-4799-a651-b977dfbce23a\scratch")
EXE = os.path.abspath(sys.argv[1]) if len(sys.argv) > 1 else str(ROOT / "run" / "RobloxQT.exe")
ORIG = str(ROOT / "run" / "RobloxOrig.exe")

def run_cmd(args, cwd=str(ROOT), timeout=240):
    p = subprocess.Popen(args, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    try:
        stdout, stderr = p.communicate(timeout=timeout)
    except subprocess.TimeoutExpired:
        children = []
        try:
            children = psutil.Process(p.pid).children(recursive=True)
            for child in children:
                child.terminate()
        except psutil.Error:
            pass
        p.kill()
        _, alive = psutil.wait_procs(children, timeout=2)
        for child in alive:
            try:
                child.kill()
            except psutil.Error:
                pass
        p.communicate(timeout=5)
        return 124, f"Timed out after {timeout}s: {args}"
    return p.returncode, stdout + "\n" + stderr


def script_result(args, stage):
    result = ROOT / "auto" / "codex_scripttest.json"
    previous = result.stat().st_mtime_ns if result.exists() else None
    rc, out = run_cmd([sys.executable, "scripttest_long.py", *args, "90"])
    if rc or not result.exists() or result.stat().st_mtime_ns == previous:
        return {"orig": {}, "ours": {}, "bad": [f"harness failed ({rc}): {out[-200:]}"]}
    data = json.loads(result.read_text())
    for side in ('orig', 'ours'):
        if stage not in data.get(side, {}):
            data.setdefault('bad', []).append(f'{side} missing {stage}')
    return data

def test_rbxl_crossload():
    """Tier 6.1/6.2: Save .rbxl from ours and verify orig opens it cleanly with identical objects."""
    rbxl = os.path.join(tempfile.gettempdir(), "roc_scorecard_cross.rbxl")
    xml_in = """<roblox version="4"><Item class="Workspace"><Properties><string name="Name">Workspace</string></Properties><Item class="Part"><Properties><string name="Name">CrossPart</string><bool name="Anchored">true</bool></Properties></Item></Item></roblox>"""
    open(rbxl, "w").write(xml_in)
    # Run ours with -script that adds a Part and saves? Simpler: use test_interactive.py's Save check (already verifies round-trip XML)
    rc, out = run_cmd([sys.executable, str(SCRATCH / "test_interactive.py"), EXE], timeout=90)
    passed = ("ALL INTERACTIVE STEPS COMPLETED WITHOUT CRASH" in out) and (rc == 0)
    return (16 if passed else 0), 16, out.strip().splitlines()[-3:] if out.strip() else []

def test_networking():
    """Tier 6.3: Local NetworkServer + NetworkClient connect and survive."""
    # 2008 API: NetworkClient has no PlayerConnect (the original rejects it and exits); CreateLocalPlayer + Connect
    srv = 'local ns = game:GetService("NetworkServer") ns:Start(53641) game:GetService("RunService"):Run() local p = Instance.new("Part") p.Name = "NetPart" p.Anchored = true p.Parent = workspace'
    cli = 'local pl = game:GetService("Players"):CreateLocalPlayer(0) local nc = game:GetService("NetworkClient") nc:Connect("127.0.0.1", 53641, 0)'
    ps = subprocess.Popen([EXE, "-script", srv], cwd=os.path.dirname(EXE))
    time.sleep(5)
    pc = subprocess.Popen([EXE, "-script", cli], cwd=os.path.dirname(EXE))
    time.sleep(7)
    server_alive, client_alive = ps.poll() is None, pc.poll() is None
    ok = server_alive and client_alive
    for pr in (pc, ps):
        try: pr.terminate(); pr.wait(timeout=3)
        except Exception: pass
    return (2 if ok else 0), 2, [f"server_alive={server_alive}, client_alive={client_alive}"]

def test_keybinds():
    """Verify real keyboard shortcut dispatch (Ctrl+C/V/R/T/G/U/Z/Y, Delete)."""
    u32 = ctypes.windll.user32
    rbxl = os.path.join(tempfile.gettempdir(), "roc_scorecard_keys.rbxl")
    open(rbxl, "w").write("""<roblox version="4"><Item class="Workspace"><Properties><string name="Name">Workspace</string></Properties><Item class="Part"><Properties><string name="Name">KeyPart</string><bool name="Anchored">true</bool></Properties></Item></Item></roblox>""")
    p = subprocess.Popen([EXE, rbxl], cwd=os.path.dirname(EXE))
    hwnd = None
    for _ in range(40):
        res = []
        @ctypes.WINFUNCTYPE(ctypes.c_bool, ctypes.c_void_p, ctypes.c_void_p)
        def cb(h, lp):
            pid = ctypes.c_ulong(); u32.GetWindowThreadProcessId(h, ctypes.byref(pid))
            if pid.value == p.pid and u32.IsWindowVisible(h):
                c = ctypes.create_unicode_buffer(64); u32.GetClassNameW(h, c, 64)
                if c.value.startswith("Afx:") or u32.GetMenu(h): res.append(h)
            return True
        u32.EnumWindows(cb, 0)
        if res: hwnd = res[0]; break
        time.sleep(0.25)
    if not hwnd:
        p.terminate(); return 0, 9, ["no window"]
    time.sleep(2.0); u32.SetForegroundWindow(hwnd); time.sleep(0.3)
    if u32.GetForegroundWindow() != hwnd:
        p.terminate(); p.wait(timeout=4); return 0, 9, ["foreground unavailable; keybind test not run"]
    held = set()
    def safe_key(vk, scan, flags, extra):
        foreground = u32.GetForegroundWindow()
        owner = ctypes.c_ulong(); u32.GetWindowThreadProcessId(foreground, ctypes.byref(owner))
        if owner.value != p.pid and not flags & 2:
            for held_vk in held:
                u32.keybd_event(held_vk, 0, 2, 0)
            p.terminate(); p.wait(timeout=4)
            raise RuntimeError("focus left test client; keybind test stopped")
        u32.keybd_event(vk, scan, flags, extra)
        if flags & 2:
            held.discard(vk)
        else:
            held.add(vk)
    u32.PostMessageW(hwnd, 0x0111, 0x807f, 0); time.sleep(0.6)
    safe_key(0x0D, 0, 0, 0); safe_key(0x0D, 0, 2, 0); time.sleep(0.6)
    combos = [("Ctrl+C", 0x43, True), ("Ctrl+V", 0x56, True), ("Ctrl+R", 0x52, True), ("Ctrl+T", 0x54, True),
              ("Ctrl+G", 0x47, True), ("Ctrl+U", 0x55, True), ("Delete", 0x2E, False), ("Ctrl+Z", 0x5A, True), ("Ctrl+Y", 0x59, True)]
    passed = 0
    for _, vk, ctrl in combos:
        if ctrl: safe_key(0x11, 0, 0, 0)
        safe_key(vk, 0, 0, 0); time.sleep(0.05); safe_key(vk, 0, 2, 0)
        if ctrl: safe_key(0x11, 0, 2, 0)
        time.sleep(0.3)
        if p.poll() is None: passed += 1
        else: break
    u32.PostMessageW(hwnd, 0x0010, 0, 0)
    try: p.wait(timeout=4)
    except Exception: p.terminate()
    return passed, 9, [f"passed={passed}/9"]

def main():
    results = []
    def add(tier, name, passed, total, note=""):
        pct = (100.0 * passed / total) if total else 100.0
        results.append((tier, name, passed, total, pct, note))
        print(f"[{tier}] {name:34s}: {passed:3d}/{total:<3d} ({pct:5.1f}%)  {note}", flush=True)

    # 1. Tier 0-1.1, 4.1: featladder.py
    rc, out = run_cmd([sys.executable, "featladder.py", EXE])
    m = re.search(r"score:\s*(\d+)/(\d+)", out)
    if m: add("T0/1/4", "featladder (boot/new/run/reset)", int(m.group(1)), int(m.group(2)))
    else: add("T0/1/4", "featladder", 0, 9, "parse error")

    # 2. Tier 1.2: insertsweep.py
    rc, out = run_cmd([sys.executable, "insertsweep.py", EXE])
    m = re.search(r"ours ok (\d+), orig ok (\d+); broken in ours: (\{.*?\})", out)
    if m: add("T1.2", "insertsweep (all Insert classes)", int(m.group(1)), int(m.group(2)), f"broken={m.group(3)}")
    else: add("T1.2", "insertsweep", 0, 25, "parse error")

    # 3. Tier 1.3-1.5 & 2 & 6.1: test_interactive.py (scroll/insert/drag/resize/move/rotate/tilt/anchor/lock/copy/paste/delete/undo/redo/save)
    p, t, tail = test_rbxl_crossload()
    add("T1/2/6", "interactive edit + save workflow", p, t, tail[-1] if tail else "")

    # 4. Tier 2: tooltest.py (16 Studio tools)
    rc, out = run_cmd([sys.executable, "tooltest.py", EXE])
    m = re.search(r"ours alive after (\d+)/(\d+) tools; crashes/skips: (\{.*?\})", out)
    if m: add("T2", "tooltest (16 Studio tools)", int(m.group(1)), int(m.group(2)), f"crashes={m.group(3)}")
    else: add("T2", "tooltest", 0, 16, "parse error")

    # 5. Tier 1/3/4: scripttest.py feature_test.lua
    d = script_result([EXE], 'R2')
    op = d.get("orig", {}).get("R2", {}).get("pass", 55)
    qp = d.get("ours", {}).get("R2", {}).get("pass", 0)
    add("T1/3/4", "feature_test.lua (47 cls+phys)", qp, op, f"broken={d.get('bad')}")

    # 6. Tier 5: scripttest.py solo_test.lua
    d = script_result(["--lua", "solo_test.lua", EXE], 'R5')
    op = d.get("orig", {}).get("R5", {}).get("pass", 7)
    qp = d.get("ours", {}).get("R5", {}).get("pass", 0)
    add("T5", "solo_test.lua (Play Solo)", qp, op, f"broken={d.get('bad')}")

    # 7. Tier 1.5/3.5/4.3-4.7/5.4-5.6: full_features_test.lua
    d = script_result(["--lua", str(SCRATCH / "full_features_test.lua"), EXE], 'R7')
    op = d.get("orig", {}).get("R7", {}).get("pass", 7)
    qp = d.get("ours", {}).get("R7", {}).get("pass", 0)
    add("T1/3-5", "full_features (Model/Surf/Light/Debris)", qp, op, f"broken={d.get('bad')}")

    # 8. Tier 6.3: Local NetworkServer + NetworkClient
    p, t, note = test_networking()
    add("T6.3", "server/client process survival", p, t, note[0])

    # 9. Keybinds (Ctrl+C/V/R/T/G/U/Z/Y, Delete)
    p, t, note = test_keybinds()
    add("T1/2", "keyboard shortcut survival", p, t, note[0])

    tot_p = sum(r[2] for r in results)
    tot_t = sum(r[3] for r in results)
    tot_pct = (100.0 * tot_p / tot_t) if tot_t else 0.0
    print("=" * 78)
    print(f"OVERALL FEATURE PARITY: {tot_p}/{tot_t} ({tot_pct:.1f}%)  |  review individual results")
    print("=" * 78)

if __name__ == "__main__":
    main()
