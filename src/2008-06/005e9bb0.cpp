// from server: 100% by king_originala
struct Ball;

struct Owner {
    char padding[0x1c];
    Ball* ball;
};

struct Shape {
    char padding0[0x18];
    int* kind;
    char padding1[8];
    Owner* owner;
};

struct Ball {
    int getBulletSphereShape() const;
    void update();
    const void* get();
};

struct BallList {
    Ball** data;
    int size;
    int capacity;

    void resize(int size, int value);
    void append(Ball* const& ball);
};

struct S {
    char padding0[0xac];
    Ball** balls;
    int count;
    int padding1;
    BallList selected;

    void f();
};

void S::f()
{
    selected.resize(0, 1);
    for (int i = 0; i < count; ++i) {
        Ball* ball = balls[i];
        Ball* entry = ball;
        Shape* shape = reinterpret_cast<Shape*>(ball->getBulletSphereShape());
        if (shape->kind) {
            int kind = *shape->kind;
            if (kind == 3 || kind == 1 || kind == 2) {
                selected.append(entry);
                if (ball != shape->owner->ball)
                    ball->update();
                ball->get();
            }
        }
    }
}
