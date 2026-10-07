"""Install everything a contributor needs, without admin rights.

pip packages, optional Ollama/Docker via winget, and the old MSVC compilers:
downloaded from archive.org, checked (Microsoft signature or pinned SHA-1),
and unpacked into tools/ instead of being installed.
"""
import functools
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
DL = TOOLS / "dl"
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
VS2008_URL = "https://archive.org/download/VisualStudioExpressEditionsDVD2007/DVD1.ISO"
VS2008_SHA1 = "65ebdd88136275768d778d1795d41a7fcc12a47e"
VS2005_URL = "https://archive.org/download/MS_VisualCPPExpress-2005/Micorosft_Visual_C%2B%2B_2005_Express.iso"
VS2005_SHA1 = "1ae44e4eaf8c61c3a39e573fd6efd9889e940529"
OPTIONAL = [("Ollama (AI drafts, needs a decent GPU)", "Ollama.Ollama", "ollama"),
            ("Docker Desktop (Rev.ng hints)", "Docker.DockerDesktop", "docker")]

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


def refresh_path():
    """Re-read PATH from the registry and add the usual install dirs.

    winget does not update the PATH of the process that started it, so a program it
    just installed stays invisible to shutil.which until this runs.

    Idempotent: rebuilt from the original PATH each call, never appended to itself.
    """
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


def cl_env(cl):
    """Environment that lets an old cl.exe find its DLLs and headers."""
    cl = Path(cl)
    env = dict(os.environ)
    env["PATH"] = os.pathsep.join([str(cl.parent), str(cl.parents[2] / "Common7" / "IDE"), env.get("PATH", "")])
    inc = cl.parents[1] / "include"
    env["INCLUDE"] = str(inc) if inc.exists() else ""
    return env


@functools.lru_cache(maxsize=None)
def compilers():
    """{build: cl.exe path} for every old MSVC found."""
    paths = CL_PATHS + sorted(TOOLS.glob("*/**/VC/bin/cl.exe"))
    paths += [Path(p) for p in os.environ.get("ROC_CL", "").split(";") if p]
    found = {}
    for cl in paths:
        if not cl.exists():
            continue
        try:
            banner = subprocess.run([str(cl)], capture_output=True, text=True,
                                    cwd=cl.parent, env=cl_env(cl), timeout=30).stderr
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
    out = powershell("$s=Get-AuthenticodeSignature '%s'; \"$($s.Status)|$($s.SignerCertificate.Subject)\"" % path)
    if not out.startswith("Valid|") or not re.search(r'O="?%s' % re.escape(org), out):
        path.unlink(missing_ok=True)
        raise SystemExit("REFUSED %s: not validly signed by %s (%s). Deleted it." % (path.name, org, out))


require_microsoft_signature = require_signature
CLOUDFLARED_URL = "https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.exe"


def get_cloudflared():
    """Cloudflare's tunnel client, for HTTPS without opening router ports."""
    exe = TOOLS / "cloudflared" / "cloudflared.exe"
    if not exe.exists():
        download(CLOUDFLARED_URL, exe)
        require_signature(exe, "Cloudflare, Inc.")
    return str(exe)


def require_sha1(path, want):
    got = sha1(path)
    if got != want:
        path.unlink(missing_ok=True)
        raise SystemExit("REFUSED %s: SHA-1 %s, expected %s. Deleted it; run again." % (path.name, got, want))


def msi_admin_extract(msi, target):
    subprocess.run(["msiexec", "/a", str(msi), "/qn", "TARGETDIR=%s" % target], check=True)


def msi_layout(msi, cab_dir, target):
    """Copy files expanded from an MSI's cab into their install paths (File/Directory tables)."""
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


def expand_cab(cab, out):
    """Windows ships two cab readers that each choke on some cabs; try both."""
    out.mkdir(parents=True, exist_ok=True)
    system = Path(os.environ["SystemRoot"]) / "System32"
    for cmd in ([str(system / "tar.exe"), "-xf", str(cab), "-C", str(out)],
                [str(system / "expand.exe"), str(cab), "-F:*", str(out)]):
        if subprocess.run(cmd, capture_output=True).returncode == 0 and any(out.iterdir()):
            return
    raise SystemExit("Could not unpack %s" % cab)


