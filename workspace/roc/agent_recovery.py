"""Single-function recovery: persistent shuffle queue, evidence, triage and receipts."""
import contextlib
import functools
import hashlib
import json
import re
import sqlite3
import statistics
import threading
import time
import uuid
from datetime import datetime, timezone
from pathlib import Path

from roc import match, research, worker

SESSION = threading.local()

PREAMBLE = """STYLE: terse technical fragments. One function per agent; no target discovery or subagents.
TRUTH: Only server verified=true, improved=true establishes a gain; score=100 establishes a new exact.
Instruction equality alone is insufficient: referenced data must match. Solved neighbours are read-only.
No inline assembly, byte blobs, patched bytes, guessed layouts, offsets or ABI declarations.
Never invent destructors or dead stores to manufacture EH state; prove the temporary type from native headers and callee RTTI.
Packet rtti_vtable_stores/callee_rtti_vtable_stores expose native type names beyond the first-eight callee preview; stores alone do not distinguish construction from destruction or prove a layout.
rtti_type_refs names relocated type descriptors (including dynamic-cast template types); these do not prove full layouts or return ABIs.
native_type_headers are candidate declarations, not layout proof; compare their real fields/bases/destructors with the native stores before choosing one.
origin=unit_hint is unverified inventory attribution, not RTTI. Stored library provenance also does not establish the target's identity.
Header excerpts are bounded; read the supplied genuine file path when a required declaration is truncated.
extent_review identifies an excluded normal frame exit; review the complete EH owner before claiming a whole-function match.
For library CRT import mismatches, inspect recipe _DLL preprocessing; final /MD cannot repair already-expanded declarations.
RECOVER: understand target behavior and ABI from asm/callers/strings/genuine headers -> draft C++ -> journaled check.
An empty func_ADDRESS definition is only a starter. State one supporting binary fact before the first edit.
Sources containing only // roc-lib directives are complete library wrappers, not empty implementations.
For those wrappers, read authentic_library.source_path before drafting; provenance still does not prove target identity.
Do not run baseline checks, compiler grids or near-match scans before drafting a useful implementation.
The wrapper has already applied project instructions. Do not reread CLAUDE.md, AGENT_GUIDE.md,
recipes, reports or logs. Read assigned source and initial_evidence_file together in one tool call.
Initial evidence retains target assembly, facts and native declarations. Read evidence_file neighbour instructions or sibling sources only when the current hypothesis needs them; do not read both packets in full.
Setup is done. The supplied packet and this preamble are authoritative for recovery.
Do not repeat pull/fetch/analyze/config or read whole logs.
Use agent-check after every experiment: it preserves the best source and journals failures too.
Triage: first useful check within 120 seconds. Missing critical evidence? Run supplied agent-block command,
name the missing declaration/ABI fact and the next concrete evidence needed, then stop.
After a check, continue within the function time budget; stop after three distinct losing hypotheses.
Vendor changes use libs.add_unit and libs.source_for; managed header copies use include_alias inside the TU.
Proven subobject offsets plus native types/prototypes permit typed receiver views, never guessed padding or virtual methods.
Unrelated header blocker? Extract minimal native declarations/types; never bypass private access or invent ABI.
Never edit files in tools/, recipes or infrastructure.
Wrapper submits improvements and tests unresolved same-shape siblings after verified wins; stay on your target.
Final report: verified receipts, blockers, next evidence. Add Improvements heading with evidence-backed suggestions.
"""


