"""Agent-driven native integration: the DeepSeek native pass as four commands any agent (Codex, Claude) can drive.

  roc native-try targets [--limit N]            files whose rebuilt methods are exact-mined near misses
  roc native-try evidence FILE [--context ...] [--only ADDR,...]
                                                the exact prompt the model pass sends (rules, code, targets, diffs)
  roc native-try check FILE BLOCKS.txt          apply SEARCH/REPLACE blocks, compile the real file, report;
                                                a new exact with no loss is minimized and saved as a proposal
  roc native-try check FILE                     revalidate saved edits after syncing a new baseline
  roc native-try submit --model MODEL           claim, stage and submit every saved proposal as one verified batch

Saved proposals live in work/native-try/proposals.json; later checks of a file build on its saved edits.
Contributor PCs without rebuild artifacts read the evidence from the server (/v1/integration/evidence).
Run it only in a private checkout: it writes rebuild/2008-06/out, and refuses the server's checkout.
`check` edits one source/header; header trials identify a real caller with --only ADDR."""
import hashlib
import json
import re
from pathlib import Path

from roc import integration, native_sweep, worker

OUT = native_sweep.ROOT / "work/native-try"
PROPOSALS = OUT / "proposals.json"


def context():
    # Every action writes the module overlay under rebuild/2008-06/out: never in the server's live checkout.
    native_sweep.require_private_workspace()
    settings = worker.load_settings()
    if not settings.get("server"):
        raise ValueError("Configure a server first: roc config --user NAME --server URL")
    api = worker.Api(settings["server"], integration.native_token() or settings.get("native_token") or settings.get("token"))
    try:
        base = api.call("/v1/integration/base")
        generator = native_sweep.ROOT / "rebuild/2008-06/patches/make_rbxgs_client.py"
        if hashlib.sha256(generator.read_bytes()).hexdigest() != base["generator"]:
            for snapshot in (native_sweep.ROOT / "work/integration-client/jobs").glob("*/submitted-generator.py"):
                original = snapshot.with_name("generator-base.py")
                if original.exists() and generator.read_bytes() == snapshot.read_bytes() and \
                        hashlib.sha256(original.read_bytes()).hexdigest() == base["generator"]:
                    native_sweep.restore_submitted_baseline(snapshot.parent.name)
                    break
        if hashlib.sha256(generator.read_bytes()).hexdigest() != base["generator"]:
            raise ValueError("Local baseline differs from server; run roc integrate sync first")
        if json.loads(generator.with_name("rbxgs-client.json").read_text()) != base["overlay"]:
            if not integration.sync_client_baseline(native_sweep.ROOT, base, only_if_clean=True):
                raise ValueError("Local baseline differs from server; preserve local edits and sync first (roc integrate sync)")
            print("accepted baseline advanced; clean local overlay refreshed", flush=True)
        integration.atomic_json(native_sweep.ROOT / "work/integration-client/baseline.json", base)
        ctx = native_sweep.native_context({}, api)
        ctx.base_revision = base["revision"]
    finally:
        api.close()
    ctx.compile = lambda source, rel, label: native_sweep.compile_unit(source, rel, label, OUT, ctx.tree, ctx.overlay,
                                                                       ctx.includes, ctx.defines, ctx.flags,
                                                                       translation_unit=getattr(ctx, "translation_unit", None),
                                                                       related_headers=getattr(ctx, "related_headers", None))
    return ctx


def saved():
    proposals = json.loads(PROPOSALS.read_text()) if PROPOSALS.exists() else []
    overlay = native_sweep.ROOT / "rebuild/2008-06/patches/rbxgs-client.json"
    base = json.loads(overlay.read_text()) if overlay.exists() else {}
    names = integration.canonical_patches({p["file"]: [] for p in proposals}, base)
    canonical = {name.casefold(): name for name in names}
    seen = set()
    for proposal in proposals:
        name = canonical[proposal["file"].casefold()]
        if name.casefold() in seen:
            raise ValueError("Duplicate saved source proposals: " + name)
        seen.add(name.casefold())
        proposal["file"] = name
        if "related_headers" in proposal:
            proposal["related_headers"] = integration.canonical_patches(proposal["related_headers"], base)
    return proposals


