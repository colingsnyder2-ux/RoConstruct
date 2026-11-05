// from server: 93% by atomic.potato
struct Value
{
    unsigned char pad[0x18];
    unsigned int size;
    void* data;
};

extern "C" void* __cdecl sub_6b0de0(void*, void*);

unsigned char __cdecl function_6b2490(void* a, void* b, void* c)
{
    Value* value = (Value*)a;
    void* source;

    if (value->size >= 0x10)
        source = value->data;
    else
        source = (char*)value + 4;

    void* result = sub_6b0de0(&b, source);
    *(void**)c = *(void**)result;
    return 1;
}
