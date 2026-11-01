// from server: 100% by EspClaude
// roc 2009-06 006b8240  unit: RBX::OscillateMotorTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8240
//
// 006b8240  56                   push esi
// 006b8241  8b742408             mov esi, dword ptr [esp + 8]
// 006b8245  8b0e                 mov ecx, dword ptr [esi]
// 006b8247  e84440faff           call 0x65c290
// 006b824c  6a07                 push 7
// 006b824e  8bce                 mov ecx, esi
// 006b8250  e83ba4fcff           call 0x682690
// 006b8255  6a0d                 push 0xd
// 006b8257  8bce                 mov ecx, esi
// 006b8259  e882a4fcff           call 0x6826e0
// 006b825e  d905a8ab8e00         fld dword ptr [0x8eaba8]
// 006b8264  51                   push ecx
// 006b8265  8bce                 mov ecx, esi
// 006b8267  d91c24               fstp dword ptr [esp]
// 006b826a  e8e1a4fcff           call 0x682750
// 006b826f  d905c4758b00         fld dword ptr [0x8b75c4]
// 006b8275  51                   push ecx
// 006b8276  8bce                 mov ecx, esi
// 006b8278  d91c24               fstp dword ptr [esp]
// 006b827b  e850a5fcff           call 0x6827d0
// 006b8280  8b0e                 mov ecx, dword ptr [esi]
// 006b8282  e82940faff           call 0x65c2b0
// 006b8287  5e                   pop esi
// 006b8288  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00001d_00619be0@ns_ROCX00001d@@YGXPAUState@1@@Z)

namespace ns_ROCX00001d {
extern const float value_00843764;
extern const float value_0081e704;

struct S
{
    void fn_ROCX00001d_00598c70();
    void fn_ROCX00001d_00598c90();
};

struct State
{
    S* receiver;
    void fn_ROCX00001d_005f13e0(int value);
    void fn_ROCX00001d_005f1430(int value);
    void fn_ROCX00001d_005f14f0(float value);
    void fn_ROCX00001d_005f15c0(float value);
};

void __stdcall fn_ROCX00001d_00619be0(State* state)
{
    state->receiver->fn_ROCX00001d_00598c70();
    state->fn_ROCX00001d_005f13e0(7);
    state->fn_ROCX00001d_005f1430(13);
    state->fn_ROCX00001d_005f14f0(value_00843764);
    state->fn_ROCX00001d_005f15c0(value_0081e704);
    state->receiver->fn_ROCX00001d_00598c90();
}
}
