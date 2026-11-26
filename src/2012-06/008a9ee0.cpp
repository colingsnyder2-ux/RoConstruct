// from server: 100% by Xemicl
// roc 2012-06 008a9ee0  unit: RBX::OscillateMotorTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a9ee0
//
// 008a9ee0  56                   push esi
// 008a9ee1  8b742408             mov esi, dword ptr [esp + 8]
// 008a9ee5  8b0e                 mov ecx, dword ptr [esi]
// 008a9ee7  e89475eaff           call 0x751480
// 008a9eec  6a07                 push 7
// 008a9eee  8bce                 mov ecx, esi
// 008a9ef0  e82b8bf7ff           call 0x822a20
// 008a9ef5  6a0d                 push 0xd
// 008a9ef7  8bce                 mov ecx, esi
// 008a9ef9  e8c28bf7ff           call 0x822ac0
// 008a9efe  d905e0b5b600         fld dword ptr [0xb6b5e0]
// 008a9f04  51                   push ecx
// 008a9f05  8bce                 mov ecx, esi
// 008a9f07  d91c24               fstp dword ptr [esp]
// 008a9f0a  e8718cf7ff           call 0x822b80
// 008a9f0f  d905e8abb500         fld dword ptr [0xb5abe8]
// 008a9f15  51                   push ecx
// 008a9f16  8bce                 mov ecx, esi
// 008a9f18  d91c24               fstp dword ptr [esp]
// 008a9f1b  e8208df7ff           call 0x822c40
// 008a9f20  8b0e                 mov ecx, dword ptr [esi]
// 008a9f22  e88975eaff           call 0x7514b0
// 008a9f27  5e                   pop esi
// 008a9f28  c20400               ret 4
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