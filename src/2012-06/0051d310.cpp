// from server: 100% by Xemicl
// roc 2012-06 0051d310  unit: Ogre::istreamDataStream  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051d310
//
// 0051d310  64a100000000         mov eax, dword ptr fs:[0]
// 0051d316  6aff                 push -1
// 0051d318  6878b0aa00           push 0xaab078
// 0051d31d  50                   push eax
// 0051d31e  64892500000000       mov dword ptr fs:[0], esp
// 0051d325  56                   push esi
// 0051d326  8bf1                 mov esi, ecx
// 0051d328  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051d32c  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0051d334  894608               mov dword ptr [esi + 8], eax
// 0051d337  c70600000000         mov dword ptr [esi], 0
// 0051d33d  83f808               cmp eax, 8
// 0051d340  7708                 ja 0x51d34a
// 0051d342  8bc6                 mov eax, esi
// 0051d344  8d4c2414             lea ecx, [esp + 0x14]
// 0051d348  eb0f                 jmp 0x51d359
// 0051d34a  50                   push eax
// 0051d34b  e8a0504600           call 0x9823f0
// 0051d350  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051d354  83c404               add esp, 4
// 0051d357  8906                 mov dword ptr [esi], eax
// 0051d359  8b5608               mov edx, dword ptr [esi + 8]
// 0051d35c  52                   push edx
// 0051d35d  51                   push ecx
// 0051d35e  50                   push eax
// 0051d35f  e8f8624600           call 0x98365c
// 0051d364  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051d368  83c40c               add esp, 0xc
// 0051d36b  837c241c08           cmp dword ptr [esp + 0x1c], 8
// 0051d370  89460c               mov dword ptr [esi + 0xc], eax
// 0051d373  7611                 jbe 0x51d386
// 0051d375  8b442414             mov eax, dword ptr [esp + 0x14]
// 0051d379  85c0                 test eax, eax
// 0051d37b  7409                 je 0x51d386
// 0051d37d  50                   push eax
// 0051d37e  e837504600           call 0x9823ba
// 0051d383  83c404               add esp, 4
// 0051d386  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0051d38a  8bc6                 mov eax, esi
// 0051d38c  64890d00000000       mov dword ptr fs:[0], ecx
// 0051d393  5e                   pop esi
// 0051d394  83c40c               add esp, 0xc
// 0051d397  c21000               ret 0x10
// copied from an identical function in another client (function ??0Item@@QAE@UBuffer@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>
struct Buffer {
    union { char data[8]; char* ptr; };
    unsigned int size;
    char* get() { return size <= 8 ? data : ptr; }
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
    Item(Buffer b, int v);
};
Item::Item(Buffer b, int v) : buf(b), value(v) {}