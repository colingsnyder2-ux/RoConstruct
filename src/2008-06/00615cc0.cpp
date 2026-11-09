// from server: 100% by king_originala
struct Value
{
    char data[28];
};

struct Buffer
{
    volatile int zero;
    Value value;
};

extern "C" void __cdecl build(Value*, void*, void*);
extern "C" void __cdecl copy(void*, const Value*);

void* __cdecl f(void* destination, void* a, void* b)
{
    Buffer buffer;
    buffer.zero = 0;
    build(&buffer.value, a, b);
    copy(destination, &buffer.value);
    return destination;
}
