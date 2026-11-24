// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were supplied, so the types below are minimal local stand-ins.
// INFERRED: the call shapes (Vector3 by value, ctor tail args, buildFace args) are read off the disassembly.
#include <new>

extern "C" int fn_006a0920(int a1);

struct Vector3 { float x, y, z; };
struct Vector2 { float x, y; };

struct Level {
    virtual ~Level();
    int refCount;
    Level(int primitive);
};

struct LevelPtr {
    Level* p;
};

struct LevelArray {
    void append(LevelPtr* const& v);
};

struct Mesh {
    int vtbl;
    LevelArray levels;
    Mesh();
};

struct LevelBuilder {
    int pad[16];
    float uvScaleX;
    float uvScaleY;
    LevelBuilder(LevelPtr& level, Vector3 size, int arg);
    void buildFace(int normalId, int purpose);
};

Vector3* mapToUvw_Legacy(Vector3* out, const Vector3* size, int normalId);
Vector2 x0y0(const Vector3* v);
extern const float kUvScale;

extern "C" Mesh* __fastcall fn_004fd270(Mesh* self, int unusedEdx, const Vector3* size, int normalId, int arg3)
{
    LevelPtr level;
    Level* raw = (Level*)fn_006a0920(0x28);
    level.p = raw ? new (raw) Level(5) : 0;

    self->levels.append(&level);

    LevelBuilder builder(level, *size, 0);
    Vector3 tmp;
    Vector2 uv = x0y0(mapToUvw_Legacy(&tmp, size, normalId));
    builder.uvScaleX = uv.x * kUvScale / size->x;
    builder.uvScaleY = uv.y * kUvScale / size->y;
    builder.buildFace(normalId, 1);
    return self;
}
