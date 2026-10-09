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


def build_hidden(limit=8, persist=True):
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
    if persist:
        HIDDEN.parent.mkdir(parents=True, exist_ok=True)
        HIDDEN.write_text(json.dumps(out, indent=1))
    return out


def run_local(corpus, models, rounds=1, log=print, resume=False, session="benchmark", strategies=("direct",),
              provider_options=None, family_examples=None):
    """Benchmark configured models without submitting or changing server state.

    ``family_examples`` optionally maps ``(client, addr)`` to verified source
    exemplars for controlled sibling experiments; normal runs pass none.

    session isolates one measured run: pass a unique id per arm (e.g.
    "bench-<date>-<label>") so background worker jobs sharing the metrics
    file can never contaminate the comparison. Filter rows by session.
    """
    import time
    from roc import clients, draft, match, metrics, providers, refsource
    done = set()
    if resume:
        try:
            for line in metrics.PATH.read_text(encoding="utf-8").splitlines():
                row = json.loads(line)
                if row.get("session") == session and row.get("event") == "job":
                    done.add((row.get("client"), row.get("addr"), row.get("model"), row.get("strategy", "direct")))
        except (OSError, ValueError):
            pass
    for target in corpus:
        client, addr = target["client"], target["addr"]
        code, relocs, row = match.target(client, addr)
        asm = match.disasm(code, int(addr, 16))
        facts = draft.facts_from_asm(asm)
        facts.update(draft.target_data_facts(client, code, relocs))
        facts.update({k: row[k] for k in ("call_targets", "external_calls", "imports", "strings",
                                          "global_reads", "global_writes", "virtual_slots", "stack_args",
                                          "this_reads", "this_writes", "calling_convention", "branches",
                                          "constants") if row.get(k)})
        for model in models:
            for strategy in strategies:
                if (client, addr, model, strategy) in done:
                    log("  skip %s %s (already measured)" % (model, addr))
                    continue
                started = time.monotonic()
                stats = []
                try:
                    examples = (family_examples or {}).get((client, addr), ())
                    score, _src = draft.llm_rounds(client, addr, model, rounds, None, (None, 0),
                                                   log, clients.load()[client].get("flags"), examples,
                                                   refsource.prompt_hints(row.get("unit", ""), target_facts=facts, client=client),
                                                   facts, stats, strategy=strategy, provider_options=provider_options)
                    failure = None
                except Exception as error:
                    score, failure = 0, str(error)[:300]
                generated = [item for item in stats if isinstance(item.get("round"), int)]
                coded = [item for item in generated if item.get("code")]
                provider_row = next((item for item in reversed(generated) if item.get("provider")), {})
                _name, _remote, config = providers.parse_model(model)
                metrics.record(session, event="job", client=client, addr=addr, unit=row.get("unit"),
                               model=model, strategy=strategy, size=row.get("size", 0), base_score=0, score=score,
                               score_gain=score, improved=score > 0, rounds=stats,
                               seconds=round(time.monotonic() - started, 2), failure=failure,
                               compiler_flags=clients.load()[client].get("flags"),
                               provider=provider_row.get("provider", _name),
                               provider_model=provider_row.get("provider_model", _remote),
                               provider_endpoint_kind=config.get("kind", "ollama"),
                               seed=(provider_options or {}).get("seed"),
                               input_tokens=sum(item.get("input_tokens", 0) for item in generated),
                               output_tokens=sum(item.get("output_tokens", 0) for item in generated),
                               reasoning_tokens=sum(item.get("reasoning_tokens") or 0 for item in generated),
                               cached_tokens=sum(item.get("cached_tokens", 0) for item in generated),
                               generation_seconds=round(sum(item.get("generation_seconds", 0) for item in generated), 3),
                               compile_seconds=round(sum(item.get("compile_seconds", 0) for item in coded), 3),
                               compile_attempts=len(coded),
                               compile_ok=sum(not item.get("compile_error") for item in coded),
                               estimated_cost=metrics.known_generation_cost(generated))
                log("  %s/%s %s %d%% %.1fs" % (model, strategy, addr, score, time.monotonic() - started))
