// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-cl: 21022
// from server: 100% by king_originala
// roc 2008-06 004adb20  unit: RBX::Network::Replicator::ChangePropertyItem  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004adb20
//
// 004adb20  83ec30               sub esp, 0x30
// 004adb23  8d0c24               lea ecx, [esp]
// 004adb26  e8a5a7fcff           call 0x4782d0
// 004adb2b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004adb2f  8d0424               lea eax, [esp]
// 004adb32  50                   push eax
// 004adb33  51                   push ecx
// 004adb34  e84790ffff           call 0x4a6b80
// 004adb39  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004adb3d  83c408               add esp, 8
// 004adb40  83790400             cmp dword ptr [ecx + 4], 0
// 004adb44  7409                 je 0x4adb4f
// 004adb46  8d1424               lea edx, [esp]
// 004adb49  52                   push edx
// 004adb4a  e811f8ffff           call 0x4ad360
// 004adb4f  83c430               add esp, 0x30
// 004adb52  c3                   ret 

struct Temporary
{
    char storage[48];
    void initialize();
};

struct Destination
{
    int reserved;
    int active;
    void apply(Temporary*);
};

void __cdecl process(void*, Temporary*);

void __cdecl reconstruct(Destination* destination, void* source)
{
    Temporary temporary;
    temporary.initialize();
    process(source, &temporary);
    destination->apply(&temporary);
}
