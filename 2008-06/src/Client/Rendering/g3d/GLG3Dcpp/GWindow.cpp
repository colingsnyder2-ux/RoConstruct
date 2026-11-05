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
