// from server: 100% by colin
struct Sub {
    char pad[0x14c];
    int state;
};

struct Inner {
    Sub* getSub(int);
};

struct S {
    char pad[0x10];
    Inner inner;
    int isEnabled() const;
};

int S::isEnabled() const
{
    Sub* s = ((S*)this)->inner.getSub(1);
    int v = s->state;
    if (v == 1 || v == 2)
        return 1;
    return 0;
}
