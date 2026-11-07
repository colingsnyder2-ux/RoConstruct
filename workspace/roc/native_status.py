#!/usr/bin/env python3
"""native-status banner generator for RoConstruct native classes/headers/world.

Reads:
  docs/native-source-links.json        addr -> {path, line}
  rebuild/2008-06/out/native-names.json addr -> {symbol, score, strings}
  docs/integration.json                inactive[addr]=[name, exact, receipt],
                                       names[addr]=[pretty, mangled, score]
  work/server.db                       funcs (addr,score,user), integration_credit (addr,user,model)

Writes a 4-line marker block to the top of every file under
rebuild/2008-06/{native-classes,native-headers,native-world}.

Banner block (idempotent; same data => identical text => no churn):
    // >>> native-status (generated) -- do not edit >>>
    // <class> | <client> | <state>
    // <n>/<m> mapped addresses reported exact (subset) | <strings> | <freshness> | by <user> (model)
    // <<< native-status | src <hash> | roc native-status --write

Placed after the // native-flags:// roc- prelude (cpp) or #pragma once (header),
otherwise at line 1. CRLF/LF/BOM preserved.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sqlite3
import sys
import time
from collections import Counter, defaultdict
from fnmatch import fnmatchcase
from pathlib import Path
from types import SimpleNamespace

ROOT = Path(__file__).resolve().parents[1]
CLIENT = "2008-06"
NATIVE_DIRS = ["native-classes", "native-headers", "native-world"] + [
    project + "/" + area for project in
    ("App", "Base", "Network", "Rendering", "WindowsClient", "Studio")
    for area in ("src", "include")
]

MARKER_START = "// >>> native-status (generated) -- do not edit >>>"
MARKER_END = "// <<< native-status"


def load_json(path):
    try:
        with open(path, encoding="utf-8") as f:
            return json.load(f)
    except FileNotFoundError:
        return {}


def load_links():
    d = load_json(ROOT / "docs/native-source-links.json")
    sources = d.get("sources", d) if isinstance(d, dict) else {}
    out = {}
    for addr, info in sources.items():
        p = (info.get("path") or "").replace("workspace/", "")
        if "/native-" in p or any("/" + scope + "/" in p for scope in NATIVE_DIRS[3:]):
            out[addr.lower()] = p
    return out


def load_names():
    return load_json(ROOT / "rebuild/2008-06/out/native-names.json")


def load_integration():
    return load_json(ROOT / "docs/integration.json")


def load_db():
    path = ROOT / "work/server.db"
    if not path.is_file():
        raise FileNotFoundError(f"Native status needs the existing server database: {path}")
    con = sqlite3.connect(path.resolve().as_uri() + "?mode=ro", uri=True)
    con.row_factory = sqlite3.Row
    scores = {r["addr"]: r["score"] for r in con.execute(
        "select addr, score from funcs where client=?", (CLIENT,))}
    users = {r["addr"]: r["user"] for r in con.execute(
        "select addr, user from funcs where client=? and user is not null", (CLIENT,))}
    credit = {}
    for r in con.execute("select addr, user, model from integration_credit where client=?", (CLIENT,)):
        credit[r["addr"]] = (r["user"], r["model"])
    attempts = {}
    for r in con.execute("select addr, attempts_by_model from funcs where client=?", (CLIENT,)):
        attempts[r["addr"]] = r["attempts_by_model"]
    con.close()
    return scores, users, credit, attempts


def file_hash(body: str) -> str:
    return hashlib.sha256(body.encode("utf-8")).hexdigest()[:8]


def strip_existing_banner(text: str):
    """Remove an existing native-status block if present; return (text_without, had_block)."""
    lines = text.split("\n")
    start = end = None
    for i, ln in enumerate(lines):
        if ln.strip().startswith(MARKER_START):
            start = i
        if start is not None and ln.strip().startswith(MARKER_END):
            end = i
            break
    if start is None:
        return text, False
    if end is None:
        end = start
    # remove the marker block lines verbatim; preserves original trailing newline
    new_lines = lines[:start] + lines[end + 1:]
    return "\n".join(new_lines), True


def find_insert_point(text: str, is_header: bool):
    """Index where banner should be inserted (after prelude/#pragma once, else 0)."""
    lines = text.split("\n")
    prelude_end = 0
    seen_pragma_once = False
    for i, ln in enumerate(lines):
        s = ln.strip()
        if s.startswith("#pragma once"):
            seen_pragma_once = True
            prelude_end = i + 1
            break
        if s.startswith("// native-flags:") or s.startswith("// roc-"):
            prelude_end = i + 1
            continue
        if s.startswith("//") or s == "":
            prelude_end = i + 1
            continue
        break
    if is_header and seen_pragma_once:
        return prelude_end
    # cpp: after contiguous native-flags/roc prelude; else top
    return prelude_end


def detect_class_name(path: Path) -> str:
    stem = path.stem
    return stem


def count_declared_methods(text: str) -> int:
    """Rough C++ method declaration counter for headers."""
    count = 0
    for ln in text.split("\n"):
        s = ln.strip()
        if not s or s.startswith("//") or s.startswith("#"):
            continue
        # method-like: has parens, not a ctor/dtor-only macro, not a variable
        if "(" in s and ")" in s and ("::" in s or s.endswith(";") or "{" in s or "}" in s):
            if any(k in s for k in ("virtual ", "static ", "explicit ", "inline ")) or "::" in s:
                count += 1
            elif re.search(r"\w+\s+\w+\s*\([^)]*\)\s*(const)?\s*(override|final|;|$)", s):
                count += 1
    return min(count, 200)


def parse_args():
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="write banners to files")
    ap.add_argument("--check", action="store_true", help="exit 1 if any banner missing/stale")
    ap.add_argument("--json", action="store_true", help="print index JSON to stdout")
    ap.add_argument("--path", help="glob relative to rebuild/2008-06 (default all native dirs)")
    ap.add_argument("--staged", action="store_true", help="check only git-staged native files")
    ap.add_argument("--client", default=CLIENT)
    return ap.parse_args()


