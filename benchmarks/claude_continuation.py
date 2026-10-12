"""Resume the interrupted 2008-06 library work, preserving every experiment.

No model calls, boundary changes, or other-client mining. Generated translation
units use only binary-observed types backed by the installed vendor headers.
"""
import argparse
import ctypes
import json
import re
import shutil
from collections import defaultdict
from itertools import islice
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match

CLIENT = "2008-06"
ROOT = Path("work/claude-continuation-20261011")


def observed_templates():
    buffer = ctypes.create_string_buffer(16384)
    decode = ctypes.windll.dbghelp.UnDecorateSymbolName
    _, image = match._image(CLIENT)
    seen = set()
    for hit in re.finditer(rb"\.\?A[VU][^\x00]{3,4000}\x00", bytes(image)):
        decorated = hit.group()[:-1]
        if not decode(decorated[1:], buffer, len(buffer), 0x2000):
            continue
        name = re.sub(r"\b(class|struct|__cdecl)\s*", "", buffer.value.decode("ascii"))
        if not name.startswith(("boost::any::holder<", "boost::iostreams::", "Ogre::SharedPtr<")):
            continue
        if "<" not in name or name in seen:
            continue
        # No fabricated app classes, sizes, device implementations or ABI stubs.
        identifiers = re.findall(r"[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*", name)
        if any(not token.startswith(("std::", "boost::", "Ogre::")) and token not in
               {"void", "bool", "char", "int", "float", "double", "const", "unsigned", "long"}
               for token in identifiers):
            continue
        if "Ogre::Rbx" in name:
            continue
        seen.add(name)
        yield {"type": name, "rtti": decorated.decode("ascii"), "image_offset": hit.start()}


def target_for(scores):
    target = fingerprint.Target(CLIENT)
    target.index = defaultdict(list)
    for addr, function in match._functions(CLIENT).items():
        if function.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    return target


def run_sources(campaign, stage, sources, jobs=1):
    scores = {r["addr"]: r["score"] for r in campaign.api.call(
        "/v1/sources?client=" + CLIENT, timeout=300)}
    target = target_for(scores)
    done = {r["key"] for r in campaign.previous(stage) if "error" not in r}
    def pending():
        for source, evidence in sources:
            if digest(source) not in done:
                yield source, evidence

    # Bound compiled-object memory; matching and journal writes retain one owner.
    def compiled():
        iterator = iter(pending())
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            queue = []
            for item in islice(iterator, jobs):
                queue.append((item, pool.submit(match.compile_text, CLIENT, item[0])))
            while queue:
                item, future = queue.pop(0)
                try:
                    obj, error = future.result(), None
                except (RuntimeError, ValueError, OSError, SystemExit) as failure:
                    obj, error = None, failure
                next_item = next(iterator, None)
                if next_item:
                    queue.append((next_item, pool.submit(match.compile_text, CLIENT, next_item[0])))
                yield *item, obj, error

    for source, evidence, obj, failure in compiled():
        key = digest(source)
        if key in done:
            continue
        row = {"key": key, "source": source, "evidence": evidence, "winners": []}
        try:
            if failure:
                raise failure
            hits = target.match_obj(obj, source)
            row["local_exact_hits"] = len(hits)
            row["reason"] = "body and referenced data exact" if hits else "no unresolved exact body/data match"
            for addr, (_, symbol, *_) in sorted(hits.items()):
                result = campaign.submit_exact(stage, CLIENT, addr, source)
                result["symbol"] = symbol
                row["winners"].append(result)
                campaign.record(stage + "-results", result)
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            row["error"] = str(error)[-2000:]
        campaign.record(stage, row)
        wins = sum(bool(w.get("submission", {}).get("improved")) for w in row["winners"])
        print(stage, evidence, "local exact", len(row["winners"]), "new verified", wins,
              row.get("error", "")[-180:], flush=True)


def ogre_sources():
    # Replay Claude's exact-producing settings, then the same settings on siblings.
    flags = "/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD"
    for file in ("OgreSceneManager.cpp", "OgreSceneNode.cpp", "OgreEntity.cpp", "OgreSubEntity.cpp"):
        yield libs.source_for("ogre-1.4.5-dll", file, "cpp", 21022, flags), file


