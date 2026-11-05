// from server: 100% by Yeetserama
// roc 2007-08 004277d0  unit: ThreadLogManager  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004277d0
//
// 004277d0  6aff                 push -1
// 004277d2  6868c87300           push 0x73c868
// 004277d7  64a100000000         mov eax, dword ptr fs:[0]
// 004277dd  50                   push eax
// 004277de  83ec14               sub esp, 0x14
// 004277e1  56                   push esi
// 004277e2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004277e7  33c4                 xor eax, esp
// 004277e9  50                   push eax
// 004277ea  8d44241c             lea eax, [esp + 0x1c]
// 004277ee  64a300000000         mov dword ptr fs:[0], eax
// 004277f4  8bf1                 mov esi, ecx
// 004277f6  8b442434             mov eax, dword ptr [esp + 0x34]
// 004277fa  8935e8e28b00         mov dword ptr [0x8be2e8], esi
// 00427800  8986cc070000         mov dword ptr [esi + 0x7cc], eax
// 00427806  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0042780a  8d9608010000         lea edx, [esi + 0x108]
// 00427810  c706b89f7800         mov dword ptr [esi], 0x789fb8
// 00427816  c746040c000000       mov dword ptr [esi + 4], 0xc
// 0042781d  2bd0                 sub edx, eax
// 0042781f  90                   nop 
// 00427820  8a08                 mov cl, byte ptr [eax]
// 00427822  880c02               mov byte ptr [edx + eax], cl
// 00427825  83c001               add eax, 1
// 00427828  84c9                 test cl, cl
// 0042782a  75f4                 jne 0x427820
// 0042782c  8b442430             mov eax, dword ptr [esp + 0x30]
// 00427830  8d5608               lea edx, [esi + 8]
// 00427833  2bd0                 sub edx, eax
// 00427835  8a08                 mov cl, byte ptr [eax]
// 00427837  880c02               mov byte ptr [edx + eax], cl
// 0042783a  83c001               add eax, 1
// 0042783d  84c9                 test cl, cl
// 0042783f  75f4                 jne 0x427835
// 00427841  8d4c2408             lea ecx, [esp + 8]
// 00427845  e8e6ea0300           call 0x466330
// 0042784a  8b0d28988c00         mov ecx, dword ptr [0x8c9828]
// 00427850  51                   push ecx
// 00427851  8d4c240c             lea ecx, [esp + 0xc]
// 00427855  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0042785d  e8beed0300           call 0x466620
// 00427862  8d542434             lea edx, [esp + 0x34]
// 00427866  52                   push edx
// 00427867  8d4c240c             lea ecx, [esp + 0xc]
// 0042786b  e810ed0300           call 0x466580
// 00427870  8d4c2434             lea ecx, [esp + 0x34]
// 00427874  ff1598dd7700         call dword ptr [0x77dd98]
// 0042787a  8d9688000000         lea edx, [esi + 0x88]
// 00427880  8a08                 mov cl, byte ptr [eax]
// 00427882  880a                 mov byte ptr [edx], cl
// 00427884  83c001               add eax, 1
// 00427887  83c201               add edx, 1
// 0042788a  84c9                 test cl, cl
// 0042788c  75f2                 jne 0x427880
// 0042788e  8d4c2434             lea ecx, [esp + 0x34]
// 00427892  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00427898  8d4c2408             lea ecx, [esp + 8]
// 0042789c  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004278a4  e847ed0300           call 0x4665f0
// 004278a9  8bc6                 mov eax, esi
// 004278ab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004278af  64890d00000000       mov dword ptr fs:[0], ecx
// 004278b6  59                   pop ecx
// 004278b7  5e                   pop esi
// 004278b8  83c420               add esp, 0x20
// 004278bb  c20c00               ret 0xc
// copied from an identical function in another client (function ??0ThreadLogManager@ns_ROCX000015@@QAE@PBD0H@Z)

namespace ns_ROCX000015 {
// from server: 100% by king_originala
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
}
