"""Match the open-source libraries the clients link in, straight from their real source.

For each library file: preprocess it into one self-contained unit (headers inlined),
compile it once per compiler/flag combination, then compare every resulting function
against every client. The matched source carries `// roc-lang/cl/flags` lines, so
`roc check` and the server re-verify it with exactly the settings that matched.

Sources are downloaded from the projects' own sites and checked against pinned SHA-256.
"""
import functools
import hashlib
import json
import os
import re
import shutil
import subprocess
import tarfile
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import clients, fingerprint, match, setup


ROOT = Path(__file__).resolve().parent.parent

LIBS = ROOT / "tools" / "libs"

BUILDS = [21022, 30729, 50727]  # vendors often shipped libs built with another compiler

GRID = ["/O2 /GS- /MD", "/O2 /Oy- /GS- /MD", "/O1 /GS- /MD", "/Ox /GS- /MD", "/O2 /GS /MD", "/O2 /Ob1 /GS- /MD"]

_JPEG = ("jcapimin jcapistd jccoefct jccolor jcdctmgr jchuff jcinit jcmainct jcmarker jcmaster jcomapi "
         "jcparam jcphuff jcprepct jcsample jctrans jdapimin jdapistd jdatadst jdatasrc jdcoefct jdcolor "
         "jddctmgr jdhuff jdinput jdmainct jdmarker jdmaster jdmerge jdphuff jdpostct jdsample jdtrans "
         "jerror jfdctflt jfdctfst jfdctint jidctflt jidctfst jidctint jidctred jquant1 jquant2 jutils "
         "jmemmgr jmemnobs").split()

_LUA = ("lapi lcode ldebug ldo ldump lfunc lgc llex lmem lobject lopcodes lparser lstate lstring ltable "
        "ltm lundump lvm lzio lauxlib lbaselib ldblib liolib lmathlib loslib ltablib lstrlib loadlib "
        "linit").split()

RECIPES = {
    "zlib-1.2.3": dict(url="https://zlib.net/fossils/zlib-1.2.3.tar.gz",
                       sha256="1795c7d067a43174113fdf03447532f373e1c6c57c08d61d9e4e9be5e244b05e",
                       src="zlib-1.2.3", langs=["c"],
                       files=["adler32.c", "compress.c", "crc32.c", "deflate.c", "gzio.c", "infback.c",
                              "inffast.c", "inflate.c", "inftrees.c", "trees.c", "uncompr.c", "zutil.c"]),
    "jpeg-6b": dict(url="https://www.ijg.org/files/jpegsrc.v6b.tar.gz",
                    sha256="75c3ec241e9996504fe02a9ed4d12f16b74ade713972f3db9e65ce95cd27e35d",
                    src="jpeg-6b", langs=["c"], files=[f + ".c" for f in _JPEG],
                    prepare=[("jconfig.vc", "jconfig.h")]),
}

for _v, _sha in [("5.1", "7f5bb9061eb3b9ba1e406a5aa68001a66cb82bac95748839dc02dd10048472c1"),
                 ("5.1.1", "c5daeed0a75d8e4dd2328b7c7a69888247868154acbda69110e97d4a6e17d1f0"),
                 ("5.1.2", "5cf098c6fe68d3d2d9221904f1017ff0286e4a9cc166a1452a456df9b88b3d9e"),
                 ("5.1.3", "6b5df2edaa5e02bf1a2d85e1442b2e329493b30b0c0780f77199d24f087d296d"),
                 ("5.1.4", "b038e225eaf2a5b57c9bcc35cd13aa8c6c8288ef493d52970c9545074098af3a")]:
    # Roblox may have built Lua as C or as C++ (C++ turns lua_error into exceptions).
    RECIPES["lua-" + _v] = dict(url="https://www.lua.org/ftp/lua-%s.tar.gz" % _v, sha256=_sha,
                                src="lua-%s/src" % _v, langs=["c", "cpp"], files=[f + ".c" for f in _LUA])

# Roblox's 2008 Lua: 5.1.2 with per-thread data before lua_State (LUAI_EXTRASPACE 12:
# allocations of 0x184 not 0x178), a call on state open and a flag cleared on resume
# (`mov byte ptr [L-4], 0`). Their 2016 luaconf.h has the same hooks (RobloxExtraSpace).
_RBX_LUACONF = [
    ("#define LUAI_EXTRASPACE\t\t0",
     "#define LUAI_EXTRASPACE\t\t12\nstruct lua_State;\nvoid rbx_luai_userstateopen(struct lua_State *L);"),
    ("#define luai_userstateopen(L)\t\t((void)L)", "#define luai_userstateopen(L)\t\trbx_luai_userstateopen(L)"),
    ("#define luai_userstateresume(L,n)\t((void)L)",
     "#define luai_userstateresume(L,n)\t(((unsigned char *)(L))[-4] = 0)"),
]

RECIPES["lua-5.1.2-rbx"] = dict(RECIPES["lua-5.1.2"], patches={"luaconf.h": _RBX_LUACONF})

RECIPES["lua-5.1.3-rbx"] = dict(RECIPES["lua-5.1.3"], patches={"luaconf.h": _RBX_LUACONF})

# Roblox 2009's shipped copyrights.txt names Lua 5.0 specifically.  Its source layout
# predates 5.1 (notably ltests.c and no linit.c), so keep an exact file list.
RECIPES["lua-5.0"] = dict(url="https://www.lua.org/ftp/lua-5.0.tar.gz",
                           sha256="4a23b3bcb812538c653033cd39fe9c9bd8030286b945c56eff280d452e4e244e",
                           src="lua-5.0/src", langs=["c"], include=["lua-5.0/include"],
                           files=[f + ".c" for f in ("lapi lcode ldebug ldo ldump lfunc lgc llex lmem lobject "
                                                        "lopcodes lparser lstate lstring ltable ltests ltm lundump lvm "
                                                        "lzio lauxlib lbaselib ldblib liolib lmathlib ltablib lstrlib loadlib").split()])

for _v, _sha in [("5.0.1", "7a09d0e70dcaff7feae97cf9c154da05b1e5b92eaea2df7150b54bcaf8f3b9c6"),
                 ("5.0.2", "a6c85d85f912e1c321723084389d63dee7660b81b8292452b190ea7190dd73bc"),
                 ("5.0.3", "1193a61b0e08acaa6eee0eecf29709179ee49c71baebc59b682a25c3b5a45671")]:
    RECIPES["lua-" + _v] = dict(url="https://www.lua.org/ftp/lua-%s.tar.gz" % _v, sha256=_sha,
                                 src="lua-%s/src" % _v, langs=["c"], include=["lua-%s/include" % _v],
                                 files=RECIPES["lua-5.0"]["files"])

_PNG = ("png pngerror pngget pngmem pngpread pngread pngrio pngrtran pngrutil pngset pngtrans pngwio "
        "pngwrite pngwtran pngwutil").split()

FAST = ["/O2 /GS- /MD"]  # what every library so far was built with

# 2008-06 has a second zlib 1.2.3 (beside boost iostreams) built by VS2005 with ZLIB_WINAPI:
# exported functions are __stdcall (`ret 8` in deflate) and it emits `sub eax, 1` where
# VS2008 emits `dec eax`.
RECIPES["zlib-1.2.3-winapi"] = dict(RECIPES["zlib-1.2.3"], builds=[50727, 21022], include=["WINSDK"],
                                    defines="ZLIB_WINAPI", grid=["/O2 /GS- /MD"])

RECIPES["zlib-1.1.4"] = dict(url="https://zlib.net/fossils/zlib-1.1.4.tar.gz",
                             sha256="9e3e973174f9910fd51539ef9ce94c86a3943d4f897fab8e9adf4b19e6a8291e",
                             src="zlib-1.1.4", langs=["c"], grid=FAST, files=RECIPES["zlib-1.2.3"]["files"])

for _v, _sha in [("1.2.5", "58ec845f95ff351c8a25bfbfa667a8f3924bb0f1a1ec572cc7e09b8817204d1e"),
                 ("1.2.6", "cadc1c98bed90fadc1cca2faa4f50242a538cec060647f4801b226cb6a0f2dc8"),
                 ("1.2.7", "c99b135378870d2671556122e0d9a6991ac6bd40a46081ed312a13125a38cb66"),
                 ("1.2.8", "d3a07a78927fa23ca8bd8c13938011e0d92b6736207e3efd093a86edcde8fc02"),
                 ("1.2.10", "f832618cf5b31cd263e5e13310789e5ca96b1d6c4b558bfc51b0528e81170d65"),
                 ("1.2.12", "07379ee5f55d57d5f96cb3291f2a3bbff1050deb4d435c2274bdc5208e365a45"),
                 ("1.2.16", "258bf220cb192c2b00310db560cfa19f79598a08e3c4ce2bf65a3286c37f05ac"),
                 ("1.2.18", "80130fe5d510ce809a9ff9420ab37b7095a82987e503799799b91b9122384339"),
                 ("1.2.22", "0eabf23e4e920a435881b43fd18778e21548ed9ab0344c9e510bc43d843a0048"),
                 ("1.2.24", "7dddee18e998caa91a323bf3cd8198cae61213e595b52ef9cbf0919d5e86c0fa"),
                 ("1.2.29", "a8184570da11cc00aca59169a347d9498f909384a7cb7c9f95fa6e743c111af9"),
                 ("1.2.32", "15b052d473d4c305eca5902d577297356465694515ccab56a8cb5792789cab0b"),
                 ("1.2.35", "e8cad1595cf57312a596be9138f130413642b4ac5ca764401fa7a57647ae9206"),
                 ("1.2.37", "363bc86c202df2188c0977e47fb730a89dffbc14dda94f850ed5309585e8939d"),
                 ("1.2.40", "26dd35d9e27866db02dbf377236d2efb0f19ceb2b32b6f5de382a4a4ba5de2e6"),
                 ("1.2.44", "e9860400efce466ab05f053505e4deb3a7dc93e8a6cd5b24447e681d332c32a7")]:
    RECIPES["libpng-" + _v] = dict(url="https://github.com/pnggroup/libpng/archive/refs/tags/v%s.tar.gz" % _v,
                                   archive="libpng-%s.tar.gz" % _v, sha256=_sha, src="libpng-" + _v,
                                   langs=["c"], grid=FAST + ["/O2 /GS /MD"], include=["zlib-1.2.3"],
                                   files=[f + ".c" for f in _PNG])

# 2008-06: the exe's own zlib was built with the WinAPI (stdcall) calling convention -
# png_read_row's inflate() call at 0x51f402 takes no caller cleanup - so pngread.c must
# be preprocessed with ZLIB_WINAPI exactly like the client's own build was.
RECIPES["libpng-1.2.6-winapi"] = dict(RECIPES["libpng-1.2.6"], include=["zlib-1.2.3", "WINSDK"],
                                      defines="WIN32 ZLIB_WINAPI")

