"""Client samples: fetch them into clients/<name>/, verify against the registry, never commit.

clients/clients.json is the registry: exe name, SHA-256, compiler build.
clients/sources.json is provenance: where each client comes from.

    drive   per-file Google Drive ids per client. Primary: pulls exactly the one
            client you asked for, so a new helper never downloads a whole archive
            of builds they will not use.
    bundle  one clients.zip holding every registered client, keyed by directory
            name. Fallback for when a client is missing from the Drive manifest or
            Drive is unreachable. Cached at work/clients.zip, hash-checked.

    roc client-fetch <name>        fetch one client (or 'all')
    roc client-sources <folder>    index a public Drive folder into the drive section
    roc client-sources --bundle    record a different clients.zip

Every fetch is verified against clients.json before it is used, whatever the
source. Stdlib only, so install.cmd's dependency list (pefile, capstone) does not
change. The binaries stay local: .gitignore excludes clients/* except the json files.
"""
import html
import json
import os
import re
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
import zipfile
from pathlib import Path

from roc import clients

ROOT = Path(__file__).resolve().parent.parent
SOURCES = ROOT / "clients" / "sources.json"
CACHE = ROOT / "work" / "clients.zip"

UA = ("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
      "(KHTML, like Gecko) Chrome/126.0 Safari/537.36")
CHUNK = 1 << 18
TIMEOUT = 120
RETRIES = 3

FOLDER_VIEW = "https://drive.google.com/embeddedfolderview?id={id}#list"
DRIVE_DIRECT = "https://drive.google.com/uc?export=download&id={id}"

ENTRY_ID = re.compile(r'id="entry-([0-9A-Za-z_-]{20,50})"')
ENTRY_TITLE = re.compile(r'<div class="flip-entry-title">([^<]*)</div>')
ENTRY_IS_DIR = re.compile(r'<a href="[^"]*?/folders/([0-9A-Za-z_-]{20,50})"')
FORM_ACTION = re.compile(r'<form[^>]*action="([^"]+)"', re.I)
FORM_FIELD = re.compile(r'<input[^>]*name="([^"]+)"[^>]*value="([^"]*)"', re.I)
MONTHS = {"jan": 1, "feb": 2, "mar": 3, "apr": 4, "may": 5, "jun": 6,
          "jul": 7, "aug": 8, "sep": 9, "oct": 10, "nov": 11, "dec": 12}
SKIP_DIRS = {"content", "cache", "styles", "logs", "assets", "overlay", "minecraft"}
VERSION_DIR = re.compile(r"^version-[0-9a-f]{4,}$", re.I)


class FetchError(Exception):
    pass


# ---------- sources.json ----------

def load_sources():
    return json.loads(SOURCES.read_text()) if SOURCES.exists() else {"bundle": None, "drive": {}}


def save_sources(data):
    SOURCES.parent.mkdir(parents=True, exist_ok=True)
    SOURCES.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")


def _opener():
    return urllib.request.build_opener()


def _get(url, referer=None):
    request = urllib.request.Request(url)
    request.add_header("User-Agent", UA)
    request.add_header("Accept-Language", "en-US,en;q=0.9")
    if referer:
        request.add_header("Referer", referer)
    return _opener().open(request, timeout=TIMEOUT)


def _human(n):
    value = float(n)
    for unit in ("B", "KB", "MB", "GB"):
        if value < 1024 or unit == "GB":
            return "%d B" % n if unit == "B" else "%.1f %s" % (value, unit)
        value /= 1024


def _progress(done, total, start, force=False):
    now = time.time()
    if not force and now - start < 0.2 and done:
        return
    rate = done / max(now - start, 0.001)
    print("\r  %s / %s  %s/s   " % (_human(done), _human(total) if total else "?", _human(rate)),
          end="", file=sys.stderr, flush=True)


# ---------- downloading ----------

def _confirm_url(body):
    """Files over ~100 MB answer with an HTML form; the real URL is action + fields."""
    action = FORM_ACTION.search(body)
    fields = {name: html.unescape(value) for name, value in FORM_FIELD.findall(body)}
    if not action or not fields:
        return None
    target = html.unescape(action.group(1))
    if target.startswith("/"):
        target = "https://drive.google.com" + target
    return target + ("&" if "?" in target else "?") + urllib.parse.urlencode(fields)


