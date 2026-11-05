// from server: 100% by Yeetserama
// roc 2009-06 00704fe0  unit: RBX::AdornG3D  size: 300 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00704fe0
//
// 00704fe0  55                   push ebp
// 00704fe1  8bec                 mov ebp, esp
// 00704fe3  6aff                 push -1
// 00704fe5  6801328700           push 0x873201
// 00704fea  64a100000000         mov eax, dword ptr fs:[0]
// 00704ff0  50                   push eax
// 00704ff1  64892500000000       mov dword ptr fs:[0], esp
// 00704ff8  83ec24               sub esp, 0x24
// 00704ffb  53                   push ebx
// 00704ffc  33db                 xor ebx, ebx
// 00704ffe  56                   push esi
// 00704fff  57                   push edi
// 00705000  895dec               mov dword ptr [ebp - 0x14], ebx
// 00705003  8965f0               mov dword ptr [ebp - 0x10], esp
// 00705006  391da404a500         cmp dword ptr [0xa504a4], ebx
// 0070500c  0f85d4000000         jne 0x7050e6
// 00705012  8d45d0               lea eax, [ebp - 0x30]
// 00705015  6824ee8e00           push 0x8eee24
// 0070501a  50                   push eax
// 0070501b  895dfc               mov dword ptr [ebp - 4], ebx
// 0070501e  e83d58edff           call 0x5da860
// 00705023  83c408               add esp, 8
// 00705026  50                   push eax
// 00705027  8d4dec               lea ecx, [ebp - 0x14]
// 0070502a  51                   push ecx
// 0070502b  c645fc01             mov byte ptr [ebp - 4], 1
// 0070502f  e88c2c1400           call 0x847cc0
// 00705034  83c408               add esp, 8
// 00705037  8b30                 mov esi, dword ptr [eax]
// 00705039  a1a404a500           mov eax, dword ptr [0xa504a4]
// 0070503e  c645fc02             mov byte ptr [ebp - 4], 2
// 00705042  3bf0                 cmp esi, eax
// 00705044  7449                 je 0x70508f
// 00705046  3bc3                 cmp eax, ebx
// 00705048  7431                 je 0x70507b
// 0070504a  83c004               add eax, 4
// 0070504d  50                   push eax
// 0070504e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00705054  85c0                 test eax, eax
// 00705056  751d                 jne 0x705075
// 00705058  8b0da404a500         mov ecx, dword ptr [0xa504a4]
// 0070505e  e81dfdd3ff           call 0x444d80
// 00705063  8b0da404a500         mov ecx, dword ptr [0xa504a4]
// 00705069  3bcb                 cmp ecx, ebx
// 0070506b  7408                 je 0x705075
// 0070506d  8b11                 mov edx, dword ptr [ecx]
// 0070506f  8b02                 mov eax, dword ptr [edx]
// 00705071  6a01                 push 1
// 00705073  ffd0                 call eax
// 00705075  891da404a500         mov dword ptr [0xa504a4], ebx
// 0070507b  3bf3                 cmp esi, ebx
// 0070507d  7410                 je 0x70508f
// 0070507f  8d4604               lea eax, [esi + 4]
// 00705082  50                   push eax
// 00705083  8935a404a500         mov dword ptr [0xa504a4], esi
// 00705089  ff15d0e18900         call dword ptr [0x89e1d0]
// 0070508f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00705092  c645fc01             mov byte ptr [ebp - 4], 1
// 00705096  3bc3                 cmp eax, ebx
// 00705098  7428                 je 0x7050c2
// 0070509a  83c004               add eax, 4
// 0070509d  50                   push eax
// 0070509e  ff15a4e18900         call dword ptr [0x89e1a4]
// 007050a4  85c0                 test eax, eax
// 007050a6  7517                 jne 0x7050bf
// 007050a8  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007050ab  e8d0fcd3ff           call 0x444d80
// 007050b0  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007050b3  3bcb                 cmp ecx, ebx
// 007050b5  7408                 je 0x7050bf
// 007050b7  8b11                 mov edx, dword ptr [ecx]
// 007050b9  8b02                 mov eax, dword ptr [edx]
// 007050bb  6a01                 push 1
// 007050bd  ffd0                 call eax
// 007050bf  895dec               mov dword ptr [ebp - 0x14], ebx
// 007050c2  8d4dd0               lea ecx, [ebp - 0x30]
// 007050c5  885dfc               mov byte ptr [ebp - 4], bl
// 007050c8  ff15c4e48900         call dword ptr [0x89e4c4]
// 007050ce  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 007050d5  eb0f                 jmp 0x7050e6
// 007050d7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 007050de  b8e4507000           mov eax, 0x7050e4
// 007050e3  c3                   ret 
// 007050e4  33db                 xor ebx, ebx
// 007050e6  8b7508               mov esi, dword ptr [ebp + 8]
// 007050e9  891e                 mov dword ptr [esi], ebx
// 007050eb  8b0da404a500         mov ecx, dword ptr [0xa504a4]
// 007050f1  51                   push ecx
// 007050f2  8bce                 mov ecx, esi
// 007050f4  e867a7d9ff           call 0x49f860
// 007050f9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007050fc  5f                   pop edi
// 007050fd  8bc6                 mov eax, esi
// 007050ff  5e                   pop esi
// 00705100  64890d00000000       mov dword ptr fs:[0], ecx
// 00705107  5b                   pop ebx
// 00705108  8be5                 mov esp, ebp
// 0070510a  5d                   pop ebp
// 0070510b  c3                   ret 
// copied from an identical function in another client (function ?getFont@@YA?AUFontRef@@XZ)

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