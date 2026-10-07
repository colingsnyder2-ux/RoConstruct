"""Copy a match from one client to every other client that contains the same function.

The clients are not independent: Roblox shipped the same code in several of them, so a
function that is byte-identical in two exes is very likely the same function. Once one
copy is matched, that source can be tried against the others nearly free - it only has
to be compiled, and a wrong guess costs nothing because only byte-identical results
count. It multiplies every future match, which is why it is worth doing before the
library work.

A copy can only succeed when the compiler can reproduce the same bytes, so candidates
are ordered by compiler group:

    21022   2008-06, 2011-06
    30729   2009-06, 2010-06, 2012-06
    50727   2007-08

Copies across groups still run - simple functions compile identically under either
compiler - but they rarely succeed, so same-group sources are always tried first.

Each source is compiled once per target client, with that client's compiler and flags,
and every function of the resulting object is tried against that client's open
functions. Verification reuses roc/fingerprint.py's Target, so a copy is recorded the
same way a hand-written match is and `roc check` re-verifies it later.
"""
import hashlib
import json
import re
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
CHUNK = 250
TAG = re.compile(r"ROCX([0-9a-f]{6,})")
FUNC = re.compile(r"\bfunc_[0-9a-f]{8}\b")


def _fingerprint():
    """roc/fingerprint.py holds the shared mass-matching helpers. Imported lazily so
    this module still loads (and is testable) when that file is absent."""
    from roc import fingerprint
    return fingerprint


def matched_sources(log=print):
    """[(body, [(origin client, addr), ...])] for every stored match, deduped by body text.

    The template header (disassembly comments) is dropped: it names the origin client
    and address and would be wrong in the copy. Deduplication matters because the same
    trivial function is often stored under many addresses."""
    groups = {}
    for client in sorted(clients.load()):
        folder = ROOT / "src" / client
        if not folder.is_dir():
            continue
        for path in sorted(folder.glob("*.cpp")):
            text = path.read_text(errors="replace")
            if "\n\n" not in text:
                continue
            body = text.split("\n\n", 1)[1].strip()
            if not body:
                continue
            key = hashlib.sha256(body.encode()).hexdigest()
            if key not in groups:
                groups[key] = (body, [])
            groups[key][1].append((client, path.stem))
    out = [v for v in groups.values()]
    log("%d distinct matched source(s) from %d client(s)" % (len(out), len(clients.load())))
    return out


def _lang(body):
    return match.directives(body).get("lang", "cpp")


def needs_global_scope(body):
    """True if a candidate cannot go inside a namespace.

    System headers must be included at global scope: inside a namespace, the CRT
    headers fail with "fpos_t is not a member of global namespace" because their
    using-declarations land in the wrong namespace. C has no namespaces at all. These
    get one translation unit each instead."""
    return _lang(body) == "c" or "#include" in body


def _build_of(body, origins, reg):
    """Which compiler produced these bytes: the library's own directive if it has one,
    else the client it was matched in. A copy can only reach a client sharing it."""
    declared = match.directives(body).get("cl", "")
    if declared.isdigit():
        return int(declared)
    for client, _addr in origins:
        got = reg.get(client, {}).get("compiler_build")
        if got:
            return got
    return None


def _order(sources, target, reg):
    """Own sources first, then same-compiler sources, then the rest.

    Own sources come first on purpose: re-verifying them is what recovers a client
    whose scores.json was lost, and it is also the cheapest way to be sure the pool
    reflects what is actually stored. Same-compiler sources are next because those are
    the only ones that can reproduce identical bytes."""
    build = reg[target].get("compiler_build")
    own, same, other = [], [], []
    for body, origins in sources:
        if all(c == target for c, _ in origins):
            own.append((body, origins))
        elif _build_of(body, origins, reg) == build:
            same.append((body, origins))
        else:
            other.append((body, origins))
    return own + same + other


def _matched_count(client):
    path = ROOT / "work" / client / "scores.json"
    try:
        return sum(1 for v in json.loads(path.read_text()).values() if v == 100)
    except (OSError, ValueError):
        return 0


def _batch_cpp(sources):
    """C++ candidates batched into one .cpp, each in its own namespace.

    Namespacing is needed because matches routinely declare the same type name - two
    zlib sources both defining z_stream_s - which is a hard error in one translation
    unit and would otherwise cost the whole chunk."""
    snippets = []
    for i, (body, _origins) in enumerate(sources):
        tag = "ROCX%06x" % i
        snippets.append((tag, "namespace ns_%s {\n%s\n}\n" % (tag, FUNC.sub("fn_%s" % tag, body))))
    return "\n\n".join(text for _tag, text in snippets), dict(snippets)


