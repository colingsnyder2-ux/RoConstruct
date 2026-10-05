#!/usr/bin/env python3
"""Compiler-in-the-loop source reconstruction: Ghidra pseudocode -> compilable C.

Technique (HELIOS / DecLLM style, 2026 state of the art):
  generate -> compile with MSVC -> feed compiler errors back -> repair -> repeat.
Compiler verdict is the oracle; no human proof needed per function.

Pipeline:
  1. python rebuild.py sample --n 40       # diverse functions from rbx2008m.db
  2. python rebuild.py run --limit 10      # codegen + cl /c + repair loop (idempotent)
  3. python rebuild.py stats               # compile rates
  4. python rebuild.py show <program> <addr>

Results live in the `rebuild` table of work/re/rbx2008m.db.
Everything local ($0 API): qwen2.5-coder:7b-instruct via Ollama + cl.exe from VS 18.
"""

import argparse
import json
import os
import re
from re import error
import sqlite3
import subprocess
import sys
import time
import urllib.request

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from summarize import (DEFAULT_DB, LIB_NAME, OLLAMA, connect,  # noqa: E402
                       ollama_chat, truncate)

RE_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), "work", "re")
BUILD_DIR = os.path.join(RE_DIR, "build")
MODEL_CODE = os.environ.get("RE_MODEL_CODE", "qwen2.5-coder:7b-instruct")
def find_vcvars():
    candidates = (
        os.environ.get("ROCONSTRUCT_VCVARS", ""),
        r"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars32.bat",
        r"C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat",
        r"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat",
    )
    for candidate in candidates:
        if os.path.isfile(candidate):
            return candidate
    raise FileNotFoundError("MSVC x86 tools missing. Run RoConstruct setup tools.")


VCVARS = find_vcvars()

REBUILD_SCHEMA = """
CREATE TABLE IF NOT EXISTS rebuild(
    program TEXT NOT NULL,
    addr TEXT NOT NULL,
    name TEXT,
    code TEXT,
    compiles INTEGER NOT NULL DEFAULT 0,
    attempts INTEGER NOT NULL DEFAULT 0,
    first_try INTEGER NOT NULL DEFAULT 0,
    last_err TEXT,
    model TEXT,
    updated_at TEXT,
    PRIMARY KEY(program, addr)
);
"""

PROMPT = """You are reconstructing source code from a decompiled 2008 Roblox \
Windows client binary (x86, MSVC era, C/C++). Fidelity to the original \
behavior is the goal.

Ghidra decompilation of function {name} at {addr} in {program}:

```c
{code}
```

"""

PROMPT_CALLEES = """
Known signatures of functions it calls (use these exact prototypes where \
possible; otherwise declare old-style `int name();` so calls type-check):
{callees}
"""

PROMPT_RULES = """Rewrite it as ONE self-contained C++ translation unit that compiles with
MSVC: `cl /nologo /c /TP /W0 /D_CRT_SECURE_NO_WARNINGS file.cpp`.

Rules:
- Keep the function's logic faithful: same control flow, same operations,
  same order. Do not add features, do not change behavior.
- Add everything needed at the top of the file to compile: #includes,
  typedefs (use <stdint.h> fixed-width types), struct/class/enum definitions
  with field offsets implied by the pseudocode, extern declarations for
  globals (DAT_*, s_*, PTR_*), and prototypes for callees.
- Replace Ghidra types: undefined1/uchar->uint8_t, undefined2/ushort->uint16_t,
  undefined4/uint->uint32_t, undefined8/ulong->uint64_t, undefined->uint32_t,
  longlong->int64_t. The Ghidra token `bool` becomes plain C++ `bool`.
  NEVER emit a typedef that pairs a width with bool (e.g. `uint32_t bool;`
  is illegal) -- just use `bool` on its own.
- KEEP the calling convention keyword (__thiscall / __stdcall / __fastcall)
  exactly as Ghidra emitted it - it is part of the real x86 ABI.
- The Ghidra `this` pointer is a normal first parameter here. Declare it as
  `void *self` (or a typed pointer) and use `self` in the body. Never name a
  parameter `this` - it is a C++ keyword.
- Declare every function you call. If its signature is unknown, declare it as
  `extern intptr_t NAME();` (an empty parameter list accepts any arguments).
- Never reference an identifier you have not declared. No `field_0`, `param_1`,
  `local_8`, `uVar1` etc. may appear as bare globals - make them locals.
- Output ONLY the complete file contents. No markdown fences, no commentary."""

PROMPT_REPAIR = """Your previous attempt failed to compile under MSVC. Compiler output:

{err}

Return the FULL corrected translation unit (entire file, code only)."""

CL_FLAGS = ["/nologo", "/c", "/TP", "/W0", "/D_CRT_SECURE_NO_WARNINGS"]

# Calling conventions the 2008 client actually uses (MSVC x86 ABI) - these are
# C++ extensions, so translation units must compile with /TP, not /TC.
_CCONV = r"__thiscall|__stdcall|__fastcall|__clrcall|__vectorcall"
_CCONV_RE = re.compile(r"\b(?:%s)\b" % _CCONV)

# `this` is a keyword in C++ but Ghidra emits it as an explicit parameter of
# __thiscall-annotated functions -> rename mechanically to this_.
_THIS_PARAM_RE = re.compile(
    r"(?<![A-Za-z0-9_])this(?![A-Za-z0-9_])")


def cxx_fix(code):
    """Mechanical C++ legality pass (no LLM).

    Ghidra emits `void __thiscall f(Type *this, ...)` -- a free function with
    a parameter literally named `this`, which is a C++ keyword (error C2377 /
    'this' cannot appear in a global declaration).

    For __thiscall/__stdcall/__fastcall functions we do NOT rename: those get
    wrapped as class members by fix_thiscall, where the implicit `this`
    replaces the explicit parameter. Everything else (plain __cdecl functions)
    gets the safe rename to `self_`.
    """
    if not code:
        return code
    out = code
    # protect the calling-convention tokens themselves
    out = _CCONV_RE.sub(lambda m: "\x00CC" + m.group(0)[2:] + "\x00", out)
    # protect the parameter list of a convention-annotated definition so the
    # later rename does not touch it
    out = re.sub(r"(\x00CC(?:his|td|ast)call\x00\s+[A-Za-z_]\w*\s*\([^)]*\))",
                 lambda m: m.group(1).replace("this", "\x00T\x00"), out)
    # struct/union member declaration:  <type> ... this ;
    out = re.sub(r"(?m)^(\s*[A-Za-z_][\w\s:*&<>]*?)\bthis\s*(;)",
                 r"\1self_\2", out)
    # remaining bare uses -> self_
    out = _THIS_PARAM_RE.sub("self_", out)
    out = (out.replace("\x00CC", "__").replace("\x00", "")
              .replace("self_", "self_"))
    return out


# ---------------------------------------------------------------- engines

