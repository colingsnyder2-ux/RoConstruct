# P4 local assets: partial gate

Source revision: `88e67662d4`. Canonical player build linked, smoke exit 0.
Normal runtime receipt: `work/2008-06/p4-disk-assets-88e67662d4/receipt.json`.
Regression receipt: `work/2008-06/p4-lifetime-regression-88e67662d4/receipt.json`.

Normal/default launches read places from disk. The default red studded block
is authored `Places/default.rbxl`; selftest retains its explicit control fixture.
`stage_demo_content.py` separates original external Content inputs from authored
CC0 test assets. Local ContentProvider and Ogre roots share the explicit absolute
content root. Ordinary disk paths work from fresh output directories.

## Native evidence and adaptations

- `00500b90` FileMesh factory and `00500780` file loader provide the existing
  algorithms. Integration uses the measured Mesh/Level types and shared bank,
  not mined padded declarations. FileMesh size is 0x88. The bool-ready local
  ContentProvider API bridges native status Succeeded=1. FileMesh scale is the
  SpecialMesh Scale alone; Part size does not multiply it. Native v1.00 vertex
  records must be contiguous: a newline between faces breaks the literal `[` scan.
  The corrected fixture preserves that parser behavior. Malformed mesh handling
  is not claimed safe or complete.
- Genuine `RBX::SpecialShape` is linkable; previous `ViewNew::SpecialShape`
  omission does not establish that the real class is unavailable. The adapter
  tracks real child/property signals and retains the existing entity path.
  Only FILE_MESH is added; other SpecialMesh variants remain unsupported.
- `004eb190`, branch `004eba71..004ebb10`, establishes file texture, VertexColor,
  alpha and material parameters. The adapter uses the recovered native material
  and TextureProxy paths. A missing texture keeps the ordinary material.
- `0056cd80` uses target string `Content` at `0082f6b0` with ContentId RTTI;
  the donor's `ContentId` XML type name was incorrect. Native `0058f6c0` branches
  parse content when xsi:nil is absent, fails conversion, or is false. Both donor
  mistakes are corrected by overlay replacements; rbxgs-app was explicitly rebuilt.
- `004e5f20` is SpecialShape::getMeshId, not FileMesh::create. Prior candidate
  labels do not supersede actual callers/native instructions.

## Verified on this source

`record_p4_assets.py` launches five separate processes with developer overrides
removed and captures actual rgmain/rgdx loaded paths/hashes. The receipt pins
source, fixture, content, executable/map, observer, commands and outputs.

1. Panel: one model at (0,0,0), size (4,4,4), native file mesh level, 6 source/GPU
   indices. Four independently sampled pixel regions verify texture UV quadrants.
2. Gallery: nested Model/Parts plus explicit CurrentCamera reference deserialize;
   models at (-2,0,0) and (2,0,0). Textured panel and red sphere both render;
   sphere has 864 source/1296 GPU indices. Camera rendering still uses harness
   camera; deserializing the reference does not prove native camera consumption.
3. Missing mesh in a new owned Content copy: explicit unavailable log, omitted
   model status 3, entirely background image, exit 0.
4. Missing texture in a separate owned copy: explicit unavailable log, visible
   native ordinary-material fallback, exit 0.
5. Absent place: explicit read error, exit 1, no rendered frame.

All rendering cases end with zero levels, refs, backends and sphere cache entries.
Mixed-shape P3 lifetime, selftest and cachetest pass on the same executable.
Owner's newer diagnostic player/engine/entity edits remain outside this commit.

## Still open

P4 is not complete. Compare both places' objects/materials/selected assets and
failure behavior against the unmodified original. Recover and exercise the native
sound path; authored tone.wav is presently an unused fixture. Preserve prior
original reference captures and avoid writing through its Content junction.
These receipts grant behavioral integration evidence, not server-verified exact
credit or full native renderer/startup ABI coverage. P5-P10 remain open.
