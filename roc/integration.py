"""Native-source promotion: durable claims, declarative uploads and verified credit."""
import hashlib
import json
import os
import re
import socket
import sqlite3
import subprocess
import sys
import threading
import time
import uuid
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parent.parent
CLIENT = "2008-06"
MODULE = "rbxgs-app"
LEASE_SECONDS = 2 * 3600
SCHEMA = """
CREATE TABLE IF NOT EXISTS integration_claims(
 id TEXT PRIMARY KEY, client TEXT, unit TEXT, user TEXT, worker TEXT,
 expires REAL, state TEXT, addresses TEXT, base TEXT, UNIQUE(client,unit));
CREATE TABLE IF NOT EXISTS integration_jobs(
 id TEXT PRIMARY KEY, claim_id TEXT, digest TEXT UNIQUE, user TEXT, model TEXT,
 unit TEXT, base TEXT, patches TEXT, evidence TEXT, state TEXT, phase TEXT,
 created REAL, updated REAL, receipt TEXT);
CREATE TABLE IF NOT EXISTS integration_credit(
 client TEXT, addr TEXT, user TEXT, model TEXT, job TEXT, ts REAL,
 PRIMARY KEY(client,addr));
CREATE TABLE IF NOT EXISTS integration_accepted(
 job TEXT PRIMARY KEY, patches TEXT, ts REAL);
CREATE TABLE IF NOT EXISTS integration_bases(
 revision TEXT PRIMARY KEY, payload TEXT);
CREATE TABLE IF NOT EXISTS integration_config(
 key TEXT PRIMARY KEY, value TEXT);
"""


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(",", ":")).encode()).hexdigest()


def atomic_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + "." + uuid.uuid4().hex + ".tmp")
    temp.write_text(json.dumps(value, indent=1) + "\n", encoding="utf-8")
    temp.replace(path)


def native_token(root=ROOT, fallback=None, create=False):
    """Native builds execute submitted C++; invitations are separate from public mining."""
    import secrets
    secret = os.environ.get("ROC_NATIVE_TOKEN") or fallback
    path = Path(root) / "local/config/native-integration-token"
    if secret:
        return secret
    if path.exists():
        return path.read_text(encoding="utf-8").strip()
    if create:
        path.parent.mkdir(parents=True, exist_ok=True)
        secret = secrets.token_urlsafe(32)
        with path.open("x", encoding="utf-8") as stream:
            stream.write(secret + "\n")
        path.chmod(0o600)
        return secret
    return None


def validate_patches(patches):
    if not isinstance(patches, dict) or not 1 <= len(patches) <= 40:
        raise ValueError("Need 1-40 source overlay paths")
    if len(json.dumps(patches).encode()) > 750_000:
        raise ValueError("Overlay exceeds 750000 bytes")
    for name, change in patches.items():
        if not isinstance(name, str):
            raise ValueError("Overlay paths must be strings")
        path = PurePosixPath(name)
        if ("\\" in name or ":" in name or path.is_absolute() or ".." in path.parts
                or path.as_posix() != name or len(path.parts) < 2
                or path.parts[0] not in ("App", "Network", "RbxView", "RbxGraphics", "Rendering")
                or path.suffix not in (".h", ".hpp", ".cpp", ".inl", ".c")):
            raise ValueError("Not a permitted native source path: " + name)
        before = []
        if isinstance(change, dict):
            if set(change) != {"before", "after"} or not isinstance(change["before"], list):
                raise ValueError("A recipe replacement needs before/after lists")
            before, edits = change["before"], change["after"]
        else:
            edits = change
        if not isinstance(edits, list) or not 1 <= len(edits) <= 100 or len(before) > 100:
            raise ValueError("Need 1-100 edits per path")
        for edit in edits:
            if (not isinstance(edit, list) or len(edit) != 2
                    or not all(isinstance(s, str) for s in edit)):
                raise ValueError("An edit must be [old_text,new_text]")
            old, new = edit
            if edit in before:
                continue
            if old.startswith("@") and not old.startswith("@all:"):
                raise ValueError("Uploaded whole-file adoption/directives are not allowed")
            if old == new or not new and not old:
                raise ValueError("Empty or unchanged edit")
            if re.search(r"\b(?:__asm|__emit)\b|\basm\s*\(", new):
                raise ValueError("Assembly/byte emission is not a source promotion")
            if re.search(r"\breinterpret_cast\b|\b(?:char|BYTE)\s+pad\w*\s*\[", new):
                raise ValueError("Padding structs and offset views are not native source")
            types = r"\b(?:struct|class|union)\s+([\w:]+)\s*(?::[^;{]+)?\{"
            if set(re.findall(types, new)) - set(re.findall(types, old)):
                raise ValueError("Promote existing native classes; do not append invented snippet types")
    return patches