def file_state(ctx, rel):
    """(text with saved edits applied, saved edits, waiting near-miss targets, baseline exacts, baseline object)."""
    original = (ctx.overlay / rel if (ctx.overlay / rel).exists() else ctx.tree / rel).read_text(errors="replace")
    if not hasattr(ctx, "related_headers"):
        ctx.related_headers = next((p.get("related_headers", {}) for p in saved() if p["file"] == rel), {})
    edits = [pair for p in saved() if p["file"] == rel for pair in p["edits"]]
    text = native_sweep.apply_edits(original, edits) if edits else original
    wanted = ctx.targets - ctx.owned
    caller = getattr(ctx, "translation_unit", rel)
    caller_text = (ctx.overlay / caller if (ctx.overlay / caller).exists() else ctx.tree / caller).read_text(errors="replace") if caller != rel else text
    homes = native_sweep.target_files({caller: caller_text}, wanted, ctx.names, ctx.by_addr)
    base = ctx.compile(text, rel, "baseline")
    if not base["ok"]:
        raise SystemExit("baseline compile failed:\n" + base["error"][-2000:])
    data = Path(base["object"]).read_bytes()
    dependencies = Path(base["object"]).with_suffix(".deps")
    included = json.loads(dependencies.read_text()) if dependencies.exists() else []
    # Use compiler evidence: an accepted overlay can differ from the original tools header.
    ctx.evidence_headers = {name: paths for name in re.findall(r'^\s*#\s*include\s*"([^"]+)"', text, re.M)
                            if (paths := [path for path in included if path.replace("\\", "/").lower().endswith(
                                "/" + name.replace("\\", "/").lower())])}
    ctx.evidence_hits = ctx.matcher.scan(data)
    return text, edits, sorted(homes.get(caller, [])), {h["addr"] for h in ctx.evidence_hits}, data


def header_caller(ctx, args):
    if Path(args.file).suffix.lower() not in (".h", ".hpp", ".inl"):
        return
    previous = next((p for p in saved() if p["file"] == args.file), {})
    caller = previous.get("translation_unit")
    if not caller:
        selected = set((getattr(args, "only", None) or "").split(",")) - {""}
        if not selected:
            raise ValueError("Header trial needs --only ADDR to identify its real caller; saved trials remember it")
        texts = {p.relative_to(ctx.tree).as_posix():
                 (ctx.overlay / p.relative_to(ctx.tree) if (ctx.overlay / p.relative_to(ctx.tree)).exists() else p).read_text(errors="replace")
                 for p in ctx.tree.glob("App/*/*.cpp") if not p.name.startswith("roc_")}
        homes = native_sweep.target_files(texts, selected, ctx.names, ctx.by_addr)
        if not homes:
            raise ValueError("No native caller found for the selected header targets")
        caller = max(sorted(homes), key=lambda rel: len(homes[rel]))
    ctx.translation_unit = caller
    print("header proof caller: " + caller, flush=True)


def diff(ctx, obj, addr):
    symbol = ctx.names.get(addr, {}).get("symbol")
    return native_sweep.body_diff(obj, symbol, addr) if symbol else "no rebuilt body"


def cmd_targets(ctx, args):
    wanted = {a for a in ctx.targets - ctx.owned - getattr(ctx, "integrated", set())
              if getattr(args, "min_score", 0) <= ctx.names.get(a, {}).get("score", 0) <= getattr(args, "max_score", 100)}
    wanted -= {w["addr"] for proposal in saved() for w in proposal["witnesses"]}
    texts = {p.relative_to(ctx.tree).as_posix():
             (ctx.overlay / p.relative_to(ctx.tree) if (ctx.overlay / p.relative_to(ctx.tree)).exists() else p).read_text(errors="replace")
             for p in ctx.tree.glob("App/*/*.cpp") if not p.name.startswith("roc_")}
    homes = native_sweep.target_files(texts, wanted, ctx.names, ctx.by_addr)
    for rel in sorted(homes, key=lambda r: -len(homes[r]))[:args.limit]:
        print("%-48s %3d  %s" % (rel, len(homes[rel]), " ".join(homes[rel][:6])))


