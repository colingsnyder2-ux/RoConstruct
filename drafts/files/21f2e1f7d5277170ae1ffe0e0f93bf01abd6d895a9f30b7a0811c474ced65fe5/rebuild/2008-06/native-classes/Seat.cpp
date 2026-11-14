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
#include "humanoid/Humanoid.h"
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"
#include "v8world/AssemblyLayout.h" // 2008 Assembly +0x24 root clump / Clump +0x1c root primitive (donor offsets differ)
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

	// 0063c8a0 (829 bytes; donor tools/rbxgs v8datamodel/Seat.cpp seatCharacter plus the 2008 torso placement).
	// PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame ctor 004782d0 / lookAt 00518b90 / operator* 00476700 /
	// inverse 00478330 / toObjectSpace 0060e8f0, Humanoid::getTorsoPrimitive 005d90a0, Primitive::getAssembly 005e7570
	// then the inline root clump (+0x24) root primitive (+0x1c), Primitive::setCoordinateFrame 005e8200 /
	// getCoordinateFrame 005e82c0 / setVelocity 005e7760 with the inline Velocity::zero() static (0097d568, guard
	// 0097d580, Velocity ctor 00614170), Creatable<Instance>::create<Weld> 004b2620, "SeatWeld" 00849cf4, AutoJoint
	// setPart0/setPart1/setC0/setC1 005e4450/005e4470/005e4490/005e44c0, Humanoid::getTorso 005d8b10,
	// Instance::setParent 0055a8f0.
	void Seat::seatCharacter(Humanoid* humanoid)
	{
		G3D::CoordinateFrame seatCoord = getCoordinateFrame(); // INFERRED: copy kept by the target (never read)

		G3D::CoordinateFrame C0;
		C0.lookAt(G3D::Vector3(0.0f, -1.0f, 0.0f), G3D::Vector3(0.0f, 0.0f, -1.0f));
		C0.translation = G3D::Vector3(0.0f, 3.0f, 0.0f);

		G3D::CoordinateFrame C1;
		C1.lookAt(G3D::Vector3(0.0f, -1.0f, 0.0f), G3D::Vector3(0.0f, 0.0f, -1.0f));
		C1.translation = G3D::Vector3(0.0f, 0.6f, 0.0f);

		G3D::CoordinateFrame seatWeld = getCoordinateFrame() * C0;
		G3D::CoordinateFrame torsoCoord = seatWeld * C1.inverse();

		Primitive* torsoPrim = humanoid->getTorsoPrimitive();
		Primitive* root = AssemblyLayout::getRootPrimitive(torsoPrim->getAssembly()); // getRootClump()->getRootPrimitive()
		if (root == torsoPrim)
		{
			torsoPrim->setCoordinateFrame(torsoCoord);
			torsoPrim->setVelocity(Velocity::zero());
		}
		else
		{
			G3D::CoordinateFrame rootOffset = torsoPrim->getCoordinateFrame().toObjectSpace(root->getCoordinateFrame());
			G3D::CoordinateFrame rootCoord = torsoCoord * rootOffset;
			root->setCoordinateFrame(rootCoord);
			root->setVelocity(Velocity::zero());
		}

		// INFERRED: both products are computed and discarded by the target (a compiled-out consistency check).
		G3D::CoordinateFrame seatWeldCoord = getCoordinateFrame() * C0;
		G3D::CoordinateFrame torsoWeldCoord = torsoPrim->getCoordinateFrame() * C1;

		weld = Creatable<Instance>::create<Weld>();
		weld->setName("SeatWeld");
		weld->setPart0(this);
		weld->setPart1(humanoid->getTorso());
		weld->setC0(C0);
		weld->setC1(C1);
		weld->setParent(this);
	}
}
