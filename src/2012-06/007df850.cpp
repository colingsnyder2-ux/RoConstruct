// from server: 66% by atomic.potato
extern "C" void Function_00523480(void*, void*, void*);

struct S
{
    void* f(void*);
};

void* S::f(void* value)
{
    S* object = (S*)((char*)this + 4);
    Function_00523480(object, value, 0);
    return value;
}