def cmd_evidence(ctx, args):
    header_caller(ctx, args)
    text, _, addrs, exact, data = file_state(ctx, args.file)
    if args.only:
        addrs = [a for a in addrs if a in args.only.split(",")]
    if not addrs:
        raise SystemExit("no waiting near-miss target in " + args.file)
    shown = native_sweep.excerpt(text, [ctx.names[a]["symbol"] for a in addrs if ctx.names.get(a, {}).get("symbol")]) if args.context == "methods" else text
    items = [dict(native_sweep.model_evidence(a, ctx.names, ctx.by_addr), current_diff=diff(ctx, data, a),
                  tu_code_and_data_exact=a in exact) for a in addrs[:6]]
    ownership = native_sweep.ownership_candidates(data, [h for h in getattr(ctx, "evidence_hits", []) if h["addr"] in addrs[:6]])
    for item in items:
        item["globally_integrated"] = item["addr"] in getattr(ctx, "integrated", set())
        if item["tu_code_and_data_exact"]:
            item["next_action"] = "Already exact in this translation unit; inspect linked ownership/provider before changing source. Server acceptance still required."
        if item["addr"] in ownership:
            item["code_candidates"] = ownership[item["addr"]]
            item["module_ownership_unique"] = ownership[item["addr"]] == [item["addr"]]
            if not item["module_ownership_unique"]:
                item["next_action"] = "Address-ambiguous body; current server ownership gate cannot credit this local exact."
        if item["globally_integrated"]:
            item["next_action"] = "Already independently integrated; changing another module's copy does not earn a new distinct credit."
    if getattr(args, "brief", False):
        for item in items:
            item.pop("target_asm", None)
        print("FILE %s\n```cpp\n%s\n```\nHEADERS (compiler-selected)\n%s\nTARGETS\n%s" %
              (args.file, shown, json.dumps(getattr(ctx, "evidence_headers", {}), indent=1), json.dumps(items, indent=1)))
    else:
        print("HEADERS (compiler-selected)\n" + json.dumps(getattr(ctx, "evidence_headers", {}), indent=1))
        print(native_sweep.model_prompt(args.file, shown, items))


