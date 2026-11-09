// from server: 63% by atomic.potato
struct Sub {
    void method();
    char pad0[8];
    unsigned char flag;
    char pad1[0x80 - 9];
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
};

struct Obj {
    char pad[0x34];
    Sub* sub;
};

struct Stage {
    char pad[0x2c];
    Obj* obj;
    void func();
};

void Stage::func() {
    Sub* s = obj->sub;
    if (s) {
        if (s->flag)
            s->method();
        float v = s->f80;
        s->f84 = 0.0f;
        s->f88 = v;
        s->f8c = 0.0f;
        s->f90 = 0.0f;
        s->f94 = 0.0f;
        s->f98 = 0.0f;
    }
}
