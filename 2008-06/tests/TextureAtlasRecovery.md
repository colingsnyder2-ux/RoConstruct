# Original mega-atlas prerequisite

Build/run with an identified real input strip, without generating replacement art:

```powershell
$env:ROC_TEXTURE_STRIP = 'C:\path\to\SurfacesStrip.png'
.\roc.cmd rebuild 2008-06 module p2-image-core --no-notify
.\roc.cmd rebuild 2008-06 module p2-texture-atlas --no-notify
```

PlayerTextureAtlas.cpp reuses existing007ae4e0 expansion/upload and007add10 shading.
It expands the input strip into32 BrickColor palette columns and uses genuine
G3D/Ogre classes. Tests cover dark/neutral/highlight shading anchors, neutral
palette texels, cache identity, full GPU RGB readback, release and missing file.
Readback is compared against CPU bytes under the same D3D9 floating-point mode;
D3D9 device creation changes x87 precision and can shift shaded bytes by one.
The test saves texture-atlas-cpu.png and texture-atlas-gpu.png.

p2-image-core rebuilds actual G3D/IJG and bundled libpng1.2.7 together. The earlier
cached G3D library had a verified_sinks.obj trap selected for PNG entry points.
It is preserved as evidence. The new target uses a separate output directory,
and final image/atlas maps must contain no verified_sinks provider. The coherent
PNG1.2.7 dependency is recorded; no new exact-target/server credit is claimed.

Available real strip:64x256 RGB, SHA256
dc5418f1c8dbd2e1fc218c392b41e3b55461817930a9468d821c5d48bdae85e4.
It occurs identically in the local August2007 client and RCCService0.3.784.0
installer (server PE timestampMay14,2008). Exact June2008 asset distribution
identity remains unproven. Input remains an identified external dependency;
this module does not depend on a private work directory or bundle substitute art.

This is a standalone prerequisite. The passing player and its entity code remain
unchanged. Next integrate measured native Material/Level/TextureProxy ownership
and virtual interfaces, then recovered renderer material creation. P2 remains open.
GPU allocation-downsize recovery is retained from existing source, not exercised
by this ordinary fixture. See work/2008-06/p2-flat-producer/atlas-material-evidence.json.
