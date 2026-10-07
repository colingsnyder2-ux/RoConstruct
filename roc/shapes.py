"""Count the assembly shapes of unmatched functions, so pattern templates can be chosen
from evidence instead of guessed.

A "shape" is the function's instruction sequence with every absolute address and
immediate normalised away. Two functions with the same shape are the same code with
different constants, so one template can match both. Counting shapes across all clients
shows which templates are worth writing, and re-running after a batch shows what is
left.

    roc shapes <client|all>        top shapes among unmatched functions
    roc shapes <client|all> --size 64 --show 3
"""
import argparse
import re
from collections import Counter, defaultdict

from roc import clients, match

HEX = re.compile(r"^0x[0-9a-f]+$")
NUM = re.compile(r"^\d+$")
MEMOFF = re.compile(r"(\+ 0x[0-9a-f]+|\+ \d+)")


def norm_line(line):
    """One asm line with addresses and immediates generalised."""
    text = line.strip()
    if not text:
        return ""
    head, _, rest = text.partition(" ")
    if not rest.strip():
        return head
    parts = []
    for token in rest.split(","):
        token = token.strip()
        if HEX.match(token) or NUM.match(token):
            parts.append("#")
        else:
            parts.append(MEMOFF.sub("+ #", token))
    return "%s %s" % (head, ", ".join(parts))


def shape_from_lines(lines, drop_ret_operand=True):
    """Shape of already-disassembled lines. Split out from shape_of so the
    normalisation can be reasoned about (and tested) without an exe or a compiler."""
    kept = []
    for line in lines:
        text = line.strip()
        head, _, rest = text.partition(" ")
        # `ret 8` and `ret` are the same shape: the cleanup is implied by the arguments,
        # and a shape that distinguished them would split a family in two.
        kept.append(head if head == "ret" else norm_line(text))
    # collapse runs of identical lines: a constructor's chain of zero-inits repeats
    out = []
    for line in kept:
        if not out or out[-1] != line:
            out.append(line)
    return tuple(out)


def shape_of(code, relocs, drop_ret_operand=True):
    """Normalised shape of a function's assembly."""
    return shape_from_lines(match.asm_lines(code, relocs), drop_ret_operand)


def collect(client, max_size=None, kind="code"):
    """{shape: [addr, ...]} for unmatched functions of one client."""
    scores = match._scores(client) if hasattr(match, "_scores") else None
    import json
    from pathlib import Path
    path = Path("work") / client / "scores.json"
    scores = json.loads(path.read_text()) if path.exists() else {}
    out = defaultdict(list)
    for addr, row in match._functions(client).items():
        if row.get("kind", "code") != kind or scores.get(addr, 0) >= 100:
            continue
        if max_size and row["size"] > max_size:
            continue
        code, relocs, _ = match.target(client, addr)
        out[shape_of(code, relocs)].append((addr, row["size"], row["unit"]))
    return out


def report(clients_wanted=(), max_size=48, show=3, top=25):
    reg = clients.load()
    names = sorted(reg) if "all" in clients_wanted or not clients_wanted else list(clients_wanted)
    total = Counter()
    where = defaultdict(set)
    examples = {}
    per_client = {}
    for client in names:
        shapes = collect(client, max_size=max_size)
        per_client[client] = {s: len(v) for s, v in shapes.items()}
        for shape, addrs in shapes.items():
            total[shape] += len(addrs)
            where[shape].add(client)
            if shape not in examples:
                examples[shape] = (client, addrs[0])
    for client in names:
        n = sum(per_client[client].values())
        print("%-8s %d unmatched function(s) up to %d bytes, %d distinct shape(s)"
              % (client, n, max_size, len(per_client[client])))
    print()
    print("Top shapes overall (a template for one of these matches every copy of it):")
    for rank, (shape, count) in enumerate(total.most_common(top), 1):
        covered = sum(per_client[c].get(shape, 0) for c in where[shape])
        client, (addr, size, unit) = examples[shape]
        print("%3d. %5d function(s) in %d client(s)  %s" % (rank, count, len(where[shape]),
                                                            ", ".join(sorted(where[shape]))))
        for line in shape[:show]:
            print("       %s" % line)
        if len(shape) > show:
            print("       ... (%d more instructions, %d bytes in %s %s)"
                  % (len(shape) - show, size, client, addr))
        print()
    print("A single template for the top shape would match %d functions." % total.most_common(1)[0][1]
          if total else "no unmatched small functions")
    return total, where, per_client


def main(argv=None):
    ap = argparse.ArgumentParser(prog="roc shapes", description=__doc__)
    ap.add_argument("name", nargs="?", default="all")
    ap.add_argument("--size", type=int, default=48, help="only functions up to this many bytes")
    ap.add_argument("--top", type=int, default=25)
    ap.add_argument("--show", type=int, default=3, help="instructions of each shape to print")
    a = ap.parse_args(argv)
    report([a.name], max_size=a.size, show=a.show, top=a.top)


if __name__ == "__main__":
    main()
