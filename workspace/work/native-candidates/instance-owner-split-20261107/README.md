# Inactive Instance ownership candidate

`original.cpp` preserves the captured donor source. `candidate.cpp` retains its
five method bodies under inactive guards so separately compiled native providers
can own them. Do not add either file to a client build based on this folder.

`proof.json` records object, data, relocation, source, and archive comparison
evidence. It does not prove a linked client, complete ABI or runtime safety.
The remaining gates and blockers are listed there.
