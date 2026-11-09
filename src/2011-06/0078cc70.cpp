// from server: 100% by Yeetserama
// roc 2011-06 0078cc70  unit: RBX::OscillateMotorTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078cc70
//
// 0078cc70  56                   push esi
// 0078cc71  8b742408             mov esi, dword ptr [esp + 8]
// 0078cc75  8b0e                 mov ecx, dword ptr [esi]
// 0078cc77  e864fbedff           call 0x66c7e0
// 0078cc7c  6a07                 push 7
// 0078cc7e  8bce                 mov ecx, esi
// 0078cc80  e86b1dfdff           call 0x75e9f0
// 0078cc85  6a0d                 push 0xd
// 0078cc87  8bce                 mov ecx, esi
// 0078cc89  e8b21dfdff           call 0x75ea40
// 0078cc8e  d905dcbda900         fld dword ptr [0xa9bddc]
// 0078cc94  51                   push ecx
// 0078cc95  8bce                 mov ecx, esi
// 0078cc97  d91c24               fstp dword ptr [esp]
// 0078cc9a  e8111efdff           call 0x75eab0
// 0078cc9f  d90560eca600         fld dword ptr [0xa6ec60]
// 0078cca5  51                   push ecx
// 0078cca6  8bce                 mov ecx, esi
// 0078cca8  d91c24               fstp dword ptr [esp]
// 0078ccab  e8801efdff           call 0x75eb30
// 0078ccb0  8b0e                 mov ecx, dword ptr [esi]
// 0078ccb2  e849fbedff           call 0x66c800
// 0078ccb7  5e                   pop esi
// 0078ccb8  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000f_00619be0@ns_ROCX00000f@@YGXPAUState@1@@Z)

namespace ns_ROCX00000f {
// from server: 100% by king_originala
extern const float value_00843764;
extern const float value_0081e704;

struct S
{
    void fn_ROCX00000f_00598c70();
    void fn_ROCX00000f_00598c90();
};

struct State
{
    S* receiver;
    void fn_ROCX00000f_005f13e0(int value);
    void fn_ROCX00000f_005f1430(int value);
    void fn_ROCX00000f_005f14f0(float value);
    void fn_ROCX00000f_005f15c0(float value);
};

void __stdcall fn_ROCX00000f_00619be0(State* state)
{
    state->receiver->fn_ROCX00000f_00598c70();
    state->fn_ROCX00000f_005f13e0(7);
    state->fn_ROCX00000f_005f1430(13);
    state->fn_ROCX00000f_005f14f0(value_00843764);
    state->fn_ROCX00000f_005f15c0(value_0081e704);
    state->receiver->fn_ROCX00000f_00598c90();
}
}
