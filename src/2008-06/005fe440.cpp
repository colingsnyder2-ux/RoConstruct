// from server: 100% by king_originala
struct Data
{
    unsigned int a, b, c, d, e, f;
};

extern bool __cdecl func_0060a2f0();
extern unsigned char global_00841990;

struct S
{
    void* tag;
    unsigned int padding;
    Data data;

    void f(const Data* source);
};

void S::f(const Data* source)
{
    if (!((bool (__cdecl *)(const Data*))func_0060a2f0)(source))
    {
        Data* destination = &data;
        if (destination)
        {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            destination->d = source->d;
            destination->e = source->e;
            destination->f = source->f;
        }
        tag = &global_00841990;
    }
    else
    {
        tag = 0;
    }
}
