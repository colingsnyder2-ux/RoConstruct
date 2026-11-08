import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch
from roc import clients
import pefile

HERE = Path(__file__).resolve().parents[1] / "rebuild/2008-06/tests"
spec = importlib.util.spec_from_file_location("runner_sdk_trial", HERE / "native_check_runner.py")
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


def archive(symbol, dll):
    name = symbol.encode() + b"\0" + dll.encode() + b"\0"
    member = b"\0\0\xff\xff" + b"\0" * 14 + struct.pack("<H", 3 << 2) + name
    header = b"x/".ljust(16) + b"0".ljust(12) + b"0".ljust(6) + b"0".ljust(6) + b"0".ljust(8) + str(len(member)).encode().ljust(10) + b"`\n"
    return b"!<arch>\n" + header + member + (b"\n" if len(member) & 1 else b"")


class SdkImportTests(unittest.TestCase):
    def test_sdk_alias_is_hashed_and_missing_sdk_fails_closed(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            crt = root / "tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/lib"
            crt.mkdir(parents=True)
            for name in ("msvcrt.lib", "msvcprt.lib"):
                (crt / name).write_bytes(b"!<arch>\n")
            sdk = root / "sdk"
            sdk.mkdir()
            library = sdk / "Kernel32.Lib"
            library.write_bytes(archive("_InterlockedDecrement@4", "KERNEL32.dll"))
            image = root / "client.exe"
            image.write_bytes(b"fixture")
            entry = SimpleNamespace(address=0x8021ac, name=b"InterlockedDecrement")
            descriptor = SimpleNamespace(dll=b"KERNEL32.dll", imports=[entry])
            pe = SimpleNamespace(DIRECTORY_ENTRY_IMPORT=[descriptor], parse_data_directories=lambda **kw: None, close=lambda: None)
            with patch.object(runner, "ROOT", root), patch.object(clients, "load", return_value={"2008-06": {}}), \
                 patch.object(clients, "exe_path", return_value=image), patch.object(pefile, "PE", return_value=pe):
                with patch.object(runner.rebuild, "toolchain", return_value={"sdk_lib": sdk}):
                    labels, aliases, hashes = runner.import_evidence()
                self.assertEqual(labels[0x8021ac], "KERNEL32.dll!InterlockedDecrement")
                self.assertIn("__imp__InterlockedDecrement@4", aliases[("kernel32.dll", "InterlockedDecrement")])
                self.assertIn(str(library), hashes)
                with patch.object(runner.rebuild, "toolchain", return_value={"sdk_lib": None}):
                    _, aliases, hashes = runner.import_evidence()
                self.assertNotIn(("kernel32.dll", "InterlockedDecrement"), aliases)
                self.assertNotIn(str(library), hashes)

if __name__ == "__main__":
    unittest.main()
