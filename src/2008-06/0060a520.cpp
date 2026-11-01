// from server: 100% by king_originala
struct Transform {
    float rotation[9];
    float x, y, z;

    Transform();
};

extern float firstScale;
extern float secondScale;

extern "C" const void* __cdecl getColor();
extern "C" void __cdecl draw(
    void* context, const Transform& transform, int mode,
    float scale1, float scale2, const void* color);

struct Feature {
    bool get(Transform& result);
    void render(void* context, void* unused);
};

void Feature::render(void* context, void* unused)
{
    Transform transform;
    Feature* owner = reinterpret_cast<Feature*>(
        reinterpret_cast<char*>(this) - 0x130);

    if (owner->get(transform)) {
        const void* color = getColor();
        draw(context, transform, 2, firstScale, secondScale, color);
    }
}
