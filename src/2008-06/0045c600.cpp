// from server: 100% by king_originala
struct Instance {};

struct Part {
    void setValue(float value);
};

struct Model {
    void visit(void (__cdecl *callback)(Instance*));
};

extern const char instanceType;
extern const char partType;
extern const char modelType;

extern "C" void* __cdecl castObject(
    void* object, int offset, const void* sourceType,
    const void* targetType, int isReference);

void __cdecl apply(Instance* object)
{
    Part* part = static_cast<Part*>(
        castObject(object, 0, &instanceType, &partType, 0));

    if (part) {
        part->setValue(1.0f);
        return;
    }

    Model* model = static_cast<Model*>(
        castObject(object, 0, &instanceType, &modelType, 0));

    if (model)
        model->visit(apply);
}
