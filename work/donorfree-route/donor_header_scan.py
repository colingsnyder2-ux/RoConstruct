"""Which 2007 rbxgs donor Roblox headers do native sources still read? Preprocess-only (`cl /EP /showIncludes`).

    python work/donorfree-route/donor_header_scan.py   -> work/donorfree-route/donor_header_scan.json
Prints the donor headers by number of native sources that reach them (vendor trees excluded).
"""
import importlib.util, json, re, subprocess, sys
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BASE = ROOT / 'rebuild/2008-06'
sys.path.insert(0, str(ROOT))
from roc import rebuild   # noqa: E402

spec = importlib.util.spec_from_file_location('ncr', BASE / 'tests/native_check_runner.py')
ncr = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ncr)
tc = rebuild.toolchain(21022)
env = rebuild.env(tc)
DONOR = re.compile(r'tools[\\/]rbxgs[\\/]Client[\\/](?:App|Network|RbxGraphics|RbxView|Rendering[\\/]RenderLib)[\\/]include[\\/](.+)$', re.I)


def scan(src):
    flags = [f for f in ncr.compiler_flags(src) if f != '/c']
    done = subprocess.run([str(tc['cl'])] + flags + ['/EP', '/showIncludes', '/nologo', str(src)], cwd=BASE, env=env,
                          capture_output=True, text=True, errors='replace')
    hits = set()
    for line in done.stderr.splitlines():
        if line.startswith('Note: including file:'):
            m = DONOR.search(line.split(':', 2)[-1].strip())
            if m and 'raknet' not in m.group(1).lower():
                hits.add(m.group(1).replace('\\', '/'))
    return src.name, sorted(hits), done.returncode


def main():
    sources = sorted((BASE / 'native-classes').glob('*.cpp'))
    with ThreadPoolExecutor(16) as pool:
        rows = list(pool.map(scan, sources))
    use = Counter(h for _, hs, _ in rows for h in hs)
    users = sum(1 for _, hs, _ in rows if hs)
    out = {'sources': len(rows), 'sources_reading_donor_headers': users, 'failed_preprocess': sum(1 for r in rows if r[2]),
           'donor_headers': use.most_common(), 'per_source': {n: hs for n, hs, _ in rows if hs}}
    (Path(__file__).parent / 'donor_header_scan.json').write_text(json.dumps(out, indent=1))
    print('sources', len(rows), '| reading donor Roblox headers', users, '| distinct headers', len(use))
    for h, n in use.most_common(25):
        print('%5d %s' % (n, h))


if __name__ == '__main__':
    main()
