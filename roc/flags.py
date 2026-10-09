"""Find compiler flags. Greedy tune plus exact exhaustive sweep.

Greedy: start from the current flags, try each alternative per option group,
keep any change that raises the total score over src/<client>/*.cpp.
ponytail: greedy can miss flag interactions; fine while groups are independent.
"""
from pathlib import Path
from itertools import product

from roc import clients, match

ROOT = Path(__file__).resolve().parent.parent
GROUPS = [
    ["/O2", "/O1", "/Ox"],
    ["", "/Oy", "/Oy-"],       # frame pointer omission
    ["/GS-", "/GS"],           # buffer security checks
    ["/EHsc", "/EHa", ""],     # exception model
    ["/MD", "/MT"],            # CRT import vs static calls
    ["", "/Ob0", "/Ob1", "/Ob2"], # inlining
    ["", "/GR-"],              # RTTI
    ["", "/Zc:wchar_t-"],
    ["", "/Oi", "/Oi-"],       # intrinsic expansion
    ["", "/fp:precise", "/fp:fast"],
    ["", "/Gd", "/Gr", "/Gz"], # default calling convention
]


def candidates(current):
    """Bounded Cartesian flag search; preserve non-group flags."""
    fixed = [o for o in current if not any(o in g for g in GROUPS)]
    choices = []
    for group in GROUPS:
        choices.append(group if any(o in current for o in group if o) else group[:])
    seen = set()
    for pick in product(*choices):
        value = " ".join(fixed + [o for o in pick if o])
        if value not in seen:
            seen.add(value)
            yield value


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


def sweep(client, log=print, limit=None):
    """Try flag interactions. Stop immediately on one exact source match."""
    sources = sorted((ROOT / "src" / client).glob("*.cpp"),
                     key=lambda p: (p.stat().st_size, p.name))
    if limit:
        sources = sources[:limit]
    if not sources:
        raise SystemExit("No sources in src/%s." % client)
    current = (clients.load()[client].get("flags") or match.DEFAULT_FLAGS).split()
    best, best_flags = -1, None
    for trial in candidates(current):
        score = total(client, sources, trial)
        log("try    %-48s %d / %d" % (trial, score, 100 * len(sources)))
        if score > best:
            best, best_flags = score, trial
        if score == 100 * len(sources):
            break
    reg = clients.load()
    reg[client]["flags"] = best_flags
    clients.save(reg)
    log("best   %-48s %d / %d%s (saved)" %
        (best_flags, best, 100 * len(sources), " sample" if limit else ""))
    return best_flags, best
