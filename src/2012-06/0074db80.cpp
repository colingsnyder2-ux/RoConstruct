// from server: 32% by atomic.potato
// roc 2012-06 0074db80  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0074db80

struct S {
    void f(int, int);
};

extern "C" {
    void __stdcall sub_b22644();
    void __stdcall sub_b2263c();
}

void S::f(int a, int b)
{
    sub_b22644();
    sub_b2263c();
}
