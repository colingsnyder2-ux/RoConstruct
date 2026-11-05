// from server: 100% by king_originala
extern int property;

struct S {
    char padding[0x170];
    int value;

    void setValue(const int& v);
    void notify(const int* p);
    void changed();
};

void S::setValue(const int& v)
{
    if (v != value) {
        value = v;
        notify(&property);
        changed();
    }
}
