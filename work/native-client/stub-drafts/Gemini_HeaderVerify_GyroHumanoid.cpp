// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Gyro.h"
#include "v8datamodel/BodyMovers.h"
#include "humanoid/Humanoid.h"
typedef char CheckHumanoidSize[sizeof(RBX::Humanoid) == 0x22c ? 1 : -1];
typedef char CheckRocketSize[sizeof(RBX::Rocket) == 0x190 ? 1 : -1];
typedef char CheckBodyGyroSize[sizeof(RBX::BodyGyro) == 0x18c ? 1 : -1];
int gemini_hdr_verify_anchor() { return sizeof(RBX::Humanoid); }
