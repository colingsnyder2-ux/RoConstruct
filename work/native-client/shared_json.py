"""Shared JSON files written by several lanes at once (class-identity-bindings.json, class-lane-new-sources.json).
update(path, fn): lock, read, fn(document) -> document, write to a temp file, atomic replace.  A plain
read_text()/write_text() pair lets another lane read a half-written (empty) file (thunk lane crash, 2026-11-17).
read(path): retries while a writer is replacing the file."""
import json
import os
import time
from pathlib import Path


def read(path, default=None):
    path = Path(path)
    for _ in range(40):
        try:
            return json.loads(path.read_text(encoding='utf-8'))
        except FileNotFoundError:
            return default
        except (ValueError, PermissionError, OSError):
            time.sleep(0.25)
    return json.loads(path.read_text(encoding='utf-8'))


def update(path, fn, default=None):
    path = Path(path)
    lock = path.with_suffix(path.suffix + '.lock')
    started = time.time()
    while True:
        try:
            handle = os.open(str(lock), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
            break
        except FileExistsError:
            if time.time() - started > 60:               # a crashed writer left its lock: take over
                try:
                    lock.unlink()
                except OSError:
                    pass
                started = time.time()
            time.sleep(0.1)
    try:
        doc = fn(read(path, default))
        tmp = path.with_suffix(path.suffix + '.tmp%d' % os.getpid())
        tmp.write_text(json.dumps(doc, indent=1), encoding='utf-8')
        for _ in range(40):
            try:
                os.replace(tmp, path)
                break
            except PermissionError:                      # a reader has the file open for a moment
                time.sleep(0.25)
        return doc
    finally:
        os.close(handle)
        try:
            lock.unlink()
        except OSError:
            pass


if __name__ == '__main__':                               # self-check
    import tempfile
    from concurrent.futures import ThreadPoolExecutor
    target = Path(tempfile.mkdtemp()) / 'x.json'
    with ThreadPoolExecutor(8) as pool:
        list(pool.map(lambda i: update(target, lambda d: (d or []) + [i], []), range(200)))
    assert sorted(read(target)) == list(range(200)), 'lost updates'
    print('shared_json ok')
