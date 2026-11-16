// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "util/Profiling.h"
namespace RBX { namespace Profiling {
// 005c3f20: sampleTimeSpan +0, frames +0x10.
double Bucket::getActualFPS() const
{
    return sampleTimeSpan > 0 ? frames / sampleTimeSpan : 0;
}
// 005c3f40: wallTimeSpan +8, frames +0x10.
double Bucket::getNominalFPS() const
{
    return wallTimeSpan > 0 ? frames / wallTimeSpan : 0;
}
// 005c3f60: signed frame count guards wall-time division.
double Bucket::getFrameTime() const
{
    return frames > 0 ? wallTimeSpan / frames : 0;
}
} }
