// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {

// INFERRED: base type owning a heap buffer at +0x18
struct PropBase {
    char pad[0x14];
    char* owned;
    virtual void f() {}
    virtual ~PropBase() {
        delete owned;
    }
};

// INFERRED: derived type; its vptr is reset to the base vtable after the base body
struct PropTest3 : public PropBase {
    virtual ~PropTest3() {}
};

static PropTest3 prop_Test3;

}
