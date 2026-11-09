// from server: 100% by EspClaude
// from server: 86% by colin
// roc 2008-06 0044ce70  unit: CRobloxModule  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044ce70
//
// 0044ce70  64a100000000         mov eax, dword ptr fs:[0]
// 0044ce76  6aff                 push -1
// 0044ce78  68eb137c00           push 0x7c13eb
// 0044ce7d  50                   push eax
// 0044ce7e  64892500000000       mov dword ptr fs:[0], esp
// 0044ce85  81ec40010000         sub esp, 0x140
// 0044ce8b  e85093fbff           call 0x4061e0
// 0044ce90  84c0                 test al, al
// 0044ce92  0f8401010000         je 0x44cf99
// 0044ce98  e843adfbff           call 0x407be0
// 0044ce9d  8b8034010000         mov eax, dword ptr [eax + 0x134]
// 0044cea3  83e801               sub eax, 1
// 0044cea6  7473                 je 0x44cf1b
// 0044cea8  83e801               sub eax, 1
// 0044ceab  0f85e8000000         jne 0x44cf99
// 0044ceb1  8d44240c             lea eax, [esp + 0xc]
// 0044ceb5  50                   push eax
// 0044ceb6  e81592fbff           call 0x4060d0
// 0044cebb  68406c8100           push 0x816c40
// 0044cec0  50                   push eax
// 0044cec1  8d4c2410             lea ecx, [esp + 0x10]
// 0044cec5  51                   push ecx
// 0044cec6  c784245801000005000000 mov dword ptr [esp + 0x158], 5
// 0044ced1  e88a12fcff           call 0x40e160
// 0044ced6  83c410               add esp, 0x10
// 0044ced9  8bc8                 mov ecx, eax
// 0044cedb  c684244801000006     mov byte ptr [esp + 0x148], 6
// 0044cee3  ff15e03e8000         call dword ptr [0x803ee0]
// 0044cee9  50                   push eax
// 0044ceea  e8919bfbff           call 0x406a80
// 0044ceef  83c404               add esp, 4
// 0044cef2  8d4c2404             lea ecx, [esp + 4]
// 0044cef6  ff15143f8000         call dword ptr [0x803f14]
// 0044cefc  8d4c240c             lea ecx, [esp + 0xc]
// 0044cf00  ff15143f8000         call dword ptr [0x803f14]
// 0044cf06  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 0044cf0d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cf14  81c44c010000         add esp, 0x14c
// 0044cf1a  c3                   ret 
// 0044cf1b  8d542408             lea edx, [esp + 8]
// 0044cf1f  52                   push edx
// 0044cf20  e8ab91fbff           call 0x4060d0
// 0044cf25  68246c8100           push 0x816c24
// 0044cf2a  50                   push eax
// 0044cf2b  8d44240c             lea eax, [esp + 0xc]
// 0044cf2f  50                   push eax
// 0044cf30  c784245801000000000000 mov dword ptr [esp + 0x158], 0
// 0044cf3b  e82012fcff           call 0x40e160
// 0044cf40  83c410               add esp, 0x10
// 0044cf43  6a00                 push 0
// 0044cf45  8bc8                 mov ecx, eax
// 0044cf47  c684244c01000001     mov byte ptr [esp + 0x14c], 1
// 0044cf4f  ff15e03e8000         call dword ptr [0x803ee0]
// 0044cf55  50                   push eax
// 0044cf56  6a7c                 push 0x7c
// 0044cf58  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cf5c  e84f1f0000           call 0x44eeb0
// 0044cf61  8d0c24               lea ecx, [esp]
// 0044cf64  ff15143f8000         call dword ptr [0x803f14]
// 0044cf6a  8d4c2408             lea ecx, [esp + 8]
// 0044cf6e  c684244801000004     mov byte ptr [esp + 0x148], 4
// 0044cf76  ff15143f8000         call dword ptr [0x803f14]
// 0044cf7c  8d4c2410             lea ecx, [esp + 0x10]
// 0044cf80  e8c9382500           call 0x6a084e
// 0044cf85  8d4c2410             lea ecx, [esp + 0x10]
// 0044cf89  c7842448010000ffffffff mov dword ptr [esp + 0x148], 0xffffffff
// 0044cf94  e8b740fbff           call 0x401050
// 0044cf99  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 0044cfa0  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cfa7  81c44c010000         add esp, 0x14c
// 0044cfad  c3                   ret 

