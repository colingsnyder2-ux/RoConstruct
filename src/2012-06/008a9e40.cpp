// from server: 100% by Xemicl
// roc 2012-06 008a9e40  unit: RBX::HingeTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a9e40
//
// 008a9e40  56                   push esi
// 008a9e41  8b742408             mov esi, dword ptr [esp + 8]
// 008a9e45  8b0e                 mov ecx, dword ptr [esi]
// 008a9e47  e83476eaff           call 0x751480
// 008a9e4c  6a06                 push 6
// 008a9e4e  8bce                 mov ecx, esi
// 008a9e50  e8cb8bf7ff           call 0x822a20
// 008a9e55  6a00                 push 0
// 008a9e57  8bce                 mov ecx, esi
// 008a9e59  e8628cf7ff           call 0x822ac0
// 008a9e5e  d9ee                 fldz 
// 008a9e60  51                   push ecx
// 008a9e61  d91c24               fstp dword ptr [esp]
// 008a9e64  8bce                 mov ecx, esi
// 008a9e66  e8158df7ff           call 0x822b80
// 008a9e6b  d9ee                 fldz 
// 008a9e6d  51                   push ecx
// 008a9e6e  d91c24               fstp dword ptr [esp]
// 008a9e71  8bce                 mov ecx, esi
// 008a9e73  e8c88df7ff           call 0x822c40
// 008a9e78  8b0e                 mov ecx, dword ptr [esi]
// 008a9e7a  e83176eaff           call 0x7514b0
// 008a9e7f  5e                   pop esi
// 008a9e80  c20400               ret 4
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