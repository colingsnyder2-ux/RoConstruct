"""Recover source/mined function counts from archived Git website snapshots."""
import json
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def backfill():
    def git(*args):
        return subprocess.check_output(["git", *args], cwd=ROOT).decode().splitlines()

    refs = [(ref, "docs/") for ref in git("log", "--all", "--format=%H", "--", "docs/progress.json")]
    refs += [(ref, "") for ref in git("reflog", "show", "--format=%H", "origin/gh-pages")]
    history_file = ROOT / "docs/history.json"
    history = json.loads(history_file.read_text())
    fields = ("functions", "matched", "partial", "bytes", "matched_bytes")

    def key(name, stats):
        return (name, *(stats.get(field, 0) for field in fields), stats.get("source_bytes", 0))

    needed = {}
    for snap in history:
        for name, stats in snap["clients"].items():
            if "source_matched" not in stats:
                needed.setdefault(key(name, stats), []).append(stats)

    # Keep one cat-file process: spawning Git per snapshot is slow on Windows.
    with subprocess.Popen(["git", "cat-file", "--batch"], cwd=ROOT,
                          stdin=subprocess.PIPE, stdout=subprocess.PIPE) as reader:
        def read(path):
            reader.stdin.write((path + "\n").encode())
            reader.stdin.flush()
            header = reader.stdout.readline().split()
            if header[-1] == b"missing":
                return None, None
            body = reader.stdout.read(int(header[-1]))
            assert reader.stdout.read(1) == b"\n"
            return header[0], body

        candidates = {}
        for ref, prefix in refs:
            _, body = read(ref + ":" + prefix + "progress.json")
            if body is None:
                continue
            for stats in json.loads(body).get("clients", []):
                identity = key(stats["name"], stats)
                if identity in needed:
                    candidates.setdefault(identity, []).append((ref, prefix))

        recovered, cache = 0, {}
        for identity, rows in needed.items():
            for ref, prefix in candidates.get(identity, []):
                blob, body = read(ref + ":" + prefix + "data/" + identity[0] + ".json")
                if blob is None:
                    continue
                if blob not in cache:
                    funcs = json.loads(body)["funcs"]
                    exact = [f for f in funcs if f[2] == 100]
                    source = [f for f in exact if len(f) > 5 and f[5]]
                    cache[blob] = (len(funcs), len(exact), sum(f[1] for f in source), len(source))
                functions, matched, source_bytes, source_count = cache[blob]
                if (functions, matched, source_bytes) != (identity[1], identity[2], identity[-1]):
                    continue  # Never attach a different inventory or source classification.
                for stats in rows:
                    stats.update(source_matched=source_count, mined_matched=matched - source_count)
                    recovered += 1
                break
        reader.stdin.close()
    history_file.write_text(json.dumps(history, separators=(",", ":")) + "\n")
    print(f"Recovered {recovered}/{sum(map(len, needed.values()))} client snapshots from archived function data.")


if __name__ == "__main__":
    backfill()
