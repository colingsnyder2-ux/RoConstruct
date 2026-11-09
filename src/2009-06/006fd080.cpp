// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00670380  unit: RBX::AdornRbxGfx  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670380
//
// 00670380  6aff                 push -1
// 00670382  683bf47b00           push 0x7bf43b
// 00670387  64a100000000         mov eax, dword ptr fs:[0]
// 0067038d  50                   push eax
// 0067038e  64892500000000       mov dword ptr fs:[0], esp
// 00670395  51                   push ecx
// 00670396  6a60                 push 0x60
// 00670398  c744240400000000     mov dword ptr [esp + 4], 0
// 006703a0  e87b050300           call 0x6a0920
// 006703a5  83c404               add esp, 4
// 006703a8  890424               mov dword ptr [esp], eax
// 006703ab  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006703b3  85c0                 test eax, eax
// 006703b5  740e                 je 0x6703c5
// 006703b7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006703bb  51                   push ecx
// 006703bc  8bc8                 mov ecx, eax
// 006703be  e8edfbffff           call 0x66ffb0
// 006703c3  eb02                 jmp 0x6703c7
// 006703c5  33c0                 xor eax, eax
// 006703c7  56                   push esi
// 006703c8  8b742418             mov esi, dword ptr [esp + 0x18]
// 006703cc  50                   push eax
// 006703cd  8bce                 mov ecx, esi
// 006703cf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006703d7  c70600000000         mov dword ptr [esi], 0
// 006703dd  e8be8bf2ff           call 0x598fa0
// 006703e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006703e6  8bc6                 mov eax, esi
// 006703e8  5e                   pop esi
// 006703e9  64890d00000000       mov dword ptr fs:[0], ecx
// 006703f0  83c410               add esp, 0x10
// 006703f3  c20800               ret 8

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String {
    unsigned char data[28];
};

struct Object {
    unsigned char data[104];
    Object(const String&);
};

struct Result {
    Object* value;
    Result(Object*);
    ~Result();
    void reset(Object*);
};

__forceinline Result::Result(Object* p)
{
    value = 0;
    reset(p);
}

Result __stdcall create(const String& str)
{
    return Result(new Object(str));
}
