// from server: 42% by atomic.potato
extern "C" void CallAt54(void* object, int value);

struct S
{
    void* vtable;
    char padding[0x84];
    void* value;
    void* f(int);
};

void* S::f(int value)
{
    void* result = this;
    CallAt54(*(void**)this, 0);
    value = (int)*(void**)((char*)this + 0x88);
    return (void*)value;
}
