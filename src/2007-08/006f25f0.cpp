// from server: 72% by colin
// roc 2007-08 006f25f0  unit: CXTPImageEditorDlg  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f25f0
//
// 006f25f0  e829e4f3ff           call 0x630a1e
// 006f25f5  81c418010000         add esp, 0x118
// 006f25fb  c20c00               ret 0xc

extern "C" void __cdecl sub_630a1e();

void __stdcall sub_6f25f0(int, int, int)
{
    sub_630a1e();
}
