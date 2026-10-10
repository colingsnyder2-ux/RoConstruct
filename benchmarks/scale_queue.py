"""Continue expanded sweeps after prior writers exit; preserve their existing logs."""
import argparse
import subprocess
import sys
import threading
import time
from pathlib import Path

import psutil


def queue(pid, commands, label):
    root = Path("work/match-campaign-20261010")
    root.mkdir(parents=True, exist_ok=True)
    try:
        process = psutil.Process(pid)
        while process.is_running():
            time.sleep(15)
    except psutil.NoSuchProcess:
        pass
    with (root / (label + "-queue.log")).open("a", encoding="utf-8") as log:
        for args in commands:
            print("starting", label, args, flush=True)
            result = subprocess.run([sys.executable, "-X", "utf8", "-m", *args], stdout=log, stderr=log)
            log.flush()
            if result.returncode:
                print(label, "failed", result.returncode, flush=True)
                break


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--prop-pid", type=int, required=True)
    ap.add_argument("--template-pid", type=int, required=True)
    args = ap.parse_args()
    propagation = threading.Thread(target=queue, args=(args.prop_pid, [
        ["benchmarks.match_campaign", "propagate", "--donor-limit", "0", "--server", "http://127.0.0.1:8765"],
        ["benchmarks.class_layout", "--refresh", "--limit", "10000000"]], "propagation"))
    templates = threading.Thread(target=queue, args=(args.template_pid, [
        ["benchmarks.match_campaign", "templates", "--template-limit", "10000000", "--all-template-builds",
         "--server", "http://127.0.0.1:8765"]], "templates"))
    propagation.start()
    templates.start()
    propagation.join()
    templates.join()
