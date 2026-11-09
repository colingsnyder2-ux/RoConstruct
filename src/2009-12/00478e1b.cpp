// from server: 100% by nuck16
// roc 2009-12 00478e1b  unit: VCWorkspace::?$CComObject  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00478e1b
//
// 00478e1b  6a00                 push 0
// 00478e1d  6a00                 push 0
// 00478e1f  e854ba3700           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
