"""Reference ingestion must preserve provenance and reject unsafe kits."""
import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest
import zipfile

from research.mobile_reference import export_member, install, macho_records


class MobileReferenceTests(unittest.TestCase):
    def test_macho_preserves_debug_map_and_symbol_addresses(self):
        names = b"\0App/util/Name.cpp\0__ZN3RBX4Name11getNullNameEv\0"
        entries = [(1, 0x64, 0, 0, 0), (19, 0x24, 1, 0, 0x367da8), (0, 0x24, 0, 0, 36)]
        header = struct.pack("<7I", 0xfeedface, 12, 9, 2, 1, 24, 0)
        table = b"".join(struct.pack("<IBBHI", *entry) for entry in entries)
        cmd = struct.pack("<6I", 2, 24, 52, len(entries), 52 + len(table), len(names))
        records, sections = macho_records(header + cmd + table + names)
        self.assertEqual(records[0][-1], "App/util/Name.cpp")
        self.assertEqual(records[1][3:], (0x367da8, "__ZN3RBX4Name11getNullNameEv"))
        self.assertEqual(records[2][3], 36)
        self.assertEqual(sections, [])

    def test_invalid_macho_bounds_rejected(self):
        header = struct.pack("<7I", 0xfeedface, 12, 9, 2, 1, 24, 0)
        command = struct.pack("<6I", 2, 24, 10000, 1, 20000, 1)
        with self.assertRaisesRegex(ValueError, "bounds"):
            macho_records(header + command)

    def test_export_paths_reject_windows_and_parent_traversal(self):
        prefix = "/dump/ios-2013-12_2.132.41333/"
        self.assertEqual(export_member(prefix + "RBX/getNullName.c"), "RBX/getNullName.c")
        for path in ("../escape", "RBX/../../escape", "C:/escape", "RBX\\..\\escape"):
            with self.assertRaises(ValueError):
                export_member(prefix + path)

    def test_install_checks_archive_and_member_hashes_without_overwrite(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            archive = base / "kit.zip"
            body = b"reference text"
            inventory = {"docs/evidence.txt": hashlib.sha256(body).hexdigest()}
            with zipfile.ZipFile(archive, "w") as kit:
                kit.writestr("reference-kit.json", json.dumps(dict(files=inventory)))
                kit.writestr("docs/evidence.txt", body)
            digest = hashlib.sha256(archive.read_bytes()).hexdigest()
            with self.assertRaisesRegex(ValueError, "SHA-256"):
                install(archive, "0" * 64, base / "bad")
            install(archive, digest, base / "installed")
            self.assertEqual((base / "installed/docs/evidence.txt").read_bytes(), body)
            with self.assertRaisesRegex(ValueError, "exists"):
                install(archive, digest, base / "installed")

    def test_traversal_kit_cannot_write_outside_destination(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            archive = base / "bad.zip"
            body = b"bad"
            inventory = {"../escape": hashlib.sha256(body).hexdigest()}
            with zipfile.ZipFile(archive, "w") as kit:
                kit.writestr("reference-kit.json", json.dumps(dict(files=inventory)))
                kit.writestr("../escape", body)
            digest = hashlib.sha256(archive.read_bytes()).hexdigest()
            with self.assertRaisesRegex(ValueError, "Unsafe"):
                install(archive, digest, base / "installed")
            self.assertFalse((base / "escape").exists())


if __name__ == "__main__":
    unittest.main()
