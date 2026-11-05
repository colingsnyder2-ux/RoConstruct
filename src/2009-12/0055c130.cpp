// from server: 55% by atomic.potato
typedef float FLOAT;
typedef double DOUBLE;

struct S
{
    void* GetValue();
    int f(int a, int b);
};

extern "C" void* sub_523e90(S*);
extern "C" int sub_7e7f30(S*, int, int, double);

void* S::GetValue()
{
    return sub_523e90(this);
}

int S::f(int a, int b)
{
    FLOAT value = *(FLOAT*)((char*)GetValue() + 0xd8);
    sub_7e7f30(this, b, a, (DOUBLE)value);
    return b;
}
