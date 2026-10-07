"""Mass matching: compile a whole source file once, then compare every function it
produces against every open function of the same size in a client exe.

Used for library code (zlib, Lua, ...), STL instantiations, and copying matches to
identical functions. Only byte-identical results count, with a strict rule: every
place the exe has a relocated address must also be a relocation in the compiled
object, so a constant can never pass for an address. Matches are saved as normal
src/<client>/<addr>.cpp files, so `roc check` and the server verify them unchanged.
"""
import json
from bisect import bisect_left
from pathlib import Path

from roc import match

ROOT = Path(__file__).resolve().parent.parent


def open_index(client):
    """{size: [addr, ...]} of real-code functions not yet matched."""
    path = ROOT / "work" / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    index = {}
    for r in match._functions(client).values():
        if r["kind"] == "code" and scores.get(r["addr"], 0) < 100:
            index.setdefault(r["size"], []).append(r["addr"])
    return index


class Target:
    """One client's exe bytes and relocations, ready for fast comparisons."""

    def __init__(self, client):
        self.client = client
        self.base, self.image = match._image(client)
        self.relocs = sorted(match._base_relocs(client))
        self.index = open_index(client)

    def exe_relocs(self, va, size):
        lo, hi = bisect_left(self.relocs, va), bisect_left(self.relocs, va + size)
        return {r - va for r in self.relocs[lo:hi]}

    def same(self, addr, code, relocs):
        """Exe function at addr equals code (masked), with exe relocs a subset of the object's."""
        va = int(addr, 16)
        exe_rel = self.exe_relocs(va, len(code))
        if not exe_rel <= set(relocs):
            return None
        exe = bytes(self.image[va - self.base:va - self.base + len(code)])
        return exe if match.masked(exe, relocs) == match.masked(code, relocs) else None

    def match_obj(self, obj, source, data_check=True):
        """{addr: (source, symbol, data spans)} for every object function found in the exe."""
        found = {}
        for name, code, relocs in match.coff_functions(obj):
            if len(code) < 6:  # too short to say anything (a lone ret matches everywhere)
                continue
            for addr in self.index.get(len(code), []):
                if addr in found:
                    continue
                exe = self.same(addr, code, relocs)
                if exe is None:
                    continue
                spans, bad = (match.data_check(self.client, addr, exe, match.coff_data_refs(obj, name))
                              if data_check else ([], []))
                if not bad:
                    found[addr] = (source, name, spans)
        for addr in found:  # matched functions leave the pool
            self.index[len(match.target(self.client, addr)[0])].remove(addr)
        return found


def save(client, found, note):
    """Write matches into src/<client>/ (existing files are kept). Returns how many were new."""
    new = 0
    for addr, (source, symbol, spans) in found.items():
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        match.save_score(client, addr, 100)
        match.save_data(client, addr, spans)
        if path.exists():
            continue
        header = match.template(client, addr).split("\n\n")[0]
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("%s\n// %s (function %s)\n\n%s" % (header, note, symbol, source))
        new += 1
    return new
