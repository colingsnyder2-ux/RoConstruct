"""Per-class member offsets from Ghidra headless (decompiler FillOutStructure on `this`, which follows aliases and
callees): runs ghidra-headless/scripts/Layout.java once over every registry method of the classes the class-agent
queue holds (exact and remaining), merges per class -> ghidra-struct.json, and hint(cls) for agent prompts.
Works on the project COPY in ghidra-headless/proj-copy (the owner's Ghidra projects are never touched).
Sizes are lower bounds (the helper counts the highest offset reached through callees); types are weak - the value is
the offset list and which functions touch each offset.
  python work/native-client/ghidra_struct.py [--all-classes]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
GH = HERE / 'ghidra-headless'
OUT = HERE / 'ghidra-struct.json'


def owner_of(sig):
    flat = re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', sig or '')))
    hit = re.search(r'__\w+ ((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)::~?[A-Za-z_]\w*\(', flat)
    return hit.group(1) if hit and hit.group(1) not in ('RBX', 'std', 'boost', 'G3D') else None


def build(all_classes=False):
    sys.argv = sys.argv[:1]
    sys.path.insert(0, str(HERE))
    import native_llm as m
    reg = m.load_registry()
    queue = json.loads((HERE / 'agent-class-queue.json').read_text()) if (HERE / 'agent-class-queue.json').is_file() else []
    wanted = {c.strip() for t in queue for c in t['class'].split(' + ')}
    leaves = {c.split('::')[-1] for c in wanted}
    members = collections.defaultdict(list)
    for addr, row in reg.items():
        cls = owner_of(row.get('signature')) or row.get('owner_class')
        if cls and (all_classes or cls.split('::')[-1] in leaves):
            members[cls].append(addr)
    addrs = sorted({a for v in members.values() for a in v})
    (GH / 'struct.addrs').write_text('\n'.join(addrs) + '\n')
    tsv = GH / 'struct.out.tsv'
    headless = Path('C:/Users/colin/RBXBanland/work/re/ghidra/support/analyzeHeadless.bat')
    run = subprocess.run(['cmd', '/c', str(headless), str(GH / 'proj-copy'), 'Rbx2008M', '-process', 'RobloxApp_client.exe',
                          '-noanalysis', '-scriptPath', str(GH / 'scripts'), '-postScript', 'Layout.java',
                          str(GH / 'struct.addrs'), str(tsv)], capture_output=True, text=True, cwd=GH, timeout=1800)
    if not tsv.is_file():
        sys.exit('headless run produced no output:\n' + (run.stdout + run.stderr)[-1500:])
    per = collections.defaultdict(lambda: collections.defaultdict(list))
    for line in tsv.read_text(errors='replace').splitlines():
        r = line.split('\t')
        if r[0] == 'M' and len(r) >= 5:
            per[r[1]][int(r[2])].append((int(r[3]), r[4]))
    out = {}
    for cls, fns in members.items():
        offs = collections.defaultdict(lambda: {'types': collections.Counter(), 'fns': set()})
        for a in fns:
            for off, lst in per.get(a, {}).items():
                for width, ty in lst:
                    offs[off]['types']['%s/%d' % (ty, width)] += 1
                    offs[off]['fns'].add(a)
        if offs:
            out[cls] = [{'off': '0x%x' % o, 'types': [k for k, _ in v['types'].most_common(3)], 'uses': len(v['fns']),
                         'example': sorted(v['fns'])[0]} for o, v in sorted(offs.items())]
    OUT.write_text(json.dumps(out, indent=1))
    print('classes %d, offsets %d, from %d methods' % (len(out), sum(len(v) for v in out.values()), len(addrs)))


def hint(cls, limit=1600):
    if not OUT.is_file():
        return ''
    data = json.loads(OUT.read_text())
    rows = data.get(cls) or next((v for k, v in data.items() if k.split('::')[-1] == cls.split('::')[-1]), None)
    if not rows:
        return ''
    text = '\n'.join('+%s %s  (%d fn, e.g. %s)' % (r['off'], ', '.join(r['types']), r['uses'], r['example']) for r in rows)
    return text[:limit]


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--all-classes', action='store_true')
    build(ap.parse_args().all_classes)
