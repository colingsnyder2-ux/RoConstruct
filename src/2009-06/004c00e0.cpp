// from server: 73% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004929c0  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004929c0
//
// 004929c0  6aff                 push -1
// 004929c2  6843797c00           push 0x7c7943
// 004929c7  64a100000000         mov eax, dword ptr fs:[0]
// 004929cd  50                   push eax
// 004929ce  64892500000000       mov dword ptr fs:[0], esp
// 004929d5  51                   push ecx
// 004929d6  8b442428             mov eax, dword ptr [esp + 0x28]
// 004929da  53                   push ebx
// 004929db  56                   push esi
// 004929dc  57                   push edi
// 004929dd  8bf1                 mov esi, ecx
// 004929df  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004929e3  50                   push eax
// 004929e4  51                   push ecx
// 004929e5  89742414             mov dword ptr [esp + 0x14], esi
// 004929e9  e872e9ffff           call 0x491360
// 004929ee  50                   push eax
// 004929ef  8bce                 mov ecx, esi
// 004929f1  e89a2d1000           call 0x595790
// 004929f6  8b542420             mov edx, dword ptr [esp + 0x20]
// 004929fa  8b442424             mov eax, dword ptr [esp + 0x24]
// 004929fe  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00492a06  c706c01d8200         mov dword ptr [esi], 0x821dc0
// 00492a0c  895638               mov dword ptr [esi + 0x38], edx
// 00492a0f  89463c               mov dword ptr [esi + 0x3c], eax
// 00492a12  8d7e40               lea edi, [esi + 0x40]
// 00492a15  e816a20d00           call 0x56cc30
// 00492a1a  6a08                 push 8
// 00492a1c  8907                 mov dword ptr [edi], eax
// 00492a1e  e8fdde2000           call 0x6a0920
// 00492a23  83c404               add esp, 4
// 00492a26  85c0                 test eax, eax
// 00492a28  740f                 je 0x492a39
// 00492a2a  8a4c2430             mov cl, byte ptr [esp + 0x30]
// 00492a2e  c70084ba8000         mov dword ptr [eax], 0x80ba84
// 00492a34  884804               mov byte ptr [eax + 4], cl
// 00492a37  eb02                 jmp 0x492a3b
// 00492a39  33c0                 xor eax, eax
// 00492a3b  894704               mov dword ptr [edi + 4], eax
// 00492a3e  c644241801           mov byte ptr [esp + 0x18], 1
// 00492a43  8d5e14               lea ebx, [esi + 0x14]
// 00492a46  e805201000           call 0x594a50
// 00492a4b  57                   push edi
// 00492a4c  8903                 mov dword ptr [ebx], eax
// 00492a4e  e8dda10d00           call 0x56cc30
// 00492a53  8b542430             mov edx, dword ptr [esp + 0x30]
// 00492a57  50                   push eax
// 00492a58  6aff                 push -1
// 00492a5a  52                   push edx
// 00492a5b  e830150c00           call 0x553f90
// 00492a60  83c408               add esp, 8
// 00492a63  50                   push eax
// 00492a64  8bcb                 mov ecx, ebx
// 00492a66  e8d5201000           call 0x594b40
// 00492a6b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00492a6f  5f                   pop edi
// 00492a70  8bc6                 mov eax, esi
// 00492a72  5e                   pop esi
// 00492a73  5b                   pop ebx
// 00492a74  64890d00000000       mov dword ptr fs:[0], ecx
// 00492a7b  83c410               add esp, 0x10
// 00492a7e  c21800               ret 0x18

void* operator new(unsigned int);

extern void* func_00491360();
extern void* func_0056cc30();
extern void* func_00594a50();
extern void* __cdecl func_00553f90(int, int);

struct Holder;

struct Descriptor
{
    void* value;
    void func_00594b40(void*, void*, Holder*);
};

struct Base
{
    virtual ~Base();
    char reserved0[16];
    Descriptor descriptor;
    char reserved1[32];

    Base(void*, int, int);
};

struct Action
{
    virtual ~Action();
    bool flag;

    Action(bool);
};

inline Action::Action(bool value) : flag(value)
{
}

struct Holder
{
    void* type;
    Action* action;

    Holder(bool);
    ~Holder();
};

inline Holder::Holder(bool flag)
    : type(func_0056cc30()), action(new Action(flag))
{
}

struct S : Base
{
    int first;
    int second;
    Holder holder;

    S(int, int, int, int, bool, int);
    virtual ~S();
};

S::S(int a, int b, int c, int d, bool flag, int e)
    : Base(func_00491360(), c, e),
      first(a),
      second(b),
      holder(flag)
{
    descriptor.value = func_00594a50();
    descriptor.func_00594b40(
        func_00553f90(d, -1), func_0056cc30(), &holder);
}
