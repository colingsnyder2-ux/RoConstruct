// from server: 100% by king_originala
struct Pair
{
    unsigned int data[2];
};

struct Value
{
    unsigned int data[5];
    void destroy();
};

struct Product
{
    unsigned int data[5];
    Product* copy(const Pair*);
};

extern bool __cdecl func_0060a2f0(const Pair*);
extern unsigned char descriptor[];

struct S
{
    void* descriptorPointer;
    unsigned int reserved;
    Product product;

    S* initialize(Pair, Value);
};

S* S::initialize(Pair source, Value value)
{
    descriptorPointer = 0;
    if (!func_0060a2f0(&source))
    {
        Product* destination = &product;
        if (destination)
            destination->copy(&source);
        descriptorPointer = descriptor;
        value.destroy();
        return this;
    }

    descriptorPointer = 0;
    value.destroy();
    return this;
}
