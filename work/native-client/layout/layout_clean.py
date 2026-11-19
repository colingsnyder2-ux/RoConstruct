"""Beautify an exported source: move recovery notes to a sidecar, tidy whitespace.

clean(text) -> (cleaned_text, notes). Only whole-line `//` comment blocks that carry
recovery vocabulary (target addresses, native-flags, donor/tool paths, proof words)
leave the file; `// INFERRED:` lines and ordinary doc comments stay. Nothing is lost:
every removed block is returned with its original line number for the evidence file.

tokens(text) strips comments and whitespace. Equal tokens before and after mean the
compiler sees the same program apart from line numbers; line_sensitive(text) flags
files where line numbers can reach codegen (assert-style macros, __LINE__).
"""
import re

RECOVERY = re.compile(
    r'\b(?:0x)?00[4-9a-fA-F][0-9a-fA-F]{5}\b'
    r'|native-(?:flags|profile|headers|classes|status|world)'
    r'|\bdonor\b|tools/(?:rbxgs|openrbx|libs)|\b[Ii]nactive\b|\broc_\w+|\bmined\b'
    r'|byte-identical|\b2008-06\b|tests/\w+\.py|check_native_class|\b[Rr]ecovered\b'
    r'|\bRTTI\b|near-miss|\bBatch \d|emitted by this unit')
LINE_SENSITIVE = re.compile(r'assert|__LINE__|__FILE__|__COUNTER__|\bVERIFY\b|\bTRACE\b', re.I)
FLAGS = re.compile(r'^// native-(flags|profile): ?(.*)$', re.M)


def tokens(text):
    """Program text without comments or whitespace; strings and char literals kept verbatim."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            out.append(text[i:j + 1])
            i = j + 1
        elif text.startswith('//', i):
            while i < n and text[i] != '\n':
                i += 2 if text.startswith('\\\n', i) else 1   # a backslash continues a // comment
        elif text.startswith('/*', i):
            i = text.find('*/', i + 2)
            i = n if i < 0 else i + 2
            out.append(' ')                                    # a block comment separates tokens
        elif c.isspace():
            out.append(' ')
            i += 1
        else:
            out.append(c)
            i += 1
    return re.sub(r'\s+', ' ', ''.join(out)).strip()


def line_sensitive(text):
    return bool(LINE_SENSITIVE.search(tokens(text)))


def is_wrapper(text):
    """True when a source holds no code of its own: only comments and preprocessor lines.

    Vendor and donor wrappers just `#include` a library file or a cached preprocessed unit. A copy
    of one at an original path would publish an include of something else, not source.
    """
    code = [line for line in re.sub(r'/\*.*?\*/', '', text, flags=re.S).splitlines()
            if line.strip() and not line.lstrip().startswith('//')]
    return bool(code) and all(line.lstrip().startswith('#') for line in code)


def build_notes(text):
    """Pinned compiler flags/profile recorded in the source, for the build table."""
    return {kind: value.strip() for kind, value in FLAGS.findall(text.replace('\r\n', '\n'))}


def clean(text):
    newline = '\r\n' if '\r\n' in text else '\n'
    lines = text.replace('\r\n', '\n').split('\n')
    keep, notes, i = [], [], 0
    while i < len(lines):
        if not lines[i].lstrip().startswith('//'):
            keep.append(lines[i].rstrip())
            i += 1
            continue
        j = i
        while j < len(lines) and lines[j].lstrip().startswith('//'):
            j += 1
        block = lines[i:j]
        if any(RECOVERY.search(line) for line in block):
            notes.append({'line': i + 1, 'text': [line.strip() for line in block]})
            keep.extend(line.rstrip() for line in block if 'INFERRED' in line)
        else:
            keep.extend(line.rstrip() for line in block)
        i = j
    tidy = []
    for line in keep:                      # at most one blank line in a row, none at the top
        if line or (tidy and tidy[-1]):
            tidy.append(line)
    while tidy and not tidy[-1]:
        tidy.pop()
    return newline.join(tidy) + newline, notes
