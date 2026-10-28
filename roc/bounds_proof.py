"""Byte-proven function-extent repairs, so bounds fixes stop being hand audits.

Three proofs, each from bytes or compiler tables, never from a guess:

- owned_catch_merges: a catch funclet named by an MSVC FuncInfo try map belongs to the
  function whose prologue pushes that __ehhandler$ (`push -1; push HANDLER`). analyze
  folds it into its owner even when bounds.json pinned the owner short.
- tail_proof: a compiled candidate whose first N bytes equal the target and whose extra
  bytes equal the exe bytes right after the target's end proves the real extent. Every
  check runs it, so mining itself collects bounds suggestions.
- carry: an exact function in one client proves the extent of the byte-identical
  function in another client.

Suggestions land in work/<client>/bounds-suggestions.jsonl; `roc extents NAME --apply`
writes the clean ones into bounds.json. A suggestion never absorbs an exact function.
"""
import json
import struct
import threading
from bisect import bisect_left
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
_LOCK = threading.Lock()


def pushed_handler(code):
    """__ehhandler$ address an MSVC EH prologue pushes (`6a ff 68 imm32`), or None."""
    i = code[:24].find(b"\x6a\xff\x68")
    return struct.unpack_from("<I", code, i + 3)[0] if 0 <= i <= len(code) - 7 else None


def owned_catch_merges(funcs, handlers, read, locked=()):
    """Fold catch funclets (plus their continuation rows) into the owning row, in place.

    `handlers` is analyze.msvc_catch_handlers output: {funclet va: [context]} where
    context["handler"] is the __ehhandler$ stub. A run of eh rows right after a code row
    is absorbed while each row is a catch of that row's handler or a context-free
    continuation following one. Locked (exact) rows are never grown or absorbed.
    Returns [{addr, old, new, absorbs, handler}]."""
    by_start = sorted(funcs, key=lambda f: int(f["addr"], 16))
    locked = set(locked)
    merges, gone = [], set()
    for i, row in enumerate(by_start):
        start = int(row["addr"], 16)
        if row["kind"] != "code" or start in locked or row["addr"] in gone:
            continue
        handler = pushed_handler(read(start, 24))
        if not handler:
            continue
        absorbed, proven, j = [], False, i + 1
        while j < len(by_start) and by_start[j]["kind"] == "eh" and int(by_start[j]["addr"], 16) not in locked:
            ctx = handlers.get(int(by_start[j]["addr"], 16))
            if ctx and all(c["handler"] == handler for c in ctx):
                proven = True
            elif ctx or not proven:
                break
            absorbed.append(by_start[j])
            j += 1
        if not absorbed:
            continue
        last = absorbed[-1]
        new = int(last["addr"], 16) + last["size"] - start
        relocs = list(row["relocs"])
        for part in absorbed:
            shift = int(part["addr"], 16) - start
            relocs += [r + shift for r in part["relocs"]]
        merges.append({"addr": row["addr"], "old": row["size"], "new": new,
                       "absorbs": [p["addr"] for p in absorbed], "handler": "%08x" % handler})
        row.update(size=new, relocs=sorted(relocs), calls=row["calls"] + sum(p["calls"] for p in absorbed),
                   catch_merge=merges[-1]["absorbs"])
        gone.update(p["addr"] for p in absorbed)
    funcs[:] = [f for f in funcs if f["addr"] not in gone]
    return merges


def _rows(client):
    from roc import match
    rows = match._functions(client)
    order = sorted(int(a, 16) for a in rows)
    return rows, order


def _exact(client):
    path = ROOT / "work" / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    exact = {a for a, s in scores.items() if s == 100}
    db = ROOT / "work" / "server.db"
    if db.exists():  # the host's server knows every contributor's exacts
        import sqlite3
        try:
            conn = sqlite3.connect("file:%s?mode=ro" % db.as_posix(), uri=True, timeout=30)
            try:
                exact |= {a for (a,) in conn.execute("SELECT addr FROM funcs WHERE client = ? AND score = 100",
                                                     (client,))}
            finally:
                conn.close()
        except sqlite3.Error:
            return None  # unknown exacts: callers must not propose extents blind
    return exact


