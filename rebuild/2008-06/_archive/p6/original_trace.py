"""Record startup order in the unmodified original with one-shot int3 breakpoints.
Patches process memory only, never the file. Needs a DESKTOP LOCK; 32-bit target,
64-bit Python. Terminates only the process it started."""
import ctypes, json, struct, sys, time
from ctypes import wintypes as w

SITES = {0x6a1ba6: "entry", 0x7bca00: "WinMain thunk", 0x44d810: "InitInstance", 0x44d8ed: "InitCommonControls call",
         0x44da5c: "nativeInitializeCom", 0x44da67: "CRobloxCommandLineInfo", 0x44daf4: "profiler enable", 0x44dafc: "initializeTypes",
         0x44db4e: "initializeSettings", 0x449910: "CIDEDocManager ctor", 0x449bf0: "initializeFramework", 0x431d00: "CMainFrame OnCreate",
         0x44d1b0: "openFiles", 0x44d790: "CRobloxApp slot 23", 0x44ad60: "ExitInstance"}
k = ctypes.WinDLL("kernel32", use_last_error=True)
for name, args, res in (("ReadProcessMemory", [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p], w.BOOL),
                        ("WriteProcessMemory", [w.HANDLE, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p], w.BOOL),
                        ("FlushInstructionCache", [w.HANDLE, ctypes.c_void_p, ctypes.c_size_t], w.BOOL),
                        ("OpenThread", [w.DWORD, w.BOOL, w.DWORD], w.HANDLE),
                        ("TerminateProcess", [w.HANDLE, w.UINT], w.BOOL)):
    getattr(k, name).argtypes, getattr(k, name).restype = args, res


class StartupInfo(ctypes.Structure):
    _fields_ = [("cb", w.DWORD), ("r", ctypes.c_byte * 100)]


class ProcessInfo(ctypes.Structure):
    _fields_ = [("hProcess", w.HANDLE), ("hThread", w.HANDLE), ("pid", w.DWORD), ("tid", w.DWORD)]


exe, place, out = sys.argv[1:4]
info, pi = StartupInfo(), ProcessInfo()
info.cb = 104
if not k.CreateProcessW(exe, f'"{exe}" "{place}"', None, None, False, 2, None, exe.rsplit(chr(92), 1)[0], ctypes.byref(info), ctypes.byref(pi)):
    sys.exit(ctypes.get_last_error())
event = ctypes.create_string_buffer(176)
saved, hits, start = {}, [], time.time()
while time.time() - start < 12:
    if not k.WaitForDebugEvent(event, 200):
        continue
    code, pid, tid = struct.unpack_from("<III", event.raw, 0)
    status = 0x00010002  # DBG_CONTINUE
    if code == 3:  # process created
        for va in SITES:
            old = ctypes.c_ubyte()
            k.ReadProcessMemory(pi.hProcess, va, ctypes.byref(old), 1, None)
            saved[va] = old.value
            cc = ctypes.c_ubyte(0xCC)
            k.WriteProcessMemory(pi.hProcess, va, ctypes.byref(cc), 1, None)
        k.FlushInstructionCache(pi.hProcess, None, 0)
    elif code == 1:  # exception
        number, = struct.unpack_from("<I", event.raw, 16)
        address, = struct.unpack_from("<Q", event.raw, 32)
        if number in (0x80000003, 0x4000001F) and address in saved:
            hits.append({"va": "%08x" % address, "name": SITES[address], "seconds": round(time.time() - start, 3)})
            byte = ctypes.c_ubyte(saved.pop(address))
            k.WriteProcessMemory(pi.hProcess, address, ctypes.byref(byte), 1, None)
            k.FlushInstructionCache(pi.hProcess, None, 0)
            thread = k.OpenThread(0x1FFFFF, False, tid)
            context = ctypes.create_string_buffer(716 + 16)
            base = (ctypes.addressof(context) + 15) & ~15
            ctypes.memmove(base, struct.pack("<I", 0x10001), 4)
            k.Wow64GetThreadContext(thread, ctypes.c_void_p(base))
            ctypes.memmove(base + 0xB8, struct.pack("<I", address), 4)
            k.Wow64SetThreadContext(thread, ctypes.c_void_p(base))
            k.CloseHandle(thread)
        elif number not in (0x80000003, 0x4000001F):
            status = 0x80010001  # pass to the target
    elif code == 5:
        break
    k.ContinueDebugEvent(pid, tid, status)
k.TerminateProcess(pi.hProcess, 0)
json.dump({"hits": hits, "not_hit": sorted(SITES[v] for v in saved)}, open(out, "w"), indent=1)
for hit in hits:
    print(hit["seconds"], hit["va"], hit["name"])
print("not hit:", sorted(SITES[v] for v in saved))