def cmd_check(ctx, args):
    header_caller(ctx, args)
    previous_proposal = next((p for p in saved() if p["file"] == args.file), {})
    ctx.related_headers = {name: list(pairs) for name, pairs in previous_proposal.get("related_headers", {}).items()}
    text, edits, addrs, baseline, _ = file_state(ctx, args.file)
    previous = [w for p in saved() if p["file"] == args.file for w in p["witnesses"]]
    if not args.blocks and not previous:
        raise ValueError("check requires a blocks file, or saved edits to recheck")
    blocks = Path(args.blocks).read_text(encoding="utf-8-sig") if args.blocks else ""
    headers = {}
    if blocks.lstrip().startswith("{"):
        bundle = json.loads(blocks)
        if args.file not in bundle or Path(args.file).suffix.lower() != ".cpp":
            raise ValueError("Paired JSON edits need the primary CPP file and its header edits")
        new_edits = bundle.pop(args.file)
        headers = bundle
        for name, pairs in dict(headers, **{args.file: new_edits}).items():
            if name != args.file and Path(name).suffix.lower() not in (".h", ".hpp", ".inl"):
                raise ValueError("Related files must be headers")
            if not isinstance(pairs, list) or any(not isinstance(pair, list) or len(pair) != 2 or
                                                 not all(isinstance(value, str) for value in pair) for pair in pairs):
                raise ValueError("Paired edits must contain SEARCH/REPLACE string pairs")
        for name, pairs in headers.items():
            ctx.related_headers.setdefault(name, []).extend(pairs)
    else:
        new_edits = native_sweep.parse_edits(blocks) if blocks else []
    changed = bool(new_edits or headers)
    candidate = native_sweep.apply_edits(text, new_edits) if new_edits else text
    result = ctx.compile(candidate, args.file, "check")
    if not result["ok"]:
        raise SystemExit("compile failed:\n" + result["error"][-3000:])
    data = Path(result["object"]).read_bytes()
    hits = ctx.matcher.scan(data)
    found = {h["addr"] for h in hits}
    keep = baseline | {w["addr"] for w in previous}
    # Whole-TU proofs include real header instantiations; inventory file labels are only hints.
    new = (found & ctx.targets) - baseline - ctx.owned - getattr(ctx, "integrated", set())
    lost = keep - found
    ownership = native_sweep.ownership_candidates(data, [h for h in hits if h["addr"] in new])
    ambiguous = {a: candidates for a, candidates in ownership.items() if candidates != [a]}
    new -= ambiguous.keys()
    waiting = set(addrs) - found
    if getattr(args, "only", None):
        waiting &= set(args.only.split(","))
    diffs = {addr: diff(ctx, data, addr) for addr in
             sorted(lost or (waiting if not new and (changed or not previous) else set()))[:3]}
    report = Path(result["object"]).with_suffix(".evidence.json")
    integration.atomic_json(report, dict(file=args.file, base_revision=ctx.base_revision, proof=result,
                                        newly_exact=sorted(new), lost=sorted(lost), still_not_exact=sorted(waiting),
                                        ownership_candidates=ownership, current_diffs=diffs))
    if ambiguous:
        print("address-ambiguous local exacts (no unique module credit): " +
              json.dumps({a: len(candidates) for a, candidates in sorted(ambiguous.items())[:6]}) +
              ("; %d more targets (see evidence)" % (len(ambiguous) - 6) if len(ambiguous) > 6 else ""))
    print("newly exact: %s\nlost: %s\nstill not exact: %s" % (sorted(new) or "none", sorted(lost) or "none",
                                                             sorted(set(addrs) - found) or "none"))
    print("evidence: " + str(report))
    # Successful trials need only their gain/loss summary. On failure show regressions first,
    # rather than burying them under unrelated waiting methods.
    for addr, instructions in diffs.items():
        print("\n%s target vs rebuilt:\n%s" % (addr, instructions))
    if lost or (not new and (not previous or changed)):
        raise SystemExit(1)
    if new_edits:
        proposal = native_sweep.minimize(args.file, text, new_edits, new, keep,
                                         lambda source, label: ctx.compile(source, args.file, label), ctx.matcher, "check",
                                         allow_empty=bool(ctx.related_headers), definitions=result.get("defined_symbols", ()))
    else:
        proposal = dict(file=args.file, edits=[], mode="model", witnesses=[],
                        proof=dict(result, hits=ctx.matcher.scan(data), losses=[]))
    if not proposal:
        raise SystemExit("minimized edits lost the proof; nothing saved")
    if headers:
        source = native_sweep.apply_edits(text, proposal["edits"]) if proposal["edits"] else text
        for name, pairs in headers.items():
            for pair in list(pairs):
                kept = list(ctx.related_headers[name])
                ctx.related_headers[name].remove(pair)
                trial = ctx.compile(source, args.file, "minimize-header-" + native_sweep.integration.digest([name, ctx.related_headers[name]])[:12])
                found = {h["addr"] for h in ctx.matcher.scan(Path(trial["object"]).read_bytes())} if trial["ok"] else set()
                if not new <= found or keep - found or set(result.get("defined_symbols", ())).intersection(trial.get("undefined_symbols", ())):
                    ctx.related_headers[name] = kept
        final = ctx.compile(source, args.file, "paired-final")
        hits = ctx.matcher.scan(Path(final["object"]).read_bytes()) if final["ok"] else []
        found = {h["addr"] for h in hits}
        if not new <= found or keep - found or set(result.get("defined_symbols", ())).intersection(final.get("undefined_symbols", ())):
            raise SystemExit("paired edits lost their final proof; nothing saved")
        proposal["proof"] = dict(final, hits=hits, losses=[])
        proposal["witnesses"] = [h for h in hits if h["addr"] in new]
    for hit in proposal["witnesses"]:
        hit["claim_unit"] = native_sweep.claim_unit(hit, ctx.by_addr[hit["addr"]])
    rest = [p for p in saved() if p["file"] != args.file]
    # One proposal per file: saved edits first, then these (anchors were checked against that text).
    proposal["edits"] = edits + proposal["edits"]
    proposal["witnesses"] += previous
    proposal["base_revision"] = ctx.base_revision
    if getattr(ctx, "translation_unit", None):
        proposal["translation_unit"] = ctx.translation_unit
    if ctx.related_headers:
        proposal["related_headers"] = {name: pairs for name, pairs in ctx.related_headers.items() if pairs}
    if PROPOSALS.exists():
        archive = OUT / "archive" / ("before-check-" + integration.digest(PROPOSALS.read_text()) + ".json")
        if not archive.exists():
            integration.atomic_json(archive, json.loads(PROPOSALS.read_text()))
    integration.atomic_json(PROPOSALS, rest + [proposal])
    print("saved: %d edit(s) for %s" % (len(proposal["edits"]), ", ".join(w["addr"] for w in proposal["witnesses"])))


