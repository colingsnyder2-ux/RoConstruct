// from server: 100% by EspClaude
// roc 2009-06 006b81a0  unit: RBX::HingeTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b81a0
//
// 006b81a0  56                   push esi
// 006b81a1  8b742408             mov esi, dword ptr [esp + 8]
// 006b81a5  8b0e                 mov ecx, dword ptr [esi]
// 006b81a7  e8e440faff           call 0x65c290
// 006b81ac  6a06                 push 6
// 006b81ae  8bce                 mov ecx, esi
// 006b81b0  e8dba4fcff           call 0x682690
// 006b81b5  6a00                 push 0
// 006b81b7  8bce                 mov ecx, esi
// 006b81b9  e822a5fcff           call 0x6826e0
// 006b81be  d9ee                 fldz 
// 006b81c0  51                   push ecx
// 006b81c1  d91c24               fstp dword ptr [esp]
// 006b81c4  8bce                 mov ecx, esi
// 006b81c6  e885a5fcff           call 0x682750
// 006b81cb  d9ee                 fldz 
// 006b81cd  51                   push ecx
// 006b81ce  d91c24               fstp dword ptr [esp]
// 006b81d1  8bce                 mov ecx, esi
// 006b81d3  e8f8a5fcff           call 0x6827d0
// 006b81d8  8b0e                 mov ecx, dword ptr [esi]
// 006b81da  e8d140faff           call 0x65c2b0
// 006b81df  5e                   pop esi
// 006b81e0  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00001a_00619af0@ns_ROCX00001a@@YGXPAUObject@1@@Z)

namespace ns_ROCX00001a {
struct S
{
    void fn_ROCX00001a_00598c70();
    void fn_ROCX00001a_00598c90();
};

struct Object
{
    S* receiver;
    void fn_ROCX00001a_005f13e0(int value);
    void fn_ROCX00001a_005f1430(int value);
    void fn_ROCX00001a_005f14f0(float value);
    void fn_ROCX00001a_005f15c0(float value);
};

void __stdcall fn_ROCX00001a_00619af0(Object* object)
{
    object->receiver->fn_ROCX00001a_00598c70();
    object->fn_ROCX00001a_005f13e0(6);
    object->fn_ROCX00001a_005f1430(0);
    object->fn_ROCX00001a_005f14f0(0.0f);
    object->fn_ROCX00001a_005f15c0(0.0f);
    object->receiver->fn_ROCX00001a_00598c90();
}
}
