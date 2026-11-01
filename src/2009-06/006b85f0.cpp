// from server: 100% by EspClaude
// roc 2009-06 006b85f0  unit: RBX::WeldTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b85f0
//
// 006b85f0  56                   push esi
// 006b85f1  8b742408             mov esi, dword ptr [esp + 8]
// 006b85f5  57                   push edi
// 006b85f6  8bf9                 mov edi, ecx
// 006b85f8  8b0e                 mov ecx, dword ptr [esi]
// 006b85fa  e8913cfaff           call 0x65c290
// 006b85ff  8bce                 mov ecx, esi
// 006b8601  e84aa2fcff           call 0x682850
// 006b8606  6a02                 push 2
// 006b8608  8bce                 mov ecx, esi
// 006b860a  e881a0fcff           call 0x682690
// 006b860f  8b0e                 mov ecx, dword ptr [esi]
// 006b8611  e89a3cfaff           call 0x65c2b0
// 006b8616  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b8619  6a08                 push 8
// 006b861b  50                   push eax
// 006b861c  e80f52f5ff           call 0x60d830
// 006b8621  83c404               add esp, 4
// 006b8624  8bc8                 mov ecx, eax
// 006b8626  e88519f9ff           call 0x649fb0
// 006b862b  5f                   pop edi
// 006b862c  5e                   pop esi
// 006b862d  c20400               ret 4
// copied from an identical function in another client (function ?apply@WeldTool@ns_ROCX000005@@QAEXPAUState@2@@Z)

namespace ns_ROCX000005 {
struct Receiver
{
    void begin();
    void end();
};

struct State
{
    Receiver* receiver;
    void reset();
    void set(int value);
};

struct Instance;

struct ServiceProvider
{
    void set(int value);
};

extern ServiceProvider* __cdecl findProvider(Instance* instance);

struct WeldTool
{
    char padding[0x18];
    Instance* instance;
    void apply(State* state);
};

void WeldTool::apply(State* state)
{
    state->receiver->begin();
    state->reset();
    state->set(2);
    state->receiver->end();
    findProvider(instance)->set(8);
}
}
