// from server: 100% by EspClaude
// roc 2009-06 004e5a10  unit: CRobloxWnd::UserInputJob  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5a10
//
// 004e5a10  83ec30               sub esp, 0x30
// 004e5a13  8d0c24               lea ecx, [esp]
// 004e5a16  e8959efbff           call 0x49f8b0
// 004e5a1b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004e5a1f  8d0424               lea eax, [esp]
// 004e5a22  50                   push eax
// 004e5a23  51                   push ecx
// 004e5a24  e81781ffff           call 0x4ddb40
// 004e5a29  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004e5a2d  83c408               add esp, 8
// 004e5a30  83790400             cmp dword ptr [ecx + 4], 0
// 004e5a34  7409                 je 0x4e5a3f
// 004e5a36  8d1424               lea edx, [esp]
// 004e5a39  52                   push edx
// 004e5a3a  e851f7ffff           call 0x4e5190
// 004e5a3f  83c430               add esp, 0x30
// 004e5a42  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@ns_ROCX0000a7@@YAXPAUDestination@1@PAX@Z)

namespace ns_ROCX0000a7 {
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
    if (destination->active != 0)
        destination->apply(&temporary);
}
}
