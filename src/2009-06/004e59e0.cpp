// from server: 100% by EspClaude
// roc 2009-06 004e59e0  unit: CRobloxWnd::UserInputJob  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e59e0
//
// 004e59e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e59e4  83ec0c               sub esp, 0xc
// 004e59e7  8d0424               lea eax, [esp]
// 004e59ea  50                   push eax
// 004e59eb  51                   push ecx
// 004e59ec  e89f82ffff           call 0x4ddc90
// 004e59f1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e59f5  83c408               add esp, 8
// 004e59f8  83790400             cmp dword ptr [ecx + 4], 0
// 004e59fc  7409                 je 0x4e5a07
// 004e59fe  8d1424               lea edx, [esp]
// 004e5a01  52                   push edx
// 004e5a02  e829f7ffff           call 0x4e5130
// 004e5a07  83c40c               add esp, 0xc
// 004e5a0a  c3                   ret 
// copied from an identical function in another client (function ?function@ns_ROCX0000a6@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000a6 {
struct Value {
    unsigned int words[3];
};

struct S {
    unsigned int reserved;
    unsigned int count;
    void apply(Value*);
};

extern void __cdecl prepare(void*, Value*);

void __cdecl function(S* object, void* source)
{
    Value value;
    prepare(source, &value);
    if (object->count != 0)
        object->apply(&value);
}
}
