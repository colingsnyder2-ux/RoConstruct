// from server: 100% by colin
struct Inner {
    char pad[0x50];
    unsigned char field;
};

struct Outer {
    char pad[0x27c];
    Inner* inner;
    void setField(unsigned char value);
};

void Outer::setField(unsigned char value) {
    inner->field = value;
}
