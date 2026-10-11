"""Structured DeepSeek pilot using verified same-family source exemplars."""
import argparse
import json
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest, family_index
from benchmarks.ai_representatives_v3 import Budget
from roc import clients, draft, match


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    model = "deepseek:deepseek-flash"
    budget = Budget(campaign.root / "ai-budget.json")
    snapshots, indexes = campaign.snapshot(), family_index(campaign)
    manifest = campaign.root / "ai-representatives-v4-manifest.json"
    if not manifest.exists():
        rows = []
        for client, index in indexes.items():
            if client == "2009-12":
                continue
            for addr, family in index.items():
                row = snapshots[client].get(addr, {})
                if row.get("score", 0) < 100 and 32 <= match._functions(client)[addr]["size"] <= 512:
                    rows.append(dict(client=client, addr=addr, family=family))
        manifest.write_text(json.dumps(rows), encoding="utf-8")
    done = {r["family"] for r in campaign.previous("ai-representatives-v4")}
    options = dict(allow_cloud=True, budget=budget, max_tokens=2048, thinking="disabled", retries=0, retry_forever=False, timeout=90)
    for row in json.loads(manifest.read_text(encoding="utf-8"))[:limit]:
        if row["family"] in done:
            continue
        record = {**row, "rounds": []}
        try:
            client, addr = row["client"], row["addr"]
            code, relocs, _ = match.target(client, addr)
            facts = draft.facts_from_asm(match.disasm(code, int(addr, 16)))
            facts.update(draft.target_data_facts(client, code, relocs))
            examples = [snapshots[c][a]["source"] for c, index in indexes.items() for a, family in index.items()
                        if snapshots[c].get(a, {}).get("score") == 100 and family == row["family"]
                        and c != "2009-12" and snapshots[c].get(a, {}).get("source")][:2]
            options["family_exemplars"] = True
            score, source, topk = draft.llm_rounds_k(client, addr, model, 2, None, (None, 0), print,
                clients.load()[client].get("flags"), examples=examples, facts=facts, stats=record["rounds"],
                strategy="structured", provider_options=options)
            record.update(score=score, exemplar_count=len(examples))
            if source:
                path = campaign.root / "ai-trials-v4" / client / (addr + ".cpp")
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(source, encoding="utf-8")
                record.update(source_sha256=digest(source), source_path=str(path))
            if score == 100:
                record["winner"] = campaign.submit_exact("ai-representatives-v4", client, addr, source)
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            record["error"] = str(error)[-500:]
        record["budget"] = dict(cost=budget.cost, requests=budget.requests)
        campaign.record("ai-representatives-v4", record)
        print("AI V4", row["client"], row["addr"], record.get("score"), record.get("exemplar_count"), flush=True)
        if budget.requests >= 2000 or budget.cost >= 4.50:
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=12)
    run(parser.parse_args().limit)
