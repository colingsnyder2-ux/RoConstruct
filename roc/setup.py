"""Install everything a contributor needs, without admin rights.

pip packages, optional Ollama/Docker via winget, and the old MSVC compilers:
downloaded from archive.org, checked (Microsoft signature or pinned SHA-1),
and unpacked into tools/ instead of being installed.

On Windows that is the whole story. On Linux the same MSI/ISO bundles are
unpacked with msitools/cabextract/7z, and the old cl.exe is run through Wine
with a private prefix under tools/wineprefix, so the matching pipeline works
unchanged.
"""
import functools
import hashlib
import json
import os
import platform
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
DL = TOOLS / "dl"
STATE = TOOLS / "install-state.json"
WINDOWS = os.name == "nt"
WINE_PREFIX = TOOLS / "wineprefix"
PF86 = Path(r"C:\Program Files (x86)")
LOCAL = Path(os.environ.get("LOCALAPPDATA", ""))
CL_PATHS = [PF86 / r"Microsoft Visual Studio 8\VC\bin\cl.exe",
            PF86 / r"Microsoft Visual Studio 9.0\VC\bin\cl.exe",
            LOCAL / r"Programs\Common\Microsoft\Visual C++ for Python\9.0\VC\bin\cl.exe",
            PF86 / r"Common Files\Microsoft\Visual C++ for Python\9.0\VC\bin\cl.exe"]
NAMES = {50727: "VS2005 (cl 14.00.50727)", 21022: "VS2008 RTM (cl 15.00.21022)",
         30729: "VS2008 SP1 (cl 15.00.30729)"}
VCPY_URL = ("https://web.archive.org/web/20210106040224id_/https://download.microsoft.com/download/"
            "7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi")
VCPY_SHA256 = "070474db76a2e625513a5835df4595df9324d820f9cc97eab2a596dcbc2f5cbf"
VS2008_URL = "https://archive.org/download/VisualStudioExpressEditionsDVD2007/DVD1.ISO"
VS2008_SHA1 = "65ebdd88136275768d778d1795d41a7fcc12a47e"
VS2005_URL = "https://archive.org/download/MS_VisualCPPExpress-2005/Micorosft_Visual_C%2B%2B_2005_Express.iso"
VS2005_SHA1 = "1ae44e4eaf8c61c3a39e573fd6efd9889e940529"

# winget installs these under LOCALAPPDATA and appends them to the *user* PATH in the
# registry. The process running install.cmd already has its PATH, so which() cannot
# see them until we re-read it. That mismatch is why a fresh install looked like it
# had failed and asked again on every run.
EXTRA_PATHS = [LOCAL / r"Programs\Ollama",
               LOCAL / r"Microsoft\WinGet\Links",
               LOCAL / r"Programs\Docker\Docker\resources\bin",
               Path(r"C:\Program Files\Docker\Docker\resources\bin"),
               LOCAL / r"Programs\Python\Python312\Scripts"]
OLLAMA_API = "http://127.0.0.1:11434/api/tags"

# The PATH this process started with, kept so refresh_path can rebuild instead of
# accumulating. Prepending to the live PATH on every call grows it without bound, and
# Windows caps a single environment variable at 32767 characters - after ~20 calls
# every cl.exe invocation died with "the environment variable is longer than 32767
# characters", silently failing every compile in a worker run.
_ORIGINAL_PATH = os.environ.get("PATH", "")


# ---------- Wine (Linux) ----------

def wine_exe():
    """The Wine loader, or None. `wine` first: the old cl.exe is 32-bit.

    ROC_WINE overrides it, which is how ARM boards run the x86 cl.exe: point it
    at a wrapper that starts Box86/FEX with Wine (or at an x86 Wine binary).
    """
    override = os.environ.get("ROC_WINE")
    if override:
        return shutil.which(override) or override
    for name in ("wine", "wine64"):
        found = shutil.which(name)
        if found:
            return found
    return None


def to_wine_path(path):
    """A Unix path as a Windows path Wine can hand to cl.exe (Z: maps to /)."""
    text = str(path)
    if WINDOWS:
        return text
    drive = os.environ.get("ROC_WINE_DRIVE", "z:")
    if text.startswith("/"):
        return drive + text.replace("/", "\\")
    return text.replace("/", "\\")


def wine_env(extra=None):
    """Environment for Windows programs run through Wine: a private prefix,
    no debug noise, and Wine's own popups suppressed."""
    env = dict(os.environ)
    env["WINEPREFIX"] = str(WINE_PREFIX)
    env["WINEDEBUG"] = "-all"
    env.setdefault("WINEDLLOVERRIDES", "mscoree,mshtml=")
    if extra:
        env.update(extra)
    return env


def ensure_wine_prefix(log=print):
    """Create tools/wineprefix once. Returns False when Wine is missing."""
    if WINDOWS:
        return True
    wine = wine_exe()
    if not wine:
        return False
    if (WINE_PREFIX / "system.reg").exists():
        return True
    log("Preparing the Wine prefix (first run; takes a minute)...")
    WINE_PREFIX.mkdir(parents=True, exist_ok=True)
    try:
        subprocess.run([wine, "wineboot", "-u"], env=wine_env(),
                       capture_output=True, timeout=600)
    except (OSError, subprocess.TimeoutExpired) as error:
        log("Wine prefix setup failed: %s" % error)
        return False
    return (WINE_PREFIX / "system.reg").exists()


