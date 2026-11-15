#pragma once
// 2008-06 native RBX::Seat (inactive). Shape after the donor tools/rbxgs Seat.h; every base, field and descriptor
// below is read from the 2008-06 binary:
//   RTTI       vtable 00849f74 .?AVSeat@RBX@@ -> DescribedCreatable<Seat, PartInstance, sSeat> (37 bases; name mangled
//              $1?sSeat@2@3PADA, a char array in .data at 00961598), PartInstance's virtual bases IPrimaryPart /
//              ICameraSubject(ILocation) / ISelectable3d through the vbptr at +0x134 (vbase vtables at +0x424/+0x42c/
//              +0x434, vtordisp at +0x420).
//   size       0x43c: Creatable<Instance>::create<Seat> 005c3080 allocates 0x43c and calls 0063d390 with the
//              most-derived flag. PartInstance's non-virtual part ends at +0x3e8 (as for SpawnLocation); Seat's fields
//              fill +0x3e8..+0x420 (the vtordisp thunks subtract 0x38 = 0x420 - 0x3e8, 0063d570/0063d5b0/0063d610).
//   fields     constructor 0063d390: scoped_connection +0x3e8 (connection: shared_ptr +0x3ec/+0x3f0, controlling
//              +0x3f4; released +0x3f8), scoped_connection +0x3fc (+0x400/+0x404, +0x408; +0x40c), double +0x410 = 0.0
//              (fldz), shared_ptr<Weld> +0x418/+0x41c, then setName(sSeat) through PartInstance::setName 00598c20 (the
//              std::string is built from 00961598, the class-name array itself). The destructor 0063d640 releases
//              +0x41c, then ~scoped_connection 005954b0 on +0x3fc and +0x3e8 (declaration order below).
//   use        onServiceProvider 0063d0d0 disconnects +0x3e8 (connection::disconnect 00595230) and connects
//              PartInstance::event_Touched (00976164) to onEvent_seatTouched 0063cf30 into +0x3e8 (scoped_connection
//              assignment 00595540). onEvent_seatTouched compares getLocalTime() - (+0x410) with 3.0 (00828b90),
//              requires +0x418 empty, then connects the Humanoid "Seated"(bool active) signal (SignalDesc 0097a558,
//              initializer 007f6950) to 0063c810 into +0x3fc. 0063c810 runs only for active == false: disconnects
//              +0x3fc, stores getLocalTime() (00508410) in +0x410 and detaches the weld at +0x418 (setParent(0),
//              setPart0(0), setPart1(0), reset). seatCharacter 0063c8a0 creates the weld into +0x418/+0x41c.
//   no descriptors: the unit has no property/function descriptors (only classDescriptor 005c3a40, atexit 007fe6a0).
//   vtable     only slot 12 onServiceProvider 0063d0d0 differs from PartInstance's vtable 00832d4c; the destructor
//              0063d640 does not reset vtables (implicit).
// Blocked: native-headers/v8datamodel/PartInstance.h currently compiles to sizeof 0x2ec (vbases included), not the
// 2008 non-virtual size 0x3e8, so every row that depends on these field offsets or on PartInstance's size is recorded
// as non-exact by tests/record_native_seat.py (see the receipt).
#include "v8datamodel/PartInstance.h"
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>

struct NativeSeatLayout;

namespace RBX
{
	class Weld;
	class Humanoid;

	extern char sSeat[];

	class Seat : public DescribedCreatable<Seat, PartInstance, sSeat>
	{
		friend struct ::NativeSeatLayout; // tests/NativeSeatLayout.cpp offset asserts (pending PartInstance)

	private:
		boost::signals::scoped_connection seatTouched;      // +0x3e8
		boost::signals::scoped_connection humanoidSeated;   // +0x3fc
		double sleepTime;                                   // +0x410 (getLocalTime() when the character left)
		boost::shared_ptr<Weld> weld;                       // +0x418

	private:
		// 0063cf30: bound to PartInstance::event_Touched by onServiceProvider. Not defined here: see the receipt.
		void onEvent_seatTouched(boost::shared_ptr<Instance> other);
		// 0063c810: bound to the Humanoid "Seated" signal (argument "active") by onEvent_seatTouched.
		void onEvent_humanoidSeated(bool active);
		// 0063c8a0 (829 bytes). Not defined here: see the receipt.
		void seatCharacter(Humanoid* humanoid);

	public:
		Seat();                                             // 0063d390

	protected:
		// 0063d0d0: SignalDesc connect 004a3340 with a third argument 10 the donor signal.h lacks. Not defined here.
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
}