def draw(root, rows, limit, scope="", hold_seconds=7200):
    """Least-visited random draw, atomically reserved across local processes."""
    if not rows or limit <= 0:
        return []
    scope = hashlib.sha256(scope.encode()).hexdigest()
    path = root / "work/agent-memory/recovery-queue.sqlite"
    path.parent.mkdir(parents=True, exist_ok=True)
    now, owner = time.time(), uuid.uuid4().hex
    candidates = {(row["client"], row["addr"]): row for row in rows}
    with contextlib.closing(sqlite3.connect(path, timeout=30)) as db:
        db.execute("CREATE TABLE IF NOT EXISTS picks(scope TEXT, client TEXT, addr TEXT, revision TEXT, "
                   "visits INTEGER, owner TEXT, expires REAL, PRIMARY KEY(scope,client,addr))")
        db.execute("CREATE TEMP TABLE pool(client TEXT,addr TEXT,PRIMARY KEY(client,addr))")
        db.execute("BEGIN IMMEDIATE")
        for (client, addr), row in candidates.items():
            revision = row.get("evidence_hash") or research.digest(row.get("source") or "")
            db.execute("INSERT INTO pool VALUES(?,?)", (client, addr))
            db.execute("INSERT INTO picks VALUES(?,?,?,?,0,NULL,0) ON CONFLICT(scope,client,addr) DO UPDATE SET "
                       "visits=CASE WHEN revision=excluded.revision THEN visits ELSE 0 END, revision=excluded.revision",
                       (scope, client, addr, revision))
        # Visits are pick rounds: every eligible function gets a turn before a repeat.
        keys = db.execute("SELECT p.client,p.addr FROM picks p JOIN pool q USING(client,addr) "
                          "WHERE scope=? AND expires<=? ORDER BY visits,RANDOM() LIMIT ?",
                          (scope, now, limit)).fetchall()
        for client, addr in keys:
            db.execute("UPDATE picks SET visits=visits+1,owner=?,expires=? WHERE scope=? AND client=? AND addr=?",
                       (owner, now + hold_seconds, scope, client, addr))
        db.commit()
    return [dict(candidates[key], queue_owner=owner) for key in keys]


def release(root, row, scope=""):
    if not row.get("queue_owner"):
        return
    scope = hashlib.sha256(scope.encode()).hexdigest()
    with contextlib.closing(sqlite3.connect(root / "work/agent-memory/recovery-queue.sqlite", timeout=30)) as db:
        db.execute("UPDATE picks SET owner=NULL,expires=0 WHERE scope=? AND client=? AND addr=? AND owner=?",
                   (scope, row["client"], row["addr"], row["queue_owner"]))
        db.commit()


_TYPE_DECL = re.compile(r"\b(?:class|struct)\s+(?:(?:__declspec\([^()]*\)|_\w+|[A-Z_][A-Z_0-9]*)\s+)?"
                        r"([A-Za-z_]\w*)\s*(?::[^;{}]+)?\{")


@functools.lru_cache(maxsize=16)
def _type_header_index(directory, stamp):
    """Reuse the declaration index across packets; read chosen excerpts afresh."""
    index = {}
    for path in sorted([*directory.rglob("*.h"), *directory.rglob("*.hpp")]):
        text = path.read_text(encoding="utf-8", errors="replace")
        for name in dict.fromkeys(m.group(1) for m in _TYPE_DECL.finditer(text)):
            index.setdefault(name, []).append(path)
    return index


def native_type_headers(root, client, stores, limit=6, unit=None):
    """Bounded genuine declarations; distinguish RTTI from inventory hints."""
    if client != "2008-06":
        return []
    folders = {
        "RBX": ["tools/rbxgs/Client/App/include", "tools/openrbx/Client/App/include"],
        "Ogre": ["tools/libs/ogre-1.4.5/ogrenew/OgreMain/include"],
        "G3D": ["tools/rbxgs/Client/Rendering/g3d/include"],
    }
    identities = []
    for typename in dict.fromkeys(store.get("type", "") for store in stores):
        identity = re.fullmatch(r"\.\?A[VU]([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@", typename)
        if not identity:
            continue
        name, namespace = identity.groups()
        namespace = namespace.rstrip("@").split("@")[-1]
        identities.append((typename, name, namespace, "rtti"))
    identity = re.fullmatch(r"(RBX|Ogre|G3D)::([A-Za-z_]\w*)", unit or "")
    if identity:
        namespace, name = identity.groups()
        identities.append((unit, name, namespace, "unit_hint"))
    result, seen = [], set()
    for typename, name, namespace, origin in identities:
        for folder in folders.get(namespace, []):
            directory = root / folder
            if not directory.is_dir():
                continue
            filenames = [name + ".h", "Ogre" + name + ".h"] if namespace == "Ogre" else [name + ".h"]
            paths = _type_header_index(directory, directory.stat().st_mtime_ns).get(name, [])
            for path in sorted(paths, key=lambda path: (path.name not in filenames, str(path))):
                if path in seen:
                    continue
                text = path.read_text(encoding="utf-8", errors="replace")
                declaration = next((m for m in _TYPE_DECL.finditer(text) if m.group(1) == name), None)
                if not declaration:
                    continue
                seen.add(path)
                start = max(0, declaration.start() - 100)
                result.append(dict(type=typename, origin=origin, path=str(path), read_only=True, candidate_only=True,
                    excerpt=text[start:start + 2400], truncated=start > 0 or len(text) > start + 2400))
                if len(result) >= limit:
                    return result
    return result


