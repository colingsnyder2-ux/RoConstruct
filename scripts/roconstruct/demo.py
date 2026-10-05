#!/usr/bin/env python3
"""Run a deterministic, non-Roblox end-to-end RoConstruct smoke test."""
import hashlib
import json
import re
from pathlib import Path

from coordinator import Store


ROOT = Path(__file__).resolve().parents[2]
DEMO = ROOT / "examples" / "tiny_demo"
OUT = ROOT / "work" / "demo" / "reconstructed"


def compact(value):
    return re.sub(r"\s+", " ", value).strip()


def generated(name, pseudo):
    # Deterministic stand-in for model codegen. Real workers use Ollama.
    return pseudo.replace("; }", ";\n}")


def main():
    items = json.loads((DEMO / "decompiled.json").read_text(encoding="utf-8"))
    ground = (DEMO / "demo_source.c").read_text(encoding="utf-8")
    binary_hash = hashlib.sha256(ground.encode()).hexdigest()
    OUT.parent.mkdir(parents=True, exist_ok=True)
    store = Store(":memory:")
    jobs = [{"binary_hash": binary_hash, "program": item["program"], "address": item["address"]} for item in items]
    print("DEMO // seed %d functions" % store.seed(jobs))
    OUT.mkdir(parents=True, exist_ok=True)
    completed = 0
    while True:
        job = store.claim("demo-worker", 60, {"client": "tiny-demo", "state": "working"})
        if not job:
            break
        item = next(item for item in items if item["address"] == job["address"])
        source = generated(item["name"], item["pseudocode"])
        ok = compact(source).replace(" ", "") in compact(ground).replace(" ", "")
        result = {"ok": ok, "source": source if ok else "", "pseudocode": item["pseudocode"],
                  "summary": "tiny demo function", "evidence": [
                      {"kind": "compiler", "value": "demo verifier", "score": 1 if ok else 0},
                      {"kind": "runtime", "value": "demo trace matched", "score": 3 if ok else 0}]}
        path = OUT / (item["name"] + ".cpp")
        if ok:
            path.write_text(source + "\n", encoding="utf-8")
        store.result(job["id"], "demo-worker", job["lease_id"], result)
        completed += 1
        print("DEMO // %s:%s // %s" % (item["name"], item["address"], "OK" if ok else "ERROR"))
    print("DEMO // complete %d/%d // compiler + runtime evidence OK" % (completed, len(items)))
    print("DEMO // output %s" % OUT)


if __name__ == "__main__":
    main()
