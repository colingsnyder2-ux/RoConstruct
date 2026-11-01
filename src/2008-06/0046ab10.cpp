// from server: 100% by king_originala
struct Value
{
    unsigned char data[16];
    ~Value();
};

struct Target
{
    void func_00555350();
};

struct S
{
    unsigned char padding[20];
    Target* target;
    void func_0046ab10(int, Value);
};

void S::func_0046ab10(int, Value)
{
    target->func_00555350();
}