# G3D 6.09 (2007-2010 clients) bundles its own zlib, libjpeg and libpng. Old releases left
# SourceForge; this is the archive.org copy (SHA-1 matches archive.org's record).
RECIPES["g3d-6.09"] = dict(url="https://archive.org/download/g3d-src-6_09/g3d-src-6_09.zip",
                           sha256="d8036ded1a9730d80c5a2f5397efc958d6613ca41a1c7b842b212c3be7e0b6ff",
                           unpack="g3d-6.09", src="g3d-6.09/source", langs=["cpp"],
                           # /GS on (VS2005's default) is how G3D's own VC8 build was compiled.
                           grid=["/O2 /GS /EHsc /MD", "/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast", "/O2 /GS- /EHsc /MD",
                                 "/O2 /GS- /MD /arch:SSE2 /fp:fast", "/O2 /GS- /MD",
                                 # 2008 GFont uses fast floating-point reassociation on x87, without SSE2.
                                 "/O2 /GS- /EHsc /MD /fp:fast"],
                           include=["g3d-6.09/source/include", "g3d-6.09/source/boost/include", "WINSDK",
                                    "SDL-1.2.11/include"],
                           needs=["sdl-1.2.11"], files="G3Dcpp/*.cpp GLG3Dcpp/*.cpp",
                           # Roblox's project compiled these as .\glg3dcpp\X.cpp / .\G3Dcpp\X.cpp
                           # (spellings read from the 2007-08 and 2008-06 exes' assert strings).
                           file_names={"G3Dcpp\\Stopwatch.cpp": ".\\g3dcpp\\Stopwatch.cpp",
                                       "*": lambda p: ".\\" + p.replace("GLG3Dcpp\\", "glg3dcpp\\")})

# G3D 6.09 ships its own libpng 1.2.7 and IJG trees (source/png, source/IJG); 2008-06 links
# those copies, compiled like G3D itself (/fp:fast where float math is involved).
_G3D_FAST = ["/O2 /GS- /MD", "/O2 /GS- /MD /fp:fast"]

RECIPES["g3d-6.09-png"] = dict(RECIPES["g3d-6.09"], src="g3d-6.09/source/png", langs=["c"], grid=_G3D_FAST,
                               include=["g3d-6.09/source/zlib", "WINSDK"], needs=[], files="png*.c",
                               file_names=None)

RECIPES["g3d-6.09-ijg"] = dict(RECIPES["g3d-6.09"], src="g3d-6.09/source/IJG", langs=["c"], grid=_G3D_FAST,
                               include=["WINSDK"], needs=[], files="j*.c", file_names=None)

# Roblox's 2008 G3D edits, each read from the 2008-06 exe.
# GImage::Error derives from std::runtime_error: RTTI chain
# Error -> runtime_error -> exception, CatchableType size 0x60, and the out-of-line ctor
# (0x4728b0) calls runtime_error(reason) then copies reason/filename to +0x28/+0x44.
RECIPES["g3d-6.09-rbx2008"] = dict(RECIPES["g3d-6.09"], patches={"include/G3D/GImage.h": [
    ("#include <string>\n", "#include <string>\n#include <stdexcept>\n"),
    ("    class Error {\n    public:\n        Error(\n            const std::string& reason,\n"
     "            const std::string& filename = \"\") :\n        reason(reason), filename(filename) {}",
     "    class Error : public std::runtime_error {\n    public:\n        Error(\n            const std::string& reason,\n"
     "            const std::string& filename = \"\") :\n        std::runtime_error(reason), reason(reason), filename(filename) {}")],
    # Inlined getCArray in GImage::load (0x510490) builds std::exception(const char* const&) from
    # "Cannot getCArray for a huge file" (0x820c68) and throws it.
    "include/G3D/BinaryInput.h": [('throw "Cannot getCArray for a huge file";',
                                   'throw std::exception("Cannot getCArray for a huge file");')]})

RECIPES["sdl-1.2.11"] = dict(url="https://www.libsdl.org/release/SDL-1.2.11.tar.gz",  # headers for GLG3D
                             sha256="6985823287b224b57390b1c1b6cbc54cc9a7d7757fbf9934ed20754b4cd23730",
                             src="SDL-1.2.11/include", langs=[], files=[])

_BOOST_SRC = ("libs/signals/src/*.cpp libs/thread/src/*.cpp libs/thread/src/win32/*.cpp libs/filesystem/src/*.cpp "
              "libs/system/src/*.cpp libs/iostreams/src/*.cpp libs/date_time/src/gregorian/*.cpp "
              "libs/date_time/src/posix_time/*.cpp libs/regex/src/*.cpp libs/program_options/src/*.cpp")

for _v, _sha in [("1.34.1", "ef99062117068a0d641f4045c421661768657262a3d119c4a272c97a3e7ae5b3"),
                 ("1.36.0", "7f790b1636c2fdad23c0134db4c28433f90524c981ac752d8a9c8041a00b942c"),
                 ("1.35.0", "c0816cf644653a7bf8b41993261156249bd888840a12d828f3df8329277521f4"),
                 ("1.37.0", "222816baed23e460dcdec299d5621be5e83285369a02205dcab8d7ee4cbaa883"),
                 ("1.38.0", "ff8c3fc932b21453ca31d28903419617f41b2110aba341256eb31be3435843af"),
                 ("1.39.0", "6479e019463d3ac55624905ea159cad68cd36b5ff56a91c5e796a26df97b447f"),
                 ("1.40.0", "10f1ae33c9c25105554653aa7e86052e7afc9fe797c3cf188a5c8951965ae0d7"),
                 ("1.44.0", "7fbb6c9698335968a9e7f468a2b39ac25cc5b62a9c7b2cd9d6acc35c808d7451"),
                 ("1.47.0", "73d62846091af316cfe4efbc112f21d02b7c2cfe8511737be5e497bcb61ce1a3")]:
    _u = _v.replace(".", "_")
    RECIPES["boost-" + _v] = dict(url="https://archives.boost.io/release/%s/source/boost_%s.tar.gz" % (_v, _u),
                                  sha256=_sha, src="boost_" + _u, langs=["cpp"], grid=["/O2 /GS- /EHsc /MD"],
                                  include=["WINSDK", "zlib-1.2.3"], files=_BOOST_SRC)

def winsdk_include():
    """Windows SDK headers ship inside the VCForPython compiler package."""
    found = sorted(setup.TOOLS.glob("*/**/WinSDK/Include"))
    return str(found[0]) if found else ""

def files_of(r, folder):
    if isinstance(r["files"], str):
        return sorted(str(p.relative_to(folder)) for pat in r["files"].split() for p in folder.glob(pat))
    return r["files"]

def archive_members(path):
    """(member name, COFF bytes) from a Microsoft .lib archive."""
    data = path.read_bytes()
    if not data.startswith(b"!<arch>\n"):
        raise match.CompileError("not a COFF archive: %s" % path)
    names, off = b"", 8
    while off + 60 <= len(data):
        head = data[off:off + 60]
        try:
            size = int(head[48:58].decode("ascii").strip())
        except ValueError:
            raise match.CompileError("bad COFF archive: %s" % path)
        raw = head[:16].rstrip()
        body = data[off + 60:off + 60 + size]
        off += 60 + size + (size & 1)
        if raw == b"//":
            names = body
            continue
        if raw == b"/":
            continue
        if raw.startswith(b"/") and raw[1:].isdigit():
            start = int(raw[1:])
            end = names.find(b"\0", start)
            raw = names[start:end if end >= 0 else len(names)]
        elif raw.startswith(b"#1/"):
            length = int(raw[3:])
            raw, body = body[:length], body[length:]
        yield raw.decode("latin-1").rstrip("/"), body

def archive_unit(name, path, build):
    """Exact COFF member named by a saved CRT match."""
    r = RECIPES.get(name)
    if not r or not r.get("archive"):
        raise match.CompileError("unknown archive %r" % name)
    library, _, member = path.partition("/")
    cl = setup.compilers().get(build)
    if not cl or library not in r["files"]:
        raise match.CompileError("no archive %r for compiler %s" % library, build)
    lib = _archive_dir(r, cl) / library
    for found, obj in archive_members(lib):
        if found.replace("\\", "/") == member.replace("\\", "/"):  # source_for writes "/"
            return obj
    raise match.CompileError("no member %r in %s" % (member, lib))

def _archive_dir(r, cl):
    """Static libs ship beside the compiler unless the recipe names its own folder."""
    return LIBS / r["lib_dir"] if r.get("lib_dir") else Path(cl).parents[1] / "lib"

def archive_files(r, build):
    folder = _archive_dir(r, setup.compilers()[build])
    return [(lib, member, obj) for lib in r["files"] for member, obj in archive_members(folder / lib)]

def template_units():
    """Generated .cpp files: explicit instantiations of std/boost templates Roblox code uses.
    Explicit instantiation emits every member, so each unit fingerprints a whole family."""
    elems = {
        "ptr": "struct T; typedef T* E;", "int": "typedef int E;", "float": "typedef float E;",
        "double": "typedef double E;", "string": "#include <string>\ntypedef std::string E;",
        "sp": "#include <boost/shared_ptr.hpp>\nstruct T; typedef boost::shared_ptr<T> E;",
        "wp": "#include <boost/weak_ptr.hpp>\nstruct T; typedef boost::weak_ptr<T> E;",
        "spc": "#include <boost/shared_ptr.hpp>\nstruct T; typedef boost::shared_ptr<const T> E;",
        "pod12": "struct E { float v[3]; };", "pod16": "struct E { float v[4]; };",
        "pod48": "struct E { float v[12]; };",
    }
    containers = {
        "vector": "#include <vector>\ntemplate class std::vector<E>;",
        "list": "#include <list>\ntemplate class std::list<E>;",
        "deque": "#include <deque>\ntemplate class std::deque<E>;",
        "map_int": "#include <map>\ntemplate class std::map<int, E>;",
        "map_str": "#include <map>\n#include <string>\ntemplate class std::map<std::string, E>;",
        "map_ptr": "#include <map>\nstruct K; template class std::map<K*, E>;",
        "set": "#include <set>\ntemplate class std::set<E>;",
    }
    out = {}
    for cn, ct in containers.items():
        for en, et in elems.items():
            if cn == "set" and en.startswith("pod"):
                continue
            out["%s_%s.cpp" % (cn, en)] = "%s\n%s\n" % (et, ct)
    sigs = {"v": "void ()", "i": "void (int)", "p": "void (T*)", "sp": "void (boost::shared_ptr<T>)",
            "b": "void (bool)", "f": "void (float)", "pp": "void (T*, T*)", "s": "void (const std::string&)"}
    for sn, sig in sigs.items():
        head = "#include <string>\n#include <boost/shared_ptr.hpp>\nstruct T;\n"
        out["function_%s.cpp" % sn] = head + "#include <boost/function.hpp>\ntemplate class boost::function<%s>;\n" % sig
        out["signal_%s.cpp" % sn] = head + "#include <boost/signal.hpp>\ntemplate class boost::signal<%s>;\n" % sig
    return out

for _b in ("1_34_1", "1_40_0", "1_44_0", "1_47_0"):
    RECIPES["templates-boost-" + _b] = dict(generate=template_units, src="templates-boost-" + _b,
                                           langs=["cpp"], grid=["/O2 /GS- /EHsc /MD"],
                                           include=["boost_" + _b, "WINSDK"], files="*.cpp",
                                           needs=["boost-" + _b.replace("_", ".")])

# Client-specific template instantiations extracted from RTTI decorated names.
# Generated by tools/template_extractor/mangled_parser.py from the 2007-08 binary.
# These instantiate boost/std/RBX templates with the exact type arguments observed
# in the client's RTTI, using forward declarations for client types.
RECIPES["templates-2007-08"] = dict(src="templates/template_instantiations_2007-08",
                                    langs=["cpp"], grid=["/O2 /GS- /EHsc /MD"],
                                    include=["boost_1_34_1", "WINSDK"], files="*.cpp",
                                    needs=["boost-1.34.1"])

# Same for 2008-06 (shares boost 1.34.1) and 2010-06 (boost 1.37).
RECIPES["templates-2008-06"] = dict(src="templates/template_instantiations_2008-06",
                                    langs=["cpp"], grid=["/O2 /GS- /EHsc /MD"],
                                    include=["boost_1_34_1", "WINSDK"], files="*.cpp",
                                    needs=["boost-1.34.1"])

