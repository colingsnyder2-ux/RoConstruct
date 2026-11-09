// from server: 100% by Yeetserama
// roc 2011-06 00458e30  unit: CRbxPlayDocTemplate  size: 464 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00458e30
//
// 00458e30  6aff                 push -1
// 00458e32  68d0219d00           push 0x9d21d0
// 00458e37  64a100000000         mov eax, dword ptr fs:[0]
// 00458e3d  50                   push eax
// 00458e3e  64892500000000       mov dword ptr fs:[0], esp
// 00458e45  83ec08               sub esp, 8
// 00458e48  53                   push ebx
// 00458e49  55                   push ebp
// 00458e4a  56                   push esi
// 00458e4b  57                   push edi
// 00458e4c  8bf9                 mov edi, ecx
// 00458e4e  897c2410             mov dword ptr [esp + 0x10], edi
// 00458e52  e8cb1d3b00           call 0x80ac22
// 00458e57  6898000000           push 0x98
// 00458e5c  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00458e64  c707ecdea600         mov dword ptr [edi], 0xa6deec
// 00458e6a  e8ef113b00           call 0x80a05e
// 00458e6f  8bf0                 mov esi, eax
// 00458e71  83c404               add esp, 4
// 00458e74  89742414             mov dword ptr [esp + 0x14], esi
// 00458e78  c644242001           mov byte ptr [esp + 0x20], 1
// 00458e7d  85f6                 test esi, esi
// 00458e7f  744e                 je 0x458ecf
// 00458e81  807c242800           cmp byte ptr [esp + 0x28], 0
// 00458e86  7407                 je 0x458e8f
// 00458e88  e8e3640200           call 0x47f370
// 00458e8d  eb05                 jmp 0x458e94
// 00458e8f  e8bc910200           call 0x482050
// 00458e94  8be8                 mov ebp, eax
// 00458e96  e855c1fbff           call 0x414ff0
// 00458e9b  8bd8                 mov ebx, eax
// 00458e9d  e8fe630100           call 0x46f2a0
// 00458ea2  55                   push ebp
// 00458ea3  53                   push ebx
// 00458ea4  50                   push eax
// 00458ea5  6881000000           push 0x81
// 00458eaa  8bce                 mov ecx, esi
// 00458eac  e8bf1d3b00           call 0x80ac70
// 00458eb1  8d8e94000000         lea ecx, [esi + 0x94]
// 00458eb7  c706acdda600         mov dword ptr [esi], 0xa6ddac
// 00458ebd  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 00458ec7  ff15b42da400         call dword ptr [0xa42db4]
// 00458ecd  eb02                 jmp 0x458ed1
// 00458ecf  33f6                 xor esi, esi
// 00458ed1  56                   push esi
// 00458ed2  8bcf                 mov ecx, edi
// 00458ed4  c644242400           mov byte ptr [esp + 0x24], 0
// 00458ed9  897724               mov dword ptr [edi + 0x24], esi
// 00458edc  e8351d3b00           call 0x80ac16
// 00458ee1  6890000000           push 0x90
// 00458ee6  e873113b00           call 0x80a05e
// 00458eeb  8bf0                 mov esi, eax
// 00458eed  83c404               add esp, 4
// 00458ef0  89742428             mov dword ptr [esp + 0x28], esi
// 00458ef4  c644242002           mov byte ptr [esp + 0x20], 2
// 00458ef9  85f6                 test esi, esi
// 00458efb  742a                 je 0x458f27
// 00458efd  e81e94fbff           call 0x412320
// 00458f02  8bd8                 mov ebx, eax
// 00458f04  e857c0fbff           call 0x414f60
// 00458f09  8be8                 mov ebp, eax
// 00458f0b  e84094fbff           call 0x412350
// 00458f10  53                   push ebx
// 00458f11  55                   push ebp
// 00458f12  50                   push eax
// 00458f13  68b9000000           push 0xb9
// 00458f18  8bce                 mov ecx, esi
// 00458f1a  e8511d3b00           call 0x80ac70
// 00458f1f  c70614dda600         mov dword ptr [esi], 0xa6dd14
// 00458f25  eb02                 jmp 0x458f29
// 00458f27  33f6                 xor esi, esi
// 00458f29  56                   push esi
// 00458f2a  8bcf                 mov ecx, edi
// 00458f2c  c644242400           mov byte ptr [esp + 0x24], 0
// 00458f31  897720               mov dword ptr [edi + 0x20], esi
// 00458f34  e8dd1c3b00           call 0x80ac16
// 00458f39  6890000000           push 0x90
// 00458f3e  e81b113b00           call 0x80a05e
// 00458f43  8bf0                 mov esi, eax
// 00458f45  83c404               add esp, 4
// 00458f48  89742428             mov dword ptr [esp + 0x28], esi
// 00458f4c  c644242003           mov byte ptr [esp + 0x20], 3
// 00458f51  85f6                 test esi, esi
// 00458f53  742a                 je 0x458f7f
// 00458f55  e806460300           call 0x48d560
// 00458f5a  8bd8                 mov ebx, eax
// 00458f5c  e893173b00           call 0x80a6f4
// 00458f61  8be8                 mov ebp, eax
// 00458f63  e8d8450300           call 0x48d540
// 00458f68  53                   push ebx
// 00458f69  55                   push ebp
// 00458f6a  50                   push eax
// 00458f6b  68cf000000           push 0xcf
// 00458f70  8bce                 mov ecx, esi
// 00458f72  e8f91c3b00           call 0x80ac70
// 00458f77  c70614dda600         mov dword ptr [esi], 0xa6dd14
// 00458f7d  eb02                 jmp 0x458f81
// 00458f7f  33f6                 xor esi, esi
// 00458f81  56                   push esi
// 00458f82  8bcf                 mov ecx, edi
// 00458f84  c644242400           mov byte ptr [esp + 0x24], 0
// 00458f89  897728               mov dword ptr [edi + 0x28], esi
// 00458f8c  e8851c3b00           call 0x80ac16
// 00458f91  6890000000           push 0x90
// 00458f96  e8c3103b00           call 0x80a05e
// 00458f9b  8bf0                 mov esi, eax
// 00458f9d  83c404               add esp, 4
// 00458fa0  89742428             mov dword ptr [esp + 0x28], esi
// 00458fa4  c644242004           mov byte ptr [esp + 0x20], 4
// 00458fa9  85f6                 test esi, esi
// 00458fab  742a                 je 0x458fd7
// 00458fad  e8be49feff           call 0x43d970
// 00458fb2  8be8                 mov ebp, eax
// 00458fb4  e83b173b00           call 0x80a6f4
// 00458fb9  8bd8                 mov ebx, eax
// 00458fbb  e88048feff           call 0x43d840
// 00458fc0  55                   push ebp
// 00458fc1  53                   push ebx
// 00458fc2  50                   push eax
// 00458fc3  688a000000           push 0x8a
// 00458fc8  8bce                 mov ecx, esi
// 00458fca  e8a11c3b00           call 0x80ac70
// 00458fcf  c70614dda600         mov dword ptr [esi], 0xa6dd14
// 00458fd5  eb02                 jmp 0x458fd9
// 00458fd7  33f6                 xor esi, esi
// 00458fd9  56                   push esi
// 00458fda  8bcf                 mov ecx, edi
// 00458fdc  c644242400           mov byte ptr [esp + 0x24], 0
// 00458fe1  89772c               mov dword ptr [edi + 0x2c], esi
// 00458fe4  e82d1c3b00           call 0x80ac16
// 00458fe9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00458fed  8bc7                 mov eax, edi
// 00458fef  5f                   pop edi
// 00458ff0  5e                   pop esi
// 00458ff1  5d                   pop ebp
// 00458ff2  5b                   pop ebx
// 00458ff3  64890d00000000       mov dword ptr fs:[0], ecx
// 00458ffa  83c414               add esp, 0x14
// 00458ffd  c20400               ret 4
// copied from an identical function in another client (function ??0CRbxPlayDocTemplate@@QAE@_N@Z)

// from server: 100% by king_originala
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