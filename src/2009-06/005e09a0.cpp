// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 005e09a0  unit: RBX::ContentProvider  size: 310 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e09a0
//
// 005e09a0  6aff                 push -1
// 005e09a2  68803d8600           push 0x863d80
// 005e09a7  64a100000000         mov eax, dword ptr fs:[0]
// 005e09ad  50                   push eax
// 005e09ae  64892500000000       mov dword ptr fs:[0], esp
// 005e09b5  81ec90000000         sub esp, 0x90
// 005e09bb  55                   push ebp
// 005e09bc  56                   push esi
// 005e09bd  57                   push edi
// 005e09be  8bf9                 mov edi, ecx
// 005e09c0  8bac24ac000000       mov ebp, dword ptr [esp + 0xac]
// 005e09c7  8d8424b0000000       lea eax, [esp + 0xb0]
// 005e09ce  50                   push eax
// 005e09cf  6a01                 push 1
// 005e09d1  83ec20               sub esp, 0x20
// 005e09d4  8bf4                 mov esi, esp
// 005e09d6  89642434             mov dword ptr [esp + 0x34], esp
// 005e09da  55                   push ebp
// 005e09db  8bce                 mov ecx, esi
// 005e09dd  c78424d000000000000000 mov dword ptr [esp + 0xd0], 0
// 005e09e8  ff15b8e48900         call dword ptr [0x89e4b8]
// 005e09ee  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005e09f1  894e1c               mov dword ptr [esi + 0x1c], ecx
// 005e09f4  8bcf                 mov ecx, edi
// 005e09f6  e825f4ffff           call 0x5dfe20
// 005e09fb  85c0                 test eax, eax
// 005e09fd  0f848b000000         je 0x5e0a8e
// 005e0a03  8b08                 mov ecx, dword ptr [eax]
// 005e0a05  85c9                 test ecx, ecx
// 005e0a07  743a                 je 0x5e0a43
// 005e0a09  6a01                 push 1
// 005e0a0b  6a01                 push 1
// 005e0a0d  51                   push ecx
// 005e0a0e  8d4c241c             lea ecx, [esp + 0x1c]
// 005e0a12  ff159ce48900         call dword ptr [0x89e49c]
// 005e0a18  50                   push eax
// 005e0a19  6a01                 push 1
// 005e0a1b  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 005e0a22  c68424ac00000001     mov byte ptr [esp + 0xac], 1
// 005e0a2a  e85155ffff           call 0x5d5f80
// 005e0a2f  8d4c2410             lea ecx, [esp + 0x10]
// 005e0a33  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 005e0a3b  ff15a0e48900         call dword ptr [0x89e4a0]
// 005e0a41  eb4b                 jmp 0x5e0a8e
// 005e0a43  8b4008               mov eax, dword ptr [eax + 8]
// 005e0a46  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005e0a4a  7205                 jb 0x5e0a51
// 005e0a4c  8b4004               mov eax, dword ptr [eax + 4]
// 005e0a4f  eb03                 jmp 0x5e0a54
// 005e0a51  83c004               add eax, 4
// 005e0a54  6a01                 push 1
// 005e0a56  6a40                 push 0x40
// 005e0a58  6a21                 push 0x21
// 005e0a5a  50                   push eax
// 005e0a5b  8d4c2420             lea ecx, [esp + 0x20]
// 005e0a5f  ff153ce48900         call dword ptr [0x89e43c]
// 005e0a65  50                   push eax
// 005e0a66  6a01                 push 1
// 005e0a68  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 005e0a6f  c68424ac00000002     mov byte ptr [esp + 0xac], 2
// 005e0a77  e80455ffff           call 0x5d5f80
// 005e0a7c  8d4c2410             lea ecx, [esp + 0x10]
// 005e0a80  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 005e0a88  ff1540e48900         call dword ptr [0x89e440]
// 005e0a8e  8b8424b0000000       mov eax, dword ptr [esp + 0xb0]
// 005e0a95  c78424a4000000ffffffff mov dword ptr [esp + 0xa4], 0xffffffff
// 005e0aa0  85c0                 test eax, eax
// 005e0aa2  7418                 je 0x5e0abc
// 005e0aa4  8b00                 mov eax, dword ptr [eax]
// 005e0aa6  85c0                 test eax, eax
// 005e0aa8  7412                 je 0x5e0abc
// 005e0aaa  8d9424b8000000       lea edx, [esp + 0xb8]
// 005e0ab1  6a02                 push 2
// 005e0ab3  52                   push edx
// 005e0ab4  8bca                 mov ecx, edx
// 005e0ab6  51                   push ecx
// 005e0ab7  ffd0                 call eax
// 005e0ab9  83c40c               add esp, 0xc
// 005e0abc  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 005e0ac3  5f                   pop edi
// 005e0ac4  5e                   pop esi
// 005e0ac5  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0acc  5d                   pop ebp
// 005e0acd  81c49c000000         add esp, 0x9c
// 005e0ad3  c22400               ret 0x24

