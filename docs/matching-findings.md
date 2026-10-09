# Matching findings

Append-only experiment log.

- 2026-10-09: `2007-08/004485c0`: baseline 98. Target saves `esi` after null-check; candidate saves before. Requested compiler-flag variants: `/O2`, `/Ox`, `/Ob0`, `/Ob1`, `/Ob2`, `/Oi`, `/Oi-`, `/GS`, `/GS-`, `/EHsc`, `/EHa`, `/MD`, `/MT`, `/GR`, `/GR-`, `/fp:precise`, `/fp:fast` all remain 98. `/O1`=75, `/Oy-`=88. Flags do not solve.
- 2026-10-09: `2007-08/004485c0`: `else` source shape=84; `goto` shape=98. No exact.
- 2026-10-09: `2007-08/004021a0`: baseline 89. Tested comparator argument reversal=89; signed pointer casts=91; inlined comparator=74; declaration reorder=89. No exact. Target uses global comparator in `ebx`, argument in `edi`, signed `jl`; current source emits different register/order and unsigned `jb`.
- 2026-10-09: Flag sweep `004021a0`: `/O1`=58, `/O2` and `/Ox`=89, `/Oy-`=83; `/Ob0`, `/Ob1`, `/Ob2`, `/Oi`, `/Oi-`, `/GS`, `/GS-`, `/EHsc`, `/EHa`, `/MD`, `/MT`, `/GR`, `/GR-`, `/Zc:wchar_t-`, `/fp:precise`, `/fp:fast`, `/Gd`, `/Gr`, `/Gz`=89. No exact.
- 2026-10-09: Flag sweep `00449820`: `/O1`=78, `/O2` and `/Ox`=98, `/Oy-`=82; all other requested variants remain 98. No exact.
- 2026-10-09: `2007-08/00435660`: volatile member stores + typed `this` return=100.
- 2026-10-09: `2007-08/00446c80`: predicate-before-padding parameter=100.
- 2026-10-09: `2007-08/004b8400`: strict `<` comparison=100.
- 2026-10-09: Current `work/2007-08/scores.json`: 9,919 functions at 100; ten remaining 98% holdouts: `004021a0`, `004485c0`, `00449820`, `0055ece0`, `005b1e90`, `005f8b40`, `005fc300`, `00675890`, `006a2dd0`, `006cb940`.
- 2026-10-09: Added explicit `/Ob2` and `/Oi` sweep choices. Full Cartesian flag matrix now 62,208 combinations; no rerun yet.
- 2026-10-09: `00449820`: external GUID-like declarations produce 98, not exact; unresolved external data becomes zero-sized `push` and worsens branch layout. Keep literal constants for now.
