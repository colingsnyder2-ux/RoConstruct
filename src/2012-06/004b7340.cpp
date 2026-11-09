// from server: 56% by atomic.potato
struct CVideoStream
{
    int Query(void*);
};

int CVideoStream::Query(void* arg)
{
    struct V
    {
        int (**vtable)();
    };

    V* object = *(V**)((char*)this + 0x9c);
    if (object == 0)
        return (int)0x80040209;

    int (**table)() = object->vtable;
    return ((int (__thiscall*)(V*, void*))table[6])(object, arg);
}
