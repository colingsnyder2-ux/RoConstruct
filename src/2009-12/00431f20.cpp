// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

extern "C" void __cdecl func_7f3e30();
extern "C" void* __cdecl func_63e9e0(void*);
extern "C" void* __cdecl func_431d10(void*, void*, void*);
extern "C" char __cdecl func_664540(void*, void*);
extern "C" void __cdecl func_664370(void*);
extern "C" void __cdecl func_57ba80(void*, void*);
extern "C" void __cdecl func_41af50(void*);

struct CStandardOutputView {
    void func_431f20(void* a, void* b);
};

void CStandardOutputView::func_431f20(void* a, void* b)
{
    func_7f3e30();
    if (a == 0) {
        func_664370((char*)this + 0x148);
        return;
    }
    void* tmp = 0;
    void* r = func_63e9e0(&tmp);
    void* v = *(void**)r;
    void* out = func_431d10((char*)v + 0x10, &tmp, (void*)0x4317d0);
    void* self148 = (char*)this + 0x148;
    if (func_664540(self148, out)) {
        func_664370(self148);
        func_57ba80(self148, out);
    }
    func_41af50(&tmp);
    RefCounted* rc = (RefCounted*)tmp;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc->vptr[2])(rc);
            }
        }
    }
}
