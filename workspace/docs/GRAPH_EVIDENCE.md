# June 2008 rendering graph evidence

The P2 preset names the five rendering entry points requested for exploration.
It does not add call edges. All direct edges come from `functions.jsonl`.

A read-only `roc.match.target` / `roc.match.disasm` inspection of original
`007ab0a0` on 2026-10-31 found:

- `007ab9c7: call 00549a50`, on the non-special branch after testing the level's
  dirty byte at `+1c`, passing the context and an AxisAlignedBox pointer.
- `007aba67: call 00549610`, on the special branch with the same receiver and
  arguments.
- `007ac5aa` and `007ac5d7`: direct calls to `0067d9b0`.

The recovered renderer source calls `updateGeometry` and `updateSpecialGeometry`
on these branches. Recovered implementations use analog names
`NativeMeshLevel::upload` (`roc_unit_32290385cfe42487.cpp`) and
`NativeMeshLevel::makeHWSubMesh` (`src/2008-06/00549610.cpp`). The graph displays
semantic method labels with source-supported confidence, not a claim that these
were original declarations. See also
`work/big-mining-2008-20261020/renderer-native-sdk-contract.json:bounds_api`.

Both geometry functions currently have cached 100% mining scores. They must not
be described as unmined merely because their analog names differ. Their native
integration status comes only from available rebuild ownership reports. There
is no function runtime-verification claim here.

The old contract's known layout gaps are historical observations, not proof of
current blockers. No dependency or virtual-target edges are inferred from them.
