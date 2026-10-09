"""Small caller/callee ABI evidence graph for compiler-guided repair."""
import re
from urllib.parse import quote


_SIG = re.compile(
    r'(?m)^\s*(?:extern\s+"C"\s+)?(?P<ret>[A-Za-z_][\w:<>*& ]*?)\s+'
    r"(?P<cc>__(?:cdecl|stdcall|thiscall|fastcall)\s+)?"
    r"(?P<name>[A-Za-z_]\w*(?:::\w+)?)\s*\((?P<args>[^;{}]*)\)"
)


def source_signature(source):
    """Extract conservative return/ABI/arity facts; unknown stays unknown."""
    match = _SIG.search(source or "")
    if not match:
        return {}
    args = match.group("args").strip()
    return {
        "return_type": " ".join(match.group("ret").split()),
        "calling_convention": (match.group("cc") or "").strip() or "default",
        "arity": 0 if not args or args == "void" else args.count(",") + 1,
        "name": match.group("name"),
    }


def target_evidence(api, client, row, limit=6):
    """Build bounded exact-callee evidence for one target."""
    edges = []
    for target in (row.get("call_targets") or [])[:limit]:
        target = str(target).lower()
        if not re.fullmatch(r"[0-9a-f]{8}", target):
            continue
        try:
            item = api.call("/v1/source?client=%s&addr=%s" % (quote(client), target))
        except Exception:
            continue
        if int((item or {}).get("score", 0) or 0) != 100:
            continue
        signature = source_signature((item or {}).get("source"))
        if signature:
            edges.append({"addr": target, **signature})
    return {
        "caller_count": len(row.get("callers") or []),
        "callee_count": len(row.get("call_targets") or []),
        "exact_callees": edges,
    }
