// from server: 100% by EspClaude
// roc 2009-06 00458b70  unit: VCRobloxView::?$VerbBinder  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00458b70
//
// 00458b70  6aff                 push -1
// 00458b72  68b82b8500           push 0x852bb8
// 00458b77  64a100000000         mov eax, dword ptr fs:[0]
// 00458b7d  50                   push eax
// 00458b7e  64892500000000       mov dword ptr fs:[0], esp
// 00458b85  51                   push ecx
// 00458b86  56                   push esi
// 00458b87  8bf1                 mov esi, ecx
// 00458b89  89742404             mov dword ptr [esp + 4], esi
// 00458b8d  8d4e58               lea ecx, [esi + 0x58]
// 00458b90  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00458b98  e843171900           call 0x5ea2e0
// 00458b9d  8bce                 mov ecx, esi
// 00458b9f  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00458ba7  e85e082c00           call 0x71940a
// 00458bac  f644241801           test byte ptr [esp + 0x18], 1
// 00458bb1  7409                 je 0x458bbc
// 00458bb3  56                   push esi
// 00458bb4  e879fe2b00           call 0x718a32
// 00458bb9  83c404               add esp, 4
// 00458bbc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00458bc0  8bc6                 mov eax, esi
// 00458bc2  5e                   pop esi
// 00458bc3  64890d00000000       mov dword ptr fs:[0], ecx
// 00458bca  83c410               add esp, 0x10
// 00458bcd  c20400               ret 4
// copied from an identical function in another client (function ?destroy@CWrapperView@@QAEPAXI@Z)

void __cdecl operator delete(void*);

struct Base {
    char padding[0x58];
    ~Base();
};

struct Member {
    ~Member();
};

struct BaseCleanup {
    Base* object;
    BaseCleanup(Base* p);
    ~BaseCleanup();
};

inline BaseCleanup::BaseCleanup(Base* p) : object(p)
{
}

inline BaseCleanup::~BaseCleanup()
{
    object->Base::~Base();
}

struct CWrapperView : Base {
    Member member;
    void* destroy(unsigned int flags);
};

void* CWrapperView::destroy(unsigned int flags)
{
    {
        BaseCleanup cleanup(this);
        member.~Member();
    }

    if (flags & 1)
        operator delete(this);

    return this;
}