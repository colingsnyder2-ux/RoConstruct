// from server: 49% by colin
struct Exposer {
    char pad[0x18];
    float x;
    float y;
    float z;
    float w;

    bool Check(const Exposer* other);
};

extern float g_79eb38;
extern double g_79eb40;

bool Exposer::Check(const Exposer* other) {
    float dx = x - other->x;
    float adx = dx < 0.0f ? -dx : dx;
    if (!(adx > (float)g_79eb40)) {
        return false;
    }
    float dy = y - other->y;
    float ady = dy < 0.0f ? -dy : dy;
    if (!(ady > (float)g_79eb40)) {
        return false;
    }
    float dz = z - other->z;
    float adz = dz < 0.0f ? -dz : dz;
    if (!(adz > (float)g_79eb40)) {
        return false;
    }
    float limit = g_79eb38;
    for (int i = 0; i < 3; ++i) {
        float a0 = (&x)[i];
        float a1 = (&x)[i + 3];
        float b0 = (&other->x)[i];
        float b1 = (&other->x)[i + 3];
        float d0 = a0 - b0;
        float d1 = a1 - b1;
        float d2 = (&w)[i] - (&other->w)[i];
        float dist2 = d0 * d0 + d1 * d1 + d2 * d2;
        if (!(dist2 < limit)) {
            return false;
        }
    }
    return true;
}
