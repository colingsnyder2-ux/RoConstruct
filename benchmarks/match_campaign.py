"""Resumable, compiler-verified recovery campaign; no implicit model calls."""
import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path
from urllib.parse import quote

from roc import auto, clients, draft, families, libs, match, worker


def digest(source):
    return hashlib.sha256(source.encode("utf-8")).hexdigest()


class Campaign:
    def __init__(self, output, server=None):
        self.root = Path(output)
        self.root.mkdir(parents=True, exist_ok=True)
        settings = worker.load_settings()
        self.api = worker.Api(server or settings["server"], settings.get("token"))
        self.user = settings["user"]
        self.info = self.api.call("/v1/info")
        # 2009-12 is registered for provenance, excluded from this mining campaign.
        self.info["clients"].pop("2009-12", None)
        for client, remote in self.info["clients"].items():
            if clients.load().get(client, {}).get("sha256") != remote["sha256"]:
                raise ValueError("Client registry differs: " + client)

    def record(self, stage, row):
        with (self.root / (stage + ".jsonl")).open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(row) + "\n")

    def previous(self, stage):
        path = self.root / (stage + ".jsonl")
        return [json.loads(line) for line in path.read_text(encoding="utf-8").splitlines()] if path.exists() else []

    def current(self, client, addr):
        if client not in self.info["clients"]:
            raise ValueError("Client excluded from experiments: " + client)
        return self.api.call("/v1/source?client=%s&addr=%s" % (quote(client), addr))

    def submit_exact(self, stage, client, addr, source, flags=None):
        if client not in self.info["clients"]:
            raise ValueError("Client excluded from experiments: " + client)
        score, symbol, diff, spans = match.check_text(client, addr, source, flags)
        result = {"client": client, "addr": addr, "score": score,
                  "symbol": symbol, "source_sha256": digest(source)}
        if score != 100:
            result["diff"] = diff[:500]
            return result
        folder = self.root / "candidates" / stage / client
        folder.mkdir(parents=True, exist_ok=True)
        if flags and "flags" not in match.directives(source):
            source = "// roc-flags: %s\n%s" % (flags, source)
        path = folder / (addr + ".cpp")
        path.write_text(source, encoding="utf-8")
        result["candidate_path"] = str(path)
        result["source_sha256"] = digest(source)
        current = self.current(client, addr)
        result["server_before"] = current["score"]
        if current["score"] == 100:
            result["already_exact"] = True
            return result
        if client not in self.info["verify"]:
            result["not_submitted"] = "server cannot verify this client"
            return result
        response = self.api.call("/v1/submit", {
            "user": self.user, "client": client, "addr": addr, "score": 100,
            "source": source, "model": "roc " + stage}, timeout=120)
        result["submission"] = response
        if not response["verified"] or response["score"] != 100:
            raise ValueError("Server failed exact verification: %s %s" % (client, addr))
        return result

    def snapshot(self):
        out = {}
        for client in self.info["clients"]:
            path = self.root / ("sources-" + client + ".json")
            if not path.exists():
                rows = self.api.call("/v1/sources?client=" + client, timeout=120)
                path.write_text(json.dumps(rows), encoding="utf-8")
            out[client] = {r["addr"]: r for r in json.loads(path.read_text(encoding="utf-8"))}
        return out


def harvest(campaign):
    archive = Path("work/mass-search/refine-unsolved-final")
    rows = json.loads((archive / "report.json").read_text(encoding="utf-8"))
    done = {(r["client"], r["addr"]) for r in campaign.previous("harvest") if "error" not in r}
    for row in rows:
        if row["client"] not in campaign.info["clients"]:
            continue
        if (row["client"], row["addr"]) in done:
            continue
        try:
            path = archive / row["client"] / (row["addr"] + ".cpp")
            source = path.read_text(encoding="utf-8")
            if digest(source) != row["source_sha256"]:
                raise ValueError("Archived source hash mismatch")
            result = campaign.submit_exact("harvest", row["client"], row["addr"], source, row.get("compiler_flags"))
        except (OSError, ValueError, RuntimeError, SystemExit) as error:
            result = {"client": row["client"], "addr": row["addr"], "error": str(error)[-800:]}
        campaign.record("harvest", result)
        print(row["client"], row["addr"], result.get("score"),
              result.get("submission", {}).get("improved", False), flush=True)


