// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void* __cdecl alignedAlloc(unsigned int, unsigned int);
extern void __cdecl alignedFree(void*);

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Entry {
    void* object;
    Control* control;
};

struct S {
    Entry* data;
    int reserved;
    int count;
    void resizeStorage(int oldCount);
};

void S::resizeStorage(int oldCount)
{
    Entry* oldData = data;
    Entry* newData = static_cast<Entry*>(alignedAlloc(count * sizeof(Entry), 16));
    int copyCount = count;
    data = newData;
    if (oldCount < copyCount)
        copyCount = oldCount;

    Entry* destinationEnd = newData + copyCount;
    Entry* source = oldData;
    for (; newData < destinationEnd; ++newData, ++source) {
        if (newData) {
            newData->object = source->object;
            newData->control = source->control;
            if (newData->control) {
                volatile long* counter =
                    reinterpret_cast<volatile long*>(newData->control);
                ++counter;
                _InterlockedIncrement(counter);
            }
        }
    }

    Entry* oldEnd = oldData + oldCount;
    if (oldData < oldEnd) {
        Control** current = &oldData->control;
        unsigned int remaining =
            ((reinterpret_cast<unsigned int>(oldEnd) -
              reinterpret_cast<unsigned int>(oldData) - 1) >> 3) + 1;
        do {
            Control* control = *current;
            if (control) {
                if (_InterlockedDecrement(&control->strong) == 0) {
                    control->dispose();
                    if (_InterlockedDecrement(&control->weak) == 0)
                        control->destroy();
                }
            }
            current += 2;
        } while (--remaining);
    }

    alignedFree(oldData);
}
