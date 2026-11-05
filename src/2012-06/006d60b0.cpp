// from server: 49% by atomic.potato
struct E {
    void* vf;
    char pad[8];
    int a;
    int b;
    void* c;
    int d;
    int e;
    int f;
    int g;
};

extern "C" void __stdcall sub_b229e4(void*);

struct S {
    void f(E* other);
};

void S::f(E* other) {
    E* self = (E*)this;
    self->vf = (void*)0xb98880;
    sub_b229e4(self);
    self->a = other->a;
    self->b = other->b;
    self->c = (void*)0xb43e60;
    self->d = 0;
    self->e = 0;
    self->f = 0;
    self->g = -1;
    self->vf = (void*)0xb98fb8;
    self->c = (void*)0xb98fb0;
}
