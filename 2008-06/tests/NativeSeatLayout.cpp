// Layout probe for the inactive native Seat header; tests/record_native_seat.py checks each function body is
// `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Instance)  0x130  (Instance constructor 0055b7e0; Seat's Instance-range adjustor thunks 0063d560..0063d630)
// Seat (0x43c, fields +0x3e8..+0x420) is not asserted: the current native PartInstance.h does not have the 2008
// non-virtual size 0x3e8, so its asserts stay behind NATIVE_SEAT_LAYOUT until it does.
#include <stddef.h>
#include "v8datamodel/Seat.h"

struct NativeSeatLayout
{
#ifdef NATIVE_SEAT_LAYOUT
	typedef char SeatTouched[offsetof(RBX::Seat, seatTouched) == 0x3e8 ? 1 : -1];
	typedef char HumanoidSeated[offsetof(RBX::Seat, humanoidSeated) == 0x3fc ? 1 : -1];
	typedef char SleepTime[offsetof(RBX::Seat, sleepTime) == 0x410 ? 1 : -1];
	typedef char Weld[offsetof(RBX::Seat, weld) == 0x418 ? 1 : -1];
	typedef char Size[sizeof(RBX::Seat) == 0x43c ? 1 : -1];
#endif
	static size_t partSize() { return sizeof(RBX::PartInstance); }
};

size_t nativeSeatInstanceSize() { return sizeof(RBX::Instance); }
size_t nativeSeatPartInstanceSize() { return NativeSeatLayout::partSize(); }
size_t nativeSeatSize() { return sizeof(RBX::Seat); }
