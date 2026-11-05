// from server: 100% by king_originala
struct Transform {
    float data[12];
};

struct Source {
    void read(Transform* result);
};

struct Node {
    char padding[0xA0];
    Source* source;
};

struct Link {
    char padding[0x1C];
    Node* node;
};

struct Controller {
    void apply(Transform* transform, float depth);
    void finish(Transform* transform, float depth, float scale);
};

struct Owner {
    char padding[8];
    Controller controller;
};

typedef float (__thiscall* Getter)(void*);

struct Object {
    char padding0[0x18];
    Owner* owner;
    char padding1[8];
    Link* link;
    char padding2[0x28];
    float depth;
    unsigned char dirty;
    char padding3[3];
    char* context;
    int reserved;
    Getter getter;
    int adjustment;
};

extern const float scale;

#pragma float_control(precise, off, push)

void __stdcall update(Object* object)
{
    Transform transform;
    object->link->node->source->read(&transform);

    if (object->dirty) {
        object->depth = object->getter(object->context + object->adjustment);
        object->dirty = 0;
    }

    float depth = object->depth;
    Controller* controller = &object->owner->controller;
    controller->apply(&transform, depth);
    controller->finish(&transform, depth, scale);
}

#pragma float_control(pop)
