// from server: 31% by atomic.potato
struct S1 {
    char pad[0x48];
    void ctor();
};

struct S2 {
    char pad[0x48];
    void ctor();
};

struct S3 {
    char pad[0x48];
    void ctor();
};

extern "C" void __stdcall f5135e0(void*);
extern "C" void __stdcall f514230(void*);
extern "C" void __stdcall f513390(void*);

struct Outer {
    char pad0[0x50];
    int field54;
    char pad58[0x48];
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    void* method();
};

void* Outer::method() {
    char buf[0x48];
    int local4 = 0;
    int localA8 = 1;
    f5135e0(&fieldB8);
    f514230(&fieldB4);
    int* p = (int*)fieldB4;
    int v = fieldB8;
    p[0] = v;
    f5135e0(&p[1]);
    local4 = 1;
    f513390(&buf[0]);
    f513390(&buf[0x64]);

    return this;
}
