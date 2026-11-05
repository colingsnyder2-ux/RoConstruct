// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VAnimationTrackState {
    void EventDesc(double, int, int, int, int, int, int, int);
};

void VAnimationTrackState::EventDesc(double a, int b, int c, int d, int e, int f, int g, int h)
{
    int* p = (int*)this;
    void** vtbl = (void**)*p;
    int* obj = (int*)b;
    if (obj)
        _InterlockedExchangeAdd((volatile long*)(obj + 1), 1);
    int off = *(int*)((char*)this + 4);
    off += c;
    void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
    fn((char*)this + off, 0);
    if (obj)
    {
        if (_InterlockedExchangeAdd((volatile long*)(obj + 1), -1) == 1)
        {
            void** v = (void**)*obj;
            void (*f2)(void*) = (void (*)(void*))v[1];
            f2(obj);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1)
            {
                void** v2 = (void**)*obj;
                void (*f3)(void*) = (void (*)(void*))v2[2];
                f3(obj);
            }
        }
    }
}
