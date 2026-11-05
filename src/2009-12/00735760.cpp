// from server: 100% by nuck16
// roc 2009-12 00735760  unit: RBX::BodyForce  size: 62 bytes
//
// 00735760  c7013c0d9e00         mov dword ptr [ecx], 0x9e0d3c
// 00735766  c74104300d9e00       mov dword ptr [ecx + 4], 0x9e0d30
// 0073576d  c74118240d9e00       mov dword ptr [ecx + 0x18], 0x9e0d24
// 00735774  c7411c1c0d9e00       mov dword ptr [ecx + 0x1c], 0x9e0d1c
// 0073577b  c78194000000d40c9e00 mov dword ptr [ecx + 0x94], 0x9e0cd4
// 00735785  c781b4000000b40c9e00 mov dword ptr [ecx + 0xb4], 0x9e0cb4
// 0073578f  c7812c010000980c9e00 mov dword ptr [ecx + 0x12c], 0x9e0c98
// 00735799  e942fdffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e0d3c;
    *(int *)((char *)this + 0x4) = 0x9e0d30;
    *(int *)((char *)this + 0x18) = 0x9e0d24;
    *(int *)((char *)this + 0x1c) = 0x9e0d1c;
    *(int *)((char *)this + 0x94) = 0x9e0cd4;
    *(int *)((char *)this + 0xb4) = 0x9e0cb4;
    *(int *)((char *)this + 0x12c) = 0x9e0c98;
    func_7354e0();
}
