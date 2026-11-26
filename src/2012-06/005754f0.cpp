// from server: 100% by Xemicl
// roc 2012-06 005754f0  unit: AsyncResult  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005754f0
//
// 005754f0  83ec30               sub esp, 0x30
// 005754f3  8d0c24               lea ecx, [esp]
// 005754f6  e855840b00           call 0x62d950
// 005754fb  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005754ff  8d0424               lea eax, [esp]
// 00575502  50                   push eax
// 00575503  51                   push ecx
// 00575504  e8177bffff           call 0x56d020
// 00575509  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0057550d  83c408               add esp, 8
// 00575510  83790400             cmp dword ptr [ecx + 4], 0
// 00575514  7409                 je 0x57551f
// 00575516  8d1424               lea edx, [esp]
// 00575519  52                   push edx
// 0057551a  e8e1e4ffff           call 0x573a00
// 0057551f  83c430               add esp, 0x30
// 00575522  c3                   ret 
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