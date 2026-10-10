"""Diversified DeepSeek family pilot: choose a different unresolved member per family."""
import argparse
import json
from collections import defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest, family_index
from roc import clients, draft, match, providers


class Budget(providers.CloudBudget):
    def __init__(self, path):
        super().__init__(requests=2000, cost=4.50)
        self.path = path
        if path.exists():
            saved = json.loads(path.read_text(encoding="utf-8"))
            self.requests, self.tokens, self.cost = saved["requests"], saved["tokens"], saved["cost"]

    def save(self):
        temp = self.path.with_suffix(".tmp")
        temp.write_text(json.dumps(dict(requests=self.requests, tokens=self.tokens, cost=self.cost, cap=self.max_cost)), encoding="utf-8")
        temp.replace(self.path)

    def reserve(self, estimate_tokens=0, estimate_cost=0.0):
        ticket = super().reserve(estimate_tokens, estimate_cost)
        self.save()
        return ticket

    def settle(self, ticket, tokens=0, cost=None):
        if cost is None or (tokens == 0 and cost == 0):
            return
        super().settle(ticket, tokens, cost)
        self.save()


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    model = "deepseek:deepseek-flash"
    provider, remote, config = providers.parse_model(model)
    if config["base_url"].rstrip("/") != "https://api.deepseek.com" or not providers.available(model):
        raise ValueError("official DeepSeek endpoint/key unavailable")
    budget = Budget(campaign.root / "ai-budget.json")
    snapshots, indexes = campaign.snapshot(), family_index(campaign)
    old = {}
    prior = campaign.root / "ai-representatives-v2-manifest.json"
    if prior.exists():
        for row in json.loads(prior.read_text(encoding="utf-8")):
            old[row["family"]] = (row["client"], row["addr"])
    groups = defaultdict(list)
    exact_families = set()
    for client, index in indexes.items():
        if client == "2009-12":
            continue
        for addr, family in index.items():
            if snapshots[client].get(addr, {}).get("score") == 100:
                exact_families.add(family)
            elif 32 <= match._functions(client)[addr]["size"] <= 512:
                groups[family].append((client, addr))
    manifest = campaign.root / "ai-representatives-v3-manifest.json"
    if not manifest.exists():
        planned = []
        for family, members in sorted(groups.items(), key=lambda item: (-len(item[1]), item[0])):
            if family in exact_families or len(members) < 3:
                continue
            candidates = [m for m in members if m != old.get(family)]
            if candidates:
                client, addr = max(candidates, key=lambda item: snapshots[item[0]].get(item[1], {}).get("score", 0))
                planned.append(dict(client=client, addr=addr, family=family, members=members))
        manifest.write_text(json.dumps(planned, indent=1), encoding="utf-8")
    done = {r["family"] for r in campaign.previous("ai-representatives-v3")}
    options = dict(allow_cloud=True, budget=budget, max_tokens=2048, thinking="disabled", retries=0, retry_forever=False, timeout=90)
    for row in json.loads(manifest.read_text(encoding="utf-8"))[:limit]:
        if row["family"] in done:
            continue
        record = {**row, "rounds": [], "siblings": []}
        try:
            if campaign.current(row["client"], row["addr"])["score"] == 100:
                record["skip"] = "already exact"
            else:
                code, relocs, _ = match.target(row["client"], row["addr"])
                facts = draft.facts_from_asm(match.disasm(code, int(row["addr"], 16)))
                facts.update(draft.target_data_facts(row["client"], code, relocs))
                score, source = draft.llm_rounds(row["client"], row["addr"], model, 2, None, (None, 0), print,
                    clients.load()[row["client"]].get("flags"), facts=facts, stats=record["rounds"], provider_options=options)
                record["score"] = score
                if source:
                    path = campaign.root / "ai-trials-v3" / row["client"] / (row["addr"] + ".cpp")
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(source, encoding="utf-8")
                    record.update(source_sha256=digest(source), source_path=str(path))
                if score == 100:
                    record["winner"] = campaign.submit_exact("ai-representatives-v3", row["client"], row["addr"], source)
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            record["error"] = str(error)[-500:]
        record["budget"] = dict(cost=budget.cost, requests=budget.requests)
        campaign.record("ai-representatives-v3", record)
        print("AI V3", row["client"], row["addr"], record.get("score"), "cost", budget.cost, flush=True)
        if budget.requests >= 2000 or budget.cost >= 4.50:
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=12)
    run(parser.parse_args().limit)
