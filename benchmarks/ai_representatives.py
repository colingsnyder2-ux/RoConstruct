"""Uncovered-family AI pilot, persistent peak-price budget, exact-only submissions."""
import argparse
import json
from collections import defaultdict

from benchmarks.match_campaign import Campaign, digest, family_index
from roc import clients, draft, match, providers


class PersistentBudget(providers.CloudBudget):
    def __init__(self, path):
        super().__init__(requests=200, cost=1.80)
        self.path = path
        if path.exists():
            saved = json.loads(path.read_text(encoding="utf-8"))
            self.requests, self.tokens, self.cost = saved["requests"], saved["tokens"], saved["cost"]

    def save(self):
        temp = self.path.with_suffix(".tmp")
        temp.write_text(json.dumps(dict(requests=self.requests, tokens=self.tokens,
                                        cost=self.cost, cap=self.max_cost)), encoding="utf-8")
        temp.replace(self.path)

    def reserve(self, estimate_tokens=0, estimate_cost=0.0):
        ticket = super().reserve(estimate_tokens, estimate_cost)
        self.save()  # Crash leaves reservation charged, never resets the cap.
        return ticket

    def settle(self, ticket, tokens=0, cost=None):
        if cost is None or (tokens == 0 and cost == 0):
            return  # Missing usage retains the full reservation.
        super().settle(ticket, tokens, cost)
        self.save()


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    model = "deepseek:deepseek-flash"
    provider, remote, config = providers.parse_model(model)
    if config["base_url"].rstrip("/") != "https://api.deepseek.com":
        raise ValueError("Budget supports official DeepSeek endpoint only")
    if not providers.available(model):
        raise ValueError("DeepSeek key unavailable; no requests made")
    # Verified official peak rates, 2026-10-10. Cache/off-peak discounts ignored.
    prices = providers._pricing(config, remote)
    if not prices or prices["input_per_million"] < 0.30 or prices["output_per_million"] < 1.20:
        raise ValueError("Configure peak pricing >= $0.30 input/$1.20 output per million")
    budget = PersistentBudget(campaign.root / "ai-budget.json")
    snapshots, indexes = campaign.snapshot(), family_index(campaign)
    groups = defaultdict(list)
    exact_families = set()
    for client, index in indexes.items():
        for addr, family in index.items():
            if snapshots[client].get(addr, {}).get("score") == 100:
                exact_families.add(family)
            else:
                groups[family].append((client, addr))
    manifest = campaign.root / "ai-representatives-v2-manifest.json"
    if not manifest.exists():
        planned = []
        for family, members in sorted(groups.items(), key=lambda item: (-len(item[1]), item[0])):
            if family in exact_families or len(members) < 3:
                continue
            choices = [(client, addr) for client, addr in members
                       if 32 <= match._functions(client)[addr]["size"] <= 512]
            if choices:
                client, addr = max(choices, key=lambda item: snapshots[item[0]].get(item[1], {}).get("score", 0))
                planned.append(dict(client=client, addr=addr, family=family, members=members))
        manifest.write_text(json.dumps(planned, indent=1), encoding="utf-8")
    done = {r["family"] for r in campaign.previous("ai-representatives")}
    options = dict(allow_cloud=True, budget=budget, max_tokens=2048, thinking="disabled",
                   retries=0, retry_forever=False, timeout=90)
    for row in json.loads(manifest.read_text(encoding="utf-8"))[:limit]:
        if row["family"] in done or row["client"] not in indexes:
            continue
        record = {**row, "rounds": [], "siblings": []}
        client, addr = row["client"], row["addr"]
        try:
            if campaign.current(client, addr)["score"] == 100:
                record["skip"] = "already exact"
            else:
                code, relocs, target = match.target(client, addr)
                asm = match.disasm(code, int(addr, 16))
                facts = draft.facts_from_asm(asm)
                facts.update(draft.target_data_facts(client, code, relocs))
                score, source = draft.llm_rounds(client, addr, model, 2, None, (None, 0),
                    print, clients.load()[client].get("flags"), facts=facts,
                    stats=record["rounds"], provider_options=options)
                record["score"] = score
                if source:
                    path = campaign.root / "ai-trials" / client / (addr + ".cpp")
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(source, encoding="utf-8")
                    record.update(source_sha256=digest(source), source_path=str(path))
                if score == 100:
                    record["winner"] = campaign.submit_exact("ai-representatives", client, addr, source)
                    for sibling_client, sibling_addr in row["members"]:
                        if (sibling_client, sibling_addr) == (client, addr) or sibling_client not in indexes:
                            continue
                        from roc import auto
                        sibling_code, _, _ = match.target(sibling_client, sibling_addr)
                        candidate = auto.family_propagate(match.disasm(sibling_code, int(sibling_addr, 16)), source) or source
                        try:
                            record["siblings"].append(campaign.submit_exact("ai-family", sibling_client, sibling_addr, candidate))
                        except (RuntimeError, ValueError, OSError, SystemExit) as error:
                            record["siblings"].append(dict(client=sibling_client, addr=sibling_addr, error=str(error)[-300:]))
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            record["error"] = str(error)[-500:]
        record["budget"] = dict(cost=budget.cost, requests=budget.requests)
        campaign.record("ai-representatives", record)
        print("AI FAMILY", client, addr, record.get("score"), "cost", budget.cost, flush=True)
        if budget.requests >= 200 or budget.cost >= 1.80:
            break


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=12)
    run(ap.parse_args().limit)
