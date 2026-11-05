// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SharedCount {
    void* vptr;
    long m_use;
    long m_weak;
    virtual void dispose();
    virtual void destroy();
};

struct RefHolder {
    char pad[4];
    SharedCount* m_ptr;
    ~RefHolder();
};

struct Inner {
    char pad[0x100];
    double* get();
};

struct Outer {
    char pad[0x118];
    double m_val;
    double f(double* a, double* b, double* c, double* d);
};

void sub_7fdd10(void*, void**);

double Outer::f(double* a, double* b, double* c, double* d)
{
    RefHolder h;
    double v;
    {
        void* p = 0;
        sub_7fdd10(this, &p);
        if (p) {
            SharedCount* sc = (SharedCount*)p;
            if (sc->vptr) {
                typedef char (__thiscall *Fn)(void*);
                Fn fn = *(Fn*)(*(char**)sc->vptr + 8);
                if (fn(sc))
                    v = *(double*)0xc953c0;
                else
                    v = 0.0;
            } else {
                v = 0.0;
            }
        } else {
            v = 0.0;
        }
    }
    double inv = 1.0 / *(double*)((char*)&h + 0x10);
    double tmp = v;
    int mode = *(int*)0xc953bc - 1;
    if (mode == 0) {
        double t = ((Inner*)((char*)this + 0x100))->get()[0];
        if (t * *(double*)0xa98658 > tmp) {
            *a = tmp;
            a[1] = *(double*)((char*)&tmp + 4);
            h.~RefHolder();
            return tmp;
        }
    } else if (mode == 1) {
        double t = *(double*)((char*)this + 0x118);
        if (t * *(double*)0xa98658 > tmp) {
            *a = tmp;
            a[1] = *(double*)((char*)&tmp + 4);
            h.~RefHolder();
            return tmp;
        }
    }
    double diff = tmp - *c;
    if (tmp > diff) {
        *a = tmp;
        a[1] = *(double*)((char*)&tmp + 4);
    } else {
        *a = diff;
        a[1] = *(double*)((char*)&diff + 4);
    }
    SharedCount* sc = h.m_ptr;
    if (sc) {
        if (_InterlockedExchangeAdd(&sc->m_use, -1) == 1) {
            sc->dispose();
            if (_InterlockedExchangeAdd(&sc->m_weak, -1) == 1)
                sc->destroy();
        }
    }
    return *a;
}
