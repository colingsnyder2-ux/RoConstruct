// from server: 100% by colin
struct Vector3 { float x, y, z; };

struct Item {
    int getBulletSphereShape() const;
    const Vector3& getValue();
    const void* get();
};

struct Kind {
    int value;
};

struct Link {
    char pad[0x1c];
    Item* item;
};

struct Shape {
    char pad0[0x18];
    Kind* kind;
    char pad1[8];
    Link* link;
};

struct Service {
    char pad[0xac];
    Item** items;
    int count;
    void f(void*);
};

void Service::f(void*)
{
    for (int i = 0; i < count; ++i) {
        Item* item = items[i];
        Shape* shape = (Shape*)item->getBulletSphereShape();
        bool special;

        if (!shape->kind)
            goto ordinary;
        if (shape->kind->value == 3 || shape->kind->value == 1 || shape->kind->value == 2)
            goto chosen;
ordinary:
        special = false;
        goto process;
chosen:
        special = true;
        if (item != shape->link->item)
            continue;
process:

        item->getValue();
        if (!special)
            item->get();
    }
}
