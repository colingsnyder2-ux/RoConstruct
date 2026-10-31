// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7d00  unit: RBX::LaserTool  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7d00
//
// 005c7d00  6aff                 push -1
// 005c7d02  683bf47b00           push 0x7bf43b
// 005c7d07  64a100000000         mov eax, dword ptr fs:[0]
// 005c7d0d  50                   push eax
// 005c7d0e  64892500000000       mov dword ptr fs:[0], esp
// 005c7d15  51                   push ecx
// 005c7d16  56                   push esi
// 005c7d17  57                   push edi
// 005c7d18  6a38                 push 0x38
// 005c7d1a  8bf9                 mov edi, ecx
// 005c7d1c  e8ff8b0d00           call 0x6a0920
// 005c7d21  8bf0                 mov esi, eax
// 005c7d23  83c404               add esp, 4
// 005c7d26  89742408             mov dword ptr [esp + 8], esi
// 005c7d2a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005c7d32  85f6                 test esi, esi
// 005c7d34  7446                 je 0x5c7d7c
// 005c7d36  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c7d39  50                   push eax
// 005c7d3a  8bce                 mov ecx, esi
// 005c7d3c  e8afdc0400           call 0x6159f0
// 005c7d41  d9ee                 fldz 
// 005c7d43  c706749b8300         mov dword ptr [esi], 0x839b74
// 005c7d49  c74604589b8300       mov dword ptr [esi + 4], 0x839b58
// 005c7d50  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005c7d57  d95620               fst dword ptr [esi + 0x20]
// 005c7d5a  d95624               fst dword ptr [esi + 0x24]
// 005c7d5d  5f                   pop edi
// 005c7d5e  d95628               fst dword ptr [esi + 0x28]
// 005c7d61  8bc6                 mov eax, esi
// 005c7d63  d9562c               fst dword ptr [esi + 0x2c]
// 005c7d66  d95630               fst dword ptr [esi + 0x30]
// 005c7d69  d95e34               fstp dword ptr [esi + 0x34]
// 005c7d6c  5e                   pop esi
// 005c7d6d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c7d71  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7d78  83c410               add esp, 0x10
// 005c7d7b  c3                   ret 
// 005c7d7c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7d80  5f                   pop edi
// 005c7d81  33c0                 xor eax, eax
// 005c7d83  5e                   pop esi
// 005c7d84  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7d8b  83c410               add esp, 0x10
// 005c7d8e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const char cursorTable[];
extern const char cursorSecondaryTable[];

struct Base {
    int data[7];
    int f(int);
};

struct Cursor : Base {
    int state;
    float x, y, z, dx, dy, dz;
    Cursor(int);
};

struct S {
    int reserved[6];
    int value;
    Cursor* f();
};

__forceinline Cursor::Cursor(int a)
{
    Base::f(a);
    *(volatile int*)&data[0] = (int)cursorTable;
    *(volatile int*)&data[1] = (int)cursorSecondaryTable;
    *(volatile int*)&state = 0;
    *(volatile float*)&x = 0.0f;
    *(volatile float*)&y = 0.0f;
    *(volatile float*)&z = 0.0f;
    *(volatile float*)&dx = 0.0f;
    *(volatile float*)&dy = 0.0f;
    *(volatile float*)&dz = 0.0f;
}

Cursor* S::f()
{
    return new Cursor(value);
}
