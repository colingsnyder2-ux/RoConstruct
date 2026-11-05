// from server: 57% by colin
// roc 2007-08 00514e30  unit: G3D::_internal::DialogTemplate  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00514e30
//
// 00514e30  e8e9bb1100           call 0x630a1e
// 00514e35  83c40c               add esp, 0xc
// 00514e38  c3                   ret 

extern "C" void __cdecl sub_00630a1e();

void __cdecl func_00514e30()
{
    sub_00630a1e();
}