// from server: 79% by king_originala
// roc 2008-06 0044ce70  unit: CRobloxModule  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044ce70
//
// 0044ce70  64a100000000         mov eax, dword ptr fs:[0]
// 0044ce76  6aff                 push -1
// 0044ce78  68eb137c00           push 0x7c13eb
// 0044ce7d  50                   push eax
// 0044ce7e  64892500000000       mov dword ptr fs:[0], esp
// 0044ce85  81ec40010000         sub esp, 0x140
// 0044ce8b  e85093fbff           call 0x4061e0
// 0044ce90  84c0                 test al, al
// 0044ce92  0f8401010000         je 0x44cf99
// 0044ce98  e843adfbff           call 0x407be0
// 0044ce9d  8b8034010000         mov eax, dword ptr [eax + 0x134]
// 0044cea3  83e801               sub eax, 1
// 0044cea6  7473                 je 0x44cf1b
// 0044cea8  83e801               sub eax, 1
// 0044ceab  0f85e8000000         jne 0x44cf99
// 0044ceb1  8d44240c             lea eax, [esp + 0xc]
// 0044ceb5  50                   push eax
// 0044ceb6  e81592fbff           call 0x4060d0
// 0044cebb  68406c8100           push 0x816c40
// 0044cec0  50                   push eax
// 0044cec1  8d4c2410             lea ecx, [esp + 0x10]
// 0044cec5  51                   push ecx
// 0044cec6  c784245801000005000000 mov dword ptr [esp + 0x158], 5
// 0044ced1  e88a12fcff           call 0x40e160
// 0044ced6  83c410               add esp, 0x10
// 0044ced9  8bc8                 mov ecx, eax
// 0044cedb  c684244801000006     mov byte ptr [esp + 0x148], 6
// 0044cee3  ff15e03e8000         call dword ptr [0x803ee0]
// 0044cee9  50                   push eax
// 0044ceea  e8919bfbff           call 0x406a80
// 0044ceef  83c404               add esp, 4
// 0044cef2  8d4c2404             lea ecx, [esp + 4]
// 0044cef6  ff15143f8000         call dword ptr [0x803f14]
// 0044cefc  8d4c240c             lea ecx, [esp + 0xc]
// 0044cf00  ff15143f8000         call dword ptr [0x803f14]
// 0044cf06  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 0044cf0d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cf14  81c44c010000         add esp, 0x14c
// 0044cf1a  c3                   ret 
// 0044cf1b  8d542408             lea edx, [esp + 8]
// 0044cf1f  52                   push edx
// 0044cf20  e8ab91fbff           call 0x4060d0
// 0044cf25  68246c8100           push 0x816c24
// 0044cf2a  50                   push eax
// 0044cf2b  8d44240c             lea eax, [esp + 0xc]
// 0044cf2f  50                   push eax
// 0044cf30  c784245801000000000000 mov dword ptr [esp + 0x158], 0
// 0044cf3b  e82012fcff           call 0x40e160
// 0044cf40  83c410               add esp, 0x10
// 0044cf43  6a00                 push 0
// 0044cf45  8bc8                 mov ecx, eax
// 0044cf47  c684244c01000001     mov byte ptr [esp + 0x14c], 1
// 0044cf4f  ff15e03e8000         call dword ptr [0x803ee0]
// 0044cf55  50                   push eax
// 0044cf56  6a7c                 push 0x7c
// 0044cf58  8d4c241c             lea ecx, [esp + 0x1c]
// 0044cf5c  e84f1f0000           call 0x44eeb0
// 0044cf61  8d0c24               lea ecx, [esp]
// 0044cf64  ff15143f8000         call dword ptr [0x803f14]
// 0044cf6a  8d4c2408             lea ecx, [esp + 8]
// 0044cf6e  c684244801000004     mov byte ptr [esp + 0x148], 4
// 0044cf76  ff15143f8000         call dword ptr [0x803f14]
// 0044cf7c  8d4c2410             lea ecx, [esp + 0x10]
// 0044cf80  e8c9382500           call 0x6a084e
// 0044cf85  8d4c2410             lea ecx, [esp + 0x10]
// 0044cf89  c7842448010000ffffffff mov dword ptr [esp + 0x148], 0xffffffff
// 0044cf94  e8b740fbff           call 0x401050
// 0044cf99  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 0044cfa0  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cfa7  81c44c010000         add esp, 0x14c
// 0044cfad  c3                   ret 

extern "C" bool __stdcall GetState();

struct Configuration
{
    char reserved[0x134];
    int mode;
};

extern Configuration* __cdecl getConfiguration();
extern void __cdecl reportError(const char*);

struct Text;
extern const char* (__thiscall *textData)(const Text*);
extern void (__thiscall *textDestroy)(Text*);

struct Text
{
    void* storage;
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) const char* data() const;
};


struct TextB { void* storage; __declspec(dllimport) ~TextB() throw(); __declspec(dllimport) const char* data() const; };
struct TextC { void* storage; __declspec(dllimport) ~TextC() throw(); __declspec(dllimport) const char* data() const; };
struct TextD { void* storage; __declspec(dllimport) ~TextD() throw(); __declspec(dllimport) const char* data() const; };
extern Text __cdecl make_exception();
extern TextB __cdecl appendText(const Text&, const char*);
extern TextC __cdecl make_exception2();
extern TextD __cdecl appendText2(const TextC&, const char*);
extern const char reportDialogPath[];
extern const char dumpPath[];

struct String
{
    char storage[28];
    ~String();
};

struct Dialog : String
{
    char remaining[276];
    Dialog(int, const char*, int);
    ~Dialog();
    void run();
};

inline Dialog::~Dialog()
{
}

void handleError()
{
    if (GetState())
    {
        switch (getConfiguration()->mode)
        {
        case 1:
            {
                Dialog dialog(124,
                    appendText(make_exception(), reportDialogPath).data(), 0);
                dialog.run();
            }
            break;

        case 2:
            reportError(appendText2(make_exception2(), dumpPath).data());
            break;
        }
    }
}
