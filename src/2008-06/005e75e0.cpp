// from server: 100% by king_originala
struct S {
    unsigned char padding[0xAB];
    unsigned char value;
    void setValue(unsigned char v);
};

void S::setValue(unsigned char v)
{
    if (v != value)
        value = v;
}
