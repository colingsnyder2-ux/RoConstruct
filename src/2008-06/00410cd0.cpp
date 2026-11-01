// from server: 100% by colin
// from server: 93% by colin
// roc 2008-06 00410c40  unit: CBrowserView  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00410c40
//
// 00410c40  6aff                 push -1
// 00410c42  684ad67b00           push 0x7bd64a
// 00410c47  64a100000000         mov eax, dword ptr fs:[0]
// 00410c4d  50                   push eax
// 00410c4e  64892500000000       mov dword ptr fs:[0], esp
// 00410c55  83ec0c               sub esp, 0xc
// 00410c58  56                   push esi
// 00410c59  8bf1                 mov esi, ecx
// 00410c5b  8974240c             mov dword ptr [esp + 0xc], esi
// 00410c5f  e84cfcffff           call 0x4108b0
// 00410c64  8d442408             lea eax, [esp + 8]
// 00410c68  50                   push eax
// 00410c69  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00410c71  c7066cda8000         mov dword ptr [esi], 0x80da6c
// 00410c77  e85454ffff           call 0x4060d0
// 00410c7c  6858da8000           push 0x80da58
// 00410c81  50                   push eax
// 00410c82  8d4c2410             lea ecx, [esp + 0x10]
// 00410c86  51                   push ecx
// 00410c87  c644242801           mov byte ptr [esp + 0x28], 1
// 00410c8c  e8cfd4ffff           call 0x40e160
// 00410c91  83c410               add esp, 0x10
// 00410c94  50                   push eax
// 00410c95  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 00410c9b  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00410ca0  ff1544318000         call dword ptr [0x803144]
// 00410ca6  8d4c2404             lea ecx, [esp + 4]
// 00410caa  ff15143f8000         call dword ptr [0x803f14]
// 00410cb0  8d4c2408             lea ecx, [esp + 8]
// 00410cb4  ff15143f8000         call dword ptr [0x803f14]
// 00410cba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410cbe  8bc6                 mov eax, esi
// 00410cc0  5e                   pop esi
// 00410cc1  64890d00000000       mov dword ptr fs:[0], ecx
// 00410cc8  83c418               add esp, 0x18
// 00410ccb  c3                   ret 

// from server: 92% by king_originala
// roc 2008-06 00410c40  unit: CBrowserView  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00410c40
//
// 00410c40  6aff                 push -1
// 00410c42  684ad67b00           push 0x7bd64a
// 00410c47  64a100000000         mov eax, dword ptr fs:[0]
// 00410c4d  50                   push eax
// 00410c4e  64892500000000       mov dword ptr fs:[0], esp
// 00410c55  83ec0c               sub esp, 0xc
// 00410c58  56                   push esi
// 00410c59  8bf1                 mov esi, ecx
// 00410c5b  8974240c             mov dword ptr [esp + 0xc], esi
// 00410c5f  e84cfcffff           call 0x4108b0
// 00410c64  8d442408             lea eax, [esp + 8]
// 00410c68  50                   push eax
// 00410c69  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00410c71  c7066cda8000         mov dword ptr [esi], 0x80da6c
// 00410c77  e85454ffff           call 0x4060d0
// 00410c7c  6858da8000           push 0x80da58
// 00410c81  50                   push eax
// 00410c82  8d4c2410             lea ecx, [esp + 0x10]
// 00410c86  51                   push ecx
// 00410c87  c644242801           mov byte ptr [esp + 0x28], 1
// 00410c8c  e8cfd4ffff           call 0x40e160
// 00410c91  83c410               add esp, 0x10
// 00410c94  50                   push eax
// 00410c95  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 00410c9b  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00410ca0  ff1544318000         call dword ptr [0x803144]
// 00410ca6  8d4c2404             lea ecx, [esp + 4]
// 00410caa  ff15143f8000         call dword ptr [0x803f14]
// 00410cb0  8d4c2408             lea ecx, [esp + 8]
// 00410cb4  ff15143f8000         call dword ptr [0x803f14]
// 00410cba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410cbe  8bc6                 mov eax, esi
// 00410cc0  5e                   pop esi
// 00410cc1  64890d00000000       mov dword ptr fs:[0], ecx
// 00410cc8  83c418               add esp, 0x18
// 00410ccb  c3                   ret 

struct String;

typedef void (__thiscall *StringCopy)(String *, const String &);
typedef void (__thiscall *StringDestroy)(String *);

extern StringCopy copyString;
extern StringDestroy destroyString;

struct String {
    void *data;
    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String() throw();
};

struct TemporaryString : String {
    __declspec(dllimport) ~TemporaryString() throw();
};

extern "C" String __cdecl make_exception();
TemporaryString __cdecl concatenate(const String &, const char *);

struct Base {
    char storage[0x2c8];
    Base();
    ~Base();
    virtual void virtualFunction();
};

struct CBrowserView : Base {
    String address;
    CBrowserView();
    virtual void virtualFunction();
};

CBrowserView::CBrowserView()
    : address(concatenate(make_exception(), "/Start.aspx"))
{
}
