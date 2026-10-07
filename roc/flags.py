"""Find the compiler flags a client was built with.

Greedy: start from the current flags, try each alternative per option group,
keep any change that raises the total score over src/<client>/*.cpp.
ponytail: greedy can miss flag interactions; fine while groups are independent.
"""
from pathlib import Path

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
GROUPS = [
    ["/O2", "/O1", "/Ox"],
    ["", "/Oy-"],              # frame pointer omission (O1/O2 imply /Oy)
    ["/GS-", "/GS"],           # buffer security checks
    ["/EHsc", "/EHa", ""],     # exception model
    ["/MD", "/MT"],            # CRT import vs static calls
    ["", "/Ob1", "/Ob0"],      # inlining
    ["", "/GR-"],              # RTTI
    ["", "/Zc:wchar_t-"],
]


def total(client, sources, flags):
    s = 0
    for src in sources:
        try:
            s += match.check(client, src.stem, src, flags)[0]
        except match.CompileError:
            pass
    return s


def tune(client, log=print):
    sources = sorted((ROOT / "src" / client).glob("*.cpp"))
    if not sources:
        raise SystemExit("No sources in src/%s yet. Claim and write a few small functions first." % client)
    entry = clients.load()[client]
    current = (entry.get("flags") or match.DEFAULT_FLAGS).split()
    # Normalise to one choice per group.
    pick = [next((o for o in g if o and o in current), g[0]) for g in GROUPS]
    flags = lambda p: " ".join(o for o in p if o)
    best = total(client, sources, flags(pick))
    log("start  %-40s %d / %d" % (flags(pick), best, 100 * len(sources)))
    for gi, group in enumerate(GROUPS):
        for option in group:
            if option == pick[gi]:
                continue
            trial = pick[:gi] + [option] + pick[gi + 1:]
            s = total(client, sources, flags(trial))
            log("try    %-40s %d" % (flags(trial), s))
            if s > best:
                best, pick = s, trial
    reg = clients.load()
    reg[client]["flags"] = flags(pick)
    clients.save(reg)
    log("best   %-40s %d / %d  (saved to clients.json)" % (flags(pick), best, 100 * len(sources)))
    return flags(pick), best
