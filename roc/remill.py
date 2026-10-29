"""Optional integration with Remill's example 32-bit x86 lifter.

Remill is only an *evidence* source.  It gives a model of how the original
instructions behave, which is useful for branch/flag/memory questions.  It is
never the original C++, and LLVM's verifier only proves that the produced IR is
well formed; it does not prove equivalence to the original source.

The tools are optional.  Configure them with:

    ROC_REMILL_EXE   full path to remill-lift-17 (or another compatible lifter)
    ROC_LLVM_OPT     full path to opt (LLVM 17 is the lifter's matching version)
    ROC_LLVM_BIN     directory containing opt, when ROC_LLVM_OPT is not set

Otherwise a repository-local ``tools/remill`` or ``tools/llvm`` tree is used
when present, then ``PATH``.  Nothing is downloaded or installed implicitly,
and a missing lifter never breaks the other mining phases.
"""
import functools
import hashlib
import json
import os
import re
import shutil
import subprocess
import threading
import time
from pathlib import Path

from roc import draft, match

REPO_ROOT = Path(getattr(match, "ROOT", Path(__file__).resolve().parent.parent))
REMILL_BASENAMES = ("remill-lift-17", "remill-lift")
OPT_BASENAMES = ("opt-17", "opt")
REPO_REMILL_CANDIDATES = (
    "tools/remill/bin/{name}",
    "tools/remill/build/bin/{name}",
    "tools/remill/build-remill/bin/{name}",
    "tools/remill/{name}",
    "tools/bin/{name}",
    "tools/{name}",
)
REPO_OPT_CANDIDATES = (
    "tools/llvm/bin/{name}",
    "tools/llvm-17/bin/{name}",
    "tools/remill/bin/{name}",
    "tools/remill/dependencies/install/bin/{name}",
    "tools/bin/{name}",
)

# Common user-home installation paths (auto-detected when env vars are unset).
# These make Remill work across PCs without manual configuration.
USER_HOME_REMILL_PATTERNS = (
    "remill/build-remill-*/bin/lift/{name}",
    "remill/build-remill*/bin/lift/{name}",
    "remill/build/bin/lift/{name}",
    "remill/build/bin/{name}",
    "remill/bin/lift/{name}",
    "remill/bin/{name}",
    "remill/{name}",
)
USER_HOME_OPT_PATTERNS = (
    "msys64/mingw64/bin/{name}",
    "msys64/usr/bin/{name}",
    "llvm/bin/{name}",
    "llvm-17/bin/{name}",
    "remill/bin/{name}",
    "remill/dependencies/install/bin/{name}",
)
LIFT_OPTIONS = {"arch": "x86", "os": "windows"}

_MEMO = {}
_MEMO_LOCK = threading.Lock()
_VERSION_CACHE = {}


def _platform_names(basename):
    """Windows keeps the .exe suffix; other platforms do not.  Try both so a
    checked-out tools tree works when moved between machines."""
    if os.name == "nt":
        return (basename + ".exe", basename)
    return (basename, basename + ".exe")


def _first_file(paths):
    for path in paths:
        try:
            if Path(path).is_file():
                return Path(path)
        except OSError:
            continue
    return None


def _repo_root():
    """Resolved repository root; tests may monkeypatch ``REPO_ROOT``."""
    return Path(REPO_ROOT)


def _repo_candidates(templates, basenames):
    root = _repo_root()
    for template in templates:
        for basename in basenames:
            for name in _platform_names(basename):
                yield root / template.format(name=name)


def _which(names):
    for name in names:
        for candidate in _platform_names(name):
            found = shutil.which(candidate)
            if found:
                return Path(found)
    return None


