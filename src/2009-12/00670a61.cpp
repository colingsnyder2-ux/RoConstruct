// from server: 100% by nuck16
// roc 2009-12 00670a61  unit: RBX::DataModel  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00670a61
//
// 00670a61  6a00                 push 0
// 00670a63  6a00                 push 0
// 00670a65  e80e3e1800           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
