"""Source file of a native piece from the iOS Dec 2013 linker debug map (the build agent's real source paths).

The debug map says which source file produced each iOS function. A 2008 function with the same qualified name
(RBX::Instance::setParent) is evidence for the same file. A native piece takes the file that most of its named
functions share; ties, thin votes and pieces that already have PDB, census or curated evidence are left alone.

This is evidence from a build five years later: the result is an inferred path, never Authentic.
"""
import collections
import re
import sqlite3
from pathlib import Path

from common import ROOT

DB = ROOT / 'local/references/mobile-index/symbols.sqlite'
MIN_VOTES = 2          # named functions that agree
MIN_SHARE = 0.6        # share of the piece's iOS-matched functions that name the winning file


def msvc(symbol):
    """RBX::Instance::setParent from ?setParent@Instance@RBX@@..., None for templates and operators."""
    if not symbol.startswith('?') or symbol.startswith('?$') or '@@' not in symbol:
        return None
    head = symbol[1:].split('@@', 1)[0]
    if head.startswith('?'):
        if head[1] not in '01':
            return None
        parts = head[2:].split('@')
        tail = ('<init>',) if head[1] == '0' else ('<fini>',)
    else:
        parts, tail = head.split('@'), ()
    if not parts or not all(parts) or any(p.startswith('?') or '$' in p for p in parts):
        return None
    return tuple(reversed(parts)) + tail


def itanium(symbol):
    m = re.match(r'_?_ZN[KV]*', symbol)
    if not m:
        return None
    parts, pos = [], m.end()
    while True:
        d = re.match(r'\d+', symbol[pos:])
        if not d:
            break
        n = int(d.group())
        pos += len(d.group())
        parts.append(symbol[pos:pos + n])
        pos += n
    ending = re.match(r'(C[12]|D[012])?E', symbol[pos:])
    if not parts or not ending:
        return None
    if ending.group(1):
        parts.append('<init>' if ending.group(1).startswith('C') else '<fini>')
    return tuple(parts)


def client_path(source):
    """'/Volumes/.../work/<id>/Client/App/x.cpp' -> 'client/App/x.cpp' (case kept), None outside Client/."""
    path = source.replace('\\', '/')
    at = path.rfind('/Client/')
    if at < 0:
        return None
    parts = []
    for part in path[at + 8:].split('/'):
        if part == '..':
            parts and parts.pop()
        elif part and part != '.':
            parts.append(part)
    return 'client/' + '/'.join(parts) if parts else None


def index():
    """{qualified name tuple: {original path: functions}} for every iOS function that has a source file."""
    if not DB.exists():
        return {}
    db = sqlite3.connect(DB.resolve().as_uri() + '?mode=ro', uri=True)
    result = collections.defaultdict(collections.Counter)
    for name, source in db.execute("select name, source from symbols where source != '' and kind = 36"):
        key, path = itanium(name), client_path(source)
        if key and path and path.endswith(('.cpp', '.cc', '.c')):
            result[key][path] += 1
    return result


def targets(jobs, index_=None):
    """{native source (as in the census jobs): {'target', 'votes', 'share', 'files'}} for pieces with a clear winner."""
    ios = index_ if index_ is not None else index()
    out = {}
    for job in jobs:
        votes = collections.Counter()
        for check in job['checks']:
            key = msvc(check['symbol'])
            for path in ios.get(key, ()):
                votes[path.casefold()] += 1
        if not votes:
            continue
        best, n = votes.most_common(1)[0]
        total = sum(votes.values())
        if n >= MIN_VOTES and n / total >= MIN_SHARE:
            display = next(p for key in ios.values() for p in key if p.casefold() == best)
            out[job['source']] = {'target': display, 'votes': n, 'share': round(n / total, 2), 'files': len(votes)}
    return out
