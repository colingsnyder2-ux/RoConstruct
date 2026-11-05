// roc 2012-06 009d5fe0  unit: CXTPDrawHelpers  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d5fe0
//
// 009d5fe0  8b442404             mov eax, dword ptr [esp + 4]
// 009d5fe4  85c0                 test eax, eax
// 009d5fe6  7416                 je 0x9d5ffe
// 009d5fe8  8b4004               mov eax, dword ptr [eax + 4]
// 009d5feb  50                   push eax
// 009d5fec  e8cfe8ffff           call 0x9d48c0
// 009d5ff1  83c404               add esp, 4
// 009d5ff4  85c0                 test eax, eax
// 009d5ff6  7406                 je 0x9d5ffe
// 009d5ff8  b801000000           mov eax, 1
// 009d5ffd  c3                   ret 
// 009d5ffe  33c0                 xor eax, eax
// 009d6000  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000065@ns_ROCX000065@@YAHPAH@Z)

namespace ns_ROCX000065 {
extern int __cdecl fn_ROCX000065(int);

int fn_ROCX000065(int* p)
{
    if (p)
    {
        if (fn_ROCX000065(p[1]))
            return 1;
    }
    return 0;
}
}
