"""Find real code-exact/data-wrong plateaus and repair literal strings conservatively."""
import argparse
import ast
import json
import random
import re

from benchmarks.match_campaign import Campaign, digest
from roc import match


def string_candidate(source, before, after):
    before, after = before.rstrip(b"\0"), after.rstrip(b"\0")
    if not before or before == after or any(b < 32 or b > 126 for b in before + after):
        return None
    for literal in re.finditer(r'(?<![\w])"(?:[^"\\]|\\.)*"', source):
        try:
            if ast.literal_eval(literal[0]).encode("ascii") == before:
                return source[:literal.start()] + json.dumps(after.decode("ascii")) + source[literal.end():]
        except (SyntaxError, ValueError, UnicodeError):
            pass
    return None


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    manifest = campaign.root / "data-recovery-manifest.json"
    if not manifest.exists():
        rows = [dict(client=client, **row) for client, sources in campaign.snapshot().items()
                for row in sources.values() if row.get("score") == 99 and row.get("source")]
        random.Random(20261010).shuffle(rows)
        manifest.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    done = {(r["client"], r["addr"]) for r in campaign.previous("data-recovery")}
    for row in json.loads(manifest.read_text(encoding="utf-8"))[:limit]:
        client, addr, source = row["client"], row["addr"], row["source"]
        if client not in campaign.info["clients"] or (client, addr) in done:
            continue
        result = dict(client=client, addr=addr, source_sha256=digest(source), qualified=False)
        try:
            code, relocs, _ = match.target(client, addr)
            obj = match.compile_text(client, source)
            exacts = [f for f in match.coff_functions(obj) if match.exact_match(code, relocs, f[1], f[2])]
            if exacts:
                selected, _, bad = match.select_exact_data(client, addr, code, obj, exacts)
                result.update(qualified=bool(bad), data_errors=bad, symbol=selected[0])
                if bad:
                    base, image = match._image(client)
                    candidate = source
                    for off, data, inner in match.coff_data_refs(obj, selected[0]):
                        if inner or off < 0 or off + 4 > len(code):
                            continue
                        va = int.from_bytes(code[off:off + 4], "little")
                        if not 0 <= va - base < len(image):
                            continue
                        expected = bytes(image[va - base:va - base + len(data)])
                        candidate = string_candidate(candidate, data, expected) or candidate
                    if candidate != source:
                        result["trial"] = campaign.submit_exact("data-recovery", client, addr, candidate)
            else:
                result["code_exact"] = False
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            result["error"] = str(error)[-500:]
        campaign.record("data-recovery", result)
        print("data", client, addr, result["qualified"], flush=True)


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=200)
    run(ap.parse_args().limit)
