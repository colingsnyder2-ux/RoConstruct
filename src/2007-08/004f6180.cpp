// from server: 88% by EspClaude
// roc 2007-08 004f6180 137 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// Layout from target: base class (vptr, +4, +8 zeroed; EH state 0 after it),
// derived vptr; member at +0xc (zeroes +0x10,+0x14,+0xc; EH state 1);
// member at +0x18 built by out-of-line thiscall ctor 0x4f5b90 (EH state 2);
// one-time static init guarded by a byte flag (0x8bfbd0) calling 0x4f5b30;
// float at +0x4c = 0.0f.

struct BaseObj {
    BaseObj() : f4(0), f8(0) {}
    virtual ~BaseObj();
    int f4;
    int f8;
};

struct Member0C {
    Member0C() : y(0), z(0) { x = 0; }
    ~Member0C();
    int x;
    int y;
    int z;
};

struct Member18 {
    Member18();
    ~Member18();
    int w[13];
};

extern bool g_staticsInitialized;
void __cdecl initStatics();

struct Derived : BaseObj {
    Derived();
    Member0C m0c;
    Member18 m18;
    float f4c;
};

Derived::Derived()
{
    if (!g_staticsInitialized) {
        initStatics();
        g_staticsInitialized = true;
    }
    f4c = 0.0f;
}
