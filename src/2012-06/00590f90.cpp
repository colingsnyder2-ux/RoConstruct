// from server: 39% by atomic.potato
extern "C" void __cdecl _invalid_parameter_noinfo(void);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" void* __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);

struct VServerReplicator {
    char pad0[0x10];
    int* data;
    int size;
    int capacity;
    void reserve(int);
};

void VServerReplicator::reserve(int n) {
    int oldcap = capacity;
    if ((0xAAAAAAA - oldcap) < (unsigned int)n)
        _invalid_parameter_noinfo();
    int newcap = oldcap >> 1;
    if (newcap < 8)
        newcap = 8;
    if ((unsigned int)n < (unsigned int)newcap) {
        int lim = 0xAAAAAAA - newcap;
        if ((unsigned int)oldcap <= (unsigned int)lim) {
            n = newcap;
        }
    }
    int oldsize = size;
    int* newdata = (int*)operator_new((oldcap + n) * 4);
    int* src = data;
    int* dst = newdata + oldsize;
    int cnt = ((oldcap * 4 - (int)(src + oldsize) + (int)src) >> 2);
    if (cnt > 0) {
        memmove_s(dst, cnt * 4, src + oldsize, cnt * 4);
    }
    int* p;
    if ((unsigned int)oldsize <= (unsigned int)n) {
        int cnt2 = ((int)(src - src) + oldsize * 4) >> 2;
        p = dst + cnt2;
        if (cnt2 > 0) {
            memmove_s(p, cnt2 * 4, src, cnt2 * 4);
        }
        int rem = n - oldsize;
        if (rem != 0) {
            int* q = p;
            for (int i = 0; i < rem; i++) q[i] = 0;
        }
        p = newdata;
        if (oldsize > 0) {
            int c = oldsize;
            int* d = p;
            for (int i = 0; i < c; i++) d[i] = 0;
        }
    } else {
        int cnt3 = (n * 4) >> 2;
        if (cnt3 > 0) {
            memmove_s(newdata, cnt3 * 4, src, cnt3 * 4);
        }
        int* e = data;
        int* f = newdata + n;
        int cnt4 = ((int)(e - f) + oldsize * 4) >> 2;
        p = f + cnt4;
        if (cnt4 > 0) {
            memmove_s(p, cnt4 * 4, f, cnt4 * 4);
        }
        if (n > 0) {
            int* q = p;
            for (int i = 0; i < n; i++) q[i] = 0;
        }
    }
    if (data) {
        operator_delete(data);
    }
    capacity += n;
    data = newdata;
}
