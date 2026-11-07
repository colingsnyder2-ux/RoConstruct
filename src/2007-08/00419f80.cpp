// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 00419f80  unit: VDHTMLWindowService::?$BoundFuncDesc  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00419f80
//
// 00419f80  6aff                 push -1
// 00419f82  688cb17300           push 0x73b18c
// 00419f87  64a100000000         mov eax, dword ptr fs:[0]
// 00419f8d  50                   push eax
// 00419f8e  51                   push ecx
// 00419f8f  53                   push ebx
// 00419f90  55                   push ebp
// 00419f91  56                   push esi
// 00419f92  57                   push edi
// 00419f93  a188518b00           mov eax, dword ptr [0x8b5188]
// 00419f98  33c4                 xor eax, esp
// 00419f9a  50                   push eax
// 00419f9b  8d442418             lea eax, [esp + 0x18]
// 00419f9f  64a300000000         mov dword ptr fs:[0], eax
// 00419fa5  8b442430             mov eax, dword ptr [esp + 0x30]
// 00419fa9  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00419fad  8bf1                 mov esi, ecx
// 00419faf  89742414             mov dword ptr [esp + 0x14], esi
// 00419fb3  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00419fb7  51                   push ecx
// 00419fb8  50                   push eax
// 00419fb9  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00419fc1  e84af1ffff           call 0x419110
// 00419fc6  50                   push eax
// 00419fc7  8bce                 mov ecx, esi
// 00419fc9  e8e26d1500           call 0x570db0
// 00419fce  8b542428             mov edx, dword ptr [esp + 0x28]
// 00419fd2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00419fd6  c644242001           mov byte ptr [esp + 0x20], 1
// 00419fdb  c70650787800         mov dword ptr [esi], 0x787850
// 00419fe1  895628               mov dword ptr [esi + 0x28], edx
// 00419fe4  89462c               mov dword ptr [esi + 0x2c], eax
// 00419fe7  8d7e30               lea edi, [esi + 0x30]
// 00419fea  e8113a1500           call 0x56da00
// 00419fef  8d4c2438             lea ecx, [esp + 0x38]
// 00419ff3  51                   push ecx
// 00419ff4  8d4f04               lea ecx, [edi + 4]
// 00419ff7  8907                 mov dword ptr [edi], eax
// 00419ff9  e8a2a1ffff           call 0x4141a0
// 00419ffe  c644242002           mov byte ptr [esp + 0x20], 2
// 0041a003  8d5e14               lea ebx, [esi + 0x14]
// 0041a006  e845331500           call 0x56d350
// 0041a00b  57                   push edi
// 0041a00c  8903                 mov dword ptr [ebx], eax
// 0041a00e  e8ed391500           call 0x56da00
// 0041a013  50                   push eax
// 0041a014  6aff                 push -1
// 0041a016  55                   push ebp
// 0041a017  e824291100           call 0x52c940
// 0041a01c  83c408               add esp, 8
// 0041a01f  50                   push eax
// 0041a020  8bcb                 mov ecx, ebx
// 0041a022  e8d9331500           call 0x56d400
// 0041a027  8d4c2438             lea ecx, [esp + 0x38]
// 0041a02b  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0041a033  ff15ace67700         call dword ptr [0x77e6ac]
// 0041a039  8bc6                 mov eax, esi
// 0041a03b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041a03f  64890d00000000       mov dword ptr fs:[0], ecx
// 0041a046  59                   pop ecx
// 0041a047  5f                   pop edi
// 0041a048  5e                   pop esi
// 0041a049  5d                   pop ebp
// 0041a04a  5b                   pop ebx
// 0041a04b  83c410               add esp, 0x10
// 0041a04e  c23000               ret 0x30

