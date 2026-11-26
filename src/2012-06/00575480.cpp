// from server: 100% by Xemicl
// roc 2012-06 00575480  unit: AsyncResult  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00575480
//
// 00575480  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00575484  83ec0c               sub esp, 0xc
// 00575487  8d0424               lea eax, [esp]
// 0057548a  50                   push eax
// 0057548b  51                   push ecx
// 0057548c  e8ff7dffff           call 0x56d290
// 00575491  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00575495  83c408               add esp, 8
// 00575498  83790400             cmp dword ptr [ecx + 4], 0
// 0057549c  7409                 je 0x5754a7
// 0057549e  8d1424               lea edx, [esp]
// 005754a1  52                   push edx
// 005754a2  e879e4ffff           call 0x573920
// 005754a7  83c40c               add esp, 0xc
// 005754aa  c3                   ret 
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