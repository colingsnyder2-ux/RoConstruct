// from server: 80% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    S *f(unsigned int);
};

struct T
{
    char data[0x18];
};

extern "C" T *CreateObject();

S *S::f(unsigned int flags)
{
    S *result = this;

    if (flags & 1)
    {
        T *object = CreateObject();
        EnterCriticalSection(object);
        result->f(0);
        object->data[0x18] = 0;
        LeaveCriticalSection(object);
    }

    return result;
}
