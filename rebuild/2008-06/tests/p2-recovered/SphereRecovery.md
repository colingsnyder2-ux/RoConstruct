# P3 native ball path

Part::updateMesh004ef930 shape0 reaches factory004eea30 and ctor004fcfb0.
Existing source bodies are integrated against the measured Mesh0x88/Level0x28
and shared native vertex bank. MeshRef now correctly retains the common Mesh
base, rather than assuming every shape is BlockMesh. Existing entity methods
are unchanged. SphereMesh's genuine static MeshFactory base yields allocation
0x8c; no padding field is fabricated. Mesh geometryKind is2 at+84.

SphereLevelBuilder uses the genuine QuadVolume.h members, measured size0x20;
SphereBuilder adds six-element subdivision at+20, size0x24. The six wrappers
004fce90/c0/f0,004fcf20/50/80 call face templates004fbdb0,004fc080/350/620/8f0/cbc0.
Their emitters004fac10/af00/b1f0/b4e0/b7d0/bac0 allocate a7x7 vertex grid per
flat face, apply callback004fabb0, map normal/position through the original
NormalId transforms, retain each appended quad index, then release temporary
grid references. UV scale is0.5 from00819bac. Callback copies normalized vertex
to normal before component radius scaling; this deliberately preserves the
target's ellipsoid-normal behavior. No stock Ogre sphere generation is used.

Factory004eea30 caches one variant per surface/size. Genuine G3D::Table, mutex,
decal/texture key maps and counter reproduce cache0x60, mutex+10,count+5c from
004d97b0/004d92a0 and factory code. The surface key is retargeted to its unsigned
value with the same identity hash/equality. The unused decal/texture maps remain
empty and those factory paths are not implemented or credited. Every100 creations
flush cache-only refs while retaining the current result. Empty keys/singleton
persist like native code; resource-zero assertions count live objects, not every
heap allocation. Existing block factory behavior remains separately tested.

Balls bypass usesMegaTexture004e5f80 and use existing getMaterial, shaded original
Surfaces.png and native texture/backend code. stage_demo_content.py now stages
that additional external period asset. General's FileSystem root permits original
Ogre image loading with resolved absolute paths. Exact June asset identity remains
unproven. Model-side factory still derives texture directory from selected strip.

First player run hit a measured null read at00000805 in the standard texture path.
The harness intentionally has no enclosing native renderer/context. Its explicit
texture mode enables mipmaps and disables AA resizing when context is null;
native +805/+800 reads are preserved when a real context exists. This settings
bridge is a tracked P6/native-context dependency, not proof of native defaults or
reconstruction of an invented padded context. The material dependency must be
rebuilt explicitly after changes; player builds reuse dependency archives.

P3SphereMeshTest verifies GPU streams:294 vertices,864 retained quad indices,
1296 triangle indices, unit normals, ellipsoid scaling and flat(.125,.25) UV.
It exercises32 release cycles, repeated shared lookups,120 new sizes across the
100-creation purge, and zero live levels/bank refs/backends afterward.
Reference-client silhouette comparison and mixed-shape lifetime acceptance remain
required before closing P3. Runtime/map receipts must pin the exact source build.
