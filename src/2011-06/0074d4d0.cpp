// from server: 66% by atomic.potato
struct A;
struct B;

extern "C" {
    A* __stdcall sub_6a37c0(void* p);
    A* __stdcall sub_6a37e0(void* p, A* q);
    bool __stdcall sub_759b60(A* p, float f);
    int* __stdcall sub_7ef2e0(void* p, int* a, int* b);
}

struct A {
    char pad0[0xc];
    A* f0c;
    A* f10;
};

struct B {
    char pad0[4];
    int f4;
};

bool __stdcall f(B* self, void* a, float f, int b) {
    A* p = sub_6a37c0(a);
    while (p) {
        A* q = p->f0c;
        if (q == a) q = p->f10;
        int tmp = (int)q;
        int* r = sub_7ef2e0(self, &tmp, &tmp);
        if (*r == self->f4) {
            if (sub_759b60(p, f)) return true;
        }
        p = sub_6a37e0(a, p);
    }
    return false;
}
