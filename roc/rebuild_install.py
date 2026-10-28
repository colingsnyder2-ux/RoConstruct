"""Restore legacy ROC build inputs from the findings repository's clean package."""
from pathlib import Path
import shutil
import subprocess


def install(root, client='2008-06', package=None):
    root = Path(root)
    destination = root / 'rebuild' / client
    if (destination / 'modules/rbxgs-app.json').exists():
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
    return destination