// from server: 100% by king_originala
// roc 2008-06 0041be50  unit: VDHTMLWindow::?$BoundFuncDesc  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041be50
//
// 0041be50  6aff                 push -1
// 0041be52  681ce17b00           push 0x7be11c
// 0041be57  64a100000000         mov eax, dword ptr fs:[0]
// 0041be5d  50                   push eax
// 0041be5e  64892500000000       mov dword ptr fs:[0], esp
// 0041be65  51                   push ecx
// 0041be66  53                   push ebx
// 0041be67  56                   push esi
// 0041be68  8bf1                 mov esi, ecx
// 0041be6a  57                   push edi
// 0041be6b  8974240c             mov dword ptr [esp + 0xc], esi
// 0041be6f  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0041be73  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0041be77  50                   push eax
// 0041be78  51                   push ecx
// 0041be79  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041be81  e81afaffff           call 0x41b8a0
// 0041be86  50                   push eax
// 0041be87  8bce                 mov ecx, esi
// 0041be89  e802991700           call 0x595790
// 0041be8e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041be92  8b442424             mov eax, dword ptr [esp + 0x24]
// 0041be96  c644241801           mov byte ptr [esp + 0x18], 1
// 0041be9b  c70610ef8000         mov dword ptr [esi], 0x80ef10
// 0041bea1  895638               mov dword ptr [esi + 0x38], edx
// 0041bea4  89463c               mov dword ptr [esi + 0x3c], eax
// 0041bea7  8d7e40               lea edi, [esi + 0x40]
// 0041beaa  e8410f1500           call 0x56cdf0
// 0041beaf  8d4c2430             lea ecx, [esp + 0x30]
// 0041beb3  51                   push ecx
// 0041beb4  8d4f04               lea ecx, [edi + 4]
// 0041beb7  8907                 mov dword ptr [edi], eax
// 0041beb9  e872b3ffff           call 0x417230
// 0041bebe  c644241802           mov byte ptr [esp + 0x18], 2
// 0041bec3  8d5e14               lea ebx, [esi + 0x14]
// 0041bec6  e8858b1700           call 0x594a50
// 0041becb  57                   push edi
// 0041becc  8903                 mov dword ptr [ebx], eax
// 0041bece  e81d0f1500           call 0x56cdf0
// 0041bed3  8b542430             mov edx, dword ptr [esp + 0x30]
// 0041bed7  50                   push eax
// 0041bed8  6aff                 push -1
// 0041beda  52                   push edx
// 0041bedb  e8b0801300           call 0x553f90
// 0041bee0  83c408               add esp, 8
// 0041bee3  50                   push eax
// 0041bee4  8bcb                 mov ecx, ebx
// 0041bee6  e8558c1700           call 0x594b40
// 0041beeb  8d4c2430             lea ecx, [esp + 0x30]
// 0041beef  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0041bef7  ff1568248000         call dword ptr [0x802468]
// 0041befd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041bf01  5f                   pop edi
// 0041bf02  8bc6                 mov eax, esi
// 0041bf04  5e                   pop esi
// 0041bf05  5b                   pop ebx
// 0041bf06  64890d00000000       mov dword ptr fs:[0], ecx
// 0041bf0d  83c410               add esp, 0x10
// 0041bf10  c23000               ret 0x30

struct String;
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroyString(this);
}

struct Holder {
    void* value;
    Holder(const String&);
    ~Holder();
};

struct Entry {
    void* type;
    void set(void* name, void* valueType, void* storage);
};

struct Base {
    virtual ~Base();
    char padding[16];
    Entry entry;
    char remainder[16];

    Base(void* descriptor);
};

struct Callback {
    unsigned first;
    unsigned second;
};

extern "C" void* __stdcall getDescriptor(const char*, unsigned);
extern "C" void* __cdecl getValueType();
extern "C" void* __cdecl getEntryType();
extern "C" void* __cdecl getName(const char*, int);

struct Value {
    void* type;
    Holder holder;

    Value(const String&);
};

__forceinline Value::Value(const String& text)
    : type(getValueType()), holder(text)
{
}

struct S : Base {
    Callback callback;
    Value value;

    S(Callback, const char*, const char*, String, unsigned);
    virtual ~S();
};

S::S(Callback function, const char* name, const char* category,
     String text, unsigned flags)
    : Base(getDescriptor(name, flags)),
      callback(function),
      value(text)
{
    entry.type = getEntryType();
    entry.set(getName(category, -1), getValueType(), &value);
}
