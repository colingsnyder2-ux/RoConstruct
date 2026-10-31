// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 00616180  unit: RBX::ArrowTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00616180
//
// 00616180  8b442404             mov eax, dword ptr [esp + 4]
// 00616184  56                   push esi
// 00616185  68e0be9700           push 0x97bee0
// 0061618a  50                   push eax
// 0061618b  8bf1                 mov esi, ecx
// 0061618d  e8eefeffff           call 0x616080
// 00616192  85c0                 test eax, eax
// 00616194  0f95c1               setne cl
// 00616197  884e1c               mov byte ptr [esi + 0x1c], cl
// 0061619a  5e                   pop esi
// 0061619b  c20400               ret 4

struct S {
    char pad[0x1c];
    bool field_1c;
    void f(const void*);
};

extern "C" void* __stdcall sub_616080(const void*, const void*);

void S::f(const void* a) {
    field_1c = sub_616080(a, (const void*)0x97bee0) != 0;
}
