// from server: 100% by king_originala
struct Bounds {
    float x0, y0, z0;
    float x1, y1, z1;
};

struct BoundsCache {
    Bounds get();
};

struct ModelInstance {
    char pad[0x258];
    BoundsCache cache;
    Bounds getBounds();
};

Bounds ModelInstance::getBounds() {
    Bounds temporary = cache.get();
    Bounds result;
    result.x0 = temporary.x0;
    result.y0 = temporary.y0;
    result.z0 = temporary.z0;
    result.x1 = temporary.x1;
    result.y1 = temporary.y1;
    result.z1 = temporary.z1;
    return result;
}
