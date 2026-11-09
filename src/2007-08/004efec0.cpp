// from server: 49% by tester
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct WeakReferenceCountedPointer {
    void __cdecl assign(unsigned int count, void** dst, void** src);
};

void WeakReferenceCountedPointer::assign(unsigned int count, void** dst, void** src) {
    while (count > 0) {
        if (dst != 0) {
            *dst = 0;
            void* p = *src;
            if (p != 0) {
                *dst = p;
                InterlockedIncrement((long*)((char*)p + 4));
            }
        }
        count--;
        dst++;
    }
}