def _extent(client, start, size, rows, order, exact):
    """Exe bytes + known relocs for [start, start+size), and the rows that range absorbs.
    None when it would swallow an exact or data row, or end mid-row."""
    from roc import match
    base, image = match._image(client)
    end = row_end = start + size
    absorbs, relocs = [], []
    for va in order[bisect_left(order, start):]:
        if va >= end:
            break
        row = rows["%08x" % va]
        if va > start:
            # A reviewed data span (e.g. a switch's jump table) may be absorbed: MSVC emits the
            # table inside its function, and the byte comparison covers it like code.
            if row["addr"] in exact:
                return None
            absorbs.append(row["addr"])
        relocs += [va - start + r for r in row["relocs"] if va - start + r + 4 <= size]
        row_end = va + row["size"]
    # Clean only when the new end is a row end (int3 padding after it is fine).
    clean = row_end == end or (row_end > end and not bytes(image[end - base:row_end - base]).strip(b"\xcc"))
    return bytes(image[start - base:end - base]), relocs, absorbs, clean


def tail_proof(client, addr, candidates):
    """First candidate (name, bytes, relocs) proving a longer extent for addr, as a
    suggestion dict, or None. The candidate must equal the target over the current extent
    and the exe bytes over the extra tail, relocations masked."""
    from roc import match
    try:
        rows, order = _rows(client)
    except FileNotFoundError:
        return None
    row = rows.get(addr)
    if not row or row.get("kind") != "code":
        return None
    start, size = int(addr, 16), row["size"]
    exact = _exact(client)
    if exact is None:
        return None
    for name, code, relocs in candidates:
        if len(code) <= size or any(r < size < r + 4 for r in relocs):
            continue
        target, target_relocs, _ = match.target(client, addr)
        if not match.exact_match(target, target_relocs, code[:size], [r for r in relocs if r + 4 <= size]):
            continue
        found = _extent(client, start, len(code), rows, order, exact)
        if not found:
            continue
        ext, ext_relocs, absorbs, clean = found
        if match.exact_match(ext, ext_relocs, code, relocs):
            return {"client": client, "addr": addr, "old": size, "new": len(code), "absorbs": absorbs,
                    "clean": clean, "proof": "tail", "symbol": name}
    return None


def carry(src, dst, log=print):
    """Extents in dst proven by exact functions in src: same masked bytes, other size."""
    from roc import match
    src_rows, _ = _rows(src)
    dst_rows, dst_order = _rows(dst)
    src_exact, dst_exact = _exact(src), _exact(dst)
    if src_exact is None or dst_exact is None:
        raise SystemExit("work/server.db is busy; retry")
    key = lambda code, relocs: match.masked(code[:24], [r for r in relocs if r < 24])
    index = {}
    for a in src_exact:
        row = src_rows.get(a)
        if row and row.get("kind") == "code" and row["size"] >= 24:
            code, relocs, _ = match.target(src, a)
            index.setdefault(key(code, relocs), []).append((a, code, relocs))
    out = []
    for a, row in dst_rows.items():
        if row.get("kind") != "code" or a in dst_exact or row["size"] < 24:
            continue
        code, relocs, _ = match.target(dst, a)
        for src_addr, src_code, src_relocs in index.get(key(code, relocs), ()):
            if len(src_code) == row["size"]:
                continue
            found = _extent(dst, int(a, 16), len(src_code), dst_rows, dst_order, dst_exact)
            if found and match.exact_match(found[0], found[1], src_code, src_relocs):
                # A shorter exact twin is a whole function: its relative branches stay inside it, so
                # the rest of this row is unreachable from it and starts a separate one (a split).
                out.append({"client": dst, "addr": a, "old": row["size"], "new": len(src_code),
                            "absorbs": found[2], "clean": found[3] or len(src_code) < row["size"],
                            "proof": "carry %s %s" % (src, src_addr)})
                break
    log("%s -> %s: %d carried extents" % (src, dst, len(out)))
    return out


