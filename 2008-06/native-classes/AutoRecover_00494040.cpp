// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided. Instead of hand-writing the thunk, I model the
// layout that makes the compiler emit it: Player has a primary base of 0x14 bytes
// (vptr + 16 bytes) and a second polymorphic base at offset 0x14 with a virtual destructor.
// Player's destructor overrides the second base's, so the compiler generates the
// `vector deleting destructor'`adjustor{20}' thunk (sub ecx,0x14 ; jmp primary) in the vtable.
namespace RBX {
namespace Network {

// INFERRED: placeholder for whatever the real first base is; 4-byte vptr + 16 bytes = 0x14
struct PlayerBase0 {
    virtual ~PlayerBase0();
    char pad[16];
};

// INFERRED: placeholder for the real second base (at offset 0x14) with a virtual destructor
struct PlayerBase1 {
    virtual ~PlayerBase1();
};

class Player : public PlayerBase0, public PlayerBase1 {
public:
    Player();
    virtual ~Player();
};

// Defining the constructor forces the vtable (and its adjustor thunks) to be emitted here.
Player::Player()
{
}

} // namespace Network
} // namespace RBX
