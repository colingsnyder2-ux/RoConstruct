"""Restore desktop RTM ATL/MFC from existing MSI-keyed cabinet extraction.

The original extractor discarded the path before atlmfc and let CE files
overwrite desktop files. This repair retains that tree and all affected caches.
No download, guessed headers, or proprietary source added to Git.
"""
import json
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "work/claude-continuation-20261011/rtm-desktop-repair"


def desktop_files(rows):
    return [row for row in rows if "\\vc7\\atlmfc\\" in row["path"].lower()
            and any(part in row["path"].lower() for part in
                    ("\\atlmfc\\include\\", "\\atlmfc\\src\\"))]


def repair():
    media = ROOT / "tools/dl/vs2008pro"
    rows = desktop_files(json.loads((media / "atlmfc-files.json").read_text()))
    missing = [row["key"] for row in rows if not (media / "raw" / row["key"]).is_file()]
    if missing:
        raise ValueError("Missing desktop cabinet members: " + repr(missing))
    OUTPUT.mkdir(parents=True, exist_ok=True)
    destination = ROOT / "tools/libs/mfc-9.0-rtm"
    backup = OUTPUT / "mixed-desktop-ce-tree"
    assert destination.resolve().is_relative_to(ROOT / "tools/libs")
    if not backup.exists():
        shutil.move(str(destination), str(backup))
    elif (OUTPUT / "manifest.json").exists():
        raise ValueError("Repair already recorded; refusing to overwrite it")
    for row in rows:
        relative = row["path"][row["path"].lower().index("\\atlmfc\\") + 1:].replace("\\", "/")
        path = destination / relative
        assert path.resolve().is_relative_to(destination)
        path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(media / "raw" / row["key"], path)
    cache_root = ROOT / "work/libcache"
    for folder in cache_root.glob("*-rtm"):
        target = OUTPUT / "old-cache" / folder.name
        assert folder.resolve().is_relative_to(cache_root)
        assert target.resolve().is_relative_to(OUTPUT)
        if target.exists():
            raise ValueError("Cache backup exists: " + str(target))
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.move(str(folder), str(target))
    (OUTPUT / "manifest.json").write_text(json.dumps(rows, indent=2))
    print("Restored", len(rows), "desktop files; CE excluded; original tree/caches preserved")


if __name__ == "__main__":
    repair()