def merge_patches(base, additions):
    result = {name: list(edits) for name, edits in base.items()}
    for name, change in additions.items():
        if isinstance(change, dict):
            if result.get(name, []) != change["before"]:
                raise ValueError("Stale recipe replacement: " + name)
            result[name] = list(change["after"])
        else:
            result.setdefault(name, []).extend(change)
    return result


def overlay_delta(base, candidate):
    """Add recipes, or replace an existing recipe with an exact baseline guard."""
    result = {}
    for name in set(base) | set(candidate):
        before, after = base.get(name, []), candidate.get(name, [])
        if not after and before:
            raise ValueError("Cannot remove a complete accepted source overlay: " + name)
        if after[:len(before)] != before:
            result[name] = {"before": before, "after": after}
        elif len(after) > len(before):
            result[name] = after[len(before):]
    return validate_patches(result)


class Promotions:
    def __init__(self, store, root=ROOT):
        self.store, self.root = store, Path(root)
        self.directory = self.root / "work" / "integration"
        self.overlay = self.root / "rebuild" / CLIENT / "patches" / "rbxgs-client.json"
        self.generator = self.overlay.with_name("make_rbxgs_client.py")
        self.wake = threading.Event()
        self.worker_error = None
        self.catalog_key, self.catalog_rows = None, []
        self.native_paths = {}
        with store.lock:
            store.db.executescript(SCHEMA)
            initial = self.overlay.with_name("native-promotions.json")
            store.db.execute("INSERT OR IGNORE INTO integration_config VALUES('initial_patches',?)",
                             (initial.read_text(encoding="utf-8") if initial.exists() else "{}",))
            store.db.commit()

    def accepted(self):
        with self.store.lock:
            rows = self.store.db.execute("SELECT patches FROM integration_accepted ORDER BY ts,job").fetchall()
            initial = json.loads(self.store.db.execute(
                "SELECT value FROM integration_config WHERE key='initial_patches'").fetchone()[0])
        result = initial if isinstance(initial, list) else [initial] if initial else []
        for row in rows:
            result.append(json.loads(row[0]))
        return result

    def baseline(self):
        if not self.generator.exists() or not self.overlay.exists():
            raise ValueError("Native rebuild inputs are not installed on this server")
        with self.store.lock, self.store.db:
            base = json.loads(self.overlay.read_text(encoding="utf-8"))
            generator = hashlib.sha256(self.generator.read_bytes()).hexdigest()
            initial = json.loads(self.store.db.execute(
                "SELECT value FROM integration_config WHERE key='initial_patches'").fetchone()[0])
            accepted = initial if isinstance(initial, list) else [initial] if initial else []
            for row in self.store.db.execute("SELECT patches FROM integration_accepted ORDER BY ts,job"):
                accepted.append(json.loads(row[0]))
            result = {"revision": digest([base, generator]), "overlay": base,
                      "generator": generator, "accepted": accepted}
            self.store.db.execute("INSERT OR IGNORE INTO integration_bases VALUES(?,?)",
                                  (result["revision"], json.dumps(result)))
        return result

    def catalog(self):
        path = self.root / "rebuild" / CLIENT / "manifests" / "functions.json"
        report = path.parent.parent / "out" / "RbxgsApp" / "report.json"
        queue = path.parent.parent / "out" / "agent-queue.json"
        key = (path.stat().st_mtime_ns, report.stat().st_mtime_ns if report.exists() else 0,
               queue.stat().st_mtime_ns if queue.exists() else 0)
        if self.catalog_key != key:
            from collections import defaultdict
            tree = self.root / "tools/rbxgs/Client"
            header_texts = [(p, p.read_text(errors="replace")) for p in (tree / "App/include").rglob("*.h")]
            headers = "\n".join(t for _, t in header_texts)
            self.native_paths = {}
            for p, text in header_texts:
                for cls in re.findall(r"\bclass\s+(\w+)", text):
                    self.native_paths.setdefault(cls, set()).add(p.relative_to(tree).as_posix())
            for p in (tree / "App").rglob("*.cpp"):
                if p.name.startswith("roc_"):
                    continue
                for cls in set(re.findall(r"\b(\w+)::~?\w+\s*\(", p.read_text(errors="replace"))):
                    self.native_paths.setdefault(cls, set()).add(p.relative_to(tree).as_posix())
            owned = set(json.loads(report.read_text()).get("owned_addrs", [])) if report.exists() else set()
            with self.store.lock:
                accepted = self.store.db.execute("SELECT receipt FROM integration_jobs WHERE state='accepted'").fetchall()
            for receipt, in accepted:
                owned.update(json.loads(receipt).get("gains", []))
            groups = defaultdict(list)
            state = json.loads(queue.read_text()) if queue.exists() else {}
            skipped = set(state.get("done", [])) | set(state.get("parked", {}))
            for f in json.loads(path.read_text(encoding="utf-8")):
                unit = f.get("unit") or ""
                m = re.fullmatch(r"RBX::(?:\w+::)*(\w+)", unit)
                if (f.get("score") == 100 and f.get("source_kind") == "snippet"
                        and unit not in skipped and f["addr"] not in owned and f["size"] >= 24 and m
                        and re.search(r"\bclass\s+" + re.escape(m[1]) + r"\b", headers)):
                    groups[unit].append(f)
            self.catalog_rows = sorted(groups.items(), key=lambda x: (-len(x[1]), x[0]))
            self.catalog_key = key
        return self.catalog_rows

    def packet(self, claim):
        identifier, unit, user, worker, expires, addresses, revision = claim
        evidence = []
        for addr in json.loads(addresses)[:5]:
            path = self.root / "src" / CLIENT / (addr + ".cpp")
            evidence.append({"addr": addr, "source": path.read_text(errors="replace")[:10000]
                             if path.exists() else "Use roc pull to obtain this exact source."})
            if (self.root / "clients/2008-06/Roblox.exe").exists():
                from roc import match
                code, _, _ = match.target(CLIENT, addr)
                instructions = match.disasm(code, int(addr, 16))
                evidence[-1]["disassembly"] = instructions[:200]
                evidence[-1]["disassembly_truncated"] = len(instructions) > 200
        abi = self.root / "rebuild" / CLIENT / "manifests" / "abi-evidence.json"
        with self.store.lock:
            baseline = json.loads(self.store.db.execute("SELECT payload FROM integration_bases WHERE revision=?",
                                                       (revision,)).fetchone()[0])
        return {"id": identifier, "client": CLIENT, "module": MODULE, "unit": unit,
                "user": user, "worker": worker, "expires": expires,
                "addresses": json.loads(addresses), "base_revision": revision,
                "baseline": baseline, "snippets": evidence,
                "native_paths": sorted(self.native_paths.get(unit.rsplit("::", 1)[-1], [])),
                "abi": json.loads(abi.read_text()).get(unit, {}) if abi.exists() else {},
                "instructions": "Edit make_rbxgs_client.py only; regenerate; submit a declarative overlay. "
                "Derive every change from target bytes. No pad structs, offset views or invented fields."}

    def claim(self, user, worker, count=1, unit=None):
        if not isinstance(count, int) or not 1 <= count <= 16:
            raise ValueError("Claim count must be 1-16")
        if not re.fullmatch(r"[A-Za-z0-9_.-]{2,32}", user) or not worker or len(worker) > 100:
            raise ValueError("Need a valid user and worker identity")
        revision = self.baseline()["revision"]
        candidates = self.catalog()
        now, claimed = time.time(), []
        with self.store.lock, self.store.db:
            # IMMEDIATE also serializes two separate server connections/processes.
            self.store.db.execute("BEGIN IMMEDIATE")
            for name, functions in candidates:
                if unit and name != unit:
                    continue
                old = self.store.db.execute("SELECT id,user,worker,expires,state FROM integration_claims "
                                            "WHERE client=? AND unit=?", (CLIENT, name)).fetchone()
                if old and (old[4] == "submitted" or old[3] > now):
                    if old[1:3] != (user, worker) or old[4] != "claimed":
                        continue
                    row = self.store.db.execute("SELECT id,unit,user,worker,expires,addresses,base "
                                                "FROM integration_claims WHERE id=?", (old[0],)).fetchone()
                else:
                    row = (uuid.uuid4().hex, name, user, worker, now + LEASE_SECONDS,
                           json.dumps([f["addr"] for f in functions]), revision)
                    self.store.db.execute("DELETE FROM integration_claims WHERE client=? AND unit=?", (CLIENT, name))
                    self.store.db.execute("INSERT INTO integration_claims "
                                          "(id,client,unit,user,worker,expires,state,addresses,base) "
                                          "VALUES(?,?,?,?,?,?,'claimed',?,?)",
                                          (row[0], CLIENT, name, user, worker, row[4], row[5], revision))
                claimed.append(row)
                if len(claimed) == count:
                    break
        return {"claims": [self.packet(row) for row in claimed]}

    def renew(self, user, identifier, release=False, reason=None):
        parked = release and bool(reason)
        if reason is not None and (not isinstance(reason, str) or len(reason) > 500):
            raise ValueError("Park reason must be at most 500 characters")
        with self.store.lock, self.store.db:
            changed = self.store.db.execute("UPDATE integration_claims SET expires=?,state=? "
                "WHERE id=? AND user=? AND state='claimed' AND expires>?",
                (time.time() if release and not parked else time.time() + LEASE_SECONDS,
                 "parked: " + reason if parked else "released" if release else "claimed", identifier, user, time.time())).rowcount
        return {"ok": bool(changed)}

    def submit(self, user, body):
        patches = validate_patches(body.get("patches"))
        model, evidence = body.get("model"), body.get("evidence")
        if not isinstance(model, str) or not model.strip() or len(model) > 120:
            raise ValueError("Record the actual model, or human for manual work")
        if not isinstance(evidence, str) or not 1 <= len(evidence) <= 16000:
            raise ValueError("Evidence notes are required")
        identifiers = body.get("claims", [body.get("claim")])
        if (not isinstance(identifiers, list) or not 1 <= len(identifiers) <= 16
                or any(not isinstance(i, str) for i in identifiers) or len(set(identifiers)) != len(identifiers)):
            raise ValueError("Need 1-16 distinct claim IDs")
        identifiers = sorted(identifiers)
        base = str(body.get("base_revision", ""))
        retry = body.get("retry_of")
        if retry is not None and (not isinstance(retry, str) or not re.fullmatch(r"[0-9a-f]{32}", retry)):
            raise ValueError("Invalid retry job ID")
        key = digest([user, identifiers, base, model, patches, evidence, retry])
        with self.store.lock, self.store.db:
            self.store.db.execute("BEGIN IMMEDIATE")
            previous = self.store.db.execute("SELECT id,state FROM integration_jobs WHERE digest=?", (key,)).fetchone()
            if previous:
                return {"id": previous[0], "state": previous[1], "duplicate": True}
            if retry and not self.store.db.execute("SELECT 1 FROM integration_jobs WHERE id=? AND user=? "
                    "AND state='rejected' AND claim_id=?", (retry, user, json.dumps(identifiers))).fetchone():
                raise ValueError("Only your rejected batch can be retried")
            claims = []
            for identifier in identifiers:
                claim = self.store.db.execute("SELECT unit,addresses,base FROM integration_claims "
                    "WHERE id=? AND user=? AND state='claimed' AND expires>?", (identifier, user, time.time())).fetchone()
                if not claim or claim[2] != base:
                    raise ValueError("Missing, expired or mismatched claim; renew/reclaim before submitting")
                if not any(addr in evidence for addr in json.loads(claim[1])):
                    raise ValueError("Cite a claimed target address for " + claim[0])
                claims.append(claim)
            job = uuid.uuid4().hex
            self.store.db.execute("INSERT INTO integration_jobs VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
                (job, json.dumps(identifiers), key, user, model, ", ".join(c[0] for c in claims), base, json.dumps(patches), evidence,
                 "queued", "queued", time.time(), time.time(), None))
            for identifier in identifiers:
                self.store.db.execute("UPDATE integration_claims SET state='submitted' WHERE id=?", (identifier,))
        self.wake.set()
        return {"id": job, "state": "queued", "duplicate": False}

    def status(self, identifier=None):
        with self.store.lock:
            rows = self.store.db.execute("SELECT id,user,model,unit,state,phase,created,updated,receipt "
                "FROM integration_jobs " + ("WHERE id=? " if identifier else "") + "ORDER BY created DESC LIMIT 100",
                (identifier,) if identifier else ()).fetchall()
            leaders = self.store.db.execute("SELECT user,model,COUNT(*) FROM integration_credit "
                                           "GROUP BY user,model ORDER BY COUNT(*) DESC,user").fetchall()
            parked = self.store.db.execute("SELECT unit,state,expires FROM integration_claims "
                                           "WHERE state LIKE 'parked:%' AND expires>?", (time.time(),)).fetchall()
        return {"verifier_error": self.worker_error,
                "parked": [{"unit": u, "reason": s[8:], "until": e} for u, s, e in parked],
                "jobs": [dict(zip(("id", "user", "model", "unit", "state", "phase", "created", "updated", "receipt"),
                                 (*r[:-1], json.loads(r[-1]) if r[-1] else None))) for r in rows],
                "leaderboard": [{"user": u, "model": m, "native_credits": n} for u, m, n in leaders]}

    def take(self):
        with self.store.lock, self.store.db:
            self.store.db.execute("BEGIN IMMEDIATE")
            row = self.store.db.execute("SELECT id,user,model,unit,base,patches,evidence FROM integration_jobs "
                                       "WHERE state='queued' ORDER BY created LIMIT 1").fetchone()
            if not row:
                return None
            self.store.db.execute("UPDATE integration_jobs SET state='verifying',phase='snapshot',updated=? WHERE id=?",
                                  (time.time(), row[0]))
        return dict(zip(("id", "user", "model", "unit", "base", "patches", "evidence"), row))

    def progress(self, identifier, phase):
        with self.store.lock, self.store.db:
            self.store.db.execute("UPDATE integration_jobs SET phase=?,updated=? WHERE id=? AND state='verifying'",
                                  (phase, time.time(), identifier))

    def finish(self, job, receipt, publish=None):
        """Called only by the server's verifier; no client result/credit endpoint."""
        with self.store.lock, self.store.db:
            self.store.db.execute("BEGIN IMMEDIATE")
            current = self.store.db.execute("SELECT state FROM integration_jobs WHERE id=?", (job["id"],)).fetchone()
            if not current or current[0] != "verifying":
                return False
            accepted = receipt.get("accepted") is True
            if accepted:
                for addr in receipt["new_distinct"]:
                    self.store.db.execute("INSERT OR IGNORE INTO integration_credit VALUES(?,?,?,?,?,?)",
                                         (CLIENT, addr, job["user"], job["model"], job["id"], time.time()))
                self.store.db.execute("INSERT INTO integration_accepted VALUES(?,?,?)",
                                      (job["id"], job["patches"], time.time()))
                if publish:
                    initial = json.loads(self.store.db.execute(
                        "SELECT value FROM integration_config WHERE key='initial_patches'").fetchone()[0])
                    accepted_patches = initial if isinstance(initial, list) else [initial] if initial else []
                    for row in self.store.db.execute("SELECT patches FROM integration_accepted ORDER BY ts,job"):
                        accepted_patches.append(json.loads(row[0]))
                    publish(accepted_patches)
                receipt["credits"] = self.store.db.execute("SELECT COUNT(*) FROM integration_credit WHERE job=?",
                                                           (job["id"],)).fetchone()[0]
            receipt.update({"job": job["id"], "user": job["user"], "model": job["model"], "unit": job["unit"]})
            self.store.db.execute("UPDATE integration_jobs SET state=?,phase=?,receipt=?,updated=? WHERE id=?",
                ("accepted" if accepted else "rejected", "complete", json.dumps(receipt), time.time(), job["id"]))
            claims = self.store.db.execute("SELECT claim_id FROM integration_jobs WHERE id=?", (job["id"],)).fetchone()[0]
            for identifier in json.loads(claims):
                self.store.db.execute("UPDATE integration_claims SET state=?,expires=? WHERE id=?",
                    ("released" if accepted else "claimed", 0 if accepted else time.time() + LEASE_SECONDS, identifier))
        self.catalog_key = None
        return True


