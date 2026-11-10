"""Exercise native-doc cache functions without running the client builder."""
import ast
import hashlib
import json
import os
from pathlib import Path
import re
import shutil


def test_native_doc_cache_roundtrip_and_header_invalidation(tmp_path):
    builder = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/build_client.py'
    tree = ast.parse(builder.read_text())
    names = {'native_deps', 'cache_key', 'cache_paths', 'restore_cached', 'store_cached'}
    functions = ast.Module(body=[node for node in tree.body
                                if isinstance(node, ast.FunctionDef) and node.name in names],
                           type_ignores=[])
    headers = tmp_path / 'headers'
    headers.mkdir()
    header = headers / 'Class.h'
    header.write_text('class Class {};\n')
    source = tmp_path / 'Class.cpp'
    source.write_text('#include "Class.h"\n')
    output = tmp_path / 'out'
    output.mkdir()
    cache = tmp_path / 'cache'
    scope = dict(Path=Path, hashlib=hashlib, json=json, re=re, shutil=shutil, os=os,
                 ROOT=tmp_path, header_root=headers, cache_dir=cache, out=output,
                 NATIVE_DOC=True, NATIVE_DOC_CACHE=True)
    exec(compile(functions, str(builder), 'exec'), scope)
    key = scope['cache_key'](source, ['/O2'])
    assert key == json.loads(json.dumps(key))
    artifact = output / 'Class.obj'
    artifact.write_bytes(b'compiled object')
    scope['store_cached']('Class.obj', key)
    artifact.unlink()
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, ['/O2']))
    assert artifact.read_bytes() == b'compiled object'
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, ['/Od']))
    stamp = header.stat().st_mtime_ns + 1_000_000_000
    header.write_text('class Class { int value; };\n')
    os.utime(header, ns=(stamp, stamp))
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, ['/O2']))

    profile = headers / 'std-boundary'
    profile.mkdir()
    xstring = profile / 'xstring'
    xstring.write_text('original boundary\n')
    flags = ['/O2', '/I' + str(profile)]
    profile_key = scope['cache_key'](source, flags)
    assert profile_key == json.loads(json.dumps(profile_key))
    scope['store_cached']('Class.obj', profile_key)
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    stamp = xstring.stat().st_mtime_ns + 1_000_000_000
    xstring.write_text('changed boundary\n')
    os.utime(xstring, ns=(stamp, stamp))
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))

    # Editing content must miss even when a tool preserves its timestamp.
    prior_key = scope['cache_key'](source, flags)
    artifact.write_bytes(b'edited profile object')
    scope['store_cached']('Class.obj', prior_key)
    old_stamp = xstring.stat().st_mtime_ns
    xstring.write_text('third boundary\n')
    os.utime(xstring, ns=(old_stamp, old_stamp))
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))

    # Returning to earlier content reuses that exact variant, not the last build.
    xstring.write_text('original boundary\n')
    assert scope['cache_key'](source, flags) == profile_key
    artifact.unlink()
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    assert artifact.read_bytes() == b'compiled object'
    xstring.write_text('changed boundary\n')
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    assert artifact.read_bytes() == b'edited profile object'

    # Source edits invalidate independently; timestamp-only touches do not.
    saved = source.read_bytes()
    source.write_bytes(saved + b'// source changed\n')
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    source.write_bytes(saved)
    os.utime(source, None)
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))

    # Quoted native headers also invalidate when timestamps are preserved.
    saved_header = header.read_bytes()
    old_stamp = header.stat().st_mtime_ns
    header.write_bytes(saved_header + b'// layout changed\n')
    os.utime(header, ns=(old_stamp, old_stamp))
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    header.write_bytes(saved_header)
    assert scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))

    # Interrupted metadata writes never become valid cache hits.
    _, receipt = scope['cache_paths']('Class.obj', scope['cache_key'](source, flags))
    receipt.write_text('{partial')
    assert not scope['restore_cached']('Class.obj', scope['cache_key'](source, flags))
    assert not list(cache.rglob('*.tmp-*'))
