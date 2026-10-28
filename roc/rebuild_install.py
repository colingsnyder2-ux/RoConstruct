"""Restore legacy ROC build inputs from the findings repository's clean package."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
import urllib.request


def ensure_abi(root, client='2008-06'):
    """Use published binary evidence, never candidate-derived expected layouts."""
    path = Path(root) / 'rebuild' / client / 'manifests/abi-evidence.json'
    if not path.exists():
        base = 'https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct-findings/main/' + client + '/'
        with urllib.request.urlopen(base + 'package.json', timeout=60) as response:
            expected = json.load(response)['files']['verification/manifests/abi-evidence.json']
        with urllib.request.urlopen(base + 'verification/manifests/abi-evidence.json', timeout=60) as response:
            content = response.read()
        if hashlib.sha256(content).hexdigest() != expected:
            raise ValueError('Published ABI manifest hash mismatch; nothing installed')
        data = json.loads(content)
    else:
        content = path.read_bytes()
        data = json.loads(content)
    if not isinstance(data, dict) or not data or any(not isinstance(v, dict) or v.get('confidence') != 'observed'
            or not isinstance(v.get('vtables'), list) for v in data.values()):
        raise ValueError('Invalid original-binary ABI evidence: ' + str(path))
    if not path.exists():
        path.parent.mkdir(parents=True, exist_ok=True)
        temporary = path.with_suffix('.download')
        temporary.write_bytes(content)
        temporary.replace(path)
    return path


def install(root, client='2008-06', package=None):
    root = Path(root)
    destination = root / 'rebuild' / client
    if (destination / 'modules/rbxgs-app.json').exists():
        ensure_abi(root, client)
        return destination
    if client != '2008-06':
        raise ValueError('No findings rebuild package configured for ' + client)
    package = Path(package) if package else root / 'local/findings' / client
    if not (package / 'config/rbxgs-app.json').exists():
        cache = root / 'local/rebuild-inputs'
        cache.parent.mkdir(parents=True, exist_ok=True)
        if not (cache / '.git').exists():
            subprocess.run(['git', 'clone', '--filter=blob:none', '--no-checkout', '--depth=1',
                            '--branch', 'main', 'https://github.com/colingsnyder2-ux/RoConstruct-findings.git',
                            str(cache)], check=True)
        subprocess.run(['git', '-C', str(cache), 'sparse-checkout', 'set', '--cone',
                        *[client + '/' + folder for folder in
                          ('config', 'patches', 'tests', 'scripts', 'src/glue', 'verification/manifests')]], check=True)
        subprocess.run(['git', '-C', str(cache), 'checkout', 'main'], check=True)
        package = cache / client
    copies = []
    for source, target in [('config', 'modules'), ('patches', 'patches'), ('tests', 'tests'),
                           ('src/glue', 'glue'), ('verification/manifests', 'manifests'), ('scripts', '')]:
        for path in (package / source).rglob('*'):
            if not path.is_file() or path.name == 'compile_test.py':
                continue
            copies.append((path, destination / target / path.relative_to(package / source)))
    if not any(target == destination / 'modules/rbxgs-app.json' for _, target in copies):
        raise ValueError('Findings package lacks rbxgs-app.json')
    for source, target in copies:
        if target.exists() and target.read_bytes() != source.read_bytes():
            raise ValueError('Preserving existing rebuild file; resolve before installing: ' + str(target))
    for source, target in copies:
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
    print('Rebuild inputs installed from findings:', destination)
    ensure_abi(root, client)
    return destination


def prepare(client='2008-06', log=print):
    """Complete cold contributor inputs before the expensive pinned native proof."""
    from roc import analyze, clients, libs, rebuild, setup
    root = rebuild.ROOT
    log('Native setup: checking published ABI manifest')
    install(root, client)
    entry = clients.load()[client]
    if clients.status(client, entry) != 'ok' and not clients.ensure(client):
        raise ValueError('Verified client required before native preflight: ' + client)
    work = root / 'work' / client
    if not (work / 'functions.jsonl').exists():
        log('Native setup: generating client analysis')
        analyze.analyze(client, clients.exe_path(client, entry))
    if not (work / 'vtables.json').exists():
        log('Native setup: generating RTTI/vtable index')
        analyze.vtable_report(client, top=0, log=log)
    if not json.loads((work / 'vtables.json').read_text()):
        raise ValueError('Empty RTTI/vtable index; rerun roc vtables ' + client)
    modules, seen = [], set()
    def visit(name):
        if name in seen:
            return
        seen.add(name)
        spec = rebuild.load_module(client, name)
        for dependency in spec.get('depends', []):
            visit(dependency)
        modules.append((name, spec))
    visit('rbxgs-app')
    required = {rebuild.BUILD}
    for _, spec in modules:
        for layer in spec.get('layers', []):
            required.add(layer.get('cl', rebuild.BUILD))
            if layer.get('fallback_cl'):
                required.add(layer['fallback_cl'])
    missing = required - set(setup.compilers())
    if missing:
        log('Native setup: installing declared compiler profiles ' + ', '.join(map(str, sorted(missing))))
        setup.install_compilers(only=sorted(missing), assume_yes=True)
    if required - set(setup.compilers()):
        raise ValueError('Declared dependency compiler profiles remain missing')
    if not libs.winsdk_include():
        setup.install_compilers(only=[30729], assume_yes=True)
        rebuild.sdk_roots.cache_clear()
    if not rebuild.toolchain()['atlmfc_include']:
        libs.bundle_fetch(['mfc-9.0-rtm'])
    for build in sorted(required):
        profile = rebuild.toolchain(build)
        if any(not profile.get(k) for k in ('cl', 'link', 'lib', 'vc_include', 'sdk_include', 'sdk_lib')):
            raise ValueError('Incomplete historical compiler profile %s; repair installation before preflight' % build)
    for _, spec in modules:
        for layer in spec.get('layers', []):
            for key in ('recipe', 'includes_from_recipe', 'defines_from_recipe'):
                if layer.get(key):
                    recipe = layer[key]
                    if not libs._case_path(libs.LIBS / libs.RECIPES[recipe]['src']).is_dir():
                        log('Native setup: fetching source recipe ' + recipe)
                        libs.fetch(recipe)
    for name, spec in modules[:-1]:
        out = root / 'rebuild' / client / 'out' / spec['name']
        report = json.loads((out / 'report.json').read_text()) if (out / 'report.json').exists() else {}
        if not (out / 'linked/linked.lib').exists() or not report.get('linked') or \
                spec.get('test') and report.get('test_exit') != 0:
            log('Native setup: building declared dependency ' + name)
            result = rebuild.build_module(client, name)
            if not result.get('linked') or spec.get('test') and result.get('test_exit') != 0:
                raise ValueError('Dependency build/smoke failed: ' + name)
    log('Native setup: ABI, RTTI, compiler profiles and declared libraries ready')
