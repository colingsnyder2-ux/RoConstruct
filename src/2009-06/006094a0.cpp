// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00568910  unit: RBX::VInstance::?$NonFactoryProduct  size: 319 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00568910
//
// 00568910  6aff                 push -1
// 00568912  68fef67c00           push 0x7cf6fe
// 00568917  64a100000000         mov eax, dword ptr fs:[0]
// 0056891d  50                   push eax
// 0056891e  64892500000000       mov dword ptr fs:[0], esp
// 00568925  81ecd0000000         sub esp, 0xd0
// 0056892b  57                   push edi
// 0056892c  8d442404             lea eax, [esp + 4]
// 00568930  50                   push eax
// 00568931  8bf9                 mov edi, ecx
// 00568933  e828fbffff           call 0x568460
// 00568938  83c404               add esp, 4
// 0056893b  837c241800           cmp dword ptr [esp + 0x18], 0
// 00568940  c78424dc00000000000000 mov dword ptr [esp + 0xdc], 0
// 0056894b  752b                 jne 0x568978
// 0056894d  8d4c2404             lea ecx, [esp + 4]
// 00568951  c78424dc000000ffffffff mov dword ptr [esp + 0xdc], 0xffffffff
// 0056895c  ff1568248000         call dword ptr [0x802468]
// 00568962  5f                   pop edi
// 00568963  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 0056896a  64890d00000000       mov dword ptr fs:[0], ecx
// 00568971  81c4dc000000         add esp, 0xdc
// 00568977  c3                   ret 
// 00568978  56                   push esi
// 00568979  e8b2900200           call 0x591a30
// 0056897e  8bf0                 mov esi, eax
// 00568980  89742424             mov dword ptr [esp + 0x24], esi
// 00568984  56                   push esi
// 00568985  8bcf                 mov ecx, edi
// 00568987  c68424e400000001     mov byte ptr [esp + 0xe4], 1
// 0056898f  e87cf7feff           call 0x558110
// 00568994  837c242010           cmp dword ptr [esp + 0x20], 0x10
// 00568999  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056899d  7304                 jae 0x5689a3
// 0056899f  8d44240c             lea eax, [esp + 0xc]
// 005689a3  6a01                 push 1
// 005689a5  6a40                 push 0x40
// 005689a7  6a22                 push 0x22
// 005689a9  50                   push eax
// 005689aa  8d4c2460             lea ecx, [esp + 0x60]
// 005689ae  ff15d0238000         call dword ptr [0x8023d0]
// 005689b4  8d4c2450             lea ecx, [esp + 0x50]
// 005689b8  51                   push ecx
// 005689b9  8d4c242c             lea ecx, [esp + 0x2c]
// 005689bd  c68424e400000002     mov byte ptr [esp + 0xe4], 2
// 005689c5  e826760200           call 0x58fff0
// 005689ca  c74424281cea8000     mov dword ptr [esp + 0x28], 0x80ea1c
// 005689d2  56                   push esi
// 005689d3  8d4c242c             lea ecx, [esp + 0x2c]
// 005689d7  c68424e400000003     mov byte ptr [esp + 0xe4], 3
// 005689df  e82c5e0200           call 0x58e810
// 005689e4  8d4c242c             lea ecx, [esp + 0x2c]
// 005689e8  c68424e000000002     mov byte ptr [esp + 0xe0], 2
// 005689f0  e8dbbceaff           call 0x4146d0
// 005689f5  8d4c2450             lea ecx, [esp + 0x50]
// 005689f9  c68424e000000001     mov byte ptr [esp + 0xe0], 1
// 00568a01  ff15d4238000         call dword ptr [0x8023d4]
// 00568a07  c68424e000000000     mov byte ptr [esp + 0xe0], 0
// 00568a0f  85f6                 test esi, esi
// 00568a11  7410                 je 0x568a23
// 00568a13  8bce                 mov ecx, esi
// 00568a15  e856b0eaff           call 0x413a70
// 00568a1a  56                   push esi
// 00568a1b  e85a7c1300           call 0x6a067a
// 00568a20  83c404               add esp, 4
// 00568a23  8d4c2408             lea ecx, [esp + 8]
// 00568a27  c78424e0000000ffffffff mov dword ptr [esp + 0xe0], 0xffffffff
// 00568a32  ff1568248000         call dword ptr [0x802468]
// 00568a38  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 00568a3f  5e                   pop esi
// 00568a40  5f                   pop edi
// 00568a41  64890d00000000       mov dword ptr fs:[0], ecx
// 00568a48  81c4dc000000         add esp, 0xdc
// 00568a4e  c3                   ret 

struct String;
struct Stream;
struct Product;

typedef void (__thiscall *StringDestructor)(String*);
typedef void (__thiscall *StreamConstructor)(Stream*, const char*, int, int, int);
typedef void (__thiscall *StreamDestructor)(Stream*);

extern StringDestructor destroyString;
extern StreamConstructor constructStream;
extern StreamDestructor destroyStream;

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~String();
};

inline String::~String()
{
    destroyString(this);
}

extern String __cdecl func_00568460();

struct Product
{
    void func_00413a70();
};

extern Product* __cdecl func_00591a30();
extern void __cdecl func_006a067a(void*);

struct Owner
{
    Product* pointer;
    explicit Owner(Product* p);
    ~Owner();
};

inline Owner::Owner(Product* p) : pointer(p)
{
}

struct CritSec { void* a; long b; long c; void* d; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSec*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSec*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct FreeNode { FreeNode* next; };
struct Pool { CritSec cs; FreeNode* head; };
extern Pool* __cdecl getPool();
extern long productCount;

inline Owner::~Owner()
{
    if (pointer)
    {
        pointer->func_00413a70();
        Pool* pool = getPool();
        EnterCriticalSection(&pool->cs);
        FreeNode* node = reinterpret_cast<FreeNode*>(pointer);
        node->next = pool->head;
        pool->head = node;
        LeaveCriticalSection(&pool->cs);
        InterlockedDecrement(&productCount);
    }
}

struct Stream
{
    char storage[136];

    Stream(const char*, int, int);
    ~Stream();
};

inline Stream::Stream(const char* path, int mode, int protection)
{
    constructStream(this, path, mode, protection, 1);
}

inline Stream::~Stream()
{
    destroyStream(this);
}

struct WriterBase
{
    void func_004146d0();
};

extern char writerTable;

struct Writer
{
    void* table;
    char storage[36];

    explicit Writer(Stream*);
    ~Writer();

    void func_0058fff0(Stream*);
    void func_0058e810(Product*);
};

inline Writer::Writer(Stream* stream)
{
    func_0058fff0(stream);
    table = &writerTable;
}

inline Writer::~Writer()
{
    reinterpret_cast<WriterBase*>(storage)->func_004146d0();
}

struct S
{
    void func_00558110(Product*);
    void func_00568910();
};

void S::func_00568910()
{
    String path = func_00568460();
    if (path.length == 0)
        return;

    Owner product(func_00591a30());
    func_00558110(product.pointer);

    const char* filename =
        path.capacity >= 16 ? path.storage.pointer : path.storage.buffer;

    Stream stream(filename, 34, 64);
    Writer writer(&stream);
    writer.func_0058e810(product.pointer);
}
