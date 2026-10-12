"""Proven function extents from already-verified library sources.

A whole compiled function whose bytes (relocations masked) occur in the exe proves
where that function starts and ends. Recompile each distinct library source that
already produced a server-verified exact (so its build configuration is right),
locate every function it emits, and keep the extents that disagree with the
analyzer over still-unmatched code. `--apply` merges them into
work/<client>/bounds.json (read by roc/analyze.py); re-run `roc analyze <client>`
and restart servers afterwards.
"""
import argparse
import json
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import pefile

from roc import analyze, clients, match, worker

ROOT = Path(__file__).resolve().parent.parent


def locate(text, text_va, code, relocs):
    """Every address in .text where code occurs, relocation bytes masked."""
    if len(code) < 16:
        return []
    mask = {i for r in relocs for i in range(r, r + 4)}
    best, cur = (0, 0), 0
    for i in range(len(code) + 1):  # longest unmasked run anchors the search
        if i == len(code) or i in mask:
            if i - cur > best[1] - best[0]:
                best = (cur, i)
            cur = i + 1
    a, b = best
    if b - a < 8:
        return []
    hits, pos = [], text.find(code[a:b])
    while pos >= 0:
        s = pos - a
        if s >= 0 and all(text[s + i] == code[i] for i in range(len(code)) if i not in mask):
            hits.append(text_va + s)
        pos = text.find(code[a:b], pos + 1)
    return hits


def scan(client, server, jobs):
    rows = worker.Api(server, None).call("/v1/sources?client=" + client, timeout=300)
    scores = {r["addr"]: r["score"] for r in rows}
    # One compile per library file + settings; stored sources differ only in comments.
    keys = {tuple(sorted(match.directives(r["source"]).items())) for r in rows
            if r["score"] == 100 and "lib" in match.directives(r.get("source", ""))}
    sources = sorted("".join("// roc-%s: %s\n" % kv for kv in key) for key in keys)
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    sec = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    text_va = pe.OPTIONAL_HEADER.ImageBase + sec.VirtualAddress
    text = sec.get_data()[:sec.Misc_VirtualSize]
    funcs = {int(a, 16): f for a, f in match._functions(client).items()}
    starts = sorted(funcs)
    open_gaps = [(a, f["size"]) for a, f in funcs.items()
                 if f.get("kind") == "code" and scores.get("%08x" % a, 0) < 100]

    def compile_one(source):
        try:
            return source, match.coff_functions(match.compile_text(client, source))
        except BaseException:
            return source, []

    claims = {}
    print(client, "verified library sources", len(sources), flush=True)
    with ThreadPoolExecutor(jobs) as pool:
        for i, (source, compiled) in enumerate(pool.map(compile_one, sources)):
            for name, code, relocs in compiled:
                for hit in locate(text, text_va, code, relocs):
                    if funcs.get(hit, {}).get("size") != len(code):
                        claims[(hit, len(code))] = (name, match.directives(source)["lib"])
            if i % 100 == 0:
                print(" ", i, "compiled,", len(claims), "disagreements", flush=True)
    # Keep claims over unmatched code; drop claims that cross each other.
    useful = sorted(k for k in claims if any(k[0] < g + n and g < k[0] + k[1] for g, n in open_gaps))
    kept = []
    for h, n in useful:
        if any(h < s + m and s < h + n for s, m in kept):
            continue
        kept.append((h, n))
    out = ROOT / "work" / client / "bounds-candidates.json"
    out.write_text(json.dumps([dict(addr="%08x" % h, size=n, symbol=claims[(h, n)][0],
                                    lib=claims[(h, n)][1]) for h, n in kept], indent=1))
    print(client, "claims over unmatched code", len(kept), "->", out, flush=True)
    return kept


def apply(client):
    """Merge candidates into bounds.json after a dry run over the analyzer."""
    folder = ROOT / "work" / client
    bounds = folder / "bounds.json"
    old = [(int(a, 16), n) for a, n in json.loads(bounds.read_text())] if bounds.exists() else []
    new = [(int(c["addr"], 16), c["size"]) for c in json.loads((folder / "bounds-candidates.json").read_text())]
    merged = []
    for h, n in sorted(set(old) | set(new)):
        if not any(h < s + m and s < h + n for s, m in merged):
            merged.append((h, n))
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    base = pe.OPTIONAL_HEADER.ImageBase
    sec = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    text_va, code = base + sec.VirtualAddress, sec.get_data()[:sec.Misc_VirtualSize]
    image, relocs = pe.get_memory_mapped_image(), analyze.reloc_sites(pe)
    in_text = lambda v: text_va <= v < text_va + len(code)
    seeds = {base + pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    seeds.update(v for v in (int.from_bytes(image[s - base:s - base + 4], "little")
                             for s in relocs if not in_text(s)) if in_text(v))
    cur = {int(f["addr"], 16): f["size"] for f in analyze.find_functions(code, text_va, seeds, relocs, old)}
    after = {int(f["addr"], 16): f["size"] for f in analyze.find_functions(code, text_va, seeds, relocs, merged)}
    changed = set(cur) ^ set(after) | {a for a in set(cur) & set(after) if cur[a] != after[a]}
    print(client, "extents", len(merged), "| starts removed", len(set(cur) - set(after)),
          "added", len(set(after) - set(cur)), "resized", len(changed & set(cur) & set(after)), flush=True)
    bounds.write_text(json.dumps([["%08x" % h, n] for h, n in merged]))
    print("wrote", bounds, "- now run: roc analyze", client, flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("client")
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--jobs", type=int, default=3)
    parser.add_argument("--apply", action="store_true", help="merge bounds-candidates.json into bounds.json")
    args = parser.parse_args()
    apply(args.client) if args.apply else scan(args.client, args.server, args.jobs)