// from server: 100% by king_originala
// roc 2008-06 00562530  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 310 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00562530
//
// 00562530  6aff                 push -1
// 00562532  6800f07c00           push 0x7cf000
// 00562537  64a100000000         mov eax, dword ptr fs:[0]
// 0056253d  50                   push eax
// 0056253e  64892500000000       mov dword ptr fs:[0], esp
// 00562545  81ec90000000         sub esp, 0x90
// 0056254b  55                   push ebp
// 0056254c  56                   push esi
// 0056254d  57                   push edi
// 0056254e  8bf9                 mov edi, ecx
// 00562550  8bac24ac000000       mov ebp, dword ptr [esp + 0xac]
// 00562557  8d8424b0000000       lea eax, [esp + 0xb0]
// 0056255e  50                   push eax
// 0056255f  6a01                 push 1
// 00562561  83ec20               sub esp, 0x20
// 00562564  8bf4                 mov esi, esp
// 00562566  89642434             mov dword ptr [esp + 0x34], esp
// 0056256a  55                   push ebp
// 0056256b  8bce                 mov ecx, esi
// 0056256d  c78424d000000000000000 mov dword ptr [esp + 0xd0], 0
// 00562578  ff155c248000         call dword ptr [0x80245c]
// 0056257e  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 00562581  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00562584  8bcf                 mov ecx, edi
// 00562586  e8f5f3ffff           call 0x561980
// 0056258b  85c0                 test eax, eax
// 0056258d  0f848b000000         je 0x56261e
// 00562593  8b08                 mov ecx, dword ptr [eax]
// 00562595  85c9                 test ecx, ecx
// 00562597  743a                 je 0x5625d3
// 00562599  6a01                 push 1
// 0056259b  6a01                 push 1
// 0056259d  51                   push ecx
// 0056259e  8d4c241c             lea ecx, [esp + 0x1c]
// 005625a2  ff153c248000         call dword ptr [0x80243c]
// 005625a8  50                   push eax
// 005625a9  6a01                 push 1
// 005625ab  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 005625b2  c68424ac00000001     mov byte ptr [esp + 0xac], 1
// 005625ba  e871880400           call 0x5aae30
// 005625bf  8d4c2410             lea ecx, [esp + 0x10]
// 005625c3  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 005625cb  ff1540248000         call dword ptr [0x802440]
// 005625d1  eb4b                 jmp 0x56261e
// 005625d3  8b4008               mov eax, dword ptr [eax + 8]
// 005625d6  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005625da  7205                 jb 0x5625e1
// 005625dc  8b4004               mov eax, dword ptr [eax + 4]
// 005625df  eb03                 jmp 0x5625e4
// 005625e1  83c004               add eax, 4
// 005625e4  6a01                 push 1
// 005625e6  6a40                 push 0x40
// 005625e8  6a21                 push 0x21
// 005625ea  50                   push eax
// 005625eb  8d4c2420             lea ecx, [esp + 0x20]
// 005625ef  ff1504248000         call dword ptr [0x802404]
// 005625f5  50                   push eax
// 005625f6  6a01                 push 1
// 005625f8  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 005625ff  c68424ac00000002     mov byte ptr [esp + 0xac], 2
// 00562607  e824880400           call 0x5aae30
// 0056260c  8d4c2410             lea ecx, [esp + 0x10]
// 00562610  c68424a400000000     mov byte ptr [esp + 0xa4], 0
// 00562618  ff1508248000         call dword ptr [0x802408]
// 0056261e  8b8424b0000000       mov eax, dword ptr [esp + 0xb0]
// 00562625  c78424a4000000ffffffff mov dword ptr [esp + 0xa4], 0xffffffff
// 00562630  85c0                 test eax, eax
// 00562632  7418                 je 0x56264c
// 00562634  8b00                 mov eax, dword ptr [eax]
// 00562636  85c0                 test eax, eax
// 00562638  7412                 je 0x56264c
// 0056263a  8d9424b8000000       lea edx, [esp + 0xb8]
// 00562641  6a01                 push 1
// 00562643  52                   push edx
// 00562644  8bca                 mov ecx, edx
// 00562646  51                   push ecx
// 00562647  ffd0                 call eax
// 00562649  83c40c               add esp, 0xc
// 0056264c  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 00562653  5f                   pop edi
// 00562654  5e                   pop esi
// 00562655  64890d00000000       mov dword ptr fs:[0], ecx
// 0056265c  5d                   pop ebp
// 0056265d  81c49c000000         add esp, 0x9c
// 00562663  c22400               ret 0x24

