// from server: 100% by king_originala
struct S {
    char pad0[0x10];
    int value;
    char pad1[8];
    S** children;
    int count;

    void setValue(int v);
};

void S::setValue(int v)
{
    value = v;
    for (int i = 0; i < count; ++i)
        children[i]->setValue(v);
}