def copy_from_iso(iso, inner, dest):
    """Mount the ISO (no admin needed on Windows 8+), copy one file out, unmount."""
    out = powershell(
        "$i=Mount-DiskImage -ImagePath '%s' -PassThru; $d=($i|Get-Volume).DriveLetter; "
        "Copy-Item \"${d}:\\%s\" '%s'; Dismount-DiskImage -ImagePath '%s' | Out-Null; 'ok'"
        % (iso, inner, dest, iso))
    if not Path(dest).exists():
        raise SystemExit("Could not read %s from %s (%s)" % (inner, iso.name, out))


def carve_cab(exe, cab):
    """Self-extracting setup exes carry a plain .cab after the stub."""
    data = Path(exe).read_bytes()
    at = data.find(b"MSCF\0\0\0\0")
    if at < 0:
        raise SystemExit("No cab inside %s" % exe)
    Path(cab).write_bytes(data[at:])


def get_vs2008_sp1():
    msi = download(VCPY_URL, DL / "VCForPython27.msi")
    require_microsoft_signature(msi)
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
SIZES = {30729: "85 MB", 21022: "940 MB", 50727: "460 MB"}


# ---------- install ----------

def has_module(name):
    try:
        __import__(name)
        return True
    except ImportError:
        return False


def needed_builds():
    from roc import clients
    return sorted({e.get("compiler_build") for e in clients.load().values()} - {None})


def install(ask=input, only=None):
    if not (has_module("pefile") and has_module("capstone")):
        print("Installing Python packages...")
        subprocess.run([sys.executable, "-m", "pip", "install", "--user", "-q", "pefile", "capstone"], check=True)
    have = compilers()
    for build in needed_builds():
        if build in have or build not in FETCHERS or (only and build not in only):
            continue
        if not ask("Download compiler %s (%s)? [Y/n] " % (NAMES[build], SIZES[build])).strip().lower().startswith("n"):
            try:
                FETCHERS[build]()
            except SystemExit as error:  # one failed download must not stop the others
                print(error)
            compilers.cache_clear()
    refresh_path()
    optional(ask)
    if not report():
        raise SystemExit(1)


def optional(ask):
    """Install Ollama and Docker if they are missing, then prove they actually work.

    Detection is by resolved path, not shutil.which: winget appends to the registry
    PATH and the running process never sees it. After installing we start Ollama's
    server if it is not listening yet, because "installed" and "answering API calls"
    are different states and only the second one lets the worker draft sources."""
    if not shutil.which("winget"):
        print("\nwinget is missing, so Ollama and Docker must be installed by hand.")
        return
    for label, package, exe in OPTIONAL:
        if find_exe(exe):
            continue
        if not ask("Install %s? [y/N] " % label).strip().lower().startswith("y"):
            continue
        print("Installing %s..." % label.split(" (")[0])
        subprocess.run(["winget", "install", "--id", package, "-e", "--silent",
                        "--accept-package-agreements", "--accept-source-agreements"])
        refresh_path()
        found = find_exe(exe)
        if not found:
            print("  %s still not found. Restart Windows and run this again." % exe)
            continue
        if exe == "ollama":
            try:
                models = ensure_ollama(found)
            except SystemExit as error:
                print("  %s" % error)
                continue
            print("  Ollama is installed and running (%d model(s))." % len(models))
            if not models:
                print("  No models yet. Pull one to let the worker draft sources:")
                print("    ollama pull qwen2.5-coder:7b")


def report():
    from roc import clients, draft
    have = compilers()
    print("\nCompilers:")
    for name, entry in sorted(clients.load().items()):
        build = entry.get("compiler_build")
        print("  %-6s %-28s %s" % (name, entry.get("compiler"), "ready" if build in have else "MISSING (roc install)"))
    model = draft.pick_model()
    if model:
        print("AI drafts (Ollama): ready, %s" % model)
    elif not find_exe("ollama"):
        print("AI drafts (Ollama): not installed (optional: run  roc install)")
    elif not wait_for_http(OLLAMA_API, timeout=5, interval=1):
        print("AI drafts (Ollama): installed but not running.")
        print("  Start it from the Start menu, or run:  ollama serve")
    else:
        print("AI drafts (Ollama): running, but no model. Run:  ollama pull qwen2.5-coder:7b")
    print("Rev.ng hints (Docker):", "ready" if draft.revng_available() else
          "not available (optional: Docker Desktop, then  docker pull revng/revng)")
    return all(e.get("compiler_build") in have for e in clients.load().values())
