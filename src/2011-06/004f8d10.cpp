// from server: 100% by Yeetserama
// roc 2011-06 004f8d10  unit: RBX::Network::Replicator::SendDataJob  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f8d10
//
// 004f8d10  83ec30               sub esp, 0x30
// 004f8d13  8d0c24               lea ecx, [esp]
// 004f8d16  e8758b0400           call 0x541890
// 004f8d1b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004f8d1f  8d0424               lea eax, [esp]
// 004f8d22  50                   push eax
// 004f8d23  51                   push ecx
// 004f8d24  e81781ffff           call 0x4f0e40
// 004f8d29  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004f8d2d  83c408               add esp, 8
// 004f8d30  83790400             cmp dword ptr [ecx + 4], 0
// 004f8d34  7409                 je 0x4f8d3f
// 004f8d36  8d1424               lea edx, [esp]
// 004f8d39  52                   push edx
// 004f8d3a  e811e7ffff           call 0x4f7450
// 004f8d3f  83c430               add esp, 0x30
// 004f8d42  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@ns_ROCX00001d@@YAXPAUDestination@1@PAX@Z)

namespace ns_ROCX00001d {
// from server: 100% by king_originala
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