def client_template_units():
    """Binary-observed 2008-06 vendor template units (RTTI-derived Boost/std instantiations),
    kept as data in research/template-units.json."""
    return json.loads((ROOT / "research" / "template-units.json").read_text(encoding="utf-8"))


RECIPES["templates-2008-06"]["generate"] = client_template_units

STDINT = """/* stdint.h for VS2005/VS2008, which lack it. */
#pragma once
typedef signed char int8_t; typedef short int16_t; typedef int int32_t; typedef __int64 int64_t;
typedef unsigned char uint8_t; typedef unsigned short uint16_t; typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t; typedef int intptr_t; typedef unsigned int uintptr_t;
#define INT8_MIN (-127i8 - 1)
#define INT16_MIN (-32767i16 - 1)
#define INT32_MIN (-2147483647i32 - 1)
#define INT64_MIN (-9223372036854775807i64 - 1)
#define INT8_MAX 127i8
#define INT16_MAX 32767i16
#define INT32_MAX 2147483647i32
#define INT64_MAX 9223372036854775807i64
#define UINT8_MAX 0xffui8
#define UINT16_MAX 0xffffui16
#define UINT32_MAX 0xffffffffui32
#define UINT64_MAX 0xffffffffffffffffui64
"""

# Roblox's 2016 logging/fast-flag header, absent from the tree. The 2007-2012 clients
# predate it, so log calls compile to nothing and flags are plain globals.
FASTLOG = """#pragma once
#define LOGGROUP(n)
#define DYNAMIC_LOGGROUP(n)
#define FASTLOG(...) ((void)0)
#define FASTLOG1(...) ((void)0)
#define FASTLOG2(...) ((void)0)
#define FASTLOG3(...) ((void)0)
#define FASTLOG4(...) ((void)0)
#define FASTLOG5(...) ((void)0)
#define FASTLOGS(...) ((void)0)
#define FASTLOG1F(...) ((void)0)
#define DYNAMIC_FASTINT(n) namespace DFInt { extern int n; }
#define DYNAMIC_FASTINTVARIABLE(n, v) namespace DFInt { int n = v; }
#define DYNAMIC_FASTFLAG(n) namespace DFFlag { extern bool n; }
#define DYNAMIC_FASTFLAGVARIABLE(n, v) namespace DFFlag { bool n = v; }
#define FASTINT(n) namespace FInt { extern int n; }
#define FASTFLAG(n) namespace FFlag { extern bool n; }
#define FASTFLAGVARIABLE(n, v) namespace FFlag { bool n = v; }
"""

RECIPES["compat"] = dict(generate=lambda: {"stdint.h": STDINT, "FastLog.h": FASTLOG}, src="compat", langs=[], files=[])

# RBLXDecomp/RBXGSdecomp: a matching decompilation of Roblox's OWN code (RBXGS 0.3.634.0,
# Nov 2007, VS2005 SP1 50727 - our 2007-08 client's compiler). This is real RBX:: source
# (v8kernel, v8world, humanoid, reflection, script), the biggest open bucket, that no
# library ships. Cloned with submodules into tools/rbxgs (git submodule update --init).
# Its ReleaseAssert config built with these defines; code unchanged since 2007 compiles
# to the same bytes under each client's compiler, so match_obj tries every client.
_RBXGS = "../rbxgs/Client/"

_RBXGS_INC = [_RBXGS + d for d in ("App/include", "RbxGraphics/include", "Network/include",
              "RbxView/include", "Rendering/png", "Rendering/g3d/include",
              "Rendering/g3d/zlib", "Rendering/RenderLib/include", "Rendering/AppDraw/include",
              "boost_1_34_1/src", "App/lua-5.1.1/src", "Rendering/SDL-1.2.6/include")] + ["WINSDK"]

_RBXGS_DEF = "WIN32 NDEBUG _LIB _RELEASE _RELEASEASSERT _VC80_UPGRADE=0x0710"

_RBXGS_GRID = ["/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", "/O2 /Oy /Gy /GS- /EHsc /MD",
               "/O2 /GS- /EHsc /MD", "/O1 /Ob2 /Oy /GS- /EHsc /MD",
               # x87 code keeps extended precision (Streaming.cpp isBrickLocation 82 -> 98 with /fp:fast)
               "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast"]

RECIPES["rbxgs"] = dict(src=_RBXGS + "App", langs=["cpp"], files="**/*.cpp",
                        grid=_RBXGS_GRID, include=_RBXGS_INC, defines=_RBXGS_DEF)

# The Network project: Roblox's networking (RBX::Network::Replicator, Player, Server).
_RBXGS_NET_INC = [_RBXGS + d for d in ("Network/include", "Network/include/network", "App/include",
                  "Network/RakNet30/source", "Rendering/g3d/include", "Rendering/g3d/zlib",
                  "Rendering/png", "boost_1_34_1/src", "App/lua-5.1.1/src", "Rendering/AppDraw/include",
                  "Rendering/SDL-1.2.6/include", "Rendering/RenderLib/include", "RbxGraphics/include")] + ["WINSDK"]

RECIPES["rbxgs-net"] = dict(src=_RBXGS + "Network", langs=["cpp"], files="*.cpp",
                            grid=_RBXGS_GRID, include=_RBXGS_NET_INC, defines=_RBXGS_DEF)

# Target-specific reflection descriptor probe; source is evidence-derived string variant.
RECIPES["rbxgs-net-setbody"] = dict(src="rbxgs-net-custom", langs=["cpp"], files="Players.cpp",
                                    grid=_RBXGS_GRID, include=_RBXGS_NET_INC + [_RBXGS + "Network"], defines=_RBXGS_DEF)

RECIPES["rbxgs-net-setbody-lower"] = dict(src="rbxgs-net-custom-lower", langs=["cpp"], files="Players.cpp",
                                          grid=_RBXGS_GRID, include=_RBXGS_NET_INC + [_RBXGS + "Network"], defines=_RBXGS_DEF)

# RakNet 3.0 core source (RBXGSdecomp's raknet30 submodule) - the RakNet the 2007 clients
# actually linked, older than the 2016 fork (rbx2016-raknet).
_RBXGS_RAK_INC = [_RBXGS + d for d in ("Network/RakNet30/Source", "Network/include", "App/include",
                  "boost_1_34_1/src")] + ["compat", "WINSDK"]

RECIPES["rbxgs-raknet"] = dict(src=_RBXGS + "Network/RakNet30/Source", langs=["cpp"], files="*.cpp",
                               grid=_RBXGS_GRID, include=_RBXGS_RAK_INC, defines=_RBXGS_DEF)

# Public RakNet 4.081.  The checked-in source is byte-identical to Facebook's archived
# upstream RakPeer.cpp; later Roblox clients retain a small amount of this core code.
RECIPES["raknet-4.081"] = dict(src="RakNet-master/Source", langs=["cpp"], files="*.cpp",
                                grid=["/O2 /GS- /EHsc /MD", "/O2 /GS- /MD", "/O1 /GS- /EHsc /MD"],
                                include=["RakNet-master/Source", "WINSDK"], defines="WIN32 _WIN32 _LIB")

# RbxView (Part, meshes = the Ogre::Rbx* render classes) and RenderLib (Clusterer,
# RenderScene). Broad include covers every sibling project they pull headers from.
_RBXGS_VIEW_INC = [_RBXGS + d for d in ("RbxView/include", "RbxViewBase", "App/include",
                   "RbxGraphics/include", "Network/include", "Rendering/RenderLib/include",
                   "Rendering/AppDraw/include", "Rendering/g3d/include", "Rendering/g3d/zlib",
                   "Rendering/png", "boost_1_34_1/src", "App/lua-5.1.1/src",
                   "Rendering/SDL-1.2.6/include")] + ["WINSDK"]

RECIPES["rbxgs-view"] = dict(src=_RBXGS + "RbxView", langs=["cpp"], files="*.cpp",
                             grid=_RBXGS_GRID, include=_RBXGS_VIEW_INC, defines=_RBXGS_DEF)

RECIPES["rbxgs-render"] = dict(src=_RBXGS + "Rendering/RenderLib", langs=["cpp"], files="*.cpp",
                               grid=_RBXGS_GRID, include=_RBXGS_VIEW_INC, defines=_RBXGS_DEF)

# AppDraw (drawing utilities, adornments, fonts): source path AppDraw\ appears in 2012-06
# debug strings but has no recipe. Include set is the same as the main rbxgs project.
RECIPES["rbxgs-appdraw"] = dict(src=_RBXGS + "Rendering/AppDraw", langs=["cpp"], files="*.cpp",
                                grid=_RBXGS_GRID, include=_RBXGS_INC, defines=_RBXGS_DEF)

# RBXGSdecomp's own g3d fork: the exact G3D the RBXGS build linked (patched by Roblox),
# which may byte-match where generic g3d-6.09 does not. G3D is float-heavy -> SSE2 grid.
_RBXGS_G3D = _RBXGS + "Rendering/g3d/"

_RBXGS_G3D_INC = [_RBXGS_G3D + d for d in ("include", "zlib", "png", "IJG", "boost")] + \
                 [_RBXGS + "Rendering/SDL-1.2.6/include", "WINSDK"]

_RBXGS_G3D_GRID = ["/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast",
                   "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD", "/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast",
                   "/O2 /GS- /EHsc /MD"]

RECIPES["rbxgs-g3d"] = dict(src=_RBXGS_G3D.rstrip("/"), langs=["cpp"], files="G3Dcpp/*.cpp GLG3Dcpp/*.cpp",
                            grid=_RBXGS_G3D_GRID, include=_RBXGS_G3D_INC, defines=_RBXGS_DEF)

# Asphaltian/OpenRBX: instruction-accurate December 2007 client decompilation.
# Keep this separate from RBXGSdecomp: it follows PDB-recorded Client paths and
# contains newer, still-being-recovered translation units.
_OPENRBX = "../openrbx/"

_OPENRBX_INC = [_OPENRBX + d for d in (
    "Client/App/include", "Client/Network/include", "Client/RbxView/include",
    "Client/RbxViewBase", "Client/Rendering/RenderLib/include",
    "Client/Rendering/AppDraw/include", "Client/RbxGraphics/include",
    "3rdparty/RakNet30/Source", "util", "3rdparty/boost_1_34_1",
    "3rdparty/g3d/source/include", "3rdparty/lua-5.1.1/src",
    "3rdparty/g3d/source/png", "3rdparty/g3d/source/zlib",
    "3rdparty/SDL-1.2.6/include")] + ["WINSDK"]

RECIPES["openrbx-client"] = dict(src=_OPENRBX + "Client", langs=["cpp"], files="**/*.cpp",
                                  grid=_RBXGS_GRID, include=_OPENRBX_INC,
                                  defines="WIN32 NDEBUG _LIB _VC80_UPGRADE=0x0710 _MBCS")

# verify-stack/rccservice-decompile (May 2008 RCCService), cloned by hand into
# tools/libs/rccservice. Two std template matches (2008-06, 2009-06) came from its gSOAP.
RECIPES["rccservice"] = dict(src="rccservice/RBXGS", langs=["cpp"], files="gSOAP/generated/stdsoap2.cpp",
                             grid=["/O2 /Oy- /GS- /MD"], include=["rccservice/RBXGS/gSOAP", "WINSDK"])

