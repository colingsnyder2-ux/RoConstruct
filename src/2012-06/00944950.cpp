// from server: 100% by Xemicl
// roc 2012-06 00944950  unit: RBX::ChatWidget  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00944950
//
// 00944950  6aff                 push -1
// 00944952  687810ad00           push 0xad1078
// 00944957  64a100000000         mov eax, dword ptr fs:[0]
// 0094495d  50                   push eax
// 0094495e  64892500000000       mov dword ptr fs:[0], esp
// 00944965  51                   push ecx
// 00944966  56                   push esi
// 00944967  8bf1                 mov esi, ecx
// 00944969  89742404             mov dword ptr [esp + 4], esi
// 0094496d  8d8e98000000         lea ecx, [esi + 0x98]
// 00944973  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0094497b  ff153c26b200         call dword ptr [0xb2263c]
// 00944981  8bce                 mov ecx, esi
// 00944983  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0094498b  e8e079d8ff           call 0x6cc370
// 00944990  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00944994  5e                   pop esi
// 00944995  64890d00000000       mov dword ptr fs:[0], ecx
// 0094499c  83c410               add esp, 0x10
// 0094499f  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000003@@QAE@XZ)

namespace ns_ROCX000003 {
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
    char storage[0x98];
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
}
