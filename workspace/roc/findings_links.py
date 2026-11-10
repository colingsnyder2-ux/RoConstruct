"""Unambiguous native definition links into the actual published source files."""
import os
import re
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path


def plain_name(name):
    """Remove template arguments, keeping the defining class and method."""
    depth, result = 0, []
    for char in name:
        if char == "<":
            depth += 1
        elif char == ">" and depth:
            depth -= 1
        elif not depth:
            result.append(char)
    return re.sub(r"\s+", "", "".join(result))


def definitions(text):
    """Locate bodies in namespace/class scopes, including inline header methods."""
    mask = re.compile(r"""/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'|^[ \t]*#[^\n]*(?:\\\n[^\n]*)*""", re.S | re.M)
    text = mask.sub(lambda m: re.sub(r"[^\n]", " ", m[0]), text)
    # Template arguments cannot introduce a source scope. Preserve offsets for line links.
    while re.search(r"<[^<>{};]*>", text):
        text = re.sub(r"<[^<>{};]*>", lambda m: re.sub(r"[^\n]", " ", m[0]), text)
    stack, start = [], 0
    for event in re.finditer(r"[{};]", text):
        end, token = event.start(), event[0]
        segment = text[start:end]
        if token == "}":
            if stack:
                stack.pop()
        elif token == "{":
            if any(kind == "function" for kind, _ in stack):
                stack.append(("block", ""))
            else:
                namespace = re.search(r"\bnamespace\s*([\w:]*)\s*$", segment)
                classes = list(re.finditer(r"\b(?:class|struct)\s+(\w+)", segment))
                if namespace:
                    stack.append(("scope", namespace[1] or "<anonymous>"))
                elif classes and "(" not in segment[classes[-1].end():]:
                    stack.append(("scope", classes[-1][1]))
                else:
                    method = re.search(r"((?:\w+\s*::\s*)*(?:~?\w+|operator\s*(?:\(\)|\[\]|[=+*/!&|^-]+)))\s*\(", segment)
                    if method and method[1] not in {"if", "for", "while", "switch", "catch"}:
                        scope = "::".join(name for kind, name in stack if kind == "scope")
                        name = plain_name(method[1])
                        if scope and not name.startswith(scope + "::"):
                            name = scope + "::" + name
                        yield name, text.count("\n", 0, start + method.start(1)) + 1
                        stack.append(("function", ""))
                    else:
                        stack.append(("block", ""))
        start = event.end()


def native_sources(package, published, names):
    from roc.integration_site import readable
    undecorate = None
    if os.name == "nt":
        import ctypes
        from ctypes import wintypes
        undecorate = ctypes.WinDLL("dbghelp").UnDecorateSymbolName
        undecorate.argtypes = [ctypes.c_char_p, ctypes.c_char_p, wintypes.DWORD, wintypes.DWORD]
        undecorate.restype = wintypes.DWORD
    found = {}
    def scan(relative):
        path = Path(package) / relative
        if not relative.startswith('src/') or path.name.startswith('roc_') or path.suffix not in {'.c', '.cpp', '.h', '.hpp', '.inl', '.ipp'}:
            return relative, []
        return relative, list(definitions(path.read_text(encoding='utf-8', errors='replace')))
    with ThreadPoolExecutor(max_workers=8) as pool:
        for relative, entries in pool.map(scan, sorted(published)):
            for name, line in entries:
                found.setdefault(name, []).append({'path': '2008-06/' + relative, 'line': line})
    sources = {}
    for address, entry in names.items():
        name = readable(entry['symbol'])
        if undecorate:
            buffer = ctypes.create_string_buffer(16384)
            if undecorate(entry['symbol'].encode(), buffer, len(buffer), 0x1000):  # UNDNAME_NAME_ONLY
                name = buffer.value.decode(errors='replace')
        matches = found.get(plain_name(name), [])
        if len(matches) == 1:
            sources[address] = matches[0]
    return sources
