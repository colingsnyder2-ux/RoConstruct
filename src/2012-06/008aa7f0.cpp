// from server: 50% by atomic.potato
struct ConstraintSurfacePair
{
    void f();
    int* begin;
    int* end;
};

void ConstraintSurfacePair::f()
{
    int count = (int)(((char*)end - (char*)begin) >> 2);
    int i = 0;

    if (count > 0)
    {
        do
        {
            void* object = (void*)begin[i];
            void** vtable = *(void***)object;
            typedef void (__thiscall *Function)(void*);
            ((Function)vtable[2])(object);
            ++i;
            count = (int)(((char*)end - (char*)begin) >> 2);
        }
        while (i < count);
    }
}