def frame_exit_review(client, addr, code, functions):
    """Expose a framed prefix jumping into its excluded, parent-owned epilogue."""
    if not code.startswith(b"\x55"):
        return None
    start = int(addr, 16)
    md = match.Cs(match.CS_ARCH_X86, match.CS_MODE_32)
    instructions = list(md.disasm_lite(code, start))
    adjustment = 0
    if len(instructions) >= 3 and instructions[1][2] == "lea":
        frame = re.fullmatch(r"ebp, \[esp - (0x[0-9a-f]+|\d+)\]", instructions[1][3])
        if not frame:
            return None
        adjustment = int(frame[1], 0)
        if instructions[2][2:] != ("sub", "esp, " + hex(adjustment)):
            return None
    elif len(instructions) < 2 or instructions[1][2:] != ("mov", "ebp, esp"):
        return None
    if (len(instructions) < 3 or instructions[0][2:] != ("push", "ebp")
            or not any("fs:[0]" in op for _, _, _, op in instructions[:24])
            or any(m == "ret" for _, _, m, _ in instructions)):
        return None
    destinations = dict.fromkeys(int(op, 16) for _, _, m, op in instructions
                                if m.startswith("j") and op.startswith("0x")
                                and start + len(code) <= int(op, 16) < start + 32768)
    for destination in list(destinations)[:8]:
        owner = next((row for row in functions.values() if row.get("kind") == "eh"
                      and int(row["addr"], 16) <= destination < int(row["addr"], 16) + row["size"]), None)
        if not owner:
            continue
        base, image = match._image(client)
        tail = []
        for instruction in md.disasm_lite(image[destination-base:destination-base+96], destination):
            _, _, mnemonic, operands = instruction
            if (mnemonic.startswith(("j", "loop")) or mnemonic in ("int3", "hlt", "ud2")
                    or (mnemonic, operands) in (("push", "ebp"), ("mov", "ebp, esp"))):
                break
            tail.append(instruction)
            if mnemonic == "ret":
                break
        if (len(tail) < 3 or tail[-1][2] != "ret"
                or tail[-3][2:] != ("mov", "esp, ebp") or tail[-2][2:] != ("pop", "ebp")
                or adjustment and (len(tail) < 4 or tail[-4][2:] != ("add", "ebp, " + hex(adjustment)))
                or not any(m == "mov" and op.startswith("dword ptr fs:[0],") for _, _, m, op in tail)):
            continue
        return dict(candidate_only=True, recorded_size=len(code), normal_exit="%08x" % destination,
            exit_end="%08x" % (tail[-1][0] + tail[-1][1]), inventory_owner=owner["addr"],
            instructions=["%08x %s %s" % (a, m, op) for a, _, m, op in tail],
            reason="Recorded extent excludes a normal exit restoring this EBP/FS frame; review full EH ownership.")
    return None


def initial_evidence(evidence, full_path):
    """Keep one-screen proof; model triage must reach an experiment quickly."""
    facts = evidence.get("facts", {})
    result = dict(client=evidence.get("client"), addr=evidence.get("addr"),
        target_asm=evidence.get("target_asm", [])[:32],
        facts={key: facts[key] for key in ("calling_convention", "return_stack_bytes", "stack_args",
            "this_reads", "this_writes", "virtual_slots", "imports", "strings", "constants") if facts.get(key)},
        missing_evidence=evidence.get("missing_evidence", [])[:2],
        full_evidence_file=str(full_path),
        deferred_details="Open full packet only for a specific missing declaration or neighbour.")
    if evidence.get("extent_review"):
        review = evidence["extent_review"]
        result["extent_review"] = {key: review.get(key) for key in ("recorded_size", "normal_exit", "inventory_owner", "reason")}
    if evidence.get("native_type_headers"):
        result["native_type_headers"] = evidence["native_type_headers"][:1]
    return result


