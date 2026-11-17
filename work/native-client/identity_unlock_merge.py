"""Merge identity_unlock_* route outputs into work/native-client/unnamed-identities.json.

Priority (first wins per address): init > mfc > vtable (original RTTI) > align/objvt
(compiled objects) > calls > donor.  Every kept name: undnames, is not already a registry name of another
address, and is unique in the output.  Each row records whether its owner class (leaf
name) is declared by a class/struct in rebuild/2008-06/native-headers, tools/rbxgs or
tools/libs headers (`header-known` evidence) - report only, not a filter.
"""
import json
from functools import lru_cache
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, unnamed, undname_many  # noqa: E402

NC = ROOT / 'work/native-client'
ROUTES = [('init', 'identity-unlock-init.json'), ('mfc', 'identity-unlock-mfc.json'),
          ('vtable', 'identity-unlock-vtable.json'), ('dupfix', 'identity-unlock-dupfix.json'), ('vtsib', 'identity-unlock-vtsib.json'),
          ('vthdr', 'identity-unlock-vthdr.json'), ('align', 'identity-unlock-align.json'), ('wsfp', 'identity-unlock-wsfp.json'), ('ws', 'identity-unlock-ws.json'),
          ('objvt', 'identity-unlock-objvt.json'), ('donorcg', 'identity-unlock-donorcg.json'),
          ('strlit', 'identity-unlock-strlit.json'),
          ('bodyhash', 'identity-unlock-bodyhash.json'), ('msgmap', 'identity-unlock-msgmap.json'), ('srcorder', 'identity-unlock-srcorder.json'),
          ('clink', 'identity-unlock-clink.json'), ('upgrade', 'identity-unlock-upgrade.json'),
          ('reflect', 'identity-unlock-reflect.json'),
          ('calls', 'identity-unlock-calls.json'),
          ('donor', 'identity-unlock-donor.json')]
OUT = NC / 'unnamed-identities.json'
PLACEHOLDER = re.compile(r'(sub|FUN|func|LAB|thunk|unk|fn)_[0-9A-Fa-f]+$')  # drafts put these in headers
HEADER_DIRS = ['rebuild/2008-06/native-headers', 'tools/rbxgs', 'tools/libs']
CLASS_RE = r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(?:[A-Z_][A-Z0-9_]+\s+)?[A-Za-z_]\w*'


@lru_cache(None)
def header_classes():
    out = subprocess.run(['rg', '-uu', '-o', '-N', '--no-filename', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl',
                          CLASS_RE] + [str(ROOT / d) for d in HEADER_DIRS],
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    return {line.split()[-1] for line in out.splitlines()}


@lru_cache(None)
def vendor_classes():
    """Classes declared by vendor library headers (tools/libs, VC include, VC atlmfc)."""
    dirs = ['tools/libs'] + [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/include')]
    out = subprocess.run(['rg', '-uu', '-o', '-N', '--no-filename', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl',
                          CLASS_RE] + [str(ROOT / d) for d in dirs],
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    return {line.split()[-1] for line in out.splitlines()}


def vendor_owner(path, vendor):
    """Vendor-library owner not yet named in the binary: a namespaced non-RBX class
    (ATL::CRegObject) or a Codejock CXT* class declared in vendor headers; generic leaf names
    such as 'S' or 'Table' are declared somewhere in every library and prove nothing."""
    parts = path.split('@')
    if parts[-1] == 'RBX' or parts[0] not in vendor:
        return False
    return len(parts) > 1 or parts[0].startswith('CXT')


@lru_cache(None)
def header_idents():
    """Identifiers in authentic headers (roc_* scratch and archive files excluded)."""
    dirs = HEADER_DIRS + [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/include')] +         [str(p.relative_to(ROOT)) for p in ROOT.glob('tools/vc2008rtm/*/VC/atlmfc/include')]
    out = subprocess.run(['rg', '-uu', '-o', '-N', '--no-filename', '-g', '*.h', '-g', '*.hpp', '-g', '*.inl',
                          '-g', '!roc_*', '-g', '!*_archive*', r'[A-Za-z_]\w*'] + [str(ROOT / d) for d in dirs],
                         capture_output=True, text=True, encoding='utf-8', errors='ignore').stdout
    return set(out.split())


def untemplate(s):
    depth, out = 0, []
    for ch in s:
        depth += ch == "<"
        if not depth:
            out.append(ch)
        depth -= ch == ">" and depth > 0
    return "".join(out)


@lru_cache(None)
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
    # also 'bogus duplicate name' rows (one template-peer name on several addresses)
    rc = NC / 'remaining-classified.json'
    bogus = {a: v['name'] for a, v in json.load(open(rc)).items()
             if v.get('bucket') == 'bogus duplicate name'} if rc.exists() else {}
    targets = set(unnamed()) | set(bogus)
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')} - set(bogus.values())
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
    # owner path as mangled (e.g. 'DataModel@RBX') of every registry symbol
    reg_owners = {m.group(1) for m in (re.match(r'\?(?:\?[0-9A-Z_]{1,2})?\w+@((?:\w+@)*?\w+)@@', v['name'])
                                       for v in REG.values() if not v.get('placeholder')) if m}
    # classes the original binary uses as a type in some real registry name (parameter, RTTI)
    reg_text = '|'.join(v['name'] for v in REG.values() if not v.get('placeholder'))
    idents = header_idents()
    vendor = vendor_classes()
    out, per, hk = {}, Counter(), Counter()
    for a, r in sorted(rows.items()):
        sig = und.get(r['name'])
        if src[a] == 'clink' and re.match(r'_[A-Za-z]\w*$', r['name']):
            sig = r['signature']  # C names do not undecorate
        if not sig or sig == r['name']:
            per[src[a] + ':undname-failed'] += 1
            continue
        # compiled-object names can come from LLM drafts: every name part must be authentic
        if src[a] in ('align', 'objvt', 'vthdr', 'calls', 'strlit', 'bodyhash', 'upgrade', 'reflect') and not all(x in idents and len(x) > 1 and not PLACEHOLDER.match(x)
                                                                                                                for x in qual_parts(sig)):
            per[src[a] + ':not-in-headers'] += 1
            continue
        # a compiled-object member name must belong to a class (exact namespace path) that the
        # original binary already has other named members of; drafts invent classes like 'S'
        om = re.match(r'\?(?:\?[0-9A-Z_]{1,2})?\w+@((?:\w+@)*?\w+)@@', r['name'])
        if src[a] in ('align', 'objvt', 'vthdr', 'calls', 'strlit', 'bodyhash', 'upgrade', 'reflect') and om and om.group(1) not in reg_owners                 and not vendor_owner(om.group(1), vendor)                 and 'V%s@@' % om.group(1) not in reg_text and 'U%s@@' % om.group(1) not in reg_text:
            per[src[a] + ':owner-not-in-binary'] += 1
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
