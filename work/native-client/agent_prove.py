"""One command, one screen: prove a native source and say what happened to each target address.
Replaces the hand-written manifest.json walks + obj diffs that cost class agents ~8 tool calls per session.

  python work/native-client/agent_prove.py FILE.cpp ADDR[=NAME] [ADDR[=NAME] ...]
  python work/native-client/agent_prove.py --batch FILE1.cpp:ADDR[=NAME][,ADDR...] FILE2.cpp:ADDR ...   (one process, sequential)

Per address: EXACT | REJECTED (byte-equal, with the identity/reference reason) | DIFF (closest emitted symbol +
assembly diff) | COMPILE FAILED (first errors).  NAME is a substring of the function name when it is not sub_<addr>.
Also usable as a module: verdict(file, {addr: needle}) -> {addr: (status, text)}."""
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
PY = sys.executable
MAX_DIFF = 70


def run(argv, timeout=900):
    done = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True, encoding='utf-8', errors='replace', timeout=timeout)
    return (done.stdout or '') + (done.stderr or '')


def compile_errors(out_dir, prove_text):
    logs = sorted(out_dir.rglob('compile.log'), key=lambda p: p.stat().st_mtime) if out_dir.is_dir() else []
    text = (logs[-1].read_text(errors='replace') if logs else '') + '\n' + prove_text
    errs = [re.sub(r'^.*?([\w.]+\(\d+\)) ?: ', r'\1: ', line.strip())[:220] for line in text.splitlines()
            if re.search(r'\berror [A-Z]+\d+', line)]
    return list(dict.fromkeys(errs))[:12]


def verdict(source, targets):
    """targets: {addr: needle or ''}.  Runs the per-source proof (no shared registration, no census)."""
    from roc import match
    source = Path(source)
    stem = source.stem
    out_dir = HERE / 'prove-out' / ('prove-' + stem)
    before = (out_dir / 'manifest.json').stat().st_mtime if (out_dir / 'manifest.json').is_file() else 0
    manifest = out_dir / 'manifest.json'
    (out_dir / 'run.lock').unlink(missing_ok=True)      # a killed earlier proof of this same file leaves its lock behind
    for attempt in range(4):
        text = run([PY, 'work/native-client/prove.py', str(source), '--rounds', '1', '--no-register'])
        # Another worker touched a header or class file during the compile: the prover refuses the result
        # ('inputs changed during compile; rerun').  That is not a compile error: prove again.
        try:
            blockers = json.loads(manifest.read_text(encoding='utf-8'))['families'][0].get('blockers') or []
        except (OSError, ValueError, KeyError, IndexError):
            blockers = []
        if not any('inputs changed' in str(b) for b in blockers):
            break
        # the prover caches that refusal per source and would replay it forever: drop this source's cache row
        try:
            import hashlib
            rel = Path(source).resolve().relative_to(ROOT).as_posix()
            (HERE / 'prove-cache' / (hashlib.sha1(rel.encode()).hexdigest()[:20] + '.json')).unlink(missing_ok=True)
        except (OSError, ValueError):
            pass
    else:
        return {addr: ('RETRY LATER', 'inputs kept changing during the proof (other workers editing headers); '
                       'nothing is wrong with the file yet') for addr in targets}
    result = {}
    if not manifest.is_file() or manifest.stat().st_mtime <= before:
        errs = compile_errors(out_dir, text)
        why = 'COMPILE FAILED', '\n'.join(errs) if errs else text.strip()[-900:]
        return {addr: why for addr in targets}
    fam = json.loads(manifest.read_text(encoding='utf-8'))['families'][0]
    rows = fam.get('symbols') or []
    obj = next((j.get('object') for j in fam.get('jobs') or [] if j.get('object')), '')
    if not rows:
        errs = compile_errors(out_dir, text)
        return {addr: ('COMPILE FAILED', '\n'.join(errs) or text.strip()[-900:]) for addr in targets}
    for addr, needle in targets.items():
        hit = [r for r in rows if r.get('status') == 'inactive_exact' and r.get('addr') == addr]
        if hit:
            result[addr] = ('EXACT', hit[0]['symbol'])
            continue
        rej = [(r['symbol'], '; '.join(q.get('errors') or [])) for r in rows for q in r.get('rejections') or []
               if q.get('addr') == addr]
        if rej:
            result[addr] = ('REJECTED', 'bytes are equal, identity/references are not proven:\n' +
                            '\n'.join('  %s\n    %s' % (s[:150], e[:400]) for s, e in rej[:3]))
            continue
        size = len(match.target('2008-06', addr)[0])
        needle = needle or ('sub_' + addr)
        named = [r for r in rows if needle.lower() in r['symbol'].lower()]
        pick = sorted(named or rows, key=lambda r: abs(r.get('size', 0) - size))[:1]
        if not pick:
            result[addr] = ('DIFF', 'no symbol emitted; define the function (name containing %s)' % needle)
            continue
        sym = pick[0]['symbol']
        diff = run([PY, 'roc.py', 'native-asm', '2008-06', addr, '--obj', obj, '--sym', sym], timeout=180).splitlines()
        note = '' if named else ' (no symbol contains "%s"; closest by size)' % needle
        result[addr] = ('DIFF', 'target %d bytes, candidate %s %d bytes%s\n%s' % (
            size, sym[:150], pick[0].get('size', 0), note, '\n'.join(line[:150] for line in diff[:MAX_DIFF])))
    return result


def main():
    if len(sys.argv) > 2 and sys.argv[1] == '--batch':
        for spec in sys.argv[2:]:
            path, _, addrs = spec.rpartition(':')
            if not path or not addrs:
                print('== %s BAD SPEC (want FILE:ADDR[,ADDR])' % spec)
                continue
            print('#### %s' % path, flush=True)
            try:
                res = verdict(path, dict((a.split('=', 1) + [''])[:2] for a in addrs.split(',')))
            except (Exception, SystemExit) as exc:     # one bad unit must not lose the rest of the batch
                print('== ERROR %s: %s' % (type(exc).__name__, str(exc)[:300]), flush=True)
                continue
            for addr, (status, text) in res.items():
                print('== %s %s\n%s' % (addr, status, text), flush=True)
        return
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    targets = dict((a.split('=', 1) + [''])[:2] for a in sys.argv[2:])
    for addr, (status, text) in verdict(sys.argv[1], targets).items():
        print('== %s %s\n%s' % (addr, status, text), flush=True)


if __name__ == '__main__':
    main()
