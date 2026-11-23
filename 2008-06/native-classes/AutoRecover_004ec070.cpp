// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: minimal local layouts; no class header was available for this unit.
struct TexRef { void* p; };

struct TexObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(...);
};

struct Part;
struct Decal;

struct DecalView {
    char pad[0xbc];
    Part* part;
    TexRef tex;
    bool pending;
    char pad2[3];
    char* obj;
    char pad3[4];
    Decal* decal;
};

extern "C" {
    extern const float g_00942904, g_00942908, g_0094290c, g_009326f8;
    void* __fastcall fn_004e5bb0(Decal* self, int unusedEdx, std::string* out);
    void* fn_00465210(Part* p);
    void __fastcall fn_00598fa0(TexRef* self, int unusedEdx, void* p);
    void* fn_00551730();
    int __fastcall fn_00562670(void* self, int unusedEdx, int a1, int a2, int a3);
    int __fastcall fn_00551920(void* self, int unusedEdx, int a1, int a2, int a3);

    TexRef* __fastcall fn_004ec070(DecalView* self, int unusedEdx, TexRef* out)
    {
        if (self->pending) {
            std::string s;
            int status = 0;
            bool ok;
            {
                std::string tid;
                void* t = fn_004e5bb0(self->decal, 0, &tid);
                void* cp = fn_00465210(self->part);
                fn_00562670(cp, 0, (int)t, (int)&status, (int)&s);
                ok = (status == 1);
            }
            if (ok) {
                fn_00598fa0(&self->tex, 0, fn_00551730());
                int a = *(int*)(*(char**)&self->obj + 0xc);
                TexObj* newTex = (TexObj*)(void*)fn_00551920(&s, 0, a, (int)&s, 1);
                TexObj* cur = (TexObj*)self->tex.p;
                float back = 1.0f - *(float*)((char*)self->part + 0x328);
                TexRef r;
                r.p = 0;
                fn_00598fa0(&r, 0, newTex);
                char* d = (char*)self->decal;
                cur->v3(r, g_00942904, g_00942908, g_0094290c,
                        *(float*)(d + 0x164), *(float*)(d + 0x168), 0.0f, back);
                newTex->v3(g_009326f8);
                self->pending = false;
            }
        }
        out->p = 0;
        fn_00598fa0(out, 0, self->tex.p);
        return out;
    }
}
