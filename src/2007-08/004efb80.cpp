// from server: 43% by tester
// roc 2007-03 004efb80  unit: seg_004e0000  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004efb80

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct WeakReferenceCountedPointer
{
    void* __cdecl assign(void** dst, void** first, void** last);
};

void* WeakReferenceCountedPointer::assign(void** dst, void** first, void** last)
{
    while (first != last)
    {
        if (dst)
        {
            *dst = 0;
            void* p = *first;
            if (p)
            {
                *dst = p;
                InterlockedIncrement((long*)((char*)p + 4));
            }
        }
        dst++;
        first++;
    }
    return dst;
}
