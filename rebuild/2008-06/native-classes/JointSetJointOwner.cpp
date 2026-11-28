// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Joint::setJointOwner (inactive). Flags from WorldJoint.cpp (the Joint unit 00645490..00645750) without
// its kernel-stages include path, which this body does not need. WorldJoint.cpp builds on native-headers/v8world/
// Joints2008.h, which does not declare setJointOwner yet (header proposal); its callers (JointInstanceAdorn.cpp) use the
// declaration `void setJointOwner(IJointOwner* value);` of v8world/Joint.h, so the body lives in this small unit on
// that header (the guarded NATIVE_JOINTS_HEADER_DECLARES_SET_JOINT_OWNER copy in WorldJoint.cpp was moved here).
#include "v8world/Joint.h"

namespace RBX
{
	// 006454a0 (registry placeholder func_006454a0, 10 B `mov eax, [esp+4]; mov [ecx+0x20], eax; ret 4`): the jointOwner
	// (+0x20) setter. Callers: JointInstance constructor path 005e393b (setJointOwner(this), IJointOwner base at +0x140)
	// and ~JointInstance 005e2eac (setJointOwner(NULL)); it sits between ~Joint 00645490 and canBuildJoint 006454b0 in
	// the Joint unit.
	void Joint::setJointOwner(IJointOwner* value)
	{
		jointOwner = value;
	}
}