def _matches(path_glob, key):
    if not path_glob:
        return True
    import fnmatch
    return fnmatch.fnmatch(key.replace("\\", "/"), path_glob)


def build_index(path_glob=None):
    links = load_links()
    names = load_names()
    integ = load_integration()
    inactive = integ.get("inactive", {})
    names_map = integ.get("names", {})
    scores, users, credit, attempts_by_model = load_db()

    file_entries = defaultdict(lambda: {
        "addrs": [], "exact": 0, "named": 0, "partial": 0, "strings": set(),
        "miners": Counter(), "models": Counter(), "receipts": set(), "class": "",
        "is_header": False,
    })

    for addr, fpath in links.items():
        if not fpath.startswith("rebuild/"):
            fpath = "rebuild/" + fpath
        p = ROOT / fpath
        if not p.exists():
            continue
        fe = file_entries[str(p.relative_to(ROOT))]
        fe["class"] = detect_class_name(p)
        fe["is_header"] = p.suffix.lower() in (".h", ".hpp")
        fe["addrs"].append(addr.lower())

        nn = names.get(addr, {})
        is_exact_body = bool(inactive.get(addr.lower(), [None, False])[1])
        is_named = bool(nn.get("symbol")) or bool(names_map.get(addr.lower(), [None])[0])
        if is_exact_body:
            fe["exact"] += 1
            if is_named:
                fe["named"] += 1
        else:
            fe["partial"] += 1
        for s in nn.get("strings", []) or []:
            fe["strings"].add(s)

        # miner = funcs.user ; model = top model from attempts_by_model (or credit model if integrated)
        miner = users.get(addr.lower())
        if miner:
            fe["miners"][miner] += 1
        abm = attempts_by_model.get(addr.lower())
        model = None
        if abm:
            try:
                d = json.loads(abm)
                if isinstance(d, dict) and d:
                    model = max(d.items(), key=lambda x: x[1])[0]
            except Exception:
                pass
        cr = credit.get(addr.lower())
        if cr:
            if cr[1]:
                model = cr[1]
        if model:
            fe["models"][model] += 1
        r = inactive.get(addr.lower(), [None, None, None])[2]
        if r:
            fe["receipts"].add(r)

    # include native files with no address links (unmapped)
    for dname in NATIVE_DIRS:
        base = ROOT / "rebuild" / CLIENT / dname
        if not base.exists():
            continue
        for p in base.rglob("*"):
            if p.is_file() and p.suffix.lower() in (".cpp", ".c", ".h", ".hpp"):
                key = str(p.relative_to(ROOT))
                if path_glob and not _matches(path_glob, key):
                    continue
                if key not in file_entries:
                    file_entries[key] = {
                        "addrs": [], "exact": 0, "named": 0, "partial": 0, "strings": set(),
                        "miners": Counter(), "models": Counter(), "receipts": set(),
                        "class": detect_class_name(p), "is_header": p.suffix.lower() in (".h", ".hpp"),
                    }

    # filter mapped entries too
    if path_glob:
        for k in [k for k in file_entries if not _matches(path_glob, k)]:
            del file_entries[k]

    return file_entries


