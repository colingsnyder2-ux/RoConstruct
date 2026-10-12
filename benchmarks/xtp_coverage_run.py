"""Resume exact XTP configuration pilots and transfer their winning sources."""
import argparse
import copy
import json
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from roc import fingerprint, libs, match, worker
from roc.cpu_jobs import check_many_text

ROOT = Path("work/xtp-2008-20261011")


def transfer_sources(campaign, plans, targets, done, stage="ob1-transfer"):
    groups = defaultdict(list)
    for client, source in plans:
        if digest(client + source) not in done:
            groups[source].append(client)

    def attempt(client, source, obj):
        isolated = copy.copy(campaign)
        isolated.api = worker.Api(campaign.api.server, campaign.api.token)
        row = dict(key=digest(client + source), client=client,
                   directives=match.directives(source), winners=[])
        try:
            found = targets[client].match_obj(obj, source)
            checked = check_many_text(client, list(found), source) if found else []
            batch = [addr for addr, score, spans in checked if score == 100]
            for offset in range(0, len(batch), 1000):
                addrs = batch[offset:offset + 1000]
                response = isolated.api.call("/v1/submit-batch", dict(
                    user=campaign.user, client=client, source=source, addrs=addrs,
                    model="roc " + stage), timeout=120)
                if not response.get("verified") or any(r["score"] != 100 for r in response["results"]):
                    raise ValueError("Server batch did not verify every exact")
                folder = campaign.root / "candidates" / stage / client
                folder.mkdir(parents=True, exist_ok=True)
                for result in response["results"]:
                    addr = result["addr"]
                    path = folder / (addr + ".cpp")
                    path.write_text(source)
                    row["winners"].append(dict(client=client, addr=addr, score=100,
                        symbol=found[addr][1], candidate_path=str(path), source_sha256=digest(source),
                        submission=dict(result, verified=True)))
            # The batch comparator ranks one class; retain other exact object symbols too.
            for addr in found.keys() - set(batch):
                winner = isolated.submit_exact(stage, client, addr, source)
                winner["symbol"] = found[addr][1]
                row["winners"].append(winner)
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            row["error"] = str(error)[-1000:]
        finally:
            isolated.api.close()
        return row

    # One source at a time: each mutable client target has exactly one owner.
    # Journal writes stay on the main thread; client verification may run in parallel.
    with ThreadPoolExecutor(max_workers=3) as pool:
        for source, clients in groups.items():
            try:
                obj = match.compile_text("2008-06", source)
                results = list(pool.map(lambda client: attempt(client, source, obj), clients))
            except match.CompileError as error:
                results = [dict(key=digest(client + source), client=client, directives=match.directives(source),
                                winners=[], error=str(error)[-1000:]) for client in clients]
            for row in results:
                campaign.record(stage, row)
                print(stage, row["client"], row["directives"].get("lib", "member"),
                      len(row["winners"]), row.get("error", "")[:120], flush=True)


