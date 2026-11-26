// from server: 100% by Xemicl
// roc 2012-06 00415d10  unit: CNullDoc  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415d10
//
// 00415d10  6aff                 push -1
// 00415d12  686a21aa00           push 0xaa216a
// 00415d17  64a100000000         mov eax, dword ptr fs:[0]
// 00415d1d  50                   push eax
// 00415d1e  64892500000000       mov dword ptr fs:[0], esp
// 00415d25  51                   push ecx
// 00415d26  56                   push esi
// 00415d27  6a58                 push 0x58
// 00415d29  e8ecc35600           call 0x98211a
// 00415d2e  8bf0                 mov esi, eax
// 00415d30  83c404               add esp, 4
// 00415d33  89742404             mov dword ptr [esp + 4], esi
// 00415d37  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00415d3f  85f6                 test esi, esi
// 00415d41  7426                 je 0x415d69
// 00415d43  8bce                 mov ecx, esi
// 00415d45  e8b2c65600           call 0x9823fc
// 00415d4a  c7064454b400         mov dword ptr [esi], 0xb45444
// 00415d50  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00415d57  8bc6                 mov eax, esi
// 00415d59  5e                   pop esi
// 00415d5a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00415d5e  64890d00000000       mov dword ptr fs:[0], ecx
// 00415d65  83c410               add esp, 0x10
// 00415d68  c3                   ret 
// 00415d69  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00415d6d  33c0                 xor eax, eax
// 00415d6f  5e                   pop esi
// 00415d70  64890d00000000       mov dword ptr fs:[0], ecx
// 00415d77  83c410               add esp, 0x10
// 00415d7a  c3                   ret 
// copied from an identical function in another client (function ?CreateView@@YAPAUView@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct BaseView {
    BaseView();
    virtual ~BaseView();
    unsigned char storage[0x50];
};

struct View : BaseView {
    View();
    virtual ~View();
    int state;
};

inline View::View() : state(0) {}

View* __cdecl CreateView()
{
    return new View;
}