"""Merge identity_unlock_* route outputs into work/native-client/unnamed-identities.json.

Priority (first wins per address): init > mfc > vtable (original RTTI) > align/objvt
(compiled objects) > calls > donor.  Every kept name: undnames, is not already a registry name of another
address, and is unique in the output.  Each row records whether its owner class (leaf
name) is declared by a class/struct in rebuild/2008-06/native-headers, tools/rbxgs or
tools/libs headers (`header-known` evidence) - report only, not a filter.
"""
import json
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, unnamed, undname_many  # noqa: E402

NC = ROOT / 'work/native-client'
ROUTES = [('init', 'identity-unlock-init.json'), ('mfc', 'identity-unlock-mfc.json'),
          ('vtable', 'identity-unlock-vtable.json'), ('align', 'identity-unlock-align.json'),
          ('objvt', 'identity-unlock-objvt.json'), ('calls', 'identity-unlock-calls.json'),
          ('donor', 'identity-unlock-donor.json')]
OUT = NC / 'unnamed-identities.json'
HEADER_DIRS = ['rebuild/2008-06/native-headers', 'tools/rbxgs', 'tools/libs']
CLASS_RE = r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(?:[A-Z_][A-Z0-9_]+\s+)?[A-Za-z_]\w*'


def header_classes():
    out = subprocess.run(['rg', '-uu', '-o', '-N', '--no-filename', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl',
                          CLASS_RE] + [str(ROOT / d) for d in HEADER_DIRS],
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    return {line.split()[-1] for line in out.splitlines()}


def header_idents():
    """Identifiers in authentic headers (roc_* scratch and archive files excluded)."""
    dirs = HEADER_DIRS + [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/include')] +         [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/atlmfc/include')]
    out = subprocess.run(['rg', '-uu', '-o', '-N', '--no-filename', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl',
                          '-g', '!roc_*', '-g', '!*_archive*', r'[A-Za-z_]\w*'] + [str(ROOT / d) for d in dirs],
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    return set(out.split())


def qual_parts(sig):
    """Identifier parts of the qualified function name (templates and params dropped)."""
    depth, cut = 0, []
    for ch in sig:
        depth += ch == '<'
        if not depth:
            cut.append(ch)
        depth -= ch == '>'
    head = ''.join(cut).split('(')[0].split()
    parts = head[-1].split('::') if head else []
    return [x.lstrip('~') for x in parts if x and not x.startswith(('operator', '`'))]


def owner_of(sig):
    """Owner class leaf from an undname signature ('...RBX::Foo<...>::bar(...)')."""
    depth, cut = 0, []
    for ch in sig:  # drop template args, then the parameter list
        depth += ch == '<'
        if not depth:
            cut.append(ch)
        depth -= ch == '>'
    head = ''.join(cut).split('(')[0]
    parts = head.split()[-1].split('::') if head.split() else []
    return parts[-2] if len(parts) >= 2 else None


def main():
    targets = set(unnamed())
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    rows, src = {}, {}
    for route, fn in ROUTES:
        p = NC / fn
        if not p.exists():
            continue
        for a, r in json.load(open(p)).items():
            if a in targets and a not in rows and r['name'] not in taken:
                rows[a], src[a] = dict(r), route
    names = Counter(r['name'] for r in rows.values())
    rows = {a: r for a, r in rows.items() if names[r['name']] == 1}
    und = undname_many([r['name'] for r in rows.values()])
    known = header_classes()
    idents = header_idents()
    out, per, hk = {}, Counter(), Counter()
    for a, r in sorted(rows.items()):
        sig = und.get(r['name'])
        if not sig or sig == r['name']:
            per[src[a] + ':undname-failed'] += 1
            continue
        # compiled-object names can come from LLM drafts: every name part must be authentic
        if src[a] in ('align', 'objvt', 'calls') and not all(x in idents for x in qual_parts(sig)):
            per[src[a] + ':not-in-headers'] += 1
            continue
        r['signature'] = r.get('signature') or sig
        if r['name'].startswith('??__'):
            m = re.search(r"`dynamic (?:atexit destructor|initializer) for '(.*)''", sig)
            own = owner_of(m.group(1) + '(') if m else None
        else:
            own = owner_of(sig)
        if not own and r.get('owner_class'):
            own = owner_of(r['owner_class'] + '::x(')
        r['owner_class'] = r.get('owner_class') or own
        ok = bool(own) and re.sub(r'<.*', '', own) in known
        r['evidence'] = r['evidence'] + [{'kind': 'header-known', 'owner_leaf': own, 'known': ok}]
        out[a] = r
        per[src[a]] += 1
        hk[src[a]] += ok
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print(json.dumps({'unnamed_targets': len(targets), 'named': len(out), 'per_route': dict(per),
                      'header_known_per_route': dict(hk), 'header_known_total': sum(hk.values())}))


if __name__ == '__main__':
    main()