def run(limit, transfer=False, strings=False, server="http://127.0.0.1:8765", internals=False,
        recipe=None, shard=None, tag="", only=None):
    campaign = Campaign(ROOT, server)
    stage = (recipe + "-files" + tag + ("-%d" % shard[0] if shard else "") if recipe else "ob1-transfer" if transfer else "private-string-files" if internals and strings
             else "private-files" if internals else "string-files" if strings else "ob1-files")
    previous = campaign.previous(stage)
    done = {r["key"] for r in previous if "error" not in r}
    if shard and not tag:
        done |= {r["key"] for r in campaign.previous(recipe + "-files") if "error" not in r}
    clients = list(campaign.info["clients"]) if transfer else ["2008-06"]
    targets, scores = {}, {}
    for client in clients:
        rows = campaign.api.call("/v1/sources?client=" + client, timeout=120)
        scores[client] = {r["addr"]: r["score"] for r in rows}
        target = fingerprint.Target(client)
        target.index = defaultdict(list)
        for addr, function in match._functions(client).items():
            if function.get("kind") == "code" and scores[client].get(addr, 0) < 100:
                if transfer or recipe or "CXTP" in function.get("unit", ""):
                    target.index[function["size"]].append(addr)
        targets[client] = target

    if transfer:
        sources = {}
        for pilot in ("ob1-pilot", "ob1-files", "string-pilot", "string-files", "abi-pilot", "private-pilot", "private-files", "private-string-files", "xtp-11.2.2-lib-files", "xtp-11.2.2-lib-files-0", "xtp-11.2.2-lib-files-1", "xtp-11.2.2-lib-files-2", "xtp-11.2.2-lib-strlen-files-0", "xtp-11.2.2-lib-strlen-files-1", "xtp-11.2.2-lib-strlen-files-2"):
            for row in campaign.previous(pilot):
                for winner in row.get("winners", [row]):
                    if winner.get("submission", {}).get("improved"):
                        source = Path(winner["candidate_path"]).read_text()
                        sources[digest(source)] = source
        plans = [(client, source) for source in sources.values() for client in clients]
    else:
        manifest = ROOT / "ob1-files-manifest.json"
        if manifest.exists():
            plans = [tuple(row) for row in json.loads(manifest.read_text())]
        else:
            snapshot = json.loads((ROOT / "sources-2008-06.json").read_text())
            support = Counter()
            for row in snapshot:
                if row["score"] < 100:
                    directive = match.directives(row.get("source", ""))
                    recipe, _, path = directive.get("lib", "").partition(" ")
                    if recipe.startswith("xtp-") and path:
                        support[path.replace("\\", "/")] += 1
            recipe = libs.RECIPES["xtp-11.2.2-shared-mfc"]
            folder = libs.fetch("xtp-11.2.2-shared-mfc")
            paths = sorted(libs.files_of(recipe, folder),
                           key=lambda p: (-support[p.replace("\\", "/")], p))
            # Explicit inlining fixes the observed runtime-class call difference.
            # Test EH/cookies both ways; no global compiler settings are changed.
            plans = []
            for path in paths:
                for flags in ("/O2 /MD /GS /EHsc /Ob1", "/O2 /MD /GS- /Ob1"):
                    source = ("// roc-lang: cpp\n// roc-cl: 21022\n"
                              "// roc-flags: " + flags + "\n"
                              "// roc-lib: xtp-11.2.2-shared-mfc " + path + "\n")
                    plans.append(("2008-06", source))
            manifest.write_text(json.dumps(plans))

    if transfer:
        transfer_sources(campaign, plans[:limit] if limit else plans, targets, done)
        return
    if recipe:
        # /GS- never produced a 2008 exact (0 of 1,078 wins); skip it.
        plans = [(client, source.replace("xtp-11.2.2-shared-mfc ", recipe + " "))
                 for client, source in plans if "/GS-" not in source]
        if only:
            plans = [(c, s) for c, s in plans if match.directives(s)["lib"].split(" ", 1)[1].replace("\\", "/") in only]
        if shard:
            plans = plans[shard[0]::shard[1]]
    if internals and not transfer:
        paths = set(json.loads((ROOT / "private-paths.json").read_text()))
        plans = [(client, source.replace("xtp-11.2.2-shared-mfc ",
                                         "xtp-11.2.2-shared-mfc-internals "))
                 for client, source in plans
                 if match.directives(source)["lib"].partition(" ")[2] in paths]
    if strings and not transfer:
        plans = [(client, source.replace("xtp-11.2.2-shared-mfc ",
                                         "xtp-11.2.2-shared-mfc-string-calls "))
                 for client, source in plans]
        if internals:
            plans = [(client, source.replace("xtp-11.2.2-shared-mfc-internals ",
                                             "xtp-11.2.2-shared-mfc-internals-string-calls "))
                     for client, source in plans]
    for client, source in plans[:limit] if limit else plans:
        key = digest(client + source)
        if key in done:
            continue
        row = dict(key=key, client=client, directives=match.directives(source), winners=[])
        try:
            obj = match.compile_text("2008-06" if transfer else client, source)
            found = targets[client].match_obj(obj, source)
            if not transfer and not internals and not recipe and found:
                baseline = (source.replace("xtp-11.2.2-shared-mfc-string-calls ",
                                           "xtp-11.2.2-shared-mfc ") if strings
                            else source.replace(" /Ob1", ""))
                base = fingerprint.Target(client)
                base.index = defaultdict(list)
                for addr in found:
                    base.index[match._functions(client)[addr]["size"]].append(addr)
                baseline_found = base.match_obj(match.compile_text(client, baseline), baseline)
                row["baseline_matches"] = list(baseline_found)
                row["variant_only"] = [addr for addr in found if addr not in baseline_found]
            for addr in found:
                winner = campaign.submit_exact(stage, client, addr, source)
                winner["symbol"] = found[addr][1]
                row["winners"].append(winner)
                if winner.get("already_exact") or winner.get("submission", {}).get("score") == 100:
                    scores[client][addr] = 100
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            row["error"] = str(error)[-1000:]
        campaign.record(stage, row)
        print(stage, client, row["directives"].get("lib", "reconstructed member"), len(row["winners"]),
              row.get("error", "")[:120], flush=True)

    winners = {(w["client"], w["addr"]) for row in campaign.previous(stage)
               for w in row.get("winners", []) if w.get("submission", {}).get("improved")}
    print("TOTAL", stage, len(winners), flush=True)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=24, help="0 checks all frozen plans")
    parser.add_argument("--transfer", action="store_true")
    parser.add_argument("--strings", action="store_true")
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    parser.add_argument("--internals", action="store_true")
    parser.add_argument("--recipe", help="replay every file with this libs.RECIPES entry")
    parser.add_argument("--shard", help="i/n: this process takes every n-th plan from i")
    parser.add_argument("--tag", default="", help="stage suffix, e.g. after re-analysis")
    parser.add_argument("--only", help="JSON list of library paths to replay")
    args = parser.parse_args()
    shard = tuple(map(int, args.shard.split("/"))) if args.shard else None
    only = set(json.loads(Path(args.only).read_text())) if args.only else None
    run(args.limit, args.transfer, args.strings, args.server, args.internals, args.recipe, shard,
        args.tag, only)
