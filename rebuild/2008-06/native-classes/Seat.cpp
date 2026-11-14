// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::Seat (inactive): one original unit (0063c430..0063d710; classDescriptor 005c3a40, doDeclare
// 005bfe90 / callDoDeclare 005c0060, atexit 007fe6a0). Evidence in native-headers/v8datamodel/Seat.h.
// Verified by tests/record_native_seat.py.
// >>> native-status (generated) -- do not edit >>>
// Seat | 2008-06 | 8 byte-exact, inactive (not link-selected)
// 8/8 mapped addresses byte-exact | named 4 | 0 unproved | 1 referenced strings (not rechecked) | by auto (+1)
// <<< native-status | src 51609181 | roc native-status --write
#include "v8datamodel/Seat.h"
#include "v8datamodel/JointInstance.h"
#include <G3D/System.h>

namespace RBX
{
	char sSeat[] = "Seat"; // 00961598 (doDeclare 005bfe90, classDescriptor 005c3a40, Seat::Seat 0063d515)

	// Template members the shared headers only declare (same definitions as SpawnLocation.cpp / Team.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Seat::Seat()
		: sleepTime(0.0)
	{
		setName(sSeat);
	}

	void Seat::onEvent_humanoidSeated(bool active)
	{
		if (!active)
		{
			humanoidSeated.disconnect();
			sleepTime = G3D::System::getLocalTime();
			if (weld)
			{
				weld->setParent(NULL);
				weld->setPart0(NULL);
				weld->setPart1(NULL);
				weld.reset();
			}
		}
	}
}
