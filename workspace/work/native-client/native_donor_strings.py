"""Candidate names for 2008 functions from string literals shared with the iOS 2013 donor.

Read-only.  A string literal used by exactly one donor function and by a 2008
function names a candidate (donor `Owner::method`).  Precision is measured on
2008 functions the identity closure already names: the candidate's
`Owner::method` must equal the bound name.  Candidates are donor evidence for a
2008 identity, never proof (CLAUDE.md: donor evidence never substitutes for
selected-target proof).
"""
import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_conversion_queue import undecorate  # noqa: E402

LITERAL = re.compile(r'"((?:[^"\\\n]|\\.){6,200})"')
SIGNATURE = re.compile(r'^/\* ((?!WARNING)[^*\n]+?\(.*?) \*/$', re.M)


def norm(name):
    """Drop elaborated-type keywords and the repeated template-ctor arguments."""
    name = re.sub(r'\b(?:enum|class|struct) ', '', name)
    if name.endswith('>'):  # drop the balanced template-argument list of the last component
        depth = 0
        for i in range(len(name) - 1, -1, -1):
            depth += name[i] == '>'
            depth -= name[i] == '<'
            if depth == 0:
                return name[:i]
    return name


def method(signature):
    """`RBX::Owner::name` from a donor `/* RBX::Owner::name(args) */` line."""
    depth = 0
    for i, ch in enumerate(signature):
        depth += ch == '<'
        depth -= ch == '>'
        if ch == '(' and depth == 0:
            return signature[:i].strip()
    return signature.strip()


def index(donor):
    users = defaultdict(set)  # literal -> donor methods
    for path in donor.rglob('*.c'):
        text = path.read_text(encoding='utf-8', errors='replace')
        sig = SIGNATURE.search(text)
        if not sig:
            continue
        name = method(sig[1])
        for lit in set(LITERAL.findall(text)):
            users[lit.encode().decode('unicode_escape', errors='replace')].add(name)
    return {k: sorted(v) for k, v in users.items()}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--donor', type=Path, default=ROOT / 'local/references/ios-2013-12_2.132.41333')
    ap.add_argument('--index', type=Path, default=Path(__file__).resolve().parent / 'claude-donor-literals.json',
                    help='cached literal index; delete to rescan the donor (about 26 min)')
    ap.add_argument('--strings', type=Path, required=True, help='claude-string-evidence.json')
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    if args.index.exists():
        users = json.loads(args.index.read_text())
    else:
        users = index(args.donor)
        args.index.write_text(json.dumps(users) + '\n')
    unique = {lit: n[0] for lit, n in users.items() if len(n) == 1}
    bound = defaultdict(list)
    for row in json.loads(args.closure.read_text())['bindings']:
        bound[row['addr']].append(undecorate(row['symbol'], 0x1000))
    rows, totals = [], Counter()
    for addr, info in json.loads(args.strings.read_text())['functions'].items():
        votes = Counter(unique[s] for s in info['strings'] if s in unique)
        if not votes:
            continue
        (best, n), *rest = votes.most_common()
        if rest and rest[0][1] == n:
            totals['tied'] += 1
            continue
        names = bound.get(addr, [])
        verdict = ('agree' if norm(best) in {norm(x) for x in names} else 'disagree') if names else 'new'
        totals[verdict] += 1
        rows.append({'address': addr, 'candidate': best, 'shared_unique_strings': n,
                     'other_candidates': dict(rest[:3]), 'bound': names[:3], 'verdict': verdict})
    checked = totals['agree'] + totals['disagree']
    totals['precision_on_named'] = round(totals['agree'] / checked, 3) if checked else None
    totals['donor_literals'], totals['donor_unique_literals'] = len(users), len(unique)
    out = {'scope': __doc__.splitlines()[0] + ' Donor candidates only.', 'summary': dict(totals),
           'functions': sorted(rows, key=lambda r: (r['verdict'] != 'new', -r['shared_unique_strings']))}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    assert norm('RBX::E<enum RBX::S>::E<enum RBX::S>') == norm('RBX::E<RBX::S>::E')
    assert SIGNATURE.findall('/* WARNING: x */\n/* RBX::A::b(int) */') == ['RBX::A::b(int)']
    main()
