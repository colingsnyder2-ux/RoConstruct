// from server: 100% by colin
// from server: 75% by king_originala
extern float baseline;

struct Model;

struct Bounds {
    float values[6];
};

struct ModelVTable {
    void* slots[21];
    Bounds* (__thiscall *getBounds)(Model*, Bounds*);
};

struct Model {
    ModelVTable* vtable;
    char padding[0x1DC];
    Model* parent;

    double getOffset();
};

double Model::getOffset()
{
    double result = baseline;
    if (parent != 0) {
        Bounds bounds;
        float parentValue =
            parent->vtable->getBounds(parent, &bounds)->values[4];
        result = vtable->getBounds(this, &bounds)->values[4]
               - parentValue + baseline;
    }
    return result;
}
