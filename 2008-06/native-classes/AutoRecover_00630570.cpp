// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/PartInstance.h"

// INFERRED: SimBody::update is private; declared as an extern "C" fastcall helper (0x00658d20).
extern "C" void __fastcall fn_00658d20(void* self);

namespace RBX {

// INFERRED: the 2008 layout differs from the header, so members are accessed at the raw offsets seen in the disassembly.
// The adjusted 'this' of this override sits 0x130 bytes into the object, so 'force' is at +0x18 and the
// weak_ptr is at +0x10 relative to it. Both are therefore derived from &force.
void BodyForce::computeForce(const float dt, bool throttling)
{
	boost::weak_ptr<Instance>* wp = (boost::weak_ptr<Instance>*)((char*)&force - 8);

	// INFERRED: Instance(+0x2c8) -> primitive, (+0x10) -> world/owner node
	char* node = *(char**)(*(char**)((char*)wp->lock().get() + 0x2c8) + 0x10);

	char* simBody = *(char**)(*(char**)(node + 0x10) + 0x2c);
	if (simBody)
	{
		if (*(char*)(simBody + 8))
			fn_00658d20(simBody);

		float* acc = (float*)(simBody + 0x84);
		acc[0] = force.x + acc[0];
		acc[1] = force.y + acc[1];
		acc[2] = force.z + acc[2];
	}
}

}