struct StringCore {
    unsigned char data[24];
    unsigned int capacity;
};

extern StringCore* (__thiscall *copyString)(StringCore*, const StringCore&);

struct String : StringCore {
    unsigned int extra;
    String(const String&);
};

inline String::String(const String& s)
{
    copyString(this, s);
    extra = s.extra;
}

struct Stream {
    unsigned char data[140];
};

struct StringStream : Stream {
    StringStream(const StringCore&, int, Stream*&);
    ~StringStream();
};

struct FileStream : Stream {
    FileStream(const char*, int, int, Stream*&);
    ~FileStream();
};

extern Stream* (__thiscall *constructStringStream)(
    StringStream*, const StringCore&, int, int);
extern void (__thiscall *destroyStringStream)(StringStream*);
extern Stream* (__thiscall *constructFileStream)(
    FileStream*, const char*, int, int, int);
extern void (__thiscall *destroyFileStream)(FileStream*);

inline StringStream::StringStream(const StringCore& text, int mode, Stream*& result)
{
    result = constructStringStream(this, text, mode, 1);
}

inline StringStream::~StringStream()
{
    destroyStringStream(this);
}

inline FileStream::FileStream(const char* path, int mode, int share, Stream*& result)
{
    result = constructFileStream(this, path, mode, share, 1);
}

inline FileStream::~FileStream()
{
    destroyFileStream(this);
}

struct Callable {
    unsigned char data[24];
};

typedef void (__cdecl *Manager)(Callable*, Callable*, int);

struct Callback {
    Manager* manager;
    unsigned int reserved;
    Callable callable;
    void read(int, Stream*);
    ~Callback();
};

inline Callback::~Callback()
{
    Manager* table = manager;
    if (table) {
        Manager destroy = *table;
        if (destroy)
            destroy(&callable, &callable, 2);
    }
}

struct Resource {
    StringCore* text;
    unsigned int reserved;
    StringCore* filename;
};

struct S {
    Resource* find(String, int, Callback*);
    void f(const String&, Callback);
};

void S::f(const String& name, Callback callback)
{
    Resource* resource = find(name, 1, &callback);
    if (resource) {
        Stream* result;
        if (resource->text) {
            StringStream stream(*resource->text, 1, result);
            callback.read(1, result);
        } else {
            StringCore* filename = resource->filename;
            const char* path;
            if (filename->capacity >= 16)
                path = *reinterpret_cast<const char**>(filename->data + 4);
            else
                path = reinterpret_cast<const char*>(filename->data + 4);
            FileStream stream(path, 33, 64, result);
            callback.read(1, result);
        }
    }
}
