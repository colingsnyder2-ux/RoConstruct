"""Bounded 2008-06 library repairs; no guessed layouts or matching-rule changes."""
import argparse
import ctypes
import json
import re
from collections import Counter, defaultdict
from pathlib import Path
from capstone import CS_ARCH_X86, CS_MODE_32, Cs

from benchmarks.data_recovery import string_candidate
from benchmarks.match_campaign import Campaign, digest
from roc import libraries, libs, match

CLIENT = "2008-06"
ROOT = Path("work/library-fill-20261011")


def assert_lines(code, relocs, candidate, candidate_relocs, lines):
    if len(code) != len(candidate):
        return None
    masked = set()
    for offset in set(relocs) | set(candidate_relocs):
        masked.update(range(offset, offset + 4))
    differences = {i for i, (a, b) in enumerate(zip(code, candidate)) if a != b and i not in masked}
    if not differences:
        return None
    changes = {}
    for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(candidate, 0):
        covered = set(range(instruction.address, instruction.address + instruction.size))
        if not differences.intersection(covered):
            continue
        if instruction.mnemonic != "push" or instruction.size not in (2, 5) or instruction.bytes[0] not in (0x68, 0x6a) \
                or code[instruction.address] != instruction.bytes[0]:
            return None
        offset = instruction.address + 1
        before = int.from_bytes(candidate[offset:offset+instruction.size-1], "little", signed=True)
        after = int.from_bytes(code[offset:offset+instruction.size-1], "little", signed=True)
        if not 0 < before <= len(lines) or not 0 < after <= 10000 or \
                not any(word in lines[before-1] for word in ("assert", "Assert")):
            return None
        if before in changes and changes[before] != after:
            return None
        changes[before] = after
        differences -= covered
    return changes if not differences and changes else None


def trial(campaign, stage, addr, source, evidence):
    row = dict(addr=addr, source=source, evidence=evidence, source_sha256=digest(source))
    try:
        score, symbol, diff, spans = match.check_text(CLIENT, addr, source)
        row.update(score=score, symbol=symbol, diff=diff)
        path = campaign.root / "candidates" / stage / (addr + "-" + digest(source)[:16] + ".cpp")
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(source)
        row["candidate_path"] = str(path)
        recipe, _, relative = match.directives(source).get("lib", "").partition(" ")
        if recipe:
            vendor = (libs.fetch(recipe) / relative).read_bytes()
            snapshot = path.with_suffix(".vendor.cpp")
            snapshot.write_bytes(vendor)
            row["vendor_snapshot"] = str(snapshot)
        current = campaign.current(CLIENT, addr)
        row["server_before"] = current["score"]
        if score > current["score"]:
            row["submission"] = campaign.api.call("/v1/submit", dict(
                user=campaign.user, client=CLIENT, addr=addr, score=score, source=source,
                model="roc " + stage), timeout=120)
        else:
            row["reason"] = "local candidate does not beat current server score"
    except (RuntimeError, ValueError, OSError, SystemExit) as error:
        row["error"] = str(error)[-2000:]
    campaign.record(stage, row)
    print(stage, addr, row.get("score"), row.get("submission", {}).get("improved", False), flush=True)
    return row


def repair99(campaign, limit):
    rows = campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300)
    done = {row["addr"] for row in campaign.previous("diagnostic99") if "error" not in row}
    for row in [r for r in rows if r["score"] == 99 and r.get("source")][:limit]:
        addr, source = row["addr"], row["source"]
        if addr in done:
            continue
        result = dict(addr=addr, source=source, server_before=row["score"], changes=[])
        try:
            code, relocs, _ = match.target(CLIENT, addr)
            obj = match.compile_text(CLIENT, source)
            exact = [f for f in match.coff_functions(obj) if match.exact_match(code, relocs, f[1], f[2])]
            if not exact:
                result["reason"] = "99% body differs; literal-data repair not applicable"
                result["score"], result["symbol"], result["diff"], _ = match.check_text(CLIENT, addr, source)
            else:
                selected, _, bad = match.select_exact_data(CLIENT, addr, code, obj, exact)
                result.update(score=99 if bad else 100, symbol=selected[0], data_errors=bad)
                directive = match.directives(source)
                recipe, _, relative = directive.get("lib", "").partition(" ")
                path = libs.fetch(recipe) / relative if recipe else None
                original = path.read_text(errors="replace") if path else source
                candidate = original
                filename = None
                base, image = match._image(CLIENT)
                for offset, data, inner in match.coff_data_refs(obj, selected[0]):
                    if inner or offset < 0 or offset + 4 > len(code) or not data.endswith(b"\0"):
                        continue
                    va = int.from_bytes(code[offset:offset + 4], "little") - base
                    if not 0 <= va < len(image):
                        continue
                    tail = bytes(image[va:va + 8192]); end = tail.find(b"\0")
                    if end < 0:
                        continue
                    expected = tail[:end + 1]
                    if data == expected or any(b < 32 or b > 126 for b in data[:-1] + expected[:-1]):
                        continue
                    replaced = string_candidate(candidate, data, expected)
                    if replaced:
                        candidate = replaced
                        result["changes"].append(dict(before=data.decode(), after=expected.decode(), kind="literal"))
                    elif path and data[:-1].decode().replace("\\", "/").split("/")[-1] == path.name and \
                            expected[:-1].decode().replace("\\", "/").split("/")[-1] == path.name:
                        filename = expected[:-1].decode()
                        result["changes"].append(dict(before=data.decode(), after=expected.decode(), kind="__FILE__"))
                if candidate != original or filename:
                    if path:
                        candidate = "#line 1 " + json.dumps(filename or str(path.resolve())) + "\n" + candidate
                        copy = path.with_name("roc_data_" + digest(candidate)[:16] + path.suffix)
                        if copy.exists() and copy.read_text() != candidate:
                            raise ValueError("Generated copy conflict")
                        copy.write_text(candidate)
                        result["vendor_copy"] = str(copy)
                        result["vendor_copy_sha256"] = digest(candidate)
                        candidate = libs.source_for(recipe, str(copy.relative_to(libs.fetch(recipe))),
                            directive.get("lang", "cpp"), int(directive["cl"]), directive["flags"])
                    result["trial"] = trial(campaign, "data99-repair", addr, candidate, result["changes"])
                elif not bad:
                    result["trial"] = trial(campaign, "data99-refresh", addr, source, "fresh comparator now exact")
                else:
                    result["reason"] = "mismatch not a directly recoverable source literal/main-file path"
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            result["error"] = str(error)[-2000:]
        campaign.record("diagnostic99", result)
        print("99 diagnostic", addr, result.get("score"), result.get("reason", ""), flush=True)


