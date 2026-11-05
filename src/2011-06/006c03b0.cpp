// from server: 14% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

struct Obj {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

struct Holder {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

extern "C" void __cdecl sub_73f730(void*, void*);
extern "C" void __cdecl sub_6bf3c0(void*, void*, void*, void*);

struct VInsertService {
    void func(void* a, void* b, void* c, void* d);
};

void VInsertService::func(void* a, void* b, void* c, void* d)
{
    void* local8 = 0;
    void* local24 = 0;
    void* local30 = 0;
    void* local34 = 0;
    void* local3c = 0;

    sub_73f730(&local8, &local24);

    void* esi = local8;
    if (esi) {
        void* tmp[8];
        tmp[0] = 0;
        if (local24) {
            tmp[0] = local24;
            void* p = local24;
            void* vt = *(void**)p;
            void* arg = &local3c;
            ((void (__stdcall*)(void*, void*, void*))vt)(p, arg, 0);
        }
        void* t1 = local30;
        void* t2 = local34;
        void* pair[2];
        pair[0] = t1;
        pair[1] = t2;
        if (t2) {
            _InterlockedExchangeAdd((volatile long*)((char*)t2 + 4), 1);
        }
        sub_6bf3c0(esi, pair, 0, 0);
    }

    if (local8) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local8 + 4), -1) == 1) {
            void* vt = *(void**)local8;
            ((void (__stdcall*)(void*))*(void**)((char*)vt + 4))(local8);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local8 + 8), -1) == 1) {
                void* vt2 = *(void**)local8;
                ((void (__stdcall*)(void*))*(void**)((char*)vt2 + 8))(local8);
            }
        }
    }

    if (local24) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local24 + 8), -1) == 1) {
            void* vt = *(void**)local24;
            ((void (__stdcall*)(void*))*(void**)((char*)vt + 8))(local24);
        }
    }

    if (local30) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local30 + 4), -1) == 1) {
            void* vt = *(void**)local30;
            ((void (__stdcall*)(void*))*(void**)((char*)vt + 4))(local30);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local30 + 8), -1) == 1) {
                void* vt2 = *(void**)local30;
                ((void (__stdcall*)(void*))*(void**)((char*)vt2 + 8))(local30);
            }
        }
    }

    if (local34) {
        void* vt = *(void**)local34;
        if (vt) {
            ((void (__stdcall*)(void*, void*, int))vt)(&local3c, &local3c, 2);
        }
    }
}
