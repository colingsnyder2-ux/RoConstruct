// from server: 100% by EspClaude
// roc 2009-06 004290b0  unit: CWrapperView  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004290b0
//
// 004290b0  6aff                 push -1
// 004290b2  68b82b8500           push 0x852bb8
// 004290b7  64a100000000         mov eax, dword ptr fs:[0]
// 004290bd  50                   push eax
// 004290be  64892500000000       mov dword ptr fs:[0], esp
// 004290c5  51                   push ecx
// 004290c6  56                   push esi
// 004290c7  8bf1                 mov esi, ecx
// 004290c9  89742404             mov dword ptr [esp + 4], esi
// 004290cd  8d4e58               lea ecx, [esi + 0x58]
// 004290d0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004290d8  e8d38bffff           call 0x421cb0
// 004290dd  8bce                 mov ecx, esi
// 004290df  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004290e7  e81e032f00           call 0x71940a
// 004290ec  f644241801           test byte ptr [esp + 0x18], 1
// 004290f1  7409                 je 0x4290fc
// 004290f3  56                   push esi
// 004290f4  e839f92e00           call 0x718a32
// 004290f9  83c404               add esp, 4
// 004290fc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00429100  8bc6                 mov eax, esi
// 00429102  5e                   pop esi
// 00429103  64890d00000000       mov dword ptr fs:[0], ecx
// 0042910a  83c410               add esp, 0x10
// 0042910d  c20400               ret 4
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