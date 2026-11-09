// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct CMainFrame {
    void sub_00442760(void*);
    CMainFrame* sub_00442a30(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i);
};

CMainFrame* CMainFrame::sub_00442a30(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i)
{
    void* args[9];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = e;
    args[5] = f;
    args[6] = g;
    args[7] = h;
    args[8] = i;

    RefCounted* rc = (RefCounted*)d;
    if (rc != 0) {
        _InterlockedExchangeAdd(&rc->refcount, 1);
    }

    sub_00442760(args);

    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakref, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    return this;
}