def packet(root, client, addr, source, row):
    """Actual target instructions and bounded neighbours; no invented declarations."""
    from roc import agent, libs, rtti
    code, relocs, target = match.target(client, addr)
    functions = match._functions(client)
    evidence = dict(client=client, addr=addr, source=source,
        source_hash=research.digest(source), target_asm=match.disasm(code, int(addr, 16)),
        facts=agent.function_evidence(target, functions), neighbours=[], siblings=[], authentic_headers=[])
    review = frame_exit_review(client, addr, code, functions)
    if review:
        evidence["extent_review"] = review
    evidence["rtti_vtable_stores"] = rtti.vtable_stores(client, addr, code, relocs)
    evidence["rtti_type_refs"] = rtti.function_refs(client, addr)[:16] if relocs else []
    evidence["callee_rtti_vtable_stores"] = []
    # A sorted first-eight callee preview often misses the allocating constructor.
    # Keep a separate bounded type index without expanding every callee's asm.
    for neighbour in target.get("call_targets", [])[:128]:
        item = functions.get(neighbour)
        if not item or item.get("kind", "code") != "code":
            continue
        body, relocations, _ = match.target(client, neighbour)
        stores = rtti.vtable_stores(client, neighbour, body, relocations)
        if stores:
            evidence["callee_rtti_vtable_stores"].append(dict(addr=neighbour, stores=stores))
        if len(evidence["callee_rtti_vtable_stores"]) == 8:
            break
    evidence["native_type_headers"] = native_type_headers(root, client,
        evidence["rtti_vtable_stores"] + evidence["rtti_type_refs"] + [store for callee in evidence["callee_rtti_vtable_stores"]
                                         for store in callee["stores"]], unit=target.get("unit"))
    for kind, limit in (("callers", 4), ("call_targets", 8)):
        for neighbour in target.get(kind, [])[:limit]:
            item = functions.get(neighbour)
            if not item or item.get("kind", "code") != "code":
                continue
            body, _, _ = match.target(client, neighbour)
            evidence["neighbours"].append(dict(relation=kind, addr=neighbour, unit=item.get("unit"),
                instructions=match.disasm(body, int(neighbour, 16))[:64],
                facts=agent.function_evidence(item, functions)))
    for donor in row.get("donors", [])[:3]:
        evidence["siblings"].append(dict(addr=donor["addr"], score=donor["score"],
            matched_read_only=donor["score"] == 100, source=donor.get("source", "")[:12000]))
    directive = match.directives(source).get("lib", "").split(maxsplit=1)
    if directive and directive[0] in libs.RECIPES:
        recipe = libs.RECIPES[directive[0]]
        folder = libs._case_path(libs.LIBS / recipe["src"]).resolve()
        evidence["authentic_library"] = dict(recipe=directive[0], source_root=str(folder),
            candidate_only=True,
            source_file=directive[1] if len(directive) > 1 else "", defines=recipe.get("defines", ""),
            preinclude=recipe.get("preinclude", []), include_dirs=recipe.get("include", []))
        headers = []
        source_file = folder / directive[1] if len(directive) > 1 else None
        evidence["authentic_library"]["source_path"] = (
            str(source_file.resolve()) if source_file and source_file.is_file() else None)
        include_dirs = [libs._case_path(libs.LIBS / include).resolve() for include in recipe.get("include", [])
                        if include != "WINSDK"]
        if source_file and source_file.is_file():
            for include in re.findall(r'^\s*#\s*include\s*"([^"\n]+\.(?:h|hpp))"',
                                      source_file.read_text(encoding="utf-8", errors="replace"), re.M | re.I):
                for directory in [source_file.parent, *include_dirs]:
                    header = libs._case_path(directory / include.replace("\\", "/"))
                    if header.is_file():
                        if header not in headers:
                            headers.append(header)
                        break
                if len(headers) >= 12:
                    break
        if not headers:
            headers = list(sorted(folder.glob("*.h")))[:12]
            for directory in include_dirs:
                if len(headers) >= 12:
                    break
                headers.extend(list(sorted(directory.glob("*.h")))[:12-len(headers)])
        for header in headers:
            text = header.read_text(encoding="utf-8", errors="replace")
            declaration = _TYPE_DECL.search(text)
            start = max(0, declaration.start() - 100) if declaration else 0
            evidence["authentic_headers"].append(dict(path=str(header), read_only=True,
                excerpt=text[start:start + 2400], truncated=start > 0 or len(text) > start + 2400))
    evidence["missing_evidence"] = ([] if evidence["authentic_headers"] or evidence["native_type_headers"] else
        ["No authentic header identified in this packet; recover declarations from genuine sources or caller evidence."])
    if review:
        evidence["missing_evidence"].append(review["reason"])
    return evidence


