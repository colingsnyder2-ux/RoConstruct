# Default red studded block and period sky

Stage the required images from an owned period Content tree, then build:

```powershell
python rebuild/2008-06/tests/stage_demo_content.py C:\path\to\Content
.\roc.cmd rebuild 2008-06 module p2-recovered-player --no-notify
```

The helper preserves differing existing files and writes a hash manifest beside
the executable. Assets are external inputs, not generated replacements. Local
August2007/May2008 installer copies agree; exact June distribution provenance
remains unproven. Proprietary asset files are not added to this source commit.

Launch P2RecoveredPlayer.exe with no arguments for the red4x1.2x2 anchored block,
TopSurface=Studs and default skybox. Its camera shows the full2x4 stud grid.
Content defaults to the executable's Content directory, independent of cwd.
`--content-root` selects another tree. Existing ROC_TEXTURE_STRIP remains a
developer override for the atlas input. Green `--selftest` remains separate.

`--capture-spin 180` writes180 actual800x600 backbuffer PNGs, one complete turn.
`python rebuild/2008-06/tests/capture_sky_demo.py` records the six-second30fps VP8
video and screenshot, validates six sky directions and missing-file errors,
and saves revision/input/output receipts under work/2008-06/sky-demo.
Encoding uses installed Python OpenCV; normal player launch does not require it.

Sky setup reuses004d9e00's material text (byte-confirmed at00940660), face order
back/front/left/right/up/down, unlit/depth-write-off/clamp state and2700 distance.
An explicit Ogre FileSystem content root replaces the omitted content-service
wrapper, without fabricated Sky/VisualEngine/SceneManager layouts. Custom Sky
ContentIds and online service resolution remain later roadmap work.

The period polar images use a different UV basis from stock Ogre sky planes.
Top needs+90-degree UV rotation, bottom-90; original image bytes stay intact.
Raw image edges establish orientation, and six actual cardinal camera captures
are checked against the expected image rotations. The initial fractional2.5
brick depth cut a partial stud row; the demo now uses whole4x2 stud dimensions.
The first polar rotation attempt used reversed signs; six-view readback exposed
it and the corrected mappings match the source images. These are integration
corrections, not new original-function matching claims.

Missing sky faces fail explicitly instead of silently leaving an untextured
plane. Missing requested place paths also fail, replacing the old fixture
fallback. No P4 completion or full native startup/UI claim is made by this demo.
