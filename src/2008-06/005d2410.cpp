// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Storage {
    void *value;
    void clear();
};

struct S {
    unsigned int data[0x130 / 4];
    Storage storage;
    void destroy();
    void finish();
};

void S::destroy()
{
    Storage *p = &storage;

    data[0x000 / 4] = 0x83bd2c;
    data[0x010 / 4] = 0x83bd1c;
    data[0x014 / 4] = 0x83bd14;
    data[0x020 / 4] = 0x83bd0c;
    data[0x024 / 4] = 0x83bcfc;
    data[0x044 / 4] = 0x83bcec;
    data[0x064 / 4] = 0x83bcdc;
    data[0x084 / 4] = 0x83bccc;
    data[0x0a4 / 4] = 0x83bcbc;
    data[0x0c4 / 4] = 0x83bcac;

    p->clear();
    release(p->value);
    finish();
}