# Same tree with _DLL. preprocess() runs /EP without the grid's /MD, so without it CRT
# calls lose __declspec(dllimport) and `call free` never matches `call [__imp__free]`.
# A separate name because existing openrbx-client matches verify only without _DLL.
RECIPES["openrbx-client-dll"] = dict(RECIPES["openrbx-client"],
                                     defines=RECIPES["openrbx-client"]["defines"] + " _DLL")

# OpenRBX's RakNet 3.0 is recovered from WebService.dll (270 markers), not stock RakNet.
# Network library: plain /O2 (so /GS on) and only RakNet files add _CRT_SECURE_NO_WARNINGS.
RECIPES["openrbx-raknet"] = dict(src=_OPENRBX + "3rdparty/RakNet30/Source", langs=["cpp"], files="*.cpp",
                                  grid=["/O2 /EHsc /MD", "/O2 /GS- /EHsc /MD"], include=_OPENRBX_INC,
                                  defines="WIN32 NDEBUG _LIB _VC80_UPGRADE=0x0710 _MBCS _CRT_SECURE_NO_WARNINGS _DLL")

# Exact CRT/STL objects from each installed compiler. Fingerprint archive members directly.
RECIPES["msvc-crt"] = dict(archive=True, builds=[50727, 21022, 30729],
                            files=["libcmt.lib", "libcpmt.lib"])

# 2008-06 links shared MFC/CRT (/MD) plus the static parts of ATL and MFC: atls.lib and
# mfcs90.lib from the VS2008 RTM Professional DVD (cab46/cab47 of archive.org's
# en_visual_studio_2008_professional_x86_dvd_x14-26326 ISO, members FL_atls_lib_16138 and
# FL_mfcs90_lib_x86_Shared), copied to tools/libs/mfc-9.0-rtm/atlmfc/lib/. Express lacks them.
# Their prebuilt code has hotpatch `mov edi, edi` prologues and no alignment padding.
RECIPES["msvc-atlmfc-rtm"] = dict(archive=True, builds=[21022], lib_dir="mfc-9.0-rtm/atlmfc/lib",
                                  files=["atls.lib", "mfcs90.lib"])

# _com_raise_error etc. (comdef.h support) from the compiler's own comsupp.lib.
RECIPES["msvc-comsupp-rtm"] = dict(archive=True, builds=[21022], files=["comsupp.lib"])

# OGRE 1.7.0 (Cthugha), public source archive. Useful for stock Ogre symbols in the
# older clients; Roblox-specific Rbx/Gfx subclasses remain outside this tree.
RECIPES["ogre-1.7.0"] = dict(
    url="https://downloads.sourceforge.net/project/ogre/ogre/1.7/ogre-v1-7-0.zip",
    archive="ogre-v1-7-0.zip", sha256="4abb420aa30047c32ec99ad3cace59d9014e808ef2adfc36e84b819a8e0641f4",
    unpack="ogre-1.7.0", src="ogre-1.7.0/ogre/OgreMain/src", langs=["cpp"],
    builds=[50727, 21022, 30729],
    include=["ogre-1.7.0/ogre/OgreMain/include", "WINSDK"],
    grid=["/O2 /GS- /EHsc /MD", "/O2 /GS /EHsc /MD"], files="*.cpp",
    write={"../include/OgreBuildSettings.h": """#ifndef __Custom_Config_H_\n#define __Custom_Config_H_\n#define OGRE_CONFIG_LITTLE_ENDIAN\n#define OGRE_DOUBLE_PRECISION 0\n#define OGRE_MEMORY_ALLOCATOR 4\n#define OGRE_CONTAINERS_USE_CUSTOM_MEMORY_ALLOCATOR 0\n#define OGRE_STRING_USE_CUSTOM_MEMORY_ALLOCATOR 0\n#define OGRE_MEMORY_TRACKER_DEBUG_MODE 0\n#define OGRE_MEMORY_TRACKER_RELEASE_MODE 0\n#define OGRE_THREAD_SUPPORT 0\n#define OGRE_THREAD_PROVIDER 0\n#define OGRE_NO_FREEIMAGE 0\n#define OGRE_NO_DDS_CODEC 0\n#define OGRE_NO_PVRTC_CODEC 0\n#define OGRE_NO_ZIP_ARCHIVE 0\n#define OGRE_NO_VIEWPORT_ORIENTATIONMODE 0\n#define OGRE_USE_NEW_COMPILERS 0\n#define OGRE_USE_BOOST 0\n#define OGRE_PROFILING 0\n#endif\n"""})

# The 2010 Plugin_CgProgramManager PDB path names ogre-v1-6-4 exactly.  This is
# the matching VC9-era stock Ogre release, useful for inline/template code in clients.
RECIPES["ogre-1.6.4"] = dict(
    url="https://downloads.sourceforge.net/project/ogre/ogre/1.6.4/ogre-v1-6-4.tar.bz2",
    archive="ogre-v1-6-4.tar.bz2", sha256="af348dc278ff53f5eec966073d1eb8a87ad5c29215339713ce91eda1501bf12e",
    src="ogre/OgreMain/src", langs=["cpp"], builds=[50727, 21022, 30729],
    include=["ogre/OgreMain/include", "WINSDK"],
    defines="WIN32 NDEBUG _USRDLL _MT OGRE_NONCLIENT_BUILD",
    grid=["/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT",
          "/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD"], files="*.cpp")

# 2009's rgpar.dll and Plugin_CgProgramManager.dll PDB paths name ogre-v1-4-9.
RECIPES["ogre-1.4.9"] = dict(
    url="https://downloads.sourceforge.net/project/ogre/ogre/1.4.9/ogre-v1-4-9.tar.bz2",
    archive="ogre-v1-4-9.tar.bz2", sha256="38b17826b6b34e70bf1bab17d4791ab1d485409c938cf71e1e5f866f3391c35b",
    unpack="ogre-1.4.9", src="ogre-1.4.9/ogre/OgreMain/src", langs=["cpp"], builds=[50727, 21022, 30729],
    include=["ogre-1.4.9/ogre/OgreMain/include", "WINSDK"],
    defines="WIN32 NDEBUG _USRDLL _MT OGRE_NONCLIENT_BUILD",
    grid=["/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT",
          "/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD"], files="*.cpp")

# 2008-06 ships OgreMain as rgmain.dll (PDB c:\ogrenew\lib\rgmain.pdb; "ogrenew" is the
# release zip's top folder). Its SceneManager has 228 virtuals: 1.4.5, not 1.4.6-1.4.9 (241).
RECIPES["ogre-1.4.5"] = dict(
    url="https://downloads.sourceforge.net/project/ogre/ogre/1.4.5/ogre-win32-v1-4-5.zip",
    archive="ogre-win32-v1-4-5.zip", sha256="b304bde612d3b5b4fc470cda15788892382e1f8255280b978ba4bbcba6b24d28",
    unpack="ogre-1.4.5", src="ogre-1.4.5/ogrenew/OgreMain/src", langs=["cpp"], builds=[21022],
    include=["ogre-1.4.5/ogrenew/OgreMain/include", "WINSDK"],
    defines="WIN32 NDEBUG _USRDLL _MT OGRE_NONCLIENT_BUILD",
    # No /O2: rgmain.dll was built with /Ob2 /Oi /Ot /Oy /GF but without /Og (/O2 matches nothing).
    grid=["/Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD", "/Ob2 /Oi /Ot /Oy /GF /EHsc /MD"], files="*.cpp")

# Roblox's own 2016 source tree (roc/refsource.py) keeps the forks the clients were built
# from: G3D 8.00 (gone from the web), their modified Lua 5.1.4, RakNet, libjpeg and libpng.
# Code unchanged since 2012 compiles to the same bytes with the client's compiler.
# These recipes have no URL: the tree has to be extracted locally.
REF = "../roblox2016/src/ROBLOX2016-main/"

_REF_INC = [REF + "Rendering/g3d/include", REF + "Rendering/g3d/include/png", REF + "Rendering/g3d/ijg",
            "compat", "boost_1_40_0", "zlib-1.2.3", "WINSDK"]

_REF_NEEDS = ["compat", "boost-1.40.0", "zlib-1.2.3"]

# Roblox built the float-heavy G3D math with SSE2: /arch:SSE2 /fp:fast is what matches it.
_REF_GRID = ["/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast", "/O2 /GS- /EHsc /MD /arch:SSE2",
             "/O2 /GS- /EHsc /MD", "/O2 /GS- /MD /arch:SSE2 /fp:fast"]

RECIPES["rbx2016-g3d"] = dict(src=REF + "Rendering/g3d/g3dcpp", langs=["cpp"], files="*.cpp",
                              grid=_REF_GRID, include=_REF_INC, needs=_REF_NEEDS)

RECIPES["rbx2016-lua"] = dict(src=REF + "App/Lua-5.1.4/src", langs=["c", "cpp"], files=[f + ".c" for f in _LUA],
                              grid=FAST + ["/O2 /GS- /EHsc /MD"], include=_REF_INC, needs=_REF_NEEDS)

RECIPES["rbx2016-jpeg"] = dict(src=REF + "Rendering/g3d/ijg", langs=["c"], files="j*.c", grid=FAST,
                               include=_REF_INC, needs=_REF_NEEDS)

RECIPES["rbx2016-png"] = dict(src=REF + "Rendering/g3d/png", langs=["c"], files="png*.c", grid=FAST,
                              include=_REF_INC, needs=_REF_NEEDS)

# Roblox's RakNet fork (RakNet::RakPeer and friends in the 2009-2012 RTTI).
RECIPES["rbx2016-raknet"] = dict(src=REF + "Network/raknet/Source", langs=["cpp"], files="*.cpp",
                                 grid=["/O2 /GS- /EHsc /MD", "/O2 /GS- /MD", "/O2 /GS- /EHsc /MD /arch:SSE2"],
                                 include=_REF_INC, needs=_REF_NEEDS)

# MFC static library source. Each client statically links the MFC build that shipped with
# its compiler, so the source compiled with the same cl.exe fingerprint-matches ~1600/client.
# MFC 8.0 (_MFC_VER 0x0800) is VS2005 -> the 2007-08 client only. No URL: extracted locally
# from github.com/pixelspark/corespark (Libraries/atlmfc) into tools/libs/mfc-8.0/.
_MFC80_INC = ["mfc-8.0/atlmfc/src/mfc", "mfc-8.0/atlmfc/include", "WINSDK"]

_MFC_GRID = ["/O2 /GS- /MD", "/O2 /GS- /MT", "/O1 /GS- /MD", "/O2 /GF /Gy /GS- /MD"]

RECIPES["mfc-8.0"] = dict(src="mfc-8.0", langs=["cpp"], builds=[50727], include=_MFC80_INC,
                          grid=_MFC_GRID, files="atlmfc/src/mfc/*.cpp")

# MFC 9.0 (0x0900) = VS2008. Commit 9.00.30729 (SP1) matches the 30729 clients exactly; the
# RTM 21022 clients (2008-06, 2011-06) differ by SP but share most functions, so try both.
_MFC90_INC = ["mfc-9.0/atlmfc/src/mfc", "mfc-9.0/atlmfc/include", "WINSDK"]

RECIPES["mfc-9.0"] = dict(src="mfc-9.0", langs=["cpp"], builds=[30729, 21022], include=_MFC90_INC,
                          grid=_MFC_GRID, files="atlmfc/src/mfc/*.cpp")

RECIPES["mfc-9.0-shared"] = dict(src="mfc-9.0", langs=["cpp"], builds=[30729, 21022],
                                 include=_MFC90_INC,
                                 defines="_AFXDLL _DLL", grid=["/O2 /GS- /MD", "/O1 /GS- /MD"],
                                 files="atlmfc/src/mfc/*.cpp")