def block(root, path, reason, retry_seconds=None):
    path = Path(path).resolve()
    task = json.loads((path.parent / "task.json").read_text(encoding="utf-8"))
    if path.name != task["addr"] + ".cpp":
        raise ValueError("Source does not belong to this assigned target")
    row = dict(kind="recovery_blocked", date=datetime.now(timezone.utc).isoformat(),
        client=task["client"], addresses=[task["addr"]], evidence_hash=task.get("evidence_hash"),
        outcome="blocked", missing_evidence=reason, evidence=str(path.parent / "evidence.json"))
    if retry_seconds is not None:
        row["retry_at"] = time.time() + retry_seconds
    (path.parent / "blocker.json").write_text(json.dumps(row), encoding="utf-8")
    research.append(root / "work/agent-memory/attempts.jsonl", row)
    return row


@contextlib.contextmanager
def session(root, folder, triage_seconds=120):
    previous = getattr(SESSION, "value", None)
    SESSION.value = dict(root=root, folder=folder, seconds=triage_seconds, started=time.monotonic())
    try:
        yield
    finally:
        SESSION.value = previous


def experiments(folder):
    return [row for row in research.journal_records(folder / "trials.jsonl")
            if not row.get("duplicate") and not row.get("validation_failed") and
            (not row.get("baseline_hash") or row.get("source_hash") != row["baseline_hash"])]


def remaining():
    active = getattr(SESSION, "value", None)
    if not active or experiments(active["folder"]):
        return None
    return max(0, active["started"] + active["seconds"] - time.monotonic())


def timeout(log):
    active = SESSION.value
    folder = active["folder"]
    task = json.loads((folder / "task.json").read_text(encoding="utf-8"))
    if not (folder / "blocker.json").exists():
        block(active["root"], folder / (task["addr"] + ".cpp"),
            "No journaled experiment within triage budget; inspect model/tool availability and packet evidence before retrying.",
            retry_seconds=600)
    log("Triage budget exhausted without an experiment; blocker saved, moving on.")


def watch(kill, log):
    """Cancel no-check sessions without counting normal triage as a CLI failure."""
    active = getattr(SESSION, "value", None)
    if not active:
        return None
    finished, expired = threading.Event(), threading.Event()
    folder = active["folder"]

    def check():
        deadline = active["started"] + active["seconds"]
        while not finished.is_set():
            if (folder / "blocker.json").exists():
                expired.set()
                log("Missing evidence recorded; stopping this target.")
                kill()
                return
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                break
            if finished.wait(min(1, remaining)):
                return
        if finished.is_set():
            return
        if experiments(folder):
            return
        # Thread-local session state belongs to the launching worker, not this watcher.
        with session(active["root"], folder):
            timeout(log)
        expired.set()
        kill()

    thread = threading.Thread(target=check, daemon=True)
    thread.start()
    return finished, expired


def metrics(folder, elapsed, verified_gains, verified_exacts):
    trials = research.journal_records(folder / "trials.jsonl")
    useful = experiments(folder)
    times = [row["seconds_to_check"] for row in useful if isinstance(row.get("seconds_to_check"), (int, float))]
    blockers = research.journal_records(folder / "blocker.json")
    return dict(first_check_seconds=min(times) if times else None, checks=len(trials),
        experiments=len(useful),
        elapsed_seconds=elapsed, verified_gains=verified_gains, verified_exacts=verified_exacts,
        verified_gains_per_hour=3600 * verified_gains / elapsed if elapsed > 0 else 0,
        blocked=(folder / "blocker.json").exists(),
        blocked_reason=blockers[-1].get("missing_evidence") if blockers else None)


