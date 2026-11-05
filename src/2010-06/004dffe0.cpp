// from server: 23% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Outer {
    char pad[0x1d0];
    void* field1d0;
    char pad2[0x1c];
    void* field1ec;
    char pad3[4];
    void* field1f4;
    void method(void* arg);
};

extern "C" void __stdcall sub_4a5450(void* out, void* in);
extern "C" void __stdcall sub_7954f0(void* out, void* in);
extern "C" void __stdcall sub_795540(void* p);
extern "C" void __stdcall sub_4dff30(void* a, void* b, void* c, void* d, void* e, void* f);

void Outer::method(void* arg)
{
    void* local14 = 0;
    sub_4a5450(&local14, (char*)this + 0x1f4);
    void* ebp = local14;
    int flag = 0;
    if (ebp != 0) {
        void* local10 = 0;
        sub_7954f0(&local10, (char*)this + 0x1d0);
        void* ebx = *(void**)((char*)this + 0x1ec);
        void* edx = (void*)0x4de1b0;
        void* eax = *(void**)((char*)this + 0x1d4);
        void* local1c = eax;
        void* tmp = *(void**)ebx;
        void* args[4];
        args[0] = edx;
        args[1] = 0;
        args[2] = this;
        args[3] = ebp;
        flag = 1;
        sub_4dff30(&local10, eax, tmp, ebx, args, arg);
        flag = 0;
        sub_795540(&local10);
        RefCounted* rc = (RefCounted*)local10;
        if (rc != 0) {
            if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
                void** vt = (void**)rc->vptr;
                void (*fn)(void*) = (void (*)(void*))vt[1];
                fn(rc);
                if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                    void** vt2 = (void**)rc->vptr;
                    void (*fn2)(void*) = (void (*)(void*))vt2[2];
                    fn2(rc);
                }
            }
        }
        return;
    }
    RefCounted* rc = (RefCounted*)local14;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = (void**)rc->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void** vt2 = (void**)rc->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(rc);
            }
        }
    }
}
