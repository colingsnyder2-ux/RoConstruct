#!/usr/bin/env python3
"""Dump every function + decompilation + call edges from the Rbx2008M Ghidra project to JSONL.

Runs as native CPython3 against the Ghidra JVM via the pyghidra library (no Ghidra
script provider needed -- headless analyzeHeadless cannot run .py in Ghidra 12 without
PyGhidra-mode launch, which this replaces).

Usage:
    python export_pyghidra.py               # both programs
    python export_pyghidra.py /rgmain.dll   # one program (project path)

Writes (append-safe, one JSON object per line):
    <OUT>/functions_<tag>.jsonl  {addr, program, name, size, sig, is_thunk, n_xrefs_in, decompiled}
    <OUT>/edges_<tag>.jsonl      {program, src, dst}

Requires: Ghidra project closed in GUI (exclusive lock) and
    python -m pip install --no-index -f <ghidra>/Ghidra/Features/PyGhidra/pypkg/dist pyghidra
"""

import json
import os
import sys
import time

ROOT_DIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GHIDRA_DIR = os.path.join(ROOT_DIR, "work", "re", "ghidra")
PROJ_DIR = os.path.join(ROOT_DIR, "work", "re", "projects")
PROJ_NAME = "Rbx2008M"
OUT_DIR = os.path.join(ROOT_DIR, "work", "re", "export")
PROGRAMS = ["/RobloxApp_client.exe", "/rgmain.dll"]
DECOMP_TIMEOUT = 120  # seconds per function


def export_program(prog, out_dir):
    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor

    prog_name = str(prog.getName())
    fm = prog.getFunctionManager()
    refmgr = prog.getReferenceManager()
    listing = prog.getListing()
    monitor = ConsoleTaskMonitor()

    dec = DecompInterface()
    dec.openProgram(prog)

    tag = prog_name.replace(".", "_")
    fn_path = os.path.join(out_dir, "functions_%s.jsonl" % tag)
    edge_path = os.path.join(out_dir, "edges_%s.jsonl" % tag)

    n_func = 0
    n_decomp = 0
    t0 = time.time()

    with open(fn_path, "a", encoding="utf-8") as fn_out, \
         open(edge_path, "a", encoding="utf-8") as edge_out:

        fn_iter = fm.getFunctions(True)
        while fn_iter.hasNext() and not monitor.isCancelled():
            fn = fn_iter.next()
            addr = str(fn.getEntryPoint())
            name = str(fn.getName())
            size = fn.getBody().getNumAddresses()
            sig = str(fn.getSignature())
            is_thunk = 1 if fn.isThunk() else 0

            decompiled = None
            res = dec.decompileFunction(fn, DECOMP_TIMEOUT, monitor)
            if res is not None and res.decompileCompleted():
                d = res.getDecompiledFunction()
                if d is not None:
                    decompiled = str(d.getC())

            try:
                n_xrefs = refmgr.getReferenceCountTo(fn.getEntryPoint())
            except Exception:
                n_xrefs = -1

            fn_out.write(json.dumps({
                "addr": addr,
                "program": prog_name,
                "name": name,
                "size": size,
                "sig": sig,
                "is_thunk": is_thunk,
                "n_xrefs_in": n_xrefs,
                "decompiled": decompiled,
            }, ensure_ascii=False) + "\n")

            # outgoing CALL references from inside the function body
            body = fn.getBody()
            addr_iter = body.getAddresses(True)
            while addr_iter.hasNext():
                a = addr_iter.next()
                for r in refmgr.getReferencesFrom(a):  # returns Reference[], not iterator
                    if r.getReferenceType().isCall():
                        tgt = r.getToAddress()
                        if tgt is not None and tgt.isMemoryAddress():
                            edge_out.write(json.dumps({
                                "program": prog_name,
                                "src": addr,
                                "dst": str(tgt),
                            }) + "\n")

            n_func += 1
            if decompiled:
                n_decomp += 1
            if n_func % 200 == 0:
                fn_out.flush()
                edge_out.flush()
                print("export: %s %d funcs (%d decompiled) %.1fs"
                      % (prog_name, n_func, n_decomp, time.time() - t0), flush=True)

    print("export: DONE %s -> %d functions, %d decompiled, %.1fs"
          % (prog_name, n_func, n_decomp, time.time() - t0), flush=True)


def main():
    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    import pyghidra

    paths = sys.argv[1:] or PROGRAMS
    os.makedirs(OUT_DIR, exist_ok=True)

    print("export: starting JVM...", flush=True)
    pyghidra.start(install_dir=GHIDRA_DIR, verbose=False)
    project = pyghidra.open_project(PROJ_DIR, PROJ_NAME)

    for ppath in paths:
        with pyghidra.program_context(project, ppath) as prog:
            export_program(prog, OUT_DIR)

    try:
        project.close(False)
    except Exception:
        pass

    print("export: ALL DONE", flush=True)
    sys.stdout.flush()
    sys.stderr.flush()
    os._exit(0)  # JPype JVM threads must not block interpreter exit


if __name__ == "__main__":
    main()