def refresh_path():
    """Re-read PATH from the registry and add the usual install dirs.

    winget does not update the PATH of the process that started it, so a program it
    just installed stays invisible to shutil.which until this runs.

    Idempotent: rebuilt from the original PATH each call, never appended to itself.
    Windows-only: Linux installs already land on PATH.
    """
    if not WINDOWS:
        return os.environ.get("PATH", "")
    import winreg
    parts = []
    for hive, key in ((winreg.HKEY_CURRENT_USER, "Environment"),
                      (winreg.HKEY_LOCAL_MACHINE,
                       r"SYSTEM\CurrentControlSet\Control\Session Manager\Environment")):
        try:
            with winreg.OpenKey(hive, key) as k:
                value, _ = winreg.QueryValueEx(k, "PATH")
                if value:
                    parts.append(value)
        except OSError:
            pass
    seen, ordered = set(), []
    for part in [str(p) for p in EXTRA_PATHS if p.is_dir()] + parts + [_ORIGINAL_PATH]:
        for one in part.split(os.pathsep):
            key = one.strip().rstrip("\\").lower()
            if one and key not in seen:
                seen.add(key)
                ordered.append(one)
    os.environ["PATH"] = os.pathsep.join(ordered)
    return os.environ["PATH"]


def find_exe(name):
    """Locate a program on PATH, in the registry PATH, or in a known install dir."""
    found = shutil.which(name)
    if found:
        return found
    if not WINDOWS:
        return None  # the extra dirs below are Windows install locations
    for folder in EXTRA_PATHS:
        candidate = folder / (name + ".exe")
        if candidate.is_file():
            return str(candidate)
    for var in ("ProgramFiles", "ProgramFiles(x86)", "LOCALAPPDATA"):
        base = os.environ.get(var)
        if not base:
            continue
        for pattern in (r"Programs\Ollama", r"Ollama", r"Docker\Docker\resources\bin"):
            candidate = Path(base) / pattern / (name + ".exe")
            if candidate.is_file():
                return str(candidate)
    return None


def wait_for_http(url, timeout=60, interval=2):
    """Poll until the endpoint answers. True if it came up in time."""
    deadline = time.time() + timeout
    while time.time() < deadline:
        try:
            with urllib.request.urlopen(url, timeout=4):
                return True
        except OSError:
            time.sleep(interval)
    return False


