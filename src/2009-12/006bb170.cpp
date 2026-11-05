// from server: 100% by nuck16
// roc 2009-12 006bb170  unit: RBX::VDecal::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bb170
//
// 006bb170  c701dc669d00         mov dword ptr [ecx], 0x9d66dc
// 006bb176  c74104d0669d00       mov dword ptr [ecx + 4], 0x9d66d0
// 006bb17d  c74118c4669d00       mov dword ptr [ecx + 0x18], 0x9d66c4
// 006bb184  c7411cbc669d00       mov dword ptr [ecx + 0x1c], 0x9d66bc
// 006bb18b  c78194000000a4669d00 mov dword ptr [ecx + 0x94], 0x9d66a4
// 006bb195  e966ffffff           jmp 0x6bb100

extern "C" void func_6bb100();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d66dc;
    *(int *)((char *)this + 0x4) = 0x9d66d0;
    *(int *)((char *)this + 0x18) = 0x9d66c4;
    *(int *)((char *)this + 0x1c) = 0x9d66bc;
    *(int *)((char *)this + 0x94) = 0x9d66a4;
    func_6bb100();
}
