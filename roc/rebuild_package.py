"""Publish native source and required build inputs without moving live inputs."""
import hashlib
from concurrent.futures import ThreadPoolExecutor
import json
import locale
import os
from pathlib import Path
import re
import threading

TEXT = {'.py', '.json', '.h', '.hpp', '.c', '.cpp', '.cxx', '.inl', '.md', '.txt',
        '.bat', '.cmd', '.ps1', '.xml', '.manifest', '.log', '.err', '.out', '.asm',
        '.csv', '.yml', '.yaml', '.ini', '.cfg', '.cmake', '.vcproj', '.sln', '.dsp', '.dsw'}
MAX_BLOB = 95 * 1024 * 1024
WEBHOOK = re.compile(rb'https://(?:canary\.|ptb\.)?discord(?:app)?\.com/api/webhooks/[^\s\x22\x27<>]+')


def files(root):
    for directory, folders, names in os.walk(root, followlinks=False):
        folders[:] = sorted(name for name in folders if name not in {'.git', '__pycache__', '.pytest_cache'})
        for name in sorted(names):
            path = Path(directory) / name
            if path.suffix.lower() not in {'.key', '.pem'} and name.lower() not in {
                'api-keys.cmd', 'native-integration-token', 'roconstruct-secrets.json',
                'roconstruct-settings.json', 'roconstruct-providers.json', '.env'}:
                yield path


def mapped(relative):
    first, *rest = relative.parts
    if first == 'out' and relative.suffix.lower() in {'.log', '.err'}:
        return Path('work/logs', *rest)
    prefix = {'modules': ('config',), 'out': ('work', 'build'),
              'manifests': ('verification', 'manifests'), 'glue': ('src', 'glue')}.get(first)
    if prefix:
        return Path(*prefix, *rest)
    if len(relative.parts) == 1 and relative.suffix == '.py':
        return Path('scripts') / relative
    if len(relative.parts) == 1:
        return Path('work/build/artifacts') / relative
    return relative


