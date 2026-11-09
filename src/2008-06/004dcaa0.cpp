// from server: 100% by king_originala
struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };

extern Vec3* positions;
extern Vec3* normals;
extern Vec2* texcoords;

extern int __cdecl makeVertex(const Vec3*, const Vec3*, const Vec2*, int);

struct Handle {
    int value;
    Handle(int);
};

inline Handle::Handle(int n) : value(n) {}

struct Renderer {
    void draw(const Handle&, const Handle&, const Handle&, const Handle&);
};

struct Context {
    char padding[12];
    Renderer renderer;
};

void __stdcall submit(Context** context, int a, int b, int c, int d, int* output)
{
    {
        Vec2* t = texcoords + a;
        Vec3* n = normals;
        Vec3* p = positions;
        n += a;
        p += a;
        output[0] = makeVertex(p, n, t, 1);
    }
    {
        Vec2* t = texcoords + b;
        Vec3* n = normals;
        Vec3* p = positions;
        n += b;
        p += b;
        output[1] = makeVertex(p, n, t, 1);
    }
    {
        Vec2* t = texcoords + c;
        Vec3* n = normals;
        Vec3* p = positions;
        n += c;
        p += c;
        output[2] = makeVertex(p, n, t, 1);
    }
    {
        Vec2* t = texcoords + d;
        Vec3* n = normals;
        Vec3* p = positions;
        n += d;
        p += d;
        output[3] = makeVertex(p, n, t, 1);
    }
    (*context)->renderer.draw(output[0], output[1], output[2], output[3]);
}
