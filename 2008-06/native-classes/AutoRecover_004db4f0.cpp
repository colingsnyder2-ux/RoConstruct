// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout/types from disassembly only; ViewBase dtor is a real virtual dtor so SEH frame appears.
struct IObj {
    virtual ~IObj();
};
struct IRes {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void release();
};
struct MatFactory { ~MatFactory(); };
struct TexTable {
    virtual ~TexTable();
};

namespace RBX {
class ViewBase {
public:
    virtual ~ViewBase();
};
}

extern "C" int __fastcall fn_004b3380(void* self, int unusedEdx);
extern "C" int fn_004db130(void);
extern "C" int fn_004db040(void);
extern "C" int fn_004daf50(void);
extern "C" int fn_004db310(void);
extern "C" int fn_004db220(void);
extern "C" int fn_004db400(void);
extern "C" void flushCache_004e5670(void);

struct ViewNewLike : RBX::ViewBase {
    IRes* res;
    IObj* obj;
    TexTable* table;
    MatFactory* mat;
    void* extra;
    virtual ~ViewNewLike() {
        res->release();
        if (obj)
            delete obj;
        obj = 0;
        if (mat) {
            mat->~MatFactory();
            operator delete(mat);
        }
        mat = 0;
        if (table)
            delete table;
        table = 0;
        if (extra)
            fn_004b3380(extra, 0);
        fn_004db130();
        fn_004db040();
        fn_004daf50();
        flushCache_004e5670();
        fn_004db310();
        fn_004db220();
        fn_004db400();
    }
};

extern "C" void __fastcall fn_004db4f0(ViewNewLike* self, int unusedEdx) {
    self->~ViewNewLike();
}
