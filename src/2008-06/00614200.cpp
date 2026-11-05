// from server: 100% by king_originala
struct Matrix {
    float elements[9];
};

struct Transform {
    Matrix rotation;
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;

    Transform& operator=(const Transform& value);
};

inline Transform& Transform::operator=(const Transform& value)
{
    rotation = value.rotation;
    x0 = value.x0;
    y0 = value.y0;
    z0 = value.z0;
    x1 = value.x1;
    y1 = value.y1;
    z1 = value.z1;
    x2 = value.x2;
    y2 = value.y2;
    z2 = value.z2;
    return *this;
}

struct Source {
    char padding[12];
    Transform transform;

    void fastUpdate();
    void update();
    Transform* calculate(Transform* result);
};

static int generation;

struct Link {
    char padding0[0x28];
    int mode;
    Source* source;
    bool enabled;
    char padding1[0x5f];
    int stamp;
    Transform transform;

    void refresh(bool fast);
};

void Link::refresh(bool fast)
{
    volatile int unused = 0;
    Transform temporary;

    if (fast && enabled) {
        source->fastUpdate();
        return;
    }

    source->update();

    const Transform* value;
    if (mode == 0)
        value = &source->transform;
    else
        value = source->calculate(&temporary);

    transform = *value;

    int next = ++generation;
    if (next == 0x7fffffff)
        generation = next = 1;
    stamp = next;
}
