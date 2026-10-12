"""Emit genuine G3D inline methods through class exports; 2008-only exact matching."""
import argparse
import json
import re
from collections import defaultdict

from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match


def run(all_classes=False):
    campaign = Campaign("work/g3d-inline-2008", "http://127.0.0.1:8765")
    client, recipe = "2008-06", "g3d-6.09"
    folder = libs.fetch(recipe)
    rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
    scores = {r["addr"]: r["score"] for r in rows}
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    for addr, function in match._functions(client).items():
        if function.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    build = campaign.info["clients"][client]["compiler_build"]
    base, image = match._image(client)
    image = bytes(image)
    done = {(r.get("directory", "G3Dcpp"), r["class"], r["flags"]) for r in campaign.previous("compile") if "error" not in r}
    cohort = [("G3Dcpp", name) for name in
              ("Vector3", "Vector2", "Matrix3", "Color3", "Color4", "Quat", "Plane", "Box", "AABox", "CoordinateFrame")]
    if all_classes:
        cohort = [(directory, header.stem) for directory, include in (("G3Dcpp", "G3D"), ("GLG3Dcpp", "GLG3D"))
                  for header in sorted((folder / "include" / include).glob("*.h"))
                  if (folder / directory / (header.stem + ".cpp")).exists()
                  and re.search(r'\bclass\s+' + re.escape(header.stem) + r'(?:\s*:[^;{}]*)?\s*\{',
                                header.read_text(errors="replace"))]
    manifest = campaign.root / ("manifest-all.json" if all_classes else "manifest-pilot.json")
    if not manifest.exists():
        manifest.write_text(json.dumps({"client": client, "recipe": recipe, "classes": cohort}, indent=2))
    for directory, name in cohort:
        header = folder / "include" / ("G3D" if directory == "G3Dcpp" else "GLG3D") / (name + ".h")
        original = header.read_text(errors="replace")
        declaration = re.search(r'\bclass\s+' + re.escape(name) + r'(?=(?:\s*:[^;{}]*)?\s*\{)', original)
        row = {"class": name, "directory": directory}
        if not declaration:
            campaign.record("compile", {**row, "error": "class declaration not found"})
            continue
        filename = str(header.resolve())
        offset = image.find((name + ".h\0").encode())
        if offset >= 0:
            value = image[image.rfind(b"\0", 0, offset) + 1:offset + len(name) + 2]
            if value and all(32 <= byte <= 126 for byte in value):
                filename = value.decode("ascii")
        text = "#line 1 " + json.dumps(filename) + "\n" + original[:declaration.start()] + \
               "class __declspec(dllexport) " + name + original[declaration.end():]
        copy = header.with_name("roc_export_" + digest(text)[:16] + ".h")
        copy.write_text(text)
        body = '#include "%s"\n#include "%s"\n' % (copy.as_posix(), (folder / directory / (name + ".cpp")).as_posix())
        wrapper = folder / directory / ("roc_export_" + digest(body)[:16] + ".cpp")
        wrapper.write_text(body)
        grid = ("/O2 /GS- /EHsc /MD /fp:fast",) if all_classes else (
            "/O2 /GS- /EHsc /MD /fp:fast", "/O2 /GS- /EHsc /MD", "/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast")
        for flags in grid:
            if (directory, name, flags) in done:
                continue
            row = {"class": name, "directory": directory, "flags": flags, "header_sha256": digest(text), "wrapper": str(wrapper)}
            try:
                file_flags = flags + " /DSDL_main=main" if name == "GApp" else flags
                source = libs.source_for(recipe, wrapper.relative_to(folder).as_posix(), "cpp", build, file_flags)
                obj = match.compile_text(client, source)
                functions = list(match.coff_functions(obj))
                row["emitted_functions"] = len(functions)
                hits = target.match_obj(obj, source)
                row["hits"] = {addr: hit[1] for addr, hit in hits.items()}
                for addr in hits:
                    result = campaign.submit_exact("g3d-inline-emission", client, addr, source)
                    campaign.record("matches", result)
                    print("match", addr, result.get("submission"), flush=True)
            except (match.CompileError, ValueError, RuntimeError, OSError) as error:
                row["error"] = str(error)
            campaign.record("compile", row)
            print(name, flags, row.get("emitted_functions"), len(row.get("hits", {})), row.get("error", "")[:160], flush=True)
    wins = sorted({r["addr"] for r in campaign.previous("matches")
                   if r.get("submission", {}).get("verified") and r["submission"].get("improved")})
    (campaign.root / "summary.json").write_text(json.dumps({"client": client, "verified_gains": wins}, indent=2))
    print("FINAL", len(wins), wins, flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--all", action="store_true", help="Expand fast-x87 emission across concrete G3D/GLG3D classes")
    run(parser.parse_args().all)
