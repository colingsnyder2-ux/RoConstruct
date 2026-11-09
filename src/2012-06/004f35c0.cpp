// from server: 44% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct MeshFileKey {
    void Release();
};

struct RefCounted {
    virtual void Destroy();
    virtual void Delete();
    volatile long ref1;
    volatile long ref2;
};

void MeshFileKey::Release()
{
    RefCounted* p = 0;
    void* tmp = 0;
    int a = *(int*)((char*)this + 0);
    void (__stdcall *fn)(void*, int, int, void**) = *(void (__stdcall**)(void*, int, int, void**))((char*)*(void**)this + 8);
    fn(this, 0, 0, &tmp);
    p = (RefCounted*)tmp;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->Destroy();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->Delete();
            }
        }
    }
}
