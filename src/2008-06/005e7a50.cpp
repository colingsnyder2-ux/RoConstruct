// from server: 100% by king_originala
struct Box {
    float x0, y0, z0;
    float x1, y1, z1;
};

struct Source {
    char reserved[0x90];
    unsigned int version;
    const void* get();
};

struct Geometry {
    char reserved0[0x80];
    volatile Box bounds;
    unsigned int version;
    char reserved1[4];
    Source* volatile source;

    Box* calculate(Box* result);
    const Box& getBounds();
};

const Box& Geometry::getBounds() {
    Source* current = source;
    current->get();
    if (version != current->version) {
        Box temporary;
        const Box* result = calculate(&temporary);
        bounds.x0 = result->x0;
        bounds.y0 = result->y0;
        bounds.z0 = result->z0;
        bounds.x1 = result->x1;
        bounds.y1 = result->y1;
        bounds.z1 = result->z1;
        current = source;
        current->get();
        version = current->version;
    }
    return const_cast<const Box&>(bounds);
}
