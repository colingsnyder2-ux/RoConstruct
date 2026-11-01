// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c9880  unit: RBX::Stats::VItem::?$BoundFuncDesc  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c9880
//
// 005c9880  6aff                 push -1
// 005c9882  6843797c00           push 0x7c7943
// 005c9887  64a100000000         mov eax, dword ptr fs:[0]
// 005c988d  50                   push eax
// 005c988e  64892500000000       mov dword ptr fs:[0], esp
// 005c9895  51                   push ecx
// 005c9896  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005c989a  53                   push ebx
// 005c989b  56                   push esi
// 005c989c  57                   push edi
// 005c989d  8bf1                 mov esi, ecx
// 005c989f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005c98a3  50                   push eax
// 005c98a4  51                   push ecx
// 005c98a5  89742414             mov dword ptr [esp + 0x14], esi
// 005c98a9  e832fdffff           call 0x5c95e0
// 005c98ae  50                   push eax
// 005c98af  8bce                 mov ecx, esi
// 005c98b1  e8dabefcff           call 0x595790
// 005c98b6  8b542420             mov edx, dword ptr [esp + 0x20]
// 005c98ba  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c98be  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005c98c6  c7062c9c8300         mov dword ptr [esi], 0x839c2c
// 005c98cc  895638               mov dword ptr [esi + 0x38], edx
// 005c98cf  89463c               mov dword ptr [esi + 0x3c], eax
// 005c98d2  8d7e40               lea edi, [esi + 0x40]
// 005c98d5  e83634faff           call 0x56cd10
// 005c98da  6a10                 push 0x10
// 005c98dc  8907                 mov dword ptr [edi], eax
// 005c98de  e83d700d00           call 0x6a0920
// 005c98e3  83c404               add esp, 4
// 005c98e6  85c0                 test eax, eax
// 005c98e8  740f                 je 0x5c98f9
// 005c98ea  dd442430             fld qword ptr [esp + 0x30]
// 005c98ee  c7001ce28200         mov dword ptr [eax], 0x82e21c
// 005c98f4  dd5808               fstp qword ptr [eax + 8]
// 005c98f7  eb02                 jmp 0x5c98fb
// 005c98f9  33c0                 xor eax, eax
// 005c98fb  894704               mov dword ptr [edi + 4], eax
// 005c98fe  c644241801           mov byte ptr [esp + 0x18], 1
// 005c9903  8d5e14               lea ebx, [esi + 0x14]
// 005c9906  e81537faff           call 0x56d020
// 005c990b  57                   push edi
// 005c990c  8903                 mov dword ptr [ebx], eax
// 005c990e  e8fd33faff           call 0x56cd10
// 005c9913  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005c9917  50                   push eax
// 005c9918  6aff                 push -1
// 005c991a  51                   push ecx
// 005c991b  e870a6f8ff           call 0x553f90
// 005c9920  83c408               add esp, 8
// 005c9923  50                   push eax
// 005c9924  8bcb                 mov ecx, ebx
// 005c9926  e815b2fcff           call 0x594b40
// 005c992b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c992f  5f                   pop edi
// 005c9930  8bc6                 mov eax, esi
// 005c9932  5e                   pop esi
// 005c9933  5b                   pop ebx
// 005c9934  64890d00000000       mov dword ptr fs:[0], ecx
// 005c993b  83c410               add esp, 0x10
// 005c993e  c21c00               ret 0x1c

typedef unsigned int size_t;

void* __cdecl operator new(size_t);

struct Type {
    unsigned char data[16];
    Type(const char*, const void*);
    ~Type();
};

const Type& __cdecl singleton();
const Type& __cdecl valueType();
void* __stdcall makeDescriptor(void*, void*);
void* __cdecl lookup(void*, int);

struct Value {
    virtual ~Value();
    double number;
    Value(double);
};

struct Variant {
    const Type* type;
    Value* value;
    Variant(double);
    ~Variant();
};

struct Member {
    const Type* type;
    unsigned char data[32];
    void bind(void*, const Type&, Variant*);
};

struct Base {
    virtual ~Base();
    unsigned char data[16];
    Member member;
    Base(void*);
};

struct S : Base {
    unsigned int first;
    unsigned int second;
    Variant value;
    S(unsigned int, unsigned int, void*, void*, double, void*);
};

inline Value::Value(double n) : number(n)
{
}

inline Variant::Variant(double n)
    : type(&valueType()), value(new Value(n))
{
}

S::S(unsigned int a, unsigned int b, void* c, void* d,
     double n, void* e)
    : Base(makeDescriptor(c, e)), first(a), second(b), value(n)
{
    member.type = &singleton();
    member.bind(lookup(d, -1), valueType(), &value);
}