# ATL implementation units are separate from MFC.  The clients contain named ATL::CRegObject
# code, so compile the shipped ATL sources with the same toolchain headers.
RECIPES["atl-8.0"] = dict(src="mfc-8.0/atlmfc/src/atl", langs=["cpp"], builds=[50727],
                           include=["mfc-8.0/atlmfc/src/atl", "mfc-8.0/atlmfc/include", "WINSDK"],
                           grid=_MFC_GRID, files="*.cpp")

RECIPES["atl-9.0"] = dict(src="mfc-9.0/atlmfc/src/atl", langs=["cpp"], builds=[30729, 21022],
                           include=["mfc-9.0/atlmfc/src/atl", "mfc-9.0/atlmfc/include", "WINSDK"],
                           grid=_MFC_GRID, files="*.cpp")

# Codejock Xtreme Toolkit Pro, statically linked by the clients (the CXTP* units). XTP is built
# on MFC, so it needs the matching MFC headers. v15.2.1 is (c)1998-2011 -> the 2011-06/2012-06
# clients. No URL: extracted locally from github.com/mavaL/NeoEngine (Dependency/XTP) into
# tools/libs/xtp-15.2.1/, with a one-line Source/StdAfx.h (#include "XTToolkitPro.h") added, since
# every XTP .cpp opens with #include "StdAfx.h" and the umbrella header lives at Source root.
_XTP_INC = ["xtp-15.2.1/Source", "mfc-9.0/atlmfc/include", "WINSDK"]

_XTP_STDAFX = {"Source/StdAfx.h": '#include "XTToolkitPro.h"\n'}

RECIPES["xtp-15.2.1"] = dict(src="xtp-15.2.1", langs=["cpp"], builds=[30729, 21022], include=_XTP_INC,
                             grid=_MFC_GRID, files="Source/**/*.cpp", write=_XTP_STDAFX)

RECIPES["xtp-15.2.1-shared-mfc"] = dict(
    src="xtp-15.2.1", langs=["cpp"], builds=[30729, 21022], include=_XTP_INC,
    defines="_AFXDLL _XTP_STATICLINK _DLL", grid=["/O2 /GS- /MD", "/O1 /GS- /MD"],
    files="Source/**/*.cpp", write=_XTP_STDAFX)

# Older XTP for the older clients (archive.org): v13.2.1 (2010) -> 2010-06, v11.2.2 (2008) ->
# 2008-06. Both build on MFC 9.0. v11 also builds on MFC 8.0 (VS2005) for the 2007-08 client,
# whose own XTP release (v9.60) shipped headers only, no source.
def _xtp_inc(ver, mfc):
    return ["%s/Source" % ver, "%s/atlmfc/include" % mfc, "WINSDK"]

RECIPES["xtp-13.2.1"] = dict(src="xtp-13.2.1", langs=["cpp"], builds=[30729, 21022],
                             include=_xtp_inc("xtp-13.2.1", "mfc-9.0"), grid=_MFC_GRID,
                             files="Source/**/*.cpp", write=_XTP_STDAFX)

RECIPES["xtp-13.2.1-shared-mfc"] = dict(
    src="xtp-13.2.1", langs=["cpp"], builds=[30729, 21022],
    include=_xtp_inc("xtp-13.2.1", "mfc-9.0"),
    defines="_AFXDLL _XTP_STATICLINK _DLL", grid=["/O2 /GS- /MD", "/O1 /GS- /MD"],
    files="Source/**/*.cpp", write=_XTP_STDAFX)

RECIPES["xtp-11.2.2"] = dict(src="xtp-11.2.2", langs=["cpp"], builds=[30729, 21022],
                             include=_xtp_inc("xtp-11.2.2", "mfc-9.0"), grid=_MFC_GRID,
                             files="Source/**/*.cpp", write=_XTP_STDAFX)

# Shared release MFC retains CObject::AssertValid/Dump virtual slots. Keep the
# configuration in a separate recipe so preprocessing and source replay agree.
RECIPES["xtp-11.2.2-shared-mfc"] = dict(
    src="xtp-11.2.2", langs=["cpp"], builds=[30729, 21022],
    include=_xtp_inc("xtp-11.2.2", "mfc-9.0"),
    defines="_AFXDLL _XTP_STATICLINK _DLL", grid=["/O2 /GS- /MD", "/O1 /GS- /MD"],
    files="Source/**/*.cpp", write=_XTP_STDAFX)

# Header members (definition text) the 2008 client calls out of line instead of inlining.
MFC_STRING_CALLS = ("bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );",
                    "operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );")

# The 2008 client calls these imported CString helpers instead of inlining them.
# Keep the header adjustment in its own recipe for reproducible source replay.
RECIPES["xtp-11.2.2-shared-mfc-string-calls"] = dict(
    RECIPES["xtp-11.2.2-shared-mfc"], noinline_mfc_strings=True,
    grid=["/O2 /MD /GS /EHsc /Ob1", "/O2 /MD /GS- /Ob1"])

# Some XTP implementation files need MFC's shipped private declarations.
RECIPES["xtp-11.2.2-shared-mfc-internals"] = dict(
    RECIPES["xtp-11.2.2-shared-mfc"],
    include=_xtp_inc("xtp-11.2.2", "mfc-9.0") + ["mfc-9.0/atlmfc/src/mfc"],
    preinclude=["XTToolkitPro.h", "afximpl.h"],
    grid=["/O2 /MD /GS /EHsc /Ob1", "/O2 /MD /GS- /Ob1"])

RECIPES["xtp-11.2.2-shared-mfc-internals-string-calls"] = dict(
    RECIPES["xtp-11.2.2-shared-mfc-internals"], noinline_mfc_strings=True)

# Codejock's own library build precompiles Common/XTPDLLExports.h: NT4/IE5 targets
# (WM_MOUSELAST 0x20a, not the SDK's Vista default 0x20e), VC_EXTRALEAN, afxpriv etc.
RECIPES["xtp-11.2.2-lib"] = dict(
    RECIPES["xtp-11.2.2-shared-mfc-string-calls"],
    defines="_AFXDLL _XTP_STATICLINK _DLL _LIB",
    preinclude=["Common/XTPDLLExports.h", "XTToolkitPro.h"])

# Most 2008 XTP files also call CSimpleStringT::GetLength out of line.
RECIPES["xtp-11.2.2-lib-strlen"] = dict(
    RECIPES["xtp-11.2.2-lib"],
    noinline=MFC_STRING_CALLS + ("int GetLength() const throw()\n\t{\n\t\treturn( GetData()->nDataLength );",))

# The client calls dllimport functions through the import table instead of expanding
# their header bodies: MFC's afxv_w32.h inline FreeResource still calls KERNEL32's.
RECIPES["xtp-11.2.2-lib-imports"] = dict(
    RECIPES["xtp-11.2.2-lib-strlen"],
    noinline=RECIPES["xtp-11.2.2-lib-strlen"]["noinline"] + ("inline BOOL __stdcall FreeResource(HGLOBAL)",))

RECIPES["xtp-11.2.2-vc8"] = dict(src="xtp-11.2.2", langs=["cpp"], builds=[50727],
                                 include=_xtp_inc("xtp-11.2.2", "mfc-8.0"), grid=_MFC_GRID,
                                 files="Source/**/*.cpp", write=_XTP_STDAFX)

RECIPES["xtp-11.2.2-vc8-shared-mfc"] = dict(
    src="xtp-11.2.2", langs=["cpp"], builds=[50727],
    include=_xtp_inc("xtp-11.2.2", "mfc-8.0"),
    defines="_AFXDLL _XTP_STATICLINK _DLL", grid=["/O2 /GS- /MD", "/O1 /GS- /MD"],
    files="Source/**/*.cpp", write=_XTP_STDAFX)

# PJ Naughter's CScintillaCtrl/CScintillaView v1.20, synchronized to Scintilla 1.76
# (the version shipped beside the 2009 client).  Keep this local: its license permits
# binary use but restricts source redistribution.  Provenance is TeXnicCenter commit
# 881e059d254b2cb921c0d239b5be16d97ad317ce; preserve its copyright headers.
_SCINTILLA_MFC_STDAFX = {"stdafx.h": "#pragma once\n#include <afxwin.h>\n#include <afxext.h>\n#include <afxdtctl.h>\n#include <afxtempl.h>\n#include <afxpriv.h>\n#include <afxmt.h>\n#include <afxcview.h>\n#include <afxcmn.h>\n#include \"Platform.h\"\n#include \"Scintilla.h\"\n#include \"SciLexer.h\"\n", "resource.h": "#pragma once\n#define IDS_SCINTILLA_DEFAULT_PRINT_FOOTER 40\n#define IDS_SCINTILLA_DEFAULT_PRINT_HEADER 41\n#define IDD_SCINTILLA_FINDDLGORD 328\n#define IDD_SCINTILLA_REPLACEDLGORD 329\n#define IDC_REGULAR_EXPRESSION 8606\n"}

RECIPES["scintilla-mfc-1.20"] = dict(src="scintilla-mfc-1.20", langs=["cpp"], builds=[21022, 30729],
                                       include=["scintilla-mfc-1.20", "mfc-9.0/atlmfc/include", "WINSDK"],
                                       grid=_MFC_GRID, files=["ScintillaCtrl.cpp", "ScintillaDocView.cpp"],
                                       write=_SCINTILLA_MFC_STDAFX, strip_header_asm="stripped-v2")

# 2008-06 imports mfc90.dll: shared MFC keeps AssertValid/Dump vtable slots (+8 bytes).
RECIPES["scintilla-mfc-1.20-shared"] = dict(RECIPES["scintilla-mfc-1.20"], defines="_AFXDLL _DLL",
                                              grid=["/O2 /GS- /MD", "/O2 /GS /EHsc /MD", "/O2 /MD /GS /EHsc /Ob1"])

# Same dllimport-call rule as XTP: CString members and FreeResource stay imported calls.
RECIPES["scintilla-mfc-1.20-shared-imports"] = dict(
    RECIPES["scintilla-mfc-1.20-shared"], noinline=RECIPES["xtp-11.2.2-lib-imports"]["noinline"],
    grid=["/O2 /MD /GS /EHsc /Ob1", "/O2 /GS- /MD", "/O2 /GS /EHsc /MD"])

RECIPES["scintilla-mfc-1.20-vc8"] = dict(src="scintilla-mfc-1.20", langs=["cpp"], builds=[50727],
                                           include=["scintilla-mfc-1.20", "mfc-8.0/atlmfc/include", "WINSDK"],
                                           grid=_MFC_GRID, files=["ScintillaCtrl.cpp", "ScintillaDocView.cpp"],
                                           write=_SCINTILLA_MFC_STDAFX, strip_header_asm="stripped-v2")

# Test: explicit _MBCS for DBCS lead byte calls (_ismbblead via IAT)
RECIPES["scintilla-mfc-1.20-mbcs"] = dict(RECIPES["scintilla-mfc-1.20"], defines="_MBCS",
                                           grid=_MFC_GRID)
RECIPES["scintilla-mfc-1.20-shared-mbcs"] = dict(RECIPES["scintilla-mfc-1.20-shared"], defines="_AFXDLL _DLL _MBCS",
                                                  grid=["/O2 /GS- /MD", "/O2 /GS /EHsc /MD", "/O2 /MD /GS /EHsc /Ob1"])