def record(suggestion):
    """Append one suggestion (deduplicated by addr/new size) to the client's ledger."""
    path = ROOT / "work" / suggestion["client"] / "bounds-suggestions.jsonl"
    with _LOCK:
        seen = {(s["addr"], s["new"]) for s in load(suggestion["client"])}
        if (suggestion["addr"], suggestion["new"]) in seen:
            return False
        with path.open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(suggestion, sort_keys=True) + "\n")
    return True


def load(client):
    path = ROOT / "work" / client / "bounds-suggestions.jsonl"
    return [json.loads(l) for l in path.read_text().splitlines() if l.strip()] if path.exists() else []


def apply(client, log=print):
    """Write clean, still-valid suggestions into bounds.json. Returns the applied list.
    Re-run `roc analyze` afterwards (it hot-reseeds a running local server)."""
    try:
        rows, order = _rows(client)
    except FileNotFoundError:
        return []
    exact = _exact(client)
    if exact is None:
        raise SystemExit("work/server.db is busy; retry")
    path = ROOT / "work" / client / "bounds.json"
    bounds = dict(json.loads(path.read_text())) if path.exists() else {}
    applied = []
    for s in load(client):
        row = rows.get(s["addr"])
        if not s.get("clean") or not row or row["size"] != s["old"] or s["addr"] in exact:
            continue  # stale (already applied / re-analyzed) or not a whole-row merge
        if not _extent(client, int(s["addr"], 16), s["new"], rows, order, exact):
            continue
        bounds[s["addr"]] = s["new"]
        for absorbed in s["absorbs"]:
            bounds.pop(absorbed, None)  # a pinned start inside the new extent would split it again
        applied.append(s)
        log("%s %s: %d -> %d (%s; absorbs %s)" % (client, s["addr"], s["old"], s["new"], s["proof"],
                                                 ", ".join(s["absorbs"]) or "nothing"))
    if applied:
        path.write_text(json.dumps(sorted([a, n] for a, n in bounds.items())))
        # Reviewed data spans the proof absorbed would otherwise be carved out again by analyze.
        data_path = ROOT / "research" / "function-data.json"
        absorbed = {a for s in applied for a in s["absorbs"]}
        reviewed = json.loads(data_path.read_text()) if data_path.exists() else {}
        before = reviewed.get(client, [])
        kept = [row for row in before if row["addr"] not in absorbed]
        if len(kept) != len(before):
            reviewed[client] = kept
            data_path.write_text(json.dumps(reviewed, indent=2) + "\n")
            log("%s: dropped %d absorbed reviewed data spans from %s" % (client, len(before) - len(kept), data_path.name))
    return applied


if __name__ == "__main__":  # self-check on a synthetic owner + catch funclet + continuation
    owner = b"\x55\x8b\xec\x6a\xff\x68\x00\x74\x7d\x00" + b"\x90" * 6
    funcs = [{"addr": "00001000", "size": 16, "relocs": [6], "calls": 0, "kind": "code"},
             {"addr": "00001010", "size": 10, "relocs": [1], "calls": 1, "kind": "eh"},
             {"addr": "0000101a", "size": 6, "relocs": [1], "calls": 0, "kind": "eh"},
             {"addr": "00001020", "size": 8, "relocs": [], "calls": 0, "kind": "code"}]
    read = lambda va, n: owner[va - 0x1000:va - 0x1000 + n]
    merged = owned_catch_merges(funcs, {0x1010: [{"handler": 0x7d7400}]}, read)
    assert merged == [{"addr": "00001000", "old": 16, "new": 32, "absorbs": ["00001010", "0000101a"],
                       "handler": "007d7400"}], merged
    assert [f["addr"] for f in funcs] == ["00001000", "00001020"] and funcs[0]["relocs"] == [6, 17, 27]
    assert owned_catch_merges(funcs, {}, read) == []
    print("bounds_proof self-check ok")
