"""Match the open-source libraries the clients link in, straight from their real source.

For each library file: preprocess it into one self-contained unit (headers inlined),
compile it once per compiler/flag combination, then compare every resulting function
against every client. The matched source carries `// roc-lang/cl/flags` lines, so
`roc check` and the server re-verify it with exactly the settings that matched.

Sources are downloaded from the projects' own sites and checked against pinned SHA-256.
"""
import hashlib
import re
import shutil
import subprocess
import tarfile
import time
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


_PNG = ("png pngerror pngget pngmem pngpread pngread pngrio pngrtran pngrutil pngset pngtrans pngwio "
        "pngwrite pngwtran pngwutil").split()
FAST = ["/O2 /GS- /MD"]  # what every library so far was built with
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


# G3D 6.09 (2007-2010 clients) bundles its own zlib, libjpeg and libpng. Old releases left
# SourceForge; this is the archive.org copy (SHA-1 matches archive.org's record).
RECIPES["g3d-6.09"] = dict(url="https://archive.org/download/g3d-src-6_09/g3d-src-6_09.zip",
                           sha256="d8036ded1a9730d80c5a2f5397efc958d6613ca41a1c7b842b212c3be7e0b6ff",
                           unpack="g3d-6.09", src="g3d-6.09/source", langs=["cpp"],
                           # /GS on (VS2005's default) is how G3D's own VC8 build was compiled.
                           grid=["/O2 /GS /EHsc /MD", "/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast", "/O2 /GS- /EHsc /MD",
                                 "/O2 /GS- /MD /arch:SSE2 /fp:fast", "/O2 /GS- /MD"],
                           include=["g3d-6.09/source/include", "g3d-6.09/source/boost/include", "WINSDK",
                                    "SDL-1.2.11/include"],
                           needs=["sdl-1.2.11"], files="G3Dcpp/*.cpp GLG3Dcpp/*.cpp")
RECIPES["sdl-1.2.11"] = dict(url="https://www.libsdl.org/release/SDL-1.2.11.tar.gz",  # headers for GLG3D
                             sha256="6985823287b224b57390b1c1b6cbc54cc9a7d7757fbf9934ed20754b4cd23730",
                             src="SDL-1.2.11/include", langs=[], files=[])


_BOOST_SRC = ("libs/signals/src/*.cpp libs/thread/src/*.cpp libs/thread/src/win32/*.cpp libs/filesystem/src/*.cpp "
              "libs/system/src/*.cpp libs/iostreams/src/*.cpp libs/date_time/src/gregorian/*.cpp "
              "libs/date_time/src/posix_time/*.cpp libs/regex/src/*.cpp libs/program_options/src/*.cpp")
for _v, _sha in [("1.34.1", "ef99062117068a0d641f4045c421661768657262a3d119c4a272c97a3e7ae5b3"),
                 ("1.36.0", "7f790b1636c2fdad23c0134db4c28433f90524c981ac752d8a9c8041a00b942c"),
                 ("1.35.0", "c0816cf644653a7bf8b41993261156249bd888840a12d828f3df8329277521f4"),
                 ("1.38.0", "ff8c3fc932b21453ca31d28903419617f41b2110aba341256eb31be3435843af"),
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
    lib = Path(cl).parents[1] / "lib" / library
    for found, obj in archive_members(lib):
        if found == member:
            return obj
    raise match.CompileError("no member %r in %s" % (member, lib))


def archive_files(r, build):
    cl = setup.compilers()[build]
    folder = Path(cl).parents[1] / "lib"
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
               "/O2 /GS- /EHsc /MD", "/O1 /Ob2 /Oy /GS- /EHsc /MD"]
RECIPES["rbxgs"] = dict(src=_RBXGS + "App", langs=["cpp"], files="**/*.cpp",
                        grid=_RBXGS_GRID, include=_RBXGS_INC, defines=_RBXGS_DEF)
