// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#undef _RELEASEASSERT
#define NATIVE_IPIPELINED2008_DONOR
#define Body ContactDonorBody
#define SimBody ContactDonorSimBody
#define Cofm ContactDonorCofm
#include "v8world/Edge.h"
#undef Cofm
#undef SimBody
#undef Body
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "tool/RunDragger.h"
namespace RBX {
bool RunDragger::adjacent(Primitive* p0, Primitive* p1)
{
    for (Contact* current = p0->getFirstContact(); current != NULL; current = p0->getNextContact(current)) {
        if (current->otherPrimitive(p0) == p1)
            return current->computeIsAdjacent(0.01f);
    }
    return false;
}
bool RunDragger::tooCloseToCamera()
{
    return (drag->getCoordinateFrame().pointToWorldSpace(dragPointLocal) - mouseRay.origin).magnitude() < 6.0f;
}
bool RunDragger::rayHitsCloserPart()
{
    G3D::Array<Primitive*> ignoreNone;
    SnapInfo answer = rayHitsPart(ignoreNone, false);
    if (answer.snap && answer.snap != snapInfo.snap) {
        if ((answer.hitWorld - mouseRay.origin).magnitude() <
            (snapInfo.hitWorld - mouseRay.origin).magnitude())
            return true;
    }
    return false;
}
}