def ollama_generate_raw(model, prompt, num_ctx=4096, num_predict=2048,
                        timeout=600):
    """Base-model completion (no chat template) — LLM4Decompile-Ref style."""
    payload = json.dumps({
        "model": model,
        "prompt": prompt,
        "raw": True,
        "stream": False,
        "options": {"temperature": 0.1, "num_ctx": num_ctx,
                    "num_predict": num_predict},
    }).encode("utf-8")
    req = urllib.request.Request(OLLAMA + "/api/generate", data=payload,
                                 headers={"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        data = json.loads(resp.read().decode("utf-8"))
    return data.get("response", "") or ""


# LLM4Decompile-Ref v2 prompt wrapper (paper: base completion, 4096 ctx)
REF_WRAP = "# This is the assembly code:\n%s\n# What is the source code?\n"


def generate(conn, fn, model, repair_err=None):
    """Dispatch by engine family: base decomp models get raw completion,
    chat models get the full rule-set prompt + repair context."""
    if any(t in model.lower() for t in ("llm4decompile", "cim-", "codeinverter")):
        _program, _addr, _name, decompiled = fn
        p = REF_WRAP % truncate(decompiled or "", head=3000, tail=800)
        if repair_err:
            p += ("The previous attempt does not compile:\n%s\n"
                  "# What is the source code?\n" % repair_err[-600:])
        return ollama_generate_raw(model, p)
    return ollama_chat(model, build_prompt(conn, fn, repair_err),
                       num_ctx=8192, num_predict=4000, timeout=600)


# ---------------------------------------------------------------- sample

def sample(conn, n):
    rows = conn.execute(
        """SELECT program, addr FROM functions
           WHERE is_thunk = 0 AND tier IN ('fast','main')
             AND length(decompiled) BETWEEN 700 AND 6000
           ORDER BY length(decompiled)""").fetchall()
    if not rows:
        print("sample: no candidates")
        return
    stride = max(1, len(rows) // n)
    picks = rows[::stride][:n]
    for program, addr in picks:
        conn.execute("INSERT OR IGNORE INTO rebuild(program, addr) VALUES(?,?)",
                     (program, addr))
    conn.commit()
    print("sample: %d/%d candidates -> %d picked" % (len(picks), len(rows), n))


# ---------------------------------------------------------------- prompt

def callee_lines(conn, program, addr):
    out = []
    try:
        rows = conn.execute(
            """SELECT f.addr, f.name, f.sig FROM edges e
               JOIN functions f ON f.program=e.program AND f.addr=e.dst
               WHERE e.program=? AND e.src=? LIMIT 40""",
            (program, addr)).fetchall()
    except sqlite3.Error:
        return out
    for dst, name, sig in rows:
        if sig:
            out.append(sig if sig.endswith(";") else sig + ";")
        else:
            out.append("void %s();" % (name or dst))
    return out


def build_prompt(conn, fn, repair_err=None):
    program, addr, name, decompiled = fn
    p = PROMPT.format(name=name or "?", addr=addr, program=program,
                      code=truncate(decompiled or "", head=5200, tail=1200))
    callees = callee_lines(conn, program, addr)
    if callees:
        p += PROMPT_CALLEES.format(callees="\n".join(callees))
    p += PROMPT_RULES
    if repair_err:
        p += ("The previous attempt does not compile:\n%s\n"
              "# What is the source code?\n" % repair_err[-1500:])
    return p


# ---------------------------------------------------------------- prelude

# C keywords / stdlib we must never redeclare
_C_BUILTIN = set("""if else for while do switch case default break continue return
sizeof typedef struct enum union static extern const volatile inline register
void char short int long float double signed unsigned size_t int8_t int16_t
int32_t int64_t uint8_t uint16_t uint32_t uint64_t intptr_t uintptr_t
va_list va_start va_arg va_end va_copy printf sprintf fprintf snprintf
malloc calloc realloc free memcpy memset memmove memcmp strlen strcmp strncmp
strcpy strncpy strcat abort exit NULL true false""".split())

_IDENT_CALL = re.compile(r"(?<![.\w>])([A-Za-z_][A-Za-z_0-9]*(?:::[A-Za-z_][A-Za-z_0-9]*)*)\s*\(")
_IDENT_DECL = re.compile(
    r"^\s*(?:static\s+|extern\s+|inline\s+|const\s+|volatile\s+)*"
    r"[A-Za-z_][A-Za-z_0-9\s*]*?\b([A-Za-z_][A-Za-z_0-9]*)\s*\(", re.M)
_DEF_NAME = re.compile(
    r"^\s*(?:static\s+|extern\s+|inline\s+)*[A-Za-z_][A-Za-z_0-9]*\s*"
    r"(?:\*\s*|\s)?([A-Za-z_][A-Za-z_0-9]*)\s*\([^;{]*\)\s*\{", re.M)


def auto_prelude(code):
    """Mechanically declare every called-but-undeclared identifier.

    Ghidra emits C++-mangled callee names (Ogre_DynLibManager_unload) and
    data symbols (DAT_xxx) that models forget to declare -> C2061/C2065.
    Emitting `intptr_t f();` declarations kills that whole error class
    without an LLM round-trip. Redeclaration of the same name is avoided by
    scanning existing prototypes/definitions first.
    """
    if not code:
        return code
    # names already declared or defined in this file
    known = set(_C_BUILTIN)
    for m in _IDENT_DECL.finditer(code):
        known.add(m.group(1))
    for m in _DEF_NAME.finditer(code):
        known.add(m.group(1))
    # names declared via typedef struct X {...} X;  and  enum X
    for m in re.finditer(r"\b(?:struct|enum|union)\s+([A-Za-z_][A-Za-z_0-9]*)", code):
        known.add(m.group(1))

    needed_fns, needed_data = [], []
    # strip strings/comments so we don't match text inside them
    scan = re.sub(r"/\*.*?\*/", " ", code, flags=re.S)
    scan = re.sub(r"//[^\n]*", " ", scan)
    scan = re.sub(r'"(?:\\.|[^"\\])*"', '""', scan)

    for m in _IDENT_CALL.finditer(scan):
        nm = m.group(1)
        if nm in known:
            continue
        # control-flow keywords already filtered; skip if it's a definition
        known.add(nm)
        needed_fns.append(nm)
    # data symbols: DAT_*, s_*, PTR_*, iVar-style globals referenced bare
    for m in re.finditer(r"(?<![.\w])(DAT_[0-9A-Fa-f]+|s_[0-9A-Fa-f]+|"
                         r"PTR_[A-Za-z_0-9]+|_[A-Z]{2,}_[0-9A-Fa-f]+)\b", scan):
        nm = m.group(1)
        if nm in known:
            continue
        known.add(nm)
        needed_data.append(nm)

    if not needed_fns and not needed_data:
        return code
    block = ["/* --- auto-prelude (mechanical declarations) --- */"]
    for nm in needed_data:
        block.append("extern unsigned char %s[];" % nm)
    for nm in needed_fns:
        block.append("extern intptr_t %s();" % nm)
    block.append("/* --- end auto-prelude --- */")

    # insert after existing #includes so <stdint.h> (intptr_t) is available
    lines = code.split("\n")
    insert_at = 0
    for i, ln in enumerate(lines):
        if ln.lstrip().startswith("#include"):
            insert_at = i + 1
        elif ln.strip() and not ln.lstrip().startswith(("#include", "#pragma",
                                                        "#define", "/*", "*", "//")):
            break
    head = "\n".join(lines[:insert_at])
    tail = "\n".join(lines[insert_at:])
    if "#include <stdint.h>" not in code:
        head += "\n#include <stdint.h>"
    return head + "\n" + "\n".join(block) + "\n" + tail


_UNKNOWN_SYM = re.compile(
    r"^(?:DAT_|PTR_|UNK_|s_|iDAT_|_DAT_)[0-9A-Fa-f_]+$"
    r"|^FUN_[0-9A-Fa-f]{4,}$")

# Names that are LOCAL variables or C++ keywords, never globals. Models emit
# Ghidra's `local_8` / `uVar1` / `param_1` naming; declaring those as extern
# arrays collides with the real locals and breaks the parse (C2059/C2377).
_LOCAL_NAMES = re.compile(
    r"^(?:local|param|uVar|iVar|puVar|inVar|extraout|inStack|dVar|bVar|cVar)"
    r"[_0-9A-Fa-f]*$")

_CPP_KEYWORDS = set("""alignas alignof and and_eq asm auto bitand bitor bool break
case catch char char8_t char16_t char32_t class compl concept const consteval
constexpr constinit const_cast continue co_await co_return co_yield decltype
default delete do double dynamic_cast else enum explicit export extern false
float for friend goto if inline int int8_t int16_t int32_t int64_t long mutable
namespace new noexcept not not_eq nullptr operator or or_eq private protected
public register reinterpret_cast requires return short signed sizeof static
static_assert static_cast struct switch template this thread_local throw true
try typedef typeid typename union unsigned using virtual void volatile wchar_t
while xor xor_eq include define pragma intptr_t uintptr_t size_t NULL""".split())


_DECL_LINE = re.compile(
    r"^[ \t]*(?:extern|static|const|volatile|register|inline)[ \t]+"
    r"(?:[A-Za-z_][\w \t]*?\*?[ \t]*)?"
    r"(?P<n1>[A-Za-z_]\w*)[ \t]*\(",
    re.M)
_DECL_DATA = re.compile(
    r"^[ \t]*(?:extern|static|const|volatile|register)[ \t]+"
    r"(?:[A-Za-z_][\w \t]*?\*?[ \t]*)?"
    r"(?P<n2>[A-Za-z_]\w*)[ \t]*(?:\[[^\]]*\])?[ \t]*;",
    re.M)
_TYPEDEF_NAMES = re.compile(r"^[ \t]*typedef\b[^;]*?\b(?P<n3>[A-Za-z_]\w*)[ \t]*;",
                             re.M)
_STRUCT_NAMES = re.compile(
    r"\b(?:struct|class|union|enum)[ \t]+([A-Za-z_]\w*)")


def _model_declared(code):
    """Every identifier the model already declares at file scope.

    The canonical table must only fill GAPS. Declaring something the model
    already declared produces 'overloaded function differs only by return
    type' (C2556) / 'differs in levels of indirection' (C2040) / 'redefinition'
    (C2733) -- which is what happens when we blindly re-declare FUN_* and CRT
    helpers the model already got right.
    """
    names = set()
    for rx in (_DECL_LINE, _DECL_DATA, _TYPEDEF_NAMES):
        for m in rx.finditer(code):
            for g in ("n1", "n2", "n3"):
                try:
                    v = m.group(g)
                except (IndexError, error):
                    v = None
                if v:
                    names.add(v)
                    break
    for m in _STRUCT_NAMES.finditer(code):
        names.add(m.group(1))
    # add_crt_externs declares these too; declaring them again here is C2556
    names |= {"memset", "memcpy", "memcmp", "free", "malloc", "realloc",
              "_purecall", "_invalid_parameter_noinfo"}
    # <windows.h> declares the Win32 API; re-declaring is C2556
    if "WINDOWS_H_MARKER" in code:
        names |= _WIN32_API_NAMES
    return names


def _strip_symbol_decls(code):
    """No-op: see normalize_symbols, which fills gaps instead of replacing.

    We deliberately keep the model's own declarations -- when it says
    `extern uint DAT_x[256];` for a 1 KB lookup table that is CORRECT, and
    replacing it with our generic `extern intptr_t DAT_x;` causes
    'differs in levels of indirection' (C2040).
    """
    return code


_WIN32_TYPES = set("""CRITICAL_SECTION HANDLE LPVOID DWORD WORD LONG ULONG LONG_PTR
SIZE_T BOOL BYTE CHAR WCHAR TCHAR BOOL LPSTR LPCSTR LPWSTR LPCWSTR HRESULT
HMODULE HINSTANCE HDC HWND HBITMAP HBRUSH HFONT HICON HCURSOR
HMENU HENHMETAFILE HGLOBAL HFILE HRSRC VARIANT_BOOL""".split())

# Types the model invents that collide with themselves or with the compiler.
_CONFLICTING_TYPEDEF = re.compile(
    r"(?m)^[ \t]*typedef[ \t]+[^;\n]*?\b(?P<nm>[A-Za-z_]\w*)[ \t]*;"
)


def strip_bad_typedefs(code):
    """Remove typedefs that shadow Win32 headers or redefine themselves.

    C2377 ('CRITICAL_SECTION': typedef cannot be overloaded) and C2371
    ('longlong': redefinition) come from the model re-declaring types the
    SDK/compiler already provide. Drop those; keep everything else.
    """
    if not code:
        return code
    out = []
    for ln in code.split("\n"):
        m = _CONFLICTING_TYPEDEF.match(ln)
        if m:
            nm = m.group("nm")
            if nm in _WIN32_TYPES or nm in _CPP_KEYWORDS or \
                    nm in ("longlong", "ulong", "ushort", "uchar", "undefined",
                           "undefined1", "undefined2", "undefined4", "undefined8",
                           "int8", "int16", "int32", "int64", "uint8", "uint16",
                           "uint32", "uint64", "dword", "word", "qword"):
                continue
        out.append(ln)
    return "\n".join(out)


_WIN32_API_NAMES = set("""
GetCurrentThreadId GetTickCount Sleep CloseHandle GetProcAddress
LoadLibraryA LoadLibraryW LoadLibraryExA FreeLibrary GetModuleHandleA
GetModuleHandleW GetModuleFileNameA GetDC ReleaseDC BeginPaint EndPaint
PostMessageA PostMessageW SendMessageA SendMessageW ShowWindow
DestroyWindow CreateWindowExA CreateWindowExW GetClientRect SetWindowPos
CoInitialize OleInitialize HeapAlloc HeapFree GlobalAlloc GlobalFree
LocalAlloc LocalFree VirtualAlloc VirtualFree TlsAlloc TlsGetValue
TlsSetValue TlsFree InterlockedIncrement InterlockedDecrement
EnterCriticalSection LeaveCriticalSection InitializeCriticalSection
DeleteCriticalSection CreateThread _beginthreadex ExitProcess
GetLastError SetLastError GetSystemDirectoryA GetSystemDirectoryW
GetWindowsDirectoryA GetTempPathA CreateFileA CreateFileW
ReadFile WriteFile DeviceIoControl GetVersionExA
""".split())


_ALLOCATOR_OPS = ()


def add_allocator_ops(code):
    """Strip the model's own operator new/delete declarations.

    C++ already provides both, so declaring them ourselves is wrong twice
    over: `extern intptr_t operator_new();` makes `puVar1 = operator_new(4)`
    assign an integer to a pointer (C2440), and `extern "C" void*
    operator_new[](uint32_t);` is illegal C++ (C2092). Removing the model's
    version lets the real operators do their job.
    """
    if not code or "ALLOC_OPS_MARKER" in code:
        return code
    if not re.search(r"(?<![.\w])operator_(?:new|delete)", code):
        return code
    out = re.sub(
        r"(?m)^[ \t]*(?:extern|static|typedef)?[ \t]*[^;\n]*"
        r"\boperator_(?:new|delete)\b[^;\n]*;[ \t]*\n?", "", code)
    return "/* ALLOC_OPS_MARKER: model decls stripped, compiler's used */\n" + out


_VOIDP_LHS = (
    "ExceptionList", "ExceptionList_1", "ExceptionList_2", "ExceptionList_3",
    "puStack_c", "_except_list", "ScopeTable", "GlobalSecurityCookie",
)


def fix_voidp_assignments(code):
    """Cast a void* SEH global when it is READ into a typed destination.

    C++ converts T* -> void* implicitly, but NOT void* -> T*:
        ExceptionList = &local_10;   /* void*  = uint8_t*  ok  */
        local_10 = ExceptionList;    /* uint8_t* = void*  C2440 */
    The failing case is the void* on the RIGHT. We do not know the
    destination's type textually, but `decltype(dest)(src)` reproduces it
    exactly, and we are already compiling as C++ (/TP).
    """
    if not code or "SEH_GLOBALS_MARKER" not in code:
        return code
    names = "|".join(re.escape(n) for n in _VOIDP_LHS if n in code)
    if not names:
        return code

    def cast(m):
        var, rhs = m.group("var"), m.group("rhs")
        if re.match(r"^\s*\(", rhs):
            return m.group(0)                     # already a cast
        return "%s = decltype(%s)(%s);" % (var, var, rhs)

    out = re.sub(
        r"(?m)^(?P<var>[ \t]*[A-Za-z_][A-Za-z_0-9.\->\[\]]*)[ \t]*=[ \t]*"
        r"(?P<rhs>(?:%s))[ \t]*;" % names,
        cast, code)
    return out


_MSVC_SEH_GLOBALS = {
    # MSVC structured-exception plumbing. Its types are incompatible with the
    # model's guesses (`ExceptionList = &local_10` where local_10 is uint8_t*),
    # giving C2440. void* accepts every assignment in the SEH dance.
    "ExceptionList": "extern void *ExceptionList;",
    "ExceptionList_1": "extern void *ExceptionList_1;",
    "ExceptionList_2": "extern void *ExceptionList_2;",
    "ExceptionList_3": "extern void *ExceptionList_3;",
    "puStack_c": "extern void *puStack_c;",
    "_except_list": "extern void *_except_list;",
    "ScopeTable": "extern void *ScopeTable;",
    "GlobalSecurityCookie": "extern void *GlobalSecurityCookie;",
    "__security_cookie": "extern void *__security_cookie;",
    "DAT_006d1c74": "extern void *DAT_006d1c74;",
}


def add_seh_globals(code):
    """Declare MSVC SEH globals with a permissive type, once."""
    if not code or "SEH_GLOBALS_MARKER" in code:
        return code
    decls = []
    for nm, dcl in _MSVC_SEH_GLOBALS.items():
        if re.search(r"(?<![.\w])%s\b" % re.escape(nm), code):
            # strip the model's own declaration of it first
            code = re.sub(
                r"(?m)^[ \t]*(?:extern|static)?[ \t]*[^;\n]*\b%s\b[^;\n]*;"
                r"[ \t]*\n?" % re.escape(nm), "", code)
            decls.append(dcl)
    if not decls:
        return code
    return ("/* SEH_GLOBALS_MARKER */\n" + "\n".join(decls)
            + "\n/* end SEH globals */\n" + code)


_ALL_NAMESPACES = ("RBX", "Ogre", "ATL", "G3D", "std")


_QUALIFIED = re.compile(r"\b([A-Z][A-Za-z0-9_]*)::([A-Za-z_][A-Za-z0-9_]*)")


def declare_namespaces(code):
    """Make every qualified name the model writes resolvable.

    `RBX::Instance` with no `namespace RBX` is C2653. An empty
    `namespace RBX { }` fixes that but then `RBX::MouseCommand` fails with
    C2039 ('MouseCommand': is not a member of 'RBX'). So each namespace is
    opened once and every unknown member referenced through it is aliased to
    void inside that namespace.

    Emitting a second `namespace RBX { }` is itself an error (C2869: has
    already been defined to be a namespace), so a namespace the model already
    opens is left alone.
    """
    if not code or "NAMESPACE_DECLS_MARKER" in code:
        return code
    used = [ns for ns in _ALL_NAMESPACES if re.search(r"\b%s\s*::" % ns, code)]
    if not used:
        return code

    already = set(re.findall(r"(?m)^\s*namespace\s+([A-Za-z_]\w*)\s*\{", code))
    # a namespace the model also defined as a STRUCT of the same name would
    # collide: "'RBX': has already been defined to be a namespace" (C2869)
    as_type = namespaces_defined_as_types(code)
    flat = _model_declared(code)
    block = ["/* --- namespace forward declarations --- */"]
    for ns in used:
        if ns in already or ns in as_type:
            continue
        members = []
        for m in _QUALIFIED.finditer(code):
            if m.group(1) != ns:
                continue
            mem = m.group(2)
            if mem in flat or mem in members or mem in _CPP_KEYWORDS:
                continue
            members.append(mem)
        block.append("namespace %s {" % ns)
        for mem in members[:80]:
            block.append("typedef void %s;" % mem)
        block.append("}")
    block.append("/* --- end namespace declarations --- */")
    if len(block) <= 2:
        return code
    return "\n".join(block) + "\n" + code


_DECL_NO_SEMI = re.compile(
    r"(?m)^(?P<head>[ \t]*(?:extern|static|const|volatile|unsigned|signed|"
    r"struct|class|enum|union|typedef)?[ \t]*[A-Za-z_][\w \t:*&<>]*?\b)"
    r"(?P<decl>[A-Za-z_]\w*(?:[ \t]*=[^;]*)?(?=[ \t]+[A-Za-z_]\w*[ \t]*(?:=|;|,|$)))")


def fix_missing_semis(code):
    """Insert the semicolons MSVC reports as C2146 / C2143 / C2059.

    DANGEROUS BY DESIGN, therefore NOT run in prepare(): the pattern that
    identifies a missing `;` (`char byte`, `int count`) is indistinguishable
    from a perfectly legal declaration (`typedef unsigned char byte;`),
    and inserting a `;` there turns a working file into
    "'uint8_t': typedef cannot be overloaded" (C2377).

    So this only runs from the repair ladder, keyed on the compiler actually
    reporting one of those codes. It is additionally restricted to lines
    inside a function body, which is where the models really do merge
    statements (`int a = 1 int b = 2`).
    """
    if not code:
        return code
    out_lines = []
    depth = 0
    for ln in code.split("\n"):
        s = ln.strip()
        if (depth > 0 and s and not s.startswith(("#", "//", "/*", "*"))
                and "typedef" not in s):
            ln = re.sub(
                r"([A-Za-z0-9_\)\]\}])([ \t]{1,})"
                r"((?:unsigned\s+|signed\s+)?(?:int|uint\d*_t|char|short|long|"
                r"float|double|bool|void|size_t|DWORD|undefined\d?)"
                r"[ \t]+[A-Za-z_]\w*)",
                r"\1;\2\3", ln)
        out_lines.append(ln)
        depth += ln.count("{") - ln.count("}")
    return "\n".join(out_lines)


_BASE_TYPES = """/* --- base scalar aliases (Ghidra + Win32 naming) --- */
typedef unsigned char  byte;
typedef unsigned char  BYTE;
typedef unsigned short word;
typedef unsigned short WORD;
typedef unsigned int   dword;
typedef unsigned int   DWORD;
typedef unsigned long long qword;
typedef unsigned int   undefined;
typedef unsigned char  undefined1;
typedef unsigned short undefined2;
typedef unsigned int   undefined4;
typedef unsigned long long undefined8;
typedef int            BOOL;
typedef char          *LPSTR;
typedef const char    *LPCSTR;
typedef void          *PVOID;
typedef unsigned char  BYTE_;
/* --- end base scalars --- */"""


def add_base_types(code):
    """Ghidra/Win32 scalar aliases, emitted only when actually referenced.

    Missing `byte`/`dword`/`undefined4` is the single largest source of
    'undeclared identifier' (C2065) and 'missing type specifier' (C4430).
    """
    if not code or "_BASE_TYPES_MARKER" in code:
        return code
    body = code
    needed = []
    for alias in ("byte", "BYTE", "word", "WORD", "dword", "DWORD", "qword",
                  "undefined", "undefined1", "undefined2", "undefined4",
                  "undefined8", "BOOL", "LPSTR", "LPCSTR", "PVOID"):
        if re.search(r"(?<![.\w])%s\b" % re.escape(alias), body) and \
                alias not in _CPP_KEYWORDS:
            needed.append(alias)
    if not needed:
        return code
    lines = [_BASE_TYPES.split("\n")[0]]
    for ln in _BASE_TYPES.split("\n")[1:]:
        m = re.search(r"\b([A-Za-z_]\w*)\s*;", ln)
        if m and m.group(1) not in needed:
            continue
        lines.append(ln)
    block = "\n".join(lines)
    return "#include <stdint.h>\n" + block + "\n" + body


def add_windows_header(code):
    """Include <windows.h> when the code touches the Win32 API.

    Provides the REAL CRITICAL_SECTION / HANDLE / DWORD / GetCurrentThreadId
    / operator new+delete declarations, so the model's (often wrong) hand
    written versions collide: 'CRITICAL_SECTION: typedef cannot be overloaded'
    (C2377), 'GetCurrentThreadId: overloaded function differs only by return
    type' (C2556). With the SDK header we then strip the model's duplicates.
    """
    if not code or "WINDOWS_H_MARKER" in code:
        return code
    hit = False
    for nm in list(_WIN32_API_NAMES) + ["CRITICAL_SECTION", "HANDLE",
                                       "HRESULT", "LPVOID"]:
        if re.search(r"(?<![.\w])%s\b" % re.escape(nm), code):
            hit = True
            break
    if not hit:
        return code
    out = ("/* WINDOWS_H_MARKER */\n#include <windows.h>\n"
           "#include <objbase.h>\n" + code)
    # drop a duplicate include the model already emitted
    out = out.replace("#include <windows.h>\n#include <objbase.h>\n"
                      "#include <windows.h>", "#include <windows.h>")
    return out


_STRIP_WIN32_DECLS = re.compile(
    r"^[ \t]*typedef\b[^;{]*\{[^}]*\}[ \t\r\n]*"
    r"(CRITICAL_SECTION|HANDLE|HRESULT|LONG_PTR|ULONG_PTR|LPVOID|LPCSTR)"
    r"[ \t]*;[ \t]*\n?"
    r"|"
    r"^[ \t]*(?:extern|typedef)[ \t]+[^;\n]*\b"
    r"(CRITICAL_SECTION|HANDLE|HRESULT|HRESULT__|LONG_PTR|ULONG_PTR)\b"
    r"[^;\n]*;[ \t]*\n?",
    re.M | re.S)
_STRIP_WINAPI_PROTO = re.compile(
    r"(?m)^[ \t]*(?:extern|static)?[ \t]*[A-Za-z_][\w \t:*&]*?\b"
    r"(GetCurrentThreadId|GetTickCount|Sleep|CloseHandle|GetProcAddress|"
    r"LoadLibrary[AW]?|FreeLibrary|GetModuleHandle[AW]?|GetDC|ReleaseDC|"
    r"BeginPaint|EndPaint|PostMessage|SendMessage|ShowWindow|DestroyWindow|"
    r"CreateWindowEx[AW]?|GetClientRect|SetWindowPos|CoInitialize|"
    r"OleInitialize|HeapAlloc|HeapFree|VirtualAlloc|TlsAlloc|TlsGetValue|"
    r"TlsSetValue|InterlockedIncrement|InterlockedDecrement)\s*"
    r"\([^;{]*\)\s*;[ \t]*\n?")


def strip_win32_decls(code):
    """Drop hand-rolled Win32 declarations now that <windows.h> is included."""
    if "WINDOWS_H_MARKER" not in code:
        return code
    code = _STRIP_WIN32_DECLS.sub("", code)
    code = _STRIP_WINAPI_PROTO.sub("", code)
    return code


OPAQUE_HEADER = os.path.join(RE_DIR, "types", "opaque.h")
_opaque_cache = None


def opaque_universe():
    """The shared type universe (work/re/types/opaque.h), loaded once.

    Every recovered class name is `typedef void`, so `ClassName *` is
    `void *` and converts implicitly from any object pointer. That removes the
    C2440/C2446/C2447/C2660/C2664/C2665 family that dominated failures.
    """
    global _opaque_cache
    if _opaque_cache is None:
        if not os.path.exists(OPAQUE_HEADER):
            return ""
        with open(OPAQUE_HEADER, "r", encoding="utf-8",
                  errors="replace") as f:
            _opaque_cache = f.read()
    return _opaque_cache


def add_opaque_universe(code):
    """Prepend the shared type universe, filtered to names this file uses.

    The full universe is 4,664 typedefs; emitting all of them per file makes
    every cl.exe invocation crawl. Only the names actually referenced here are
    emitted, which is typically a few dozen.
    """
    uni = opaque_universe()
    if not uni or "RBX_OPAQUE_UNIVERSE" in code:
        return code
    allnames = []
    for l in uni.split("\n"):
        m = re.match(r"^typedef void ([A-Za-z_]\w*);$", l.strip())
        if not m:
            continue
        nm = m.group(1)
        # C++ operators and allocator names are FUNCTIONS the compiler
        # already provides; aliasing them to void breaks `operator new`.
        if nm.startswith("operator") or nm.startswith("_") or \
                nm in ("new", "delete", "throw"):
            continue
        allnames.append(nm)
    body = re.sub(r"/\*.*?\*/", " ", code, flags=re.S)
    body = re.sub(r"//[^\n]*", " ", body)
    body = re.sub(r'"(?:\\.|[^"\\])*"', '""', body)
    # never shadow a type the model already defined itself: our
    # `typedef void X;` would collide with its `typedef struct X {...} X;`
    # -> 'X: redefinition; different basic types' (C2371)
    already = _model_declared(code)
    needed = [n for n in allnames
              if n not in already
              and re.search(r"(?<![.\w])%s\b" % re.escape(n), body)]
    if not needed:
        return code
    block = ("/* --- shared type universe (scripts/re/opaque.py) --- */\n"
             + "\n".join("typedef void %s;" % n for n in needed)
             + "\n/* --- end type universe --- */\n")
    return "#include <stdint.h>\n" + block + code


_TYPE_POSITION = re.compile(
    r"(?m)^(?P<lead>[ \t]*(?:extern|static|const|volatile)[ \t]*)"
    r"(?P<ty>[A-Z][A-Za-z0-9_]{2,})(?P<ptr>[ \t]*\*)"
    r"?[ \t]*(?P<var>[A-Za-z_]\w*)"
    r"(?P<tail>[ \t]*(?:\[[^\]]*\])?[ \t]*;)")


def alias_unknown_types(code):
    """Alias any unknown CAPITALISED type used in a declaration to void.

    `extern ThrowInfo s_DAT_1037a970;` with no `ThrowInfo` anywhere gives
    "missing type specifier" (C4430). Type names in C++ are capitalised by
    convention, so anything not already declared and not a known scalar gets
    `typedef void X;`.

    A declaration of a void-aliased type with no `*` becomes invalid C++ in
    turn ("this use of 'void' is not valid", C2182), so a `*` is added to
    those declarations -- `extern void ThrowInfo s_x;` -> `extern void *s_x;`
    """
    if not code or "TYPE_ALIASES_MARKER" in code:
        return code
    known = _model_declared(code) | _C_BUILTIN | _CPP_KEYWORDS | _WIN32_TYPES
    uni = set()
    for l in opaque_universe().split("\n"):
        m = re.match(r"^typedef void ([A-Za-z_]\w*);$", l.strip())
        if m:
            uni.add(m.group(1))

    needed = []

    def rewrite(m):
        ty = m.group("ty")
        if ty in known or ty in uni or ty in _CPP_KEYWORDS:
            return m.group(0)
        uni.add(ty)
        needed.append(ty)
        if m.group("ptr"):
            return m.group(0)
        # void-typed object declaration: make it a pointer
        return "%svoid *%s%s" % (m.group("lead"), m.group("var"), m.group("tail"))

    out = _TYPE_POSITION.sub(rewrite, code)
    if not needed:
        return code
    block = ("/* TYPE_ALIASES_MARKER: unknown type names -> void */\n"
             + "\n".join("typedef void %s;" % t for t in needed[:120])
             + "\n/* end type aliases */\n")
    return block + out


_TOPLEVEL_STRUCT = re.compile(
    r"(?m)^(?P<head>[ \t]*(?:struct|class|union)\b[^;{]*\{)"
    r"(?P<body>(?:[^{}]|\{[^{}]*\})*)"
    r"\}(?P<semi>[ \t]*;?)")


def fix_trailing_struct_semi(code):
    """`struct X { ... }` at file scope needs a `;` -> C1004 / C2059.

    Top-level definitions only (head must start the line with
    struct/class/union), so function bodies and struct members are untouched.
    """
    if not code:
        return code

    def add_semi(m):
        if m.group("semi").strip():
            return m.group(0)
        return "%s%s};" % (m.group("head"), m.group("body"))

    return _TOPLEVEL_STRUCT.sub(add_semi, code)


_QUALIFIED_EXTERN = re.compile(
    r"(?m)^[ \t]*(?:extern|static)[ \t]+[^;\n]*?\b"
    r"[A-Za-z_]\w*(?:::[A-Za-z_]\w*)+[ \t]*(?P<var>[A-Za-z_]\w*)[ \t]*;")


def unqualify_externs(code):
    """Remove file-scope declarations whose NAME is namespace-qualified.

    `extern RBX_RTTI_Type_Descriptor RBX::Instance::RTTI_Type_Descriptor;`
    is not legal C++ at file scope -- `A::B::c` there is parsed as a member
    access, giving "'c': is not a member of 'B'" (C2039). These are RTTI
    static-member declarations, decoration from the decompiler's point of
    view: nothing in the reconstructed logic depends on them, and any use of
    the name is stubbed by normalize_symbols. So the declaration is dropped
    rather than rewritten -- rewriting a qualified name safely is far harder
    than not needing it.
    """
    if not code or "::" not in code:
        return code
    out = _QUALIFIED_EXTERN.sub("/* qualified decl removed */", code)
    # also drop `extern void *A::B::c;` style pointers to qualified names
    out = re.sub(
        r"(?m)^[ \t]*(?:extern|static)[ \t]+[^;\n]*\b"
        r"[A-Za-z_]\w*(?:::[A-Za-z_]\w*)+[ \t]*;",
        "/* qualified decl removed */", out)
    return out


_ASM_BLOCK = re.compile(r"(?s)__asm[ \t]*(?:volatile|__volatile)?[ \t]*"
                        r"\{.*?\}")


def strip_asm(code):
    """Remove inline-assembly blocks.

    The model occasionally emits __asm { mov ecx, ... }. We cannot verify or
    link x86 asm meaningfully in this pipeline, and MSVC rejects it outright
    in /TP mode ("inline assembler syntax error", C2400). Dropping the block
    loses only the register shuffling; the surrounding logic still typechecks.
    """
    if not code or "__asm" not in code:
        return code
    out = _ASM_BLOCK.sub("/* asm block removed */", code)
    # a lone `__asm int 3;` style form
    out = re.sub(r"(?m)^[ \t]*__asm[ \t]+[^;\n]*;[ \t]*$",
                 "/* asm removed */", out)
    return out


_STRUCT_NAMED_LIKE_NS = re.compile(
    r"(?m)^[ \t]*(?:typedef[ \t]+)?(?:struct|class)[ \t]+"
    r"(?P<nm>[A-Z][A-Za-z0-9_]*)[ \t]*(?:\{|:)")


def namespaces_defined_as_types(code):
    """Namespaces the model turned into a STRUCT of the same name.

    Ghidra/RTTI renders some `RBX::X` as a class literally named RBX. If we
    also emit `namespace RBX { ... }` the two collide:
        "'RBX': has already been defined to be a namespace" (C2869)
    """
    return set(m.group("nm") for m in _STRUCT_NAMED_LIKE_NS.finditer(code))


def prepare(code):
    """Full deterministic preparation of model output for compilation.

    Always recomputed from the PRISTINE model output (never applied to an
    already-prepared file) so injected declarations can never accumulate.
    Order matters:
      strip_autoblocks -> remove anything we injected before
      cxx_fix          -> C++ legality (this/self_, keep cconv)
      fix_typedefs     -> illegal `<width> bool`
      strip_bad_typedefs -> shadow Win32 / self-redefining typedefs
      add_crt_externs  -> CRT helpers, only if referenced
      normalize_symbols-> ONE declaration per Ghidra symbol (replaces
                          auto_prelude/stub_undeclared entirely)
    """
    if not code:
        return code
    out = strip_autoblocks(code)
    out = strip_asm(out)
    out = cxx_fix(out)
    out = fix_typedefs(out)
    out = strip_bad_typedefs(out)
    out = add_base_types(out)
    out = add_opaque_universe(out)
    out = alias_unknown_types(out)
    out = fix_trailing_struct_semi(out)
    out = add_seh_globals(out)
    out = fix_voidp_assignments(out)
    out = add_allocator_ops(out)
    out = add_windows_header(out)
    out = strip_win32_decls(out)
    out = add_crt_externs(out)
    out = declare_namespaces(out)
    out = unqualify_externs(out)
    out = normalize_symbols(out)
    # <stdint.h> must be the FIRST thing: several injected blocks use
    # intptr_t / uint8_t, and emitting them above the include gives
    # 'missing type specifier' (C4430).
    if "#include <stdint.h>" in out:
        out = re.sub(r"^[ \t]*#include[ \t]*<stdint\.h>[ \t]*\n", "", out,
                     flags=re.M)
    return "#include <stdint.h>\n" + out


def normalize_symbols(code):
    """Emit exactly ONE declaration per unknown symbol (kills the whole
    C2040 / C2371 / C2372 / C2556 / C2733 conflict class).

    Ghidra data symbols are read at wildly different widths/indirections in
    the same function (`DAT_x` as uint32_t in one place, `char*` in another),
    so a per-use declaration is guaranteed to collide. One canonical
    declaration per symbol, chosen to be maximally permissive:

      - functions (called with parens)  -> extern intptr_t f();
      - everything else                 -> extern unsigned char SYM[64];
    """
    if not code:
        return code
    code = _strip_symbol_decls(code)

    scan = re.sub(r"/\*.*?\*/", " ", code, flags=re.S)
    scan = re.sub(r"//[^\n]*", " ", scan)
    scan = re.sub(r'"(?:\\.|[^"\\])*"', '""', scan)

    fns, datas, types = [], [], []
    seen = set()
    declared = _model_declared(code)

    def skip(nm):
        return (nm in seen or nm in _C_BUILTIN or nm in _CPP_KEYWORDS
                or _LOCAL_NAMES.match(nm) or nm.startswith("__")
                or _LOCAL_NAMES.match(nm) is None and re.match(
                    r"^(field|self|this|param)_?[0-9A-Fa-f]*$", nm))

    # symbol used as a call -> function (skip ones the model already declared)
    for m in _IDENT_CALL.finditer(scan):
        nm = m.group(1)
        if skip(nm) or nm in declared:
            continue
        seen.add(nm)
        fns.append(nm)
    # symbol used bare (not preceded by . or ->) -> data
    for m in re.finditer(r"(?<![.\w>-])([A-Za-z_]\w*)\b", scan):
        nm = m.group(1)
        if skip(nm):
            continue
        if re.search(r"\b(?:struct|class|union|enum)\s+%s\b" % re.escape(nm), code):
            continue
        if re.search(r"\btypedef\b[^;\n]*\b%s\b" % re.escape(nm), code):
            continue
        if re.search(r"(?m)^\s*(?:\w+\s+)+\**%s\s*\(" % re.escape(nm), code):
            continue
        # only accept Ghidra-looking data symbols. A loose "any bare word"
        # heuristic sweeps in struct field names (field_0), header
        # fragments (stdint/include) and parameter names, which produces
        # nonsense like `extern intptr_t stdint;` -> error C4430.
        if not _UNKNOWN_SYM.match(nm):
            continue
        if nm in declared:
            continue
        seen.add(nm)
        datas.append(nm)

    # Ghidra's naming convention: UNK_xxxxxxxx is an unknown *TYPE*
    # (undefined struct), not a variable. Using one as a cast target
    # ("cannot convert from 'UNK_x' to 'uint8_t'", error C2440) requires a
    # typedef, whereas DAT_/PTR_/s_ are variable addresses.
    for m in re.finditer(r"\b(UNK_[0-9A-Fa-f_]+)\b", scan):
        nm = m.group(1)
        if nm not in seen and nm not in declared:
            seen.add(nm)
            types.append(nm)

    if not fns and not datas and not types:
        return code
    block = ["/* --- canonical symbol table --- */"]
    for nm in types:
        block.append("typedef struct %s { uint8_t _opaque[64]; } %s;"
                     % (nm, nm))
    for nm in datas:
        # A pointer-sized OBJECT, not an array: Ghidra data is accessed both
        # as a scalar and via `&X`, and `extern intptr_t X;` accepts both,
        # while `unsigned char X[64]` breaks `&X` (C2296) and `X[0]` usage.
        block.append("extern intptr_t %s;" % nm)
    for nm in fns:
        block.append("extern intptr_t %s();" % nm)
    block.append("/* --- end canonical symbol table --- */")

    lines = code.split("\n")
    if "#include <stdint.h>" not in code:
        lines.insert(0, "#include <stdint.h>")
    insert_at = 0
    for i, ln in enumerate(lines):
        if ln.lstrip().startswith(("#include", "#pragma")):
            insert_at = i + 1
        elif ln.strip() and not ln.lstrip().startswith(("#include", "#pragma",
                                                        "#define", "/*", "*", "//")):
            break
    return "\n".join(lines[:insert_at]) + "\n" + "\n".join(block) + "\n" + \
        "\n".join(lines[insert_at:])


def extract_code(out):
    """Model output -> single C file (fences preferred, else heuristic trim).

    Guarantees brace balance: cutting at the LAST '}' is wrong because models
    append prose containing braces, and truncating mid-function yields C1075.
    We cut at the '}' that closes the last top-level function instead.
    """
    if not out:
        return ""
    blocks = re.findall(r"```(?:c|cpp|C)?\s*\n(.*?)```", out, re.S)
    if blocks:
        body = max(blocks, key=len).strip()
        return _trim_to_balance(body)
    start = out.find("#include")
    if start < 0:
        start = out.find("#pragma")
    if start < 0:
        m = re.search(r"^(?:typedef|struct|extern|void|int|long|char|"
                      r"static|const|unsigned|float|double|uint32_t|"
                      r"int32_t|uint64_t|bool)\b", out, re.M)
        start = m.start() if m else 0
    return _trim_to_balance(out[start:])


def _trim_to_balance(body):
    """Cut `body` after the brace that closes the last top-level definition."""
    body = body.strip()
    if not body:
        return body
    # walk braces, remembering the index of each top-level (depth-0) close
    depth = 0
    last_top_close = -1
    i = 0
    n = len(body)
    while i < n:
        ch = body[i]
        if ch == "/" and i + 1 < n and body[i + 1] == "/":
            j = body.find("\n", i)
            i = j if j != -1 else n
            continue
        if ch == "/" and i + 1 < n and body[i + 1] == "*":
            j = body.find("*/", i + 2)
            i = (j + 2) if j != -1 else n
            continue
        if ch == '"' or ch == "'":
            q = ch
            i += 1
            while i < n and body[i] != q:
                i += 2 if body[i] == "\\" else 1
            i += 1
            continue
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                last_top_close = i
        i += 1
    if last_top_close > 0:
        return body[:last_top_close + 1]
    if depth > 0:
        # unbalanced: close what we opened so the compiler can still parse it
        return body + "\n" + "}\n" * depth
    return body


# ---------------------------------------------------------------- compile

_CL_CACHE = {}


def vc_toolchain():
    """Locate cl.exe and its environment ONCE per process.

    `vcvars32.bat` costs ~8-10s per invocation (it rebuilds PATH/INCLUDE/LIB).
    The repair ladder compiles the same file up to 6 times, and a 176-function
    run would spend hours inside vcvars. Capture the environment once, then
    call cl.exe directly.

    The environment is captured through a generated .bat on purpose: passing
    `cmd /c 'call "x" && set'` as a LIST arg makes Python re-quote the string
    and the chain silently fails (rc=1, empty output).

    Returns (cl_path, env_dict).
    """
    if _CL_CACHE:
        return _CL_CACHE["cl"], _CL_CACHE["env"]

    os.makedirs(BUILD_DIR, exist_ok=True)
    envtxt = os.path.join(BUILD_DIR, "_vcenv.txt")
    bat = os.path.join(BUILD_DIR, "_vcenv.bat")
    with open(bat, "w", encoding="utf-8") as f:
        f.write('@echo off\r\n'
                'call "%s" >nul 2>&1\r\n'
                'set > "%s"\r\n' % (VCVARS, envtxt))
    subprocess.run([bat], capture_output=True, text=True, timeout=180)

    env = dict(os.environ)
    try:
        with open(envtxt, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                m = re.match(r"^([A-Za-z_][A-Za-z0-9_()]*)=(.*)$", line.rstrip("\n"))
                if m:
                    # vcvars emits `Path=` (not `PATH=`); keep both spellings
                    # so case-sensitive lookups and Windows agree.
                    env[m.group(1)] = m.group(2)
                    env[m.group(1).upper()] = m.group(2)
    except OSError as e:
        raise FileNotFoundError("could not read vcvars env dump: %s" % e)

    path_val = env.get("PATH") or env.get("Path") or ""
    cl = None
    for d in path_val.split(os.pathsep):
        cand = os.path.join(d.strip().strip('"'), "cl.exe")
        if os.path.isfile(cand):
            cl = cand
            break
    if cl is None:
        raise FileNotFoundError(
            "cl.exe not found after sourcing %s (PATH had %d entries)"
            % (VCVARS, len(path_val.split(os.pathsep))))
    _CL_CACHE["cl"] = cl
    _CL_CACHE["env"] = env
    return cl, env


def compile_c(code, stem):
    """Compile with MSVC; apply mechanical repair ladder on failure.

    Pass 0: cxx_fix        -> legalise C++ (`this` param rename, keep __thiscall)
    Pass 1: auto_prelude   -> declares undeclared callees/globals (C2061/C2065)
    Pass 2: stub_undeclared -> stubs exactly what the compiler named (C2065)
    Returns (ok, compiler_output).
    """
    os.makedirs(BUILD_DIR, exist_ok=True)
    src = os.path.join(BUILD_DIR, stem + ".c")
    obj = os.path.join(BUILD_DIR, stem + ".obj")
    code = prepare(code)
    with open(src, "w", encoding="utf-8", errors="replace") as f:
        f.write(code + "\n")

    cl, clenv = vc_toolchain()

    def _run():
        try:
            r = subprocess.run(
                [cl, "/nologo", "/c", "/TP", "/W0",
                 "/D_CRT_SECURE_NO_WARNINGS",
                 os.path.basename(src), "/Fo" + os.path.basename(obj)],
                cwd=BUILD_DIR, env=clenv,
                capture_output=True, text=True, timeout=90)
        except subprocess.TimeoutExpired:
            return None, "compiler timeout"
        return r, ((r.stdout or "") + (r.stderr or "")).strip()

    # Iterative repair ladder. Every pass re-prepares the file from the
    # PRISTINE model output and layers exactly one extra targeted transform on
    # top. Recomputing from pristine (rather than mutating the previous file)
    # is what stops injected declarations from accumulating into duplicates.
    last_err = ""
    pending = []           # transforms to layer on top of prepare(), in order
    for _pass in range(6):
        with open(src, "w", encoding="utf-8", errors="replace") as f:
            f.write(_apply_pending(prepare(code), pending))
        r, out = _run()
        if r is None:
            return False, out
        if r.returncode == 0:
            return True, ""
        err = out or ("exit %d" % r.returncode)
        if err == last_err:
            break                      # no progress -> stop
        last_err = err

        # ACCUMULATE: one error can need more than one transform, and a file
        # can report several classes at once. Picking one per pass (and
        # dropping the previous choice) starved cases like C1004, where the
        # missing `;` only becomes visible as an unexpected end-of-file.
        before = list(pending)
        if "C3865" in err and "thiscall" not in pending:
            pending.append("thiscall")
        if re.search(r"C2146|C2143|C2059|C1004|C1075", err) and \
                "semis" not in pending:
            pending.append("semis")
        elif re.search(r"C1075", err) and "balance" not in pending:
            pending.append("balance")
        elif re.search(r"C2371|C2372|C2365|C2373|C2369|C2040|C2556|C2733",
                       err) and "dedupe" not in pending:
            pending.append("dedupe")
        if pending == before:
            break                      # nothing new to try -> let the LLM retry
    return False, last_err


def _apply_pending(code, which):
    if isinstance(which, str):
        which = [which]
    for w in which:
        if w == "thiscall":
            code = fix_thiscall(code)
        elif w == "semis":
            code = fix_missing_semis(code)
        elif w == "balance":
            o, c = code.count("{"), code.count("}")
            if o > c:
                code = code + "\n" + "}\n" * (o - c)
        elif w == "dedupe":
            code = dedupe_decls(code)
    return code


_CRT_EXTERNS = """/* _CRT_EXTERNS_MARKER - only what vcruntime.h does NOT already provide */
extern "C" void __cdecl memset(void *, int, size_t);
extern "C" void __cdecl memcpy(void *, const void *, size_t);
extern "C" int  __cdecl memcmp(const void *, const void *, size_t);
extern "C" void __cdecl free(void *);
extern "C" void *__cdecl malloc(size_t);
extern "C" void *__cdecl realloc(void *, size_t);
extern "C" int  __cdecl _purecall(void);
extern "C" void __cdecl _invalid_parameter_noinfo(void);
"""


_BAD_TYPEDEF_RE = re.compile(
    r"(?m)^[ \t]*(?:typedef[ \t]+)?"
    r"(?:unsigned[ \t]+)?(?:char|short|int|long|float|double)\b"
    r"(?:[ \t]+(?:long|int|short|char|double))*"
    r"[ \t]+bool\b[ \t]*(?:;|,|\))")


def fix_typedefs(code):
    """Mechanically drop illegal `<width> bool` typedefs (C2628/C2632).

    Models emit `typedef uint32_t bool;` or `int bool` because Ghidra mixes
    `bool` with width-prefixed types. C++ `bool` is standalone; pairing it with
    a width is a syntax error (C2628/C2632). Delete the bogus declaration and
    let the real `bool` keyword stand.
    """
    if not code:
        return code
    out = _BAD_TYPEDEF_RE.sub(lambda m: m.group(0).split("bool")[0].rstrip() + ";"
                              if m.group(0).lstrip().startswith("typedef")
                              else "", code)
    # also: `typedef int8_t bool;` style with stdint prefixes
    out = re.sub(
        r"(?m)^[ \t]*typedef[ \t]+(?:u?int(?:8|16|32|64)_t)[ \t]+bool[ \t]*;[ \t]*$",
        "", out)
    return out


def add_crt_externs(code):
    """Prepend CRT declarations only for helpers the file actually references.

    Declaring unconditionally collides with <vcruntime.h> and with the C++
    predefined operator new/delete (error C2733 / C2092 / C2365).
    """
    if not code or "_CRT_EXTERNS_MARKER" in code:
        return code
    needed = []
    for decl, sym in (
            ("extern \"C\" void __cdecl memset(void *, int, size_t);", "memset"),
            ("extern \"C\" void __cdecl memcpy(void *, const void *, size_t);", "memcpy"),
            ("extern \"C\" int  __cdecl memcmp(const void *, const void *, size_t);", "memcmp"),
            ("extern \"C\" void __cdecl free(void *);", "free"),
            ("extern \"C\" void *__cdecl malloc(size_t);", "malloc"),
            ("extern \"C\" void *__cdecl realloc(void *, size_t);", "realloc"),
            ("extern \"C\" int  __cdecl _purecall(void);", "_purecall"),
            ("extern \"C\" void __cdecl _invalid_parameter_noinfo(void);",
             "_invalid_parameter_noinfo"),
    ):
        if re.search(r"(?<![.\w])%s\s*\(" % re.escape(sym), code):
            needed.append(decl)
    if not needed:
        return code
    return "/* _CRT_EXTERNS_MARKER */\n" + "\n".join(needed) + "\n" + code


def _match_brace(s, open_idx):
    """Index of the '}' matching the '{' at open_idx (brace counting,
    string/comment aware enough for generated code)."""
    depth = 0
    i = open_idx
    n = len(s)
    while i < n:
        c = s[i]
        if c == "/" and i + 1 < n and s[i + 1] == "/":
            j = s.find("\n", i)
            i = j if j != -1 else n
            continue
        if c == "/" and i + 1 < n and s[i + 1] == "*":
            j = s.find("*/", i + 2)
            i = (j + 2) if j != -1 else n
            continue
        if c == '"':
            i += 1
            while i < n and s[i] != '"':
                i += 2 if s[i] == "\\" else 1
            i += 1
            continue
        if c == "'":
            i += 1
            while i < n and s[i] != "'":
                i += 2 if s[i] == "\\" else 1
            i += 1
            continue
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


_THISCALL_DEF = re.compile(
    r"(?m)^(?P<indent>[ \t]*)(?P<ret>(?:extern\s+)?(?:static\s+)?(?:inline\s+)?"
    r"[A-Za-z_][\w\s:*&<>]*?)__thiscall\s+(?P<name>[A-Za-z_]\w*)\s*"
    r"\((?P<params>[^;{()]*(?:\([^)]*\)[^;{()]*)*)\)\s*\{")


_DECL_RE = re.compile(
    r"(?m)^[ \t]*(?:extern[ \t]+\"C\"[ \t]+)?"
    r"(?:static[ \t]+|inline[ \t]+|const[ \t]+|volatile[ \t]+)*"
    r"(?:unsigned[ \t]+|signed[ \t]+)?"
    r"[A-Za-z_][\w \t]*?\**\s*(&?\*?\s*)?"
    r"(?P<name>[A-Za-z_]\w*)\s*(?P<tail>\([^;]*\)\s*;|\[[^\]]*\]\s*;)")


def dedupe_decls(code):
    """Drop duplicate/conflicting file-scope declarations.

    Error class C2371/C2372/C2365/C2373/C2556: the same symbol is declared
    twice with different types (model emits `extern char DAT_x[];` and
    `extern intptr_t DAT_x();`). Keep the first, drop later duplicates so the
    file compiles; the real type is recovered later by type-inference work.
    """
    if not code:
        return code
    seen = set()
    drop_lines = set()

    def keep(m):
        name = m.group("name")
        if name in seen:
            drop_lines.add(m.group(0))
            return m.group(0)
        seen.add(name)
        return m.group(0)

    out = _DECL_RE.sub(keep, code)
    if not drop_lines:
        return code
    lines = out.split("\n")
    kept = []
    for ln in lines:
        s = ln.strip()
        if any(s == d.strip() and d.strip() for d in drop_lines):
            continue
        kept.append(ln)
    return "\n".join(kept)


def fix_thiscall(code):
    """Drop the calling-convention keyword; keep the explicit `this` pointer.

    Earlier this wrapped the function in a synthesized class to preserve the
    x86 ECX ABI, but that generated MORE errors than it fixed:
      - `->vftable` on a plain object is error C2227
      - the shim collided with the canonical prototype (C2556)
      - body rewrites broke brace balance (C1075)

    For the per-function COMPILE ORACLE the convention is irrelevant -- we are
    checking that the logic is valid C++, not linking. The real ABI is
    restored at integration time (M3), where each RBX type is emitted as a
    real class with its vtable and the convention recorded from RTTI.
    """
    if not code or not _CCONV_RE.search(code):
        return code
    return _CCONV_RE.sub("", code)


def strip_autoblocks(code):
    """Remove blocks this tool injected earlier (idempotent re-runs).

    Without this, a broken repair pass is baked into the .c file and every
    later attempt inherits the damage. Each marker form is matched
    independently so partially-removed blocks still clean up.
    """
    if not code:
        return code
    # full blocks: /* --- auto-prelude ... */ ... /* --- end auto-prelude --- */
    code = re.sub(
        r"[ \t]*/\*[ \t]*-{2,}[ \t]*(?:auto-prelude|pass-2 stubs)"
        r"[^\n]*?\*/.*?"
        r"/\*[ \t]*-{2,}[ \t]*end (?:auto-prelude|pass-2)[^\n]*?\*/\s*",
        "", code, flags=re.S)
    # canonical symbol table block
    code = re.sub(
        r"[ \t]*/\*[ \t]*-{2,}[ \t]*canonical symbol table[^\n]*?\*/.*?"
        r"/\*[ \t]*-{2,}[ \t]*end canonical symbol table[^\n]*?\*/\s*",
        "", code, flags=re.S)
    # dangling openers (block was cut mid-way)
    code = re.sub(
        r"[ \t]*/\*[ \t]*-{2,}[ \t]*(?:auto-prelude|pass-2 stubs|"
        r"canonical symbol table)[^\n]*?\*/[ \t]*\n?", "", code)
    # CRT block
    code = re.sub(r"[ \t]*/\* _CRT_EXTERNS_MARKER[^\n]*\*/\s*"
                  r"(?:extern \"C\"[^\n]*\n)*\s*", "", code)
    return code


def stub_undeclared(code, err=None):
    """Pass-2 repair driven by the compiler itself.

    MSVC wording (no 'undeclared' token):
      error C2065: 'DynLib': undeclared identifier      <- C mode
      error C3861: 'foo': identifier not found when parsing arguments
      error C4013: undefined function or variable 'foo'
    Only identifiers the compiler NAMED are stubbed -- never a blind sweep
    (a blind sweep stubs typedefs/struct tags/locals and causes C2365).
    """
    names = []
    if err:
        for pat in (
            r"error C2065:\s*'([A-Za-z_][A-Za-z_0-9]*)'\s*:\s*undeclared identifier",
            r"error C4013:\s*undefined function or variable\s*'([A-Za-z_][A-Za-z_0-9]*)'",
            r"error C3861:\s*'([A-Za-z_][A-Za-z_0-9]*)'\s*:\s*identifier not found",
            r"error C4430:\s*'([A-Za-z_][A-Za-z_0-9]*)'\s*:\s*type modifiers are not allowed",
        ):
            for m in re.finditer(pat, err):
                names.append(m.group(1))
    if not names and err:
        # last resort: parse "identifier 'X'" generically
        for m in re.finditer(
                r"identifier\s+'([A-Za-z_][A-Za-z_0-9]*)'", err):
            names.append(m.group(1))
    if not names:
        # NO blind fallback. Guessing from the source stubs typedefs, struct
        # tags and locals -> C2365 redefinition. Only the compiler knows.
        return code
    uniq = []
    skip = _C_BUILTIN | {"this", "this_"}
    for nm in names:
        if nm in skip or nm in uniq:
            continue
        # never stub something already declared as a type/typedef/struct tag
        if re.search(r"\b(?:struct|union|enum|class)\s+%s\b" % re.escape(nm),
                     code) or \
           re.search(r"\btypedef\b[^;\n]*\b%s\b" % re.escape(nm), code):
            continue
        if re.search(r"^\s*(?:\w+\s+)+\**%s\s*\(" % re.escape(nm), code, re.M):
            continue  # already prototyped
        uniq.append(nm)
    if not uniq:
        return code
    block = ["/* --- pass-2 stubs (from compiler C2065/C4013) --- */"]
    for nm in uniq:
        if re.match(r"^(DAT_|s_|PTR_)", nm):
            block.append("extern unsigned char %s[];" % nm)
        else:
            block.append("extern intptr_t %s();" % nm)
    block.append("/* --- end pass-2 --- */")
    lines = code.split("\n")
    insert_at = 0
    for i, ln in enumerate(lines):
        if ln.lstrip().startswith(("#include", "#pragma")):
            insert_at = i + 1
        elif ln.strip() and not ln.lstrip().startswith(("#include", "#pragma",
                                                        "#define", "/*", "*", "//")):
            break
    merged = "\n".join(lines[:insert_at]) + "\n" + "\n".join(block) + "\n" + \
        "\n".join(lines[insert_at:])
    return merged
    """-> (ok, compiler_output)"""
    os.makedirs(BUILD_DIR, exist_ok=True)
    src = os.path.join(BUILD_DIR, stem + ".c")
    obj = os.path.join(BUILD_DIR, stem + ".obj")
    with open(src, "w", encoding="utf-8", errors="replace") as f:
        f.write(code + "\n")
    bat = VCVARS
    cmd = ['cmd', '/c', 'call "%s" >nul 2>&1 && cl /nologo /c /TC /W0 /D_CRT_SECURE_NO_WARNINGS "%s" /Fo"%s"' % (bat, src, obj)]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=90)
    except subprocess.TimeoutExpired:
        return False, "compiler timeout"
    out = (r.stdout or "") + (r.stderr or "")
    if r.returncode == 0:
        return True, ""
    # mechanical repair pass 1: declare undeclared callees/globals, recompile
    err1 = out.strip() or ("exit %d" % r.returncode)
    if re.search(r"error C2061|error C2065|error C4013|error C2440", err1):
        try:
            with open(src, "r", encoding="utf-8", errors="replace") as f:
                cur = f.read()
            fixed = auto_prelude(cur)
            if fixed != cur:
                with open(src, "w", encoding="utf-8", errors="replace") as f:
                    f.write(fixed)
                r2 = subprocess.run(cmd, capture_output=True, text=True, timeout=90)
                out2 = (r2.stdout or "") + (r2.stderr or "")
                if r2.returncode == 0:
                    return True, ""
                # pass 2: C2065 undeclared identifier -> stub from error text
                if re.search(r"error C2065|error C4013", out2):
                    fixed2 = stub_undeclared(fixed, out2)
                    with open(src, "w", encoding="utf-8", errors="replace") as f:
                        f.write(fixed2)
                    r3 = subprocess.run(cmd, capture_output=True, text=True, timeout=90)
                    out3 = (r3.stdout or "") + (r3.stderr or "")
                    if r3.returncode == 0:
                        return True, ""
                    return False, out3.strip() or err1
                return False, out2.strip() or err1
        except Exception as e:
            return False, err1 + "\n(auto_prelude failed: %s)" % e
    return False, err1


# ---------------------------------------------------------------- run

def run(conn, limit=None, max_attempts=3, model=None):
    model = model or MODEL_CODE
    q = "SELECT program, addr, name, attempts FROM rebuild WHERE compiles = 0"
    q += " AND attempts < %d" % max_attempts
    q += " ORDER BY attempts"
    if limit:
        q += " LIMIT %d" % limit
    rows = conn.execute(q).fetchall()
    if not rows:
        print("run: nothing pending (use --retry-failed?)")
        return
    print("run: %d pending, model=%s, max_attempts=%d" %
          (len(rows), model, max_attempts))
    ok = 0
    t0 = time.time()
    for i, (program, addr, name, attempts0) in enumerate(rows, 1):
        fn = conn.execute(
            "SELECT program, addr, name, decompiled FROM functions "
            "WHERE program=? AND addr=?", (program, addr)).fetchone()
        if not fn or not fn[3]:
            conn.execute("UPDATE rebuild SET last_err=?, updated_at=? "
                         "WHERE program=? AND addr=?",
                         ("no decompiled source", time.strftime("%Y-%m-%d %H:%M:%S"),
                          program, addr))
            conn.commit()
            continue
        err = None
        attempts = attempts0
        first_try = 0
        for _ in range(max_attempts):
            attempts += 1
            try:
                out = generate(conn, fn, model, err)
            except Exception as e:
                err = "ollama: %s" % e
                continue
            code = extract_code(out)
            if not code:
                err = "no code extracted from model output"
                continue
            okc, cerr = compile_c(code, "%s_%s" % (program, addr))
            if okc:
                if attempts == 1:
                    first_try = 1
                conn.execute(
                    "UPDATE rebuild SET name=?, code=?, compiles=1, attempts=?, "
                    "first_try=?, last_err=NULL, model=?, updated_at=? "
                    "WHERE program=? AND addr=?",
                    (name, code, attempts, first_try, model, time.strftime("%Y-%m-%d %H:%M:%S"),
                     program, addr))
                conn.commit()
                ok += 1
                print("  [%d/%d] OK   %s %s (attempt %d, %.0fs)" %
                      (i, len(rows), program, addr, attempts,
                       time.time() - t0))
                break
            err = cerr
        else:
            conn.execute(
                "UPDATE rebuild SET name=?, code=?, compiles=0, attempts=?, "
                "first_try=0, last_err=?, model=?, updated_at=? "
                "WHERE program=? AND addr=?",
                (name, "", attempts, (err or "")[-4000:], model, time.strftime("%Y-%m-%d %H:%M:%S"),
                 program, addr))
            conn.commit()
            print("  [%d/%d] FAIL %s %s (attempts=%d)" %
                  (i, len(rows), program, addr, attempts))
    print("run: %d/%d compiled, %.0fs" % (ok, len(rows), time.time() - t0))


def stats(conn):
    row = conn.execute(
        "SELECT COUNT(*), SUM(compiles), SUM(first_try), AVG(attempts) FROM rebuild").fetchone()
    n, c, ft, aa = row
    print("rebuild: n=%s compiled=%s first_try=%s avg_attempts=%s" %
          (n, c or 0, ft or 0, round(aa, 2) if aa else 0))
    if n:
        print("compile rate: %.0f%%  first-try: %.0f%%" %
              (100.0 * (c or 0) / n, 100.0 * (ft or 0) / n))
    for r in conn.execute(
            "SELECT program, COUNT(*), SUM(compiles) FROM rebuild "
            "GROUP BY program"):
        print("  %s: %d/%d" % (r[0], r[2] or 0, r[1]))
    print("--- failing (up to 10)")
    for r in conn.execute(
            "SELECT program, addr, name, attempts, "
            "substr(coalesce(last_err,''),1,160) FROM rebuild "
            "WHERE compiles=0 LIMIT 10"):
        print("  %s %s %s att=%d | %s" % r)
    print("--- programs")
    for r in conn.execute("SELECT program, COUNT(*), SUM(compiles) FROM rebuild "
                          "GROUP BY program"):
        print("  %s: %d/%d" % (r[0], r[2] or 0, r[1]))


def fixup(conn):
    """Re-apply the mechanical compile ladder to already-generated code.

    Compiles the PRISTINE model output stored in the DB (not the on-disk .c,
    which earlier broken repair passes mutated) -- no LLM, no GPU.
    """
    rows = conn.execute(
        "SELECT program, addr, code FROM rebuild "
        "WHERE code IS NOT NULL AND length(code) > 0 ORDER BY program, addr"
    ).fetchall()
    if not rows:
        print("fixup: no stored code in rebuild table")
        return
    ok = 0
    for prog, addr, code in rows:
        stem = "%s_%s" % (prog, addr)
        good, err = compile_c(code, stem)
        if good:
            ok += 1
            conn.execute(
                "UPDATE rebuild SET compiles=1, last_err=NULL, updated_at=? "
                "WHERE program=? AND addr=?",
                (time.strftime("%Y-%m-%d %H:%M:%S"), prog, addr))
            print("  OK   %s %s" % (prog, addr))
        else:
            conn.execute(
                "UPDATE rebuild SET last_err=?, updated_at=? "
                "WHERE program=? AND addr=?",
                (err[-4000:], time.strftime("%Y-%m-%d %H:%M:%S"), prog, addr))
            lines = [l for l in err.strip().splitlines() if "error" in l]
            print("  FAIL %s %s | %s" % (prog, addr,
                                         lines[0][:110] if lines else "?"))
    conn.commit()
    print("fixup: %d/%d compile clean" % (ok, len(rows)))
    if ok:
        print("compile rate: %.0f%%" % (100.0 * ok / len(rows)))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("cmd", choices=["sample", "run", "stats", "fixup"])
    ap.add_argument("--db", default=DEFAULT_DB)
    ap.add_argument("--limit", type=int, default=None)
    ap.add_argument("--max-attempts", type=int, default=3)
    ap.add_argument("--model", default=None)
    a = ap.parse_args()

    conn = sqlite3.connect(a.db)
    conn.executescript(REBUILD_SCHEMA)
    if a.cmd == "sample":
        sample(conn, a.limit)
    elif a.cmd == "run":
        run(conn, a.limit, a.max_attempts, a.model)
    elif a.cmd == "stats":
        stats(conn)
    elif a.cmd == "fixup":
        fixup(conn)
    conn.close()


if __name__ == "__main__":
    main()
