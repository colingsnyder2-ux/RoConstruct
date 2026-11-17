"""Audit headless class-agent transcripts (~/.claude/projects/<project>/*.jsonl): tool calls by kind, repeated
command shapes, tokens per session, and the biggest token sinks (tool results).  Read-only.
  python work/native-client/agent_audit.py [--since HH:MM] [--files a.jsonl b.jsonl ...]"""
import argparse
import collections
import json
import os
import re
import time
from pathlib import Path

PROJ = Path.home() / '.claude/projects/C--Users-colin-RoConstruct'
ap = argparse.ArgumentParser()
ap.add_argument('--since', default='')
ap.add_argument('--files', nargs='*')
ap.add_argument('--max-mb', type=float, default=5, help='skip transcripts bigger than this (the main session)')
args = ap.parse_args()
files = [PROJ / f for f in args.files] if args.files else sorted(PROJ.glob('*.jsonl'), key=os.path.getmtime)[-30:]
if args.since:
    h, mi = map(int, args.since.split(':'))
    t = time.localtime()
    cut = time.mktime((t.tm_year, t.tm_mon, t.tm_mday, h, mi, 0, 0, 0, -1))
    files = [f for f in files if f.stat().st_mtime >= cut]
files = [f for f in files if f.stat().st_size < args.max_mb * 1e6]

tool_kinds, shapes, result_sinks = collections.Counter(), collections.Counter(), collections.Counter()
per = []
for f in files:
    calls, inp, out, cache_read, cache_write, model, first = 0, 0, 0, 0, 0, '', ''
    id_name = {}
    for line in open(f, encoding='utf-8', errors='replace'):
        try:
            e = json.loads(line)
        except ValueError:
            continue
        msg = e.get('message') or {}
        if e.get('type') == 'user' and not first and isinstance(msg.get('content'), str):
            first = msg['content'][:60]
        u = msg.get('usage') or {}
        inp += u.get('input_tokens', 0) or 0
        out += u.get('output_tokens', 0) or 0
        cache_read += u.get('cache_read_input_tokens', 0) or 0
        cache_write += u.get('cache_creation_input_tokens', 0) or 0
        model = msg.get('model') or model
        for c in msg.get('content') or [] if isinstance(msg.get('content'), list) else []:
            if c.get('type') == 'tool_use':
                calls += 1
                name = c.get('name')
                tool_kinds[name] += 1
                cmd = (c.get('input') or {}).get('command') or (c.get('input') or {}).get('file_path') or ''
                shape = re.sub(r'[0-9a-f]{8}', 'ADDR', str(cmd))
                shape = re.sub(r'"[^"]*"|\'[^\']*\'', 'STR', shape)
                shapes[(name, ' '.join(shape.split()[:4])[:90])] += 1
                id_name[c.get('id')] = (name, ' '.join(shape.split()[:3])[:60])
            if c.get('type') == 'tool_result':
                content = c.get('content')
                size = len(json.dumps(content)) if content is not None else 0
                result_sinks[id_name.get(c.get('tool_use_id'), ('?', '?'))] += size
    per.append((f.name[:8], model, calls, inp, out, cache_read, cache_write, first))

print('sessions: %d' % len(per))
print('%-9s %-22s %5s %8s %7s %10s %9s  %s' % ('id', 'model', 'calls', 'input', 'output', 'cacheRead', 'cacheWr', 'task'))
for p in per:
    print('%-9s %-22s %5d %8d %7d %10d %9d  %s' % p)
print('\ntool kinds:', dict(tool_kinds.most_common()))
print('\ntop repeated command shapes:')
for (name, shape), n in shapes.most_common(25):
    print('  %4d %-10s %s' % (n, name, shape))
print('\nbiggest tool-result sinks (chars returned into context):')
for (name, shape), n in result_sinks.most_common(15):
    print('  %9d %-10s %s' % (n, name, shape))
