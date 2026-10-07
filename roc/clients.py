"""Client registry: clients/clients.json is shared, the exes stay local."""
import hashlib
import json
import re
import shutil
from collections import Counter
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parent.parent
REGISTRY = ROOT / "clients" / "clients.json"

# Rich header build number -> compiler that must be used to match.
COMPILERS = {50727: "VS2005 (cl 14.00.50727)", 21022: "VS2008 RTM (cl 15.00.21022)",
             30729: "VS2008 SP1 (cl 15.00.30729)"}


def load():
    return json.loads(REGISTRY.read_text()) if REGISTRY.exists() else {}


def save(reg):
    REGISTRY.write_text(json.dumps(reg, indent=2, sort_keys=True) + "\n")


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def compiler_build(exe):
    """Most-used tool build in the Rich header (objects compiled, not linker)."""
    rich = pefile.PE(str(exe), fast_load=True).parse_rich_header() or {}
    vals = rich.get("values", [])
    counts = Counter()
    for comp_id, count in zip(vals[::2], vals[1::2]):
        if comp_id & 0xffff:  # build 0 = import entries, not a tool
            counts[comp_id & 0xffff] += count
    return counts.most_common(1)[0][0] if counts else None


def built(exe):
    """Build date from the PE header timestamp, e.g. '2009-06-16'."""
    import time
    return time.strftime("%Y-%m-%d", time.gmtime(pefile.PE(str(exe), fast_load=True).FILE_HEADER.TimeDateStamp))


def exe_path(name, entry):
    return ROOT / "clients" / name / entry["exe"]


def checksum_ok(exe):
    """True if the PE header checksum still matches the file. The linker writes
    it; patched/modded exes almost never recompute it. None = no checksum set."""
    pe = pefile.PE(str(exe))
    stored = pe.OPTIONAL_HEADER.CheckSum
    return None if stored == 0 else stored == pe.generate_checksum()


def add(name, exe, allow_modified=False):
    if not re.match(r"^[A-Za-z0-9_-]{1,32}$", name):
        raise SystemExit("Client name: letters, digits, - and _ only (e.g. 2008-06)")
    exe = Path(exe).resolve()
    if not exe.is_file():
        raise SystemExit("No such file: %s" % exe)
    if checksum_ok(exe) is False and not allow_modified:
        raise SystemExit("%s looks modified (PE checksum mismatch). Use an unmodified client, "
                         "or pass --allow-modified if you are sure." % exe.name)
    dest = ROOT / "clients" / name / exe.name
    if exe != dest:
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(exe, dest)
    build = compiler_build(dest)
    entry = {"exe": exe.name, "sha256": sha256(dest), "compiler_build": build, "built": built(dest),
             "compiler": COMPILERS.get(build, "unknown build %s" % build)}
    reg = load()
    reg[name] = entry
    save(reg)
    return entry


def status(name, entry):
    path = exe_path(name, entry)
    if not path.exists():
        return "missing"
    return "ok" if sha256(path) == entry["sha256"] else "hash mismatch"
