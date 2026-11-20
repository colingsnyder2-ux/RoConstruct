// INFERRED: single 4-byte pointer member, matching +0x00 being a 4-byte ref.

#ifndef GLG3D_VAR_H
#define GLG3D_VAR_H

#include <stddef.h>   // size_t

namespace G3D {

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