def _version_hint(path, kind):
    """Version from the file name first (cheap and stable); an optional one-shot
    ``-version`` probe when the name does not say.  Cached per path+mtime."""
    try:
        stat = Path(path).stat()
    except OSError:
        return "unknown"
    key = (str(path), stat.st_mtime_ns, stat.st_size, kind)
    if key in _VERSION_CACHE:
        return _VERSION_CACHE[key]
    named = re.search(r"(\d+)(?:\.[0-9]+)*", Path(path).stem or "")
    version = named.group(1) if named else "unknown"
    if version == "unknown" and kind == "llvm":
        try:
            proc = subprocess.run([str(path), "--version"], capture_output=True, text=True, timeout=8)
            found = re.search(r"(?:LLVM|version)\s+(\d+(?:\.[0-9]+)*)", (proc.stdout or "") + (proc.stderr or ""))
            if found:
                version = found.group(1)
        except (OSError, subprocess.TimeoutExpired):
            pass
    _VERSION_CACHE[key] = version
    return version


def _identity(path, kind):
    try:
        stat = Path(path).stat()
        return {"basename": Path(path).name, "size": stat.st_size,
                "mtime_ns": stat.st_mtime_ns, "version": _version_hint(path, kind)}
    except OSError:
        return {"basename": Path(path).name, "size": 0, "mtime_ns": 0,
                "version": _version_hint(path, kind)}


_CONFIG_CACHE_PATH = None


def _config_cache_path():
    global _CONFIG_CACHE_PATH
    if _CONFIG_CACHE_PATH is not None:
        return _CONFIG_CACHE_PATH
    # Look for roconstruct-settings.json in common locations
    candidates = [
        Path.cwd() / "local" / "config" / "roconstruct-settings.json",
        Path.home() / ".roconstruct" / "roconstruct-settings.json",
    ]
    for p in candidates:
        if p.is_file():
            _CONFIG_CACHE_PATH = p
            return p
    # Default to repo-local config
    _CONFIG_CACHE_PATH = Path.cwd() / "local" / "config" / "roconstruct-settings.json"
    return _CONFIG_CACHE_PATH


def _load_cached_paths():
    """Load cached Remill/LLVM paths from config file."""
    try:
        path = _config_cache_path()
        if path.is_file():
            data = json.loads(path.read_text(encoding="utf-8"))
            return data.get("remill_cache", {})
    except Exception:
        pass
    return {}


def _save_cached_paths(exe_path, opt_path):
    """Save resolved Remill/LLVM paths to config file for cross-PC sharing."""
    try:
        path = _config_cache_path()
        data = {}
        if path.is_file():
            data = json.loads(path.read_text(encoding="utf-8"))
        data["remill_cache"] = {
            "ROC_REMILL_EXE": str(exe_path) if exe_path else None,
            "ROC_LLVM_OPT": str(opt_path) if opt_path else None,
        }
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(data, indent=2), encoding="utf-8")
    except Exception:
        pass