# The Network project: Roblox's networking (RBX::Network::Replicator, Player, Server).
_RBXGS_NET_INC = [_RBXGS + d for d in ("Network/include", "Network/include/network", "App/include",
                  "Network/RakNet30/source", "Rendering/g3d/include", "Rendering/g3d/zlib",
                  "Rendering/png", "boost_1_34_1/src", "App/lua-5.1.1/src", "Rendering/AppDraw/include",
                  "Rendering/SDL-1.2.6/include", "Rendering/RenderLib/include", "RbxGraphics/include")] + ["WINSDK"]
RECIPES["rbxgs-net"] = dict(src=_RBXGS + "Network", langs=["cpp"], files="*.cpp",
                            grid=_RBXGS_GRID, include=_RBXGS_NET_INC, defines=_RBXGS_DEF)
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

# Exact CRT/STL objects from each installed compiler. Fingerprint archive members directly.
RECIPES["msvc-crt"] = dict(archive=True, builds=[50727, 21022, 30729],
                            files=["libcmt.lib", "libcpmt.lib"])

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

# Codejock Xtreme Toolkit Pro, statically linked by the clients (the CXTP* units). XTP is built
# on MFC, so it needs the matching MFC headers. v15.2.1 is (c)1998-2011 -> the 2011-06/2012-06
# clients. No URL: extracted locally from github.com/mavaL/NeoEngine (Dependency/XTP) into
# tools/libs/xtp-15.2.1/, with a one-line Source/StdAfx.h (#include "XTToolkitPro.h") added, since
# every XTP .cpp opens with #include "StdAfx.h" and the umbrella header lives at Source root.
_XTP_INC = ["xtp-15.2.1/Source", "mfc-9.0/atlmfc/include", "WINSDK"]
_XTP_STDAFX = {"Source/StdAfx.h": '#include "XTToolkitPro.h"\n'}
RECIPES["xtp-15.2.1"] = dict(src="xtp-15.2.1", langs=["cpp"], builds=[30729, 21022], include=_XTP_INC,
                             grid=_MFC_GRID, files="Source/**/*.cpp", write=_XTP_STDAFX)

# Older XTP for the older clients (archive.org): v13.2.1 (2010) -> 2010-06, v11.2.2 (2008) ->
# 2008-06. Both build on MFC 9.0. v11 also builds on MFC 8.0 (VS2005) for the 2007-08 client,
# whose own XTP release (v9.60) shipped headers only, no source.
def _xtp_inc(ver, mfc):
    return ["%s/Source" % ver, "%s/atlmfc/include" % mfc, "WINSDK"]
RECIPES["xtp-13.2.1"] = dict(src="xtp-13.2.1", langs=["cpp"], builds=[30729, 21022],
                             include=_xtp_inc("xtp-13.2.1", "mfc-9.0"), grid=_MFC_GRID,
                             files="Source/**/*.cpp", write=_XTP_STDAFX)
RECIPES["xtp-11.2.2"] = dict(src="xtp-11.2.2", langs=["cpp"], builds=[30729, 21022],
                             include=_xtp_inc("xtp-11.2.2", "mfc-9.0"), grid=_MFC_GRID,
                             files="Source/**/*.cpp", write=_XTP_STDAFX)
RECIPES["xtp-11.2.2-vc8"] = dict(src="xtp-11.2.2", langs=["cpp"], builds=[50727],
                                 include=_xtp_inc("xtp-11.2.2", "mfc-8.0"), grid=_MFC_GRID,
                                 files="Source/**/*.cpp", write=_XTP_STDAFX)