def download(url, dest):
    """Stream url to dest. Handles Drive's confirm form and leaves no partial file."""
    dest.parent.mkdir(parents=True, exist_ok=True)
    tmp = dest.with_suffix(dest.suffix + ".part")
    for attempt in range(1, RETRIES + 1):
        done, start, shown = 0, time.time(), 0.0
        try:
            response = _get(url)
            with response:
                kind = response.headers.get("Content-Type", "")
                if "text/html" in kind:
                    body = response.read().decode("utf-8", "replace")
                    real = _confirm_url(body)
                    if not real:
                        raise FetchError("drive returned a sign-in page (%s is not shared publicly)" % url)
                    response = _get(real)
                with response:
                    total = int(response.headers.get("Content-Length") or 0)
                    if dest.exists() and total and dest.stat().st_size == total:
                        return dest  # already complete
                    with tmp.open("wb") as out:
                        while True:
                            block = response.read(CHUNK)
                            if not block:
                                break
                            out.write(block)
                            done += len(block)
                            now = time.time()
                            if now - shown > 0.25 or not shown:
                                _progress(done, total, start)
                                shown = now
                    os.replace(tmp, dest)
                    if shown:
                        print("", file=sys.stderr)
                    return dest
        except FetchError:
            tmp.unlink(missing_ok=True)
            raise
        except (urllib.error.URLError, OSError) as error:
            tmp.unlink(missing_ok=True)
            if attempt == RETRIES:
                raise FetchError("%s after %d tries: %s" % (dest.name, RETRIES, error))
        time.sleep(1.5 * attempt)
    raise FetchError("%s: gave up" % dest.name)


# ---------- verification ----------

def verify(name, entry):
    """Registry checks for a client whose files are on disk."""
    exe = clients.exe_path(name, entry)
    if not exe.is_file():
        return "missing"
    if clients.sha256(exe) != entry["sha256"]:
        return "hash mismatch"
    if clients.checksum_ok(exe) is False:
        return "modified (PE checksum mismatch)"
    return "ok"


def _need(name):
    entry = clients.load().get(name)
    if not entry:
        raise FetchError("%s is not in clients/clients.json" % name)
    return entry


# ---------- bundle path ----------

def _safe_member(name):
    """Refuse absolute paths and .. so a crafted archive cannot write outside clients/."""
    if name.startswith("/") or name.startswith("\\") or re.match(r"^[A-Za-z]:", name):
        raise FetchError("archive has an absolute path: %s" % name)
    if ".." in Path(name).parts:
        raise FetchError("archive tries to escape its directory: %s" % name)
    return name


def _bundle_archive(info):
    """Cached zip matching the manifest, downloading it if needed. Verifies sha256."""
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    want = info.get("sha256")
    if CACHE.is_file() and want and clients.sha256(CACHE) == want:
        return CACHE
    if not info.get("url"):
        raise FetchError("clients/sources.json has no bundle url")
    if not info.get("sha256"):
        raise FetchError("clients/sources.json has no bundle sha256: refusing an unverified download")
    print("downloading clients.zip (%.1f MB)..." % (info.get("size", 0) / 1048576))
    download(info["url"], CACHE)
    got = clients.sha256(CACHE)
    if got != info["sha256"]:
        CACHE.unlink(missing_ok=True)
        raise FetchError("archive hash mismatch: expected %s, got %s" % (info["sha256"], got))
    return CACHE


def from_bundle(name, entry):
    """Unpack clients/<name>/ out of the cached archive. True if the client was in it."""
    info = load_sources().get("bundle")
    if not info:
        return False
    archive = _bundle_archive(info)
    with zipfile.ZipFile(archive) as zf:
        names = zf.namelist()
        members = [n for n in names if n == "%s/" % name or n.startswith("%s/" % name)]
        if not members:
            return False
        print("%-8s unpacking %d file(s) from clients.zip" % (name, len(members)))
        for member in members:
            if member.endswith("/"):
                continue
            dest = clients.ROOT / "clients" / name / Path(_safe_member(member[len(name) + 1:]))
            dest.parent.mkdir(parents=True, exist_ok=True)
            with zf.open(member) as src, dest.open("wb") as out:
                while True:
                    block = src.read(CHUNK)
                    if not block:
                        break
                    out.write(block)
    return True


# ---------- drive fallback ----------

def list_folder(folder_id):
    """(id, name, is_dir) for one Drive folder, from the public embedded listing."""
    body = _get(FOLDER_VIEW.format(id=folder_id)).read().decode("utf-8", "replace")
    out = []
    for chunk in body.split('<div class="flip-entry"')[1:]:
        found = ENTRY_ID.search(chunk)
        if not found:
            continue
        title = ENTRY_TITLE.search(chunk)
        name = html.unescape(title.group(1)).strip() if title else found.group(1)
        folder = ENTRY_IS_DIR.search(chunk)
        out.append((found.group(1), name, bool(folder) and folder.group(1) == found.group(1)))
    return out


