// from server: 100% by EspClaude
// roc 2009-06 00445290  unit: CRbxPlayDocTemplate  size: 464 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445290
//
// 00445290  6aff                 push -1
// 00445292  6800068500           push 0x850600
// 00445297  64a100000000         mov eax, dword ptr fs:[0]
// 0044529d  50                   push eax
// 0044529e  64892500000000       mov dword ptr fs:[0], esp
// 004452a5  83ec08               sub esp, 8
// 004452a8  53                   push ebx
// 004452a9  55                   push ebp
// 004452aa  56                   push esi
// 004452ab  57                   push edi
// 004452ac  8bf9                 mov edi, ecx
// 004452ae  897c2410             mov dword ptr [esp + 0x10], edi
// 004452b2  e839432d00           call 0x7195f0
// 004452b7  6898000000           push 0x98
// 004452bc  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004452c4  c7073c6d8b00         mov dword ptr [edi], 0x8b6d3c
// 004452ca  e869372d00           call 0x718a38
// 004452cf  8bf0                 mov esi, eax
// 004452d1  83c404               add esp, 4
// 004452d4  89742414             mov dword ptr [esp + 0x14], esi
// 004452d8  c644242001           mov byte ptr [esp + 0x20], 1
// 004452dd  85f6                 test esi, esi
// 004452df  744e                 je 0x44532f
// 004452e1  807c242800           cmp byte ptr [esp + 0x28], 0
// 004452e6  7407                 je 0x4452ef
// 004452e8  e843ee0000           call 0x454130
// 004452ed  eb05                 jmp 0x4452f4
// 004452ef  e8ec250100           call 0x4578e0
// 004452f4  8be8                 mov ebp, eax
// 004452f6  e865bbfcff           call 0x410e60
// 004452fb  8bd8                 mov ebx, eax
// 004452fd  e84e800000           call 0x44d350
// 00445302  55                   push ebp
// 00445303  53                   push ebx
// 00445304  50                   push eax
// 00445305  6881000000           push 0x81
// 0044530a  8bce                 mov ecx, esi
// 0044530c  e82d432d00           call 0x71963e
// 00445311  8d8e94000000         lea ecx, [esi + 0x94]
// 00445317  c706fc6b8b00         mov dword ptr [esi], 0x8b6bfc
// 0044531d  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 00445327  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0044532d  eb02                 jmp 0x445331
// 0044532f  33f6                 xor esi, esi
// 00445331  56                   push esi
// 00445332  8bcf                 mov ecx, edi
// 00445334  c644242400           mov byte ptr [esp + 0x24], 0
// 00445339  897724               mov dword ptr [edi + 0x24], esi
// 0044533c  e8a3422d00           call 0x7195e4
// 00445341  6890000000           push 0x90
// 00445346  e8ed362d00           call 0x718a38
// 0044534b  8bf0                 mov esi, eax
// 0044534d  83c404               add esp, 4
// 00445350  89742428             mov dword ptr [esp + 0x28], esi
// 00445354  c644242002           mov byte ptr [esp + 0x20], 2
// 00445359  85f6                 test esi, esi
// 0044535b  742a                 je 0x445387
// 0044535d  e8fe77fcff           call 0x40cb60
// 00445362  8bd8                 mov ebx, eax
// 00445364  e867bafcff           call 0x410dd0
// 00445369  8be8                 mov ebp, eax
// 0044536b  e82078fcff           call 0x40cb90
// 00445370  53                   push ebx
// 00445371  55                   push ebp
// 00445372  50                   push eax
// 00445373  68b9000000           push 0xb9
// 00445378  8bce                 mov ecx, esi
// 0044537a  e8bf422d00           call 0x71963e
// 0044537f  c706646b8b00         mov dword ptr [esi], 0x8b6b64
// 00445385  eb02                 jmp 0x445389
// 00445387  33f6                 xor esi, esi
// 00445389  56                   push esi
// 0044538a  8bcf                 mov ecx, edi
// 0044538c  c644242400           mov byte ptr [esp + 0x24], 0
// 00445391  897720               mov dword ptr [edi + 0x20], esi
// 00445394  e84b422d00           call 0x7195e4
// 00445399  6890000000           push 0x90
// 0044539e  e895362d00           call 0x718a38
// 004453a3  8bf0                 mov esi, eax
// 004453a5  83c404               add esp, 4
// 004453a8  89742428             mov dword ptr [esp + 0x28], esi
// 004453ac  c644242003           mov byte ptr [esp + 0x20], 3
// 004453b1  85f6                 test esi, esi
// 004453b3  742a                 je 0x4453df
// 004453b5  e896f10100           call 0x464550
// 004453ba  8bd8                 mov ebx, eax
// 004453bc  e80d3d2d00           call 0x7190ce
// 004453c1  8be8                 mov ebp, eax
// 004453c3  e868f10100           call 0x464530
// 004453c8  53                   push ebx
// 004453c9  55                   push ebp
// 004453ca  50                   push eax
// 004453cb  68cf000000           push 0xcf
// 004453d0  8bce                 mov ecx, esi
// 004453d2  e867422d00           call 0x71963e
// 004453d7  c706646b8b00         mov dword ptr [esi], 0x8b6b64
// 004453dd  eb02                 jmp 0x4453e1
// 004453df  33f6                 xor esi, esi
// 004453e1  56                   push esi
// 004453e2  8bcf                 mov ecx, edi
// 004453e4  c644242400           mov byte ptr [esp + 0x24], 0
// 004453e9  897728               mov dword ptr [edi + 0x28], esi
// 004453ec  e8f3412d00           call 0x7195e4
// 004453f1  6890000000           push 0x90
// 004453f6  e83d362d00           call 0x718a38
// 004453fb  8bf0                 mov esi, eax
// 004453fd  83c404               add esp, 4
// 00445400  89742428             mov dword ptr [esp + 0x28], esi
// 00445404  c644242004           mov byte ptr [esp + 0x20], 4
// 00445409  85f6                 test esi, esi
// 0044540b  742a                 je 0x445437
// 0044540d  e80e76feff           call 0x42ca20
// 00445412  8be8                 mov ebp, eax
// 00445414  e8b53c2d00           call 0x7190ce
// 00445419  8bd8                 mov ebx, eax
// 0044541b  e8b074feff           call 0x42c8d0
// 00445420  55                   push ebp
// 00445421  53                   push ebx
// 00445422  50                   push eax
// 00445423  688a000000           push 0x8a
// 00445428  8bce                 mov ecx, esi
// 0044542a  e80f422d00           call 0x71963e
// 0044542f  c706646b8b00         mov dword ptr [esi], 0x8b6b64
// 00445435  eb02                 jmp 0x445439
// 00445437  33f6                 xor esi, esi
// 00445439  56                   push esi
// 0044543a  8bcf                 mov ecx, edi
// 0044543c  c644242400           mov byte ptr [esp + 0x24], 0
// 00445441  89772c               mov dword ptr [edi + 0x2c], esi
// 00445444  e89b412d00           call 0x7195e4
// 00445449  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044544d  8bc7                 mov eax, edi
// 0044544f  5f                   pop edi
// 00445450  5e                   pop esi
// 00445451  5d                   pop ebp
// 00445452  5b                   pop ebx
// 00445453  64890d00000000       mov dword ptr fs:[0], ecx
// 0044545a  83c414               add esp, 0x14
// 0044545d  c20400               ret 4
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