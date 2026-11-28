"""Prove staged header ports object-neutral, then keep them in rebuild/2008-06/native-headers.

1. Dependents: native sources whose last compile read one of the staged donor headers.
2. Baseline: compile them as they are now (runner cache makes this cheap when nothing changed).
3. Install the staged headers at the native-headers root, compile the dependents again.
4. Compare each pair with tu_signature (code, data, relocations, symbols). Any changed object is listed with
   the staged headers it reads; with --keep the headers stay installed only when nothing changed.

    python work/donorfree-route/header_port_proof.py [--keep]
Diagnostic proof only: no link, client run, gate or server credit.
"""
import json, os, re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'work/native-client/layout'))
from coff_compare import parse, tu_signature   # noqa: E402

BASE = ROOT / 'rebuild/2008-06'
HERE = Path(__file__).parent
BATCH = next((a.split('=',1)[1] for a in sys.argv if a.startswith('--batch=')), '')
STAGE = HERE / ('header-port' + ('-' + BATCH if BATCH else ''))
NH = BASE / 'native-headers'
RUNNER = BASE / 'tests/native_check_runner.py'
staged = [h for h, _, _ in json.loads((HERE / ('header_port%s_staged.json' % BATCH)).read_text())]
pattern = re.compile(r'tools/rbxgs/Client/(?:App|Network|RbxGraphics|RbxView|Rendering/RenderLib)/include/(.*)$', re.I)


def run(sources, tag, parts=2):
    """Compile in `parts` runner processes at once (each runner allows at most 8 workers)."""
    from concurrent.futures import ThreadPoolExecutor
    chunks = [sources[i::parts] for i in range(parts) if sources[i::parts]]
    if not chunks:
        return {}
    with ThreadPoolExecutor(len(chunks)) as pool:
        results = list(pool.map(lambda nc: run_one(nc[1], '%s-%d' % (tag, nc[0])), enumerate(chunks)))
    return {k: v for r in results for k, v in r.items()}


def run_one(sources, tag):
    manifest = HERE / ('proof-%s.json' % tag)
    manifest.write_text(json.dumps({'compiler_build': 21022, 'jobs': [
        {'source': os.path.relpath(s, BASE).replace('\\', '/')} for s in sources]}))
    env = {k: v for k, v in os.environ.items() if k != 'NATIVE_FLAGS'}
    p = subprocess.run([sys.executable, str(RUNNER), 'run', str(manifest), '--workers', '8'], cwd=ROOT, env=env,
                       capture_output=True, text=True)
    rows = json.loads(Path(json.loads(p.stdout.strip().splitlines()[-1])['results']).read_text())
    rows = rows if isinstance(rows, list) else rows['results']
    return {str(Path(r['source']).resolve()).casefold(): r for r in rows}


def preprocess(sources, jobs=16):
    """{source: sha256 of `cl /EP` output} with each source's own runner flags; None when preprocessing fails.
    Identical preprocessed text before and after a header port proves the object unchanged without compiling."""
    import hashlib, importlib.util
    from concurrent.futures import ThreadPoolExecutor
    sys.path.insert(0, str(ROOT))
    from roc import rebuild
    spec = importlib.util.spec_from_file_location('ncr', RUNNER)
    ncr = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ncr)
    tc = rebuild.toolchain(21022)

    def one(src):
        flags = [f for f in ncr.compiler_flags(Path(src)) if f != '/c']
        env = rebuild.env(tc)
        done = subprocess.run([str(tc['cl'])] + flags + ['/EP', '/nologo', str(src)], cwd=BASE, env=env,
                              capture_output=True)
        return src, hashlib.sha256(done.stdout).hexdigest() if done.returncode == 0 and done.stdout else None
    with ThreadPoolExecutor(jobs) as pool:
        return dict(pool.map(one, sources))


def main():
    keep = '--keep' in sys.argv
    log = (BASE / 'out/donorfree/runner-all-native.log').read_text().strip().splitlines()[-1]
    rows = json.loads(Path(json.loads(log)['results']).read_text())
    rows = rows if isinstance(rows, list) else rows['results']
    wanted = {h.casefold() for h in staged}
    uses = {}
    for r in rows:
        hits = {m.group(1) for d in r.get('dependencies') or [] for m in [pattern.search(d.replace(os.sep, '/'))]
                if m and m.group(1).casefold() in wanted}
        if hits:
            uses[str(Path(r['source']).resolve())] = sorted(hits)
    sources = sorted(uses)
    print('dependents', len(sources), flush=True)
    fast = '--fast' in sys.argv
    if fast:   # preprocess-equivalence: compile only sources whose preprocessed text changes
        pre_before = preprocess(sources)
        for h in staged:
            (NH / h).parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(STAGE / h, NH / h)
        pre_after = preprocess(sources)
        for h in staged:
            (NH / h).unlink()
        same_text = [s for s in sources if pre_before[s] and pre_before[s] == pre_after[s]]
        print('preprocess-identical %d of %d; compiling the rest' % (len(same_text), len(sources)), flush=True)
        _st = set(same_text)
        sources = [s for s in sources if s not in _st]
    else:
        same_text = []
    # Baseline: today's all-native objects (same headers before the port); compile only sources without one.
    before = {str(Path(r['source']).resolve()).casefold(): r for r in rows if r['status'] == 'complete'}
    missing = [s for s in sources if s.casefold() not in before]
    before.update(run(missing, 'before') if missing else {})
    clash = [h for h in staged if (NH / h).exists()]
    if clash:
        raise SystemExit('native-headers already has: %s' % clash)
    for h in staged:
        (NH / h).parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(STAGE / h, NH / h)
    try:
        after = run(sources, 'after')
    finally:
        pass
    same, changed, unproven = list(same_text), [], []
    for s in sources:
        b, a = before.get(s.casefold()), after.get(s.casefold())
        if not (b and a and b['status'] == 'complete' and a['status'] == 'complete'):
            unproven.append({'source': s, 'before': b and b['status'], 'after': a and a['status'],
                             'error': (a or {}).get('error', '')[:200]})
        elif tu_signature(parse(b["object"])) == tu_signature(parse(a["object"])):
            same.append(s)
        else:
            changed.append({'source': s, 'headers': uses[s]})
    if changed:   # recheck against a fresh baseline: other workers may have edited headers since the all-native run
        for h in staged:
            (NH / h).unlink()
        fresh = run([c['source'] for c in changed], 'recheck')
        for h in staged:
            shutil.copyfile(STAGE / h, NH / h)
        still = []
        for c in changed:
            f, a = fresh.get(c['source'].casefold()), after.get(c['source'].casefold())
            if not (f and f['status'] == 'complete' and
                    tu_signature(parse(f['object'])) == tu_signature(parse(a['object']))):
                still.append(c)
            else:
                same.append(c['source'])
        changed = still
    ok = not changed and not [u for u in unproven if u['before'] == 'complete']
    if not (keep and ok):
        for h in staged:
            (NH / h).unlink()
    report = {'headers': staged, 'dependents': len(sources) + len(same_text), 'preprocess_identical': len(same_text), 'identical': len(same), 'changed': changed,
              'unproven': unproven, 'kept': keep and ok,
              'scope': 'object-identity proof of header ports; no link, runtime, gate or server credit'}
    (HERE / ('header_port%s_proof.json' % BATCH)).write_text(json.dumps(report, indent=1))
    print(json.dumps({k: (len(v) if isinstance(v, list) else v) for k, v in report.items() if k != 'scope'}, indent=1))


if __name__ == '__main__':
    main()