def _resolve_one(env_key, repo_templates, basenames, kind, explicit=None):
    """Resolve one tool, returning (path, source, problem).

    Precedence is explicit path, explicit directory (LLVM only), repository-local
    tree, then user-home directories, then common Windows paths, then PATH.
    Cached paths from roconstruct-settings.json are used as fallbacks.
    A set-but-invalid override is reported instead of being silently replaced."""
    override = os.environ.get(env_key, "").strip()
    if override:
        path = Path(override).expanduser()
        if path.is_file():
            return path, "env", None
        return None, "env", "%s is set but does not point to a file" % env_key
    if kind == "llvm":
        llvm_bin = os.environ.get("ROC_LLVM_BIN", "").strip()
        if llvm_bin:
            folder = Path(llvm_bin).expanduser()
            found = _first_file(folder / name for basename in basenames for name in _platform_names(basename))
            if found:
                return found, "env", None
            return None, "env", "ROC_LLVM_BIN is set but contains no opt binary"
    found = _first_file(_repo_candidates(repo_templates, basenames))
    if found:
        return found, "repo", None
    # Check user-home installation directories (portable across PCs)
    home = Path.home()
    user_patterns = USER_HOME_REMILL_PATTERNS if kind == "remill" else USER_HOME_OPT_PATTERNS
    user_candidates = []
    for pattern in user_patterns:
        for basename in basenames:
            for name in _platform_names(basename):
                # Handle glob patterns (* in path)
                if "*" in pattern:
                    # Use pathlib's glob directly on the home directory
                    glob_pattern = pattern.format(name=name)
                    try:
                        for match in home.glob(glob_pattern):
                            if match.is_file() and match.name in _platform_names(basename):
                                user_candidates.append(match)
                    except (OSError, ValueError):
                        pass
                else:
                    user_candidates.append(home / pattern.format(name=name))
    found = _first_file(user_candidates)
    if found:
        return found, "user-home", None
    # Check common Windows installation directories
    if os.name == "nt":
        common_dirs = []
        if kind == "remill":
            common_dirs = [Path("C:/Users"), Path("C:/Program Files"), Path("C:/Program Files (x86)")]
        else:
            common_dirs = [Path("C:/msys64/mingw64/bin"), Path("C:/msys64/usr/bin"),
                           Path("C:/Program Files/LLVM/bin"), Path("C:/Program Files (x86)/LLVM/bin")]
        common_candidates = []
        for d in common_dirs:
            for basename in basenames:
                for name in _platform_names(basename):
                    common_candidates.append(d / name)
        # Also glob for remill in user directories
        if kind == "remill":
            for user_dir in Path("C:/Users").iterdir() if Path("C:/Users").is_dir() else []:
                if user_dir.is_dir():
                    for pattern in USER_HOME_REMILL_PATTERNS:
                        for basename in basenames:
                            for name in _platform_names(basename):
                                common_candidates.append(user_dir / pattern.format(name=name))
        found = _first_file(common_candidates)
        if found:
            return found, "user-home", None
    # Check cached paths from config (portable across sessions on the same PC)
    cached = _load_cached_paths()
    cached_path = cached.get(env_key, "").strip() if cached else ""
    if cached_path:
        cached_p = Path(cached_path).expanduser()
        if cached_p.is_file():
            return cached_p, "cache", None
    found = _which(basenames)
    if found:
        return found, "path", None
    return None, None, "%s was not found" % (env_key if kind == "remill" else "LLVM opt")


def _public_path(path):
    """Never put a private home/checkout directory in shared logs."""
    if not path:
        return ""
    return Path(path).name


def resolve_tools(refresh=False):
    """Return the resolved optional tool chain as a plain dict.

    ``available`` means both the lifter and LLVM's ``opt`` were found; lifting
    without verification is deliberately not offered because the IR's validity
    is the only thing this repository can assert about it.
    """
    if not refresh:
        cached = getattr(resolve_tools, "_cache", None)
        if cached is not None:
            return dict(cached)
    exe, exe_source, exe_problem = _resolve_one(
        "ROC_REMILL_EXE", REPO_REMILL_CANDIDATES, REMILL_BASENAMES, "remill")
    opt, opt_source, opt_problem = _resolve_one(
        "ROC_LLVM_OPT", REPO_OPT_CANDIDATES, OPT_BASENAMES, "llvm")
    problems = [problem for problem in (exe_problem, opt_problem) if problem]
    if exe and opt:
        exe_version = _version_hint(exe, "remill")
        opt_version = _version_hint(opt, "llvm")
        # Compare major versions only (e.g., "17" matches "17.0.6")
        exe_major = exe_version.split(".")[0] if exe_version != "unknown" else "unknown"
        opt_major = opt_version.split(".")[0] if opt_version != "unknown" else "unknown"
        if (exe_major != "unknown" and opt_major != "unknown"
                and exe_major != opt_major):
            problems.append("lifter and LLVM major versions differ (%s vs %s); prefer a matching opt-17"
                            % (exe_version, opt_version))
        cache_key = hashlib.sha256(json.dumps({
            "lifter": _identity(exe, "remill"),
            "llvm": _identity(opt, "llvm"),
            "options": LIFT_OPTIONS,
        }, sort_keys=True).encode()).hexdigest()
    else:
        exe_version = opt_version = "unknown"
        cache_key = ""
    result = {
        "available": bool(exe and opt),
        "exe": str(exe) if exe else None,
        "opt": str(opt) if opt else None,
        "llvm_bin": str(Path(opt).parent) if opt else None,
        "exe_name": _public_path(exe),
        "opt_name": _public_path(opt),
        "exe_source": exe_source,
        "opt_source": opt_source,
        "lifter_version": exe_version,
        "llvm_version": opt_version,
        "options": dict(LIFT_OPTIONS),
        "cache_key": cache_key,
        "problems": problems,
        "reason": ("ready: %s + %s" % (Path(exe).name, Path(opt).name) if exe and opt
                   else "; ".join(problems) or "Remill/LLVM not configured"),
        "env_overrides": {
            "ROC_REMILL_EXE": "full path to remill-lift-17",
            "ROC_LLVM_OPT": "full path to LLVM opt (17 preferred)",
            "ROC_LLVM_BIN": "directory containing opt, used when ROC_LLVM_OPT is unset",
        },
    }
    resolve_tools._cache = dict(result)
    # Cache resolved paths for cross-session and cross-PC portability
    if result.get("available"):
        _save_cached_paths(result.get("exe"), result.get("opt"))
    return result


