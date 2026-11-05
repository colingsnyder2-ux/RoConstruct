// from server: 16% by colin
extern "C" {
    int __stdcall G1_00438c80(int);
    int __stdcall G1_00408740(int, int, int);
    int __stdcall G1_00547ca0();
    void __stdcall G1_0041c050_ctor();
}

struct Stream {
    char pad[0x90];
    int f();
};

int Stream::f()
{
    char buf[0x90];
    int *p = (int*)buf;
    p[0] = 0;
    G1_0041c050_ctor();
    return 0;
}
