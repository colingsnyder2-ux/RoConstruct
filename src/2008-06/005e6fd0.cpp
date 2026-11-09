// from server: 100% by colin
#include <intrin.h>
// from server: 97% by king_originala
// roc 2008-06 005e6fd0  unit: RBX::Clump  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e6fd0
//
// 005e6fd0  56                   push esi
// 005e6fd1  8bf1                 mov esi, ecx
// 005e6fd3  8b4620               mov eax, dword ptr [esi + 0x20]
// 005e6fd6  57                   push edi
// 005e6fd7  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005e6fdb  3bf8                 cmp edi, eax
// 005e6fdd  745f                 je 0x5e703e
// 005e6fdf  85c0                 test eax, eax
// 005e6fe1  741d                 je 0x5e7000
// 005e6fe3  8d4c240c             lea ecx, [esp + 0xc]
// 005e6fe7  51                   push ecx
// 005e6fe8  83c028               add eax, 0x28
// 005e6feb  50                   push eax
// 005e6fec  89742414             mov dword ptr [esp + 0x14], esi
// 005e6ff0  e80be2ffff           call 0x5e5200
// 005e6ff5  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e6ff8  83c408               add esp, 8
// 005e6ffb  e8a0f2ffff           call 0x5e62a0
// 005e7000  897e20               mov dword ptr [esi + 0x20], edi
// 005e7003  85ff                 test edi, edi
// 005e7005  7408                 je 0x5e700f
// 005e7007  56                   push esi
// 005e7008  8bcf                 mov ecx, edi
// 005e700a  e861ffffff           call 0x5e6f70
// 005e700f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e7012  85c9                 test ecx, ecx
// 005e7014  7407                 je 0x5e701d
// 005e7016  e855f0ffff           call 0x5e6070
// 005e701b  eb02                 jmp 0x5e701f
// 005e701d  8bc6                 mov eax, esi
// 005e701f  50                   push eax
// 005e7020  8bce                 mov ecx, esi
// 005e7022  e819f2ffff           call 0x5e6240
// 005e7027  b001                 mov al, 1
// 005e7029  884614               mov byte ptr [esi + 0x14], al
// 005e702c  884654               mov byte ptr [esi + 0x54], al
// 005e702f  884669               mov byte ptr [esi + 0x69], al
// 005e7032  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e7035  85c9                 test ecx, ecx
// 005e7037  7405                 je 0x5e703e
// 005e7039  e862f2ffff           call 0x5e62a0
// 005e703e  5f                   pop edi
// 005e703f  5e                   pop esi
// 005e7040  c20400               ret 4

struct S;
extern void __cdecl removeChild(void*, S**);

struct S {
    char pad00[0x14];
    bool dirty14;
    char pad15[0x0B];
    S* parent;
    char pad24[4];
    char children[0x2C];
    bool dirty54;
    char pad55[0x14];
    bool dirty69;

    void setParent(S*);
    void changed();
    void addChild(S*);
    S* root();
    void setRoot(S*);
};

void S::setParent(S* p)
{
    S* newParent = p;
    if (newParent != parent) {
        if (parent) {
            p = this;
            removeChild(parent->children, &p);
            parent->changed();
        }
        parent = newParent;
        if (newParent)
            newParent->addChild(this);

        S* r;
        if (parent)
            r = parent->root();
        else
            r = this;
        setRoot(r);

        dirty14 = true;
        dirty54 = true;
        dirty69 = true;
        _ReadWriteBarrier();

        if (parent)
            parent->changed();
    }
}
