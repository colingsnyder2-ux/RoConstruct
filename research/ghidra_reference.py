"""Search the optional iOS 2013 reference export without executing its contents."""
import argparse
import csv
import io
from pathlib import Path, PurePosixPath
import zipfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("query", nargs="+", help="case-insensitive terms; all must match")
    parser.add_argument("--archive", type=Path, help="optional ZIP instead of installed directory")
    parser.add_argument("--directory", type=Path, default=Path(__file__).resolve().parents[1] / "local/references/ios-2013-12_2.132.41333")
    parser.add_argument("--limit", type=int, default=10)
    parser.add_argument("--show", action="store_true", help="print matching pseudo-C bodies")
    parser.add_argument("--lines", type=int, default=100, help="maximum body lines per result")
    args = parser.parse_args()
    if args.limit < 1 or args.lines < 1:
        parser.error("--limit and --lines must be positive")
    if not args.archive and not (args.directory / "functions.csv").is_file():
        parser.error("reference directory missing; see docs/GHIDRA_REFERENCE.md")
    from contextlib import ExitStack
    with ExitStack() as stack:
        archive = stack.enter_context(zipfile.ZipFile(args.archive)) if args.archive else None
        index = archive.open("functions.csv") if archive else (args.directory / "functions.csv").open("rb")
        rows = csv.DictReader(stack.enter_context(io.TextIOWrapper(index, encoding="utf-8-sig")))
        count = 0
        for row in rows:
            label = row["namespace"] + "::" + row["name"]
            if not all(term.casefold() in label.casefold() for term in args.query):
                continue
            # Export records the contributor's absolute Linux paths. Resolve
            # only the portion below this export's directory inside the ZIP.
            member = row["file"].split("/ios-2013-12_2.132.41333/", 1)[1]
            if ".." in PurePosixPath(member).parts or member.startswith("/") or "\\" in member or ":" in member:
                raise ValueError("unsafe reference member")
            print(f"{row['address']} | {label} | size={row['size']} | {member}")
            if args.show:
                available = member in archive.namelist() if archive else (args.directory / member).is_file()
                if available:
                    body = archive.read(member) if archive else (args.directory / member).read_bytes()
                    lines = body.decode("utf-8", errors="replace").splitlines()
                    print("\n".join(lines[:args.lines]))
                    if len(lines) > args.lines:
                        print(f"... {len(lines) - args.lines} more lines; raise --lines")
                else:
                    print("Optional pseudo-C body not installed; use indexed provenance or original binary.")
            count += 1
            if count == args.limit:
                print("Result limit reached; narrow query or raise --limit.")
                break
        if not count:
            print("No matching symbols.")


if __name__ == "__main__":
    main()
