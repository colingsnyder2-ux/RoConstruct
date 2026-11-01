// from server: 100% by king_originala
struct VerbWidget {
    unsigned long data[0x148 / 4];

    VerbWidget();
    ~VerbWidget();
    void setVerb(void *);
};

struct ImageButton : VerbWidget {
    void *owner;
    unsigned char active;

    ImageButton(void *, void *);
};

ImageButton::ImageButton(void *verb, void *context)
    : VerbWidget(), owner(context)
{
    data[0x00 / 4] = 0x84b70c;
    data[0x10 / 4] = 0x84b6fc;
    data[0x14 / 4] = 0x84b6f4;
    data[0x20 / 4] = 0x84b6ec;
    data[0x24 / 4] = 0x84b6dc;
    data[0x44 / 4] = 0x84b6cc;
    data[0x64 / 4] = 0x84b6bc;
    data[0x84 / 4] = 0x84b6ac;
    data[0xa4 / 4] = 0x84b69c;
    data[0xc4 / 4] = 0x84b68c;
    data[0x130 / 4] = 0x84b684;
    active = 0;
    setVerb(verb);
}
