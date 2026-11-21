// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::Seat::onEvent_seatTouched 0063cf30 (inactive), the one Seat row Seat.cpp leaves undefined
// (?onEvent_seatTouched@Seat@RBX@@AAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z, registry header-address name; it lies
// inside the Seat unit 0063c430..0063d710 and is bound to PartInstance::event_Touched by onServiceProvider 0063d0d0).
// Flags and includes copied from Seat.cpp (same original unit), except that the Humanoid is the native 2008
// humanoid/Humanoid2008.h: its flag byte is at +0x1e8 as in the target (the non-2008 humanoid/Humanoid.h puts it at
// +0x1e4, measured: the only difference at 0063cfb0).
// No donor body (tools/rbxgs Seat.cpp has none); reconstructed from the target:
//   G3D::System::getLocalTime 00508410 - sleepTime (+0x410) compared with 3.0 (00828b90, `test ah, 0x41`: > 3.0);
//   weld (+0x418) empty; other->getParent() (+0x104) non-null, then Humanoid::modelIsCharacter 005d9a20;
//   getTorso 005d8b10; the flag byte +0x1e8 `test al, 0xa` = imDead (bit 1) | sit (bit 3);
//   Workspace::contextInWorkspace 005a33d0 of the torso, then of the seat; humanoidSeated (+0x3fc)
//   connection::disconnect 00595230; seatCharacter 0063c8a0; Humanoid::setSit(true) 005dc2b0; then
//   Humanoid::event_Seated (0097a558) connect with group 10 (004d8390) of boost::bind(&Seat::onEvent_humanoidSeated,
//   this, _1) (bind 0063c870 with the 12-byte virtual-base member pointer, slot constructor 0063cd90) assigned to
//   humanoidSeated (scoped_connection::operator= 00595540), ~connection 00595370, ~slot 0049f710 (folded).
//
// BLOCKED (header): native-headers/humanoid/Humanoid2008.h keeps imDead private with no accessor. With a scratch copy
// that adds, next to getSit 005d7530,
//     bool getDead() const { return imDead; }   // INFERRED: read by Seat::onEvent_seatTouched 0063cfb0 (+0x1e8 & 0xa)
// this unit is byte-exact for 0063cf30 (415 B), its __ehhandler 007da718, the SignalDesc<Humanoid, void(bool)>
// group connect 004d8390 and 0063cc00 (batch 32). Until the Humanoid2008.h owner adds the accessor (and defines
// HUMANOID_HEADER_DECLARES_GETDEAD, or this guard is removed) the body is kept out of the build.
#include "v8datamodel/Seat.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "humanoid/Humanoid2008.h"
#include <G3D/System.h>
#include <boost/bind.hpp>

#ifdef HUMANOID_HEADER_DECLARES_GETDEAD
namespace RBX
{
	// 0063cf30 ?onEvent_seatTouched@Seat@RBX@@AAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z
	void Seat::onEvent_seatTouched(boost::shared_ptr<Instance> other)
	{
		if (G3D::System::getLocalTime() - sleepTime > 3.0 && !weld)
		{
			if (Instance* parent = other->getParent())
			{
				Humanoid* humanoid = Humanoid::modelIsCharacter(parent);
				if (humanoid && humanoid->getTorso() && !humanoid->getDead() && !humanoid->getSit()
					&& Workspace::contextInWorkspace(humanoid->getTorso()) && Workspace::contextInWorkspace(this))
				{
					humanoidSeated.disconnect();
					seatCharacter(humanoid);
					humanoid->setSit(true);
					humanoidSeated = Humanoid::event_Seated.connect(humanoid, boost::bind(&Seat::onEvent_humanoidSeated, this, _1), 10);
				}
			}
		}
	}
}
#endif
