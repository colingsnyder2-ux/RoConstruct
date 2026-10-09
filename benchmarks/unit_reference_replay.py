"""Small paired test: direct prompt versus one verified same-unit exemplar."""
import argparse, json, random
from pathlib import Path
from roc import benchmark, clients, providers

ROOT = Path(__file__).resolve().parents[1]

def main():
    p = argparse.ArgumentParser()
    p.add_argument("--client", default="2007-08")
    p.add_argument("--unit", default="RakPeer")
    p.add_argument("--n", type=int, default=8)
    p.add_argument("--model", default="deepseek:deepseek-flash")
    p.add_argument("--rounds", type=int, default=2)
    p.add_argument("--seed", type=int, default=17)
    a = p.parse_args()
    work = ROOT / "work" / a.client
    scores = json.loads((work / "scores.json").read_text())
    rows = [json.loads(x) for x in (work / "functions.jsonl").read_text().splitlines()]
    rows = [r for r in rows if r.get("unit") == a.unit and r.get("kind", "code") == "code"]
    sources = {p.stem: p for p in (ROOT / "src" / a.client).glob("*.cpp")}
    verified = [r for r in rows if scores.get(r["addr"], 0) == 100 and r["addr"] in sources]
    targets = [r for r in rows if scores.get(r["addr"], 0) < 100 and r["addr"] not in sources]
    random.Random(a.seed).shuffle(verified); random.Random(a.seed).shuffle(targets)
    if not verified or not targets: raise SystemExit("no verified exemplar or unseen target")
    exemplar = sources[verified[0]["addr"]].read_text(errors="replace")
    corpus = [dict(r, client=a.client) for r in targets[:a.n]]
    examples = {(a.client, r["addr"]): (exemplar,) for r in corpus}
    opts = {"allow_cloud": providers.is_cloud(a.model), "max_tokens": 2048,
            "budget": providers.CloudBudget(None, None, None), "gate": providers.CloudGate(1),
            "thinking": "disabled"}
    prefix = "unit-replay-%s-%s" % (a.client, a.unit)
    benchmark.run_local(corpus, [a.model], rounds=a.rounds, session=prefix+"-direct",
                        strategies=("direct",), provider_options=opts)
    benchmark.run_local(corpus, [a.model], rounds=a.rounds, session=prefix+"-unit",
                        strategies=("direct",), provider_options=opts, family_examples=examples)
    print("targets=%d unit=%s exemplar=%s" % (len(corpus), a.unit, verified[0]["addr"]))

if __name__ == "__main__": main()