def units(campaign, limit):
    rows = {r["addr"]: r for r in campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300)}
    grouped = defaultdict(list)
    for addr, function in match._functions(CLIENT).items():
        if function.get("kind") == "code" and libraries.library_of(function["unit"]) in \
                {"XTP (Codejock)", "MFC", "Scintilla", "Ogre", "G3D", "RakNet", "ATL"}:
            grouped[function["unit"]].append(addr)
    ranked = []
    for name, addresses in grouped.items():
        missing = [addr for addr in addresses if rows.get(addr, {}).get("score", 0) < 100]
        if len(addresses) >= 5 and 0 < len(missing) <= 3:
            fraction = 1 - len(missing) / len(addresses)
            if fraction >= .9:
                ranked.append((fraction, name, addresses, missing))
    previous = {(r["addr"], r["source_sha256"]) for r in campaign.previous("unit-pilot")}
    for fraction, name, addresses, missing in sorted(ranked, reverse=True)[:limit]:
        donors = Counter(rows[a]["source"] for a in addresses if rows.get(a, {}).get("score") == 100
                         and "lib" in match.directives(rows[a].get("source") or ""))
        campaign.record("unit-manifest", dict(unit=name, fraction=fraction, targets=missing,
                                               donors=[digest(s) for s, _ in donors.most_common(3)]))
        for addr in missing:
            for source, frequency in donors.most_common(3):
                if (addr, digest(source)) in previous:
                    continue
                result = trial(campaign, "unit-pilot", addr, source,
                               dict(unit=name, exact_siblings=len(addresses)-len(missing), donor_frequency=frequency))
                if result.get("submission", {}).get("verified") and result["submission"].get("score") == 100:
                    break


