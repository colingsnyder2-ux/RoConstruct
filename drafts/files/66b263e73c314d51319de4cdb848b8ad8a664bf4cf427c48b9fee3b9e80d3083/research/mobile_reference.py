"""Build, search and share optional mobile donor evidence. No target activation."""
import argparse
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import sqlite3
import struct
import zipfile

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "local/references"
IOS_HASH = "6b008dc089b1db53f97167be048be266cab89262ddb7688d2ac8a053663c64f2"
BUILD = "ios-2013-12_2.132.41333"
STABS = {0x20: "GSYM", 0x24: "FUN", 0x26: "STSYM", 0x2e: "BNSYM",
         0x44: "SLINE", 0x4e: "ENSYM", 0x64: "SO", 0x66: "OSO",
         0x80: "LSYM", 0x84: "SOL", 0xa0: "PSYM"}


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def macho_records(data):
    """Read nlist records and section names from this thin ARM32 Mach-O."""
    if data[:4] != b"\xce\xfa\xed\xfe":
        raise ValueError("Expected thin little-endian Mach-O32")
    _, cpu, _, _, commands, commands_size, _ = struct.unpack_from("<7I", data)
    if cpu != 12 or 28 + commands_size > len(data):
        raise ValueError("Expected ARM32 with valid load commands")
    pos, table, sections = 28, None, []
    for _ in range(commands):
        cmd, size = struct.unpack_from("<II", data, pos)
        if size < 8 or pos + size > 28 + commands_size:
            raise ValueError("Invalid load command")
        if cmd == 2:
            table = struct.unpack_from("<IIII", data, pos + 8)
        if cmd == 1:
            count = struct.unpack_from("<I", data, pos + 48)[0]
            for i in range(count):
                sec = pos + 56 + i * 68
                sections.append(data[sec:sec + 16].split(b"\0")[0].decode())
        pos += size
    if table is None:
        raise ValueError("Missing LC_SYMTAB")
    off, count, strings, length = table
    if off + count * 12 > len(data) or strings + length > len(data):
        raise ValueError("Invalid symbol table bounds")
    records = []
    for i in range(count):
        index, kind, section, desc, value = struct.unpack_from("<IBBHI", data, off + i * 12)
        if index >= length:
            raise ValueError("Invalid symbol string index")
        end = data.find(b"\0", strings + index, strings + length)
        if end < 0:
            raise ValueError("Unterminated symbol name")
        name = data[strings + index:end].decode("utf-8", errors="replace")
        records.append((kind, section, desc, value, name))
    return records, sections


def export_member(path):
    member = path.split("/" + BUILD + "/", 1)[1]
    parts = PurePosixPath(member).parts
    if not parts or ".." in parts or "\\" in member or ":" in member or member.startswith("/"):
        raise ValueError("Unsafe export path")
    return member


