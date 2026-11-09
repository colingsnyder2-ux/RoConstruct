// from server: 100% by EspClaude
// roc 2009-06 0040d170  unit: CNullDoc  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040d170
//
// 0040d170  6aff                 push -1
// 0040d172  687aef8400           push 0x84ef7a
// 0040d177  64a100000000         mov eax, dword ptr fs:[0]
// 0040d17d  50                   push eax
// 0040d17e  64892500000000       mov dword ptr fs:[0], esp
// 0040d185  51                   push ecx
// 0040d186  56                   push esi
// 0040d187  6a58                 push 0x58
// 0040d189  e8aab83000           call 0x718a38
// 0040d18e  8bf0                 mov esi, eax
// 0040d190  83c404               add esp, 4
// 0040d193  89742404             mov dword ptr [esp + 4], esi
// 0040d197  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040d19f  85f6                 test esi, esi
// 0040d1a1  7426                 je 0x40d1c9
// 0040d1a3  8bce                 mov ecx, esi
// 0040d1a5  e888bb3000           call 0x718d32
// 0040d1aa  c706dcdf8a00         mov dword ptr [esi], 0x8adfdc
// 0040d1b0  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0040d1b7  8bc6                 mov eax, esi
// 0040d1b9  5e                   pop esi
// 0040d1ba  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040d1be  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d1c5  83c410               add esp, 0x10
// 0040d1c8  c3                   ret 
// 0040d1c9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040d1cd  33c0                 xor eax, eax
// 0040d1cf  5e                   pop esi
// 0040d1d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d1d7  83c410               add esp, 0x10
// 0040d1da  c3                   ret 
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