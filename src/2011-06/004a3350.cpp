// from server: 71% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long volatile*);

struct CVideoStreamFilter {
    void* vtable;
    long refcount;
    long Release();
};

long CVideoStreamFilter::Release()
{
    long result = InterlockedDecrement(&refcount);
    if (result == 0) {
        refcount++;
        void** vt = *(void***)this;
        typedef void (__thiscall* Fn)(CVideoStreamFilter*, int);
        Fn fn = (Fn)vt[3];
        fn(this, 1);
        return 0;
    }
    if ((unsigned long)result <= 1)
        return 1;
    return result;
}