def build(binary, exports, output):
    if sha(binary) != IOS_HASH:
        raise ValueError("iOS binary differs from recorded reference SHA-256")
    if output.exists():
        raise ValueError("Output exists; use a fresh --output directory")
    data = binary.read_bytes()
    records, sections = macho_records(data)
    output.mkdir(parents=True)
    db = sqlite3.connect(output / "symbols.sqlite")
    db.executescript("""
        CREATE TABLE symbols(kind INTEGER, address INTEGER, name TEXT, source TEXT, object TEXT, size INTEGER);
        CREATE TABLE exports(address INTEGER, label TEXT, member TEXT, size INTEGER);
        CREATE TABLE paths(kind INTEGER, path TEXT, source TEXT);
    """)
    counts, source, directory, obj, pending = Counter(), "", "", "", None
    functions, type_strings = 0, 0
    for kind, section, desc, value, name in records:
        counts[f"0x{kind:02x}"] += 1
        if kind == 0x64:
            if not name:
                source, directory, obj = "", "", ""
            elif name.endswith("/"):
                directory = name
            else:
                source = name if name.startswith("/") else directory + name
        if kind == 0x66:
            obj = name
        if kind in (0x64, 0x66, 0x84) and name:
            db.execute("INSERT INTO paths VALUES(?,?,?)", (kind, name, source))
        if kind == 0x80 and re.search(r":[tT](?:\(|\d)", name):
            type_strings += 1
        if kind == 0x24 and not name and pending is not None:
            db.execute("UPDATE symbols SET size=? WHERE rowid=?", (value, pending))
            pending = None
        elif name and (kind == 0x24 or not kind & 0xe0):
            # Only N_FUN carries the current debug-map compilation unit.
            row = db.execute("INSERT INTO symbols VALUES(?,?,?,?,?,NULL)",
                             (kind, value, name, source if kind == 0x24 else "",
                              obj if kind == 0x24 else ""))
            if kind == 0x24:
                functions += 1
                pending = row.lastrowid
    export_count = 0
    with (exports / "functions.csv").open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream):
            db.execute("INSERT INTO exports VALUES(?,?,?,?)", (int(row["address"], 16),
                       row["namespace"] + "::" + row["name"], export_member(row["file"]), int(row["size"])))
            export_count += 1
    db.executescript("CREATE INDEX symbol_address ON symbols(address); CREATE INDEX export_address ON exports(address);")
    matched = db.execute("SELECT count(*) FROM exports e WHERE EXISTS(SELECT 1 FROM symbols s WHERE s.address=e.address AND s.kind=36)").fetchone()[0]
    db.commit()
    db.close()
    result = dict(schema=1, donor=BUILD, binary_sha256=IOS_HASH,
                  export_csv_sha256=sha(exports / "functions.csv"), records=len(records),
                  record_types=dict(counts), named_function_debug_records=functions,
                  export_rows=export_count, exports_with_N_FUN_at_same_address=matched,
                  sections=sections, type_definition_strings=type_strings,
                  line_records=counts["0x44"], local_records=counts["0x80"], parameter_records=counts["0xa0"],
                  limits="Debug map provenance and symbol identities only; no Windows layout, ABI or runtime proof.",
                  database_sha256=sha(output / "symbols.sqlite"))
    (output / "manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    return result


def query(index, terms, limit):
    # Read-only mode avoids accidentally creating a missing DB.
    with sqlite3.connect((index / "symbols.sqlite").resolve().as_uri() + "?mode=ro", uri=True) as db:
        db.row_factory = sqlite3.Row
        where = " AND ".join("instr(lower(s.name || ' ' || s.source || ' ' || coalesce(e.label,'')), ?) > 0" for _ in terms)
        sql = """SELECT printf('%08x',s.address) AS address, s.name, s.source, s.object, s.size,
                 e.label, e.member FROM symbols s LEFT JOIN exports e ON s.address=e.address
                 WHERE s.kind=36 AND """ + where + " ORDER BY s.address,s.name LIMIT ?"
        return [dict(row) for row in db.execute(sql, [term.lower() for term in terms] + [limit])]


def pack(index, output, binaries):
    if output.exists():
        raise ValueError("Kit already exists; choose a new --output")
    inventory = {}
    manifest = json.loads((index / "manifest.json").read_text())
    if sha(index / "symbols.sqlite") != manifest["database_sha256"]:
        raise ValueError("Index database differs from manifest")
    members = [(p, "local/references/mobile-index/" + p.name) for p in (index / "manifest.json", index / "symbols.sqlite")]
    members += [(ROOT / name, name) for name in ("research/mobile_reference.py", "research/ghidra_reference.py", "docs/GHIDRA_REFERENCE.md", "docs/MOBILE_REFERENCE_PILOT.md")]
    members.append((BASE / BUILD / "functions.csv", "local/references/" + BUILD + "/functions.csv"))
    members += [(ROOT / "work/mobile-reference-pilot" / name, "work/mobile-reference-pilot/" + name)
                for name in ("2012-name-asm.txt", "2008-name-asm.txt", "target-evidence.json")]
    # A small pilot excerpt avoids copying all 88k OneDrive files. The full
    # symbol/source index is included; other pseudo-C bodies remain optional.
    with sqlite3.connect((index / "symbols.sqlite").resolve().as_uri() + "?mode=ro", uri=True) as db:
        for member, in db.execute("SELECT member FROM exports WHERE label LIKE 'RBX/Name::%' AND instr(label,'<')=0"):
            members.append((BASE / BUILD / member, "local/references/" + BUILD + "/" + member))
    members.append((BASE / BUILD / "_global/declareNullName.c", "local/references/" + BUILD + "/_global/declareNullName.c"))
    if binaries:
        members += [(BASE / "ios-2013-12_2.132.41333-binary/robloxmobile", "local/references/ios-2013-12_2.132.41333-binary/robloxmobile"),
                    (BASE / "android-2014-06_2.155.47886/libroblox.so", "local/references/android-2014-06_2.155.47886/libroblox.so")]
    output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(output, "w", zipfile.ZIP_DEFLATED) as archive:
        for path, name in members:
            inventory[name] = sha(path)
            archive.write(path, name)
        archive.writestr("reference-kit.json", json.dumps(dict(schema=1, donor=BUILD, files=inventory), indent=2))
    receipt = dict(file=output.name, sha256=sha(output), bytes=output.stat().st_size, binaries=binaries, files=inventory)
    output.with_suffix(".receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    return receipt


def install(archive, expected, destination):
    if sha(archive) != expected.lower():
        raise ValueError("Kit SHA-256 mismatch")
    if destination.exists():
        raise ValueError("Destination exists; install into a fresh directory, then review/copy")
    with zipfile.ZipFile(archive) as kit:
        inventory = json.loads(kit.read("reference-kit.json"))["files"]
        if len(set(kit.namelist())) != len(kit.namelist()) or set(kit.namelist()) != set(inventory) | {"reference-kit.json"}:
            raise ValueError("Kit inventory mismatch")
        for name, digest in inventory.items():
            path = PurePosixPath(name)
            if not path.parts or path.is_absolute() or ".." in path.parts or "\\" in name or ":" in name:
                raise ValueError("Unsafe kit member")
            if hashlib.sha256(kit.read(name)).hexdigest() != digest:
                raise ValueError("Kit member SHA-256 mismatch: " + name)
        destination.mkdir(parents=True)
        # No extractall, symlink interpretation or execution of packaged code.
        for name in inventory:
            target = destination / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(kit.read(name))
    return dict(installed=str(destination), files=len(inventory))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    p = sub.add_parser("index")
    p.add_argument("--binary", type=Path, default=BASE / "ios-2013-12_2.132.41333-binary/robloxmobile")
    p.add_argument("--exports", type=Path, default=BASE / BUILD)
    p.add_argument("--output", type=Path, default=BASE / "mobile-index")
    p = sub.add_parser("query")
    p.add_argument("terms", nargs="+")
    p.add_argument("--index", type=Path, default=BASE / "mobile-index")
    p.add_argument("--limit", type=int, default=10)
    p = sub.add_parser("pack")
    p.add_argument("--index", type=Path, default=BASE / "mobile-index")
    p.add_argument("--output", type=Path, required=True)
    p.add_argument("--binaries", action="store_true")
    p = sub.add_parser("install")
    p.add_argument("archive", type=Path)
    p.add_argument("--sha256", required=True)
    p.add_argument("--destination", type=Path, required=True)
    args = parser.parse_args()
    if args.command == "index":
        result = build(args.binary, args.exports, args.output)
    elif args.command == "query":
        if args.limit < 1:
            parser.error("--limit must be positive")
        result = query(args.index, args.terms, args.limit)
    elif args.command == "pack":
        result = pack(args.index, args.output, args.binaries)
    else:
        result = install(args.archive, args.sha256, args.destination)
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