def command(args):
    from roc import worker
    settings = worker.load_settings()
    server = args.server or settings.get("server") or worker.site_server()
    user = args.user or settings.get("user")
    if not server or not user:
        raise SystemExit("Run roc config --server URL --user NAME first")
    api = worker.Api(server, args.token or settings.get("native_token") or native_token() or settings.get("token"))
    directory = ROOT / "work" / "integration-client"
    generator = ROOT / "rebuild/2008-06/patches/make_rbxgs_client.py"
    overlay = generator.with_name("rbxgs-client.json")
    action = args.action

    if action == "invite":
        secret = native_token()
        if not secret:
            raise SystemExit("Run this on the configured native build server")
        print("Private helper invite; share only with trusted contributors:")
        print(secret)
        return

    if action == "next":
        base = api.call("/v1/integration/base")
        if not generator.exists() or not (ROOT / "tools/rbxgs/Client/App/include").exists():
            raise SystemExit("Native integration needs the rebuild recipes and your local rbxgs source tree; see docs/INTEGRATION.md")
        if hashlib.sha256(generator.read_bytes()).hexdigest() != base["generator"]:
            raise SystemExit("Generator differs from server; preserve local edits, sync/update before claiming")
        atomic_json(generator.with_name("native-promotions.json"), base["accepted"])
        subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True)
        if json.loads(overlay.read_text()) != base["overlay"]:
            raise SystemExit("Local overlay does not match the server baseline")
        identity_file = directory / "identity.json"
        if not identity_file.exists():
            atomic_json(identity_file, {"id": uuid.uuid4().hex})
        identity = json.loads(identity_file.read_text())["id"]
        result = api.call("/v1/integration/claim", {"user": user,
            "worker": user + "@" + socket.gethostname()[:40] + ":" + identity[:12],
            "count": args.count, "unit": args.unit})
        for claim in result["claims"]:
            folder = directory / "claims" / claim["id"]
            if not (folder / "packet.json").exists():
                atomic_json(folder / "packet.json", claim)
                if generator.exists():
                    (folder / "generator-base.py").write_bytes(generator.read_bytes())
                prompt = ("Integrate " + claim["unit"] + " in RoConstruct (2008-06).\n\n"
                    "Read CLAUDE.md, rebuild/2008-06/POLICY.md and patches/make_rbxgs_client.py.\n"
                    "Read packet.json: exact snippets are evidence, not structures to paste.\n"
                    "Find the real class/method; derive fields, signatures, constants and control flow from bytes.\n"
                    "Change real C++ only through make_rbxgs_client.py overlay patches. Cite addresses.\n"
                    "Never edit tools/, src/, clients/ or bounds.json. No padding structs or offset views.\n"
                    "If a whole-file redesign is needed, record the blocker and release the claim.\n"
                    "Record address-specific evidence in notes.md. Then submit with:\n"
                    "  roc integrate submit --claim " + claim["id"] + " --model ACTUAL_MODEL --evidence-file notes.md\n"
                    "The server independently rebuilds, checks M2/M4a/M5, size/base, ownership and distinct counts.\n"
                    "Only verified new distinct native bodies receive separate native credit; raw mining points stay unchanged.\n")
                (folder / "PROMPT.md").write_text(prompt, encoding="utf-8")
                (folder / "notes.md").write_text("Evidence addresses: " + " ".join(claim["addresses"][:5]) +
                                                "\n\nDescribe the byte-proven source correction here.\n", encoding="utf-8")
            print("%s: %d targets; claim %s\n  %s" % (claim["unit"], len(claim["addresses"]), claim["id"], folder))
        if not result["claims"]:
            print("No unclaimed eligible native classes available.")
        return

    if action in ("submit", "renew", "release"):
        paths = sorted((directory / "claims").glob("*/packet.json"))
        claims = [json.loads(p.read_text(encoding="utf-8")) for p in paths]
        states = {j["id"]: j["state"] for j in api.call("/v1/integration")["jobs"]}
        def active(c):
            marker = directory / "claims" / c["id"] / "job.json"
            return not marker.exists() or states.get(json.loads(marker.read_text())["id"]) == "rejected"
        claims = [c for c in claims if c["user"] == user and
                  (c["id"] == args.claim if args.claim else active(c))]
        if not claims or (len(claims) > 1 and not args.all):
            raise SystemExit("Select --claim ID, or --all for a batch of local claims")
        if action != "submit":
            for c in claims:
                print(c["id"], api.call("/v1/integration/" + action,
                    {"user": user, "claim": c["id"], "reason": args.reason}))
            return
        if not args.model or not args.evidence_file:
            raise SystemExit("Submit needs --model ACTUAL_MODEL (or human) and --evidence-file FILE")
        if len({c["base_revision"] for c in claims}) != 1:
            raise SystemExit("Batch claims have different bases; submit each baseline separately")
        subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True)
        patches = overlay_delta(claims[0]["baseline"]["overlay"], json.loads(overlay.read_text(encoding="utf-8")))
        body = {"user": user, "claims": [c["id"] for c in claims], "model": args.model,
                "base_revision": claims[0]["base_revision"], "patches": patches,
                "evidence": Path(args.evidence_file).read_text(encoding="utf-8")}
        if args.retry:
            if any(not (directory / "claims" / c["id"] / "job.json").exists() for c in claims):
                raise SystemExit("--retry needs an existing rejected batch")
            jobs = {json.loads((directory / "claims" / c["id"] / "job.json").read_text())["id"] for c in claims}
            if len(jobs) != 1:
                raise SystemExit("Retry one rejected batch at a time")
            body["retry_of"] = jobs.pop()
        result = api.call("/v1/integration/submit", body)
        folder = directory / "jobs" / result["id"]
        atomic_json(folder / "submission.json", body)
        (folder / "submitted-generator.py").write_bytes(generator.read_bytes())
        (folder / "generator-base.py").write_bytes(
            (directory / "claims" / claims[0]["id"] / "generator-base.py").read_bytes())
        for c in claims:
            atomic_json(directory / "claims" / c["id"] / "job.json", result)
        print("Queued %s (%d classes, one independent verification)" % (result["id"], len(claims)))
        if not args.wait:
            return
        args.id, action = result["id"], "watch"

    if action in ("status", "watch"):
        previous = None
        while True:
            result = api.call("/v1/integration" + ("?id=" + args.id if args.id else ""))
            phases = [(j["id"], j["state"], j["phase"]) for j in result["jobs"]]
            if phases != previous:
                for job in result["jobs"]:
                    print("%s %s | %s | %s" % (job["id"], job["state"], job["phase"], job["unit"]))
                    if job["receipt"]:
                        print(json.dumps(job["receipt"], indent=1))
                previous = phases
            if action == "status" or not result["jobs"] or all(j["state"] in ("accepted", "rejected") for j in result["jobs"]):
                print("Native credits:", json.dumps(result["leaderboard"]))
                return
            time.sleep(2)

    if action == "sync":
        base = api.call("/v1/integration/base")
        current = hashlib.sha256(generator.read_bytes()).hexdigest()
        if current != base["generator"]:
            statuses = {j["id"]: j for j in api.call("/v1/integration")["jobs"]}
            restored = False
            for path in (directory / "jobs").glob("*/submitted-generator.py"):
                if path.parent.name not in statuses or statuses[path.parent.name]["state"] != "accepted":
                    continue
                old = path.with_name("generator-base.py")
                if (hashlib.sha256(path.read_bytes()).hexdigest() == current
                        and hashlib.sha256(old.read_bytes()).hexdigest() == base["generator"]):
                    generator.write_bytes(old.read_bytes())
                    restored = True
                    break
            if not restored:
                raise SystemExit("Generator differs from server; preserve local edits and update before syncing")
        atomic_json(generator.with_name("native-promotions.json"), base["accepted"])
        subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True)
        if json.loads(overlay.read_text(encoding="utf-8")) != base["overlay"]:
            raise SystemExit("Local source/overlay baseline differs from server; update before claiming")
        print("Accepted overlays synced:", base["revision"])
