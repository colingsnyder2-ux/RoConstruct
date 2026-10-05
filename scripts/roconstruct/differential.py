#!/usr/bin/env python3
"""Compare JSON traces and emit coordinator-compatible runtime evidence."""
import argparse
import json
from pathlib import Path


def normalize(value):
    if isinstance(value, dict):
        return {key: normalize(value[key]) for key in sorted(value)}
    if isinstance(value, list):
        return [normalize(item) for item in value]
    return value


def compare(expected, actual, path="$", mismatches=None):
    mismatches = mismatches if mismatches is not None else []
    if type(expected) is not type(actual):
        mismatches.append({"path": path, "expected": expected, "actual": actual})
        return mismatches
    if isinstance(expected, dict):
        for key in sorted(set(expected) | set(actual)):
            if key not in expected or key not in actual:
                mismatches.append({"path": path + "." + key, "expected": expected.get(key), "actual": actual.get(key)})
            else:
                compare(expected[key], actual[key], path + "." + key, mismatches)
    elif isinstance(expected, list):
        if len(expected) != len(actual):
            mismatches.append({"path": path + ".length", "expected": len(expected), "actual": len(actual)})
        for index, pair in enumerate(zip(expected, actual)):
            compare(pair[0], pair[1], "%s[%d]" % (path, index), mismatches)
    elif expected != actual:
        mismatches.append({"path": path, "expected": expected, "actual": actual})
    return mismatches


def main():
    parser = argparse.ArgumentParser(description="Compare expected and reconstructed JSON traces")
    parser.add_argument("expected", type=Path)
    parser.add_argument("actual", type=Path)
    args = parser.parse_args()
    expected = normalize(json.loads(args.expected.read_text(encoding="utf-8")))
    actual = normalize(json.loads(args.actual.read_text(encoding="utf-8")))
    mismatches = compare(expected, actual)
    result = {"matched": not mismatches, "score": 3 if not mismatches else 0,
              "kind": "runtime", "value": "trace matched" if not mismatches else "trace mismatch",
              "mismatches": mismatches[:100]}
    print(json.dumps(result, indent=2))
    return 0 if not mismatches else 1


if __name__ == "__main__":
    raise SystemExit(main())
