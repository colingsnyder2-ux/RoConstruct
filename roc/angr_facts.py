"""Optional angr facts for one function; normal matching stays dependency-free."""

import json


def analyze(binary, address, max_bytes=128):
    try:
        import angr
    except ImportError:
        raise RuntimeError("optional angr is not installed; run: python -m pip install angr")

    project = angr.Project(str(binary), auto_load_libs=False)
    block = project.factory.block(address, size=max_bytes)
    mnemonics = [{"address": hex(insn.address), "mnemonic": insn.mnemonic,
                  "op_str": insn.op_str} for insn in block.capstone.insns]
    return {"tool": "angr", "address": hex(address), "found": bool(mnemonics),
            "bounded": True, "max_bytes": max_bytes,
            "blocks": [{"address": hex(address), "size": block.size}],
            "edges": [], "mnemonics": mnemonics, "size": block.size}


def dump(binary, address, max_bytes=128):
    return json.dumps(analyze(binary, address, max_bytes), indent=2, sort_keys=True)


def analyze_many(binary, items, default_size=128):
    """Analyze many windows while loading the PE once."""
    try:
        import angr
    except ImportError:
        raise RuntimeError("optional angr is not installed; run: python -m pip install angr")
    project = angr.Project(str(binary), auto_load_libs=False)
    out = []
    for address, size in items:
        block = project.factory.block(address, size=size or default_size)
        mnemonics = [{"address": hex(insn.address), "mnemonic": insn.mnemonic,
                      "op_str": insn.op_str} for insn in block.capstone.insns]
        out.append({"address": hex(address), "found": bool(mnemonics),
                    "bounded": True, "size": block.size,
                    "instructions": len(mnemonics),
                    "terminal": mnemonics[-1]["mnemonic"] if mnemonics else None})
    return out
