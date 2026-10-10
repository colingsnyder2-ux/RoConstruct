"""Small linker-aware MSVC /GL + /LTCG helper for experimental scoring."""
import subprocess
import tempfile
from pathlib import Path

import pefile
from roc import setup


def build_dll(build, source, output, map_output=None, force_unresolved=False,
              export_symbol=None, extra_sources=(), flags=("/O2", "/GS", "/EHsc", "/MD"),
              opaque_sources=(), whole_program=True):
    """Build source as a linked x86 DLL; caller extracts PE functions."""
    cl = setup.compilers()[build]
    env = setup.cl_env(cl)
    vc = Path(cl).parents[1]
    env["LIB"] = setup.cl_path(vc / "lib")
    output = Path(output).resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp:
        objects = []
        for i, extra in enumerate(opaque_sources):
            obj = Path(tmp) / ("opaque%d.obj" % i)
            run = subprocess.run([*setup.cl_command(cl), "/nologo", "/c", *flags,
                                  "/Fo" + setup.cl_path(obj), setup.cl_path(Path(extra).resolve())], capture_output=True,
                                 text=True, env=env, cwd=output.parent, timeout=120)
            if run.returncode:
                raise RuntimeError((run.stdout + run.stderr).strip())
            objects.append(setup.cl_path(obj))
        cmd = [*setup.cl_command(cl), "/nologo", "/LD", *flags,
               *(["/GL"] if whole_program else []), "/Fe" + setup.cl_path(output),
               setup.cl_path(Path(source).resolve()),
               *(setup.cl_path(Path(x).resolve()) for x in extra_sources), *objects,
               "/link", *(["/LTCG"] if whole_program else []), "/LIBPATH:" + setup.cl_path(vc / "lib")]
        if map_output:
            cmd.append("/MAP:" + setup.cl_path(Path(map_output).resolve()))
        if force_unresolved:
            cmd.append("/FORCE:UNRESOLVED")
        if export_symbol:
            cmd.append("/EXPORT:" + export_symbol)
        run = subprocess.run(cmd, capture_output=True, text=True, env=env,
                             cwd=output.parent, timeout=120)
        if run.returncode:
            raise RuntimeError((run.stdout + run.stderr).strip())
    return output


def map_symbols(map_path, image_base=0x10000000):
    """Read simple MSVC MAP public-symbol rows as (rva, symbol)."""
    rows = []
    for line in Path(map_path).read_text(errors="replace").splitlines():
        parts = line.split()
        if len(parts) >= 4 and parts[3] == "f" and ":" in parts[0] and parts[0].split(":", 1)[0].isdigit():
            try:
                # Publics table: segment:offset, symbol, RVA+image-base, ...
                rows.append((int(parts[2], 16) - image_base, parts[1]))
            except ValueError:
                pass
    return rows


def map_bytes(dll, map_path, symbol, size=256):
    """Extract bytes for a map public symbol by RVA."""
    wanted = symbol.lstrip("_")
    pe = pefile.PE(str(dll))
    row = next((rva for rva, name in map_symbols(map_path, pe.OPTIONAL_HEADER.ImageBase)
                if name.lstrip("_") == wanted), None)
    if row is None:
        pe.close()
        raise KeyError(symbol)
    data = pe.get_data(row, size)
    pe.close()
    return row, data


def reachable_size(code, address):
    """Instruction extent of reachable blocks, preserving multiple early returns."""
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_JUMP, CS_GRP_RET
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    pending, seen, end = [address], set(), address
    while pending:
        pc = pending.pop()
        while address <= pc < address + len(code) and pc not in seen:
            ins = next(md.disasm(code[pc - address:], pc, count=1), None)
            if ins is None:
                break
            seen.add(pc)
            end = max(end, pc + ins.size)
            if ins.group(CS_GRP_RET):
                break
            if ins.group(CS_GRP_JUMP):
                from capstone.x86 import X86_OP_IMM
                if ins.operands and ins.operands[0].type == X86_OP_IMM:
                    destination = ins.operands[0].imm
                    if address <= destination < address + len(code):
                        pending.append(destination)
                if ins.mnemonic == "jmp":
                    break
            pc += ins.size
    return end - address


def export_bytes(dll, name, size=256):
    """Return (RVA, bytes) for one exported PE function."""
    pe = pefile.PE(str(dll))
    wanted = name.encode() if isinstance(name, str) else name
    entry = next((x for x in pe.DIRECTORY_ENTRY_EXPORT.symbols if x.name == wanted), None)
    if entry is None:
        raise KeyError(name)
    return entry.address, pe.get_data(entry.address, size)
