// from server: 100% by Xemicl
// from server: 100% by Intel
// roc 2012-06 008ce7f0  unit: RBX::VBodyPosition::?$FactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008ce7f0
//
// 008ce7f0  c7019489be00         mov dword ptr [ecx], 0xbe8994
// 008ce7f6  c741048c89be00       mov dword ptr [ecx + 4], 0xbe898c
// 008ce7fd  c741188089be00       mov dword ptr [ecx + 0x18], 0xbe8980
// 008ce804  c7411c7489be00       mov dword ptr [ecx + 0x1c], 0xbe8974
// 008ce80b  c781800000002489be00 mov dword ptr [ecx + 0x80], 0xbe8924
// 008ce815  c7819c0000000489be00 mov dword ptr [ecx + 0x9c], 0xbe8904
// 008ce81f  c78114010000e888be00 mov dword ptr [ecx + 0x114], 0xbe88e8
// 008ce829  e902e4ffff           jmp 0x8ccc30

struct VBodyPositionFactoryProduct {
    void initialize();
};

extern "C" void __stdcall sub_8CCC30();

void VBodyPositionFactoryProduct::initialize() {
    *(int*)this = 0xBE8994;
    *(int*)((char*)this + 4) = 0xBE898C;
    *(int*)((char*)this + 0x18) = 0xBE8980;
    *(int*)((char*)this + 0x1C) = 0xBE8974;
    *(int*)((char*)this + 0x80) = 0xBE8924;
    *(int*)((char*)this + 0x84) = 0xBE8904;
    *(int*)((char*)this + 0xac) = 0xBE88E8;
    sub_8CCC30();
}
