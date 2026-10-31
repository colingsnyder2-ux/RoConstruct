// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00427a20  unit: ThreadLogManager  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427a20
//
// 00427a20  64a100000000         mov eax, dword ptr fs:[0]
// 00427a26  6aff                 push -1
// 00427a28  6818f07b00           push 0x7bf018
// 00427a2d  50                   push eax
// 00427a2e  64892500000000       mov dword ptr fs:[0], esp
// 00427a35  8b442418             mov eax, dword ptr [esp + 0x18]
// 00427a39  83ec14               sub esp, 0x14
// 00427a3c  56                   push esi
// 00427a3d  8bf1                 mov esi, ecx
// 00427a3f  8935c0069700         mov dword ptr [0x9706c0], esi
// 00427a45  8986cc070000         mov dword ptr [esi + 0x7cc], eax
// 00427a4b  8b442428             mov eax, dword ptr [esp + 0x28]
// 00427a4f  8d9608010000         lea edx, [esi + 0x108]
// 00427a55  c70620038100         mov dword ptr [esi], 0x810320
// 00427a5b  c746040c000000       mov dword ptr [esi + 4], 0xc
// 00427a62  2bd0                 sub edx, eax
// 00427a64  8a08                 mov cl, byte ptr [eax]
// 00427a66  880c02               mov byte ptr [edx + eax], cl
// 00427a69  40                   inc eax
// 00427a6a  84c9                 test cl, cl
// 00427a6c  75f6                 jne 0x427a64
// 00427a6e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00427a72  8d5608               lea edx, [esi + 8]
// 00427a75  2bd0                 sub edx, eax
// 00427a77  8a08                 mov cl, byte ptr [eax]
// 00427a79  880c02               mov byte ptr [edx + eax], cl
// 00427a7c  40                   inc eax
// 00427a7d  84c9                 test cl, cl
// 00427a7f  75f6                 jne 0x427a77
// 00427a81  8d4c2404             lea ecx, [esp + 4]
// 00427a85  e876270400           call 0x46a200
// 00427a8a  8b0dacf29700         mov ecx, dword ptr [0x97f2ac]
// 00427a90  51                   push ecx
// 00427a91  8d4c2408             lea ecx, [esp + 8]
// 00427a95  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00427a9d  e84e2a0400           call 0x46a4f0
// 00427aa2  8d542430             lea edx, [esp + 0x30]
// 00427aa6  52                   push edx
// 00427aa7  8d4c2408             lea ecx, [esp + 8]
// 00427aab  e890290400           call 0x46a440
// 00427ab0  8d4c2430             lea ecx, [esp + 0x30]
// 00427ab4  ff15e03e8000         call dword ptr [0x803ee0]
// 00427aba  8d9688000000         lea edx, [esi + 0x88]
// 00427ac0  8a08                 mov cl, byte ptr [eax]
// 00427ac2  880a                 mov byte ptr [edx], cl
// 00427ac4  40                   inc eax
// 00427ac5  42                   inc edx
// 00427ac6  84c9                 test cl, cl
// 00427ac8  75f6                 jne 0x427ac0
// 00427aca  8d4c2430             lea ecx, [esp + 0x30]
// 00427ace  ff15143f8000         call dword ptr [0x803f14]
// 00427ad4  8d4c2404             lea ecx, [esp + 4]
// 00427ad8  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00427ae0  e8cb290400           call 0x46a4b0
// 00427ae5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00427ae9  8bc6                 mov eax, esi
// 00427aeb  5e                   pop esi
// 00427aec  64890d00000000       mov dword ptr fs:[0], ecx
// 00427af3  83c420               add esp, 0x20
// 00427af6  c20c00               ret 0xc

extern "C" char * __cdecl strcpy(char *, const char *);

struct TextResult {
    const char *get();
    void release();
};

typedef const char * (__thiscall *GetText)(TextResult *);
typedef void (__thiscall *ReleaseText)(TextResult *);

extern GetText getText;
extern ReleaseText releaseText;

struct Temporary {
    unsigned short m_a;
    unsigned short m_b;
    int m_p;
    int m_x8;
    int m_xc;
    int m_x10;

    Temporary();
    ~Temporary();
    void append(int);
    void result(TextResult *);
};

extern int textSource;
extern unsigned int managerTable;

struct ThreadLogManager {
    unsigned int *table;
    int value;
    char first[128];
    char generated[128];
    char second[128];
    char reserved[0x644];
    int argument;

    ThreadLogManager(const char *, const char *, int);
};

extern ThreadLogManager *currentManager;

ThreadLogManager::ThreadLogManager(
    const char *secondText, const char *firstText, int suppliedArgument)
{
    currentManager = this;
    argument = suppliedArgument;
    table = &managerTable;
    value = 12;

    strcpy(second, secondText);
    strcpy(first, firstText);

    Temporary temporary;
    temporary.append(textSource);
    TextResult *result = reinterpret_cast<TextResult *>(&suppliedArgument);
    temporary.result(result);
    strcpy(generated, getText(result));
    releaseText(result);
}
