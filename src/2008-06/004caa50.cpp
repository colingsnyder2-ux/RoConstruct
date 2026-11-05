// from server: 57% by king_originala
struct Item {
    char padding[0x8c];
    float value;
};

struct Collection {
    int count();
    Item* get(int index);
};

struct Handle {
    Collection* resolve();
};

struct Output {
    void writeFour(float a, float b, float c, float d);
};

struct S {
    float a, b, c, d;
    char padding[0x218];
    Handle handle;
    bool f(Output* output, float scratch);
};

extern void __cdecl writeByte(void* output, unsigned char value);
extern unsigned char __cdecl encode(float value);

bool S::f(Output* output, float scratch)
{
    float values[4];
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;

    output->writeFour(scratch = values[0],
                      values[1], values[2], values[3]);

    Collection* collection = handle.resolve();
    int count = collection ? collection->count() : 0;
    writeByte(output, (unsigned char)count);

    for (int i = 0; i < count; ++i) {
        scratch = 0.0f;
        Item* item = collection->get(i);
        unsigned char value = encode(item ? item->value : scratch);
        *(unsigned char*)&scratch = value;
        writeByte(output, *(unsigned char*)&scratch);
    }

    return true;
}
