// from server: 100% by EspClaude
// roc 2009-06 00447790  unit: CRobloxModule  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447790
//
// 00447790  6aff                 push -1
// 00447792  6825008600           push 0x860025
// 00447797  64a100000000         mov eax, dword ptr fs:[0]
// 0044779d  50                   push eax
// 0044779e  64892500000000       mov dword ptr fs:[0], esp
// 004477a5  83ec24               sub esp, 0x24
// 004477a8  53                   push ebx
// 004477a9  56                   push esi
// 004477aa  33db                 xor ebx, ebx
// 004477ac  6a28                 push 0x28
// 004477ae  895c240c             mov dword ptr [esp + 0xc], ebx
// 004477b2  e881122d00           call 0x718a38
// 004477b7  8bf0                 mov esi, eax
// 004477b9  83c404               add esp, 4
// 004477bc  8974240c             mov dword ptr [esp + 0xc], esi
// 004477c0  895c2434             mov dword ptr [esp + 0x34], ebx
// 004477c4  85f6                 test esi, esi
// 004477c6  7432                 je 0x4477fa
// 004477c8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004477cc  8b01                 mov eax, dword ptr [ecx]
// 004477ce  8b5004               mov edx, dword ptr [eax + 4]
// 004477d1  ffd2                 call edx
// 004477d3  50                   push eax
// 004477d4  8d4c2414             lea ecx, [esp + 0x14]
// 004477d8  ff15b4e48900         call dword ptr [0x89e4b4]
// 004477de  8d442410             lea eax, [esp + 0x10]
// 004477e2  bb01000000           mov ebx, 1
// 004477e7  50                   push eax
// 004477e8  8bce                 mov ecx, esi
// 004477ea  c644243801           mov byte ptr [esp + 0x38], 1
// 004477ef  895c240c             mov dword ptr [esp + 0xc], ebx
// 004477f3  e8181cfcff           call 0x409410
// 004477f8  eb02                 jmp 0x4477fc
// 004477fa  33c0                 xor eax, eax
// 004477fc  8b0d3cb1a300         mov ecx, dword ptr [0xa3b13c]
// 00447802  c744243402000000     mov dword ptr [esp + 0x34], 2
// 0044780a  a33cb1a300           mov dword ptr [0xa3b13c], eax
// 0044780f  85c9                 test ecx, ecx
// 00447811  7408                 je 0x44781b
// 00447813  8b11                 mov edx, dword ptr [ecx]
// 00447815  8b02                 mov eax, dword ptr [edx]
// 00447817  6a01                 push 1
// 00447819  ffd0                 call eax
// 0044781b  5e                   pop esi
// 0044781c  f6c301               test bl, 1
// 0044781f  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00447827  5b                   pop ebx
// 00447828  740a                 je 0x447834
// 0044782a  8d4c2408             lea ecx, [esp + 8]
// 0044782e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00447834  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00447838  64890d00000000       mov dword ptr fs:[0], ecx
// 0044783f  83c430               add esp, 0x30
// 00447842  c3                   ret 
// copied from an identical function in another client (function ?update@@YAXPAUSource@@@Z)

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern void (__thiscall* stringConstruct)(void*, const char*);
extern void (__thiscall* stringDestroy)(void*);

struct String {
    char storage[28];

    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

struct Source {
    virtual void slot0() = 0;
    virtual const char* text() = 0;
};

struct Product {
    virtual ~Product();
    char storage[36];

    Product(const String&);
};

struct Holder {
    Product* value;

    void replace(Product* p)
    {
        Product* old = value;
        value = p;
        if (old)
            delete old;
    }
};

extern Holder current;

void __cdecl update(Source* source)
{
    current.replace(new Product(String(source->text())));
}