// from server: 100% by nuck16
// roc 2009-12 004199a0  unit: InsertService  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004199a0
//
// 004199a0  6a00                 push 0
// 004199a2  6a00                 push 0
// 004199a4  e8cfae3d00           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