def template_sources(campaign):
    boost_headers = """#include <string>
#include <vector>
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/stream_buffer.hpp>
"""
    for evidence in observed_templates():
        name = evidence["type"]
        recipe = "ogre-1.4.5-dll" if name.startswith("Ogre::") else "templates-2008-06-dll"
        headers = "#include <Ogre.h>\n" if name.startswith("Ogre::") else boost_headers
        if "chain" in name or "filtering_stream" in name:
            headers += "#include <boost/iostreams/filtering_stream.hpp>\n"
        text = headers + "template class " + name + ";\n"
        file = "roc_rtti_" + digest(text)[:16] + ".cpp"
        if recipe == "templates-2008-06-dll":
            (libs.LIBS / libs.RECIPES[recipe]["src"]).mkdir(parents=True, exist_ok=True)
        path = libs.fetch(recipe) / file
        if path.exists() and path.read_text() != text:
            raise ValueError("Generated file conflict: " + str(path))
        path.write_text(text)
        campaign.record("generated", dict(evidence, recipe=recipe, path=str(path), source=text))
        for flags in ("/O2 /GS- /EHsc /MD", "/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD",
                      "/O2 /Ob1 /GS /EHsc /MD"):
            yield libs.source_for(recipe, file, "cpp", 21022, flags), evidence


def rtm_sources(campaign, pilot=False, area=None):
    # Claude already exhausted ATL and the small Scintilla RTM pilot (zero wins).
    pending = defaultdict(int)
    for row in campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300):
        directive = match.directives(row.get("source") or "").get("lib", "").split(" ", 1)
        if row["score"] < 100 and len(directive) == 2:
            pending[directive[1].replace("\\", "/")] += 1
    for recipe in ("mfc-9.0-shared-rtm", "xtp-11.2.2-lib-strlen-rtm"):
        spec = libs.RECIPES[recipe]
        files = sorted(libs.files_of(spec, libs.fetch(recipe)),
                       key=lambda file: -pending[file.replace("\\", "/")])
        if area:
            files = [file for file in files if area.lower() in file.lower()]
        if pilot:
            files = files[:10]
        for file in files:
            flags = "/O2 /MD /GS /EHsc /Ob1" if recipe.startswith("xtp") else spec.get("grid", libs.GRID)[0]
            # A dependency repair must not reuse failures cached by tiny directive text.
            manifest = ROOT / "rtm-desktop-repair/manifest.json"
            stamp = "// RTM desktop manifest: " + digest(manifest.read_text()) + "\n"
            yield stamp + libs.source_for(recipe, file, "cpp", 21022, flags), {"recipe": recipe, "file": file}


def cleanup(campaign):
    starts = set(match._functions(CLIENT))
    for path in (libs.ROOT / "src" / CLIENT).glob("*.cpp"):
        if path.stem in starts:
            continue
        source = path.read_text()
        if not source.startswith("// from server:"):
            campaign.record("cleanup", {"path": str(path), "reason": "retired address; hand edit retained"})
            continue
        destination = ROOT / "retired-src" / path.name
        assert path.resolve().is_relative_to(libs.ROOT / "src" / CLIENT)
        assert destination.resolve().is_relative_to(ROOT.resolve())
        if destination.exists():
            raise ValueError("Archive already exists: " + str(destination))
        destination.parent.mkdir(parents=True, exist_ok=True)
        row = {"path": str(path), "archive": str(destination), "source_sha256": digest(source),
               "source": source, "reason": "address retired by Claude's verified boundary update"}
        campaign.record("cleanup", row)
        shutil.move(str(path), str(destination))
    print("retired server downloads archived; hand edits retained", flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("stage", choices=("ogre", "templates", "rtm", "cleanup"))
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--limit", type=int, help="maximum source configurations in this pilot")
    parser.add_argument("--area", help="restrict RTM expansion to source paths containing this text")
    parser.add_argument("--jobs", type=int, choices=range(1, 5), default=1, help="bounded compile prefetch")
    args = parser.parse_args()
    campaign = Campaign(ROOT, args.server)
    try:
        if args.stage == "cleanup":
            cleanup(campaign)
            raise SystemExit(0)
        sources = {"ogre": ogre_sources, "templates": lambda: template_sources(campaign),
                   "rtm": lambda: rtm_sources(campaign, args.limit is not None, args.area)}[args.stage]()
        if args.limit is not None:
            sources = islice(sources, args.limit)
        run_sources(campaign, args.stage, sources, args.jobs)
    finally:
        campaign.api.close()
