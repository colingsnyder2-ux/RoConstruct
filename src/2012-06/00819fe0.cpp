// from server: 75% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefObject
{
    void* vtable;
    volatile long references;
};

struct ChatService
{
};

void __cdecl f(RefObject* first, RefObject* last)
{
    while (first != last)
    {
        RefObject* object = first->references ? *(RefObject**)((char*)first + 4) : 0;
        if (object)
        {
            if (_InterlockedExchangeAdd(&object->references, -1) == 1)
            {
                typedef void (__thiscall *Destroy)(RefObject*);
                Destroy destroy = (Destroy)(*(void**)((char*)object->vtable + 8));
                destroy(object);
            }
        }
        first = (RefObject*)((char*)first + 0x18);
    }
}