def _slot_for(parts, extra=()):
    """Drive path -> (client name, build folder depth), or (None, 0).

    Drive:  2008/6.2008/June 20 (0.5.x)/version-<hash>/RobloxApp.exe
    Ours:  2008-06

    Several different builds live under one month (2008/6.2008 holds more than one
    dated folder), so the month only narrows it down. The build folder is the last
    path part before the files start, which is what we key candidate builds on.

    `extra` lets a caller index months that are not registered yet, so a client can be
    discovered and fetched before anyone commits it to clients.json.
    """
    reg = clients.load()
    year = re.search(r"(20\d\d)", parts[0]) if parts else None
    if not year:
        return None, 0
    month = None
    for part in parts[1:3]:
        numeric = re.match(r"^(\d{1,2})[.\-_]", part)
        if numeric and 1 <= int(numeric.group(1)) <= 12:
            month = int(numeric.group(1))
            break
        word = re.search(r"(%s)" % "|".join(MONTHS), part, re.I)
        if word:
            month = MONTHS[word.group(1).lower()]
            break
    if month is None:
        return None, 0
    slot = "%s-%02d" % (year.group(1), month)
    known = set(reg) | set(extra)
    return (slot, len(parts)) if slot in known else (None, 0)


def _exe_name_for(slot, reg):
    """Exe name for a slot. Registered clients know their own; for a month being
    discovered the era decides it: Roblox.exe up to 2008, RobloxApp.exe from 2009."""
    if slot in reg:
        return reg[slot]["exe"]
    year = int(slot.split("-")[0])
    return "Roblox.exe" if year <= 2008 else "RobloxApp.exe"


def index_drive(folder_id, dry_run=False, extra_slots=()):
    """Walk a public Drive folder, fill the drive section of clients/sources.json.

    Every build found for a month is kept as its own candidate. Which one is the
    registered build is decided at fetch time by hashing the exe, not by guessing
    from the folder name.

    `extra_slots` names months to record even though they are not in clients.json, so a
    client can be fetched and registered before it is committed.
    """
    reg = clients.load()
    found = {}

    def walk(current, parts, depth=0):
        if depth > 5:
            return
        for fid, name, is_dir in list_folder(current):
            clean = name.strip()
            if is_dir:
                if clean.lower() in SKIP_DIRS or VERSION_DIR.match(clean):
                    if not is_dir or clean.lower() in SKIP_DIRS:
                        continue
                walk(fid, parts + [clean], depth + 1)
                continue
            slot, build_depth = _slot_for(parts, extra_slots)
            if not slot:
                continue
            rel = "/".join([p for p in parts[build_depth:] if not VERSION_DIR.match(p)] + [clean])
            label = "/".join(parts[1:]) or parts[0]
            builds = found.setdefault(slot, {})
            build = builds.setdefault(label, {"files": []})
            build["files"].append({"path": rel, "id": fid})

    walk(folder_id, [])
    out = {}
    for slot, builds in found.items():
        rows = []
        exe_name = _exe_name_for(slot, reg)
        for label in sorted(builds):
            files = sorted(builds[label]["files"], key=lambda f: f["path"])
            if not any(f["path"].split("/")[-1] == exe_name for f in files):
                continue  # a build without the client exe is not this client
            rows.append({"label": label, "files": files})
        if rows:
            out[slot] = {"builds": rows}
    found = out

    data = load_sources()
    if not dry_run:
        data["drive"] = found
        save_sources(data)
    print("drive: %d client(s)%s" % (len(found), "" if dry_run else " -> clients/sources.json"))
    for slot in sorted(found):
        builds = found[slot]["builds"]
        print("%-8s %d build(s), %d file(s)" % (slot, len(builds), sum(len(b["files"]) for b in builds)))
        for build in builds:
            print("         %s" % build["label"])
    return found


def set_bundle(zip_path):
    """Point the manifest at a local clients.zip: record its url note, size, and hash."""
    path = Path(zip_path).resolve()
    if not path.is_file():
        raise FetchError("No such file: %s" % path)
    with zipfile.ZipFile(path) as zf:
        slots = sorted({n.split("/")[0] for n in zf.namelist() if "/" in n})
    data = load_sources()
    bundle = dict(data.get("bundle") or {})
    bundle.setdefault("url", "")
    bundle["size"] = path.stat().st_size
    bundle["sha256"] = clients.sha256(path)
    bundle["slots"] = [s for s in slots if s in clients.load()]
    data["bundle"] = bundle
    save_sources(data)
    print("bundle: %d bytes, sha256 %s" % (bundle["size"], bundle["sha256"]))
    print("slots in the archive: %s" % (", ".join(bundle["slots"]) or "none registered"))
    return bundle


# ---------- the command ----------

