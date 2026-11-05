// roc 2009-12 00401000  unit: seg_00400000  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401000
//
// 00401000  8b442408             mov eax, dword ptr [esp + 8]
// 00401004  c3                   ret 
// copied from an identical function in another client (function ?RBX_VFaceInstance_EnumPropDescriptor_f@ns_ROCX000003@@YAHHH@Z)

namespace ns_ROCX000003 {
struct RBX_VFaceInstance_EnumPropDescriptor {
    int f(int);
};

int RBX_VFaceInstance_EnumPropDescriptor_f(int this_ptr, int arg) {
    return arg;
}
}
