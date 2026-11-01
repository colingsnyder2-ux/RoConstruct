// from server: 100% by Yeetserama
// roc 2010-06 00465aa0  unit: VCRobloxView::?$VerbBinder  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00465aa0
//
// 00465aa0  6aff                 push -1
// 00465aa2  68c83a9800           push 0x983ac8
// 00465aa7  64a100000000         mov eax, dword ptr fs:[0]
// 00465aad  50                   push eax
// 00465aae  64892500000000       mov dword ptr fs:[0], esp
// 00465ab5  51                   push ecx
// 00465ab6  56                   push esi
// 00465ab7  8bf1                 mov esi, ecx
// 00465ab9  89742404             mov dword ptr [esp + 4], esi
// 00465abd  8d4e58               lea ecx, [esi + 0x58]
// 00465ac0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00465ac8  e8d3340000           call 0x468fa0
// 00465acd  8bce                 mov ecx, esi
// 00465acf  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00465ad7  e896283400           call 0x7a8372
// 00465adc  f644241801           test byte ptr [esp + 0x18], 1
// 00465ae1  7409                 je 0x465aec
// 00465ae3  56                   push esi
// 00465ae4  e8b11e3400           call 0x7a799a
// 00465ae9  83c404               add esp, 4
// 00465aec  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00465af0  8bc6                 mov eax, esi
// 00465af2  5e                   pop esi
// 00465af3  64890d00000000       mov dword ptr fs:[0], ecx
// 00465afa  83c410               add esp, 0x10
// 00465afd  c20400               ret 4
// copied from an identical function in another client (function ?destroy@CWrapperView@@QAEPAXI@Z)

// from server: 100% by king_originala
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