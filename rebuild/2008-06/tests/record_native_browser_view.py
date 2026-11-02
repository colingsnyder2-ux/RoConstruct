"""Compile and verify inactive native CBrowserView constructor/destructor."""
from pathlib import Path
import re
import sys
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/native-classes/CBrowserView.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
# Original build imports the CString accessors from mfc90 (as xtp-11.2.2-lib-imports does):
# mark them noinline in the preprocessed unit; source and shared headers stay unchanged.
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags + ["/P", str(source)], out)
assert code == 0, log
body = (out / "CBrowserView.i").read_text(encoding="utf8", errors="replace")
for member in libs.RECIPES["xtp-11.2.2-lib-imports"]["noinline"][:3]:
    assert body.count(member) == 1, member
    body = body.replace(member, "__declspec(noinline) " + member)
body, count = re.subn(r"\bint Compare\([^\n]*PCXSTR psz \) const", lambda m: "__declspec(noinline) " + m.group(0), body)
assert count == 1
translation = out / "NativeBrowserView.cpp"
translation.write_text(body, encoding="utf8")
code, log = rebuild.run(rebuild.toolchain(21022), "cl", [value for value in flags if not value.startswith(("/I", "/D"))]
                        + ["/FoNativeBrowserView.obj", str(translation)], out)
assert code == 0, log
functions = match.coff_functions((out / "NativeBrowserView.obj").read_bytes())
results = []
for address, prefix in (("004108b0", "??0CBrowserView@@"), ("00410950", "??1CBrowserView@@"),
                        ("0040df60", "?GetRuntimeClass@CBrowserView@@"), ("00410e80", "??_GCBrowserView@@"),
                        ("00410ea0", "?OnNavigateComplete2@CBrowserView@@"), ("0040e560", "?OnTitleChange@CBrowserView@@"), ("0040dfd0", "?OnDocumentComplete@CBrowserView@@"),
                        ("0040dfe0", "?OnCommandStateChange@CBrowserView@@"), ("0040dfb0", "?OnGetHostInfo@CBrowserView@@"),
                        ("0040e5b0", "?OnCreate@CBrowserView@@"), ("0040e040", "?OnSize@CBrowserView@@"), ("0040e930", "?OnStop@CBrowserView@@"),
                        ("0040e940", "?OnUpdateStop@CBrowserView@@"), ("0040e790", "?OnHome@CBrowserView@@"),
                        ("0040e130", "?OnUpdateHome@CBrowserView@@"), ("0040e7d0", "?OnRefresh@CBrowserView@@"),
                        ("0042e550", "?OnUpdateAlways@CBrowserView@@"), ("0040e920", "?OnBack@CBrowserView@@"),
                        ("0040e0d0", "?OnUpdateBack@CBrowserView@@"), ("0040e7e0", "?OnForward@CBrowserView@@"),
                        ("0040e0f0", "?OnUpdateForward@CBrowserView@@"), ("0040e110", "?OnUpdateGo@CBrowserView@@"),
                        ("0040e7f0", "?OnGo@CBrowserView@@"), ("0040eda0", "?OnAddressExecute@CBrowserView@@"),
                        ("0040e670", "?OnCreateControl@CBrowserView@@"), ("006e8870", "?OnEraseBkgnd@CBrowserView@@"),
                        ("0040f810", "?GetMessageMap@CBrowserView@@"),
                        ("00410c40", "??0CIDEBrowserView@@"), ("0040df70", "?GetRuntimeClass@CIDEBrowserView@@"),
                        ("00410cd0", "??0CPlayBrowserView@@"), ("0040df80", "?GetRuntimeClass@CPlayBrowserView@@")):
    found = [(n, b, r) for n, b, r in functions if n.startswith(prefix)]
    target, target_relocs, _ = match.target("2008-06", address)
    if not found:
        results.append((address, prefix, "missing")); continue
    name, body, relocs = found[0]
    results.append((address, prefix, match.exact_match(target, target_relocs, body, relocs), len(body), len(target)))
for row in results: print(*row)
assert all(row[2] is True for row in results), "not all exact"
print("PASS: native CBrowserView %d methods match" % len(results))

# Message map entries 0080d420: compare (message, code, id, last id, signature); handlers are relocations.
import pefile, struct
pe = pefile.PE(str(ROOT / "clients/2008-06/Roblox.exe"), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
expected = b""
address = 0x80d420
while True:
    row = pe.get_data(address - base, 24)
    expected += row[:20] + b"\0\0\0\0"
    if row == b"\0" * 24:
        break
    address += 24
obj = (out / "NativeBrowserView.obj").read_bytes()
masked = bytearray(obj)
for offset in range(0, len(obj) - len(expected) + 1):
    if obj[offset:offset + 20] == expected[:20]:
        candidate = bytearray(obj[offset:offset + len(expected)])
        for row in range(0, len(candidate), 24):
            candidate[row + 20:row + 24] = b"\0\0\0\0"
        if bytes(candidate) == expected:
            break
else:
    raise AssertionError("message map entries differ")
print("PASS: message map %d entries match" % (len(expected) // 24 - 1))
