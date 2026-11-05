// from server: 100% by nuck16
// from server: 93% by atomic.potato
// roc 2009-12 00657d00  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00657d00
//
// 00657d00  56                   push esi
// 00657d01  8b742408             mov esi, dword ptr [esp + 8]
// 00657d05  56                   push esi
// 00657d06  81c140ffffff         add ecx, 0xffffff40
// 00657d0c  e85f590700           call 0x6cd670
// 00657d11  8bc6                 mov eax, esi
// 00657d13  5e                   pop esi
// 00657d14  c20400               ret 4

struct Callee_006cd670
{
    void g(void *p);
};

struct S_func_00657d00
{
    void *f(void *a1);
};

void *S_func_00657d00::f(void *a1)
{
    ((Callee_006cd670 *)((char *)this - 192))->g(a1);
    return a1;
}
