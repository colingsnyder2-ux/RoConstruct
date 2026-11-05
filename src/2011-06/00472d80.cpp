// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VerbBinder {
    VerbBinder();
    void* m_object;
};

extern "C" void* create_471700(void*, void*);

VerbBinder::VerbBinder()
{
    void* value = create_471700(0, &m_object);
    m_object = value;
    if (value != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)value + 4), 1);
}
