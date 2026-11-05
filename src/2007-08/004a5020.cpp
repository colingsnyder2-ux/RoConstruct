// from server: 100% by colin
struct ClientProxy {
    char pad[0x1e14];
    void* field_1e14;
    int field_1e18;
    int field_1e1c;
    void sub_541630(int);
    void Method();
};

void ClientProxy::Method() {
    void** vtbl = *(void***)field_1e14;
    typedef void (__thiscall *Fn)(void*, int, int, int, int);
    Fn fn = (Fn)vtbl[0x64/4];
    fn(field_1e14, field_1e18, field_1e1c, 1, 0);
    sub_541630(0);
}
