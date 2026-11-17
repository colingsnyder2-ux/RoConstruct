"""Verify header_gap_fill.py edits with the real gate compile: each modified native header is compiled in a probe with
the native gate's flags/include roots; an error on an added `// INFERRED: ... (header gap, header_gap_fill.py)` line
(or a new error the pristine header did not have) reverts that header to git HEAD.  Prints one line per header."""
import json
import re
import subprocess
import sys
from pathlib import Path

sys.argv = sys.argv[:1]
import native_llm as m              # noqa: E402
import native_creator_gate as cg    # noqa: E402

ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'


def errors(header, tag):
    work = ROOT / 'work/native-client/header-gap-verify' / tag
    cg.discover_symbol(work, [str(header)], 'void roc_header_probe_%s() {}' % tag, 'ffffff00', 'roc_header_probe')
    return [e for e in (cg.LAST_ERROR.get('ffffff00') or '').splitlines() if 'error' in e]


changed = subprocess.run(['git', 'diff', '--name-only', '--', 'rebuild/2008-06/native-headers'], cwd=ROOT,
                         capture_output=True, text=True).stdout.split()
for rel in changed:
    header = ROOT / rel
    if 'header_gap_fill.py' not in header.read_text(errors='replace'):
        continue
    after = errors(header, 'after')
    if not after:
        print('OK      ', rel)
        continue
    current = header.read_bytes()
    pristine = subprocess.run(['git', 'show', 'HEAD:' + rel], cwd=ROOT, capture_output=True).stdout
    header.write_bytes(pristine)
    before = errors(header, 'before')
    if before and before[0].split(':', 1)[-1] == after[0].split(':', 1)[-1]:
        header.write_bytes(current)          # same failure without the additions: not caused by them
        print('KEEP    ', rel, '(pre-existing:', after[0][-100:], ')')
    else:
        print('REVERTED', rel, after[0][-140:])
