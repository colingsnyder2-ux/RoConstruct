// from server: 100% by user
// from server: 99% by colin
// roc 2008-06 0057e730  unit: RBX::ClearBackpack  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057e730
//
// 0057e730  6aff                 push -1
// 0057e732  68e10f7d00           push 0x7d0fe1
// 0057e737  64a100000000         mov eax, dword ptr fs:[0]
// 0057e73d  50                   push eax
// 0057e73e  64892500000000       mov dword ptr fs:[0], esp
// 0057e745  51                   push ecx
// 0057e746  53                   push ebx
// 0057e747  56                   push esi
// 0057e748  8bf1                 mov esi, ecx
// 0057e74a  57                   push edi
// 0057e74b  8974240c             mov dword ptr [esp + 0xc], esi
// 0057e74f  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0057e753  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0057e75b  85ff                 test edi, edi
// 0057e75d  7408                 je 0x57e767
// 0057e75f  8d9fc8010000         lea ebx, [edi + 0x1c8]
// 0057e765  eb02                 jmp 0x57e769
// 0057e767  33db                 xor ebx, ebx
// 0057e769  83ec1c               sub esp, 0x1c
// 0057e76c  8d44243c             lea eax, [esp + 0x3c]
// 0057e770  8bcc                 mov ecx, esp
// 0057e772  89642458             mov dword ptr [esp + 0x58], esp
// 0057e776  50                   push eax
// 0057e777  ff155c248000         call dword ptr [0x80245c]
// 0057e77d  53                   push ebx
// 0057e77e  8bce                 mov ecx, esi
// 0057e780  e85b4c0000           call 0x5833e0
// 0057e785  c70664078300         mov dword ptr [esi], 0x830764
// 0057e78b  8b8704020000         mov eax, dword ptr [edi + 0x204]
// 0057e791  50                   push eax
// 0057e792  8d4e0c               lea ecx, [esi + 0xc]
// 0057e795  51                   push ecx
// 0057e796  c644242001           mov byte ptr [esp + 0x20], 1
// 0057e79b  e8a0a20900           call 0x618a40
// 0057e7a0  897e14               mov dword ptr [esi + 0x14], edi
// 0057e7a3  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0057e7aa  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0057e7b1  83c408               add esp, 8
// 0057e7b4  8d4c2420             lea ecx, [esp + 0x20]
// 0057e7b8  897e20               mov dword ptr [esi + 0x20], edi
// 0057e7bb  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0057e7c3  ff1568248000         call dword ptr [0x802468]
// 0057e7c9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0057e7cd  5f                   pop edi
// 0057e7ce  8bc6                 mov eax, esi
// 0057e7d0  5e                   pop esi
// 0057e7d1  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e7d8  5b                   pop ebx
// 0057e7d9  83c410               add esp, 0x10
// 0057e7dc  c22000               ret 0x20

// from server: 95% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern String* (__thiscall *stringCopy)(String*, const String*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    __declspec(dllimport) String(const String& s);
    ~String();
};



inline String::~String() {
    stringDestroy(this);
}

struct Owner {
    char padding[0x1c8];
    char context[0x3c];
    void* value;
    void* getValue() const { return value; }
};

struct Reference {
    void* object;
    void* control;
    Reference();
    ~Reference();
};

extern Reference __cdecl shared_from(void*);

struct Base {
    virtual void invoke();
    unsigned long data[2];
    Base(void*, String);
    ~Base();
};

struct TargetOwner { Owner* ptr; __forceinline TargetOwner(Owner* p) : ptr(p) {} };

struct ClearBackpack : Base {
    Reference reference;
    Owner* owner;
    unsigned long first;
    unsigned long second;
    TargetOwner target;

    ClearBackpack(String, Owner*);
    virtual void invoke();
};

ClearBackpack::ClearBackpack(String name, Owner* p)
    : Base(p ? p->context : 0, name),
      reference(shared_from(p->getValue())),
      owner(p),
      first(0),
      second(0),
      target(p) {
}
