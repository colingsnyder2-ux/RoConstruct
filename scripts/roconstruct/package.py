#!/usr/bin/env python3
"""Assemble an offline sandbox package without copying client binaries."""
import argparse
import json
import os
import shutil
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description="Build local offline sandbox package")
    parser.add_argument("--out", default=str(ROOT / "work" / "playable"))
    args = parser.parse_args()
    out = Path(args.out).resolve()
    source = out / "source"
    source.mkdir(parents=True, exist_ok=True)
    copied = []
    for path in sorted((ROOT / "reconstructed").glob("**/*.cpp")):
        target = source / path.relative_to(ROOT / "reconstructed")
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(path, target); copied.append(str(target))
    demo = ROOT / "examples" / "tiny_demo"
    for path in (demo / "demo_source.c", demo / "demo_main.c", demo / "CMakeLists.txt"):
        if path.exists():
            shutil.copy2(path, source / path.name); copied.append(str(source / path.name))
    source_root = Path(os.environ.get("ROCONSTRUCT_SOURCE_ROOT", str(ROOT / "source")))
    if source_root.exists():
        for path in source_root.rglob("*"):
            if path.is_file() and path.suffix.lower() in (".c", ".cc", ".cpp", ".h", ".hpp"):
                target = source / "client" / path.relative_to(source_root)
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(path, target); copied.append(str(target))
    manifest = json.loads((ROOT / "third_party" / "manifest.json").read_text(encoding="utf-8"))
    missing = [item["name"] for item in manifest["dependencies"]
               if not (ROOT / "third_party" / item["name"].lower().replace(" ", "-")).exists()
               and not item.get("optional")]
    report = {"ready_for_link": bool(copied) and not missing, "source_files": copied,
              "missing_dependencies": missing, "client_files_included": False,
              "next": "build third-party deps, then link source" if missing else "run CMake build"}
    (out / "build-report.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("SANDBOX // source files: %d" % len(copied))
    print("SANDBOX // missing open-source deps: %s" % (", ".join(missing) if missing else "none"))
    print("SANDBOX // client binaries included: no")
    print("SANDBOX // report: %s" % (out / "build-report.json"))
    return 0 if copied else 1


if __name__ == "__main__":
    raise SystemExit(main())
