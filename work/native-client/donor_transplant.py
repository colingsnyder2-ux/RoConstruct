"""Donor transplant lane (no model calls): remaining functions whose server-exact analog is an authentic 2007 donor
unit (`// lib rbxgs|openrbx...`) get that donor function text, verbatim, compiled against the native headers through
the placeholder lane's judge() (include resolution, header-copy picking, vendor includes, SDK order).  Exact ones are
written as placeholder-lane/<addr>/try9.cpp (what the promoter reads) and recorded in donor-transplant-hits.json
(merged into results.json by `lane_runner.py promote`, so no race with running lanes).
  python work/native-client/donor_transplant.py [--jobs 8]"""
import argparse
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=8)
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'donor', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.regate:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, ROOT, OUT = lane['m'], lane['ROOT'], lane['OUT']
from roc import libs  # noqa: E402

reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())


def donor_text(addr):
    path = ROOT / 'src/2008-06' / (addr + '.cpp')
    if not path.is_file():
        return None
    analog = path.read_text(errors='replace')
    lib = (m.match.directives(analog).get('lib') or '').split(' ')[0]
    if not lib.startswith(('rbxgs', 'openrbx')):
        return None
    try:
        units = libs.units_used(analog)
    except Exception:                                               # noqa: BLE001
        return None
    return next(iter(next(iter(units.values())).values()), '') if units else None


def extract(raw, qual):
    """Definition of QUAL (`RBX::Lighting::setAmbient`) from donor text: header line through the matched body."""
    parts = qual.split('::')
    for spell in ('::'.join(parts[-2:]) if len(parts) > 1 else parts[-1], parts[-1]):
        for hit in re.finditer(r'(?<![\w:])%s\s*\(' % re.escape(spell), raw):
            open_brace = raw.find('{', hit.end())
            semi = raw.find(';', hit.end())
            if open_brace < 0 or (0 <= semi < open_brace and ')' not in raw[hit.end():semi]):
                continue
            between = raw[hit.end():open_brace]
            if ';' in between and ':' not in between:              # a declaration, not a definition
                continue
            start = max(raw.rfind(';', 0, hit.start()), raw.rfind('}', 0, hit.start()), raw.rfind('{', 0, hit.start())) + 1
            depth = 0
            for i in range(open_brace, len(raw)):
                depth += {'{': 1, '}': -1}.get(raw[i], 0)
                if depth == 0:
                    text = raw[start:i + 1].strip()
                    text = re.sub(r'^\s*(?:public|private|protected)\s*:\s*', '', text)
                    return text if len(text) < 12000 else None
    return None


def run(addr):
    row = reg.get(addr) or {}
    name, sig = row.get('name') or '', row.get('signature') or ''
    if not name or not sig or name.startswith(('func_', 'sub_')):
        return addr, 'no-name', ''
    qual = re.sub(r'<[^<>]*>', '', sig.split('(')[0].split()[-1])
    raw = donor_text(addr)
    if not raw:
        return addr, 'no-donor', ''
    body = extract(raw, qual)
    if not body:
        return addr, 'no-definition', ''
    owner = row.get('owner_class') or ''
    spaces = [p for p in qual.split('::')[:-2]] if '::' in qual else []
    if spaces and not body.lstrip().startswith(tuple(spaces)) and '::' not in body.split('(')[0].split()[-1][:len(qual)]:
        body = ''.join('namespace %s { ' % p for p in spaces) + '\n' + body + '\n' + '}' * len(spaces)
    lane['NAMED'][addr] = (name, sig)
    reply = '```cpp\n%s\n```' % body
    try:
        status, detail, cls, decl = lane['judge'](OUT / addr, addr, reply, body)
    except Exception as error:                                       # noqa: BLE001
        return addr, 'harness-error', repr(error)
    if status == 'inactive_exact':
        (OUT / addr).mkdir(parents=True, exist_ok=True)
        (OUT / addr / 'try9.cpp').write_text(reply)
    return addr, status, detail[:200]


targets = [a for a, v in cl.items() if 'donor-exact' in str(v.get('detail', '')) or v.get('bucket') in (
    'never tried (no header/queue route)', 'parked: 4+ LLM tries', 'LLM tried 1-3', 'LLM tried 1-3 (draft)',
    'template instantiation', 'too big for LLM lane (>2 KB)', 'static initializer')]
print('donor transplant candidates: %d' % len(targets), flush=True)
hits_path = HERE / 'donor-transplant-hits.json'
hits = json.loads(hits_path.read_text()) if hits_path.is_file() else {}
counts = {}
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(run, targets):
        counts[status] = counts.get(status, 0) + 1
        if status == 'inactive_exact':
            hits[addr] = {'cls': '', 'decl': '', 'model': 'donor-transplant'}
            hits_path.write_text(json.dumps(hits, indent=1))
            print('  %s exact (donor transplant)' % addr, flush=True)
print('RESULT donor transplant: %s' % counts, flush=True)