def not_available_message(tools=None):
    tools = tools or resolve_tools()
    return ("Remill is optional and not configured (%s). Set ROC_REMILL_EXE and "
            "ROC_LLVM_OPT (or ROC_LLVM_BIN), or install the tools under tools/remill "
            "and tools/llvm. Nothing is downloaded automatically." % tools["reason"])


def remill_available():
    return resolve_tools()["available"]


def describe(tools=None):
    """Short human summary safe for shared logs (basenames and versions only)."""
    tools = tools or resolve_tools()
    if not tools["available"]:
        return "not available: %s" % tools["reason"]
    return "%s (lifter %s) + %s (LLVM %s), from %s" % (
        tools["exe_name"], tools["lifter_version"], tools["opt_name"],
        tools["llvm_version"], ", ".join(sorted({source for source in
                                                 (tools["exe_source"], tools["opt_source"]) if source})))


def _paths(client, addr, out_dir=None):
    out_dir = Path(out_dir) if out_dir else (_repo_root() / "work" / client / "lifted" / addr)
    out_dir.mkdir(parents=True, exist_ok=True)
    return out_dir, {
        "ll": out_dir / ("%s.ll" % addr),
        "bc": out_dir / ("%s.bc" % addr),
        "pre": out_dir / ("%s.pre.ll" % addr),
        "summary": out_dir / ("%s.summary.json" % addr),
        "text": out_dir / ("%s.summary.txt" % addr),
    }


def _cfg(client, addr):
    code, relocs, row = match.target(client, addr)
    va = int(addr, 16)
    lines = match.disasm(code, va)
    facts = draft.cfg_facts(lines)
    indirect = 0
    calls = 0
    for line in lines:
        text = line.split(None, 2)[-1] if isinstance(line, str) else ""
        low = text.lower()
        if "call" in low:
            calls += 1
            if "dword ptr" in low or not re.search(r"\bcall\s+(?:0x)?[0-9a-f]{6,}\b", low):
                indirect += 1
    original_branches = sum(1 for b in facts.get("blocks", [])
                            for e in b.get("edges", []) if e.get("kind") == "branch")
    original_returns = len(facts.get("returns", []))
    original_cfg_blocks = len(facts.get("blocks", [])) or 1
    return (code, relocs, row, va, lines, facts, calls, indirect,
            original_cfg_blocks, original_branches, original_returns)


