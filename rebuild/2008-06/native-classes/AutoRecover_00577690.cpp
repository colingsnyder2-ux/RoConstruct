// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: function-local static with a non-trivial dtor (atexit thunk at 0x7fd3c0).
// Layout from the stores: 3 dwords, then two bools (0, 1). Returns the object's address.
struct Fn00577690Static {
    int a;
    int b;
    int c;
    bool d;
    bool e;
    Fn00577690Static() : b(0), c(0), a(0), d(false), e(true) {}
    ~Fn00577690Static();
};

Fn00577690Static::~Fn00577690Static() {
    // INFERRED: real dtor body lives at the 0x7fd3c0 thunk; not recovered here.
}

extern "C" Fn00577690Static* fn_00577690()
{
    static Fn00577690Static instance;
    return &instance;
}
