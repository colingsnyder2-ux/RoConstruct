// from server: 35% by colin
// roc 2007-08 00552000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00552000

struct StreamBuf {
    int pubsync();
};

struct S {
    char pad[0x4c];
    StreamBuf* buf;
    int f();
};

extern "C" void __stdcall sub_551A20();

int S::f()
{
    sub_551A20();
    if (buf)
        buf->pubsync();
    return 0;
}
