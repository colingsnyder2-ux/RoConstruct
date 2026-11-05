// from server: 29% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CreatorBase {
    void sub_417B50();
};

struct Creator {
    void* field0;
    CreatorBase field4;
    Creator(void* a, void* b);
};

Creator::Creator(void* a, void* b)
{
    field0 = a;
    field4.sub_417B50();
    if (a) {
        void** p = (void**)((char*)a + 0x2c);
        if (p) {
            *p = a;
            void* old = *(void**)&field4;
            if (old != p[1]) {
                if (old) {
                    _InterlockedExchangeAdd((volatile long*)((char*)old + 8), 1);
                }
                void* cur = p[1];
                if (cur) {
                    if (_InterlockedExchangeAdd((volatile long*)((char*)cur + 8), -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(cur);
                    }
                }
                p[1] = old;
            }
        }
    }
}
