// from server: 100% by nuck16
// roc 2009-12 00419e51  unit: InsertObject  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419e51
//
// 00419e51  6a00                 push 0
// 00419e53  6a00                 push 0
// 00419e55  e81eaa3d00           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
