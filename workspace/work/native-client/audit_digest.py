"""Hourly self-audit digest: a small text summary of how the last hours of work went, for the agent to read and act on.

  python work/native-client/audit_digest.py [--hours 1] [--transcript FILE] [--write]

No model is called here. The agent that runs this (Codex or Claude Code, on the contributor's own login) reads the digest
and follows work/native-client/AUDIT_PROMPT.md. Transcripts are read locally and never leave the machine; only this
digest (counts, command shapes, byte totals; no source code, no paths outside the repo) is meant to be read by the model.

Sections: bytes/hour, time per tool, repeated command shapes (automation candidates), waste, tool health.
Transcript formats: Claude Code (~/.claude/projects/*/*.jsonl) and Codex (~/.codex/sessions/**/rollout-*.jsonl).
"""
import argparse
import collections
import datetime
import glob
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
LOG = HERE / 'prove-log.jsonl'
OUT = HERE / 'audit'


def newest_transcript():
    home = Path.home()
    found = glob.glob(str(home / '.claude/projects/*/*.jsonl')) + glob.glob(str(home / '.codex/sessions/**/rollout-*.jsonl'), recursive=True)
    mine = [f for f in found if ROOT.name.lower() in f.lower().replace('\\', '/') or '.codex' in f]
    pool = mine or found
    return max(pool, key=os.path.getmtime) if pool else None


def stamp(value):
    try:
        return datetime.datetime.fromisoformat(str(value).replace('Z', '+00:00')).timestamp()
    except ValueError:
        return None


def events(path):
    """-> [(time, tool, command-or-'')] in order, from either transcript format."""
    rows = []
    for line in open(path, encoding='utf-8', errors='replace'):
        try:
            d = json.loads(line)
        except ValueError:
            continue
        t = stamp(d.get('timestamp'))
        if t is None:
            continue
        message = d.get('message')
        content = message.get('content') if isinstance(message, dict) else None
        if isinstance(content, list):                                   # Claude Code
            for part in content:
                if isinstance(part, dict) and part.get('type') == 'tool_use':
                    args = part.get('input') or {}
                    rows.append((t, part.get('name', '?'), str(args.get('command') or args.get('file_path') or '')[:300]))
                elif isinstance(part, dict) and part.get('type') == 'tool_result' and part.get('is_error'):
                    rows.append((t, '!error', ''))
        payload = d.get('payload')
        if isinstance(payload, dict) and payload.get('type') in ('function_call', 'local_shell_call', 'custom_tool_call'):   # Codex
            args = payload.get('arguments') or payload.get('action') or payload.get('input') or ''
            rows.append((t, payload.get('name', 'shell'), str(args)[:300]))
    return sorted(rows)


def shape(command):
    """Collapse a command to its shape: tool script + flags, numbers/paths/hex removed."""
    command = re.sub(r'0x[0-9a-fA-F]+|\b[0-9a-f]{8}\b|\d+', 'N', command)
    command = re.sub(r'["\'][^"\']*["\']', 'S', command)
    command = re.sub(r'[\w./\\:-]*[/\\][\w./\\-]*', 'P', command)
    return ' '.join(command.split()[:6])


def section_time(rows, since):
    spent = collections.Counter()
    shapes = collections.Counter()
    errors = 0
    recent = [r for r in rows if r[0] >= since]
    for (t, tool, cmd), nxt in zip(recent, recent[1:] + [(recent[-1][0] if recent else 0, '', '')]):
        if tool == '!error':
            errors += 1
            continue
        spent[tool] += max(0, min(nxt[0] - t, 1800))
        if cmd and tool.lower() in ('bash', 'powershell', 'shell', 'exec_command', 'local_shell'):
            shapes[shape(cmd)] += 1
    return spent, shapes, errors, len(recent)


def section_bytes(hours):
    """Exact bytes per hour from prove-log.jsonl (latest exact_bytes per family at each end of the window)."""
    if not LOG.exists():
        return None
    mtime = LOG.stat().st_mtime
    latest = {}
    for line in LOG.read_text(errors='replace').splitlines():
        try:
            d = json.loads(line)
        except ValueError:
            continue
        if 'family' in d:
            latest[d['family']] = d
    total = sum(d.get('exact_bytes', 0) for d in latest.values() if not d['family'] == 'ogre')
    snap = HERE / 'audit/bytes-snapshots.jsonl'
    previous = None
    if snap.exists():
        for line in snap.read_text().splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row['t'] <= time.time() - hours * 3600 + 120:
                previous = row
    return total, previous, mtime


def git_commits(hours):
    out = subprocess.run(['git', 'log', '--since=%d minutes ago' % int(hours * 60), '--format=%ct %s'], cwd=ROOT, capture_output=True, text=True).stdout
    return [l for l in out.splitlines() if l.strip()]


def tool_health():
    run = subprocess.run([sys.executable, str(HERE / 'bootstrap_tools.py')], cwd=ROOT, capture_output=True, text=True)
    return [l for l in run.stdout.splitlines() if l.startswith(('MISS', 'READY', 'NOT READY'))]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--hours', type=float, default=1.0)
    ap.add_argument('--transcript')
    ap.add_argument('--write', action='store_true', help='also save to work/native-client/audit/YYYYMMDD-HH.md and snapshot the byte total')
    args = ap.parse_args()
    now = time.time()
    lines = ['# Audit digest, last %g h (%s)' % (args.hours, time.strftime('%Y-%m-%d %H:%M'))]

    measured = section_bytes(args.hours)
    if measured:
        total, previous, _ = measured
        if previous:
            gained = total - previous['total']
            hours = max((now - previous['t']) / 3600, 0.01)
            lines.append('bytes: %d exact total; %+d in %.1f h = %+d B/h (prove-log families, inactive exact, not integrated)' % (total, gained, hours, gained / hours))
        else:
            lines.append('bytes: %d exact total (first snapshot, no rate yet)' % total)
        if args.write:
            OUT.mkdir(exist_ok=True)
            with open(OUT / 'bytes-snapshots.jsonl', 'a') as f:
                f.write(json.dumps({'t': now, 'total': total}) + '\n')
    commits = git_commits(args.hours)
    lines.append('commits: %d in window%s' % (len(commits), ' (batch: aim for at most one per hour)' if len(commits) > 1 else ''))

    transcript = args.transcript or newest_transcript()
    if transcript:
        rows = events(transcript)
        spent, shapes, errors, count = section_time(rows, now - args.hours * 3600)
        lines.append('tool calls: %d; errored results: %d' % (count, errors))
        lines.append('time per tool (min): ' + ', '.join('%s %.1f' % (k, v / 60) for k, v in spent.most_common(6)))
        repeated = [(n, s) for s, n in shapes.most_common() if n >= 3][:8]
        lines.append('repeated command shapes (3+ runs = automation candidates):')
        lines += ['  %3dx  %s' % (n, s) for n, s in repeated] or ['  none']
    else:
        lines.append('no transcript found (pass --transcript FILE)')

    lines.append('tool health: ' + ' | '.join(tool_health()))
    text = '\n'.join(lines)
    print(text)
    if args.write:
        OUT.mkdir(exist_ok=True)
        (OUT / (time.strftime('%Y%m%d-%H') + '.digest.md')).write_text(text + '\n')


if __name__ == '__main__':
    main()
