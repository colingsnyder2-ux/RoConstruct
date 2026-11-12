"""Exclusive handles for safe canonical file mutation."""
from contextlib import contextmanager
import os
from pathlib import Path


@contextmanager
def exclusive_existing(path):
    """Open existing file for read/write while excluding competing writers/deletes.

    Windows sharing is enforced by the OS handle. POSIX uses nonblocking flock,
    which coordinates only with other writers that honor advisory locks.
    """
    path = Path(path)
    if os.name == 'nt':
        import ctypes
        import msvcrt
        from ctypes import wintypes

        kernel32 = ctypes.WinDLL('kernel32', use_last_error=True)
        create_file = kernel32.CreateFileW
        create_file.argtypes = (wintypes.LPCWSTR, wintypes.DWORD, wintypes.DWORD,
                                wintypes.LPVOID, wintypes.DWORD, wintypes.DWORD,
                                wintypes.HANDLE)
        create_file.restype = wintypes.HANDLE
        handle = create_file(str(path), 0x80000000 | 0x40000000, 0x00000001,
                             None, 3, 0x00000080, None)
        invalid = ctypes.c_void_p(-1).value
        if handle == invalid:
            raise ctypes.WinError(ctypes.get_last_error())
        try:
            fd = msvcrt.open_osfhandle(handle, os.O_RDWR | getattr(os, 'O_BINARY', 0))
        except Exception:
            kernel32.CloseHandle.argtypes = (wintypes.HANDLE,)
            kernel32.CloseHandle.restype = wintypes.BOOL
            kernel32.CloseHandle(handle)
            raise
        try:
            stream = os.fdopen(fd, 'r+b', buffering=0)
        except Exception:
            os.close(fd)
            raise
        with stream:
            yield stream
    else:
        import fcntl

        with path.open('r+b', buffering=0) as stream:
            fcntl.flock(stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
            try:
                yield stream
            finally:
                fcntl.flock(stream.fileno(), fcntl.LOCK_UN)
