// from server: 94% by why2
// roc 2009-06 006851e3  unit: RBX::Sky  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006851e3
//
// 006851e3  6a00                 push 0
// 006851e5  6a00                 push 0
// 006851e7  e85e480900           call 0x719a4a

extern "C" void __stdcall sub_719a4a(int, int);

void sub_6851e3()
{
    sub_719a4a(0, 0);
}