def fetch(name):
    """Download + verify + unpack a recipe's source into tools/libs/. Returns the source folder."""
    r = RECIPES[name]
    folder = LIBS / r["src"]
    for dep in r.get("needs", []):
        fetch(dep)
    if r.get("generate"):  # deterministic generated sources: same files on every machine
        folder.mkdir(parents=True, exist_ok=True)
        for fname, text in r["generate"]().items():
            if not (folder / fname).exists() or (folder / fname).read_text() != text:
                (folder / fname).write_text(text)
        return folder
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
                tar.extractall(LIBS, filter="data")
    for src, dst in r.get("prepare", []):
        if not (folder / dst).exists():
            shutil.copyfile(folder / src, folder / dst)
    for rel, text in r.get("write", {}).items():          # small generated files (e.g. XTP's StdAfx.h)
        if (folder / rel).exists() and (folder / rel).read_text() == text:
            continue
        (folder / rel).parent.mkdir(parents=True, exist_ok=True)
        (folder / rel).write_text(text)
    return folder


def preprocess(build, path, include, defines=""):
    """One self-contained translation unit: headers inlined, link-only pragmas dropped."""
    cl = setup.compilers()[build]
    env = setup.cl_env(cl)
    env["INCLUDE"] = "%s;%s" % (include, env["INCLUDE"])
    if defines:
        env["CL"] = " ".join("/D" + d for d in defines.split())
    try:
        run = subprocess.run([cl, "/nologo", "/EP", str(path)], capture_output=True, text=True,
                             env=env, errors="replace", timeout=120)
    except subprocess.TimeoutExpired:
        raise match.CompileError("preprocessor timeout after 120 seconds")
    if run.returncode:
        raise match.CompileError(run.stderr[-500:])
    # Link-only pragmas can span several lines (the CRT manifest one does): drop them whole.
    text = LINK_PRAGMA.sub("", run.stdout)
    return "\n".join(l for l in text.splitlines() if l.strip())


LINK_PRAGMA = re.compile(r'#\s*pragma\s+(?:comment|include_alias)\s*\((?:"(?:\\.|[^"\\])*"|[^()"])*\)')


def unit(name, path, build):
    """Preprocessed translation unit for one library file, cached in work/libcache/.
    Only files of a known recipe, inside its folder, are accepted."""
    if name not in RECIPES:
        raise match.CompileError("unknown library %r" % name)
    folder = fetch(name).resolve()
    src = (folder / path).resolve()
    if not src.is_relative_to(folder) or not src.is_file():
        raise match.CompileError("no file %r in library %s" % (path, name))
    cache = ROOT / "work" / "libcache" / name / str(build) / (path.replace("\\", "/").replace("/", "__") + ".i")
    if cache.exists():
        return cache.read_text(errors="replace")
    r = RECIPES[name]
    include = ";".join([str(folder)] + [winsdk_include() if i == "WINSDK" else str(LIBS / i)
                                        for i in r.get("include", [])])
    body = preprocess(build, src, include, r.get("defines", ""))
    cache.parent.mkdir(parents=True, exist_ok=True)
    cache.write_text(body)
    return body


def source_for(name, path, lang, build, flags):
    """The small matched-source text: settings plus a pointer to the library file."""
    kind = "archive" if RECIPES[name].get("archive") is True else "lib"
    return ("// roc-lang: %s\n// roc-cl: %d\n// roc-flags: %s\n// roc-%s: %s %s\n"
            % (lang, build, flags, kind, name, path.replace("\\", "/")))


def run(names, targets, log=print):
    """Try every library recipe in `names` against the given client names. Returns {client: new}."""
    have = setup.compilers()
    tgts = {c: fingerprint.Target(c) for c in targets}
    new = {c: 0 for c in targets}
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
            for f in files_of(r, folder):
                try:
                    unit(name, f, build)  # preprocess once (cached); skip files that don't
                except match.CompileError:
                    continue
                for lang in r["langs"]:
                    for flags in r.get("grid", GRID):
                        src = source_for(name, f, lang, build, flags)
                        try:
                            obj = match.compile_text(targets[0], src, flags=flags, build=build)
                        except match.CompileError:
                            break  # this language can't compile the file: other flags won't help
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
