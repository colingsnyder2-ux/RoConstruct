// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/g3d-6.09/include
// Humanoid state physics constants that native Humanoid drafts reference by name but no linked object defined (zero
// stubs: a character could not walk, turn or jump; gemini dossier sections 17/19). The 2008-06 original code uses the
// values as literals (no registry address for these names). INFERRED values: donor tools/rbxgs
// Client/App/humanoid/{Flying,Jumping,Running}.cpp lines 9-19 (same in tools/openrbx). Class bodies here declare only
// the statics (private, matching the referenced spellings ?x@Running@RBX@@0MB).
#include "G3D/Vector3.h"

namespace RBX
{
    class Flying { static const float turnSpeed, kTurnP, kTurnAccelMax; };
    class Jumping { static const float kJumpP, jumpVelocityGrid; };
    class Running
    {
        static const float manualTurnSpeed, autoTurnSpeed, kTurnP, kTurnAccelMax, kMoveP, kAltitudeP, kAltitudeD;
        static const G3D::Vector3 maxMoveAccelerationGrid;
    };
    const float Flying::turnSpeed = 6.0f;
    const float Flying::kTurnP = 7500.0f;
    const float Flying::kTurnAccelMax = 120000.0f;
    const float Jumping::kJumpP = 5000.0f;
    const float Jumping::jumpVelocityGrid = 50.0f;
    const float Running::manualTurnSpeed = 4.0f;
    const float Running::autoTurnSpeed = 8.0f;
    const float Running::kTurnP = 7500.0f;
    const float Running::kTurnAccelMax = 160000.0f;
    const float Running::kMoveP = 1250.0f;
    const float Running::kAltitudeP = 10000.0f;
    const float Running::kAltitudeD = 1250.0f;
    const G3D::Vector3 Running::maxMoveAccelerationGrid(1000.0f, 10000.0f, 200.0f);
}
