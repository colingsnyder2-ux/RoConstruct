// from server: 62% by atomic.potato
extern "C" void Function_00961360(void *, void *);

struct S
{
    int field_1c;
    void *field_aa0;
    void f();
};

void S::f()
{
    void *value = *(void **)((char *)this->field_1c + 0xaa0);
    Function_00961360(value, &value);
}
