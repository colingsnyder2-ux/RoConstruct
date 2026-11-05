// from server: 44% by atomic.potato
struct Vector3
{
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct MyStruct;

struct Inner
{
    void method(MyStruct* outer, Vector3 v, int flags);
};

void* G1_func_006997a0(void* self);

struct MyStruct
{
    void func(float a, float b, float c);
};

void MyStruct::func(float a, float b, float c)
{
    Inner* p = (Inner*)G1_func_006997a0(this);
    if (p)
        p->method(this, Vector3(a, b, c), 2);
}
