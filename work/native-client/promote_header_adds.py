"""Promote header-add lines that the lane byte-proved (placeholder-lane/results.json: exact rows with 'header_add').

Per native header: lease it, prove up to N native TUs that include it (--no-register), insert every proven line into
its class (`// INFERRED (header-add): <evidence> - byte-proved by <addr>`), re-prove the same TUs, keep the edit only if
the summed exact count does not drop (else restore).  Then run native_placeholder_promote.py for the functions.
  python work/native-client/promote_header_adds.py [--sample 4] [--dry-run]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
ap = argparse.ArgumentParser()
ap.add_argument('--sample', type=int, default=4)
ap.add_argument('--dry-run', action='store_true')
args = ap.parse_args()
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m  # noqa: E402

results = json.loads((HERE / 'placeholder-lane/results.json').read_text())
by_header = collections.defaultdict(list)
for addr, row in results.items():
    if row.get('status') != 'inactive_exact' or not row.get('header_add'):
        continue
    for cls, decl, ev in row['header_add']:
        path = m.declaring_header(cls)
        if path and Path(path).is_relative_to(HEADERS):
            by_header[Path(path)].append((cls, decl, ev, addr))


def exact_total(files):
    if not files:
        return 0
    out = subprocess.run([sys.executable, str(HERE / 'prove.py'), *map(str, files), '--rounds', '1', '--no-register'],
                         cwd=ROOT, capture_output=True, text=True).stdout
    return sum(int(x) for x in re.findall(r': (\d+) exact', out))


def insert(text, cls, decl, ev, addr):
    leaf = cls.rsplit('::', 1)[-1]
    found = re.search(r'^[ \t]*(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text, re.M)
    if not found:
        return text, False
    depth, end = 0, found.end() - 1
    for end in range(found.end() - 1, len(text)):
        depth += {'{': 1, '}': -1}.get(text[end], 0)
        if depth == 0:
            break
    name = re.search(r'(~?\w+)\s*(?:\(|;|\[)', decl)
    if name and re.search(r'\b%s\s*[\(;\[]' % re.escape(name.group(1)), text[found.end():end]):
        return text, False                                          # already declared
    start = text.rfind('\n', 0, end) + 1
    start = start if not text[start:end].strip() else end
    indent = re.match(r'[ \t]*', text[found.start():]).group(0)
    line = '%spublic:\n%s\t%s   // INFERRED (header-add): %s - byte-proved by %s\n' % (indent, indent, decl, ev.lstrip('/ '), addr)
    return text[:start] + line + text[start:], True


report = []
for header, adds in sorted(by_header.items()):
    rel = header.relative_to(ROOT).as_posix()
    includers = [p for p in sorted(CLASSES.glob('*.cpp'))
                 if re.search(r'#include\s*"[^"]*%s"' % re.escape(header.relative_to(HEADERS).as_posix()), p.read_text(errors='replace'))]
    sample = includers[:args.sample]
    text = header.read_text(errors='replace')
    new, changed = text, 0
    for cls, decl, ev, addr in adds:
        new, ok = insert(new, cls, decl, ev, addr)
        changed += ok
    if not changed:
        continue
    if args.dry_run:
        report.append(dict(header=rel, lines=changed, sample=[s.name for s in sample]))
        continue
    lease = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'take', 'header-add:' + header.name, rel, '--hours', '1'],
                           cwd=ROOT, capture_output=True, text=True)
    if lease.returncode:
        report.append(dict(header=rel, status='blocked-lease'))
        continue
    try:
        before = exact_total(sample)
        header.write_text(new)
        after = exact_total(sample)
        if after < before:
            header.write_text(text)
            report.append(dict(header=rel, status='reverted', before=before, after=after, lines=changed))
        else:
            report.append(dict(header=rel, status='kept', before=before, after=after, lines=changed,
                               addrs=sorted({a for _, _, _, a in adds})))
    finally:
        subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'release', 'header-add:' + header.name], cwd=ROOT, capture_output=True)
(HERE / 'header-add-promotions.json').write_text(json.dumps(report, indent=1))
for row in report:
    print(row)
