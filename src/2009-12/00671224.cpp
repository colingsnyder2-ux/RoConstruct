// from server: 100% by nuck16
// roc 2009-12 00671224  unit: RBX::DataModel  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00671224
//
// 00671224  6a00                 push 0
// 00671226  6a00                 push 0
// 00671228  e84b361800           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
