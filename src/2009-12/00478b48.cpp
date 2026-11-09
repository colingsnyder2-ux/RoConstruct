// from server: 100% by nuck16
// roc 2009-12 00478b48  unit: VCWorkspace::?$CComObject  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00478b48
//
// 00478b48  6a00                 push 0
// 00478b4a  6a00                 push 0
// 00478b4c  e827bd3700           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
