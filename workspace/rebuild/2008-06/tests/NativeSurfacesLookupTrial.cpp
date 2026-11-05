#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
namespace RBX {
Surface& Surfaces::operator[](NormalId id) {
 switch (id) {
 case NORM_Y_NEG: return Bottom;
 case NORM_Z: return Back;
 case NORM_Z_NEG: return Front;
 case NORM_X: return Right;
 case NORM_X_NEG: return Left;
 default: return Top;
 }
}
const Surface& Surfaces::operator[](NormalId id) const {
 switch (id) {
 case NORM_Y_NEG: return Bottom;
 case NORM_Z: return Back;
 case NORM_Z_NEG: return Front;
 case NORM_X: return Right;
 case NORM_X_NEG: return Left;
 default: return Top;
 }
}
}
