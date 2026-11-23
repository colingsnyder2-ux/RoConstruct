// =============================================================================
// VAR.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/include/glg3d/VAR.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

// INFERRED: single 4-byte pointer member, matching +0x00 being a 4-byte ref.

#ifndef GLG3D_VAR_H
#define GLG3D_VAR_H

#include <stddef.h>   // size_t

namespace G3D
{

class VARArea;

class VARAreaRef {
public:
    VARAreaRef() : _p(0) {}
    explicit VARAreaRef(VARArea* p) : _p(p) {}
    VARArea* _p;
};

class VAR {
    VARAreaRef                 area;             // +0x00
    void*                      _pointer;         // +0x04
    size_t                     elementSize;      // +0x08
    int                        numElements;      // +0x0c
    unsigned __int64           generation;       // +0x10
    unsigned int               underlyingRepresentation;  // +0x18 (GLenum)
    size_t                     _maxSize;         // +0x1c
public:
    // INFERRED: out-of-line ctor, body at 0x489470
    VAR();
    // INFERRED: out-of-line dtor, body at 0x502a70 (??1VAR@G3D@@QAE@XZ)
    ~VAR();
};

}   // namespace G3D

#endif
