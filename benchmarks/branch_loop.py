"""Continue prepared experiment branches once current writers finish; no cloud calls."""
import json
import subprocess
import sys
import time

import psutil

from benchmarks.library_branches import ROOT


def state(value):
    ROOT.mkdir(parents=True, exist_ok=True)
    (ROOT / "loop-state.json").write_text(json.dumps(value), encoding="utf-8")


def main():
    stages = ["late-spillover", "recipe-neighbor", "numeric-settings"]
    state(dict(state="waiting for current sweeps", next_stages=stages, cloud_cost=0))
    while any("benchmarks.library_branches" in (p.info.get("cmdline") or [])
              for p in psutil.process_iter(["cmdline"])):
        time.sleep(10)
    for i, stage in enumerate(stages):
        state(dict(state="pilot then conditional scale", stage=stage, next_stages=stages[i+1:], cloud_cost=0))
        with (ROOT / (stage + "-loop.log")).open("a", encoding="utf-8") as log:
            result = subprocess.run([sys.executable, "-X", "utf8", "-m", "benchmarks.library_branches",
                                     stage, "--pilot", "12", "--scale-if-wins"], stdout=log, stderr=log)
        if result.returncode:
            state(dict(state="stage failed; inspect log before resuming", stage=stage,
                       exit_code=result.returncode, next_stages=stages[i+1:], cloud_cost=0))
            return result.returncode
    state(dict(state="prepared branches exhausted; inspect outcomes for next hypotheses", cloud_cost=0))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
