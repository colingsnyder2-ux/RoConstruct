// from server: 100% by EspClaude
// from server: 73% by EspClaude
// roc 2009-06 004c00e0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c00e0
//
// 004c00e0  6aff                 push -1
// 004c00e2  6853ec8600           push 0x86ec53
// 004c00e7  64a100000000         mov eax, dword ptr fs:[0]
// 004c00ed  50                   push eax
// 004c00ee  64892500000000       mov dword ptr fs:[0], esp
// 004c00f5  51                   push ecx
// 004c00f6  8b442428             mov eax, dword ptr [esp + 0x28]
// 004c00fa  53                   push ebx
// 004c00fb  56                   push esi
// 004c00fc  57                   push edi
// 004c00fd  8bf1                 mov esi, ecx
// 004c00ff  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c0103  50                   push eax
// 004c0104  51                   push ecx
// 004c0105  89742414             mov dword ptr [esp + 0x14], esi
// 004c0109  e8d2aaffff           call 0x4babe0
// 004c010e  50                   push eax
// 004c010f  8bce                 mov ecx, esi
// 004c0111  e88a721b00           call 0x6773a0
// 004c0116  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c011a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c011e  c706544a8c00         mov dword ptr [esi], 0x8c4a54
// 004c0124  895638               mov dword ptr [esi + 0x38], edx
// 004c0127  89463c               mov dword ptr [esi + 0x3c], eax
// 004c012a  ff05f4a5a400         inc dword ptr [0xa4a5f4]
// 004c0130  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004c0138  8d7e40               lea edi, [esi + 0x40]
// 004c013b  e8005a1200           call 0x5e5b40
// 004c0140  6a08                 push 8
// 004c0142  8907                 mov dword ptr [edi], eax
// 004c0144  e8ef882500           call 0x718a38
// 004c0149  83c404               add esp, 4
// 004c014c  85c0                 test eax, eax
// 004c014e  740f                 je 0x4c015f
// 004c0150  8a4c2430             mov cl, byte ptr [esp + 0x30]
// 004c0154  c700a0d38a00         mov dword ptr [eax], 0x8ad3a0
// 004c015a  884804               mov byte ptr [eax + 4], cl
// 004c015d  eb02                 jmp 0x4c0161
// 004c015f  33c0                 xor eax, eax
// 004c0161  894704               mov dword ptr [edi + 4], eax
// 004c0164  ff050ca5a400         inc dword ptr [0xa4a50c]
// 004c016a  c644241801           mov byte ptr [esp + 0x18], 1
// 004c016f  8d5e14               lea ebx, [esi + 0x14]
// 004c0172  e8f9c11700           call 0x63c370
// 004c0177  8903                 mov dword ptr [ebx], eax
// 004c0179  ff05f4a5a400         inc dword ptr [0xa4a5f4]
// 004c017f  e8bc591200           call 0x5e5b40
// 004c0184  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004c0188  57                   push edi
// 004c0189  50                   push eax
// 004c018a  52                   push edx
// 004c018b  e820d51000           call 0x5cd6b0
// 004c0190  83c404               add esp, 4
// 004c0193  50                   push eax
// 004c0194  8bcb                 mov ecx, ebx
// 004c0196  e885c21700           call 0x63c420
// 004c019b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c019f  5f                   pop edi
// 004c01a0  8bc6                 mov eax, esi
// 004c01a2  5e                   pop esi
// 004c01a3  5b                   pop ebx
// 004c01a4  64890d00000000       mov dword ptr fs:[0], ecx
// 004c01ab  83c410               add esp, 0x10
// 004c01ae  c21800               ret 0x18

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
extern void* __cdecl func_00553f90(int);
extern int counterA;
extern int counterB;
inline void* typeA() { ++counterA; return func_0056cc30(); }
inline void* typeB() { ++counterB; return func_00594a50(); }

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
    : type(typeA()), action(new Action(flag))
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
    descriptor.value = typeB();
    descriptor.func_00594b40(
        func_00553f90(d), typeA(), &holder);
}
