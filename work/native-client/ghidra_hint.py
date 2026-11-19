"""Ghidra decompile of the 2008-06 executable itself (C:/Users/colin/RBXBanland/work/re/rbx2008m.db, functions
table, program RobloxApp_client.exe; the owner's own analysis): pseudo-C for one address as a model hint.  Behaviour
hint only - parameter and field names are Ghidra's (param_1, *(int *)(this + 0x10)), never to be copied as offsets."""
import os
import sqlite3
import threading

DB = os.environ.get('ROC_GHIDRA_DB') or 'C:/Users/colin/RBXBanland/work/re/rbx2008m.db'
_local = threading.local()


def _conn():
    if not os.path.isfile(DB):
        return None
    c = getattr(_local, 'c', None)
    if c is None:
        c = _local.c = sqlite3.connect('file:%s?mode=ro' % DB.replace(os.sep, '/'), uri=True, check_same_thread=False)
    return c


def hint(addr, limit=2500):
    c = _conn()
    if c is None:
        return ''
    row = c.execute("select name, size, decompiled from functions where program='RobloxApp_client.exe' and addr=?",
                    (addr.lower().zfill(8),)).fetchone()
    if not row or not row[2]:
        return ''
    text = row[2].replace('\r\n', '\n').strip()
    return ("--- Ghidra decompile of THIS 2008 function (%s, %s bytes; behaviour hint, names and offsets are Ghidra's) ---\n%s"
            % (row[0], row[1], text[:limit] + ('\n... (truncated)' if len(text) > limit else '')))


if __name__ == '__main__':
    import sys
    print(hint(sys.argv[1]))
