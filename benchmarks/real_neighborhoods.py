"""Real verified-callee context tests; linked-only scores never submit as matches."""
import json
import hashlib
import re
from pathlib import Path

import pefile

from benchmarks.match_campaign import Campaign, digest
from roc import clients, draft, ltcg, match


def adapt(caller, callee, call_name, addr):
    """Attach actual callee through a storage view; require its compiled bytes later."""
    definition = re.search(r"\b(\w+)::(\w+)\s*\(([^)]*)\)\s*\{", callee)
    declaration = re.search(r"\b(int|void|bool)\s+" + re.escape(call_name) + r"\s*\(([^)]*)\)\s*;", caller)
    caller_definition = re.search(r"\b(\w+)::\w+\s*\([^)]*\)\s*\{", caller)
    if not definition or not declaration or not caller_definition:
        raise ValueError("Unsupported recovered method declarations")
    params = [p.strip() for p in declaration[2].split(",") if p.strip() and p.strip() != "void"]
    params = [re.sub(r"\s+\w+$", "", p) if p not in ("unsigned int", "int", "void", "bool") else p for p in params]
    donor_params = [p.strip() for p in definition[3].split(",") if p.strip() and p.strip() != "void"]
    if len(params) != len(donor_params) or any(p not in ("int", "unsigned int", "void*", "int*") for p in params):
        raise ValueError("Caller/callee parameter mapping is ambiguous")
    header_end = caller.rfind("\n", 0, caller_definition.start()) + 1
    header = caller[:header_end]
    donor_class = "CampaignDonor_" + addr
    callee = re.sub(r"\b" + re.escape(definition[1]) + r"\b", donor_class, callee)
    signature = ", ".join("%s a%d" % (typ, i) for i, typ in enumerate(params))
    arguments = ", ".join("a%d" % i for i in range(len(params)))
    statement = ("return " if declaration[1] != "void" else "") + "((%s*)this)->%s(%s);" % (donor_class, definition[2], arguments)
    bridge = "%s %s::%s(%s) { %s }\n" % (
        declaration[1], caller_definition[1], call_name, signature, statement)
    return callee + "\n" + header + "\n" + bridge


def run():
    campaign = Campaign("work/match-campaign-20261010", "http://127.0.0.1:8765")
    candidates = json.loads((campaign.root / "neighborhood-pairs-candidates.json").read_text())
    snapshots = campaign.snapshot()
    done = {(r["client"], r["addr"]) for r in campaign.previous("neighborhoods")
            if r.get("adapter_version") == 2 or r.get("qualified")}
    complete = sum(r.get("qualified", False) for r in campaign.previous("neighborhoods"))
    for client, addr, callee_addr, call_name, *_ in sorted(candidates, key=lambda row: row[5]):
        if client not in campaign.info["clients"] or (client, addr) in done or complete >= 10:
            continue
        record = {"client": client, "addr": addr, "callee": callee_addr, "contexts": {}, "adapter_version": 2}
        folder = campaign.root / "neighborhoods" / (client + "-" + addr)
        folder.mkdir(parents=True, exist_ok=True)
        try:
            caller = draft.clean_repair_context(snapshots[client][addr]["source"])
            callee = draft.clean_repair_context(snapshots[client][callee_addr]["source"])
            record["baseline"], symbol, _, _ = match.check_text(client, addr, caller)
            record["callee_verified"] = match.check_text(client, callee_addr, callee)[0]
            if record["callee_verified"] != 100:
                raise ValueError("Callee is not independently exact")
            adapted = adapt(caller, callee, call_name, callee_addr)
            adapted_obj = match.compile_text(client, adapted)
            target_callee, callee_relocs, _ = match.target(client, callee_addr)
            bridge = [f for f in match.coff_functions(adapted_obj) if f[0].startswith("?" + call_name + "@")]
            if not any(match.exact_match(target_callee, callee_relocs, f[1], f[2]) and
                       not match.data_check(client, callee_addr, target_callee,
                                            match.coff_data_refs(adapted_obj, f[0]))[1] for f in bridge):
                raise ValueError("Storage-view bridge did not preserve actual callee bytes")
            record.update(qualified=True, caller_sha256=digest(caller), callee_sha256=digest(callee))
            complete += 1
            caller_file, callee_file = folder / "caller.cpp", folder / "callee.cpp"
            caller_file.write_text(caller, encoding="utf-8")
            callee_file.write_text(adapted, encoding="utf-8")
            # The adapter header duplicates caller declarations; remove that exact header for same-TU use.
            definition = re.search(r"\b(\w+)::\w+\s*\([^)]*\)\s*\{", caller)
            header_end = caller.rfind("\n", 0, definition.start()) + 1
            visible = caller + "\n" + adapted.replace(caller[:header_end], "", 1)
            visible_file = folder / "visible.cpp"
            visible_file.write_text(visible, encoding="utf-8")
            target, target_relocs, _ = match.target(client, addr)
            for mode in ("opaque", "visible", "ltcg"):
                result = {}
                try:
                    dll, map_path = folder / (mode + ".dll"), folder / (mode + ".map")
                    ltcg.build_dll(clients.load()[client]["compiler_build"],
                                  visible_file if mode == "visible" else caller_file, dll, map_path,
                                  force_unresolved=True, export_symbol=symbol,
                                  opaque_sources=[callee_file] if mode == "opaque" else [],
                                  extra_sources=[callee_file] if mode == "ltcg" else [],
                                  whole_program=mode == "ltcg", flags=("/O2", "/GS-", "/EHsc", "/MD"))
                    pe = pefile.PE(str(dll))
                    base = pe.OPTIONAL_HEADER.ImageBase
                    publics = ltcg.map_symbols(map_path, base)
                    rva = next(rva for rva, name in publics if name == symbol)
                    section = pe.get_section_by_rva(rva)
                    limit = min([pos for pos, _ in publics if rva < pos < section.VirtualAddress + section.Misc_VirtualSize]
                                or [section.VirtualAddress + section.Misc_VirtualSize]) - rva
                    raw = pe.get_data(rva, min(limit, 8192))
                    size = ltcg.reachable_size(raw, base + rva)
                    code = raw[:size]
                    relocations = {entry.rva - rva for block in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", [])
                                   for entry in block.entries if entry.type and rva <= entry.rva < rva + size}
                    result.update(rva=rva, size=size, code_sha256=hashlib.sha256(code).hexdigest(),
                                  diagnostic_code_score=match.score(target, target_relocs, code, relocations),
                                  linked_data_verified=False, unresolved_links=True)
                    (folder / (mode + ".bin")).write_bytes(code)
                    pe.close()
                    # Only normal object/source verification can promote a source here.
                    if mode == "visible":
                        result["normal_source_score"] = match.check_text(client, addr, visible)[0]
                        if result["normal_source_score"] == 100:
                            result["winner"] = campaign.submit_exact("neighborhoods", client, addr, visible)
                except (RuntimeError, ValueError, KeyError, StopIteration, OSError, SystemExit) as error:
                    result["error"] = str(error)[-1200:]
                record["contexts"][mode] = result
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            record["error"] = str(error)[-1200:]
        campaign.record("neighborhoods", record)
        print("neighborhood", addr, "qualified", record.get("qualified", False),
              {mode: row.get("diagnostic_code_score", "error") for mode, row in record["contexts"].items()}, flush=True)
    print("Qualified real pairs", complete, flush=True)


if __name__ == "__main__":
    run()
