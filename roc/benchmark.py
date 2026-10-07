"""Deterministic local benchmark corpus and telemetry report."""
import hashlib
import json
from pathlib import Path

from roc import clients

ROOT = Path(__file__).resolve().parent.parent
CORPUS = ROOT / "work" / "benchmark-corpus.json"
HIDDEN = ROOT / "work" / "benchmark-hidden.json"


def build(limit=8):
    buckets = {}
    for client in sorted(clients.load()):
        path = ROOT / "work" / client / "functions.jsonl"
        if not path.exists():
            continue
        for line in path.read_text(errors="replace").splitlines():
            try:
                row = json.loads(line)
            except ValueError:
                continue
            if row.get("kind", "code") != "code":
                continue
            size = row.get("size", 0)
            bucket = "tiny" if size <= 48 else "medium" if size <= 128 else "large"
            key = (client, bucket)
            buckets.setdefault(key, []).append(row)
    out = []
    for (client, bucket), rows in sorted(buckets.items()):
        rows.sort(key=lambda r: hashlib.sha256((client + r["addr"]).encode()).hexdigest())
        for row in rows[:limit]:
            out.append({"client": client, "addr": row["addr"], "size": row["size"],
                        "unit": row.get("unit"), "bucket": bucket,
                        "source_present": not str(row.get("unit", "")).startswith("seg_")})
    CORPUS.parent.mkdir(parents=True, exist_ok=True)
    CORPUS.write_text(json.dumps(out, indent=1))
    return out


def load():
    try:
        return json.loads(CORPUS.read_text())
    except (OSError, ValueError):
        return []


def build_hidden(limit=8):
    """Sample locally solved functions while omitting their source/score metadata."""
    out = []
    for client in sorted(clients.load()):
        scores_path = ROOT / "work" / client / "scores.json"
        funcs_path = ROOT / "work" / client / "functions.jsonl"
        if not scores_path.exists() or not funcs_path.exists():
            continue
        scores = json.loads(scores_path.read_text())
        rows = {"tiny": [], "medium": [], "large": []}
        for line in funcs_path.read_text(errors="replace").splitlines():
            row = json.loads(line)
            if scores.get(row.get("addr")) != 100 or row.get("kind", "code") != "code":
                continue
            size = row.get("size", 0)
            bucket = "tiny" if size <= 48 else "medium" if size <= 128 else "large"
            rows[bucket].append(row)
        for bucket, bucket_rows in rows.items():
            for row in sorted(bucket_rows, key=lambda item: item["addr"])[:limit]:
                out.append({"client": client, "addr": row["addr"], "size": row["size"],
                            "unit": row.get("unit"), "bucket": bucket,
                            "source_present": not str(row.get("unit", "")).startswith("seg_")})
    HIDDEN.parent.mkdir(parents=True, exist_ok=True)
    HIDDEN.write_text(json.dumps(out, indent=1))
    return out


def run_local(corpus, models, rounds=1, log=print, resume=False):
    """Benchmark models locally without submitting or changing server state."""
    import time
    from roc import clients, draft, match, metrics, refsource
    session = "benchmark"
    done = set()
    if resume:
        try:
            for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
                row = json.loads(line)
                if row.get("session") == session and row.get("event") == "job":
                    done.add((row.get("client"), row.get("addr"), row.get("model")))
        except (OSError, ValueError):
            pass
    for target in corpus:
        client, addr = target["client"], target["addr"]
        code, relocs, row = match.target(client, addr)
        asm = match.disasm(code, int(addr, 16))
        facts = draft.facts_from_asm(asm)
        facts.update(draft.target_data_facts(client, code, relocs))
        for model in models:
            if (client, addr, model) in done:
                log("  skip %s %s (already measured)" % (model, addr))
                continue
            started = time.monotonic()
            stats = []
            try:
                score, _src = draft.llm_rounds(client, addr, model, rounds, None, (None, 0),
                                               log, clients.load()[client].get("flags"), (),
                                               refsource.prompt_hints(row.get("unit", ""), target_facts=facts),
                                               facts, stats)
                failure = None
            except Exception as error:
                score, failure = 0, str(error)[:300]
            metrics.record(session, event="job", client=client, addr=addr, unit=row.get("unit"),
                           model=model, size=row.get("size", 0), base_score=0, score=score,
                           score_gain=score, improved=score > 0, rounds=stats,
                           seconds=round(time.monotonic() - started, 2), failure=failure)
            log("  %s %s %d%% %.1fs" % (model, addr, score, time.monotonic() - started))
