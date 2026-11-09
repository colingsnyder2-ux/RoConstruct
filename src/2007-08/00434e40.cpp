// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_00444b70(void*);
extern "C" void* __cdecl func_00443340(void*, void*);
extern "C" void* __cdecl func_00630634(void*, int, void*, int, int, int, int, int, int, int);
extern "C" void* __cdecl func_0063063a(void*, void*, int, int, int, int, int, int);
extern "C" void __cdecl func_00434c70(void*, void*, void*);
extern "C" void* __cdecl func_0077e6a8(void*);

struct CMemberTreeView {
    char pad[0xa8];
    char field_a8;
    char pad2[3];
    int field_ac;
    void func_00434e40(void*);
};

void CMemberTreeView::func_00434e40(void* arg)
{
    char* p = (char*)arg;
    if (field_a8 == 0) {
        int v = *(int*)(p + 0xc);
        if (v != field_ac)
            return;
    }

    void* tmp;
    func_00444b70(&tmp);
    void* obj = *(void**)tmp;

    void* result = func_00443340(obj, arg);
    void* ebp = result;

    void* ref = tmp;
    if (ref != 0) {
        volatile long* cnt = (volatile long*)((char*)ref + 4);
        if (_InterlockedExchangeAdd(cnt, -1) == 1) {
            void** vt = *(void***)ref;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(ref);
            volatile long* cnt2 = (volatile long*)((char*)ref + 8);
            if (_InterlockedExchangeAdd(cnt2, -1) == 1) {
                void** vt2 = *(void***)ref;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(ref);
            }
        }
    }

    if (ebp != 0) {
        if (*(char*)((char*)ebp + 0xe8) == 0)
            return;
    }

    if ((*(unsigned char*)(p + 0x10) & 1) == 0)
        return;

    void* v4 = *(void**)(p + 4);
    void* v5 = func_0077e6a8((char*)v4 + 4);

    void* r1 = func_00630634(this, 0x23, v5, 6, 6, 0, 0, 0, 0xffff0000, 0xffff0002);
    void* r2 = func_0063063a(this, r1, 4, 0, 0, 0, 0, 0);
    func_00434c70(this, r2, ebp);
}