_INTEG_CACHE = None
def _integ():
    global _INTEG_CACHE
    if _INTEG_CACHE is None:
        _INTEG_CACHE = load_integration()
    return _INTEG_CACHE


def banner_for(key, fe, text_body):
    integ = _integ()
    total = len(fe["addrs"])
    exact = fe["exact"]
    named = fe["named"]
    cls = fe["class"]
    state = "selection unverified"

    # freshness: verified if all receipts present; else historical if any; else unmapped
    if total == 0:
        fresh = "unmapped (no binary link)"
        date = ""
    elif fe["receipts"]:
        fresh = "receipt-listed (not revalidated)"
        date = integ.get("updated", "")[:10]
    else:
        fresh = "historical"
        date = ""

    # strings
    str_total = len(fe["strings"])
    str_field = f"{str_total} referenced strings (not rechecked)" if str_total else "no mapped strings"

    # contributor / model
    if fe["miners"]:
        top_miner, mc = fe["miners"].most_common(1)[0]
        if len(fe["miners"]) == 1:
            miner_field = f"by {top_miner}"
        else:
            miner_field = f"by {top_miner} (+{len(fe['miners'])-1})"
    else:
        miner_field = "by -"
    if fe["models"]:
        top_model, mc = fe["models"].most_common(1)[0]
        if len(fe["models"]) == 1:
            model_field = f"({top_model})"
        else:
            model_field = f"(mixed {len(fe['models'])})"
    else:
        model_field = ""

    src = file_hash(text_body)
    named_part = f" | named {named}" if named > 0 else ""
    if total == 0:
        metric_line = f"// unmapped (no binary link) | {miner_field} {model_field}".strip()
    else:
        metric_line = f"// {exact}/{total} mapped addresses reported exact (subset)" + named_part + f" | {str_field} | {fresh}" + (f" {date}" if date else "") + f" | {miner_field} {model_field}".strip()
    lines = [
        MARKER_START,
        f"// {cls} | {CLIENT} | {state}",
        metric_line,
        f"// <<< native-status | src {src} | roc native-status --write",
    ]
    return "\n".join(lines)


def apply_banner(text: str, key: str, fe) -> str:
    body, had = strip_existing_banner(text)
    is_header = fe["is_header"]
    body_for_methods = body  # methods counted on body sans banner
    ban = banner_for(key, fe, body_for_methods)
    insert_at = find_insert_point(body, is_header)
    lines = body.split("\n")
    lines.insert(insert_at, ban)
    return "\n".join(lines)


