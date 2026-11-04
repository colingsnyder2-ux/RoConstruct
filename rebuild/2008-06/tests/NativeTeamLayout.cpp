// Layout probe for the inactive native Team/Teams headers; tests/record_native_team.py checks each
// function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Team)  0x13c  Creatable<Instance>::create<Team> 00409140 allocates 0x13c
//   sizeof(Teams) 0x138  Creatable<Instance>::create<Teams> 00490450 allocates 0x138
//   Team fields   score +0x130, color +0x134, autoAssignable +0x138, autoColorCharacters +0x139
//                 (constructor 005665e0, getters 00565e30/00565e40/00565e50, BoundProp member 0x139)
//   Teams::teams  +0x130 (constructor 005d6850, getTeams 005d5ed0, onChildAdded 005d6340)
// Field offsets are compile-time asserts (NativeTeamLayout is a friend of both classes).
#include <stddef.h>
#include "v8datamodel/Teams.h"

struct NativeTeamLayout
{
	typedef char Score[offsetof(RBX::Team, score) == 0x130 ? 1 : -1];
	typedef char Color[offsetof(RBX::Team, color) == 0x134 ? 1 : -1];
	typedef char AutoAssignable[offsetof(RBX::Team, autoAssignable) == 0x138 ? 1 : -1];
	typedef char AutoColorCharacters[offsetof(RBX::Team, autoColorCharacters) == 0x139 ? 1 : -1];
	typedef char TeamsList[offsetof(RBX::Teams, teams) == 0x130 ? 1 : -1];
};

size_t nativeTeamSize() { return sizeof(RBX::Team); }
size_t nativeTeamsSize() { return sizeof(RBX::Teams); }
size_t nativeInstanceSize() { return sizeof(RBX::Instance); }
