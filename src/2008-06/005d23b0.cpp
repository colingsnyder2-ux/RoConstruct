// from server: 100% by colin
struct Data {
    unsigned long a, b, c, d, e, f;
};

extern bool __cdecl func_0060a2f0();
extern unsigned char tag;

struct S {
    const void *type;
    unsigned long unused;
    Data data;

    void f(const Data &value);
};

void S::f(const Data &value)
{
    if (!reinterpret_cast<bool (__cdecl *)(const Data *)>(
            &func_0060a2f0)(&value)) {
        Data *destination = &data;
        if (destination)
            *destination = value;
        type = &tag;
    } else {
        type = 0;
    }
}