def cmd_preflight(args):
    context()  # sync the accepted baseline before combining saved recipes
    proposals = saved()
    if not proposals:
        raise ValueError("no saved proposals")
    additions = {}
    for proposal in proposals:
        for name, edits in dict(proposal.get("related_headers", {}), **{proposal["file"]: proposal["edits"]}).items():
            for edit in edits:
                if edit not in additions.setdefault(name, []):
                    additions[name].append(edit)
    from roc.integration_verify import linked_preflight
    receipt = linked_preflight(native_sweep.ROOT, additions, OUT, lambda message: print(message, flush=True))
    print(json.dumps(receipt, indent=1))


def cmd_submit(args):
    if not saved():
        raise SystemExit("no saved proposals")
    spec = {"client": "2008-06", "native_sweep": {"proposals_file": str(PROPOSALS), "apply": True, "submit": True,
                                                  "model": args.model, "wait": False}, "targets": {}}
    summary = native_sweep.run(spec, "native-try", output=OUT / "submit", log=lambda message: print(message, flush=True))
    print(json.dumps({k: summary.get(k) for k in ("state", "job", "applied_files", "local_exact", "reason", "blocked_units")}, indent=1))
    if not summary.get("job"):
        raise SystemExit("No submission queued; saved proposals retained")
    if summary.get("job"):
        submitted = set(summary["applied_paths"])
        proposals = saved()
        integration.atomic_json(PROPOSALS.with_name("submitted-%s.json" % summary["job"][:12]),
                                [p for p in proposals if p["file"] in submitted])
        remaining = [p for p in proposals if p["file"] not in submitted]
        if remaining:
            integration.atomic_json(PROPOSALS, remaining)
        else:
            PROPOSALS.unlink()
        native_sweep.restore_submitted_baseline(summary["job"])


def main(args):
    try:
        return dispatch(args)
    except ValueError as error:
        raise SystemExit(str(error)) from None


def dispatch(args):
    if args.action == "preflight":
        return cmd_preflight(args)
    if args.action == "submit":
        return cmd_submit(args)
    if args.action == "reset":
        if getattr(args, "file", None):
            remaining = [p for p in saved() if p["file"].casefold() != args.file.casefold()]
            if remaining:
                integration.atomic_json(PROPOSALS, remaining)
            else:
                PROPOSALS.unlink(missing_ok=True)
            return print("saved proposal cleared: " + args.file)
        PROPOSALS.unlink(missing_ok=True)
        return print("saved proposals cleared")
    if args.action in ("evidence", "check") and not args.file:
        raise ValueError(args.action + " requires a source FILE")
    if getattr(args, "file", None):
        registry = native_sweep.ROOT / "rebuild/2008-06/patches/rbxgs-client.json"
        if registry.exists():
            args.file = next(iter(integration.canonical_patches({args.file: []}, json.loads(registry.read_text()))))
    ctx = context()
    {"targets": cmd_targets, "evidence": cmd_evidence, "check": cmd_check}[args.action](ctx, args)


def register(cmd):
    cmd("native-try", main, "agent-driven native integration: targets, evidence, check, submit (docs/NATIVE_AGENT.md)",
        (["action"], {"choices": ["targets", "evidence", "check", "preflight", "submit", "reset"]}),
        (["file"], {"nargs": "?"}), (["blocks"], {"nargs": "?"}),
        (["--context"], {"choices": ["file", "methods"], "default": "file"}),
        (["--limit"], {"type": int, "default": 25}), (["--model"], {}),
        (["--min-score"], {"type": int, "default": 0}),
        (["--max-score"], {"type": int, "default": 100}),
        (["--brief"], {"action": "store_true", "help": "evidence: omit repeated rules and assembly; keep source, mined proof and diffs"}),
        (["--only"], {"help": "target addresses for evidence/check diagnostics; selects a header proof caller"}))

