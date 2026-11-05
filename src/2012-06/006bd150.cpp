// from server: 39% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VTableBase {
    void (__thiscall *scalar_deleting_destructor)(void*, unsigned int);
    void (__thiscall *destruct)(void*);
};

struct RefCounted {
    VTableBase* vptr;
    long ref_count;
    char pad[4];
    long weak_count;
};

struct ArgStruct {
    RefCounted* ptr;
};

extern "C" void __cdecl sub_6BC7B0(RefCounted* ecx, int edx, ArgStruct* arg, int zero);

void __cdecl sub_6BD150(ArgStruct* arg) {
    int cookie = -1;
    char local_flag = 0;
    RefCounted* eax = arg->ptr;
    RefCounted* eax_vptr_target = eax ? *reinterpret_cast<RefCounted**>(eax) : 0;
    
    sub_6BC7B0(eax_vptr_target, 0, arg, 0);
    
    RefCounted* esi = arg->ptr;
    cookie = -1;
    
    if (esi) {
        volatile long* ref_ptr = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(esi) + 4);
        long old_ref = _InterlockedExchangeAdd(ref_ptr, -1);
        if (old_ref == 1) {
            VTableBase* vtable = esi->vptr;
            esi->vptr->destruct(esi);
            
            volatile long* weak_ptr = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(esi) + 12);
            long old_weak = _InterlockedExchangeAdd(weak_ptr, -1);
            if (old_weak == 1) {
                esi->vptr->scalar_deleting_destructor(esi, 1);
            }
        }
    }
}
