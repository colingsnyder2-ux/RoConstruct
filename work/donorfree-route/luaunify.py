"""Two Lua runtimes in one link: the original's Lua has C names (_lua_load, _luaX_tokens ...; built as C++ with
lua_exception, extern "C" API) and the converted objects call those; native drafts included the Lua headers without
extern "C", so they reference C++-mangled names (?lua_newstate@@YA...) that a second, C++-compiled Lua copy supplies.
Both work on the same lua_State, but cross-calls mix their error machinery: a trivial -script failed to parse ("attempt
to call a nil value"). mapping() -> {C++ name: C name} for every C++-mangled Lua function whose C twin our link defines
(grow-only, auto/luaunify.json); quicktest strips the C++ definitions from the objects that carry them
(rebuild.strip_symbols) and aliases the C++ names to the C ones, so the whole client runs ONE Lua."""
import json, re
from pathlib import Path
H = Path(__file__).parent
CPP = re.compile(r'^\?(lua[A-Z_]?\w*|luaL_\w+|luaopen_\w+|f_parser|luai_\w+)@@')


def mapping():
    defs = set()
    for l in open(H / 'linkexp/qt.map', errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and 'stubs' not in p[-1]:
            defs.add(p[1])
    out = {}
    for n in defs:
        m = CPP.match(n)
        if m and '_' + m.group(1) in defs:
            out[n] = '_' + m.group(1)
    sf = H / 'auto/luaunify.json'
    try:
        for k, v in json.load(open(sf)).items():
            out.setdefault(k, v)
    except (OSError, ValueError):
        pass
    json.dump(out, open(sf, 'w'), indent=0)
    return out


if __name__ == '__main__':
    m = mapping()
    print('luaunify: C++-mangled Lua functions with a C twin: %d (e.g. %s)' % (len(m), list(m.items())[:2]))
