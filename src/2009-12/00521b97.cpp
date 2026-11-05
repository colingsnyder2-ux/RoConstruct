// from server: 100% by nuck16
// roc 2009-12 00521b97  unit: RBX::Network::Players::Plugin  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00521b97
//
// 00521b97  6a00                 push 0
// 00521b99  6a00                 push 0
// 00521b9b  e8d82c2d00           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
