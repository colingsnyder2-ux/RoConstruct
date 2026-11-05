// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Storage {
    void *head;
    unsigned char padding[24];
    void clear();
};

struct S {
    unsigned long words[76];
    Storage storage;

    void f();
    void cleanup();
};

void S::f()
{
    words[0]  = 0x008461ec;
    words[4]  = 0x008461dc;
    words[5]  = 0x008461d4;
    words[8]  = 0x008461cc;
    words[9]  = 0x008461bc;
    words[17] = 0x008461ac;
    words[25] = 0x0084619c;
    words[33] = 0x0084618c;
    words[41] = 0x0084617c;
    words[49] = 0x0084616c;

    storage.clear();
    release(storage.head);
    cleanup();
}
