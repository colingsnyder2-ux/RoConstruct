// from server: 100% by nuck16
// roc 2009-12 0069d8eb  unit: std::strstream  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0069d8eb
//
// 0069d8eb  6a00                 push 0
// 0069d8ed  6a00                 push 0
// 0069d8ef  e8846f1500           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
