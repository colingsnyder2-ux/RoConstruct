"""RBXGS WebService.dll (0.3.676, December 2007) as a name donor.

OpenRBX (Asphaltian/OpenRBX) recovered names for this DLL from the PDB Roblox
shipped in the same installer: tools/openrbx/reccmp/webservice-*.csv. Its
matched source carries `// FUNCTION: WEBSERVICE 0x...` markers.

A client function that is byte-identical (relocations masked, exe relocations
a subset of the donor's) to a named WebService function gets that PDB name as
a prompt hint. clients/donor.json stores only addresses and names, so workers
need neither the DLL nor OpenRBX; OpenRBX's GPL source is read from a local
checkout at prompt time, never copied into this repo.
"""
import csv
import functools
import json
import re
import shutil
import subprocess
from bisect import bisect_left
from pathlib import Path

from roc import clients, fingerprint, setup

ROOT = Path(__file__).resolve().parent.parent
OPENRBX = ROOT / "tools" / "openrbx"
TABLE = ROOT / "clients" / "donor.json"
MSI_URL = "https://archive.org/download/rbxgssetup/S3FileHandler_RBXGSSetup_0.3.676.0.msi"
MSI_SHA256 = "43935127301bf4189b2cec13bceef23bc32538bd4cd3fed94b14b1143a38e5e0"
DLL_SHA256 = "5e9c6b82605fc8429c5fc5f682f2d7f98b55b73d993dfba58437365754410e2f"
DLL_KEY = "_E338FA13480D4C3C3257E3F2D3E3A98D"  # File-table key of WebService.dll in that MSI
DLL = ROOT / "tools" / "rbxgs_msi" / "WebService.dll"
MARKER = re.compile(r"^//\s*(FUNCTION|STUB|TEMPLATE|SYNTHETIC|LIBRARY):\s*WEBSERVICE\s+0x([0-9a-fA-F]+)")


def fetch():
    """WebService.dll, extracted from the hash-pinned installer. msiexec /a fails on
    this MSI (IIS custom actions), so the cab stream is pulled out directly."""
    if DLL.exists() and setup.sha256(DLL) == DLL_SHA256:
        return DLL
    msi = setup.download(MSI_URL, DLL.with_name("rbxgs676.msi"))
    setup.require_sha256(msi, MSI_SHA256)
    try:
        import olefile
    except ImportError:
        raise SystemExit("Extracting WebService.dll needs olefile: python -m pip install olefile")
    ole = olefile.OleFileIO(str(msi))
    cab = DLL.with_name("rbxgs676.cab")
    for entry in ole.listdir():
        data = ole.openstream(entry).read()
        if data[:4] == b"MSCF":
            cab.write_bytes(data)
            break
    else:
        raise SystemExit("no cabinet inside %s" % msi.name)
    out = DLL.parent / DLL_KEY
    if setup.WINDOWS:
        subprocess.run(["expand.exe", str(cab), "-F:" + DLL_KEY, str(DLL.parent)], check=True,
                       capture_output=True)
    elif shutil.which("cabextract"):
        subprocess.run(["cabextract", "-q", "-F", DLL_KEY, "-d", str(DLL.parent), str(cab)], check=True)
    else:
        raise SystemExit("Install cabextract to unpack %s" % cab.name)
    out.replace(DLL)
    cab.unlink()
    setup.require_sha256(DLL, DLL_SHA256)
    return DLL


def names(folder=None):
    """{donor va: (csv kind, symbol)} from OpenRBX's PDB-derived CSVs."""
    out = {}
    for path in sorted((folder or OPENRBX / "reccmp").glob("webservice-*.csv")):
        kind = path.stem.split("-", 1)[1]
        with open(path, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                sym = row.get("symbol") or row.get("name")
                if sym and row.get("type") in ("library", "stub", None):
                    out[int(row["address"], 16)] = (kind, sym)
    return out


def annotations(root=None):
    """{donor va: "path:line"} for every OpenRBX source marker."""
    root = root or OPENRBX
    out = {}
    for path in sorted(root.rglob("*.cpp")) + sorted(root.rglob("*.h")):
        try:
            lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
        except OSError:
            continue
        for i, line in enumerate(lines, 1):
            m = MARKER.match(line.strip())
            if m:
                out.setdefault(int(m.group(2), 16), "%s:%d" % (path.relative_to(root).as_posix(), i))
    return out


def donor_functions(dll, folder=None):
    """{size: [(va, code, relocs)]} for every function OpenRBX sized."""
    import pefile
    from roc.analyze import reloc_sites
    pe = pefile.PE(str(dll))
    base, image = pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image()
    relocs = sorted(reloc_sites(pe))
    out = {}
    with open((folder or OPENRBX / "reccmp") / "webservice-function-size.csv", encoding="utf-8") as f:
        for row in csv.DictReader(f):
            va, size = int(row["address"], 16), int(row["size"])
            if size < 6:  # a lone ret matches everywhere
                continue
            lo, hi = bisect_left(relocs, va), bisect_left(relocs, va + size)
            out.setdefault(size, []).append((va, bytes(image[va - base:va - base + size]),
                                             [r - va for r in relocs[lo:hi]]))
    return out


def build(targets, log=print):
    """Write clients/donor.json: {client: {addr: [donor va, kind, symbol, openrbx path:line]}}."""
    pool, named, marked = donor_functions(fetch()), names(), annotations()
    table = json.loads(TABLE.read_text()) if TABLE.exists() else {}
    for client in targets:
        t, hits = fingerprint.Target(client), {}
        for size, addrs in t.index.items():
            for va, code, rel in pool.get(size, ()):
                if va not in named and va not in marked:
                    continue
                for addr in addrs:
                    if addr not in hits and t.same(addr, code, rel) is not None:
                        kind, sym = named.get(va, ("source", ""))
                        hits[addr] = ["%08x" % va, kind, sym, marked.get(va, "")]
        table[client] = dict(sorted(hits.items()))
        log("%s: %d functions identical to a named WebService.dll function" % (client, len(hits)))
    TABLE.write_text(json.dumps(table, indent=0, sort_keys=True) + "\n")
    _table.cache_clear()
    hint.cache_clear()
    return table


@functools.lru_cache(maxsize=None)
def _table():
    try:
        return json.loads(TABLE.read_text())
    except (OSError, ValueError):
        return {}


def source_at(where, limit=60):
    """The OpenRBX source after a marker, up to the next marker (local checkout only)."""
    path, _, line = where.rpartition(":")
    try:
        lines = (OPENRBX / path).read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return ""
    body = []
    for text in lines[int(line):int(line) + limit]:
        if MARKER.match(text.strip()):
            break
        body.append(text)
    return "\n".join(body).strip()


@functools.lru_cache(maxsize=4096)
def hint(client, addr):
    """{"donor", "kind", "symbol", "path", "source"} for an identical donor function, or None."""
    row = _table().get(client, {}).get(addr)
    if not row:
        return None
    va, kind, sym, where = row
    return {"donor": va, "kind": kind, "symbol": sym, "path": where,
            "source": source_at(where) if where else ""}


def default_targets():
    return [n for n, e in sorted(clients.load().items())
            if clients.status(n, e) == "ok" and (ROOT / "work" / n / "functions.jsonl").exists()]
