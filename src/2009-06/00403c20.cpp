// from server: 100% by why2
// roc 2009-06 00403c20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403c20
//
// 00403c20  8b01                 mov eax, dword ptr [ecx]
// 00403c22  50                   push eax
// 00403c23  ff15cce98900         call dword ptr [0x89e9cc]
// 00403c29  59                   pop ecx
// 00403c2a  c3                   ret

extern "C" void (__cdecl *free)(void*);

struct S {
    void* p;
    void f();
};

void S::f() {
    free(p);
}
