// native-flags: /I{headers}/v8world /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ClumpStage recovery, addresses 0064cf10 / 0064cec0 (inactive draft).
// Statement order from the byte-exact analogs src/2008-06/0064cf10.cpp, 0064cec0.cpp.
// The 2008 bodies have no rbx_static_cast assertion, so the downstream stage is reached with a plain
// static_cast<IWorldStage*> rather than the donor IWorldStage::getDownstreamWS() inline.
#include "v8world/ClumpStage.h"
#include "v8world/TreeStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{

	// 0064cf10 - ClumpStage::process(Object*), vftable slot (own-vft tier)
	// Matches roc.check: 100% ?process@ClumpStage@@QAEXPAUObject@@@Z MATCH
	// Source: src/2008-06/0064cf10.cpp - eligibility check before TreeStage::process
	void ClumpStage::sub_0064cf10(Object* object)
	{
		if (!object->parent()) {
			Object* entry = object;
			if (object->eligible())
				collection.insert(entry);
		}
		TreeStage::process(object);
	}

	// 0064cec0 - ClumpStage::process(Object*), vftable slot (own-vft tier)
	// Matches roc.check: 100% ?process@ClumpStage@@QAEXPAUObject@@@Z MATCH
	// Source: src/2008-06/0064cec0.cpp - TreeStage::process before eligibility check
	void ClumpStage::sub_0064cec0(Object* object)
	{
		TreeStage::process(object);
		if (!object->parent()) {
			Object* entry = object;
			if (object->eligible())
				collection.insert(entry);
		}
	}

}