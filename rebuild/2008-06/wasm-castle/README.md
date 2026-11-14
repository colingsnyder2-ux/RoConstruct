# Castle Island — browser port

Live demo: https://colingsnyder2-ux.github.io/RoConstruct/castle/

The current floating castle runs as WebAssembly with Ogre 1.4.5 and recovered
RbxSceneManager, RbxEntity, RbxSceneNode, geometry builders, RbxSky and TwoDManager.
The browser adapter replaces Windows context/input and translates legacy GL to
WebGL 2. This is the castle demo, not a complete client or DataModel integration.

The scene now uses half-stud grid blocks, smooth bevel normals, original
`Surfaces.png` stud UVs and the recovered `TextureProxy::shadePixel` tint body.
Original BrickColors provide the palette. Roof tiers are whole plates;
trees occupy separate planters. Visible and shadow geometry use identical cap
triangles, with matching atlas-boundary subdivisions around adjoining faces.
The native mShadowSubMesh path retains closed shadow volumes. Default depth bias
is zero. Generated vertex shaders declare invariant gl_Position to keep transforms
consistent between lit and stencil passes (GLSL ES invariance rules).

The retro toolbar is the separate Codejock Wasm source subset described in
`../wasm-codejock/README.md`, not HTML controls. Live FPS and time appear in its GDI status area. Fullscreen and a real
Codejock scene dropdown are toolbar commands. Windmill Island has a stepped
gable roof, side sheds and spinning lattice sails using native RBX transforms. The surrounding website header/navigation/footer are regular site HTML.

## Play

Desktop browser with WebGL 2 recommended. Drag to orbit; wheel to zoom.
Space: auto-orbit; R: reset; W: wireframe; S: shadows.
P: pause clock; D: resume; T: advance three hours; C: sun/moon view.
A full day takes 90 seconds. Escape stops the demo; reload to restart.
Wireframe requires WEBGL_polygon_mode and may be unavailable on mobile.
Help and camera debug controls have been removed.

## Published files

`castle/index.html`, `index.js`, `index.wasm`, and `index.data` are self-contained.
Serve the repository root with `python -m http.server 8765`, then open
http://localhost:8765/castle/. Direct file:// loading cannot fetch the Wasm assets.
The gh-pages branch preserves the existing site and adds `/castle/` plus a demo link on the homepage.

## Source build

The source checkout needs original Ogre/G3D/Boost inputs under tools/ and the
native castle executable/assets for the one-time frozen reference. These large
external inputs are not installed by this port. Compatibility edits apply only
to generated copies under work/wasm-castle/build, not original recovered sources.

From repository root, with Emscripten SDK installed under tools/emsdk:

```powershell
python tools/emsdk/emsdk.py install 7.0.0
python tools/emsdk/emsdk.py activate 7.0.0
python rebuild/2008-06/wasm-castle/freeze_reference.py
python rebuild/2008-06/wasm-castle/setup_deps.py
python rebuild/2008-06/wasm-castle/build.py --stage core
python rebuild/2008-06/wasm-castle/build.py --stage gl
python rebuild/2008-06/wasm-castle/build.py --stage rbx
python rebuild/2008-06/wasm-castle/build.py --stage support
python rebuild/2008-06/wasm-castle/build.py --stage castle
python -m http.server 8765 --directory work/wasm-castle/site
```

Freeze is one-time and refuses replacement. Build output includes HTML, JS, Wasm
and packed assets. Build receipts are under work/wasm-castle/build. A real Edge
browser smoke check verifies initialization, eight geometry batches, stencil 8,
nonempty rendered image, no JavaScript exceptions and GL error zero. Native
reference and browser screenshots are retained locally. Desktop rendering has
been exercised; broader browser/mobile compatibility is not guaranteed.

Third-party notices accompany the website under castle/licenses/.
