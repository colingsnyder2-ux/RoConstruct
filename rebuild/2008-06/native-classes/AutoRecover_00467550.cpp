// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace ATL { void __stdcall AtlThrowImpl(long hr); }

// INFERRED: COM-style objects; method identities unknown, only vtable slots and arguments known.
struct ComObj { void** vtbl; };

struct Host {
    char pad[0x174];
    ComObj* site;     // 0x174
    ComObj* inner;    // 0x178
};

typedef long (__stdcall *QueryFn)(ComObj*, const void*, ComObj**);
typedef long (__stdcall *Arg1Fn)(ComObj*, const void*);
typedef long (__stdcall *StructFn)(ComObj*, int, void*);

static inline void chk(long hr) { if (hr < 0) ATL::AtlThrowImpl(hr); }

extern "C" void __fastcall fn_00467550(Host* self, int unusedEdx)
{
    chk(((QueryFn)self->site->vtbl[3])(self->site, (const void*)0x85012c, &self->inner));
    chk(((Arg1Fn)self->inner->vtbl[0x2c / 4])(self->inner, (const void*)0x84ff0c));

    ComObj* obj = self->inner;
    int info[5];
    info[0] = 0x14;
    info[1] = 0x10;
    info[2] = 0;
    info[3] = 0;
    info[4] = 0x800;
    chk(((StructFn)obj->vtbl[0x18 / 4])(obj, 1, info));
}
