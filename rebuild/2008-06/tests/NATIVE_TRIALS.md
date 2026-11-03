# Native recovery trials

`Native*Trial.cpp` files are isolated compiler experiments.  They are not
production source and are not proof of runtime safety.  Keep them here so
failed variants, compiler flag notes, and byte-diff evidence stay reproducible
without polluting recovered class source.

## Layout

| Location | Purpose |
| --- | --- |
| `native-classes/` | promoted exact production bodies |
| `native-headers/` | recovered ABI declarations and controlled overrides |
| `tests/Native*Trial.cpp` | one-off match/layout experiments |
| `tests/record_native_*.py` | repeatable receipts for a class/layout |
| `tests/check_native_class.py` | body/range byte matcher |
| `p6/build_client.py` | explicit diagnostic selection manifest |
| `out/` | disposable compiler output and receipts |

## Trial naming

`Native<Class><Purpose>Trial.cpp` means a bounded test of one class method,
layout condition, or template form.  A trial may be exact while still blocked
from promotion by provider ABI, owner ambiguity, or a missing lifetime proof.

## Promotion checklist

1. Target address and original owner recorded.
2. Exact body and relocations checked with `roc native-asm` or checker.
3. Constructor + destructor checked for nontrivial class layouts.
4. Required header belongs in `native-headers/`, not vendor/import paths.
5. Minimal body moved into `native-classes/`.
6. Receipt rerun after move.
7. Build selection tested separately; a link is not runtime proof.

Do not delete a trial after promotion.  It is evidence and regression input.
Archive only trials conclusively superseded by an equivalent receipt, and leave
a redirect entry in this file or a manifest before moving paths.
