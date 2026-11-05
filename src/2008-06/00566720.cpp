// from server: 100% by king_originala
extern unsigned char notification;

struct S {
    unsigned char padding[0x138];
    bool value;
    void notify(void*);
    void setValue(bool);
};

void S::setValue(bool v)
{
    if (value != v) {
        value = v;
        notify(&notification);
    }
}
