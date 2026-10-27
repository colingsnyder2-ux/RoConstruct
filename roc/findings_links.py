"""Unambiguous native definition links into the actual published source files."""
import re
from pathlib import Path


def native_sources(package, published, names):
    from roc.integration_site import readable
    definitions = {}
    pattern = re.compile(r'^\s*(?:[\w:<>,*&]+\s+)*(\w+)::(~?\w+)\s*\(')
    for relative in sorted(published):
        path = Path(package) / relative
        if not relative.startswith('src/') or path.name.startswith('roc_') or path.suffix not in {'.cpp', '.h', '.hpp', '.inl'}:
            continue
        lines = path.read_text(encoding='utf-8', errors='replace').splitlines()
        for number, line in enumerate(lines):
            match = pattern.match(line)
            if not match:
                continue
            signature = '\n'.join(lines[number:number + 20])
            if '{' not in signature or (';' in signature and signature.index(';') < signature.index('{')):
                continue
            definitions.setdefault(match.groups(), []).append({'path': '2008-06/' + relative, 'line': number + 1})
    sources = {}
    for address, entry in names.items():
        method = readable(entry['symbol']).split('::')
        if len(method) >= 2:
            matches = definitions.get(tuple(method[-2:]), [])
            if len(matches) == 1:
                sources[address] = matches[0]
    return sources
