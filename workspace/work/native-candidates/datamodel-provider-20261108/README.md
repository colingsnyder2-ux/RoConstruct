# DataModel and Lua allocator provider diagnostic

Inactive evidence against 12c04e267df6f75c914cccbab07c43498c8e2ad0. Three canonical sources compiled once. Four functions matched original relocation-masked code and referenced data. Original disassembly shows no call instructions in those four bodies; fail-closed direct-call analysis passed with empty call lists. This does not establish class layout, ABI, ownership in the final executable, exception behavior, runtime or server credit.

Adding the three fresh objects to the previous link-only diagnostic reduced unresolved symbols from 122 to 118, with zero introduced unresolved symbols and zero duplicates. The link still fails; no executable was run. The shell retains P6 glue. Object hashes and all source/header/compiler input hashes are recorded in the receipts; objects remain local.