def _batch_alone(source):
    """One candidate in its own translation unit: needed for C, and for anything that
    includes a system header."""
    tag = "ROCX000000"
    return FUNC.sub("fn_%s" % tag, source), {tag: source}


def _match_batch(target, obj, sources_by_tag, client):
    """{addr: (source, symbol, data spans)} for every function of obj found in the exe."""
    found = {}
    for name, code, relocs in match.coff_functions(obj):
        tag = TAG.search(name)
        if not tag or tag.group(0) not in sources_by_tag:
            continue
        source = sources_by_tag[tag.group(0)]
        for addr in target.index.get(len(code), []):
            if addr in found:
                continue
            exe = target.same(addr, code, relocs)
            if exe is None:
                continue
            spans, bad = match.data_check(client, addr, exe, match.coff_data_refs(obj, name))
            if not bad:
                found[addr] = (source, name, spans)
    for addr in found:  # matched functions leave the pool
        target.index[len(match.target(client, addr)[0])].remove(addr)
    return found


def compile_batch(target, sources, reg, log):
    """Compile a batch, halving it whenever it fails.

    One bad source poisons a whole translation unit: an unbalanced brace or an
    unterminated #if leaves the parser mid-state, and the next candidate gets a syntax
    error instead of its own diagnostics. Splitting until the culprits are isolated
    keeps every other source usable instead of throwing away 250 of them. Returns
    [(obj, by_tag)] for everything that compiled."""
    out, bad = [], []

    def attempt(chunk):
        if not chunk:
            return
        try:
            if len(chunk) == 1 and needs_global_scope(chunk[0][0]):
                text, by_tag = _batch_alone(chunk[0][0])
            else:
                text, by_tag = _batch_cpp(chunk)
            obj = match.compile_text(target, text, build=reg[target].get("compiler_build"))
        except match.CompileError as error:
            if len(chunk) == 1:
                bad.append((chunk[0][0], str(error).splitlines()[0]))
                return
            half = len(chunk) // 2
            attempt(chunk[:half])
            attempt(chunk[half:])
            return
        out.append((obj, by_tag))

    attempt(sources)
    if bad:
        log("  %d source(s) failed even alone and were skipped" % len(bad))
        for text, why in bad[:4]:
            log("    %-58s %s" % (" ".join(text.split())[:58], why[:100]))
        if len(bad) > 4:
            log("    ... and %d more" % (len(bad) - 4))
    return out


def run(targets=None, log=print, limit=None, dry_run=False):
    """Copy stored matches into the given clients (default: all). Returns {client: new}."""
    reg = clients.load()
    targets = [c for c in (targets or sorted(reg)) if c in reg]
    sources = matched_sources(log=log)
    if not sources:
        log("Nothing stored to copy yet. Run  roc auto <client>  or match some by hand first.")
        return {}

    result = {}
    for target in targets:
        cands = _order(sources, target, reg)
        if limit:
            cands = cands[:limit]
        probe = _fingerprint().Target(target)
        open_before = sum(len(v) for v in probe.index.values())
        if not open_before:
            log("%-8s nothing open to match" % target)
            result[target] = (0, 0)
            continue
        log("%-8s %d candidate source(s) against %d open function(s)" % (target, len(cands), open_before))

        found = {}
        chunks = [cands[i:i + CHUNK] for i in range(0, len(cands), CHUNK)]
        for n, chunk in enumerate(chunks, 1):
            for obj, by_tag in compile_batch(target, chunk, reg, log):
                found.update(_match_batch(probe, obj, by_tag, target))
            log("  chunk %d/%d: %d new so far" % (n, len(chunks), len(found)))

        if not found:
            log("%-8s no new matches" % target)
            result[target] = (0, 0)
            continue
        if dry_run:
            log("%-8s would verify %d function(s)" % (target, len(found)))
            result[target] = (len(found), 0)
            continue
        before = _matched_count(target)
        files = _fingerprint().save(target, found, "copied from an identical function in another client")
        after = _matched_count(target)
        log("%-8s %d verified byte-identical: %d new file(s), matched %d -> %d"
            % (target, len(found), files, before, after))
        result[target] = (files, after - before)
    return result
