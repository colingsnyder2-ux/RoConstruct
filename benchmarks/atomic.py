"""Validate MSVC atomic code generation, then measure refcount targets."""
import json
import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import benchmark, draft, match

source = '''extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
long f(volatile long* p) { return _InterlockedExchangeAdd(p, -1); }
'''
recovered = draft.extract_code("Generated source:\n" + source)
assert recovered and '_InterlockedExchangeAdd(volatile long*' in recovered
obj = match.compile_text("2007-08", recovered)
assert any(b"\xf0" in code and b"\x0f\xc1" in code
           for _, code, _ in match.coff_functions(obj)), "No lock xadd emitted"
print("Real compiler: lock xadd emitted", flush=True)
parser = argparse.ArgumentParser()
parser.add_argument("--session", default="atomic-guidance-20261008")
args = parser.parse_args()
corpus = [row for row in json.loads(benchmark.HIDDEN.read_text())
          if row["client"] == "2007-08" and row["addr"] in {"00402a20", "00402a60"}]
for repeat in range(2):
    benchmark.run_local(corpus, ["deepseek:deepseek-flash"], rounds=2,
                        session="%s-r%d" % (args.session, repeat + 1),
                        strategies=("direct",), provider_options={"allow_cloud": True,
                        "thinking": "disabled", "history_keep_last": 0})
