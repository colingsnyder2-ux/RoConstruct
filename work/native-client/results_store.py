"""Row-level writes to placeholder-lane/results.json shared by every lane process.  Each writer used to dump its whole
in-memory snapshot, so concurrent lanes (regate, failures, polish, promote merges) clobbered each other's rows.
save(updates, deletes) takes an exclusive lock file, re-reads the file, applies only the given rows and replaces it
atomically (temp file + os.replace), so a reader never sees half-written JSON."""
import json
import os
import time
from pathlib import Path

PATH = Path(__file__).resolve().parent / 'placeholder-lane/results.json'
LOCK = PATH.with_suffix('.lock')


def _lock():
    for _ in range(6000):                                   # up to ~10 minutes
        try:
            return os.open(str(LOCK), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
        except FileExistsError:
            try:
                if time.time() - LOCK.stat().st_mtime > 120:  # writer died mid-save: a save takes well under a second
                    LOCK.unlink()
                    continue
            except OSError:
                pass
            time.sleep(0.1)
    raise TimeoutError('results.json lock held too long: %s' % LOCK)


def load():
    for _ in range(50):
        try:
            return json.loads(PATH.read_text())
        except ValueError:                                  # legacy non-atomic writer mid-write
            time.sleep(0.1)
    return json.loads(PATH.read_text())


def save(updates=None, deletes=()):
    """Apply {addr: row} UPDATES and remove DELETES on disk; returns the merged dict."""
    fd = _lock()
    try:
        current = load() if PATH.is_file() else {}
        current.update(updates or {})
        for addr in deletes:
            current.pop(addr, None)
        tmp = PATH.with_suffix('.tmp%d' % os.getpid())
        tmp.write_text(json.dumps(current, indent=1))
        os.replace(tmp, PATH)
        return current
    finally:
        os.close(fd)
        LOCK.unlink(missing_ok=True)
