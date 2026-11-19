// 2008-06 client: minimal G3D::VAR declaration matching the 32-byte binary layout.
//
// Verified against ??0VAR@G3D@@QAE@XZ (0x489470): the ctor zeroes [this, this+0x1c]
// then stores 0x1406 at +0x18 (underlyingRepresentation).  No vptr.
//
//   +0x00 VARAreaRef area            // 4-byte reference into a G3D::VARArea
//   +0x04 void*    _pointer
//   +0x08 size_t   elementSize
//   +0x0c int      numElements
//   +0x10 uint64   generation
//   +0x18 GLenum   underlyingRepresentation   // ctor stores 0x1406 here
//   +0x1c size_t   _maxSize
// sizeof == 0x20 (32 bytes).
//
// ~VAR is declared out of line: the client binary exports ??1VAR@G3D@@QAE@XZ (0x502a70),
// so the destructor is not inline. Declaring it here (without a body) makes MSVC emit
// an out-of-line call from each static-destroy thunk, matching the binary.
//
// G3D::VAR::VAR   -> 0x489470  (zeroes, then underlyingRepresentation = 0x1406)
// G3D::VAR::~VAR  -> 0x502a70  (??1VAR@G3D@@QAE@XZ, folded with zeroPointer/~ReferenceCountedPointer)
// _atexit         -> 0x6a17af
//
// VARAreaRef is a 4-byte reference handle into a G3D::VARArea; the reference count
// lives in the VARArea object itself (G3D::ReferenceCountedObject).  The vendor
// typedef is `ReferenceCountedPointer<class VARArea> VARAreaRef;`; here it is
// represented as a minimal self-contained 4-byte handle so this header compiles
// without pulling in the full vendor dependency tree.
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
