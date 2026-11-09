// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 0044fd30  unit: CRobloxDoc  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fd30
//
// 0044fd30  6aff                 push -1
// 0044fd32  6883177c00           push 0x7c1783
// 0044fd37  64a100000000         mov eax, dword ptr fs:[0]
// 0044fd3d  50                   push eax
// 0044fd3e  64892500000000       mov dword ptr fs:[0], esp
// 0044fd45  81ec38010000         sub esp, 0x138
// 0044fd4b  56                   push esi
// 0044fd4c  8d442404             lea eax, [esp + 4]
// 0044fd50  50                   push eax
// 0044fd51  8bf1                 mov esi, ecx
// 0044fd53  e87863fbff           call 0x4060d0
// 0044fd58  685c798100           push 0x81795c
// 0044fd5d  50                   push eax
// 0044fd5e  8d4c2414             lea ecx, [esp + 0x14]
// 0044fd62  51                   push ecx
// 0044fd63  c784245401000000000000 mov dword ptr [esp + 0x154], 0
// 0044fd6e  e8ede3fbff           call 0x40e160
// 0044fd73  83c410               add esp, 0x10
// 0044fd76  6a00                 push 0
// 0044fd78  8bc8                 mov ecx, eax
// 0044fd7a  c684244801000001     mov byte ptr [esp + 0x148], 1
// 0044fd82  ff15e03e8000         call dword ptr [0x803ee0]
// 0044fd88  50                   push eax
// 0044fd89  6a7b                 push 0x7b
// 0044fd8b  8d4c2418             lea ecx, [esp + 0x18]
// 0044fd8f  e81cf1ffff           call 0x44eeb0
// 0044fd94  8d4c2408             lea ecx, [esp + 8]
// 0044fd98  ff15143f8000         call dword ptr [0x803f14]
// 0044fd9e  8d4c2404             lea ecx, [esp + 4]
// 0044fda2  c684244401000004     mov byte ptr [esp + 0x144], 4
// 0044fdaa  ff15143f8000         call dword ptr [0x803f14]
// 0044fdb0  8b9694000000         mov edx, dword ptr [esi + 0x94]
// 0044fdb6  52                   push edx
// 0044fdb7  8d4c2410             lea ecx, [esp + 0x10]
// 0044fdbb  e8d4152500           call 0x6a1394
// 0044fdc0  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdc4  e8850a2500           call 0x6a084e
// 0044fdc9  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdcd  c7842444010000ffffffff mov dword ptr [esp + 0x144], 0xffffffff
// 0044fdd8  e87312fbff           call 0x401050
// 0044fddd  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 0044fde4  5e                   pop esi
// 0044fde5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fdec  81c444010000         add esp, 0x144
// 0044fdf2  c3                   ret 

// from server: 89% by colin
// roc 2008-06 0044fd30  unit: CRobloxDoc  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fd30
//
// 0044fd30  6aff                 push -1
// 0044fd32  6883177c00           push 0x7c1783
// 0044fd37  64a100000000         mov eax, dword ptr fs:[0]
// 0044fd3d  50                   push eax
// 0044fd3e  64892500000000       mov dword ptr fs:[0], esp
// 0044fd45  81ec38010000         sub esp, 0x138
// 0044fd4b  56                   push esi
// 0044fd4c  8d442404             lea eax, [esp + 4]
// 0044fd50  50                   push eax
// 0044fd51  8bf1                 mov esi, ecx
// 0044fd53  e87863fbff           call 0x4060d0
// 0044fd58  685c798100           push 0x81795c
// 0044fd5d  50                   push eax
// 0044fd5e  8d4c2414             lea ecx, [esp + 0x14]
// 0044fd62  51                   push ecx
// 0044fd63  c784245401000000000000 mov dword ptr [esp + 0x154], 0
// 0044fd6e  e8ede3fbff           call 0x40e160
// 0044fd73  83c410               add esp, 0x10
// 0044fd76  6a00                 push 0
// 0044fd78  8bc8                 mov ecx, eax
// 0044fd7a  c684244801000001     mov byte ptr [esp + 0x148], 1
// 0044fd82  ff15e03e8000         call dword ptr [0x803ee0]
// 0044fd88  50                   push eax
// 0044fd89  6a7b                 push 0x7b
// 0044fd8b  8d4c2418             lea ecx, [esp + 0x18]
// 0044fd8f  e81cf1ffff           call 0x44eeb0
// 0044fd94  8d4c2408             lea ecx, [esp + 8]
// 0044fd98  ff15143f8000         call dword ptr [0x803f14]
// 0044fd9e  8d4c2404             lea ecx, [esp + 4]
// 0044fda2  c684244401000004     mov byte ptr [esp + 0x144], 4
// 0044fdaa  ff15143f8000         call dword ptr [0x803f14]
// 0044fdb0  8b9694000000         mov edx, dword ptr [esi + 0x94]
// 0044fdb6  52                   push edx
// 0044fdb7  8d4c2410             lea ecx, [esp + 0x10]
// 0044fdbb  e8d4152500           call 0x6a1394
// 0044fdc0  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdc4  e8850a2500           call 0x6a084e
// 0044fdc9  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdcd  c7842444010000ffffffff mov dword ptr [esp + 0x144], 0xffffffff
// 0044fdd8  e87312fbff           call 0x401050
// 0044fddd  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 0044fde4  5e                   pop esi
// 0044fde5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fdec  81c444010000         add esp, 0x144
// 0044fdf2  c3                   ret 