# Magic Software's Wild Magic 2 (2003), named directly in the 2009 client's
# copyrights.txt.  Its non-transferable license prohibits source redistribution,
# so this is a local-only recipe.  The archived tree is the public kucgbowling
# mirror commit 65e40b6f33c5511bddf0fa350c1eefc647ace48a; retain all headers.
RECIPES["wildmagic-2-core"] = dict(
    src="wildmagic-2", langs=["cpp"], builds=[50727, 21022, 30729],
    include=["wildmagic-2/Approximation", "wildmagic-2/Containment", "wildmagic-2/Curves",
             "wildmagic-2/Distance", "wildmagic-2/Geometry", "wildmagic-2/Graphics",
             "wildmagic-2/ImageAnalysis", "wildmagic-2/Interpolation", "wildmagic-2/Intersection",
             "wildmagic-2/Math", "wildmagic-2/Meshes", "wildmagic-2/Numerics",
             "wildmagic-2/RationalArithmetic", "wildmagic-2/Surfaces", "wildmagic-2/System",
             "wildmagic-2/Tessellation"],
    defines="WIN32 NDEBUG _LIB",
    grid=["/O2 /Ob1 /GS- /MT", "/O2 /Ob1 /GS- /MD", "/O2 /Ob2 /GS- /MD", "/Od /Ob1 /GS- /MT"],
    files="Math/*.cpp Distance/*.cpp Intersection/*.cpp Geometry/*.cpp Containment/*.cpp")

# LAME MP3 encoder, statically linked in the 2011-06 and 2012-06 clients
# (copyrights.txt: "This program uses Lame (www.mp3dev.org)"; no lame.dll import).
# vc9_libmp3lame.vcproj Release|Win32: /Ox /Ob2 /Ot /MD.
# configMS.h is the Windows config.h substitute; prepare copies it into the src folder
# so #include <config.h> (guarded by HAVE_CONFIG_H) resolves correctly.
# 3.98.4 (2010-04-14) matches the 2011-06 client; 3.99.5 (2012-02-28) targets 2012-06.
RECIPES["lame-3.98.4"] = dict(
    url="https://downloads.sourceforge.net/project/lame/lame/3.98.4/lame-3.98.4.tar.gz",
    sha256="ac3144c76617223a9be4aaa3e28a66b51bcab28141050c3af04cb06836f772c8",
    src="lame-3.98.4/libmp3lame", langs=["c"], builds=[21022, 30729],
    include=["lame-3.98.4/include", "lame-3.98.4/mpglib", "lame-3.98.4", "WINSDK"],
    defines="NDEBUG _WINDOWS HAVE_MPGLIB WIN32 HAVE_CONFIG_H",
    prepare=[("../configMS.h", "config.h")],
    grid=["/Ox /Ob2 /Ot /GS- /MD", "/O2 /Ob2 /GS- /MD", "/Ox /GS- /MD", "/O2 /GS- /MD"],
    files="*.c")

RECIPES["lame-3.99.5"] = dict(
    url="https://downloads.sourceforge.net/project/lame/lame/3.99/lame-3.99.5.tar.gz",
    sha256="24346b4158e4af3bd9f2e194bb23eb473c75fb7377011523353196b19b9a23ff",
    src="lame-3.99.5/libmp3lame", langs=["c"], builds=[21022, 30729],
    include=["lame-3.99.5/include", "lame-3.99.5/mpglib", "lame-3.99.5", "WINSDK"],
    defines="NDEBUG _WINDOWS HAVE_MPGLIB WIN32 HAVE_CONFIG_H",
    prepare=[("../configMS.h", "config.h")],
    grid=["/Ox /Ob2 /Ot /GS- /MD", "/O2 /Ob2 /GS- /MD", "/Ox /GS- /MD", "/O2 /GS- /MD"],
    files="*.c")

# unit() preprocesses without the grid's flags, so /MD never defined _DLL and CRT calls
# compiled direct (call sym) where /MD clients import them (call [__imp_]). Separate
# recipes keep existing exact sources reproducible.
for _name, _r in list(RECIPES.items()):
    _grid = [g for g in _r.get("grid", GRID) if "/MD" in g.split()]
    # Static MFC refuses _DLL (afx.h #error); mfc-9.0-shared covers the shared build.
    if _r.get("files") and _r.get("archive") is not True and _grid and not _name.startswith("mfc-") \
            and "_DLL" not in _r.get("defines", "").split():
        RECIPES[_name + "-dll"] = dict(_r, defines=(_r.get("defines", "") + " _DLL").strip(), grid=_grid)

# 2008-06 read_long_string (00664870) has no '[' nesting case and Roblox.exe lacks the
# "nesting of [[...]] is deprecated" string: built without LUA_COMPAT_LSTR (Roblox's
# 2016 luaconf.h/llex.c dropped it too).
RECIPES["lua-5.1.4-dll-nolstr"] = dict(RECIPES["lua-5.1.4-dll"],
                                       patches={"luaconf.h": [("#define LUA_COMPAT_LSTR\t\t1", "")]})

# 2008-06 was built with VS2008 RTM (cl 21022), whose ATL/MFC headers predate SP1 (e.g.
# CSimpleStringT::SetString, AFX_IMPORT_DATA). tools/libs/mfc-9.0-rtm/atlmfc holds the
# RTM include + src trees, extracted from the VS2008 Professional RTM DVD's cabinets
# (archive.org en_visual_studio_2008_professional_x86_dvd_x14-26326, vs_setup.msi Nov 2007).
for _name, _r in list(RECIPES.items()):
    _inc = _r.get("include", [])
    if (any(i.startswith("mfc-9.0/") for i in _inc) or _r.get("src", "").startswith("mfc-9.0/")) \
            and 21022 in _r.get("builds", BUILDS):
        RECIPES[_name + "-rtm"] = dict(
            _r, builds=[21022], include=[i.replace("mfc-9.0/", "mfc-9.0-rtm/", 1) for i in _inc],
            src="mfc-9.0-rtm" if _r.get("src") == "mfc-9.0" else
                _r["src"].replace("mfc-9.0/", "mfc-9.0-rtm/", 1) if "src" in _r else _r.get("src"))

def _case_path(path):
    """The on-disk path for a possibly differently-cased recipe path.

    Recipes were written on Windows, where Network/RakNet30 and Network/raknet30
    are the same directory. On Linux the checkout's real casing must be used or
    the file is simply not found (rbxgs-raknet failed exactly this way).
    """
    path = Path(path)
    if path.exists():
        return path
    current = Path(path.anchor) if path.is_absolute() else Path()
    parts = path.parts[1:] if path.is_absolute() else path.parts
    for part in parts:
        candidate = current / part
        if part in (".", "..") or candidate.exists():
            current = candidate
            continue
        parent = candidate.parent
        if not parent.is_dir():
            return path
        match = next((entry for entry in parent.iterdir() if entry.name.lower() == part.lower()), None)
        if match is None:
            return path
        current = match
    return current

BUNDLE = ROOT / "research" / "libs-bundle.json"  # tracked: Drive folder + sha256 of one zip per private tree
BUNDLE_DIR = ROOT / "work" / "libs-bundle"


def bundle_info():
    return json.loads(BUNDLE.read_text()) if BUNDLE.exists() else {}


def private_trees():
    """Top-level tools/libs folders no recipe can download (commercial or hand-collected sources)."""
    return sorted({r["src"].split("/")[0] for r in RECIPES.values()
                   if r.get("src") and not r.get("generate") and "url" not in r
                   and not r["src"].startswith("..") and (LIBS / r["src"].split("/")[0]).is_dir()})


def bundle_has(src):
    return src.split("/")[0] in bundle_info().get("trees", {})


def bundle_pack(out=BUNDLE_DIR):
    """One zip per private tree in `out`; upload the folder to Drive, then run bundle_index."""
    import zipfile
    out = Path(out)
    out.mkdir(parents=True, exist_ok=True)
    for tree in private_trees():
        with zipfile.ZipFile(out / (tree + ".zip"), "w", zipfile.ZIP_DEFLATED) as z:
            for path in sorted((LIBS / tree).rglob("*")):
                if path.is_file():
                    z.write(path, path.relative_to(LIBS).as_posix())
    return sorted(p.name for p in out.glob("*.zip"))


def bundle_index(link, zips=BUNDLE_DIR):
    """Read a shared Drive folder of <tree>.zip files and record each file id + sha256 in the manifest.
    The sha256 comes from the local zips (run on the PC that packed them)."""
    from roc import clients
    folder = re.search(r"folders/([\w-]+)|[?&]id=([\w-]+)", link)
    folder = (folder.group(1) or folder.group(2)) if folder else link
    trees = {}
    for fid, name, is_dir in clients.list_folder(folder):
        local = Path(zips) / name
        if name.endswith(".zip") and not is_dir and local.is_file():
            trees[name[:-4]] = dict(id=fid, size=local.stat().st_size, sha256=clients.sha256(local))
    if not trees:
        raise SystemExit("No <tree>.zip files found in that Drive folder (share it as 'anyone with the link') "
                         "that also exist in %s" % zips)
    BUNDLE.write_text(json.dumps(dict(folder=folder, trees=trees), indent=2, sort_keys=True) + "\n")
    return sorted(trees)


def bundle_fetch(names=None):
    """Download + verify + unpack the named private trees (default: all) into tools/libs."""
    import zipfile
    from roc import clients
    trees = bundle_info().get("trees", {})
    if not trees:
        raise SystemExit("No libs bundle recorded. On the PC with the trees: roc libs-bundle pack, upload "
                         "work/libs-bundle to Drive, roc libs-bundle index LINK, commit research/libs-bundle.json.")
    target = LIBS.resolve()
    done = []
    for name in names or sorted(trees):
        if name not in trees:
            raise SystemExit("%s is not in the bundle. Known: %s" % (name, ", ".join(sorted(trees))))
        if (LIBS / name).is_dir():
            continue
        info = trees[name]
        archive = LIBS / "_dl" / (name + ".zip")
        if not (archive.is_file() and clients.sha256(archive) == info["sha256"]):
            print("Downloading %s (%.1f MB)..." % (name, info["size"] / 1048576))
            clients.download(clients.DRIVE_DIRECT.format(id=info["id"]), archive)
            if clients.sha256(archive) != info["sha256"]:
                archive.unlink(missing_ok=True)
                raise SystemExit("REFUSED %s: sha256 does not match research/libs-bundle.json" % name)
        with zipfile.ZipFile(archive) as z:
            for member in z.namelist():  # zip-slip safe
                if (target / member).resolve().is_relative_to(target):
                    z.extract(member, target)
        done.append(name)
    return done


_FETCH_LOCK = threading.RLock()


def fetch(name):
    """Download + verify + unpack a recipe's source into tools/libs/. Returns the source folder.
    One at a time per process: parallel compile threads all call this, and two downloads of the
    same archive collide on its .part file."""
    with _FETCH_LOCK:
        return _fetch(name)


# Public repositories that recipes read in place (their folders sit beside tools/libs).
GIT_SOURCES = {"../rbxgs/": ("https://github.com/RBLXDecomp/RBXGSdecomp.git", "../rbxgs"),
               "../openrbx/": ("https://github.com/Asphaltian/OpenRBX.git", "../openrbx"),
               "../roblox2016/": ("https://github.com/Artifaqt/ROBLOX2016.git", "../roblox2016/src/ROBLOX2016-main")}


def _clone_source(repo, target):
    """Clone a public source repository with its submodules, once. A failed clone is removed."""
    if target.exists():
        return
    if not shutil.which("git"):
        raise SystemExit("Installing %s needs git. Install Git for Windows, then retry." % repo)
    target.parent.mkdir(parents=True, exist_ok=True)
    try:
        subprocess.run(["git", "clone", "--recursive", "--shallow-submodules", "--depth", "1", repo, str(target)],
                       check=True)
    except (subprocess.CalledProcessError, OSError):
        shutil.rmtree(target, ignore_errors=True)
        raise SystemExit("Could not download %s. Check the connection, then retry." % repo)


