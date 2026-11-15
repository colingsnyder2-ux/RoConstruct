#pragma once
#include "OgreGLSupport.h"
namespace Ogre {
// Implemented by the browser canvas/context platform backend, never GLX/WGL.
GLSupport* getGLSupport();
}
