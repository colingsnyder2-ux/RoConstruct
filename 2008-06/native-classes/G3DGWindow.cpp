// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DGWindow (inactive): upstream tools/libs/g3d-6.09/source/GLG3Dcpp/GWindow.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DGWindow | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8ae8a76f | roc native-status --write
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

namespace G3D {

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
