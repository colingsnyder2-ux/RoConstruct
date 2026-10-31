// from server: 97% by EspClaude
// from server: 100% by tester
// roc 2008-06 0045ba10  unit: CRobloxWnd  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045ba10
//
// 0045ba10  6aff                 push -1
// 0045ba12  68c8d37b00           push 0x7bd3c8
// 0045ba17  64a100000000         mov eax, dword ptr fs:[0]
// 0045ba1d  50                   push eax
// 0045ba1e  64892500000000       mov dword ptr fs:[0], esp
// 0045ba25  51                   push ecx
// 0045ba26  56                   push esi
// 0045ba27  8bf1                 mov esi, ecx
// 0045ba29  89742404             mov dword ptr [esp + 4], esi
// 0045ba2d  8d8e38010000         lea ecx, [esi + 0x138]
// 0045ba33  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0045ba3b  ff1568248000         call dword ptr [0x802468]
// 0045ba41  8bce                 mov ecx, esi
// 0045ba43  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0045ba4b  e8f0ea0f00           call 0x55a540
// 0045ba50  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045ba54  5e                   pop esi
// 0045ba55  64890d00000000       mov dword ptr fs:[0], ecx
// 0045ba5c  83c410               add esp, 0x10
// 0045ba5f  c3                   ret 

struct String;
extern void (__thiscall *string_destroy)(String *);

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    string_destroy(this);
}

struct Base
{
    char storage[0x138];
    ~Base();
};

struct S : Base
{
    String value;
    ~S();
};

S::~S()
{
}
