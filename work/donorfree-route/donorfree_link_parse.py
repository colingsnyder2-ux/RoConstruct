import re


def parse_unresolved(log):
    """Mangled names from LNK2001/LNK2019 lines (demangled form `"..." (?mangled)` or the bare mangled name)."""
    out = set()
    for m in re.finditer(r'LNK2(?:001|019): unresolved external symbol (.*)', log):
        t = m.group(1).strip()
        mm = re.search(r'\((\?[^()\s]*|_[^()\s]*)\)(?: referenced.*)?$', t) if t.startswith('"') else None
        out.add(mm.group(1) if mm else t.split(' ')[0])
    return sorted(out)