def require_live_leases(paths):
    """Require a live lease owned by the configured user for every changed file."""
    if not paths:
        return float('inf')
    sys.path.insert(0, str(ROOT))
    from roc import leases
    api, user = leases._api(SimpleNamespace(server=None, user=None))
    active = api.call('/v1/leases')['leases']
    now = time.time()
    deadlines = []
    for path in paths:
        path = path.replace('\\', '/')
        covering = [lease for lease in active if lease['expires'] > now + 30
                    and any(fnmatchcase(path, pattern) for pattern in lease['patterns'])]
        if not any(lease['user'] == user for lease in covering) or any(lease['user'] != user for lease in covering):
            raise RuntimeError('A live lease owned by %s is required for %s' % (user, path))
        deadlines.append(max(lease['expires'] for lease in covering if lease['user'] == user))
    return min(deadlines)


def main():
    args = parse_args()
    if args.staged and getattr(args, 'write', False):
        raise ValueError('--staged cannot be combined with --write')
    entries = build_index(args.path)
    staged_prefix = ''
    if args.staged:
        import subprocess
        out = subprocess.check_output(["git", "diff", "--cached", "--relative", "--name-only", "-z"], cwd=ROOT, text=True)
        staged = set(out.split('\0'))
        entries = {k: v for k, v in entries.items() if k.replace("\\", "/") in staged or k in staged}
        if not args.json:
            staged_prefix = subprocess.check_output(['git', 'rev-parse', '--show-prefix'], cwd=ROOT, text=True).strip()
    if entries and not args.path and not args.staged and not any(v.get("addrs") for v in entries.values()):
        print("warning: no native source mappings; banner counts and attribution are unavailable", file=sys.stderr)
    if args.json:
        out = {k: dict(v, miners=dict(v["miners"]), models=dict(v["models"]),
                       strings=sorted(v["strings"]), receipts=sorted(v["receipts"]))
               for k, v in entries.items()}
        print(json.dumps(out, indent=1))
        return 0

    changed = 0
    stale = 0
    pending = []
    for key, fe in entries.items():
        p = ROOT / key
        if args.staged:
            raw = subprocess.check_output(['git', 'show', ':' + staged_prefix + key.replace('\\', '/')], cwd=ROOT)
        else:
            raw = p.read_bytes()
        bom = b'\xef\xbb\xbf' if raw.startswith(b'\xef\xbb\xbf') else b''
        content = raw[len(bom):]
        if b'\r' in content.replace(b'\r\n', b'') or (b'\r\n' in content and b'\n' in content.replace(b'\r\n', b'')):
            raise ValueError('Mixed or unsupported line endings: ' + str(p))
        eol = b'\r\n' if b'\r\n' in content else b'\n'
        text = content.replace(b'\r\n', b'\n').decode('utf-8')
        new = apply_banner(text, key, fe)
        if new != text:
            if args.check:
                stale += 1
                print(f"STALE: {key}")
            elif args.write:
                pending.append((key, p, raw, bom + new.encode('utf-8').replace(b'\n', eol)))
            else:
                stale += 1
                print(f"would-change: {key}")
    if args.write:
        deadline = require_live_leases([key for key, _, _, _ in pending])
        for key, p, original, replacement in pending:
            if time.time() >= deadline:
                raise RuntimeError('Lease expired before writing: ' + str(p))
            if p.read_bytes() != original:
                raise RuntimeError('File changed while preparing banner: ' + str(p))
            p.write_bytes(replacement)
            changed += 1
            print(f"wrote: {key}")
    if args.check:
        if stale:
            print(f"{stale} stale/missing banners")
            return 1
        print("all banners current")
        return 0
    if args.write:
        print(f"{changed} files updated, {len(entries) - changed} unchanged")
    else:
        print(f"dry-run: {stale} would change, {len(entries)} total (pass --write to apply)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