def family_index(campaign):
    result = {}
    for client in campaign.info["clients"]:
        path = campaign.root / ("families-" + client + ".json")
        if not path.exists():
            rows = {}
            for addr, row in match._functions(client).items():
                if row.get("kind", "code") != "code":
                    continue
                code, _, _ = match.target(client, addr)
                rows[addr] = families.fingerprint(row, match.disasm(code, int(addr, 16)))
                if len(rows) % 10000 == 0:
                    print("index", client, len(rows), flush=True)
            path.write_text(json.dumps(rows), encoding="utf-8")
        result[client] = json.loads(path.read_text(encoding="utf-8"))
    return result


def propagate(campaign):
    snapshots = campaign.snapshot()
    indexes = family_index(campaign)
    donors, pending = defaultdict(list), []
    for client, rows in indexes.items():
        for addr, family in rows.items():
            saved = snapshots[client].get(addr, {})
            if saved.get("score") == 100 and saved.get("source"):
                donors[family].append((client, addr, saved["source"]))
            else:
                pending.append((client, addr, family))
    checked = set()
    for row in campaign.previous("propagation"):
        checked.add((row["client"], row["addr"], row["candidate_sha256"]))
    verified, attempted, wins = {}, 0, 0
    for depth in range(3):
        additions, remaining = [], []
        for client, addr, family in pending:
            code, relocs, _ = match.target(client, addr)
            asm = match.disasm(code, int(addr, 16))
            distinct = set()
            # Eight independent donor source forms per family/target/pass.
            choices = sorted(donors[family], key=lambda d: d[0] != client)
            won = False
            for donor_client, donor_addr, source in choices:
                directive = match.directives(source)
                if "lib" in directive or "archive" in directive:
                    candidate = source
                else:
                    body = draft.clean_repair_context(source)
                    rewritten = auto.family_propagate(asm, body)
                    if not rewritten:
                        donor_code, donor_relocs, _ = match.target(donor_client, donor_addr)
                        if not match.exact_match(code, relocs, donor_code, donor_relocs):
                            continue
                    candidate = "".join("// roc-%s: %s\n" % item for item in directive.items()) + (rewritten or body)
                key = digest(candidate)
                if key in distinct:
                    continue
                distinct.add(key)
                if len(distinct) > 8:
                    break
                if (client, addr, key) in checked:
                    continue
                donor_key = (donor_client, donor_addr, digest(source))
                try:
                    if donor_key not in verified:
                        verified[donor_key] = match.check_text(donor_client, donor_addr, source)[0] == 100
                    if not verified[donor_key]:
                        continue
                    record = campaign.submit_exact("propagation", client, addr, candidate)
                except (RuntimeError, ValueError, OSError, SystemExit) as error:
                    record = {"client": client, "addr": addr, "error": str(error)[-400:]}
                record.update(candidate_sha256=key, family=family, depth=depth + 1,
                              donor_client=donor_client, donor_addr=donor_addr)
                campaign.record("propagation", record)
                checked.add((client, addr, key))
                attempted += 1
                if record.get("score") == 100:
                    additions.append((family, (client, addr, candidate)))
                    won = True
                    wins += bool(record.get("submission", {}).get("improved"))
                    break
                if attempted % 250 == 0:
                    print("propagation", depth + 1, "checks", attempted, "new", wins, flush=True)
            if not won:
                remaining.append((client, addr, family))
        for family, donor in additions:
            donors[family].append(donor)
        pending = remaining
        print("pass", depth + 1, "exact", len(additions), "remaining", len(pending), flush=True)
        if not additions:
            break
    campaign.record("propagation-summary", {"attempts": attempted, "new_exact": wins,
                                              "unresolved": len(pending), "verified_donors": len(verified)})


