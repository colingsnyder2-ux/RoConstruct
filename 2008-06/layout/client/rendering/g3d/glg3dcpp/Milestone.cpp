// =============================================================================
// Milestone.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/Milestone.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\glg3dcpp\\Milestone.cpp"
/**
  @file Milestone.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-08-09
  @edited  2003-08-12
*/

#include "GLG3D/Milestone.h"
#include "GLG3D/RenderDevice.h"

namespace G3D
{

Array<Milestone::GLFence> Milestone::factory;

Milestone::Milestone(const std::string& n) : _name(n), isSet(false) {

    if (glGenFencesNV) {
        if (factory.size() == 0) {
            int num = 10;
            factory.resize(num, DONT_SHRINK_UNDERLYING_ARRAY);
            glGenFencesNV(num, factory.getCArray());
        }

        // Grab a preallocated fence
        glfence = factory.pop();
    }
}

Milestone::~Milestone() {
    if (glDeleteFencesNV) {
        // The global factory might have been deallocated already on shutdown
        if (factory.getCArray() != NULL) {
            // Save it for later
            factory.push(glfence);

            if (factory.size() > 20) {
                // We've deallocated an awful lot, so free some
                glDeleteFencesNV(factory.size() - 5, &(factory.last()) - 5);
                factory.resize(20);
            }

        } else {
            glDeleteFencesNV(1, &glfence);
        }
    }
}

void Milestone::set() {
    if (glSetFenceNV) {
        glSetFenceNV(glfence, GL_ALL_COMPLETED_NV);
    }

    isSet = true;
}

void Milestone::wait() {
    debugAssertM(isSet, std::string("Waiting for a milestone (\"") + _name + "\") that was not set!");

    if (glFinishFenceNV) {
        glFinishFenceNV(glfence);
    } else {
        // With no way of waiting for a specific fence, we must wait for everything.
        glFinish();
    }

    isSet = false;
}

}
