// from server: 100% by king_originala
extern const char descriptor;

struct S {
    char padding[0x1e8];
    unsigned char reserved : 3;
    unsigned char selected : 1;
    unsigned char remaining : 4;

    void setSelected(bool value);
    void notify(const void* property);
};

void S::setSelected(bool value)
{
    if (selected != value) {
        selected = value;
        notify(&descriptor);
    }
}
