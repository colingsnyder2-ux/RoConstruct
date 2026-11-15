"""Which worker models answer at all, and how fast: one tiny prompt to every candidate in parallel.
  python work/native-client/native_llm_probe.py [MODEL ...]"""
import concurrent.futures
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_llm as n

PROMPT = 'Output exactly one ```cpp block defining `int Probe::ping() { return 1; }` and nothing else.'


def probe(model):
    started = time.time()
    try:
        code = n.ask(model, PROMPT, 'ping')
    except Exception as error:      # timeouts and CLI failures count as dead
        code = None
        n.TOOL.reply = str(error)[:80]
    return model, bool(code), round(time.time() - started, 1), (getattr(n.TOOL, 'reply', '') or '')[:60].replace('\n', ' ')


models = sys.argv[1:] or n.CLAUDE_MODELS + n.BEST_NIM + n.BEST_FREE
with concurrent.futures.ThreadPoolExecutor(len(models)) as pool:
    for model, ok, seconds, text in sorted(pool.map(probe, models), key=lambda r: (not r[1], r[2])):
        print('%-4s %6.1fs  %-48s %s' % ('OK' if ok else 'DEAD', seconds, model, '' if ok else text), flush=True)
