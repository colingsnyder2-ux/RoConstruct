// from server: 100% by king_originala
struct Source {
    char reserved[0x94];
    char data;
    const void* get();
};

struct Temporary {
    char data[0x30];
    ~Temporary();
};

struct Primitive {
    char reserved[0xA0];
    Source* source;

    Temporary* process(Temporary*, const void*, void*, const void*);
    void* func_005e81b0(void*, const void*);
};

void* Primitive::func_005e81b0(void* output, const void* input)
{
    char storage[0x30];
    Source* s = source;
    s->get();
    process(reinterpret_cast<Temporary*>(storage), input, output, &s->data)->~Temporary();
    return output;
}
