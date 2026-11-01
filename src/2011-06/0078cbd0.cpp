// from server: 100% by Yeetserama
// roc 2011-06 0078cbd0  unit: RBX::HingeTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078cbd0
//
// 0078cbd0  56                   push esi
// 0078cbd1  8b742408             mov esi, dword ptr [esp + 8]
// 0078cbd5  8b0e                 mov ecx, dword ptr [esi]
// 0078cbd7  e804fcedff           call 0x66c7e0
// 0078cbdc  6a06                 push 6
// 0078cbde  8bce                 mov ecx, esi
// 0078cbe0  e80b1efdff           call 0x75e9f0
// 0078cbe5  6a00                 push 0
// 0078cbe7  8bce                 mov ecx, esi
// 0078cbe9  e8521efdff           call 0x75ea40
// 0078cbee  d9ee                 fldz 
// 0078cbf0  51                   push ecx
// 0078cbf1  d91c24               fstp dword ptr [esp]
// 0078cbf4  8bce                 mov ecx, esi
// 0078cbf6  e8b51efdff           call 0x75eab0
// 0078cbfb  d9ee                 fldz 
// 0078cbfd  51                   push ecx
// 0078cbfe  d91c24               fstp dword ptr [esp]
// 0078cc01  8bce                 mov ecx, esi
// 0078cc03  e8281ffdff           call 0x75eb30
// 0078cc08  8b0e                 mov ecx, dword ptr [esi]
// 0078cc0a  e8f1fbedff           call 0x66c800
// 0078cc0f  5e                   pop esi
// 0078cc10  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000c_00619af0@ns_ROCX00000c@@YGXPAUObject@1@@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
struct S
{
    void fn_ROCX00000c_00598c70();
    void fn_ROCX00000c_00598c90();
};

struct Object
{
    S* receiver;
    void fn_ROCX00000c_005f13e0(int value);
    void fn_ROCX00000c_005f1430(int value);
    void fn_ROCX00000c_005f14f0(float value);
    void fn_ROCX00000c_005f15c0(float value);
};

void __stdcall fn_ROCX00000c_00619af0(Object* object)
{
    object->receiver->fn_ROCX00000c_00598c70();
    object->fn_ROCX00000c_005f13e0(6);
    object->fn_ROCX00000c_005f1430(0);
    object->fn_ROCX00000c_005f14f0(0.0f);
    object->fn_ROCX00000c_005f15c0(0.0f);
    object->receiver->fn_ROCX00000c_00598c90();
}
}
