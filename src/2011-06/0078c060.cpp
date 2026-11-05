// from server: 100% by Yeetserama
// roc 2011-06 0078c060  unit: RBX::HitTestFilter  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078c060
//
// 0078c060  83ec20               sub esp, 0x20
// 0078c063  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0078c067  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0078c06b  56                   push esi
// 0078c06c  50                   push eax
// 0078c06d  51                   push ecx
// 0078c06e  8d542410             lea edx, [esp + 0x10]
// 0078c072  52                   push edx
// 0078c073  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0078c07b  e800ffffff           call 0x78bf80
// 0078c080  8b742434             mov esi, dword ptr [esp + 0x34]
// 0078c084  8d442414             lea eax, [esp + 0x14]
// 0078c088  50                   push eax
// 0078c089  56                   push esi
// 0078c08a  e851fcffff           call 0x78bce0
// 0078c08f  83c414               add esp, 0x14
// 0078c092  8bc6                 mov eax, esi
// 0078c094  5e                   pop esi
// 0078c095  83c420               add esp, 0x20
// 0078c098  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX00000a@@YAPAXPAX00@Z)

namespace ns_ROCX00000a {
// from server: 100% by king_originala
struct Value
{
    char data[28];
};

struct Buffer
{
    volatile int zero;
    Value value;
};

extern "C" void __cdecl build(Value*, void*, void*);
extern "C" void __cdecl copy(void*, const Value*);

void* __cdecl f(void* destination, void* a, void* b)
{
    Buffer buffer;
    buffer.zero = 0;
    build(&buffer.value, a, b);
    copy(destination, &buffer.value);
    return destination;
}
}
