"""Shared paths and deterministic JSON for the source-layout tools."""
import hashlib
import json
import os
import re
from functools import lru_cache
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
NC = HERE.parent
NATIVE = [ROOT / 'rebuild/2008-06' / p for p in ('native-classes', 'native-headers')]


def read(path):
    return Path(path).read_text(encoding='utf-8', errors='replace')


def load(path):
    return json.loads(read(path))


def save(name, value):
    path = (HERE / name).resolve()
    path.relative_to(HERE)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n', encoding='utf-8')


def relative(path):
    path = Path(path)
    return (path if path.is_absolute() else ROOT / path).relative_to(ROOT).as_posix()


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def stage_inputs(manifest, stage):
    inputs = manifest.get('inputs', {}).get(stage)
    if not isinstance(inputs, dict) or not inputs:
        raise ValueError('missing frozen inputs for ' + stage)
    return inputs


def family_gate(name):
    if not isinstance(name, str) or not re.fullmatch(r'[A-Za-z0-9][A-Za-z0-9_.-]*', name):
        raise ValueError('family must be a simple name')
    return HERE / 'gates' / name


@lru_cache(maxsize=1)
def sources():
    return sorted(Path(folder) / filename for root in NATIVE
                  for folder, dirs, files in os.walk(root) for filename in files
                  if Path(filename).suffix.lower() in ('.h', '.hpp', '.cpp', '.c', '.inl'))


def inside(path):
    path = (ROOT / path).resolve()
    path.relative_to(ROOT)
    return path