// from server: 87% by king_originala
// roc 2008-06 0044fd30  unit: CRobloxDoc  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fd30
//
// 0044fd30  6aff                 push -1
// 0044fd32  6883177c00           push 0x7c1783
// 0044fd37  64a100000000         mov eax, dword ptr fs:[0]
// 0044fd3d  50                   push eax
// 0044fd3e  64892500000000       mov dword ptr fs:[0], esp
// 0044fd45  81ec38010000         sub esp, 0x138
// 0044fd4b  56                   push esi
// 0044fd4c  8d442404             lea eax, [esp + 4]
// 0044fd50  50                   push eax
// 0044fd51  8bf1                 mov esi, ecx
// 0044fd53  e87863fbff           call 0x4060d0
// 0044fd58  685c798100           push 0x81795c
// 0044fd5d  50                   push eax
// 0044fd5e  8d4c2414             lea ecx, [esp + 0x14]
// 0044fd62  51                   push ecx
// 0044fd63  c784245401000000000000 mov dword ptr [esp + 0x154], 0
// 0044fd6e  e8ede3fbff           call 0x40e160
// 0044fd73  83c410               add esp, 0x10
// 0044fd76  6a00                 push 0
// 0044fd78  8bc8                 mov ecx, eax
// 0044fd7a  c684244801000001     mov byte ptr [esp + 0x148], 1
// 0044fd82  ff15e03e8000         call dword ptr [0x803ee0]
// 0044fd88  50                   push eax
// 0044fd89  6a7b                 push 0x7b
// 0044fd8b  8d4c2418             lea ecx, [esp + 0x18]
// 0044fd8f  e81cf1ffff           call 0x44eeb0
// 0044fd94  8d4c2408             lea ecx, [esp + 8]
// 0044fd98  ff15143f8000         call dword ptr [0x803f14]
// 0044fd9e  8d4c2404             lea ecx, [esp + 4]
// 0044fda2  c684244401000004     mov byte ptr [esp + 0x144], 4
// 0044fdaa  ff15143f8000         call dword ptr [0x803f14]
// 0044fdb0  8b9694000000         mov edx, dword ptr [esi + 0x94]
// 0044fdb6  52                   push edx
// 0044fdb7  8d4c2410             lea ecx, [esp + 0x10]
// 0044fdbb  e8d4152500           call 0x6a1394
// 0044fdc0  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdc4  e8850a2500           call 0x6a084e
// 0044fdc9  8d4c240c             lea ecx, [esp + 0xc]
// 0044fdcd  c7842444010000ffffffff mov dword ptr [esp + 0x144], 0xffffffff
// 0044fdd8  e87312fbff           call 0x401050
// 0044fddd  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 0044fde4  5e                   pop esi
// 0044fde5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fdec  81c444010000         add esp, 0x144
// 0044fdf2  c3                   ret 

struct Text;
extern char* (__thiscall *get_buffer)(Text*, int);
extern void (__thiscall *destroy_text)(Text*);

struct Text {
    char storage[4];
    char* buffer(int);
    ~Text();
};

inline char* Text::buffer(int n)
{
    return get_buffer(this, n);
}

inline Text::~Text()
{
    destroy_text(this);
}

struct TextB {
    char storage[4];
    char* buffer(int);
    __declspec(dllimport) ~TextB() throw();
};

inline char* TextB::buffer(int n)
{
    return get_buffer((Text*)this, n);
}

extern Text __cdecl make_exception();
extern TextB __cdecl concatenate(const Text&, const char*);

struct DialogCore {
    char storage[300];
    DialogCore(int, char*);
};

struct Dialog {
    void* header;
    DialogCore core;
    Dialog(int id, char* url) : core(id, url) {}
    void set_owner(void*);
    void run();
    ~Dialog();
};

struct S {
    char padding[156];
    void* owner;
    void report();
};

void S::report()
{
    Dialog dialog(123,
        concatenate(make_exception(), "/AbuseReport/InGameChat.aspx").buffer(0));
    dialog.set_owner(owner);
    dialog.run();
}
