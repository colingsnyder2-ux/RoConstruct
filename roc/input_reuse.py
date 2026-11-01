"""Attach missing installed inputs from configured caches and verified tool/client locations."""
import json
import os
from pathlib import Path


def link_directory(source, target):
    source, target = Path(source).resolve(), Path(target)
    target.parent.mkdir(parents=True,exist_ok=True)
    if os.name == 'nt':
        import _winapi
        _winapi.CreateJunction(str(source),str(target))
    else:
        target.symlink_to(source,target_is_directory=True)


def ensure_link(source, target):
    source, target = Path(source), Path(target)
    if target.exists():
        return False
    junction = target.is_junction() if os.name == 'nt' else False
    if junction:
        os.rmdir(target)  # remove only the broken junction, never its target
    elif target.is_symlink():
        target.unlink()
    link_directory(source,target)
    return True


def roots(tools, verified_paths=()):
    tools = Path(tools)
    config = tools.parent/'local/config/roconstruct-inputs.json'
    configured = json.loads(config.read_text(encoding='utf-8')) if config.exists() else {}
    if not isinstance(configured,dict):
        raise ValueError('Input cache config must be a JSON object: '+str(config))
    explicit = configured.get('tools_roots',[])
    if not isinstance(explicit,list) or any(not isinstance(p,str) for p in explicit):
        raise ValueError('tools_roots must be a list of directory paths: '+str(config))
    explicit = [*explicit,*[p for p in os.environ.get('ROC_REUSE_TOOLS','').split(os.pathsep) if p]]
    candidates = []
    for item in explicit:
        path = Path(item).expanduser().resolve()
        if not path.is_dir():
            raise ValueError('Configured input cache is missing: '+str(path))
        candidates.append(path)
    for item in verified_paths:
        path = Path(item).resolve()
        if not path.is_file():
            continue
        for parent in path.parents:
            if parent.name.lower() == 'tools':
                candidates.append(parent)
                break
            if parent.name.lower() == 'clients':
                candidates.append(parent.parent/'tools')
                break
    seen = set()
    for path in candidates:
        identity = os.path.normcase(str(path.resolve()))
        if identity not in seen and path.is_dir():
            seen.add(identity)
            yield path


def attach(tools, verified_paths=(), log=print):
    """Preserve every existing file; reuse only missing directories. No network or copies."""
    tools = Path(tools)
    changed = []
    def fill(source, target, depth=2):
        if not source.is_dir():
            return
        if source.resolve()==target.resolve():
            return
        if not target.exists():
            if ensure_link(source,target): changed.append(str(target))
        elif depth and target.is_dir():
            for child in source.iterdir():
                if child.is_dir(): fill(child,target/child.name,depth-1)
    for cache in roots(tools,verified_paths):
        source, destination = cache.resolve(), tools.resolve()
        if source == destination or source.is_relative_to(destination) or destination.is_relative_to(source):
            continue
        fill(cache/'libs',tools/'libs')
        for name in ('rbxgs','openrbx','roblox2016'):
            fill(cache/name,tools/name)
        for package in cache.iterdir():
            if package.is_dir() and package.name.lower().startswith(('vc20','vcforpython','winsdk','sdk','external-sdk')):
                fill(package,tools/package.name)
    if changed:
        log('Reused %d cached input directories; existing files preserved' % len(changed))
    return changed
