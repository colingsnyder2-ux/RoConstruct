"""Audit legal MSVC source-to-binary training-pilot manifests.

RoConstruct never gathers source here.  A maintainer supplies only source they
may use, then this module prevents project leakage into held-out evaluation.
"""
import hashlib
import json
import re
from pathlib import Path

REQUIRED = {"project", "split", "license", "source", "client", "addr", "size",
            "compiler", "flags", "binary", "relocations"}
SPLITS = {"train", "validation", "test"}
ADDR = re.compile(r"^[0-9a-fA-F]{8}$")


def template():
    return {"format": "roconstruct-msvc-pilot-v1", "entries": [{
        "project": "legal-project-name", "split": "train", "license": "SPDX-or-permission-record",
        "source": "relative/path/function.cpp", "client": "2008-06", "addr": "00401000", "size": 12,
        "compiler": "msvc-2008", "flags": "/O2 /Gd", "binary": "relative/path/function.obj",
        "relocations": "relative/path/function.relocs.json"
    }]}


def _digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _relocation_offsets(path):
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return None
    if isinstance(value, dict):
        value = value.get("offsets")
    if not isinstance(value, list) or any(not isinstance(item, int) for item in value):
        return None
    return value


def audit(path, strict=True):
    """Return deterministic audit report. Missing data/error = rejected, never guessed."""
    path = Path(path)
    try:
        document = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError) as error:
        return {"ok": False, "errors": ["cannot read manifest: %s" % type(error).__name__], "entries": 0}
    entries = document.get("entries") if isinstance(document, dict) else None
    errors, projects, keys, files = [], {}, set(), []
    if document.get("format") != "roconstruct-msvc-pilot-v1" or not isinstance(entries, list):
        return {"ok": False, "errors": ["format must be roconstruct-msvc-pilot-v1 with entries list"], "entries": 0}
    for index, entry in enumerate(entries):
        label = "entry %d" % (index + 1)
        if not isinstance(entry, dict):
            errors.append(label + " is not an object")
            continue
        missing = sorted(k for k in REQUIRED if not entry.get(k) and entry.get(k) != 0)
        if missing:
            errors.append(label + " missing " + ", ".join(missing))
            continue
        if entry["split"] not in SPLITS:
            errors.append(label + " has invalid split")
        if entry["compiler"] not in {"msvc-2005", "msvc-2008"}:
            errors.append(label + " compiler must be msvc-2005 or msvc-2008")
        if not isinstance(entry["flags"], str) or not entry["flags"].strip():
            errors.append(label + " compiler flags are empty")
        if not ADDR.match(str(entry["addr"])) or not isinstance(entry["size"], int) or entry["size"] <= 0:
            errors.append(label + " has invalid function boundary")
        prior = projects.setdefault(entry["project"], entry["split"])
        if prior != entry["split"]:
            errors.append(label + " leaks project %s across %s/%s" % (entry["project"], prior, entry["split"]))
        key = (entry["project"], entry["source"], entry["addr"])
        if key in keys:
            errors.append(label + " duplicates source/function boundary")
        keys.add(key)
        for field in ("source", "binary", "relocations"):
            candidate = (path.parent / entry[field]).resolve()
            if not candidate.is_relative_to(path.parent.resolve()):
                errors.append(label + " has path outside manifest directory")
                continue
            if not candidate.is_file():
                errors.append(label + " missing " + field)
            else:
                files.append((field, str(candidate.relative_to(path.parent.resolve())), _digest(candidate)))
                if field == "binary" and candidate.stat().st_size < entry["size"]:
                    errors.append(label + " binary is smaller than declared function")
                if field == "relocations":
                    offsets = _relocation_offsets(candidate)
                    if offsets is None or len(offsets) != len(set(offsets)) or any(offset < 0 or offset >= entry["size"] for offset in offsets):
                        errors.append(label + " relocations must be unique integer offsets inside function")
    counts = {split: sum(e.get("split") == split for e in entries if isinstance(e, dict)) for split in sorted(SPLITS)}
    if strict:
        if not 100 <= len(entries) <= 300:
            errors.append("strict pilot requires 100-300 entries")
        if any(counts[split] == 0 for split in SPLITS):
            errors.append("strict pilot needs train, validation, and test splits")
        if len(projects) < 3:
            errors.append("strict pilot needs at least 3 project-held-out groups")
    return {"ok": not errors, "entries": len(entries), "splits": counts,
            "projects": len(projects), "files": files, "errors": errors}
