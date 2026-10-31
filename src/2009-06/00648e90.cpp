// from server: 100% by EspClaude
// roc 2009-06 00648e90  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00648e90
//
// 00648e90  8b442404             mov eax, dword ptr [esp + 4]
// 00648e94  56                   push esi
// 00648e95  8b7020               mov esi, dword ptr [eax + 0x20]
// 00648e98  8b06                 mov eax, dword ptr [esi]
// 00648e9a  85c0                 test eax, eax
// 00648e9c  7415                 je 0x648eb3
// 00648e9e  50                   push eax
// 00648e9f  e8d0ef0c00           call 0x717e74
// 00648ea4  50                   push eax
// 00648ea5  e806e6ffff           call 0x6474b0
// 00648eaa  83c404               add esp, 4
// 00648ead  c70600000000         mov dword ptr [esi], 0
// 00648eb3  5e                   pop esi
// 00648eb4  c3                   ret 
// copied from an identical function in another client (function ?clear@ns_ROCX00001f@@YAXPAUS@1@@Z)

namespace ns_ROCX00001f {
struct S {
    char padding[32];
    void** value;
};

extern "C" void* __stdcall convert(void*);
extern "C" void __cdecl release(void*);

void __cdecl clear(S* object)
{
    void** value = object->value;
    if (*value) {
        release(convert(*value));
        *value = 0;
    }
}
}
