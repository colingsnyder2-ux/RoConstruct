"""Compare original CRobloxWnd RTTI bases to native compiler layout."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeWindowBases.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/d1reportSingleClassLayoutNativeWindowBases", "/FoNativeWindowBases.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
assert "class NativeWindowBases\tsize(92):" in log
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack("<I", pe.get_data(address - base, 4))[0]
locator = read32(0x8199f4 - 4)
assert pe.get_string_at_rva(read32(locator + 12) - base + 8) == b".?AVCRobloxWnd@@"
hierarchy = read32(locator + 16)
array = read32(hierarchy + 12)
native = {}
for index in range(read32(hierarchy + 8)):
    descriptor = read32(array + 4 * index)
    name = pe.get_string_at_rva(read32(descriptor) - base + 8).decode("ascii")
    offset = struct.unpack("<i", pe.get_data(descriptor + 8 - base, 4))[0]
    native[name] = offset
expected = (("IRunView", ".?AVIRunView@RBX@@", 0x54),
            ("IMetric", ".?AVIMetric@RBX@@", 0x58))
for name, native_name, offset in expected:
    assert native[native_name] == offset
    marker = next(line for line in log.splitlines() if line.startswith("NativeWindowBases::$vftable@") and name in line)
    position = log.index(marker)
    assert "| -%d" % offset in log[position:position + 220]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
files = [source, ROOT / "rebuild/2008-06/native-headers/util/RunStateOwner.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): sha(p) for p in files}, original_sha256=sha(original),
               compiler_build=21022, base_extent=92, bases={name: offset for name, _, offset in expected},
               scope="Base hierarchy probe only; complete 0xc0 window members, virtual bodies and runtime linkage remain open.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: two CRobloxWnd base offsets against native RTTI")
