"""Repair observed G3D header assertion lines without changing executable bytes or matching rules."""
import json
import re
from collections import defaultdict
from pathlib import Path

from benchmarks.library_fill import assert_lines
from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match


def assertion_spans(lines):
    """Source lines inside assertion calls, ignoring parentheses in literals/comments."""
    text = "\n".join(lines)
    found = []
    tokens = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*.*?\*/|[()]', re.S)
    for call in re.finditer(r'\b(?:alwaysAssertM?|debugAssertM?|ASSERT|VERIFY)\s*\(', text):
        depth = 0
        for token in tokens.finditer(text, call.end() - 1):
            if token[0] == "(":
                depth += 1
            elif token[0] == ")":
                depth -= 1
                if depth == 0:
                    found.append((text.count("\n", 0, call.start()) + 1,
                                  text.count("\n", 0, token.end()) + 1))
                    break
    return found


def assertion_lines(lines):
    return {number for start, end in assertion_spans(lines) for number in range(start, end + 1)}


def run():
    campaign = Campaign("work/g3d-header-2008", "http://127.0.0.1:8765")
    client = "2008-06"
    rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
    scores = {r["addr"]: r["score"] for r in rows}
    target = fingerprint.Target(client)
    target.index = defaultdict(list)
    for addr, function in match._functions(client).items():
        if function.get("kind") == "code" and scores.get(addr, 0) < 100:
            target.index[function["size"]].append(addr)
    done = {(r["addr"], r["source_sha256"]) for r in campaign.previous("diagnostics")
            if r.get("comparison") == "span-line-header-and-main"}
    for row in rows:
        source = row.get("source", "")
        directive = match.directives(source)
        recipe, _, relative = directive.get("lib", "").partition(" ")
        if recipe not in ("g3d-6.09", "rbxgs-g3d") or not 95 <= row["score"] < 100:
            continue
        addr = row["addr"]
        if (addr, digest(source)) in done:
            continue
        result = {"addr": addr, "source_sha256": digest(source), "repairs": [], "comparison": "span-line-header-and-main"}
        try:
            folder = libs.fetch(recipe)
            code, relocs, _ = match.target(client, addr)
            obj = match.compile_text(client, source)
            eligible = [f for f in match.coff_functions(obj) if len(f[1]) == len(code)]
            function = max(eligible, key=lambda f: match.rank_candidate(code, relocs, f[1], f[2])) if eligible else None
            if function:
                base, image = match._image(client)
                headers = {}
                for offset, data, inner in match.coff_data_refs(obj, function[0]):
                    if inner or not 0 <= offset <= len(code) - 4 or not data.endswith((b".h\0", b".cpp\0")):
                        continue
                    va = int.from_bytes(code[offset:offset+4], "little") - base
                    if not 0 <= va < len(image):
                        continue
                    filename = bytes(image[va:va+2048]).split(b"\0", 1)[0].decode("ascii")
                    if not filename.endswith((".h", ".cpp")):
                        continue
                    original = data[:-1].decode("ascii").replace("\\", "/")
                    if original.endswith(".cpp") and original.split("/")[-1] == Path(relative).name:
                        headers[folder / relative] = filename
                        continue
                    for header in folder.rglob(original.split("/")[-1]):
                        if header.as_posix().lower() == original.lower():
                            headers[header] = filename
                for header, filename in headers.items():
                    lines = header.read_text(errors="replace").splitlines()
                    assertions = assertion_lines(lines)
                    marked = [line + " // assertion" if number in assertions else line
                              for number, line in enumerate(lines, 1)]
                    corrections = assert_lines(code, relocs, function[1], function[2], marked)
                    if not corrections:
                        continue
                    starts, ends = {}, set()
                    for before, after in corrections.items():
                        start, end = next((span for span in assertion_spans(lines) if span[0] <= before <= span[1]),
                                          (before, before))
                        adjusted = after - (before - start)
                        if start in starts and starts[start] != adjusted:
                            raise ValueError("Conflicting line evidence within one assertion")
                        starts[start] = adjusted
                        ends.add(end)
                    text = "#line 1 " + json.dumps(filename) + "\n"
                    for number, line in enumerate(lines, 1):
                        if number in starts:
                            text += "#line %d\n" % starts[number]
                        text += line + "\n"
                        if number in ends:
                            text += "#line %d\n" % (number + 1)
                    copy = header.with_name("roc_header_" + digest(text)[:16] + header.suffix)
                    copy.write_text(text)
                    original = folder / relative
                    if header.suffix == ".cpp":
                        wrapper = copy
                    else:
                        wrapper_text = '#include "%s"\n#include "%s"\n' % (copy.as_posix(), original.as_posix())
                        wrapper = original.with_name("roc_header_" + digest(wrapper_text)[:16] + ".cpp")
                        wrapper.write_text(wrapper_text)
                    candidate = libs.source_for(recipe, wrapper.relative_to(folder).as_posix(),
                                                "cpp", int(directive["cl"]), directive["flags"])
                    compiled = match.compile_text(client, candidate)
                    hits = target.match_obj(compiled, candidate)
                    result["repairs"].append({"header": str(header), "filename": filename,
                        "corrections": corrections, "wrapper": str(wrapper), "hits": list(hits)})
                    for hit in hits:
                        response = campaign.submit_exact("g3d-header-lines", client, hit, candidate)
                        campaign.record("matches", response)
                        print("match", hit, response.get("submission"), flush=True)
        except (match.CompileError, ValueError, RuntimeError, OSError, UnicodeError) as error:
            result["error"] = str(error)
        campaign.record("diagnostics", result)
        print("header", addr, result["repairs"], result.get("error", "")[:180], flush=True)
    wins = sorted({r["addr"] for r in campaign.previous("matches")
                   if r.get("submission", {}).get("verified") and r["submission"].get("improved")})
    (campaign.root / "summary.json").write_text(json.dumps({"client": client, "verified_gains": wins}, indent=2))
    print("FINAL", len(wins), wins, flush=True)


if __name__ == "__main__":
    run()
