// from server: 94% by why2
// roc 2009-06 005de504  unit: RBX::VInstance::?$NonFactoryProduct  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005de504
//
// 005de504  6a00                 push 0
// 005de506  6a00                 push 0
// 005de508  e83db51300           call 0x719a4a

extern "C" void __stdcall sub_719a4a(int, int);

void sub_5de504()
{
    sub_719a4a(0, 0);
}
