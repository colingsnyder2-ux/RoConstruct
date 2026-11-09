// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

struct Ball;
struct World {
    void changed(Ball*);
};
struct Ball {
    char pad[0x58];
    World* world;
    char pad2[0xb4 - 0x5c];
    float value;
    void setValue(float v);
};

void Ball::setValue(float v) {
    if (v != value) {
        value = v;
        if (world)
            world->changed(this);
    }
}
