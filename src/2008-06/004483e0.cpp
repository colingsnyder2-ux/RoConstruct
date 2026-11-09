// from server: 100% by king_originala
struct Converter {
    void __thiscall convert(void* output, int* value);
};

struct Descriptor {
    char padding[0x1c];
    void* source;
    Converter* converter;

    void* convert(void* output, int value);
};

void* Descriptor::convert(void* output, int value)
{
    volatile int temporary = 0;
    int* table = *reinterpret_cast<int**>(source);
    value = reinterpret_cast<int (__thiscall*)(void*, int)>(table[2])(source, value);
    converter->convert(output, &value);
    return output;
}
