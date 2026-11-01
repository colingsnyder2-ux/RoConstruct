// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00573670  unit: RBX::TextDisplay  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00573670
//
// 00573670  6aff                 push -1
// 00573672  6809e77c00           push 0x7ce709
// 00573677  64a100000000         mov eax, dword ptr fs:[0]
// 0057367d  50                   push eax
// 0057367e  64892500000000       mov dword ptr fs:[0], esp
// 00573685  83ec1c               sub esp, 0x1c
// 00573688  56                   push esi
// 00573689  8bf1                 mov esi, ecx
// 0057368b  8b06                 mov eax, dword ptr [esi]
// 0057368d  8b5064               mov edx, dword ptr [eax + 0x64]
// 00573690  8d4c2404             lea ecx, [esp + 4]
// 00573694  51                   push ecx
// 00573695  8bce                 mov ecx, esi
// 00573697  ffd2                 call edx
// 00573699  8b8e84010000         mov ecx, dword ptr [esi + 0x184]
// 0057369f  51                   push ecx
// 005736a0  8d9674010000         lea edx, [esi + 0x174]
// 005736a6  52                   push edx
// 005736a7  8b542438             mov edx, dword ptr [esp + 0x38]
// 005736ab  8d8e64010000         lea ecx, [esi + 0x164]
// 005736b1  51                   push ecx
// 005736b2  50                   push eax
// 005736b3  52                   push edx
// 005736b4  8bce                 mov ecx, esi
// 005736b6  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 005736be  e89dfcffff           call 0x573360
// 005736c3  8d4c2404             lea ecx, [esp + 4]
// 005736c7  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 005736cf  ff1568248000         call dword ptr [0x802468]
// 005736d5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005736d9  5e                   pop esi
// 005736da  64890d00000000       mov dword ptr fs:[0], ecx
// 005736e1  83c428               add esp, 0x28
// 005736e4  c20400               ret 4

struct String {
    char storage[28];
    ~String();
};

extern void (__thiscall* string_destroy)(String*);

inline String::~String()
{
    string_destroy(this);
}

struct TextDisplay {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual String text();

    char padding[0xbc];
    float first[4];
    float second[4];
    int value;

    void render(void*, const String&, const float*, const float*, int);
    void display(void*);
};

void TextDisplay::display(void* output)
{
    render(output, text(), first, second, value);
}