def export(root, destination):
    """Export the usable source package; archive old generated exports locally."""
    root, destination = Path(root), Path(destination)
    source = root / 'rebuild/2008-06'
    destination.mkdir(parents=True, exist_ok=True)
    previous = destination / 'package.json'
    owned = set(json.loads(previous.read_text(encoding='utf-8'))['files']) if previous.exists() else set()
    hashes, large, wanted, pending, locks = {}, {}, set(), [], {}
    harnesses = {'m2_window.cpp', 'm4_datamodel.cpp', 'm4_render.cpp', 'm5_place.cpp'}
    for path in (source / 'modules').glob('*.json'):
        spec = json.loads(path.read_text(encoding='utf-8'))
        if spec.get('test'):
            harnesses.add(spec['test'] + '.cpp')

    def write(relative, data):
        name = Path(relative).as_posix()
        if Path(name).is_absolute() or '..' in Path(name).parts:
            raise ValueError('Unsafe package path: ' + name)
        target = destination / name
        target.parent.mkdir(parents=True, exist_ok=True)
        with locks.setdefault(name, threading.Lock()):
            if not target.exists() or target.read_bytes() != data:
                target.write_bytes(data)
        wanted.add(name)
        hashes[name] = hashlib.sha256(data).hexdigest()

    def copy(path, relative, data=None):
        if data is None:
            try:
                before = path.stat()
                data = path.read_bytes()
                after = path.stat()
                if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
                    raise PermissionError('Artifact changed during export')
            except (PermissionError, FileNotFoundError):
                if path.is_relative_to(source / 'out'):
                    pending.append(Path(relative).as_posix())
                    return
                raise
        if path.suffix.lower() in TEXT or path.name in {'CMakeLists.txt', 'Makefile', '.gitignore'}:
            data = WEBHOOK.sub(b'DISCORD_WEBHOOK_REDACTED', data.replace(b'\r\n', b'\n'))
        elif WEBHOOK.search(data):
            raise ValueError('Credential found in binary; export stopped: ' + str(relative))
        if len(data) < MAX_BLOB:
            write(relative, data)
            return
        raise ValueError('Required source exceeds Git file budget: ' + str(relative))

    def copy_rebuild(path):
        relative = path.relative_to(source)
        # Canonical views and compatibility aliases can coexist in the live checkout.
        # Export each authoritative tree once.
        if relative.parts[0] in {'src', 'work', 'config', 'scripts', 'out'}:
            return
        if relative.parts[0] == 'tests' and path.suffix not in {'.cpp', '.h', '.hpp', '.inl'}:
            return
        if relative.parts[0] == 'tests' and path.suffix == '.cpp' and path.name not in harnesses:
            return
        if path.name in {'POLICY.md', 'README.md', '.gitignore', 'compile_test.bat'}:
            return
        if len(relative.parts) == 1 and path.suffix != '.py':
            return
        copy(path, mapped(relative))
    with ThreadPoolExecutor(max_workers=4) as pool:
        list(pool.map(copy_rebuild, files(source)))

    tree = root / 'tools/rbxgs/Client'
    overlay_path = source / 'patches/rbxgs-client.json'
    overlay = json.loads(overlay_path.read_text(encoding='utf-8')) if overlay_path.exists() else {}
    adopted_units = {new.replace('\\', '/').casefold() for edits in overlay.values() for old, new in edits if old == '@replace'}
    overlay_names = {name.replace('\\', '/').casefold(): edits for name, edits in overlay.items()}
    def copy_native(path):
        relative = path.relative_to(tree)
        if path.name.startswith('roc_') and relative.as_posix().casefold() not in adopted_units:
            return
        code = {'.c', '.cpp', '.cxx', '.h', '.hpp', '.hxx', '.inc', '.inl', '.ipp', '.tcc', '.asm', '.def', '.rc', '.xml', '.json', '.cfg', '.ini', '.png', '.jpg', '.jpeg', '.bmp', '.ico', '.tga', '.dds', '.ttf', '.mesh', '.material', '.glsl', '.vert', '.frag', '.lua', '.luau', '.rbxl', '.rbxlx', '.rbxm', '.rbxmx', '.fnt', '.wav', '.ogg'}
        notice = any(word in path.name.lower() for word in ('license', 'copying', 'copyright', 'notice'))
        if path.suffix.lower() not in code and not notice:
            return
        if not notice and any(part.lower() in {'doc', 'docs', 'examples', 'example', 'test', 'tests'} for part in relative.parts[:-1]):
            return
        edits = overlay_names.get(relative.as_posix().casefold())
        data = None
        if edits:
            text = path.read_text(errors='replace')
            for old, new in edits:
                if old == '@replace':
                    adopted = (tree / new).resolve()
                    if not adopted.is_relative_to(tree.resolve()):
                        raise ValueError('Adoption escapes native source tree')
                    text = adopted.read_text(errors='replace')
                else:
                    needle = old[5:] if old.startswith('@all:') else old
                    if needle and needle not in text:
                        raise ValueError('Overlay anchor missing: ' + relative.as_posix())
                    text = text.replace(needle, new) if old.startswith('@all:') else text.replace(old, new, 1) if old else text + new
            data = text.encode(locale.getpreferredencoding(False))
        copy(path, Path('src/rbxgs/Client') / relative, data)
    native_files = list(files(tree))
    native_names = {path.relative_to(tree).as_posix().casefold() for path in native_files}
    with ThreadPoolExecutor(max_workers=8) as pool:
        list(pool.map(copy_native, native_files))
    for relative, edits in overlay.items():
        if relative.replace('\\', '/').casefold() in native_names:
            continue
        if any(old for old, _ in edits):
            raise ValueError('Overlay source missing: ' + relative)
        write(Path('src/rbxgs/Client') / relative, ''.join(new for _, new in edits).encode())

    # The current build helpers are retained for diagnostics. The package launcher
    # builds a private legacy view so existing ROC commands keep their proven paths.
    launcher = Path(__file__).with_name('rebuild_package_launcher.py')
    copy(launcher, Path('scripts/compile_test.py'))
    write('compile_test.bat', b'@echo off\r\nsetlocal\r\npython "%~dp0scripts\\compile_test.py" %*\r\nset "result=%errorlevel%"\r\nif "%~1"=="" pause\r\nexit /b %result%\r\n')
    write('README.md', b'# 2008-06 native rebuild\n\nRun compile_test.bat with ROC_ROOT set to a configured RoConstruct checkout containing the historical compilers and dependencies. The default builds engine modules and runs their runtime harnesses. --smoke-only checks the toolchain; --tests-only relinks against a prior local build. Renderer failures are reported honestly; this is not yet a complete playable client.\n\n- src/rbxgs/Client/: assembled native C++ and required assets.\n- src/glue/: build glue.\n- ../src/2008-06/: recovered functions and library build recipes (stable URLs).\n- config/ and patches/: module definitions, overlays and their provenance. Native source already has the overlay applied.\n- tests/: only runtime harnesses required by module definitions and compile_test.bat.\n- scripts/: build and ABI checks used by RoConstruct.\n- verification/: accepted integration history, proposal states, source locations and required binary-analysis manifests.\n\nBuild outputs stay local under work/. Compiler installs and external library dependencies are supplied by RoConstruct. Original vendor license notices remain with their sources. Package metadata is not a new acceptance receipt.\n')
    for name in ('accepted-integrations.json', 'integration-jobs.json', 'native-credit.json', 'inventory.json', 'runtime-tests.json'):
        path = destination / 'verification' / name
        if path.exists():
            copy(path, Path('verification') / name)
    from roc.findings_links import native_sources
    names_path = source / 'out/native-names.json'
    names = json.loads(names_path.read_text(encoding='utf-8')) if names_path.exists() else {}
    links = native_sources(destination, hashes, names)
    write('verification/native-source-links.json', (json.dumps(links, sort_keys=True, indent=1) + '\n').encode())
    # Generated indexes and stale prior export files belong to this exporter only.
    for relative in owned - wanted:
        path = (destination / relative).resolve()
        if path.is_relative_to(destination.resolve()):
            if path.is_file():
                archive = root / 'work/archive/findings-pre-cleanup-20261027/2008-06' / relative
                archive.parent.mkdir(parents=True, exist_ok=True)
                if archive.exists():
                    if archive.read_bytes() == path.read_bytes():
                        path.unlink()
                    else:
                        archive = archive.with_name(archive.name + '-' + hashlib.sha256(path.read_bytes()).hexdigest()[:12])
                        path.replace(archive)
                else:
                    path.replace(archive)
    manifest = {'format': 1, 'source': 'native source and required build inputs', 'files': hashes,
                'overlay_sha256': hashlib.sha256(overlay_path.read_bytes()).hexdigest() if overlay_path.exists() else None,
                'native_source_overlay_applied': True, 'large_files': large,
                'pending_build_files': pending}
    (destination / 'package.json').write_text(json.dumps(manifest, indent=2, sort_keys=True) + '\n', encoding='utf-8')
    return manifest