def _fetch(name):
    r = RECIPES[name]
    folder = _case_path(LIBS / r["src"])
    for dep in r.get("needs", []):
        fetch(dep)
    if r.get("generate"):  # deterministic generated sources: same files on every machine
        folder.mkdir(parents=True, exist_ok=True)
        for fname, text in r["generate"]().items():
            if not (folder / fname).exists() or (folder / fname).read_text() != text:
                (folder / fname).write_text(text)
        return folder
    if not folder.exists() and "url" not in r and bundle_has(r["src"]):
        bundle_fetch([r["src"].split("/")[0]])
        folder = _case_path(LIBS / r["src"])
    if not folder.exists() and "url" not in r:
        for prefix, (repo, dest) in GIT_SOURCES.items():
            if r["src"].startswith(prefix):
                _clone_source(repo, (LIBS / dest).resolve())
                folder = _case_path(LIBS / r["src"])
                break
    if not folder.exists() and "url" not in r:
        raise SystemExit("%s needs %s: extract the Roblox 2016 source tree there (see roc/refsource.py)"
                         % (name, folder.resolve()))
    if not folder.exists():
        archive = setup.download(r["url"], LIBS / r.get("archive", Path(r["url"]).name))
        digest = hashlib.sha256(archive.read_bytes()).hexdigest()
        if digest != r["sha256"]:
            archive.unlink()
            raise SystemExit("REFUSED %s: SHA-256 %s, expected %s" % (archive.name, digest, r["sha256"]))
        if archive.suffix == ".zip":
            import zipfile
            with zipfile.ZipFile(archive) as z:  # zip-slip safe: extract only names inside the target
                target = (LIBS / r.get("unpack", "")).resolve()
                for member in z.namelist():
                    if (target / member).resolve().is_relative_to(target):
                        z.extract(member, target)
        else:
            with tarfile.open(archive) as tar:
                target = (LIBS / r.get("unpack", "")).resolve()
                for member in tar:
                    # A few historical source releases ship editor/test symlinks.  They are
                    # irrelevant to ROC and Python's safe filter rejects absolute ones.
                    if member.issym() or member.islnk():
                        continue
                    if (target / member.name).resolve().is_relative_to(target):
                        tar.extract(member, target, filter="data")
    for src, dst in r.get("prepare", []):
        if not (folder / dst).exists():
            shutil.copyfile(folder / src, folder / dst)
    for rel, text in [*r.get("write", {}).items(),       # small generated files (e.g. XTP's StdAfx.h)
                      *generated_units().get(r["src"], {}).items()]:  # agent-written units stored sources use
        if (folder / rel).exists() and (folder / rel).read_text() == text:
            continue
        (folder / rel).parent.mkdir(parents=True, exist_ok=True)
        (folder / rel).write_text(text)
    return folder

# Translation units written by matching work (roc_fork_*, roc_client_*, ...) live inside a
# vendor tree under tools/libs, which is not shared. Stored sources point at them by name,
# so their text is kept in the findings repository (units/generated-units.json), downloaded
# by `roc pull` into local/units/ and written into the vendor tree by `fetch`.
UNITS_FILE = ROOT / "local" / "units" / "generated-units.json"
UNITS_URL = "https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/units/generated-units.json"


def fetch_units(log=print, url=UNITS_URL):
    """Download the shared units and merge them into the local cache (local additions are
    kept). Never raises: offline PCs keep working with what they have."""
    import urllib.request
    try:
        with urllib.request.urlopen(url, timeout=60) as reply:
            remote = json.loads(reply.read().decode("utf-8"))
        if not isinstance(remote, dict):
            raise ValueError("unexpected units file")
    except (OSError, ValueError) as error:
        log("Generated units not updated (%s); using the local copy." % error)
        return 0
    local, added = generated_units(), 0
    for src, files in remote.items():
        for name, text in files.items():
            if name not in local.get(src, {}):
                local.setdefault(src, {})[name] = text
                added += 1
    UNITS_FILE.parent.mkdir(parents=True, exist_ok=True)
    UNITS_FILE.write_text(json.dumps(local, indent=1, sort_keys=True), encoding="utf-8")
    log("Generated units: %d new, %d total." % (added, sum(map(len, local.values()))))
    return added


def units_used(source):
    """{recipe src: {relative name: text}} for the generated unit a source's `// roc-lib:` line names
    (empty when it names a normal vendor file). Reads the stored units, then the file in the tree."""
    recipe, _, rel = match.directives(source).get("lib", "").partition(" ")
    r = RECIPES.get(recipe)
    rel = rel.strip().replace("\\", "/")
    if not r or r.get("generate") or not rel.rsplit("/", 1)[-1].startswith("roc_"):
        return {}
    text = generated_units().get(r["src"], {}).get(rel)
    if text is None:
        path = _case_path(LIBS / r["src"]) / rel
        text = path.read_text(errors="replace") if path.is_file() else None
    return {r["src"]: {rel: text}} if text is not None else {}


def accept_units(units):
    """Server side: store generated units uploaded by a worker so submissions naming them can be verified.
    Only roc_*.cpp under a known recipe tree, no path tricks, bounded size. Returns how many were new."""
    known = {r["src"] for r in RECIPES.values() if r.get("src")}
    clean, count = {}, 0
    if not isinstance(units, dict) or len(units) > 20:
        raise ValueError("Bad units payload")
    for src, files in units.items():
        if src not in known or not isinstance(files, dict) or len(files) > 50:
            raise ValueError("Unknown library tree: %s" % str(src)[:80])
        for rel, text in files.items():
            parts = str(rel).replace("\\", "/").split("/")
            if (not isinstance(text, str) or len(text) > 400_000 or ".." in parts or "" in parts or ":" in rel
                    or not re.fullmatch(r"roc_[A-Za-z0-9_]+\.cpp", parts[-1])):
                raise ValueError("Rejected unit name: %s" % str(rel)[:80])
            if rel not in generated_units().get(src, {}):
                count += 1
            clean.setdefault(src, {})[rel] = text
    if clean:
        _store_units(clean)
    return count


def generated_units():
    try:
        return json.loads(UNITS_FILE.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}

def add_unit(recipe, text, prefix="roc_unit_"):
    """Write one generated unit into a recipe's tree under a content-hash name and keep it
    portable. Returns the file name a `// roc-lib:` line should use."""
    name = "%s%s.cpp" % (prefix, hashlib.sha256(text.encode()).hexdigest()[:16])
    path = fetch(recipe) / name
    path.write_text(text)
    _store_units({RECIPES[recipe]["src"]: {name: text}})
    return name

def _store_units(new):
    units = generated_units()
    for src, files in new.items():
        for name, text in files.items():
            if units.get(src, {}).get(name, text) != text:
                raise ValueError("Generated unit %s/%s already stored with other text" % (src, name))
            units.setdefault(src, {})[name] = text
    UNITS_FILE.parent.mkdir(parents=True, exist_ok=True)
    UNITS_FILE.write_text(json.dumps(units, indent=1, sort_keys=True), encoding="utf-8")

def capture_units(client):
    """Store every generated unit that this PC's sources for `client` reference but that no
    `generate` recipe recreates. Returns {recipe src: [names]} that were added."""
    return capture_source_units(path.read_text(errors="replace") for path in (ROOT / "src" / client).glob("*.cpp"))

def capture_source_units(sources):
    """Store the on-disk generated unit each source text names, when it is not stored yet.
    Units written straight into a vendor tree (not through add_unit) otherwise never leave this PC."""
    known, found = generated_units(), {}
    for source in sources:
        lib = match.directives(source).get("lib", "")
        name, _, rel = lib.partition(" ")
        r = RECIPES.get(name)
        rel = rel.strip().replace("\\", "/")
        if not r or r.get("generate") or not rel.rsplit("/", 1)[-1].startswith("roc_"):
            continue
        unit = _case_path(LIBS / r["src"]) / rel
        if rel in known.get(r["src"], {}) or not unit.is_file():
            continue
        found.setdefault(r["src"], {})[rel] = unit.read_text(errors="replace")
    if found:
        _store_units(found)
    return {src: sorted(files) for src, files in found.items()}

def preprocess(build, path, include, defines="", deps=None):
    """One self-contained translation unit: headers inlined, link-only pragmas dropped.
    `deps` (a list) receives every header the compiler opened (/showIncludes)."""
    cl = setup.compilers()[build]
    env = setup.cl_env(cl)
    if not setup.WINDOWS:  # Wine needs Windows-style include paths inside INCLUDE
        include = ";".join(setup.to_wine_path(p) for p in include.split(";") if p)
    env["INCLUDE"] = "%s;%s" % (include, env["INCLUDE"])
    if defines:
        env["CL"] = " ".join("/D" + d for d in defines.split())
        if "_AFXDLL" in defines.split() and "/MD" not in env["CL"] and "/MT" not in env["CL"]:
            env["CL"] += " /MD"
    started = time.monotonic()
    try:
        run = subprocess.run([*setup.cl_command(cl), "/nologo", "/EP", "/showIncludes", setup.cl_path(path)],
                             capture_output=True, text=True,
                             env=env, errors="replace", timeout=120)
    except subprocess.TimeoutExpired:
        raise match.CompileError("preprocessor timeout after 120 seconds")
    from roc import telemetry
    telemetry.record("compiler", event="timing", phase="preprocess", build=build,
                     seconds=time.monotonic() - started)
    notes = [l for l in run.stderr.splitlines() if l.startswith(INCLUDE_NOTE)]
    if run.returncode:
        raise match.CompileError("\n".join(l for l in run.stderr.splitlines() if l not in notes)[-500:])
    if deps is not None:
        deps.extend(_host_path(l[len(INCLUDE_NOTE):].strip()) for l in notes)
    # Link-only pragmas can span several lines (the CRT manifest one does): drop them whole.
    text = LINK_PRAGMA.sub("", run.stdout)
    return "\n".join(l for l in text.splitlines() if l.strip())

INCLUDE_NOTE = "Note: including file:"

def _host_path(path):
    """A path cl.exe printed, as this PC sees it (Wine prints Z:\\ for /)."""
    if setup.WINDOWS or not re.match(r"(?i)z:\\", path):
        return path
    return "/" + path[3:].replace("\\", "/")

LINK_PRAGMA = re.compile(r'#\s*pragma\s+(?:comment|include_alias)\s*\((?:"(?:\\.|[^"\\])*"|[^()"])*\)')

