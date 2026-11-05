// from server: 98% by EspClaude
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
    char remainder[32];

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
