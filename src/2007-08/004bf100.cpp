// from server: 84% by colin
// roc 2007-08 004bf100  unit: RakPeer  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bf100
//
// 004bf100  e819191700           call 0x630a1e
// 004bf105  83c41c               add esp, 0x1c
// 004bf108  c20c00               ret 0xc

extern "C" void __cdecl sub_630a1e();

struct RakPeer {
    void method(int, int, int);
};

void RakPeer::method(int a, int b, int c) {
    sub_630a1e();
}
