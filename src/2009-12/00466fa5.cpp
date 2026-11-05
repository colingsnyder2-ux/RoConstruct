// from server: 100% by nuck16
// roc 2009-12 00466fa5  unit: CRobloxWnd::PartDropTarget  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00466fa5
//
// 00466fa5  6a00                 push 0
// 00466fa7  6a00                 push 0
// 00466fa9  e8cad83800           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
