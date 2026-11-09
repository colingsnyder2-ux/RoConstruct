// from server: 72% by colin
// roc 2007-08 004c45b0  unit: RakPeer  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c45b0

extern "C" void __cdecl sub_630a1e();

struct RakPeer {
    void method(int arg);
};

void RakPeer::method(int arg) {
    sub_630a1e();
}
