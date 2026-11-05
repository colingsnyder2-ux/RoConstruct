// from server: 57% by colin
// roc 2007-08 006ebec0  unit: CXTPDockingPaneContextAlphaWnd  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ebec0
//
// 006ebec0  e8594bf4ff           call 0x630a1e
// 006ebec5  83c474               add esp, 0x74
// 006ebec8  c3                   ret 

extern "C" void __cdecl sub_00630a1e();

void sub_006ebec0()
{
    sub_00630a1e();
}
