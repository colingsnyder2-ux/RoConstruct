// from server: 100% by Xemicl
// roc 2012-06 008a9e90  unit: RBX::RightMotorTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a9e90
//
// 008a9e90  56                   push esi
// 008a9e91  8b742408             mov esi, dword ptr [esp + 8]
// 008a9e95  8b0e                 mov ecx, dword ptr [esi]
// 008a9e97  e8e475eaff           call 0x751480
// 008a9e9c  6a07                 push 7
// 008a9e9e  8bce                 mov ecx, esi
// 008a9ea0  e87b8bf7ff           call 0x822a20
// 008a9ea5  6a0c                 push 0xc
// 008a9ea7  8bce                 mov ecx, esi
// 008a9ea9  e8128cf7ff           call 0x822ac0
// 008a9eae  d905e0b5b600         fld dword ptr [0xb6b5e0]
// 008a9eb4  51                   push ecx
// 008a9eb5  8bce                 mov ecx, esi
// 008a9eb7  d91c24               fstp dword ptr [esp]
// 008a9eba  e8c18cf7ff           call 0x822b80
// 008a9ebf  d905e8abb500         fld dword ptr [0xb5abe8]
// 008a9ec5  51                   push ecx
// 008a9ec6  8bce                 mov ecx, esi
// 008a9ec8  d91c24               fstp dword ptr [esp]
// 008a9ecb  e8708df7ff           call 0x822c40
// 008a9ed0  8b0e                 mov ecx, dword ptr [esi]
// 008a9ed2  e8d975eaff           call 0x7514b0
// 008a9ed7  5e                   pop esi
// 008a9ed8  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00001d_00619be0@ns_ROCX00001d@@YGXPAUState@1@@Z)

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
    state->fn_ROCX00001d_005f1430(12);
    state->fn_ROCX00001d_005f14f0(value_00843764);
    state->fn_ROCX00001d_005f15c0(value_0081e704);
    state->receiver->fn_ROCX00001d_00598c90();
}
}