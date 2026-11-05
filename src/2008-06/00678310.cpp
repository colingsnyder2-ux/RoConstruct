// from server: 100% by EspClaude
// from server: 76% by colin
// roc 2008-06 00678310  unit: RBX::AdornG3D  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00678310
//
// 00678310  55                   push ebp
// 00678311  8bec                 mov ebp, esp
// 00678313  6aff                 push -1
// 00678315  68c1d07d00           push 0x7dd0c1
// 0067831a  64a100000000         mov eax, dword ptr fs:[0]
// 00678320  50                   push eax
// 00678321  64892500000000       mov dword ptr fs:[0], esp
// 00678328  83ec24               sub esp, 0x24
// 0067832b  53                   push ebx
// 0067832c  33db                 xor ebx, ebx
// 0067832e  56                   push esi
// 0067832f  57                   push edi
// 00678330  895dec               mov dword ptr [ebp - 0x14], ebx
// 00678333  8965f0               mov dword ptr [ebp - 0x10], esp
// 00678336  391d40db9700         cmp dword ptr [0x97db40], ebx
// 0067833c  0f85d4000000         jne 0x678416
// 00678342  8d45d0               lea eax, [ebp - 0x30]
// 00678345  6800d58400           push 0x84d500
// 0067834a  50                   push eax
// 0067834b  895dfc               mov dword ptr [ebp - 4], ebx
// 0067834e  e85d4deeff           call 0x55d0b0
// 00678353  83c408               add esp, 8
// 00678356  50                   push eax
// 00678357  8d4dec               lea ecx, [ebp - 0x14]
// 0067835a  51                   push ecx
// 0067835b  c645fc01             mov byte ptr [ebp - 4], 1
// 0067835f  e8ecf01300           call 0x7b7450
// 00678364  83c408               add esp, 8
// 00678367  8b30                 mov esi, dword ptr [eax]
// 00678369  a140db9700           mov eax, dword ptr [0x97db40]
// 0067836e  c645fc02             mov byte ptr [ebp - 4], 2
// 00678372  3bf0                 cmp esi, eax
// 00678374  7449                 je 0x6783bf
// 00678376  3bc3                 cmp eax, ebx
// 00678378  7431                 je 0x6783ab
// 0067837a  83c004               add eax, 4
// 0067837d  50                   push eax
// 0067837e  ff15ac218000         call dword ptr [0x8021ac]
// 00678384  85c0                 test eax, eax
// 00678386  751d                 jne 0x6783a5
// 00678388  8b0d40db9700         mov ecx, dword ptr [0x97db40]
// 0067838e  e8fd29deff           call 0x45ad90
// 00678393  8b0d40db9700         mov ecx, dword ptr [0x97db40]
// 00678399  3bcb                 cmp ecx, ebx
// 0067839b  7408                 je 0x6783a5
// 0067839d  8b11                 mov edx, dword ptr [ecx]
// 0067839f  8b02                 mov eax, dword ptr [edx]
// 006783a1  6a01                 push 1
// 006783a3  ffd0                 call eax
// 006783a5  891d40db9700         mov dword ptr [0x97db40], ebx
// 006783ab  3bf3                 cmp esi, ebx
// 006783ad  7410                 je 0x6783bf
// 006783af  8d4604               lea eax, [esi + 4]
// 006783b2  50                   push eax
// 006783b3  893540db9700         mov dword ptr [0x97db40], esi
// 006783b9  ff15b0218000         call dword ptr [0x8021b0]
// 006783bf  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006783c2  c645fc01             mov byte ptr [ebp - 4], 1
// 006783c6  3bc3                 cmp eax, ebx
// 006783c8  7428                 je 0x6783f2
// 006783ca  83c004               add eax, 4
// 006783cd  50                   push eax
// 006783ce  ff15ac218000         call dword ptr [0x8021ac]
// 006783d4  85c0                 test eax, eax
// 006783d6  7517                 jne 0x6783ef
// 006783d8  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 006783db  e8b029deff           call 0x45ad90
// 006783e0  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 006783e3  3bcb                 cmp ecx, ebx
// 006783e5  7408                 je 0x6783ef
// 006783e7  8b11                 mov edx, dword ptr [ecx]
// 006783e9  8b02                 mov eax, dword ptr [edx]
// 006783eb  6a01                 push 1
// 006783ed  ffd0                 call eax
// 006783ef  895dec               mov dword ptr [ebp - 0x14], ebx
// 006783f2  8d4dd0               lea ecx, [ebp - 0x30]
// 006783f5  885dfc               mov byte ptr [ebp - 4], bl
// 006783f8  ff1568248000         call dword ptr [0x802468]
// 006783fe  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00678405  eb0f                 jmp 0x678416

#include <string>

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long *);

struct Font {
    virtual ~Font();
    volatile long references;
    void dispose();
};

struct FontRef {
    Font *pointer;
    FontRef() : pointer(0) {}
    FontRef(const FontRef &o) : pointer(0) { setPointer(o.pointer); }
    void setPointer(Font *x);
    __forceinline void zap()
    {
        if (pointer) {
            if (InterlockedDecrement(&pointer->references) == 0) {
                pointer->dispose();
                delete pointer;
            }
            pointer = 0;
        }
    }
    __forceinline FontRef &operator=(const FontRef &o)
    {
        Font *x = o.pointer;
        if (x != pointer) {
            zap();
            if (x) {
                volatile long *r = &x->references;
                pointer = x;
                InterlockedIncrement(r);
            }
        }
        return *this;
    }
    ~FontRef() { zap(); }
};

static FontRef font;
extern std::string __cdecl makeString(const char *);
extern FontRef __cdecl loadFont(const std::string &);

FontRef __cdecl getFont()
{
    if (!font.pointer) {
        try {
            font = loadFont(makeString("Fonts\\comics.fnt"));
        }
        catch (...) {
        }
    }
    return font;
}
