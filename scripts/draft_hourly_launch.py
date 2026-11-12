"""Quiet scheduled entry point; capture startup/import failures before loading the runner."""
import argparse
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path
import runpy
import sys
import traceback

parser = argparse.ArgumentParser(add_help=False)
parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
args, _ = parser.parse_known_args()
root = args.root.resolve()
log = root / 'work/draft-merger/hourly/bootstrap.log'
log.parent.mkdir(parents=True, exist_ok=True)
with log.open('a', encoding='utf-8') as stream, redirect_stdout(stream), redirect_stderr(stream):
    sys.path.insert(0, str(root))
    try:
        runpy.run_module('roc.draft_hourly', run_name='__main__', alter_sys=True)
    except SystemExit:
        raise
    except BaseException:
        traceback.print_exc()
        raise SystemExit(1)
