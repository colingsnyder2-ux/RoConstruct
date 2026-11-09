// from server: 57% by colin
// roc 2007-08 006d0f70  unit: CXTPReportPaintManager  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d0f70
//
// 006d0f70  e8a9faf5ff           call 0x630a1e
// 006d0f75  83c458               add esp, 0x58
// 006d0f78  c3                   ret 

extern "C" void __cdecl sub_00630a1e();

void sub_006d0f70()
{
    sub_00630a1e();
}
