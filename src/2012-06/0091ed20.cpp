// from server: 96% by atomic.potato
// roc 2012-06 0091ed20  unit: RBX::FilterInvisibleNonColliding  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091ed20
//
// 0091ed20  8b442404             mov eax, dword ptr [esp + 4]
// 0091ed24  50                   push eax
// 0091ed25  e8d625e3ff           call 0x751300
// 0091ed2a  33c9                 xor ecx, ecx
// 0091ed2c  83c404               add esp, 4
// 0091ed2f  3888b0010000         cmp byte ptr [eax + 0x1b0], cl
// 0091ed35  0f94c1               sete cl
// 0091ed38  8ac1                 mov al, cl
// 0091ed3a  c3                   ret

extern "C" void* __cdecl sub_751300(void*);

struct S {
    char pad[0x1b0];
    char flag;
    bool __cdecl f(void*);
};

bool __cdecl S::f(void* a) {
    S* p = (S*)sub_751300(a);
    return p->flag == 0;
}