def report(root, limit=20):
    """Compare completed recovery runs; similarity and legacy counters are excluded."""
    profiles = {}
    paths = sorted((root / "work/agent-auto").glob("*/summary.json"), key=lambda p: p.stat().st_mtime, reverse=True)
    count = 0
    coverage = dict(summary_files=len(paths), eligible_runs=0, legacy_runs_excluded=0, unreadable_summaries=0)
    for path in paths:
        try:
            row = json.loads(path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:  # A running worker can be writing its final summary.
            coverage["unreadable_summaries"] += 1
            continue
        if row.get("selection") != "persistent_random":
            coverage["legacy_runs_excluded"] += 1
            continue
        coverage["eligible_runs"] += 1
        if count >= limit:
            continue
        profile = profiles.setdefault(row["profile"], dict(runs=0, exacts=0, partials=0, wall_seconds=0,
            first_checks=[], blocked=0, blocked_reasons={}, checked_targets=0, repair_targets=0,
            repair_verified_gains=0, repair_verified_exacts=0))
        profile["runs"] += 1
        profile["exacts"] += row["matched"]
        profile["partials"] += row["improved"]
        profile["wall_seconds"] += row["wall_elapsed_seconds"]
        for target in row.get("recovery_metrics", []):
            profile["repair_targets"] += 1
            profile["repair_verified_gains"] += target.get("verified_gains", 0)
            profile["repair_verified_exacts"] += target.get("verified_exacts", 0)
            if target["first_check_seconds"] is not None:
                profile["first_checks"].append(target["first_check_seconds"])
                profile["checked_targets"] += 1
            profile["blocked"] += target["blocked"]
            if target["blocked"]:
                reason = target.get("blocked_reason")
                if not reason and target.get("client") and target.get("addr"):
                    blockers = research.journal_records(path.parent / "repair" / target["client"] / target["addr"] / "blocker.json")
                    reason = blockers[-1].get("missing_evidence") if blockers else None
                reason = reason or "unrecorded"
                profile["blocked_reasons"][reason] = profile["blocked_reasons"].get(reason, 0) + 1
        count += 1
    for profile in profiles.values():
        times = profile.pop("first_checks")
        profile["median_first_check_seconds"] = statistics.median(times) if times else None
        profile["checked_target_fraction"] = (profile["checked_targets"] / profile["repair_targets"]
                                                if profile["repair_targets"] else None)
        profile["verified_gains_per_hour"] = 3600 * (profile["exacts"] + profile["partials"]) / max(.001, profile["wall_seconds"])
        profile["repair_verified_gains_per_hour"] = 3600 * profile["repair_verified_gains"] / max(.001, profile["wall_seconds"])
    return dict(completed_runs=count, coverage=coverage, profiles=profiles,
        units="Server-verified improvement events per run wall hour; total includes compiler reuse, partial gains and sibling propagation. "
              "repair_* counts repair-phase receipts including siblings; do not attribute compiler reuse gains to model repair.")


def propagate(root, api, user, worker_id, model, donor, source, siblings, max_size, deadline, log):
    """Fan out a verified improvement to at most eight unresolved same-shape siblings."""
    if not donor.get("shape"):
        return []
    found = []
    obj = None
    for row in [row for row in siblings if row["addr"] != donor["addr"] and row.get("score", 0) < 100
                and row.get("shape") == donor["shape"] and row.get("kind", "code") == "code"][:8]:
        if time.monotonic() >= deadline:
            break
        job = None
        try:
            job = api.call("/v1/lease", dict(user=user, worker=worker_id, clients=[donor["client"]], mode="ai",
                model=model, max_size=max_size, targets=[dict(client=donor["client"], addr=row["addr"])]))["job"]
            if not job:
                continue
            if job.get("client", donor["client"]) != donor["client"] or job["addr"] != row["addr"]:
                raise RuntimeError("Server leased a target outside the propagation selection")
            if job["score"] >= 100:
                continue
            if obj is None:
                obj = match.compile_text(donor["client"], source)
            score = match.check_text(donor["client"], row["addr"], source, obj=obj)[0]
            if score <= job["score"]:
                continue
            receipt = api.call("/v1/submit", dict(user=user, worker=worker_id, model=model, lease=job["lease"],
                client=donor["client"], addr=row["addr"], score=score, source=source), timeout=120)
            if receipt.get("verified") and receipt.get("improved"):
                found.append(dict(addr=row["addr"], score=receipt["score"], previous=job["score"],
                    unit=row.get("unit", ""), size=row.get("size", 0), receipt=receipt))
                research.append(root / "work/agent-memory/attempts.jsonl", dict(kind="recovery_propagation",
                    date=datetime.now(timezone.utc).isoformat(), client=donor["client"], addresses=[row["addr"]],
                    donor=donor["addr"], source_hash=research.digest(source), outcome="server_verified", receipt=receipt))
                log("Sibling %s: server verified %d%%" % (row["addr"], receipt["score"]))
        except (worker.ApiFailure, match.CompileError, RuntimeError, OSError, ValueError) as error:
            log("Sibling checks stopped; earlier verified receipts kept: " + str(error))
            break
        finally:
            if job:
                try:
                    api.call("/v1/release", dict(lease=job["lease"], cooldown=0))
                except (worker.ApiFailure, OSError, ValueError) as error:
                    log("Sibling claim release failed: " + str(error))
    return found
