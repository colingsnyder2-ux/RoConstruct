// from server: 100% by Yeetserama
// roc 2007-08 00448b50  unit: CRbxDocTemplate  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448b50
//
// 00448b50  6aff                 push -1
// 00448b52  68c5fb7300           push 0x73fbc5
// 00448b57  64a100000000         mov eax, dword ptr fs:[0]
// 00448b5d  50                   push eax
// 00448b5e  83ec24               sub esp, 0x24
// 00448b61  53                   push ebx
// 00448b62  56                   push esi
// 00448b63  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448b68  33c4                 xor eax, esp
// 00448b6a  50                   push eax
// 00448b6b  8d442430             lea eax, [esp + 0x30]
// 00448b6f  64a300000000         mov dword ptr fs:[0], eax
// 00448b75  33db                 xor ebx, ebx
// 00448b77  6a28                 push 0x28
// 00448b79  895c2410             mov dword ptr [esp + 0x10], ebx
// 00448b7d  e874731e00           call 0x62fef6
// 00448b82  8bf0                 mov esi, eax
// 00448b84  83c404               add esp, 4
// 00448b87  89742410             mov dword ptr [esp + 0x10], esi
// 00448b8b  85f6                 test esi, esi
// 00448b8d  895c2438             mov dword ptr [esp + 0x38], ebx
// 00448b91  7432                 je 0x448bc5
// 00448b93  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00448b97  8b01                 mov eax, dword ptr [ecx]
// 00448b99  8b5004               mov edx, dword ptr [eax + 4]
// 00448b9c  ffd2                 call edx
// 00448b9e  50                   push eax
// 00448b9f  8d4c2418             lea ecx, [esp + 0x18]
// 00448ba3  ff1598e67700         call dword ptr [0x77e698]
// 00448ba9  8d442414             lea eax, [esp + 0x14]
// 00448bad  bb01000000           mov ebx, 1
// 00448bb2  50                   push eax
// 00448bb3  8bce                 mov ecx, esi
// 00448bb5  c644243c01           mov byte ptr [esp + 0x3c], 1
// 00448bba  895c2410             mov dword ptr [esp + 0x10], ebx
// 00448bbe  e8fda1fcff           call 0x412dc0
// 00448bc3  eb02                 jmp 0x448bc7
// 00448bc5  33c0                 xor eax, eax
// 00448bc7  8b0d94be8b00         mov ecx, dword ptr [0x8bbe94]
// 00448bcd  85c9                 test ecx, ecx
// 00448bcf  c744243802000000     mov dword ptr [esp + 0x38], 2
// 00448bd7  a394be8b00           mov dword ptr [0x8bbe94], eax
// 00448bdc  7408                 je 0x448be6
// 00448bde  8b11                 mov edx, dword ptr [ecx]
// 00448be0  8b02                 mov eax, dword ptr [edx]
// 00448be2  6a01                 push 1
// 00448be4  ffd0                 call eax
// 00448be6  f6c301               test bl, 1
// 00448be9  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00448bf1  740a                 je 0x448bfd
// 00448bf3  8d4c2414             lea ecx, [esp + 0x14]
// 00448bf7  ff15ace67700         call dword ptr [0x77e6ac]
// 00448bfd  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00448c01  64890d00000000       mov dword ptr fs:[0], ecx
// 00448c08  59                   pop ecx
// 00448c09  5e                   pop esi
// 00448c0a  5b                   pop ebx
// 00448c0b  83c430               add esp, 0x30
// 00448c0e  c3                   ret 
// copied from an identical function in another client (function ?update@@YAXPAUSource@@@Z)

// from server: 100% by king_originala
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