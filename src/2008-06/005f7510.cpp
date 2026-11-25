// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Storage { char d[0x58]; ~Storage(); };
struct Opt {
    Storage storage;
    bool initialized;
    void reset() { if (initialized) { storage.~Storage(); initialized = false; } }
};
struct S {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void close_impl(int which);
    char padding[0x3c];
    Opt opt;
    char padding2[0x17];
    int flags;
    void close();
};
void S::close()
{
    try { close_impl(1); } catch (...) { }
    try { close_impl(2); } catch (...) { }
    opt.reset();
    flags = 0;
}
