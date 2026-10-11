"""Caller-aware DeepSeek pilot: attach exact caller source clues to structured repair."""
import argparse
import json
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest, family_index
from benchmarks.ai_representatives_v3 import Budget
from roc import clients, draft, match


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    budget = Budget(campaign.root / "ai-budget.json")
    snapshots, indexes = campaign.snapshot(), family_index(campaign)
    rows = []
    for client, index in indexes.items():
        if client == "2009-12":
            continue
        for addr, family in index.items():
            if snapshots[client].get(addr, {}).get("score", 0) < 100 and 32 <= match._functions(client)[addr]["size"] <= 512:
                rows.append(dict(client=client, addr=addr, family=family))
    done = {r["family"] for r in campaign.previous("ai-representatives-v5")}
    options = dict(allow_cloud=True, budget=budget, max_tokens=2048, thinking="disabled", retries=0, retry_forever=False,
                   timeout=90, family_exemplars=True)
    for row in rows[:limit]:
        if row["family"] in done:
            continue
        record = {**row, "rounds": []}
        try:
            client, addr = row["client"], row["addr"]
            code, relocs, target = match.target(client, addr)
            facts = draft.facts_from_asm(match.disasm(code, int(addr, 16)))
            facts.update(draft.target_data_facts(client, code, relocs))
            caller_hints = []
            for caller in (target.get("callers") or [])[:3]:
                source = snapshots[client].get(caller, {}).get("source")
                if snapshots[client].get(caller, {}).get("score") == 100 and source:
                    caller_hints.append(dict(path="verified caller " + caller, text=source))
            score, source, _ = draft.llm_rounds_k(client, addr, "deepseek:deepseek-flash", 2, None, (None, 0), print,
                clients.load()[client].get("flags"), source_hints=caller_hints, facts=facts, stats=record["rounds"],
                strategy="structured", provider_options=options)
            record.update(score=score, caller_count=len(caller_hints))
            if source:
                path = campaign.root / "ai-trials-v5" / client / (addr + ".cpp")
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(source, encoding="utf-8")
                record.update(source_sha256=digest(source), source_path=str(path))
            if score == 100:
                record["winner"] = campaign.submit_exact("ai-representatives-v5", client, addr, source)
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            record["error"] = str(error)[-500:]
        record["budget"] = dict(cost=budget.cost, requests=budget.requests)
        campaign.record("ai-representatives-v5", record)
        print("AI V5", client, addr, record.get("score"), record.get("caller_count"), flush=True)
        if budget.requests >= 2000 or budget.cost >= 4.50:
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=12)
    run(parser.parse_args().limit)
