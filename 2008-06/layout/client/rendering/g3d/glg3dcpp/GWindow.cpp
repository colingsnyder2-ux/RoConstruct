// =============================================================================
// GWindow.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/GWindow.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\glg3dcpp\\GWindow.cpp"
/**
 @file GWindow.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2004-11-16
 @edited  2006-01-16
 */

#include "GLG3D/GWindow.h"
#include "GLG3D/GApp.h"
#include "GLG3D/GLCaps.h"

namespace G3D
{

void GWindow::loadExtensions() {
    GLCaps::init();
}

void GWindow::executeLoopBody() {
    if (notDone()) {
        if (loopBodyStack.last().isGApplet) {
            loopBodyStack.last().applet->oneFrame();
        } else {
            loopBodyStack.last().func(loopBodyStack.last().arg);
        }
    }
}

void GWindow::pushLoopBody(GApplet* applet) {
    loopBodyStack.push(LoopBody(applet));
    applet->beginRun();
}

void GWindow::popLoopBody() {
    if (loopBodyStack.size() > 0) {
        if (loopBodyStack.last().isGApplet) {
            loopBodyStack.last().applet->endRun();
            loopBodyStack.pop();
        }
    }
}

}