def configuration(campaign):
    from benchmarks.shared_mfc_verify import verify
    snapshots = campaign.snapshot()
    manifest = campaign.root / "configuration-manifest.json"
    if not manifest.exists():
        groups, guards = defaultdict(list), defaultdict(list)
        for client, rows in snapshots.items():
            functions = match._functions(client)
            for addr, row in rows.items():
                unit = functions.get(addr, {}).get("unit", "")
                if row["score"] == 100:
                    guards[client, unit].append(row)
                d = match.directives(row["source"])
                recipe, _, path = d.get("lib", "").partition(" ")
                if recipe.startswith("xtp-") and "shared-mfc" not in recipe and unit.startswith("CXTP"):
                    if 50 <= row["score"] < 100:
                        groups[client, unit, recipe, path, int(d["cl"])].append(row)
        prior = {("2008-06", "CXTPReportControl"), ("2008-06", "CXTPPopupBar"),
                 ("2008-06", "CXTPPropertyGrid"), ("2008-06", "CXTPTabClientWnd"),
                 ("2008-06", "CXTPRibbonTheme"), ("2009-06", "CXTPPropExchangeXMLNode"),
                 ("2011-06", "CXTCaptionButton"), ("2012-06", "CXTPPropExchangeXMLNode")}
        planned, used_units = [], set()
        for key, rows in sorted(groups.items(), key=lambda item: -len(item[1])):
            client, unit, recipe, path, build = key
            if (client, unit) in prior or unit in used_units or len(rows) < 10 or len(guards[client, unit]) < 3:
                continue
            shared = recipe + "-shared-mfc"
            if shared not in libs.RECIPES:
                continue
            rows = sorted(rows, key=lambda row: digest(client + row["addr"]))[:30]
            train = min(10, len(rows) // 2)
            planned.append({"client": client, "unit": unit, "recipe": shared, "path": path,
                            "build": build, "rows": [dict(row, split="train" if i < train else "holdout")
                                                        for i, row in enumerate(rows)] +
                            [dict(row, split="guard") for row in guards[client, unit][:10]]})
            used_units.add(unit)
            if len(planned) == 6:
                break
        manifest.write_text(json.dumps(planned, indent=1), encoding="utf-8")
    done = {(r["client"], r["unit"], r["addr"]) for r in campaign.previous("configuration")}
    for group in json.loads(manifest.read_text(encoding="utf-8")):
        client = group["client"]
        variants = []
        for flags in ("/O2 /GS- /MD", "/O1 /GS- /MD"):
            source = libs.source_for(group["recipe"], group["path"], "cpp", group["build"], flags)
            try:
                variants.append((source, match.compile_text(client, source)))
            except (RuntimeError, ValueError, SystemExit) as error:
                campaign.record("configuration-errors", {"client": client, "unit": group["unit"],
                                "flags": flags, "error": str(error)[-800:]})
        for row in group["rows"]:
            addr = row["addr"]
            if (client, group["unit"], addr) in done:
                continue
            record = {"client": client, "unit": group["unit"], "addr": addr,
                      "split": row["split"], "stored": row["score"], "recipe": group["recipe"],
                      "baseline_sha256": digest(row["source"]), "variants": []}
            try:
                record["before"] = match.check_text(client, addr, row["source"])[0]
                code, relocs, _ = match.target(client, addr)
                for source, obj in variants:
                    result = verify(client, addr, code, relocs, obj)
                    result["source_sha256"] = digest(source)
                    record["variants"].append(result)
                    if result["score"] == 100 and record["before"] < 100:
                        record["winner"] = campaign.submit_exact("configuration", client, addr, source)
                        break
            except (RuntimeError, ValueError, SystemExit) as error:
                record["error"] = str(error)[-800:]
            campaign.record("configuration", record)
        print("configuration", client, group["unit"], len(group["rows"]), "targets", flush=True)


def templates(campaign):
    from roc import fingerprint, template_recovery
    manifest = campaign.root / "templates-manifest.json"
    if not manifest.exists():
        inventory, supported = [], {}
        for client in campaign.info["clients"]:
            for row in template_recovery.inventory(client):
                row["client"] = client
                try:
                    source = template_recovery.instantiation(row["decoded"])
                    row["instantiation_sha256"] = digest(source)
                    if row["decoded"] not in supported:
                        supported[row["decoded"]] = {**row, "source": source}
                except (ValueError, KeyError) as error:
                    row["unsupported"] = str(error)
                inventory.append(row)
        (campaign.root / "templates-inventory.json").write_text(json.dumps(inventory, indent=1), encoding="utf-8")
        # Stable breadth: round-robin outer template names, not twenty versions of one type.
        by_kind = defaultdict(list)
        for row in supported.values():
            by_kind[row["decoded"].split("<", 1)[0]].append(row)
        chosen = []
        while by_kind and len(chosen) < 20:
            for kind in list(by_kind):
                chosen.append(by_kind[kind].pop(0))
                if not by_kind[kind]:
                    del by_kind[kind]
                if len(chosen) == 20:
                    break
        manifest.write_text(json.dumps(chosen, indent=1), encoding="utf-8")
    snapshots = campaign.snapshot()
    targets = {}
    for client in campaign.info["clients"]:
        target = fingerprint.Target(client)
        target.index = {size: [a for a in addrs if snapshots[client].get(a, {}).get("score") != 100]
                        for size, addrs in target.index.items()}
        targets[client] = target
    done = {r["variant"] for r in campaign.previous("templates")}
    for row in json.loads(manifest.read_text(encoding="utf-8")):
        for version in ("1_34_1", "1_40_0", "1_44_0", "1_47_0"):
            for policy in ("default", "release-iterators"):
                recipe = "templates-boost-" + version
                body = row["source"]
                if policy == "release-iterators":
                    body = "#define _SECURE_SCL 0\n#define _HAS_ITERATOR_DEBUGGING 0\n" + body
                filename = "client-rtti-" + digest(body)[:20] + ".cpp"
                variant = recipe + "/" + filename
                if variant in done:
                    continue
                folder = libs.fetch(recipe)
                (folder / filename).write_text(body, encoding="utf-8")
                build = clients.load()[row["client"]]["compiler_build"]
                source = libs.source_for(recipe, filename, "cpp", build, "/O2 /GS- /EHsc /MD")
                record = {"variant": variant, "client_rtti": row["client"], "raw": row["raw"],
                          "decoded": row["decoded"], "policy": policy, "build": build,
                          "source": source, "generated_sha256": digest(body), "exact": []}
                try:
                    obj = match.compile_text(row["client"], source)
                    record["object_sha256"] = hashlib.sha256(obj).hexdigest()
                    record["emitted_functions"] = len(match.coff_functions(obj))
                    for client, target in targets.items():
                        for addr in target.match_obj(obj, source):
                            result = campaign.submit_exact("templates", client, addr, source)
                            record["exact"].append(result)
                except (RuntimeError, ValueError, SystemExit) as error:
                    record["error"] = str(error)[-1200:]
                campaign.record("templates", record)
                print("template", row["decoded"][:65], version, policy,
                      "error" if "error" in record else len(record["exact"]), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("stage", choices=["harvest", "snapshot", "propagate", "configuration", "templates"])
    parser.add_argument("--output", default="work/match-campaign-20261010")
    parser.add_argument("--server")
    args = parser.parse_args()
    campaign = Campaign(args.output, args.server)
    if args.stage == "harvest":
        harvest(campaign)
    elif args.stage == "propagate":
        propagate(campaign)
    elif args.stage == "configuration":
        configuration(campaign)
    elif args.stage == "templates":
        templates(campaign)
    else:
        print({c: len(rows) for c, rows in campaign.snapshot().items()})


if __name__ == "__main__":
    main()