def unit(name, path, build):
    """Preprocessed translation unit for one library file, cached in work/libcache/.
    Only files of a known recipe, inside its folder, are accepted."""
    if name not in RECIPES:
        raise match.CompileError("unknown library %r" % name)
    folder = fetch(name).resolve()
    src = (folder / path).resolve()
    if not src.is_relative_to(folder) or not src.is_file():
        hint = " (generated unit: run `roc pull` to download it)" if path.rsplit("/", 1)[-1].startswith("roc_") else ""
        raise match.CompileError("no file %r in library %s%s" % (path, name, hint))
    r = RECIPES[name]
    suffix = ".%s.i" % r["strip_header_asm"] if r.get("strip_header_asm") else ".i"
    cache = ROOT / "work" / "libcache" / name / str(build) / (path.replace("\\", "/").replace("/", "__") + suffix)
    noinline = r.get("noinline", MFC_STRING_CALLS if r.get("noinline_mfc_strings") else ())
    identity = _recipe_identity(r, noinline)
    body = _cached_unit(cache, identity)
    if body is not None:
        return _file_literal(r, src, path, body)
    deps = []
    include = ";".join([str(folder)] + [winsdk_include() if i == "WINSDK" else str(_case_path(LIBS / i))
                                        for i in r.get("include", [])])
    if r.get("preinclude"):
        with match.compile_directory() as tmp:
            wrapper = Path(tmp) / "unit.cpp"
            wrapper.write_text("".join('#include "%s"\n' % header for header in r["preinclude"])
                               + '#include "%s"\n' % src.as_posix())
            body = preprocess(build, wrapper, include, r.get("defines", ""), deps)
    elif r.get("patches"):
        # Edits reconstructed from the client binary: preprocess a patched copy of the tree.
        with match.compile_directory() as tmp:
            copy = Path(tmp) / "src"
            shutil.copytree(folder, copy)
            for rel, edits in r["patches"].items():
                text = (copy / rel).read_text(errors="replace")
                for old, new in edits:
                    if old not in text:
                        raise match.CompileError("patch for %s no longer applies: %r" % (rel, old[:60]))
                    text = text.replace(old, new)
                (copy / rel).write_text(text)
            # Include dirs inside the tree read the patched copy too (header patches).
            include = ";".join(str(copy / Path(i).resolve().relative_to(folder))
                               if Path(i).resolve().is_relative_to(folder) else i for i in include.split(";"))
            body = preprocess(build, copy / path, include, r.get("defines", ""), deps)
            # __FILE__ and #line name the pristine tree, not the temporary copy.
            body = body.replace(str(copy).replace("\\", "\\\\"), str(folder).replace("\\", "\\\\"))
            deps = [folder / Path(d).resolve().relative_to(copy.resolve()) if Path(d).resolve().is_relative_to(copy.resolve())
                    else d for d in deps]  # patched copies: track the pristine file (patch text is in identity)
    else:
        body = preprocess(build, src, include, r.get("defines", ""), deps)
    for member in noinline:
        body = body.replace(member, "__declspec(noinline) " + member)
    if r.get("strip_header_asm"):
        body = re.sub(r"__asm\s*\{.*?\}", "", body, flags=re.S)
    cache.parent.mkdir(parents=True, exist_ok=True)
    cache.write_text(body)
    _write_deps(cache, identity, [src, *deps])
    return _file_literal(r, src, path, body)

# A preprocessed unit is only reusable while its recipe settings and every header it read are
# unchanged; otherwise an edited vendor header would replay stale output (or a stale error).
_UNIT_KEYS = ("src", "include", "preinclude", "defines", "patches", "strip_header_asm")

_UNITS = {}  # cache path -> (stamp, body): avoids re-reading big .i files in one process

def _recipe_identity(r, noinline):
    settings = {k: r.get(k) for k in _UNIT_KEYS}
    settings["noinline"] = list(noinline)
    return hashlib.sha256(json.dumps(settings, sort_keys=True, default=str).encode()).hexdigest()


def recipe_versions():
    """Fingerprints of loaded recipes, including callable filename rules."""
    import inspect
    return {name: hashlib.sha256(json.dumps(recipe, sort_keys=True,
            default=lambda value: inspect.getsource(value).strip() if callable(value) else str(value)).encode()).hexdigest()
            for name, recipe in RECIPES.items()}

def _sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def _write_deps(cache, identity, deps):
    files = {}
    for dep in dict.fromkeys(str(d) for d in deps):
        try:
            st = os.stat(dep)
            files[dep] = [st.st_size, st.st_mtime_ns, _sha256(dep)]
        except OSError:
            pass
    cache.with_suffix(cache.suffix + ".deps").write_text(json.dumps({"recipe": identity, "files": files}))
    _UNITS.pop(str(cache), None)

def _cached_unit(cache, identity):
    """Cached body when the recipe identity and all dependency contents still match, else None.
    Legacy caches without a .deps record are rebuilt once."""
    try:
        record = json.loads(cache.with_suffix(cache.suffix + ".deps").read_text())
    except (OSError, ValueError):
        return None
    if record.get("recipe") != identity:
        return None
    stamp, refreshed = [], False
    for dep, (size, mtime, digest) in record["files"].items():
        try:
            st = os.stat(dep)
        except OSError:
            return None
        if st.st_size != size or _sha256(dep) != digest:
            return None
        if st.st_mtime_ns != mtime:
            record["files"][dep] = [size, st.st_mtime_ns, digest]  # touched, same content
            refreshed = True
        stamp.append((dep, st.st_size, st.st_mtime_ns))
    if refreshed:
        cache.with_suffix(cache.suffix + ".deps").write_text(json.dumps(record))
    stamp = tuple(stamp)
    hit = _UNITS.get(str(cache))
    if hit and hit[0] == stamp:
        return hit[1]
    try:
        body = cache.read_text(errors="replace")
    except OSError:
        return None
    _UNITS[str(cache)] = (stamp, body)
    return body

def _file_literal(recipe, src, path, body):
    """__FILE__ as the original build spelled it (recipe `file_names`), not this PC's path."""
    names = recipe.get("file_names")
    if not names:
        return body
    rel = path.replace("/", "\\")
    spelled = names.get(rel) or names["*"](rel)
    esc = lambda s: '"%s"' % s.replace("\\", "\\\\")
    return body.replace(esc(str(src)), esc(spelled))

def source_for(name, path, lang=None, build=None, flags=None):
    """The small matched-source text: settings plus a pointer to the library file.

    Missing settings default to the recipe's first build and grid flags (agents call this directly).
    """
    r = RECIPES[name]
    kind = "archive" if r.get("archive") is True else "lib"
    lang = lang or ("c" if path.lower().endswith(".c") else "cpp")
    build = build if build is not None else r.get("builds", [21022])[0]
    flags = flags if flags is not None else r.get("grid", GRID)[0]
    return ("// roc-lang: %s\n// roc-cl: %d\n// roc-flags: %s\n// roc-%s: %s %s\n"
            % (lang, build, flags, kind, name, path.replace("\\", "/")))

def _compile_variants(client, name, f, lang, build, r):
    """One file across a recipe's flag grid; run in parallel with other files.

    Keeps the sequential break: the first flag that fails to compile means the
    remaining flags will not help either.
    """
    out = []
    for flags in r.get("grid", GRID):
        src = source_for(name, f, lang, build, flags)
        try:
            obj = match.compile_text(client, src, flags=flags, build=build)
        except match.CompileError:
            break
        out.append((src, obj))
    return out

def run(names, targets, log=print):
    """Try every library recipe in `names` against the given client names. Returns {client: new}."""
    have = setup.compilers()
    tgts = {c: fingerprint.Target(c) for c in targets}
    new = {c: 0 for c in targets}
    jobs = int(os.environ.get("ROC_JOBS") or 0) or min(12, os.cpu_count() or 4)
    for name in names:
        r = RECIPES[name]
        if r.get("archive") is True:
            t0, hits = time.time(), 0
            for build in [b for b in r["builds"] if b in have]:
                for library, member, obj in archive_files(r, build):
                    src = source_for(name, "%s/%s" % (library, member), "cpp", build, "")
                    for c, t in tgts.items():
                        found = t.match_obj(obj, src)
                        if found:
                            hits += len(found)
                            new[c] += fingerprint.save(c, found, "CRT %s/%s" % (library, member))
            log("%s: done (%.0fs), new so far %s" % (name, time.time() - t0, new))
            continue
        try:
            folder = fetch(name)
        except SystemExit as e:
            if "url" in r or r.get("generate"):
                raise
            log("%s: skipped, %s" % (name, e))  # local-only source not on this PC
            continue
        t0, hits = time.time(), 0
        for build in [b for b in r.get("builds", BUILDS) if b in have]:
            ready = []
            for f in files_of(r, folder):
                try:
                    unit(name, f, build)  # preprocess once (cached); skip files that don't
                except match.CompileError:
                    continue
                ready.extend((f, lang) for lang in r["langs"])
            # Compiles dominate this pass (~0.3s each, tens of thousands of them),
            # so run them concurrently and keep matching/saving serial: the
            # fingerprint index is shared state.
            with ThreadPoolExecutor(max_workers=jobs) as pool:
                futures = {pool.submit(_compile_variants, targets[0], name, f, lang, build, r): f
                           for f, lang in ready}
                for future in as_completed(futures):
                    f = futures[future]
                    try:
                        variants = future.result()
                    except Exception:
                        continue
                    for src, obj in variants:
                        for c, t in tgts.items():
                            found = t.match_obj(obj, src)
                            if found:
                                hits += len(found)
                                new[c] += fingerprint.save(c, found, "library %s/%s" % (name, f))
        log("%s: done (%.0fs), new so far %s" % (name, time.time() - t0, new))
    return new

def default_targets():
    have = setup.compilers()
    return [n for n, e in sorted(clients.load().items())
            if clients.status(n, e) == "ok" and (ROOT / "work" / n / "functions.jsonl").exists()
            and e.get("compiler_build") in have]


# --- libraries ---
# Library of a unit label: the same rules as the progress site's table (docs/index.html).

_MFC = re.compile(r"^(?:[A-Z0-9_$]*V)?C(?:Wnd|FrameWnd|MDIFrameWnd|MDIChildWnd|Edit|Static|ListBox|ComboBox|Button|Brush|Pen|Rgn|Rect|Point|Size|PtrList|PtrArray|ObList|StringList|StringArray|Ole\w*|CmdUI|EnabledCmdUI|Dialog|View|Document|WinApp|WinThread|Object|Archive|File|Exception|DC|ClientDC|PaintDC|WindowDC|GdiObject|Bitmap|Font|Menu|ImageList|ToolBar|StatusBar|ControlBar|SplitterWnd|ScrollView|FormView|EditView|HtmlView|HtmlEditView|DHtmlDialog|PropertySheet|PropertyPage|TreeCtrl|ListCtrl|TabCtrl|SpinButtonCtrl|ProgressCtrl|SliderCtrl|DockState|DockBar|DocTemplate|SingleDocTemplate|MultiDocTemplate|DocManager|MemFile|String|Map\w+|Array|CommandLineInfo|RecentFileList|Mini\w*Wnd)$")


RULES = [
    ("XTP (Codejock)", lambda u: re.search(r"CXTP|XTP[A-Z_]|(^|V)CXT[A-Z]", u)),
    ("G3D", lambda u: "G3D" in u),
    ("Ogre", lambda u: "Ogre" in u),
    ("boost", lambda u: "boost" in u),
    ("RakNet", lambda u: re.search(r"RakPeer|RakNet|PacketReliab", u)),
    ("Scintilla", lambda u: "Scintilla" in u),
    ("Lua", lambda u: re.search(r"(^|[^A-Za-z])lua_|^lua", u)),
    ("STL (std)", lambda u: re.match(r"std(::|$)", u)),
    ("ATL", lambda u: re.match(r"ATL(::|$)", u)),
    ("MFC", lambda u: _MFC.match(re.split(r"::|<|\?\$", u)[0])),
    ("Roblox engine (RBX)", lambda u: re.search(r"RBX|rbx", u)),
    ("Unlabeled (no RTTI nearby)", lambda u: not u or u.startswith("seg_")),
]


OTHER = "Roblox app / other"


NAMES = [name for name, _ in RULES] + [OTHER]


@functools.lru_cache(maxsize=65536)
def library_of(unit):
    unit = unit or ""
    return next((name for name, test in RULES if test(unit)), OTHER)
