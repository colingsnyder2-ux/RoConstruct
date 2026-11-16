// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Surfaces.h"
namespace RBX {
Surfaces::Surfaces(PartInstance* partInstance)
    : Top(partInstance, NORM_Y), Bottom(partInstance, NORM_Y_NEG),
      Left(partInstance, NORM_X_NEG), Right(partInstance, NORM_X),
      Front(partInstance, NORM_Z_NEG), Back(partInstance, NORM_Z) {}
Surface& Surfaces::operator[](NormalId normalId)
{
    switch (normalId) {
    case NORM_Y_NEG: return Bottom;
    case NORM_Z: return Back;
    case NORM_Z_NEG: return Front;
    case NORM_X: return Right;
    case NORM_X_NEG: return Left;
    default: return Top;
    }
}
const Surface& Surfaces::operator[](NormalId normalId) const
{
    switch (normalId) {
    case NORM_Y_NEG: return Bottom;
    case NORM_Z: return Back;
    case NORM_Z_NEG: return Front;
    case NORM_X: return Right;
    case NORM_X_NEG: return Left;
    default: return Top;
    }
}
const bool Surfaces::isStandardPart() const
{
    return Bottom.getSurfaceType() == INLET && Front.getSurfaceType() == NO_SURFACE &&
        Back.getSurfaceType() == NO_SURFACE && Left.getSurfaceType() == NO_SURFACE &&
        Right.getSurfaceType() == NO_SURFACE;
}
}
