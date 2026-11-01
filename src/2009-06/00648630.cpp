// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bd360  unit: VStockSound::?$FactoryProduct  size: 194 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd360
//
// 005bd360  64a100000000         mov eax, dword ptr fs:[0]
// 005bd366  6aff                 push -1
// 005bd368  6808497d00           push 0x7d4908
// 005bd36d  50                   push eax
// 005bd36e  64892500000000       mov dword ptr fs:[0], esp
// 005bd375  56                   push esi
// 005bd376  57                   push edi
// 005bd377  8bf1                 mov esi, ecx
// 005bd379  8d442418             lea eax, [esp + 0x18]
// 005bd37d  50                   push eax
// 005bd37e  8dbe40010000         lea edi, [esi + 0x140]
// 005bd384  57                   push edi
// 005bd385  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005bd38d  e8cee9f9ff           call 0x55bd60
// 005bd392  83c408               add esp, 8
// 005bd395  84c0                 test al, al
// 005bd397  7464                 je 0x5bd3fd
// 005bd399  8d4c2418             lea ecx, [esp + 0x18]
// 005bd39d  51                   push ecx
// 005bd39e  8bcf                 mov ecx, edi
// 005bd3a0  ff150c248000         call dword ptr [0x80240c]
// 005bd3a6  8b542434             mov edx, dword ptr [esp + 0x34]
// 005bd3aa  8bce                 mov ecx, esi
// 005bd3ac  89571c               mov dword ptr [edi + 0x1c], edx
// 005bd3af  e85cf2ffff           call 0x5bc610
// 005bd3b4  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005bd3ba  85c0                 test eax, eax
// 005bd3bc  741b                 je 0x5bd3d9
// 005bd3be  6a00                 push 0
// 005bd3c0  50                   push eax
// 005bd3c1  e82e280e00           call 0x69fbf4
// 005bd3c6  50                   push eax
// 005bd3c7  e8d4b3ffff           call 0x5b87a0
// 005bd3cc  83c404               add esp, 4
// 005bd3cf  c7863c01000000000000 mov dword ptr [esi + 0x13c], 0
// 005bd3d9  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005bd3df  8d8e34010000         lea ecx, [esi + 0x134]
// 005bd3e5  85c0                 test eax, eax
// 005bd3e7  7408                 je 0x5bd3f1
// 005bd3e9  ff4808               dec dword ptr [eax + 8]
// 005bd3ec  e88f9ae9ff           call 0x456e80
// 005bd3f1  6864709700           push 0x977064
// 005bd3f6  8bce                 mov ecx, esi
// 005bd3f8  e80307e5ff           call 0x40db00
// 005bd3fd  8d4c2418             lea ecx, [esp + 0x18]
// 005bd401  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005bd409  ff1568248000         call dword ptr [0x802468]
// 005bd40f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005bd413  5f                   pop edi
// 005bd414  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd41b  5e                   pop esi
// 005bd41c  83c40c               add esp, 0xc
// 005bd41f  c22000               ret 0x20

struct String;

extern void (__thiscall *stringDestroy)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

struct String {
    char data[28];

    ~String();
    String& operator=(const String&);
};

__forceinline String::~String()
{
    stringDestroy(this);
}

__forceinline String& String::operator=(const String& other)
{
    return stringAssign(this, other);
}

struct Node {
    char padding[8];
    int count;
};

struct Reference {
    Node* pointer;
    void* control;

    void release();
};

extern "C" bool __cdecl differs(const String*, const String*);
extern "C" void* __stdcall convert(void*, int);
extern "C" void __cdecl dispose(void*);
extern char notification[];

struct S {
    char padding[0x134];
    Reference reference;
    void* resource;
    String value;
    int setting;

    void release();
    void notify(const char*);
    void f(String incoming, int newSetting);
};

void S::f(String incoming, int newSetting)
{
    String* destination = &value;

    if (differs(destination, &incoming)) {
        *destination = incoming;
        reinterpret_cast<int*>(destination)[7] = newSetting;
        release();

        if (resource) {
            dispose(convert(resource, 0));
            resource = 0;
        }

        if (reference.pointer) {
            --reference.pointer->count;
            reference.release();
        }

        notify(notification);
    }
}
