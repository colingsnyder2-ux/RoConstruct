"""Compile current native sources into fresh objects (parallel cl workers).

Usage: native_fresh_objects.py --output DIR [--jobs 8] SOURCE...
Writes DIR/<stem>/candidate.obj with the checker's own flags (plus fallback
include dirs).  Prints failures.  No source edits.
"""
import argparse
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[1]))
sys.path.insert(0, str(HERE))
import native_template_probe as probe  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--jobs', type=int, default=8)
    args = ap.parse_args()
    check = probe.runner()

    def one(source):
        source = source.resolve()
        out = args.output.resolve() / source.stem
        code, log, seconds = probe.compile_tu(probe.flags_for(check, source, out), source, out)
        return source.name, code, seconds

    with ThreadPoolExecutor(args.jobs) as pool:
        for name, code, seconds in pool.map(one, args.sources):
            print(name, 'ok' if not code else 'FAILED', seconds, flush=True)


if __name__ == '__main__':
    main()
