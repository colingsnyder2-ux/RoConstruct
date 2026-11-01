// from server: 100% by colin
struct RakPeer {
    char pad[0x510];
    void method1(int);
    void method2();
    void func(int);
};

void RakPeer::func(int arg) {
    RakPeer* p = (RakPeer*)((char*)this + 0x510);
    if (arg) {
        p->method1(arg);
    } else {
        p->method2();
    }
}
