// from server: 100% by Xemicl
// roc 2012-06 00520870  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00520870
//
// 00520870  6aff                 push -1
// 00520872  6878b0aa00           push 0xaab078
// 00520877  64a100000000         mov eax, dword ptr fs:[0]
// 0052087d  50                   push eax
// 0052087e  64892500000000       mov dword ptr fs:[0], esp
// 00520885  51                   push ecx
// 00520886  53                   push ebx
// 00520887  56                   push esi
// 00520888  57                   push edi
// 00520889  8bf9                 mov edi, ecx
// 0052088b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0052088f  8b542428             mov edx, dword ptr [esp + 0x28]
// 00520893  c644240c00           mov byte ptr [esp + 0xc], 0
// 00520898  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052089c  50                   push eax
// 0052089d  51                   push ecx
// 0052089e  83ec10               sub esp, 0x10
// 005208a1  8bf4                 mov esi, esp
// 005208a3  8bc2                 mov eax, edx
// 005208a5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005208ad  89642448             mov dword ptr [esp + 0x48], esp
// 005208b1  895608               mov dword ptr [esi + 8], edx
// 005208b4  c70600000000         mov dword ptr [esi], 0
// 005208ba  83f808               cmp eax, 8
// 005208bd  7708                 ja 0x5208c7
// 005208bf  8bc6                 mov eax, esi
// 005208c1  8d4c2438             lea ecx, [esp + 0x38]
// 005208c5  eb0f                 jmp 0x5208d6
// 005208c7  50                   push eax
// 005208c8  e8231b4600           call 0x9823f0
// 005208cd  8906                 mov dword ptr [esi], eax
// 005208cf  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005208d3  83c404               add esp, 4
// 005208d6  8b5608               mov edx, dword ptr [esi + 8]
// 005208d9  52                   push edx
// 005208da  51                   push ecx
// 005208db  50                   push eax
// 005208dc  e87b2d4600           call 0x98365c
// 005208e1  8b442450             mov eax, dword ptr [esp + 0x50]
// 005208e5  83c40c               add esp, 0xc
// 005208e8  8bcf                 mov ecx, edi
// 005208ea  89460c               mov dword ptr [esi + 0xc], eax
// 005208ed  e86ee7ffff           call 0x51f060
// 005208f2  837c242808           cmp dword ptr [esp + 0x28], 8
// 005208f7  8ad8                 mov bl, al
// 005208f9  7611                 jbe 0x52090c
// 005208fb  8b442420             mov eax, dword ptr [esp + 0x20]
// 005208ff  85c0                 test eax, eax
// 00520901  7409                 je 0x52090c
// 00520903  50                   push eax
// 00520904  e8b11a4600           call 0x9823ba
// 00520909  83c404               add esp, 4
// 0052090c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00520910  5f                   pop edi
// 00520911  5e                   pop esi
// 00520912  8ac3                 mov al, bl
// 00520914  64890d00000000       mov dword ptr fs:[0], ecx
// 0052091b  5b                   pop ebx
// 0052091c  83c410               add esp, 0x10
// 0052091f  c21400               ret 0x14
// copied from an identical function in another client (function ?f@S@@QAE_NUItem@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>
struct Buffer {
    union { char data[8]; char* ptr; };
    unsigned int size;
    Buffer(const Buffer& o) : size(o.size) {
        ptr = 0;
        char* dst;
        const char* src;
        if (size <= 8) { dst = data; src = o.data; }
        else { dst = ptr = (char*)operator new(size); src = o.ptr; }
        memcpy(dst, src, size);
    }
    ~Buffer() { if (size > 8 && ptr) operator delete(ptr); }
};
struct Item {
    Buffer buf;
    int value;
};
struct Flag { bool b; Flag(bool v) : b(v) {} };
struct S {
    bool g(Item item, int a, Flag f);
    bool f(Item item, int a);
};
bool S::f(Item item, int a)
{
    return g(item, a, Flag(false));
}