def _pull_files(name, files, quiet):
    """Download a file list into clients/<name>/, creating folders as needed.

    Non-exe files that Drive will not serve are reported and skipped rather than
    failing the whole client; a missing exe always fails.
    """
    target = clients.ROOT / "clients" / name
    skipped = []
    for item in files:
        dest = target / item["path"]
        if dest.is_file() and (not item.get("size") or dest.stat().st_size == item["size"]):
            continue
        try:
            if not quiet:
                print("   %s" % item["path"])
            download(DRIVE_DIRECT.format(id=item["id"]), dest)
        except FetchError as error:
            if dest.name.lower().endswith(".exe"):
                raise
            skipped.append("%s (%s)" % (item["path"], str(error).split(":")[-1].strip()))
    for note in skipped:
        print("%-8s skipped %s" % (name, note), file=sys.stderr)
    return skipped


def from_drive(name, entry, quiet=False):
    """Pull one client from Drive, choosing the build whose exe matches the registry.

    A month folder on Drive can hold several different builds, so the exe is
    fetched first and hashed; the rest of that build follows only once it matches.
    """
    slot = load_sources().get("drive", {}).get(name)
    if not slot:
        raise FetchError("no Drive files for %s in clients/sources.json" % name)
    builds = slot["builds"]
    exe_name = entry["exe"]
    target = clients.ROOT / "clients" / name
    wanted = entry["sha256"]

    order = _preferred_build(name)
    builds = sorted(builds, key=lambda b: (b["label"] != order, b["label"]))
    if not quiet:
        print("%-8s %d Drive build(s) to try" % (name, len(builds)))

    problems = []
    for build in builds:
        exe_item = next((f for f in build["files"] if f["path"].split("/")[-1] == exe_name), None)
        if not exe_item:
            continue
        exe_dest = target / exe_item["path"]
        try:
            if not (exe_dest.is_file() and clients.sha256(exe_dest) == wanted):
                if not quiet:
                    print("   %s  [%s]" % (exe_name, build["label"]))
                download(DRIVE_DIRECT.format(id=exe_item["id"]), exe_dest)
            if clients.sha256(exe_dest) != wanted:
                problems.append("%s: different build" % build["label"])
                exe_dest.unlink(missing_ok=True)
                continue
        except FetchError as error:
            problems.append("%s: %s" % (build["label"], str(error).split(":")[-1].strip()))
            continue

        if not quiet:
            print("%-8s matched build %s, fetching the rest" % (name, build["label"]))
        _pull_files(name, [f for f in build["files"] if f is not exe_item], quiet)
        _remember_build(name, build["label"])
        return build["label"]
    raise FetchError("no Drive build matches %s (%s)" % (name, "; ".join(problems) or "none had the exe"))


def _preferred_build(name):
    """Label of the build that worked last time, so we skip re-probing."""
    path = ROOT / "work" / name / "drive_build.txt"
    return path.read_text().strip() if path.exists() else None


def _remember_build(name, label):
    path = ROOT / "work" / name / "drive_build.txt"
    try:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(label + "\n")
    except OSError:
        pass


def fetch(name, quiet=False):
    """Get one client onto disk and verified. Drive first, clients.zip as fallback."""
    entry = _need(name)
    if verify(name, entry) == "ok":
        if not quiet:
            print("%-8s already here, hash matches the registry" % name)
        return "ok"

    problems = []
    try:
        label = from_drive(name, entry, quiet)
        state = verify(name, entry)
        if state == "ok":
            if not quiet:
                print("%-8s ok from Drive (%s), hash matches the registry" % (name, label))
            return "ok"
        problems.append("drive: %s" % state)
    except FetchError as error:
        problems.append("drive: %s" % error)

    try:
        if from_bundle(name, entry):
            state = verify(name, entry)
            if state == "ok":
                if not quiet:
                    print("%-8s ok from clients.zip, hash matches the registry" % name)
                return "ok"
            problems.append("clients.zip: %s" % state)
        else:
            problems.append("clients.zip: %s is not in the archive" % name)
    except (FetchError, zipfile.BadZipFile) as error:
        problems.append("clients.zip: %s" % error)

    detail = "; ".join(problems) if problems else "no sources in clients/sources.json"
    raise FetchError("%s could not be fetched (%s). Supply your own copy at clients/%s/%s"
                     % (name, detail, name, entry["exe"]))


def ensure(name):
    """Called before work starts on a client: fetch it if it is not verified on disk."""
    entry = clients.load().get(name)
    if not entry or verify(name, entry) == "ok":
        return True
    sources = load_sources()
    if not sources.get("bundle") and name not in sources.get("drive", {}):
        return False
    try:
        fetch(name)
        return True
    except FetchError as error:
        print("%s: %s" % (name, error), file=sys.stderr)
        return False