def summarize_ir(text, addr, original_cfg_blocks, indirect_calls,
                 original_branches=0, original_returns=0, max_chars=1800):
    """Build a small, actionable evidence packet instead of an operation census.

    Counts are kept only when they answer a reconstruction question (control
    flow, memory traffic, call sites, constants).  ``max_chars`` bounds the
    prompt contribution; callers can inspect ``truncated`` in the summary.
    """
    labels = re.findall(r"(?m)^\s*(?:\d+|[A-Za-z_][\w.]*)\s*:\s*(?:;.*)?$", text)
    blocks = len(labels)
    br = len(re.findall(r"\bbr\b", text))
    ret = len(re.findall(r"\bret\b", text))
    loads = len(re.findall(r"\bload\b", text))
    stores = len(re.findall(r"\bstore\b", text))
    calls = len(re.findall(r"\bcall\b", text))
    helpers = sorted(set(re.findall(r"@__remill_[A-Za-z0-9_]*", text)))
    arith_ops = ["add", "sub", "mul", "and", "or", "xor", "shl", "lshr", "ashr"]
    arith = sum(len(re.findall(r"\b" + op + r"\b", text)) for op in arith_ops)
    constants = []
    for match_imm in re.finditer(r"\bi32\s+(-?\d+)\b", text):
        value = match_imm.group(1)
        if value not in constants:
            constants.append(value)
        if len(constants) >= 12:
            break
    verified_structure = (ret >= max(1, original_returns))
    unresolved = []
    if indirect_calls:
        unresolved.append("original has %d opaque/indirect call site(s); lifted IR models them as "
                          "state/memory operations, not named calls" % indirect_calls)
    if original_branches and br < original_branches:
        unresolved.append("branch coverage differs (original CFG %d, lifted %d); treat as a sanity "
                          "check, not proof" % (original_branches, br))
    if not verified_structure:
        unresolved.append("return count differs from the original CFG (%d vs %d)"
                          % (ret, original_returns))
    if original_cfg_blocks > 1 and blocks and abs(blocks - original_cfg_blocks) > 2:
        unresolved.append("block count differs (%d lifted vs %d original); inline data or "
                          "jump tables may explain it" % (blocks, original_cfg_blocks))
    if not unresolved:
        unresolved.append("none recorded by static checks; ABI, types and data layout remain "
                          "unverified assumptions")
    summary = {
        "address": "0x" + addr.lower().replace("0x", "").zfill(8),
        "original_cfg_blocks": original_cfg_blocks,
        "original_branches": original_branches,
        "original_returns": original_returns,
        "indirect_calls": indirect_calls,
        "lifted_blocks": blocks,
        "lifted_branches": br,
        "lifted_returns": ret,
        "memory_ops": loads + stores,
        "lifted_calls": calls,
        "arithmetic_ops": arith,
        "constants_sample": constants,
        "helpers_sample": helpers[:8],
        "unresolved": unresolved,
        "verification_scope": "llvm-verifier: IR is well formed; this does NOT prove semantic "
                              "equivalence to the original C++",
        "coverage_note": "CFG coverage is approximate; jump tables and inline data may not "
                         "correspond 1:1",
        "truncated": False,
    }
    lines = [
        "Remill evidence packet (not the original source)",
        "================================================",
        "function: 0x%s" % addr.lower().replace("0x", "").zfill(8),
        "control flow: %d lifted block(s), %d conditional/unconditional branch(es), %d return(s); "
        "original CFG %d block(s), %d branch(es), %d return(s)" %
        (blocks, br, ret, original_cfg_blocks, original_branches, original_returns),
        "memory: %d load(s) + %d store(s); calls in IR: %d; arithmetic/flag operations: %d" %
        (loads, stores, calls, arith),
        "constants (sample): %s" % (", ".join(constants[:8]) if constants else "none"),
        "helpers (sample): %s" % (", ".join(helpers[:5]) if helpers else "none"),
        "unresolved assumptions: " + "; ".join(unresolved),
        "use the original disassembly for names/ABI/types; LLVM verified only that the IR is "
        "well formed, not that it matches the original C++",
    ]
    compact = "\n".join(lines)
    if len(compact) > max_chars:
        summary["truncated"] = True
        compact = compact[:max_chars].rsplit("\n", 1)[0] + "\n[packet truncated at %d chars]" % max_chars
    summary["chars"] = len(compact)
    summary["estimated_tokens"] = max(1, len(compact) // 4)
    return summary, compact


def _cache_matches(cached, code_sha, tools):
    if not isinstance(cached, dict):
        return False
    if cached.get("code_sha256") != code_sha or cached.get("verified") is not True:
        return False
    if tools.get("cache_key") and cached.get("toolchain_key") == tools["cache_key"]:
        return True
    # Older summaries have no toolchain key.  Accept them only when the exact
    # lifter identity still matches, and never after a toolchain change.
    return (not tools.get("cache_key") and cached.get("lifter_path") == tools.get("exe")
            and cached.get("lifter_mtime") == _lifter_mtime(tools))


def _lifter_mtime(tools):
    try:
        return Path(tools["exe"]).stat().st_mtime
    except (OSError, TypeError, KeyError):
        return 0


def lift_function(client, addr, out_dir=None, timeout=180, max_chars=1800, refresh=False):
    addr = addr.lower().replace("0x", "").zfill(8)
    tools = resolve_tools(refresh=refresh)
    if not tools["available"]:
        raise RuntimeError(not_available_message(tools))
    code, relocs, row, va, lines, facts, calls, indirect, cfg_blocks, branches, returns = _cfg(client, addr)
    code_sha = hashlib.sha256(code).hexdigest()
    memo_key = (client, addr, code_sha, tools["cache_key"])
    with _MEMO_LOCK:
        if memo_key in _MEMO:
            return _MEMO[memo_key]
    out_dir, paths = _paths(client, addr, out_dir)
    summary_path = paths["summary"]
    if summary_path.is_file() and paths["ll"].is_file() and paths["bc"].is_file():
        try:
            cached = json.loads(summary_path.read_text(encoding="utf-8"))
        except ValueError:
            cached = None
        if _cache_matches(cached, code_sha, tools):
            compact = paths["text"].read_text(encoding="utf-8") if paths["text"].is_file() else ""
            result = (cached, compact, paths)
            with _MEMO_LOCK:
                _MEMO[memo_key] = result
            return result
    cmd = [
        tools["exe"],
        "--arch=%s" % LIFT_OPTIONS["arch"],
        "--os=%s" % LIFT_OPTIONS["os"],
        "--address=%d" % va,
        "--entry_address=%d" % va,
        "--bytes=%s" % code.hex(),
        "--ir_out=%s" % paths["ll"],
        "--bc_out=%s" % paths["bc"],
        "--ir_pre_out=%s" % paths["pre"],
    ]
    started = time.time()
    proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
    verified = False
    verify_error = ""
    # Prefer .ll (text IR) over .bc (bitcode) — Remill's bitcode format
    # is not always readable by newer LLVM opt versions.
    verify_path = paths["ll"] if paths["ll"].is_file() else paths["bc"]
    if verify_path.is_file():
        try:
            v = subprocess.run([tools["opt"], "-passes=verify", "-disable-output", str(verify_path)],
                               capture_output=True, text=True, timeout=120)
            verified = (v.returncode == 0)
            verify_error = (v.stderr or v.stdout or "").strip()
        except (OSError, subprocess.TimeoutExpired) as error:
            verify_error = str(error)
    text = paths["ll"].read_text(errors="replace") if paths["ll"].is_file() else ""
    summary, compact = summarize_ir(text, addr, cfg_blocks, indirect,
                                    original_branches=branches, original_returns=returns,
                                    max_chars=max_chars)
    summary.update({
        "client": client,
        "code_sha256": code_sha,
        "toolchain_key": tools["cache_key"],
        "lifter_path": tools["exe"],
        "lifter_name": tools["exe_name"],
        "lifter_version": tools["lifter_version"],
        "lifter_mtime": _lifter_mtime(tools),
        "opt_path": tools["opt"],
        "opt_name": tools["opt_name"],
        "llvm_version": tools["llvm_version"],
        "lift_options": dict(LIFT_OPTIONS),
        "size": row["size"],
        "function": row.get("unit"),
        "returncode": proc.returncode,
        "elapsed_seconds": round(time.time() - started, 2),
        "verified": verified,
        "verification_scope": summary["verification_scope"],
        "verify_error": verify_error[:500],
        "stdout_tail": (proc.stdout or "")[-500:],
        "stderr_tail": (proc.stderr or "")[-800:],
        "ir_path": str(paths["ll"]),
        "bc_path": str(paths["bc"]),
        "pre_path": str(paths["pre"]),
    })
    paths["summary"].write_text(json.dumps(summary, indent=2), encoding="utf-8")
    paths["text"].write_text(compact + "\n", encoding="utf-8")
    result = (summary, compact, paths)
    with _MEMO_LOCK:
        _MEMO[memo_key] = result
    return result


def latest_summary(client, addr):
    addr = addr.lower().replace("0x", "").zfill(8)
    path = _repo_root() / "work" / client / "lifted" / addr / ("%s.summary.json" % addr)
    if not path.is_file():
        return None
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except ValueError:
        return None
