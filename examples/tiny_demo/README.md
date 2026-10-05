# Tiny reconstruction demo

Safe, non-Roblox smoke test. It exercises stable IDs, queue leases, attempts,
generated C++, compiler-style verification, differential evidence, and batch
output. It needs Python only—no client binary, Ghidra, Ollama, or MSVC.

Run from repo root:

```powershell
py scripts\roconstruct\demo.py
```

Output lands in `work\demo\reconstructed`. `demo_source.c` is ground truth;
`decompiled.json` is a tiny stand-in for a Ghidra export. Real client work
replaces that export with authorized Ghidra output.
