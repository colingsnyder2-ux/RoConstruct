// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Vector4 {
    float x, y, z, w;
};

const Vector3& __cdecl getVector();

struct Decal {
    void* getTexture();
};

void __cdecl renderDecal(void*, int, int, const Vector4*);

struct DecalTool {
    char padding0[0x18];
    Decal* decal;
    char padding1[8];
    int face;

    void render(int);
};

void DecalTool::render(int argument)
{
    if (decal) {
        const Vector3& v = getVector();
        Decal* d = decal;
        Vector4 color = { v.x, v.y, v.z, 1.0f };
        renderDecal(d->getTexture(), face, argument, &color);
    }
}
