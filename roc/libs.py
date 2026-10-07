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
                                   langs=["c"], grid=FAST, include=["zlib-1.2.3"],
                                   files=[f + ".c" for f in _PNG])


# G3D 6.09 (2007-2010 clients) bundles its own zlib, libjpeg and libpng. Old releases left
# SourceForge; this is the archive.org copy (SHA-1 matches archive.org's record).
RECIPES["g3d-6.09"] = dict(url="https://archive.org/download/g3d-src-6_09/g3d-src-6_09.zip",
                           sha256="d8036ded1a9730d80c5a2f5397efc958d6613ca41a1c7b842b212c3be7e0b6ff",
                           unpack="g3d-6.09", src="g3d-6.09/source", langs=["cpp"],
                           grid=["/O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast", "/O2 /GS- /EHsc /MD",
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
                 ("1.40.0", "10f1ae33c9c25105554653aa7e86052e7afc9fe797c3cf188a5c8951965ae0d7")]:
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


for _b in ("1_34_1", "1_40_0"):
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
RECIPES["compat"] = dict(generate=lambda: {"stdint.h": STDINT}, src="compat", langs=[], files=[])

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
    return folder


def preprocess(build, path, include):
    """One self-contained translation unit: headers inlined, link-only pragmas dropped."""
    cl = setup.compilers()[build]
    env = setup.cl_env(cl)
    env["INCLUDE"] = "%s;%s" % (include, env["INCLUDE"])
    run = subprocess.run([cl, "/nologo", "/EP", str(path)], capture_output=True, text=True,
                         env=env, errors="replace")
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
    body = preprocess(build, src, include)
    cache.parent.mkdir(parents=True, exist_ok=True)
    cache.write_text(body)
    return body


def source_for(name, path, lang, build, flags):
    """The small matched-source text: settings plus a pointer to the library file."""
    return ("// roc-lang: %s\n// roc-cl: %d\n// roc-flags: %s\n// roc-lib: %s %s\n"
            % (lang, build, flags, name, path.replace("\\", "/")))


def run(names, targets, log=print):
    """Try every library recipe in `names` against the given client names. Returns {client: new}."""
    have = setup.compilers()
    tgts = {c: fingerprint.Target(c) for c in targets}
    new = {c: 0 for c in targets}
    for name in names:
        r = RECIPES[name]
        try:
            folder = fetch(name)
        except SystemExit as e:
            if "url" in r or r.get("generate"):
                raise
            log("%s: skipped, %s" % (name, e))  # local-only source not on this PC
            continue
        t0, hits = time.time(), 0
        for build in [b for b in BUILDS if b in have]:
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