def line_repair(campaign, limit):
    rows = campaign.api.call("/v1/sources?client=" + CLIENT, timeout=300)
    done = {r["addr"] for r in campaign.previous("assert-lines") if r.get("comparison") == "same-size"}
    pending = [r for r in rows if 95 <= r["score"] < 100 and r.get("source")]
    pending.sort(key=lambda r: ("g3d" not in r["source"].lower(), r["addr"]))
    for row in pending[:limit]:
        addr, source = row["addr"], row["source"]
        if addr in done:
            continue
        result = dict(addr=addr, source=source, server_before=row["score"], comparison="same-size")
        try:
            directive = match.directives(source)
            recipe, _, relative = directive.get("lib", "").partition(" ")
            if not recipe:
                result["reason"] = "not a vendor source reference"
            else:
                path = libs.fetch(recipe) / relative
                lines = path.read_text(errors="replace").splitlines()
                code, relocs, _ = match.target(CLIENT, addr)
                obj = match.compile_text(CLIENT, source)
                eligible = [f for f in match.coff_functions(obj) if len(f[1]) == len(code)]
                function = max(eligible, key=lambda f: match.rank_candidate(code, relocs, f[1], f[2])) if eligible else None
                corrections = assert_lines(code, relocs, function[1], function[2], lines) if function else None
                if corrections:
                    filename = str(path.resolve())
                    base, image = match._image(CLIENT)
                    for offset, data, inner in match.coff_data_refs(obj, function[0]):
                        if inner or not 0 <= offset <= len(code)-4:
                            continue
                        va = int.from_bytes(code[offset:offset+4], "little") - base
                        if not 0 <= va < len(image):
                            continue
                        value = bytes(image[va:va+2048]).split(b"\0", 1)[0]
                        if value and all(32 <= b <= 126 for b in value) and \
                                value.decode().replace("\\", "/").split("/")[-1] == path.name:
                            filename = value.decode()
                            break
                    text = "#line 1 " + json.dumps(filename) + "\n"
                    for number, line in enumerate(lines, 1):
                        if number in corrections:
                            text += "#line %d\n" % corrections[number]
                        text += line + "\n"
                        if number in corrections:
                            text += "#line %d\n" % (number + 1)
                    copy = path.with_name("roc_line_" + digest(text)[:16] + path.suffix)
                    if copy.exists() and copy.read_text() != text:
                        raise ValueError("Generated copy conflict")
                    copy.write_text(text)
                    candidate = libs.source_for(recipe, str(copy.relative_to(libs.fetch(recipe))),
                        directive.get("lang", "cpp"), int(directive["cl"]), directive["flags"])
                    result.update(corrections=corrections, vendor_copy=str(copy), vendor_copy_sha256=digest(text))
                    result["trial"] = trial(campaign, "assert-line-repair", addr, candidate, corrections)
                else:
                    result["reason"] = "body differences not exclusively observed assertion-line pushes in source file"
        except (RuntimeError, ValueError, OSError, SystemExit) as error:
            result["error"] = str(error)[-2000:]
        campaign.record("assert-lines", result)
        print("assert-lines", addr, result.get("corrections"), flush=True)


def mfc_core_sources():
    # stdafx.h explicitly selects AFX_CORE_DATA declarations with _AFX_CORE_IMPL.
    for recipe in ("mfc-9.0-shared-rtm", "mfc-9.0-shared"):
        folder = libs.fetch(recipe)
        for file in ("wincore.cpp", "appcore.cpp", "viewcore.cpp"):
            original = folder / "atlmfc/src/mfc" / file
            wrapper = original.with_name("roc_core_" + file)
            source = '#define _AFX_CORE_IMPL\n#include "' + file + '"\n'
            if wrapper.exists() and wrapper.read_text() != source:
                raise ValueError("Core wrapper conflict")
            wrapper.write_text(source)
            for flags in ("/O2 /GS- /EHsc /MD", "/O1 /GS- /EHsc /MD"):
                yield libs.source_for(recipe, str(wrapper.relative_to(folder)), "cpp", 21022, flags), \
                    dict(recipe=recipe, file=file, evidence="vendor stdafx.h _AFX_CORE_IMPL branch")


def real_header_templates():
    wanted = {
        "boost::any::holder<boost::shared_ptr<RBX::Instance> >",
        "boost::any::holder<RBX::Reflection::PropertyDescriptor const *>",
        "boost::any::holder<boost::function<void (boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const *),std::allocator<void> > >",
    }
    buffer = ctypes.create_string_buffer(16384)
    _, image = match._image(CLIENT)
    for hit in re.finditer(rb"\.\?A[VU][^\x00]{3,4000}\x00", bytes(image)):
        decorated = hit.group()[:-1]
        if not ctypes.windll.dbghelp.UnDecorateSymbolName(decorated[1:], buffer, len(buffer), 0x2000):
            continue
        name = re.sub(r"\b(class|struct|__cdecl)\s*", "", buffer.value.decode("ascii"))
        if name not in wanted:
            continue
        source = '''#include <boost/any.hpp>
#include <boost/function.hpp>
#include "v8tree/Instance.h"
#include "reflection/property.h"
template class ''' + name + ";\n"
        folder = libs.fetch("rbxgs-dll")
        file = "roc_real_template_" + digest(source)[:16] + ".cpp"
        path = folder / file
        if path.exists() and path.read_text() != source:
            raise ValueError("Real-header template conflict")
        path.write_text(source)
        evidence = dict(type=name, rtti=decorated.decode(), image_offset=hit.start(),
                        source=source, path=str(path), headers="genuine RBXGS Instance/Property definitions")
        for flags in ("/O2 /GS- /EHsc /MD", "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"):
            yield libs.source_for("rbxgs-dll", file, "cpp", 21022, flags), evidence


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("stage", choices=("data99", "units", "lines", "mfc-core", "real-templates"))
    parser.add_argument("--limit", type=int, default=10)
    parser.add_argument("--server", default="http://127.0.0.1:8765")
    args = parser.parse_args()
    campaign = Campaign(ROOT, args.server)
    try:
        if args.stage in ("mfc-core", "real-templates"):
            from benchmarks.claude_continuation import run_sources
            sources = mfc_core_sources() if args.stage == "mfc-core" else real_header_templates()
            run_sources(campaign, args.stage, sources, 2)
        else:
            {"data99": repair99, "units": units, "lines": line_repair}[args.stage](campaign, args.limit)
    finally:
        campaign.api.close()
