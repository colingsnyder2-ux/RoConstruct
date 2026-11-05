// roc 2012-06 0085c670  unit: UString_sink::?$stream_buffer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085c670
//
// 0085c670  56                   push esi
// 0085c671  8bf1                 mov esi, ecx
// 0085c673  e808f6ffff           call 0x85bc80
// 0085c678  8b0d9024b200         mov ecx, dword ptr [0xb22490]
// 0085c67e  8d4618               lea eax, [esi + 0x18]
// 0085c681  8908                 mov dword ptr [eax], ecx
// 0085c683  8b159424b200         mov edx, dword ptr [0xb22494]
// 0085c689  50                   push eax
// 0085c68a  8910                 mov dword ptr [eax], edx
// 0085c68c  ff159824b200         call dword ptr [0xb22498]
// 0085c692  83c404               add esp, 4
// 0085c695  5e                   pop esi
// 0085c696  c3                   ret 
// copied from an identical function in another client (function ?func_54d4c0@stream_buffer@ns_ROCX000006@@QAEXXZ)

namespace ns_ROCX000006 {
struct stream_buffer {
    char pad[0x18];
    void* field_18;
    void func_54d4c0();
};

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

void stream_buffer::func_54d4c0()
{
    this->func_54d4c0();
    this->field_18 = g_77e4dc;
    this->field_18 = g_77e4e0;
    g_77e4e4(&this->field_18);
}
}
