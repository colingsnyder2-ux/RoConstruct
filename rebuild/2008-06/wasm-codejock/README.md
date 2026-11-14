# Codejock toolbar Wasm port

First target: a canvas toolbar executing original Codejock C++ layout, hit-test,
button tracking and theme paint code. No DOM buttons or CSS toolbar. The browser
adapter supplies the Win32 message queue/capture and MFC geometry/DC operations.

The first fixed, caption-button toolbar works. Build and browser interaction
checks pass in Edge: hover, pressed/checked rendering, command dispatch, disabled
buttons, release outside, drag out/back, Escape, focus loss, Enter/Space, arrow
navigation and resize wrapping. No HTML buttons or CSS exist in the demo.

This is a source-level, toolbar-only port, not the complete MFC framework or a
binary-compatible Windows emulator. Original method bodies are selected from the
local XTP 11.2.2 source by `build.py`, hashed in a provenance receipt, and compiled
without rewriting their bodies. Browser declarations expose only this subset.
Unported operations fail explicitly. Generated third-party source stays under
`work/codejock-wasm`; upstream files and the published castle remain untouched.

Acceptance: real Codejock layout and paint execute in Wasm; pointer hover/press,
release outside cancellation, disabled controls, separator groups and resize work;
commands arrive through the compatibility message queue. Keyboard activation is
tested separately. Browser tests must reject any DOM button-based replacement.

Build: `python rebuild/2008-06/wasm-codejock/build.py` (Emscripten 7.0.0).
Serve: `python -m http.server 8877 --directory work/codejock-wasm/site`.
Local URL: http://localhost:8877/.

Browser gate (uses an installed Microsoft Edge):

```powershell
npm install --prefix work/codejock-wasm/browser-test playwright@1.65.1
node rebuild/2008-06/wasm-codejock/test_browser.cjs
```

Evidence: `work/codejock-wasm/build.json`, `browser-test.json`, `provenance.json`,
`toolbar.png`, `pressed.png`, and `site/index.html.symbols`. The build selects 39
original methods plus their layout record. The binary contains the original
`CXTPToolBar::CalcDockingLayout`, `CXTPControls::CalcDynamicSize`,
`CXTPCommandBar::DrawCommandBar` and `CXTPControl::ClickToolBarButton` paths.
Canvas2D implements GDI presentation and browser font measurement; Codejock C++
owns toolbar layout, button face/state painting and press-tracking decisions.
Emscripten Asyncify lets the original nested GetMessage loop await browser input.
Host command handling and window-event routing are browser adaptation code.

Current profile is classic-theme, fixed caption buttons, not P6's full Whidbey
frame. Overflow/customization and popup controls fail explicitly. Original C++
has two non-exhaustive enum-switch compiler warnings; those have not been hidden.

The full Codejock class hierarchy, docking, COM/OLE, image managers, resources,
Windows theming and complete MFC have not been ported. A working toolbar subset
does not establish those capabilities. Source remains local; this change does
not redistribute Codejock sources.
