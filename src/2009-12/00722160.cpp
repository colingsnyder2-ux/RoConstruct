// from server: 78% by atomic.potato
struct S {
    char pad[0x3c];
    int flags;
    virtual int vf(int);
};

extern "C" int __stdcall pubsync(void*);

int __cdecl f(S* p, int, int x) {
    if (x == 2) {
        pubsync(p);
        int f = p->flags;
        if (!(f & 4)) {
            p->flags = f | 4;
            p->vf(2);
        }
    } else if (x == 1) {
        int f = p->flags;
        if (!(f & 2)) {
            p->flags = f | 2;
            p->vf(1);
        }
    }
    return 0;
}