def start_ollama(exe):
    """Bring the Ollama server up if the installer did not start it."""
    print("Starting the Ollama server...")
    subprocess.Popen([exe, "serve"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                     creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    return wait_for_http(OLLAMA_API, timeout=90)


def ensure_ollama(exe):
    """Ollama is only usable once its HTTP API answers: start it if needed, then report."""
    if not wait_for_http(OLLAMA_API, timeout=3, interval=1) and not start_ollama(exe):
        raise SystemExit("Ollama is installed but its server did not start.\n"
                         "Start it from the Start menu, then run this again.")
    try:
        with urllib.request.urlopen(OLLAMA_API, timeout=15) as r:
            return json.loads(r.read()).get("models", [])
    except (OSError, ValueError):
        return []


@functools.lru_cache(maxsize=16)
def _cached_cl_env(cl):
    """Environment that lets an old cl.exe find its DLLs and headers.

    Windows passes an inherited PATH. Under Wine the Windows program needs
    Windows-style WINEPATH/INCLUDE values instead, because a Unix PATH inside
    the prefix means nothing to cl.exe.
    """
    cl = Path(cl)
    ide = cl.parents[2] / "Common7" / "IDE"
    inc = cl.parents[1] / "include"
    if not WINDOWS:
        winpath = [to_wine_path(cl.parent)]
        if ide.is_dir():
            winpath.append(to_wine_path(ide))
        return wine_env({"WINEPATH": ";".join(winpath),
                         "INCLUDE": to_wine_path(inc) if inc.exists() else ""})
    env = dict(os.environ)
    env["PATH"] = os.pathsep.join([str(cl.parent), str(ide), env.get("PATH", "")])
    env["INCLUDE"] = str(inc) if inc.exists() else ""
    return env


def cl_env(cl):
    # Callers add per-invocation include/define values; never share that mutation.
    return dict(_cached_cl_env(str(cl)))


def cl_command(cl):
    """How to run this cl.exe: directly on Windows, through Wine on Linux."""
    if WINDOWS:
        return [str(cl)]
    wine = wine_exe()
    if not wine:
        raise SystemExit("The old cl.exe needs Wine on Linux. Install it first "
                         "(Arch: sudo pacman -S wine; Debian/Ubuntu: sudo apt install wine wine32).")
    return [wine, str(cl)]


def cl_path(path):
    """A path as an argument cl.exe understands: plain on Windows, Z:\\ under Wine.

    A bare Unix path starts with '/', which cl.exe reads as an option name
    ('cl : Command line warning D9002'), so paths must be converted first.
    """
    return str(path) if WINDOWS else to_wine_path(path)


def compiler_ready():
    """True when a cl.exe could run at all: always on Windows, Wine elsewhere."""
    return WINDOWS or wine_exe() is not None


@functools.lru_cache(maxsize=None)
def compilers():
    """{build: cl.exe path} for every old MSVC found."""
    paths = CL_PATHS + sorted(TOOLS.glob("*/**/VC/bin/cl.exe"))
    paths += [Path(p) for p in os.environ.get("ROC_CL", "").split(os.pathsep) if p]
    if not compiler_ready():
        return {}
    found = {}
    timeout = 30 if WINDOWS else 180  # the first Wine run initialises the prefix
    for cl in paths:
        if not cl.exists():
            continue
        try:
            banner = subprocess.run(cl_command(cl), capture_output=True, text=True,
                                    cwd=cl.parent, env=cl_env(cl), timeout=timeout).stderr
        except (OSError, subprocess.TimeoutExpired):
            continue
        m = re.search(r"Version \d+\.\d+\.(\d+)", banner)
        if m:
            found.setdefault(int(m.group(1)), str(cl))
    return found


# ---------- downloads ----------

def download(url, dest, tries=6):
    """Download with resume (HTTP Range) and retries: archive.org drops big transfers."""
    if dest.exists() and dest.stat().st_size > 0:
        return dest
    dest.parent.mkdir(parents=True, exist_ok=True)
    part = dest.with_suffix(dest.suffix + ".part")
    print("Downloading %s ..." % dest.name)
    for attempt in range(1, tries + 1):
        have = part.stat().st_size if part.exists() else 0
        req = urllib.request.Request(url, headers={"Range": "bytes=%d-" % have} if have else {})
        try:
            with urllib.request.urlopen(req, timeout=120) as r:
                if have and r.status != 206:  # server ignored Range: start over
                    have = 0
                total = have + int(r.headers.get("Content-Length") or 0)
                with open(part, "ab" if have else "wb") as f:
                    done, shown = have, -1
                    while chunk := r.read(1 << 20):
                        f.write(chunk)
                        done += len(chunk)
                        if total and done * 20 // total != shown:
                            shown = done * 20 // total
                            print("\r  %d / %d MB" % (done >> 20, total >> 20), end="", flush=True)
            print()
            part.replace(dest)
            return dest
        except (OSError, ValueError) as error:  # URLError/HTTPError/timeouts are OSError
            if attempt == tries:
                raise SystemExit("Download of %s failed (%s). Run install.cmd again: it resumes." % (dest.name, error))
            wait = 10 * attempt
            print()
            print("  %s, retrying in %d s (attempt %d/%d)..." % (error, wait, attempt + 1, tries))
            time.sleep(wait)


def sha1(path):
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def powershell(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, text=True).stdout.strip()


def require_signature(path, org="Microsoft Corporation"):
    if not WINDOWS:
        # Authenticode is a Windows check. On Linux the ISOs carry pinned
        # SHA-1 hashes and the MSI carries a pinned SHA-256 instead.
        return
    out = powershell("$s=Get-AuthenticodeSignature '%s'; \"$($s.Status)|$($s.SignerCertificate.Subject)\"" % path)
    if not out.startswith("Valid|") or not re.search(r'O="?%s' % re.escape(org), out):
        path.unlink(missing_ok=True)
        raise SystemExit("REFUSED %s: not validly signed by %s (%s). Deleted it." % (path.name, org, out))


require_microsoft_signature = require_signature


def cloudflared_url():
    """The tunnel client for this OS/arch. Windows has an .exe; Linux a bare binary."""
    machine = platform.machine().lower()
    arch = "arm64" if machine in ("aarch64", "arm64") else "amd64"
    base = "https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-"
    if WINDOWS:
        return base + "windows-%s.exe" % arch
    if sys.platform == "darwin":
        return base + "darwin-%s.tgz" % arch
    return base + "linux-%s" % arch


def get_cloudflared():
    """Cloudflare's tunnel client, for HTTPS without opening router ports."""
    exe = TOOLS / "cloudflared" / ("cloudflared.exe" if WINDOWS else "cloudflared")
    if not exe.exists():
        download(cloudflared_url(), exe)
        require_signature(exe, "Cloudflare, Inc.")
    if not WINDOWS:
        exe.chmod(0o755)
    return str(exe)


def require_sha1(path, want):
    got = sha1(path)
    if got != want:
        path.unlink(missing_ok=True)
        raise SystemExit("REFUSED %s: SHA-1 %s, expected %s. Deleted it; run again." % (path.name, got, want))


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def require_sha256(path, want):
    got = sha256(path)
    if got != want:
        path.unlink(missing_ok=True)
        raise SystemExit("REFUSED %s: SHA-256 %s, expected %s. Deleted it; run again." % (path.name, got, want))


def _reset_extract_dir(target):
    target = Path(target).resolve()
    tools = TOOLS.resolve()
    if tools not in target.parents or target == DL.resolve() or target == WINE_PREFIX.resolve():
        raise ValueError("Extraction target must be a compiler directory under tools: %s" % target)
    shutil.rmtree(target, ignore_errors=True)


def msi_admin_extract(msi, target):
    """Extract an MSI's files with their install paths, running no installer logic."""
    if WINDOWS:
        subprocess.run(["msiexec", "/a", str(msi), "/qn", "TARGETDIR=%s" % target], check=True)
        return
    target = Path(target)
    _reset_extract_dir(target)  # never mix a failed attempt's files
    target.mkdir(parents=True, exist_ok=True)
    if ensure_wine_prefix():
        run = subprocess.run([wine_exe(), "msiexec", "/a", to_wine_path(msi), "/qn",
                              "TARGETDIR=%s" % to_wine_path(target)],
                             env=wine_env(), capture_output=True, text=True, timeout=900)
        if run.returncode == 0 and any(target.iterdir()):
            return
    if shutil.which("msiextract"):
        subprocess.run(["msiextract", "-C", str(target), str(msi)], check=True)
        if any(target.iterdir()):
            return
    raise SystemExit("Could not unpack %s on Linux. Install Wine or msitools "
                     "(msiextract) and run this again." % msi.name)


def msi_table(msi, table):
    """Rows of one MSI table as dicts, via msitools' msiinfo (Linux fallback)."""
    out = subprocess.run(["msiinfo", "export", str(msi), table],
                         capture_output=True, text=True, check=True).stdout
    lines = out.splitlines()
    if len(lines) < 2:
        return []
    columns = lines[0].split("\t")
    return [dict(zip(columns, line.split("\t"))) for line in lines[3:] if line.strip()]


def msi_layout(msi, cab_dir, target):
    """Copy files expanded from an MSI's cab into their install paths (File/Directory tables)."""
    if not WINDOWS:
        return msi_layout_unix(msi, cab_dir, target)
    try:
        import msilib
    except ImportError:
        raise SystemExit("This step needs Python 3.12 or older (msilib). install.cmd installs 3.12.")
    db = msilib.OpenDatabase(str(msi), msilib.MSIDBOPEN_READONLY)

    def rows(query, n):
        view = db.OpenView(query)
        view.Execute(None)
        out = []
        while (r := view.Fetch()) is not None:
            out.append([r.GetString(i) for i in range(1, n + 1)])
        return out

    # DefaultDir is "target:source", each "short|long"; we want the long target name.
    dirs = {d: (p, name.split(":")[0].split("|")[-1])
            for d, p, name in rows("SELECT Directory, Directory_Parent, DefaultDir FROM Directory", 3)}

    def path(d):
        parent, name = dirs[d]
        if not parent or parent == d:
            return Path()
        return path(parent) / ("" if name == "." else name)

    comp = dict(rows("SELECT Component, Directory_ FROM Component", 2))
    for key, c, fname in rows("SELECT File, Component_, FileName FROM File", 3):
        src = Path(cab_dir) / key
        if src.exists():
            dst = Path(target) / path(comp[c]) / fname.split("|")[-1]
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(src, dst)


def msi_layout_unix(msi, cab_dir, target):
    """The same mapping on Linux without msilib.

    Order: read the table streams with 7z (deterministic, stdlib only), then Wine's
    msiexec /a, then msitools' msiinfo. The 7z path is what makes the older VS2005
    MSI work: Wine's msiexec chokes on it and extracts only a handful of files.
    """
    target = Path(target)
    _reset_extract_dir(target)  # never mix a failed attempt's files
    try:
        if _msi_layout_7z(msi, cab_dir, target):
            return
    except Exception:  # a non-standard table just means "try the next method"
        pass
    _reset_extract_dir(target)
    if ensure_wine_prefix():
        target.mkdir(parents=True, exist_ok=True)
        run = subprocess.run([wine_exe(), "msiexec", "/a", to_wine_path(msi), "/qn",
                              "TARGETDIR=%s" % to_wine_path(target)],
                             env=wine_env(), capture_output=True, text=True, timeout=900)
        if run.returncode == 0 and any(target.iterdir()):
            return
        _reset_extract_dir(target)
    if shutil.which("msiinfo") and Path(cab_dir).is_dir():
        dirs = {row["Directory"]: (row["Directory_Parent"], row["DefaultDir"].split(":")[0].split("|")[-1])
                for row in msi_table(msi, "Directory")}

        def path(d):
            parent, name = dirs[d]
            if not parent or parent == d:
                return Path()
            return path(parent) / ("" if name == "." else name)

        comp = {row["Component"]: row["Directory_"] for row in msi_table(msi, "Component")}
        for row in msi_table(msi, "File"):
            src = Path(cab_dir) / row["File"]
            if src.exists():
                dst = Path(target) / path(comp[row["Component_"]]) / row["FileName"].split("|")[-1]
                dst.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(src, dst)
        return
    raise SystemExit("Could not unpack %s on Linux. Install Wine or msitools "
                     "(msiinfo) and run this again." % msi.name)


# Standard MSI layout tables we need, as (column, kind): 's' is a string reference
# into the string pool, 'i2'/'i4' are biased integers. The on-disk table stream is
# column-major; the column definitions live in the _Columns table but these three
# schemas are fixed by the MSI spec, so they can be hardcoded.
MSI_LAYOUT_TABLES = {
    "Directory": [("Directory", "s"), ("Directory_Parent", "s"), ("DefaultDir", "s")],
    "Component": [("Component", "s"), ("ComponentId", "s"), ("Directory_", "s"),
                  ("Attributes", "i2"), ("Condition", "s"), ("KeyPath", "s")],
    "File": [("File", "s"), ("Component_", "s"), ("FileName", "s"), ("FileSize", "i4"),
             ("Version", "s"), ("Language", "s"), ("Attributes", "i2"), ("Sequence", "i2")],
}


def _msi_strings(pool, data):
    """({id: text}, bytes-per-string-ref) from the _StringPool/_StringData streams.

    The pool is 4-byte entries: the first is the codepage, each later one is
    (length, refcount). Strings are stored back to back in _StringData.
    """
    words = struct.unpack("<%dH" % (len(pool) // 2), pool)
    strref = 3 if (len(pool) > 4 and (words[1] & 0x8000)) else 2
    strings, offset, n, pos = {0: ""}, 0, 1, 4
    while pos + 4 <= len(pool):
        length, refs = struct.unpack_from("<HH", pool, pos)
        pos += 4
        if length == 0:
            if refs == 0:  # an empty slot still consumes a string id
                n += 1
                continue
            high = refs  # >64k string: the high length sits in the previous slot
            length, refs = struct.unpack_from("<HH", pool, pos)
            pos += 4
            length |= high << 16
        strings[n] = data[offset:offset + length].decode("cp1252", "replace")
        offset += length
        n += 1
    return strings, strref


def _msi_table_rows(raw, schema, strings, strref):
    """Rows of one MSI table stream, decoded from its column-major layout."""
    sizes = [strref if kind == "s" else (2 if kind == "i2" else 4) for _, kind in schema]
    row_size = sum(sizes)
    if not row_size or len(raw) % row_size:
        raise ValueError("unexpected table size %d for row size %d" % (len(raw), row_size))
    rows = len(raw) // row_size
    out = []
    for i in range(rows):
        row, base = {}, 0
        for (name, kind), size in zip(schema, sizes):
            chunk = raw[base + i * size: base + (i + 1) * size]
            if kind == "s":
                row[name] = strings.get(int.from_bytes(chunk, "little"), "")
            elif kind == "i2":
                row[name] = int.from_bytes(chunk, "little") - 0x8000
            else:
                row[name] = int.from_bytes(chunk, "little") ^ 0x80000000
            base += size * rows
        out.append(row)
    return out


def _msi_layout_7z(msi, cab_dir, target):
    """Map an already-expanded cab through the MSI tables using 7z and stdlib.

    Returns False (never raises) when the MSI does not look like the standard
    layout, so the caller can fall back to Wine or msitools.
    """
    seven = shutil.which("7z")
    if not seven or not Path(cab_dir).is_dir():
        return False
    with tempfile.TemporaryDirectory() as tmp:
        run = subprocess.run([seven, "x", "-y", "-o" + tmp, str(msi), "!*"], capture_output=True)
        if run.returncode:
            return False

        def read(name):
            path = Path(tmp) / name
            return path.read_bytes() if path.exists() else None

        pool, data = read("!_StringPool"), read("!_StringData")
        if pool is None or data is None:
            return False
        strings, strref = _msi_strings(pool, data)
        tables = {}
        for table, schema in MSI_LAYOUT_TABLES.items():
            raw = read("!" + table)
            if raw is None:
                return False
            tables[table] = _msi_table_rows(raw, schema, strings, strref)

    dirs = {row["Directory"]: (row["Directory_Parent"], row["DefaultDir"].split(":")[0].split("|")[-1])
            for row in tables["Directory"]}

    def path(d):
        parent, name = dirs[d]
        if not parent or parent == d:
            return Path()
        return path(parent) / ("" if name == "." else name)

    comp = {row["Component"]: row["Directory_"] for row in tables["Component"]}
    copied = 0
    for row in tables["File"]:
        src = Path(cab_dir) / row["File"]
        if not src.exists():
            continue
        dst = Path(target) / path(comp[row["Component_"]]) / row["FileName"].split("|")[-1]
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src, dst)
        copied += 1
    return copied > 0


def expand_cab(cab, out):
    """Unpack a .cab: Windows ships two readers that each choke on some cabs;
    Linux uses cabextract with 7z as the fallback."""
    out.mkdir(parents=True, exist_ok=True)
    if WINDOWS:
        system = Path(os.environ["SystemRoot"]) / "System32"
        commands = ([str(system / "tar.exe"), "-xf", str(cab), "-C", str(out)],
                    [str(system / "expand.exe"), str(cab), "-F:*", str(out)])
    else:
        commands = ([shutil.which("cabextract"), "-q", "-d", str(out), str(cab)],
                    [shutil.which("7z"), "x", "-y", "-o" + str(out), str(cab)])
    for cmd in commands:
        if not cmd[0]:
            continue
        if subprocess.run(cmd, capture_output=True).returncode == 0 and any(out.iterdir()):
            return
    raise SystemExit("Could not unpack %s (Linux needs cabextract or 7z)" % cab)


def copy_from_iso(iso, inner, dest):
    """Mount the ISO (Windows 8+) or extract the one file (Linux), no admin rights."""
    if not WINDOWS:
        return copy_from_iso_unix(iso, inner, dest)
    out = powershell(
        "$i=Mount-DiskImage -ImagePath '%s' -PassThru; $d=($i|Get-Volume).DriveLetter; "
        "Copy-Item \"${d}:\\%s\" '%s'; Dismount-DiskImage -ImagePath '%s' | Out-Null; 'ok'"
        % (iso, inner, dest, iso))
    if not Path(dest).exists():
        raise SystemExit("Could not read %s from %s (%s)" % (inner, iso.name, out))


def copy_from_iso_unix(iso, inner, dest):
    """Extract one file from an ISO with 7z or bsdtar. Case may differ on disc."""
    dest = Path(dest)
    dest.parent.mkdir(parents=True, exist_ok=True)
    names = [inner.replace("\\", "/")]
    upper = "/".join(part.upper() for part in names[0].split("/"))
    if upper != names[0]:
        names.append(upper)
    with tempfile.TemporaryDirectory() as tmp:
        for tool in ("7z", "bsdtar"):
            exe = shutil.which(tool)
            if not exe:
                continue
            for name in names:
                if tool == "7z":
                    cmd = [exe, "x", "-y", "-o" + tmp, str(iso), name]
                else:
                    cmd = [exe, "-xf", str(iso), "-C", tmp, name]
                if subprocess.run(cmd, capture_output=True).returncode != 0:
                    continue
                found = Path(tmp) / name
                if found.is_file():
                    shutil.copyfile(found, dest)
                    return
    raise SystemExit("Could not read %s from %s (Linux needs 7z or bsdtar)" % (inner, iso.name))


def carve_cab(exe, cab):
    """Self-extracting setup exes carry a plain .cab after the stub."""
    data = Path(exe).read_bytes()
    at = data.find(b"MSCF\0\0\0\0")
    if at < 0:
        raise SystemExit("No cab inside %s" % exe)
    Path(cab).write_bytes(data[at:])


def get_vs2008_sp1():
    msi = download(VCPY_URL, DL / "VCForPython27.msi")
    require_sha256(msi, VCPY_SHA256)
    require_signature(msi)
    msi_admin_extract(msi, TOOLS / "vc2008sp1")


def get_vs2008_rtm():
    iso = download(VS2008_URL, DL / "VS2008Express2007.iso")
    require_sha1(iso, VS2008_SHA1)
    work = DL / "vs2008rtm"
    work.mkdir(parents=True, exist_ok=True)
    copy_from_iso(iso, r"VCExpress\Ixpvc.exe", work / "Ixpvc.exe")
    require_microsoft_signature(work / "Ixpvc.exe")
    carve_cab(work / "Ixpvc.exe", work / "outer.cab")
    expand_cab(work / "outer.cab", work / "outer")
    require_microsoft_signature(work / "outer" / "vs_setup.msi")
    expand_cab(work / "outer" / "vs_setup.cab", work / "files")
    msi_layout(work / "outer" / "vs_setup.msi", work / "files", TOOLS / "vc2008rtm")


def get_vs2005():
    iso = download(VS2005_URL, DL / "VC2005Express.iso")
    require_sha1(iso, VS2005_SHA1)
    work = DL / "vs2005"
    work.mkdir(parents=True, exist_ok=True)
    copy_from_iso(iso, r"Ixpvc.exe", work / "Ixpvc.exe")
    require_microsoft_signature(work / "Ixpvc.exe")
    carve_cab(work / "Ixpvc.exe", work / "outer.cab")
    expand_cab(work / "outer.cab", work / "outer")
    msi = next((work / "outer").glob("*.msi"))
    require_microsoft_signature(msi)
    expand_cab(next((work / "outer").glob("*.cab")), work / "files")
    msi_layout(msi, work / "files", TOOLS / "vc2005")


FETCHERS = {30729: get_vs2008_sp1, 21022: get_vs2008_rtm, 50727: get_vs2005}
# download MB, unpacked MB, and minutes to fetch + unpack at roughly 8 MB/s.
# Shown to the user before anything is downloaded, so nobody is surprised by 1.5 GB.
BUNDLES = {30729: (85, 250, 3), 21022: (940, 2900, 14), 50727: (460, 1400, 8)}
SIZES = {build: "%d MB" % spec[0] for build, spec in BUNDLES.items()}


# ---------- install ----------

# What a re-install must never touch: mined source, claims and settings are the
# user's work, not installer output.
PRESERVE = ("work", "src", "roconstruct-settings.json")
PIP_PACKAGES = ("pefile", "capstone")


def state():
    """Recorded install steps, so a second run knows what it already did."""
    try:
        return json.loads(STATE.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}


def save_state(**changes):
    current = state()
    current.update({k: v for k, v in changes.items() if v is not None})
    try:
        STATE.parent.mkdir(parents=True, exist_ok=True)
        STATE.write_text(json.dumps(current, indent=1), encoding="utf-8")
    except OSError:
        pass
    return current


def step_done(name):
    return bool(state().get(name, {}).get("done"))


def mark_done(step, **fields):
    # `step` rather than `name`: callers record {"name": "VS2008 SP1 ..."}, and a
    # parameter called `name` would collide with that keyword on a fresh install.
    entry = {"done": True, "at": int(time.time())}
    entry.update(fields)
    return save_state(**{step: entry})


def clear_step(name):
    """Forget a recorded step, so the next run retries it (used after a bad fetch)."""
    current = state()
    if current.pop(name, None) is not None:
        return save_state(**current)
    return current


def snapshot(paths=PRESERVE, deep=False):
    """Fingerprint of the things a re-install must leave alone.

    Cheap by default (one stat per entry, so install stays quick on a tree with
    tens of thousands of source files). `deep=True` records every file, which is
    what the tests use to prove nothing under work/ was touched.
    """
    out = {}
    for name in paths:
        target = ROOT / name
        try:
            stat = target.stat()
        except OSError:
            out[name] = None
            continue
        if target.is_file():
            out[name] = [stat.st_size, int(stat.st_mtime)]
            continue
        if not deep:
            try:
                out[name] = [len(list(target.iterdir())), int(stat.st_mtime)]
            except OSError:
                out[name] = None
            continue
        for path in sorted(target.rglob("*")):
            if path.is_file():
                stat = path.stat()
                out["%s/%s" % (name, path.relative_to(target).as_posix())] = [stat.st_size, int(stat.st_mtime)]
    return out


def changed_since(before, paths=PRESERVE, deep=False):
    """Names under work/, src/ and the settings file that differ from `before`."""
    after = snapshot(paths, deep=deep)
    return sorted(key for key in set(before) | set(after) if before.get(key) != after.get(key))





def has_module(name):
    try:
        __import__(name)
        return True
    except ImportError:
        return False


def missing_packages():
    return [name for name in PIP_PACKAGES if not has_module(name)]


def ensure_packages(install=True):
    """Install only the packages that are actually absent (pefile, capstone)."""
    missing = missing_packages()
    if not missing:
        return []
    if not install:
        return missing
    print("Installing Python packages: %s" % ", ".join(missing))
    user = ["--user"] if sys.prefix == sys.base_prefix else []
    run = subprocess.run([sys.executable, "-m", "pip", "install", *user, "-q", *missing])
    if run.returncode or missing_packages():
        raise SystemExit("pip could not install %s. Check your internet connection and run this again."
                         % ", ".join(missing))
    mark_done("pip", packages=list(PIP_PACKAGES))
    return missing


def needed_builds():
    from roc import clients
    return sorted({e.get("compiler_build") for e in clients.load().values()} - {None})


def client_mb(name=None):
    """Rough size of the client exe a worker needs for byte matching."""
    if not name:
        return 0
    from roc import sources
    bundle = sources.load_sources().get("bundle") or {}
    size, slots = bundle.get("size"), bundle.get("slots") or []
    if size and slots:
        return int(size / len(slots) / 1048576) + 1
    return 12


def missing_builds():
    have = compilers()
    return [build for build in needed_builds() if build in FETCHERS and build not in have]


def plan(client=None):
    """Everything a fresh install on this machine would download, in one dict."""
    builds = missing_builds()
    return {"packages": missing_packages(),
            "compilers": builds,
            "download_mb": sum(BUNDLES[b][0] for b in builds),
            "disk_mb": sum(BUNDLES[b][1] for b in builds) + client_mb(client),
            "client_mb": client_mb(client),
            "minutes": sum(BUNDLES[b][2] for b in builds),
            "present": sorted(compilers())}


def show_plan(current):
    """Print the size and time cost before any download starts."""
    print("\nWhat this install needs")
    if WINDOWS:
        python_line = ("ready" if has_module("msilib") else
                       "WRONG: 3.13+ cannot unpack compilers (run install.cmd)")
    else:
        python_line = "ready (%s; unpacking uses Wine/msitools)" % platform.python_version()
    print("  Python              %s" % python_line)
    print("  pip packages        %s" % (", ".join(current["packages"]) if current["packages"]
                                        else "already installed (%s)" % ", ".join(PIP_PACKAGES)))
    if current["compilers"]:
        for build in current["compilers"]:
            print("  %-20s %s download, about %d MB unpacked" % (NAMES[build], SIZES[build], BUNDLES[build][1]))
    else:
        print("  compilers           already installed, nothing to download")
    print("  ---")
    print("  Total download %d MB | disk %d MB | about %d min" %
          (current["download_mb"], current["disk_mb"], current["minutes"]))
    if current["client_mb"]:
        print("  Plus about %d MB for the client exe when the worker starts." % current["client_mb"])
    print("  Not installed: Ollama, Docker, local models. Those are opt-in "
          "('Use local model'), so no GPU is needed.")


def install_compilers(only=None, ask=input, assume_yes=False):
    """Fetch only the compiler bundles that are missing. Never reinstalls one."""
    done = []
    for build in missing_builds():
        if only and build not in only:
            continue
        if step_done("compiler-%d" % build):
            print("Compiler %s already installed, skipping." % NAMES[build])
            continue
        if not assume_yes and ask("Download compiler %s (%s)? [Y/n] " % (NAMES[build], SIZES[build])
                                  ).strip().lower().startswith("n"):
            print("  Skipped. Run this again whenever you want it; downloads resume.")
            continue
        try:
            FETCHERS[build]()
            mark_done("compiler-%d" % build, name=NAMES[build])
            done.append(build)
        except SystemExit as error:  # one failed download must not stop the others
            print(error)
        compilers.cache_clear()
    return done


def register_link():
    """Register roconstruct:// for this user, so the website can launch the worker."""
    if os.name != "nt":
        print("roconstruct:// links need Windows; skipping registration.")
        return False
    from roc import link
    if link.installed():
        print("One-click links already registered: roconstruct://")
        return True
    link.install()
    mark_done("link")
    return True


def install(ask=input, only=None, assume_yes=False, client=None):
    """The tiny first-run install: packages, exact compiler bundles, link, website.

    No Ollama, no Docker, no local model. `local_ai` is a separate opt-in step.
    """
    before = snapshot()
    ensure_packages()
    if not compiler_ready():
        print("\nWine is required on Linux: it runs the exact 2005/2008 cl.exe compilers.")
        print("  Arch:          sudo pacman -S wine")
        print("  Debian/Ubuntu: sudo apt install wine wine32")
        print("  Fedora:        sudo dnf install wine")
        print("Then run this again.")
        return False
    if not ensure_wine_prefix():
        raise SystemExit("Could not prepare the Wine prefix. Check that wine runs: wine --version")
    show_plan(plan(client))
    install_compilers(only=only, ask=ask, assume_yes=assume_yes)
    refresh_path()
    register_link()
    ok = report()
    print("\nPreserved your work: %s" % describe(before))
    changed = changed_since(before)
    if changed:
        print("  %d entr(y/ies) changed while this ran (a worker was probably running): %s"
              % (len(changed), ", ".join(changed[:5])))
    return ok


def describe(snap):
    """One line about what a snapshot covered, e.g. 'work/ (412 files), settings'."""
    parts = []
    for name in sorted(snap):
        value = snap[name]
        if value is None:
            continue
        if (ROOT / name).is_dir():
            parts.append("%s (%d entries)" % (name, value[0]))
        else:
            parts.append("%s (%d bytes)" % (name, value[0]))
    return ", ".join(parts) or "nothing on disk yet"


def local_ai(ask=input, docker=False, model="qwen2.5-coder:7b"):
    """Opt-in local AI. Never called by the default install.

    Ollama is offered here and only here. Docker / Rev.ng is a second, later
    question because it costs gigabytes of disk and needs a bigger setup.
    """
    if not WINDOWS:
        return local_ai_unix(ask=ask, docker=docker, model=model)
    if not shutil.which("winget"):
        print("\nwinget is missing, so Ollama must be installed by hand: https://ollama.com/download")
        return False
    exe = find_exe("ollama")
    if not exe:
        if not ask("Install Ollama for local models? [y/N] ").strip().lower().startswith("y"):
            print("Skipped. Cloud models work without it.")
            return False
        print("Installing Ollama...")
        subprocess.run(["winget", "install", "--id", "Ollama.Ollama", "-e", "--silent",
                        "--accept-package-agreements", "--accept-source-agreements"])
        refresh_path()
        exe = find_exe("ollama")
        if not exe:
            print("  Ollama still not found. Restart Windows, then run: roc local-ai")
            return False
    try:
        models = ensure_ollama(exe)
    except SystemExit as error:
        print("  %s" % error)
        return False
    print("  Ollama is installed and running (%d model(s))." % len(models))
    if model and model not in models:
        if not ask("Download the %s model (~4.7 GB, one time)? [y/N] " % model
                   ).strip().lower().startswith("y"):
            print("  No models yet. Pull one later: ollama pull %s" % model)
        else:
            subprocess.run([exe, "pull", model], check=False)
    mark_done("local-ai")
    if docker:
        extras(ask)
    return True


def local_ai_unix(ask=input, docker=False, model="qwen2.5-coder:7b"):
    """Linux/macOS local AI: Ollama comes from the distro or ollama.com, not winget."""
    exe = find_exe("ollama")
    if not exe:
        print("\nOllama is not installed. Install it with your package manager, or:")
        print("  curl -fsSL https://ollama.com/install.sh | sh")
        print("Then run: roc local-ai")
        return False
    try:
        models = ensure_ollama(exe)
    except SystemExit as error:
        print("  %s" % error)
        return False
    print("  Ollama is installed and running (%d model(s))." % len(models))
    if model and model not in models:
        if not ask("Download the %s model (~4.7 GB, one time)? [y/N] " % model
                   ).strip().lower().startswith("y"):
            print("  No models yet. Pull one later: ollama pull %s" % model)
        else:
            subprocess.run([exe, "pull", model], check=False)
    mark_done("local-ai")
    if docker:
        extras_unix(ask)
    return True


def extras(ask):
    """Docker + Rev.ng: only offered after local AI, never during a normal install."""
    if draft_revng_ready():
        print("Rev.ng hints: already ready.")
        return True
    if not ask("Install Docker Desktop for Rev.ng hints (~5 GB, needs a restart)? [y/N] "
               ).strip().lower().startswith("y"):
        print("Skipped. Rev.ng hints stay off; matching still works.")
        return False
    if not shutil.which("winget"):
        print("winget is missing, so Docker must be installed by hand: https://docker.com")
        return False
    print("Installing Docker Desktop...")
    subprocess.run(["winget", "install", "--id", "Docker.DockerDesktop", "-e", "--silent",
                    "--accept-package-agreements", "--accept-source-agreements"])
    refresh_path()
    mark_done("docker")
    print("  Start Docker Desktop, then: docker pull revng/revng")
    return True


def extras_unix(ask):
    """Linux/macOS Rev.ng: Docker comes from the distro; only the image is fetched."""
    if draft_revng_ready():
        print("Rev.ng hints: already ready.")
        return True
    if not shutil.which("docker"):
        print("Docker is not installed. Install it with your package manager, then run:")
        print("  docker pull revng/revng")
        return False
    if not ask("Download the Rev.ng image for decompiler hints (~2 GB)? [y/N] "
               ).strip().lower().startswith("y"):
        print("Skipped. Rev.ng hints stay off; matching still works.")
        return False
    print("Pulling revng/revng...")
    run = subprocess.run(["docker", "pull", "revng/revng"])
    if run.returncode == 0:
        mark_done("docker")
    return run.returncode == 0


def draft_revng_ready():
    from roc import draft
    return draft.revng_available()


def report():
    """What this machine can do right now, without implying anything is missing."""
    from roc import clients, draft
    have = compilers()
    print("\nCompilers:")
    for name, entry in sorted(clients.load().items()):
        build = entry.get("compiler_build")
        print("  %-6s %-28s %s" % (name, entry.get("compiler"),
                                    "ready" if build in have else "missing (roc install)"))
    model = draft.pick_model()
    if model:
        print("Local AI drafts (Ollama): ready, %s" % model)
    elif find_exe("ollama"):
        if not wait_for_http(OLLAMA_API, timeout=5, interval=1):
            print("Local AI drafts (Ollama): installed but not running. Run: ollama serve")
        else:
            print("Local AI drafts (Ollama): running, but no model. Run: ollama pull qwen2.5-coder:7b")
    else:
        print("Local AI drafts (Ollama): not installed. Cloud models work without it: roc local-ai")
    print("Rev.ng hints (Docker): %s" % ("ready" if draft.revng_available() else
          "off (optional: roc local-ai --docker)"))
    print("Cloud worker: ready, no GPU or local model needed.")
    return all(e.get("compiler_build") in have for e in clients.load().values())
