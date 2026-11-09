// from server: 67% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long volatile *Addend);

struct CVideoStreamFilter {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int);
    long refCount;
    long Release();
};

long CVideoStreamFilter::Release()
{
    long result = InterlockedDecrement(&refCount);
    if (result == 0) {
        refCount++;
        vf3(1);
        return 0;
    }
    if (result > 1)
        return result;
    return 1;
}
