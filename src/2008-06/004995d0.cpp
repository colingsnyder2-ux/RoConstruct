// from server: 100% by EspClaude
// from server: 82% by king_originala
// roc 2008-06 004995d0  unit: RBX::Network::VPlayers::?$SignalDesc  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004995d0
//
// 004995d0  53                   push ebx
// 004995d1  55                   push ebp
// 004995d2  56                   push esi
// 004995d3  8b742410             mov esi, dword ptr [esp + 0x10]
// 004995d7  57                   push edi
// 004995d8  83ec20               sub esp, 0x20
// 004995db  89642434             mov dword ptr [esp + 0x34], esp
// 004995df  8bec                 mov ebp, esp
// 004995e1  83ec10               sub esp, 0x10
// 004995e4  8bfc                 mov edi, esp
// 004995e6  8bd9                 mov ebx, ecx
// 004995e8  89642444             mov dword ptr [esp + 0x44], esp
// 004995ec  56                   push esi
// 004995ed  8bcf                 mov ecx, edi
// 004995ef  c6460c01             mov byte ptr [esi + 0xc], 1
// 004995f3  e8f8d8ffff           call 0x496ef0
// 004995f8  0fb61598029700       movzx edx, byte ptr [0x970298]
// 004995ff  8a460c               mov al, byte ptr [esi + 0xc]
// 00499602  52                   push edx
// 00499603  88470c               mov byte ptr [edi + 0xc], al
// 00499606  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00499609  53                   push ebx
// 0049960a  33c0                 xor eax, eax
// 0049960c  50                   push eax
// 0049960d  b8f0744900           mov eax, 0x4974f0
// 00499612  50                   push eax
// 00499613  55                   push ebp
// 00499614  884f0d               mov byte ptr [edi + 0xd], cl
// 00499617  e814feffff           call 0x499430
// 0049961c  83c424               add esp, 0x24
// 0049961f  8bcb                 mov ecx, ebx
// 00499621  e8aaeeffff           call 0x4984d0
// 00499626  5f                   pop edi
// 00499627  5e                   pop esi
// 00499628  5d                   pop ebp
// 00499629  5b                   pop ebx
// 0049962a  c20400               ret 4

struct Core {
    unsigned char data[12];
    Core(const Core&);
};

struct Argument : Core {
    bool first;
    bool second;
    ~Argument();
};

inline Argument::~Argument()
{
}

struct Result {
    unsigned char data[32];
    Result(const Result&);
    ~Result();
};

inline Result::~Result()
{
}

struct Base1 {};
struct Base2 {};

struct __multiple_inheritance S : Base1, Base2 {
    void f(Argument*);
    void consume(Result);
    void callback();
};

static unsigned char globalFlag;
extern Result __cdecl build(void (S::*)(), S*, unsigned char, Argument);

void S::f(Argument* argument)
{
    argument->first = true;
    consume(build(&S::callback, this, globalFlag, *argument));
}
