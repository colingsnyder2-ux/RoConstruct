// from server: 100% by Xemicl
// roc 2012-06 0046cfc0  unit: CRbxPlayDocTemplate  size: 464 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046cfc0
//
// 0046cfc0  6aff                 push -1
// 0046cfc2  68c0fea900           push 0xa9fec0
// 0046cfc7  64a100000000         mov eax, dword ptr fs:[0]
// 0046cfcd  50                   push eax
// 0046cfce  64892500000000       mov dword ptr fs:[0], esp
// 0046cfd5  83ec08               sub esp, 8
// 0046cfd8  53                   push ebx
// 0046cfd9  55                   push ebp
// 0046cfda  56                   push esi
// 0046cfdb  57                   push edi
// 0046cfdc  8bf9                 mov edi, ecx
// 0046cfde  897c2410             mov dword ptr [esp + 0x10], edi
// 0046cfe2  e8c15c5100           call 0x982ca8
// 0046cfe7  6898000000           push 0x98
// 0046cfec  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046cff4  c7076498b500         mov dword ptr [edi], 0xb59864
// 0046cffa  e81b515100           call 0x98211a
// 0046cfff  8bf0                 mov esi, eax
// 0046d001  83c404               add esp, 4
// 0046d004  89742414             mov dword ptr [esp + 0x14], esi
// 0046d008  c644242001           mov byte ptr [esp + 0x20], 1
// 0046d00d  85f6                 test esi, esi
// 0046d00f  744e                 je 0x46d05f
// 0046d011  807c242800           cmp byte ptr [esp + 0x28], 0
// 0046d016  7407                 je 0x46d01f
// 0046d018  e823200200           call 0x48f040
// 0046d01d  eb05                 jmp 0x46d024
// 0046d01f  e89c550200           call 0x4925c0
// 0046d024  8be8                 mov ebp, eax
// 0046d026  e825b5faff           call 0x418550
// 0046d02b  8bd8                 mov ebx, eax
// 0046d02d  e8fed10000           call 0x47a230
// 0046d032  55                   push ebp
// 0046d033  53                   push ebx
// 0046d034  50                   push eax
// 0046d035  6881000000           push 0x81
// 0046d03a  8bce                 mov ecx, esi
// 0046d03c  e8b55c5100           call 0x982cf6
// 0046d041  8d8e94000000         lea ecx, [esi + 0x94]
// 0046d047  c7062497b500         mov dword ptr [esi], 0xb59724
// 0046d04d  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 0046d057  ff158447b200         call dword ptr [0xb24784]
// 0046d05d  eb02                 jmp 0x46d061
// 0046d05f  33f6                 xor esi, esi
// 0046d061  56                   push esi
// 0046d062  8bcf                 mov ecx, edi
// 0046d064  c644242400           mov byte ptr [esp + 0x24], 0
// 0046d069  897724               mov dword ptr [edi + 0x24], esi
// 0046d06c  e82b5c5100           call 0x982c9c
// 0046d071  6890000000           push 0x90
// 0046d076  e89f505100           call 0x98211a
// 0046d07b  8bf0                 mov esi, eax
// 0046d07d  83c404               add esp, 4
// 0046d080  89742428             mov dword ptr [esp + 0x28], esi
// 0046d084  c644242002           mov byte ptr [esp + 0x20], 2
// 0046d089  85f6                 test esi, esi
// 0046d08b  742a                 je 0x46d0b7
// 0046d08d  e82e83faff           call 0x4153c0
// 0046d092  8bd8                 mov ebx, eax
// 0046d094  e827b4faff           call 0x4184c0
// 0046d099  8be8                 mov ebp, eax
// 0046d09b  e86083faff           call 0x415400
// 0046d0a0  53                   push ebx
// 0046d0a1  55                   push ebp
// 0046d0a2  50                   push eax
// 0046d0a3  68b9000000           push 0xb9
// 0046d0a8  8bce                 mov ecx, esi
// 0046d0aa  e8475c5100           call 0x982cf6
// 0046d0af  c7068c96b500         mov dword ptr [esi], 0xb5968c
// 0046d0b5  eb02                 jmp 0x46d0b9
// 0046d0b7  33f6                 xor esi, esi
// 0046d0b9  56                   push esi
// 0046d0ba  8bcf                 mov ecx, edi
// 0046d0bc  c644242400           mov byte ptr [esp + 0x24], 0
// 0046d0c1  897720               mov dword ptr [edi + 0x20], esi
// 0046d0c4  e8d35b5100           call 0x982c9c
// 0046d0c9  6890000000           push 0x90
// 0046d0ce  e847505100           call 0x98211a
// 0046d0d3  8bf0                 mov esi, eax
// 0046d0d5  83c404               add esp, 4
// 0046d0d8  89742428             mov dword ptr [esp + 0x28], esi
// 0046d0dc  c644242003           mov byte ptr [esp + 0x20], 3
// 0046d0e1  85f6                 test esi, esi
// 0046d0e3  742a                 je 0x46d10f
// 0046d0e5  e876310300           call 0x4a0260
// 0046d0ea  8bd8                 mov ebx, eax
// 0046d0ec  e883565100           call 0x982774
// 0046d0f1  8be8                 mov ebp, eax
// 0046d0f3  e848310300           call 0x4a0240
// 0046d0f8  53                   push ebx
// 0046d0f9  55                   push ebp
// 0046d0fa  50                   push eax
// 0046d0fb  68cf000000           push 0xcf
// 0046d100  8bce                 mov ecx, esi
// 0046d102  e8ef5b5100           call 0x982cf6
// 0046d107  c7068c96b500         mov dword ptr [esi], 0xb5968c
// 0046d10d  eb02                 jmp 0x46d111
// 0046d10f  33f6                 xor esi, esi
// 0046d111  56                   push esi
// 0046d112  8bcf                 mov ecx, edi
// 0046d114  c644242400           mov byte ptr [esp + 0x24], 0
// 0046d119  897728               mov dword ptr [edi + 0x28], esi
// 0046d11c  e87b5b5100           call 0x982c9c
// 0046d121  6890000000           push 0x90
// 0046d126  e8ef4f5100           call 0x98211a
// 0046d12b  8bf0                 mov esi, eax
// 0046d12d  83c404               add esp, 4
// 0046d130  89742428             mov dword ptr [esp + 0x28], esi
// 0046d134  c644242004           mov byte ptr [esp + 0x20], 4
// 0046d139  85f6                 test esi, esi
// 0046d13b  742a                 je 0x46d167
// 0046d13d  e8aec2fdff           call 0x4493f0
// 0046d142  8be8                 mov ebp, eax
// 0046d144  e82b565100           call 0x982774
// 0046d149  8bd8                 mov ebx, eax
// 0046d14b  e810c1fdff           call 0x449260
// 0046d150  55                   push ebp
// 0046d151  53                   push ebx
// 0046d152  50                   push eax
// 0046d153  688a000000           push 0x8a
// 0046d158  8bce                 mov ecx, esi
// 0046d15a  e8975b5100           call 0x982cf6
// 0046d15f  c7068c96b500         mov dword ptr [esi], 0xb5968c
// 0046d165  eb02                 jmp 0x46d169
// 0046d167  33f6                 xor esi, esi
// 0046d169  56                   push esi
// 0046d16a  8bcf                 mov ecx, edi
// 0046d16c  c644242400           mov byte ptr [esp + 0x24], 0
// 0046d171  89772c               mov dword ptr [edi + 0x2c], esi
// 0046d174  e8235b5100           call 0x982c9c
// 0046d179  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046d17d  8bc7                 mov eax, edi
// 0046d17f  5f                   pop edi
// 0046d180  5e                   pop esi
// 0046d181  5d                   pop ebp
// 0046d182  5b                   pop ebx
// 0046d183  64890d00000000       mov dword ptr fs:[0], ecx
// 0046d18a  83c414               add esp, 0x14
// 0046d18d  c20400               ret 4
// copied from an identical function in another client (function ??0CRbxPlayDocTemplate@@QAE@_N@Z)

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern char* __cdecl func_0040df70();
extern char* __cdecl func_0040dfa0();
extern char* __cdecl func_00412af0();
extern char* __cdecl func_00412b80();
extern char* __cdecl func_004332e0();
extern char* __cdecl func_00433410();
extern char* __cdecl func_0044f200();
extern char* __cdecl func_00455d40();
extern char* __cdecl func_00458e70();
extern char* __cdecl func_004638a0();
extern char* __cdecl func_004638c0();
extern char* __cdecl func_006a0d2e();

