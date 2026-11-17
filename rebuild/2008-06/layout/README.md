# 2008-06 organized source layout (export)

This folder is a generated export, not the working tree. Live native sources stay in
`rebuild/2008-06/native-classes` and `native-headers`; nothing is moved there.

Each file here is a copy of one live native file placed at its original 2007/08 path
(`client/app/gui/ArrowPanel.cpp`, `client/app/include/gui/ArrowPanel.h`, ...). Paths come from
source paths recorded in the RBXGS `WebService.pdb` (same engine tree), with file-name case from
OpenRBX. Only one-to-one mappings with no open review flag are exported.

Proof: every exported `.cpp` is compiled next to its live original with the same compiler and
flags; code, data, relocations and symbols of the two objects are identical (only the discardable
`.debug$S` section, which embeds the object path, is excluded). See `clean-pdb-object-compare.json`.
`*-receipt.json` lists each source, its export path, hashes and any include rewrite.

Not here yet: files with no original path evidence (most recovery units), merged/split units,
and files with open case or identity review. This is not a source-only client and not a P5/P6 gate.

Regenerate: `python work/native-client/layout/layout_export.py work/native-client/layout/families/clean-pdb-export.json`
