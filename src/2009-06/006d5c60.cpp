// from server: 100% by why2
// roc 2009-06 006d5c60  unit: RBX::Body  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d5c60
//
// 006d5c60  6a0f                 push 0xf
// 006d5c62  e899ffffff           call 0x6d5c00
// 006d5c67  c3                   ret

extern "C" void __stdcall sub_6d5c00(int);

void sub_6d5c60()
{
    sub_6d5c00(0xf);
}