extern void* vtable_00816684[];
extern void* vtable_0081671c[];
extern void* vtable_0081685c[];
extern void (__thiscall* imported_00803f04)(void*);

struct Document {
    void** vptr;
    char padding[0x8c];

    Document(int, char*, char*, char*);
};

struct SimpleDocument : Document {
    SimpleDocument(int, char*, char*, char*);
};

struct ExtendedDocument : Document {
    int field_90;
    unsigned int field_94;

    ExtendedDocument(int, char*, char*, char*);
};

struct TemplateBase {
    void** vptr;
    char padding[0x1c];

    TemplateBase();
    ~TemplateBase();
    void attach(Document*);
};

struct CRbxPlayDocTemplate : TemplateBase {
    SimpleDocument* field_20;
    ExtendedDocument* field_24;
    SimpleDocument* field_28;
    SimpleDocument* field_2c;

    CRbxPlayDocTemplate(bool);
};

__forceinline SimpleDocument::SimpleDocument(
    int id, char* a, char* b, char* c)
    : Document(id, a, b, c)
{
    vptr = vtable_00816684;
}

__forceinline ExtendedDocument::ExtendedDocument(
    int id, char* a, char* b, char* c)
    : Document(id, a, b, c)
{
    vptr = vtable_0081671c;
    field_90 = 0;
    imported_00803f04(&field_94);
}

CRbxPlayDocTemplate::CRbxPlayDocTemplate(bool play)
    : TemplateBase()
{
    vptr = vtable_0081685c;

    field_24 = new ExtendedDocument(
        0x81,
        func_0044f200(),
        func_00412b80(),
        play ? func_00455d40() : func_00458e70());
    attach(field_24);

    field_20 = new SimpleDocument(
        0xb9,
        func_0040dfa0(),
        func_00412af0(),
        func_0040df70());
    attach(field_20);

    field_28 = new SimpleDocument(
        0xcf,
        func_004638a0(),
        func_006a0d2e(),
        func_004638c0());
    attach(field_28);

    field_2c = new SimpleDocument(
        0x8a,
        func_004332e0(),
        func_006a0d2e(),
        func_00433410());
    attach(field_2c);
}