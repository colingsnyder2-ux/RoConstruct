// from server: 73% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a06b0  unit: RBX::Network::VClient::?$BoundFuncDesc  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a06b0
//
// 004a06b0  6aff                 push -1
// 004a06b2  6843797c00           push 0x7c7943
// 004a06b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a06bd  50                   push eax
// 004a06be  64892500000000       mov dword ptr fs:[0], esp
// 004a06c5  51                   push ecx
// 004a06c6  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a06ca  53                   push ebx
// 004a06cb  56                   push esi
// 004a06cc  57                   push edi
// 004a06cd  8bf1                 mov esi, ecx
// 004a06cf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a06d3  50                   push eax
// 004a06d4  51                   push ecx
// 004a06d5  89742414             mov dword ptr [esp + 0x14], esi
// 004a06d9  e852e4ffff           call 0x49eb30
// 004a06de  50                   push eax
// 004a06df  8bce                 mov ecx, esi
// 004a06e1  e8aa500f00           call 0x595790
// 004a06e6  8b542420             mov edx, dword ptr [esp + 0x20]
// 004a06ea  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a06ee  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004a06f6  c706ec308200         mov dword ptr [esi], 0x8230ec
// 004a06fc  895638               mov dword ptr [esi + 0x38], edx
// 004a06ff  89463c               mov dword ptr [esi + 0x3c], eax
// 004a0702  8d7e40               lea edi, [esi + 0x40]
// 004a0705  e8b6c40c00           call 0x56cbc0
// 004a070a  6a08                 push 8
// 004a070c  8907                 mov dword ptr [edi], eax
// 004a070e  e80d022000           call 0x6a0920
// 004a0713  83c404               add esp, 4
// 004a0716  85c0                 test eax, eax
// 004a0718  740f                 je 0x4a0729
// 004a071a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004a071e  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a0724  894804               mov dword ptr [eax + 4], ecx
// 004a0727  eb02                 jmp 0x4a072b
// 004a0729  33c0                 xor eax, eax
// 004a072b  894704               mov dword ptr [edi + 4], eax
// 004a072e  c644241801           mov byte ptr [esp + 0x18], 1
// 004a0733  8d5e14               lea ebx, [esi + 0x14]
// 004a0736  e815430f00           call 0x594a50
// 004a073b  57                   push edi
// 004a073c  8903                 mov dword ptr [ebx], eax
// 004a073e  e87dc40c00           call 0x56cbc0
// 004a0743  8b542430             mov edx, dword ptr [esp + 0x30]
// 004a0747  50                   push eax
// 004a0748  6aff                 push -1
// 004a074a  52                   push edx
// 004a074b  e840380b00           call 0x553f90
// 004a0750  83c408               add esp, 8
// 004a0753  50                   push eax
// 004a0754  8bcb                 mov ecx, ebx
// 004a0756  e8e5430f00           call 0x594b40
// 004a075b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a075f  5f                   pop edi
// 004a0760  8bc6                 mov eax, esi
// 004a0762  5e                   pop esi
// 004a0763  5b                   pop ebx
// 004a0764  64890d00000000       mov dword ptr fs:[0], ecx
// 004a076b  83c410               add esp, 0x10
// 004a076e  c21800               ret 0x18

typedef unsigned long DWORD;

extern "C" void* __stdcall factory(DWORD, DWORD);
extern "C" void* __cdecl holderType();
extern "C" void* __cdecl fieldType();
extern "C" void* __cdecl makeValue(DWORD, int);

void* __cdecl operator new(unsigned int);

struct Holder;

struct Field {
    void* type;
    void set(void*, void*, Holder*);
};

struct Base {
    virtual void invoke();
    char padding[16];
    Field field;
    char tail[32];

    Base(void*);
    ~Base();
};

struct Callback {
    virtual void invoke();
    DWORD value;

    Callback(DWORD);
};

struct Holder {
    void* type;
    Callback* callback;

    Holder(DWORD);
    ~Holder();
};

struct S : Base {
    DWORD first;
    DWORD second;
    Holder holder;

    virtual void invoke();
    S(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
};

__forceinline Callback::Callback(DWORD argument)
    : value(argument)
{
}

__forceinline Holder::Holder(DWORD argument)
{
    type = holderType();
    callback = new Callback(argument);
}

S::S(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e, DWORD f)
    : Base(factory(c, f)), first(a), second(b), holder(e)
{
    field.type = fieldType();
    field.set(makeValue(d, -1), holderType(), &holder);
}
