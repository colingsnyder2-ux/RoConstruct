// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout/types guessed from disassembly; static local is a G3D::Array<bool> of per-normal facing flags.
struct Vec3 { float x, y, z; };
struct CFrame;
struct Face { unsigned a, b, c; };
struct Edge { unsigned v0, v1, f0, f1; };

extern "C" int  __fastcall fn_0054c290(void* self, int unusedEdx);
extern "C" bool* __fastcall fn_0054c2b0(void* self, int unusedEdx, int a1);
extern "C" Face* __fastcall fn_0054c030(void* self, int unusedEdx, int a1);
extern "C" int  __fastcall fn_0054b070(void* self, int unusedEdx, Vec3* a, Vec3* b, Vec3* c);
extern "C" Edge* __fastcall fn_0054bfc0(void* self, int unusedEdx, int a1);
extern "C" int  __fastcall fn_0054aed0(void* self, int unusedEdx, Vec3* a, Vec3* b);
extern "C" int  __fastcall fn_00442cd0(void* self, int unusedEdx);
extern "C" int  __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" Vec3* __fastcall fn_00518b80(void* self, int unusedEdx, unsigned i);
extern "C" float __fastcall fn_00510720(Vec3* self, int unusedEdx, Vec3* o);
extern "C" void __fastcall fn_0047ff20(void* self, int unusedEdx, int n, bool b);
extern "C" void __fastcall fn_00500690(void* self, int unusedEdx, int* a, int* b, int* c);
extern "C" void fn_004766a0_dummy();
extern "C" Vec3* __fastcall fn_004766a0(CFrame* self, int unusedEdx, Vec3* ret, Vec3* v);
extern "C" Vec3* __fastcall fn_005187c0(CFrame* self, int unusedEdx, Vec3* ret, Vec3* v);

struct FacingFlags {
    char data[16];
    FacingFlags() { fn_0054c290(this, 0); }
    ~FacingFlags() {}
};

struct Mesh {
    char pad0[0x18];
    char edges[0x0c];     // +0x18
    char normals[0x0c];   // +0x24
    char faces[0x0c];     // +0x30
    char verts[0x0c];     // +0x3c

    void build(CFrame* cf, Vec3* lightDir, void* indices, void* out, bool flag);
};

void Mesh::build(CFrame* cf, Vec3* lightDir, void* indices, void* out, bool flag)
{
    Vec3 objDir;
    fn_005187c0(cf, 0, &objDir, lightDir);

    static FacingFlags facing;

    fn_0047ff20(&facing, 0, fn_00442cd0(normals, 0), false);
    for (int i = 0; i < fn_00442cd0(normals, 0); ++i) {
        *fn_0054c2b0(&facing, 0, i) = fn_00510720(fn_00518b80(normals, 0, i), 0, &objDir) > 0.0;
    }

    if (flag) {
        for (int i = 0; i < fn_0054bf70(&facing, 0); ++i) {
            if (!*fn_0054c2b0(&facing, 0, i)) {
                int n = fn_00442cd0(out, 0);
                int i2 = n + 2, i1 = n + 1, i0 = n;
                fn_00500690(indices, 0, &i0, &i1, &i2);
                Face* f = fn_0054c030(faces, 0, i);
                Vec3* p0 = fn_00518b80(verts, 0, f->a);
                Vec3* p1 = fn_00518b80(verts, 0, f->b);
                Vec3* p2 = fn_00518b80(verts, 0, f->c);
                Vec3 w0, w1, w2;
                fn_0054b070(out, 0,
                    fn_004766a0(cf, 0, &w0, p0),
                    fn_004766a0(cf, 0, &w1, p1),
                    fn_004766a0(cf, 0, &w2, p2));
            }
        }
    }

    for (int i = 0; i < fn_0054bf70(edges, 0); ++i) {
        Edge* e = fn_0054bfc0(edges, 0, i);
        bool b0 = *fn_0054c2b0(&facing, 0, e->f0);
        bool b1 = *fn_0054c2b0(&facing, 0, e->f1);
        if (b0 != b1) {
            Vec3* a = fn_00518b80(verts, 0, e->v0);
            Vec3* b = fn_00518b80(verts, 0, e->v1);
            Vec3 wa, wb;
            fn_004766a0(cf, 0, &wa, a);
            fn_004766a0(cf, 0, &wb, b);
            int n = fn_00442cd0(out, 0);
            fn_0054aed0(out, 0, &wa, &wb);
            int x, y;
            if (b0) { x = n; y = n + 1; } else { x = n + 1; y = n; }
            int z = 0;
            fn_00500690(indices, 0, &x, &y, &z);
        }
    }
}
