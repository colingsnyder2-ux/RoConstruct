// from server: 88% by atomic.potato
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
// roc 2009-12 0041ad80  unit: CInstanceRecord::CNameItem  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041ad80
//
// 0041ad80  8b01                 mov eax, dword ptr [ecx]
// 0041ad82  8a4904               mov cl, byte ptr [ecx + 4]
// 0041ad85  8808                 mov byte ptr [eax], cl
// 0041ad87  c3                   ret 
// library ??? (function ???)

struct S {
    int f();
};

int S::f() {
    DWORD* eax = (DWORD*)(this);
    unsigned char cl = *(unsigned char*)(this + 4);
    *(unsigned char*)(*eax) = cl;
    return 0;
}
