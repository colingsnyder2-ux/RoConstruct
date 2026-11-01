// from server: 100% by king_originala
struct Primitive;
struct Joint;

struct World {
    void detachJoint(Joint*, Primitive*);
    void attachJoint(Joint*, Primitive*);
};

struct Owner {
    virtual void reserved();
    virtual int getKind();
    Owner* parent;
    unsigned int padding;
    World* world;
};

struct Edge {
    unsigned int header;
    Owner* owner;
    unsigned int padding;
    Primitive* primitives[2];

    void setPrimitive(int, Primitive*);
};

struct Joint : Edge {
    void f(int, Primitive*);
};

void Joint::f(int index, Primitive* primitive)
{
    if (primitive == primitives[index])
        return;

    World* world;
    if (owner == 0) {
        world = 0;
    } else {
        Owner* object;
        if (owner->getKind() == 7)
            object = owner->parent;
        else
            object = owner;
        world = object->world;

        if (world && primitives[index])
            world->detachJoint(this, primitives[index]);
    }

    Edge::setPrimitive(index, primitive);

    if (world && primitive)
        world->attachJoint(this, primitive);
}
