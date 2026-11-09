// from server: 40% by atomic.potato
struct Inner {
    char pad0[32];
    int f();
};

struct Outer {
    char pad0[0x10];
    Inner* a;
    Inner* b;
};

struct Node {
    char pad0[0x24];
    char* ptr;
};

struct Getter {
    char pad[0xf4];
    char* ptr;
    char get() const;
};

char Getter::get() const
{
    return *(char*)(ptr + 0x3c);
}

int Inner::f()
{
    return *(int*)((char*)this + 32);
}

bool Assembly_006767f0(Outer* self)
{
    Node* p1;
    Node* p2;

    Inner* i1 = self->a;
    if (i1 != 0) {
        Inner* t = (Inner*)((char*)i1 + 8);
        int r = t->f();
        if (r != 0) {
            Inner* t2 = (Inner*)((char*)r + 8);
            int r2 = t2->f();
            if (r2 != 0) {
                p1 = (Node*)(r2 - 8);
            } else {
                p1 = 0;
            }
        } else {
            p1 = 0;
        }
    } else {
        p1 = 0;
    }

    Inner* i2 = self->b;
    if (i2 != 0) {
        Inner* t = (Inner*)((char*)i2 + 8);
        int r = t->f();
        if (r != 0) {
            Inner* t2 = (Inner*)((char*)r + 8);
            int r2 = t2->f();
            if (r2 != 0) {
                p2 = (Node*)(r2 - 8);
            } else {
                p2 = 0;
            }
        } else {
            p2 = 0;
        }
    } else {
        p2 = 0;
    }

    char* c1 = p1->ptr;
    char* v1 = *(char**)(c1 + 0x1c);
    Getter* g1;
    if (v1 != 0) {
        g1 = (Getter*)(v1 - 8);
    } else {
        g1 = 0;
    }
    if (!g1->get()) {
        return false;
    }

    char* c2 = p2->ptr;
    char* v2 = *(char**)(c2 + 0x1c);
    Getter* g2;
    if (v2 != 0) {
        g2 = (Getter*)(v2 - 8);
    } else {
        g2 = 0;
    }
    if (!g2->get()) {
        return false;
    }

    return true;
}
