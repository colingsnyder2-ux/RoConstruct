"""Recover field displacements from verified donor methods, with exact acceptance."""
import argparse
import json
import random
import re
from collections import defaultdict

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

from benchmarks.match_campaign import Campaign, digest
from roc import auto, draft, match


FIELD = re.compile(r"\[(eax|ebx|ecx|edx|esi|edi)(?: \+ (0x[0-9a-f]+|\d+))?\]")


def displacement_map(target, donor):
    """Require equal instruction shapes and a consistent offset correspondence."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    left, right = list(md.disasm_lite(target, 0)), list(md.disasm_lite(donor, 0))
    if len(left) != len(right):
        return {}
    mapping = {}
    for (_, _, mnemonic, operands), (_, _, old_mnemonic, old_operands) in zip(left, right):
        if mnemonic != old_mnemonic:
            return {}
        if mnemonic == "call" or mnemonic.startswith("j"):
            continue
        fields, old_fields = list(FIELD.finditer(operands)), list(FIELD.finditer(old_operands))
        if FIELD.sub("[field]", operands) != FIELD.sub("[field]", old_operands) or len(fields) != len(old_fields):
            return {}
        for new, old in zip(fields, old_fields):
            if new[1] != old[1]:
                return {}
            before, after = int(old[2] or "0", 0), int(new[2] or "0", 0)
            if before != after and max(before, after) >= 0x10000:
                return {}  # Absolute addresses are not class layout evidence.
            if before in mapping and mapping[before] != after:
                return {}
            mapping[before] = after
    return {old: new for old, new in mapping.items() if old != new}


def candidates(source, mapping):
    """Try explicit byte offsets and first padding arrays; never invent value layouts."""
    if not mapping:
        return []
    out = []
    candidate = re.sub(r"\b0x[0-9a-fA-F]+\b",
                       lambda m: hex(mapping.get(int(m[0], 16), int(m[0], 16))), source)
    if candidate != source:
        out.append(("explicit-offsets", candidate))
    # A uniform shift can be represented by expanding the leading class padding.
    deltas = {new - old for old, new in mapping.items()}
    if len(deltas) == 1:
        delta = deltas.pop()
        for pad in re.finditer(r"\b(?:char|unsigned char|BYTE)\s+\w+\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]", source):
            size = int(pad[1], 0) + delta
            if size > 0:
                candidate = source[:pad.start(1)] + str(size) + source[pad.end(1):]
                out.append(("padding-shift", candidate))
            if len(out) >= 8:
                break
    return out


def run(limit):
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    snapshots = campaign.snapshot()
    manifest = campaign.root / "class-layout-manifest.json"
    if not manifest.exists():
        eligible = []
        seen = set()
        for row in campaign.previous("propagation"):
            key = (row["client"], row["addr"], row["donor_client"], row["donor_addr"])
            if row["client"] not in snapshots or row["donor_client"] not in snapshots or key in seen:
                continue
            donor = snapshots[row["donor_client"]].get(row["donor_addr"], {})
            if 40 <= row.get("score", 0) < 100 and donor.get("source"):
                if not any(k in match.directives(donor["source"]) for k in ("lib", "archive")):
                    eligible.append({k: row[k] for k in ("client", "addr", "donor_client", "donor_addr", "family")})
                    seen.add(key)
        random.Random(20261010).shuffle(eligible)
        manifest.write_text(json.dumps(eligible, indent=1), encoding="utf-8")
    done = {(r["client"], r["addr"], r["donor_client"], r["donor_addr"]) for r in campaign.previous("class-layout")}
    evidence = defaultdict(list)
    for row in campaign.previous("class-layout"):
        if row.get("winner", {}).get("score") == 100:
            fields = row.get("accepted_mapping", row["mapping"])
            if all(max(int(k), v) < 0x10000 for k, v in fields.items()):
                evidence[(row["client"], row.get("unit"), row["donor_client"], row.get("donor_unit"))].append(fields)
    rows = json.loads(manifest.read_text(encoding="utf-8"))
    for row in rows[:limit]:
        client, addr = row["client"], row["addr"]
        donor_client, donor_addr = row["donor_client"], row["donor_addr"]
        if client not in snapshots or donor_client not in snapshots or (client, addr, donor_client, donor_addr) in done:
            continue
        record = {**row, "variants": []}
        try:
            target, _, function = match.target(client, addr)
            record["unit"] = function.get("unit")
            record["donor_unit"] = match.target(donor_client, donor_addr)[2].get("unit")
            evidence_key = (client, record["unit"], donor_client, record["donor_unit"])
            if campaign.current(client, addr)["score"] == 100:
                record["skip"] = "already exact on server"
            else:
                source = snapshots[donor_client][donor_addr]["source"]
                if match.check_text(donor_client, donor_addr, source)[0] != 100:
                    raise ValueError("Donor no longer verifies exact")
                directives = match.directives(source)
                body = draft.clean_repair_context(source)
                rewritten = auto.family_propagate(match.disasm(target, int(addr, 16)), body)
                source = "".join("// roc-%s: %s\n" % item for item in directives.items()) + (rewritten or body)
                before, symbol, _, _ = match.check_text(client, addr, source)
                record.update(before=before, source_sha256=digest(source))
                obj = match.compile_text(client, source)
                compiled = next(code for name, code, _ in match.coff_functions(obj) if name == symbol)
                mapping = displacement_map(target, compiled)
                record["mapping"] = mapping
                hypotheses = [("method-inferred", mapping)]
                hypotheses += [("verified-class-evidence", {int(k): v for k, v in other.items()})
                               for other in evidence[evidence_key] if not str(record["unit"]).startswith("seg_")]
                checked = set()
                for origin, fields in hypotheses:
                    for kind, candidate in candidates(source, fields):
                        sha = digest(candidate)
                        if sha in checked:
                            continue
                        checked.add(sha)
                        try:
                            score = match.check_text(client, addr, candidate)[0]
                            record["variants"].append(dict(kind=kind, origin=origin, score=score, sha256=sha))
                            path = campaign.root / "class-layout-trials" / client / (addr + "-" + sha[:12] + ".cpp")
                            path.parent.mkdir(parents=True, exist_ok=True)
                            path.write_text(candidate, encoding="utf-8")
                            if score == 100:
                                record["winner"] = campaign.submit_exact("class-layout", client, addr, candidate)
                                record["accepted_mapping"] = fields
                                evidence[evidence_key].append(fields)
                                break
                        except (RuntimeError, ValueError, OSError, SystemExit) as error:
                            record["variants"].append(dict(kind=kind, origin=origin, error=str(error)[-300:]))
                    if "winner" in record:
                        break
        except (RuntimeError, ValueError, OSError, SystemExit, StopIteration) as error:
            record["error"] = str(error)[-500:]
        campaign.record("class-layout", record)
        print(client, addr, record.get("mapping"), record.get("winner", {}).get("score"), flush=True)


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=160)
    run(ap.parse_args().limit)
