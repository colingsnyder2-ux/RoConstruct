// from server: 100% by king_originala
#pragma optimize("", off)

struct S {
    char padding[0x28];
    int value;
    void setValue(int v);
};

void S::setValue(int v) {
    value = v;
}
