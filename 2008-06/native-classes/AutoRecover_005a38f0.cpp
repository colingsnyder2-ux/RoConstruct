// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: all class layouts and names below are guesses derived from the disassembly offsets.

struct NameSource {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    // slot 14 (+0x38): returns a std::string by value
    virtual std::string getName() const;
};

struct Receiver {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    // slot 7 (+0x1c)
    virtual void handle(int arg, const std::string& name);
};

struct ContextObj {
    char pad[0x130];
    Receiver* receiver; // +0x130
};

struct TargetClass {
    char pad[0x3b0];
    NameSource* source; // +0x3b0
};

// the callee is called with only `this` on the stack
extern "C" ContextObj* fn_005a3330(TargetClass* self);

extern "C" void __fastcall fn_005a38f0(TargetClass* self, int unusedEdx, int arg1)
{
    ContextObj* ctx = fn_005a3330(self);
    Receiver* r = ctx->receiver;
    if (r) {
        r->handle(arg1, self->source->getName());
    }
}
