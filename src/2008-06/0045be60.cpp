// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 0045be60  unit: CRobloxWnd  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045be60
//
// 0045be60  56                   push esi
// 0045be61  8bf1                 mov esi, ecx
// 0045be63  837e5c02             cmp dword ptr [esi + 0x5c], 2
// 0045be67  7506                 jne 0x45be6f
// 0045be69  5e                   pop esi
// 0045be6a  e971ffffff           jmp 0x45bde0
// 0045be6f  83beb800000000       cmp dword ptr [esi + 0xb8], 0
// 0045be76  742e                 je 0x45bea6
// 0045be78  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0045be7e  85c9                 test ecx, ecx
// 0045be80  7408                 je 0x45be8a
// 0045be82  8b01                 mov eax, dword ptr [ecx]
// 0045be84  8b10                 mov edx, dword ptr [eax]
// 0045be86  6a01                 push 1
// 0045be88  ffd2                 call edx
// 0045be8a  c786b400000000000000 mov dword ptr [esi + 0xb4], 0
// 0045be94  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0045be9a  85c9                 test ecx, ecx
// 0045be9c  7408                 je 0x45bea6
// 0045be9e  8b01                 mov eax, dword ptr [ecx]
// 0045bea0  8b10                 mov edx, dword ptr [eax]
// 0045bea2  6a01                 push 1
// 0045bea4  ffd2                 call edx
// 0045bea6  5e                   pop esi
// 0045bea7  c3                   ret 
#include <intrin.h>

struct Object
{
    virtual ~Object();
};

struct S
{
    char padding0[0x5c];
    int state;
    char padding1[0x54];
    Object* first;
    Object* second;

    void alternate();
    void cleanup();
};

void S::cleanup()
{
    if (state == 2)
    {
        alternate();
        return;
    }

    if (second)
    {
        delete first;
        first = 0;
        _ReadWriteBarrier();
        delete second;
    }
}
