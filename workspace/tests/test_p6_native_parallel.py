"""Verify native Doc parallel jobs own outputs, profiles and cache entries."""
import ast
from concurrent.futures import ThreadPoolExecutor
import hashlib
from pathlib import Path
import re
from types import SimpleNamespace
import threading
import time


def test_parallel_doc_jobs_isolate_outputs_and_cache(tmp_path):
    builder = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/build_client.py'
    tree = ast.parse(builder.read_text())
    function = next(node for node in ast.walk(tree)
                    if isinstance(node, ast.FunctionDef) and node.name == 'compile_doc_source')
    barrier = threading.Barrier(3)
    writes, cached = {}, {}
    lock = threading.Lock()

    def run(tc, tool, flags, output):
        obj = next(flag[3:] for flag in flags if flag.startswith('/Fo'))
        barrier.wait(timeout=10)
        with lock:
            assert obj not in writes
            writes[obj] = flags
        return (2 if obj == 'Failed.obj' else 0), obj

    def store(name, key, obj, include_log=None, started_ns=None):
        with lock:
            assert name not in cached
            cached[name] = obj

    scope = dict(doc_flags=['/O2'], re=re, ROOT=tmp_path, data_defines='WIN32',
                 mfc=tmp_path / 'mfc', xtp=tmp_path / 'xtp', includes=[],
                 cache_key=lambda source, flags: (str(source), tuple(flags)),
                 restore_cached=lambda *args: False, store_cached=store,
                 hashlib=hashlib, time=time, NATIVE_DOC_CACHE=False, tc={}, rebuild=SimpleNamespace(run=run), out=tmp_path)
    exec(compile(ast.Module(body=[function], type_ignores=[]), str(builder), 'exec'), scope)
    jobs = []
    for i, obj in enumerate(['NativeDocExtra00.obj', 'NativeFileSystemFull.obj', 'Failed.obj']):
        source = tmp_path / ('source%d.cpp' % i)
        source.write_text('// native-flags: /O2 /I{headers}/profile\n' if i == 0 else '// source\n')
        jobs.append((obj, source))
    with ThreadPoolExecutor(max_workers=3) as pool:
        results = list(pool.map(scope['compile_doc_source'], jobs))
    assert [code for code, _ in results] == [0, 0, 2]
    assert len(writes) == 3 and len(cached) == 2
    assert 'Failed.obj' not in cached.values()
    assert any(name.startswith('NativeDocExtra00.obj-') for name in cached)
    assert '/DNATIVE_FILE_SYSTEM_APPDATA_ONLY' not in writes['NativeFileSystemFull.obj']
    assert tmp_path / 'rebuild/2008-06/native-headers/profile' in [
        Path(flag[2:]) for flag in writes['NativeDocExtra00.obj'] if flag.startswith('/I')]
