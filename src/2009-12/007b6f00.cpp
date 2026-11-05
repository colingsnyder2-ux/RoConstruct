// from server: 69% by atomic.potato
struct Sub {
    char pad0[8];
    char flag8;
    char pad9[0x9c - 9];
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
    float fb0;
};

struct Inner {
    char pad0[0x34];
    Sub* p34;
};

struct CleanStage {
    char pad0[0x2c];
    Inner* p2c;
    void f();
};

extern "C" void __fastcall sub_7a5390(Sub* s);

void CleanStage::f() {
    Sub* s = p2c->p34;
    if (s) {
        if (s->flag8) {
            sub_7a5390(s);
        }
        s->f9c = 0.0f;
        s->fa0 = 0.0f;
        s->fa4 = 0.0f;
        s->fa8 = 0.0f;
        s->fac = 0.0f;
        s->fb0 = 0.0f;
    }
}
