// from server: 56% by atomic.potato
struct S
{
    void f(int);
};

extern "C" void* sub_76e680(void*);
extern "C" void sub_76a190(void*, void*);

void S::f(int value)
{
    void* result;
    void* value2;

    result = sub_76e680((char*)this + value + 4);
    value2 = *(void**)result;
    sub_76a190(this, &value2);
}
