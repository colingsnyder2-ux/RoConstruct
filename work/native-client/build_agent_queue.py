"""Class-recovery queue for headless agents (dashboard lane `agents`): remaining functions grouped by owner class,
ranked by remaining bytes, skipping core-header classes and classes already queued/done (agent-class-done.json).
Each entry carries the address list and evidence hints.  -> agent-class-queue.json
  python work/native-client/build_agent_queue.py [--min 3] [--max 40]"""
import argparse
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--min', type=int, default=3, help='least remaining functions for a class to get an agent')
ap.add_argument('--max', type=int, default=40, help='queue length')
args = ap.parse_args()
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import native_llm as m  # noqa: E402
from roc import integration_site  # noqa: E402

CORE = {'RBX::Instance', 'RBX::DataModel', 'Instance', 'DataModel'}
reg = m.load_registry()
exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
remaining = {a: v for a, v in json.loads((HERE / 'remaining-classified.json').read_text()).items() if a not in exact}
done_path = HERE / 'agent-class-done.json'
done = set(json.loads(done_path.read_text())) if done_path.is_file() else set()
done |= {'RBX::AdornRbxGfx', 'RBX::Render::RenderScene', 'RBX::Network::Replicator', 'RBX::ScriptContext',
         'CRobloxWnd', 'RBX::Camera', 'RBX::SleepStage', 'RBX::World', 'RBX::GeoPair', 'RBX::Workspace',
         'RBX::Accoutrement'}           # this session's first agent batch


INFERRED_OWNERS = json.loads((HERE / 'owner-classes.json').read_text()) if (HERE / 'owner-classes.json').is_file() else {}


def owner(addr):
    if addr in INFERRED_OWNERS:      # owner_classes.py: neighbours/vtable/thiscall agreement (>=91% on known owners)
        return INFERRED_OWNERS[addr]['class']
    row = reg.get(addr) or {}
    sig = row.get('signature') or ''
    hit = re.search(r'__\w+ ((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)::~?[A-Za-z_]\w*\(', re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', sig)))
    if hit and hit.group(1) not in ('RBX', 'std', 'boost', 'G3D'):
        return hit.group(1)
    return row.get('owner_class') or None


DONE_LEAVES = {d.split(' + ')[0].split('::')[-1] for d in done}
NOT_CLASSES = {'RBX', 'std', 'boost', 'G3D', 'const_iterator', 'iterator', 'Descriptor', 'Creator', 'FactoryProduct'}
groups = collections.defaultdict(list)
for a, v in remaining.items():
    if v.get('bucket') == 'vendor-library':
        continue
    cls = owner(a)
    if cls and cls not in CORE and len(cls) > 2:
        groups[cls].append(a)
queue = []
for cls, addrs in sorted(groups.items(), key=lambda kv: -sum(remaining[a]['size'] for a in kv[1])):
    if len(addrs) < args.min or cls in done or cls.split('::')[-1] in DONE_LEAVES or cls.split('::')[-1] in NOT_CLASSES:
        continue
    header = m.declaring_header(cls)
    queue.append({'class': cls, 'addresses': sorted(addrs), 'bytes': sum(remaining[a]['size'] for a in addrs),
                  'header': str(Path(header).relative_to(ROOT)) if header and Path(header).is_relative_to(ROOT) else None})
    if len(queue) >= args.max:
        break
# One session per header family: classes declared in the same header would otherwise collide on its lease and each
# re-read it.  Classes without a native header stay separate.
merged, by_header = [], {}
for q in queue:
    h = q['header']
    if h and h in by_header and len(by_header[h]['addresses']) + len(q['addresses']) <= 30:
        t = by_header[h]
        t['class'] += ' + ' + q['class']
        t['addresses'] += q['addresses']
        t['bytes'] += q['bytes']
        continue
    merged.append(q)
    if h:
        by_header[h] = q
queue = merged
(HERE / 'agent-class-queue.json').write_text(json.dumps(queue, indent=1))
print('queued %d classes (%d functions); top: %s' % (len(queue), sum(len(q['addresses']) for q in queue),
                                                     ', '.join('%s(%d)' % (q['class'], len(q['addresses'])) for q in queue[:10])))
