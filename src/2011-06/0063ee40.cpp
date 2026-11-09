// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Helper {
    char pad0[4];
    Inner* m_inner;
};

struct Outer {
    char pad0[8];
    void* m_ptr;
    void release();
};

struct Target;

struct Container {
    Target* m_target;
    Helper m_helper;
    void set(Target* target, Outer* outer);
};

struct TargetVtbl {
    void* pad0;
    void* pad1;
    void* dtor;
};

struct Target {
    char pad0[8];
    volatile long refcount;
    char pad12[0x20];
    Target* m_self;
    Target* m_other;
};

extern "C" void __stdcall sub_0063ea90(Helper* helper, Target* target, void* arg);

void Container::set(Target* target, Outer* outer)
{
    m_target = target;
    sub_0063ea90(&m_helper, target, 0);
    if (target != 0) {
        Target* self = (Target*)((char*)target + 0x2c);
        if (self != 0) {
            self->m_self = target;
            Target* old = m_helper.m_inner ? (Target*)m_helper.m_inner->pad0 : 0;
            if (old != self->m_other) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Target* prev = self->m_other;
                if (prev != 0) {
                    if (_InterlockedExchangeAdd(&prev->refcount, -1) == 1) {
                        TargetVtbl* vtbl = *(TargetVtbl**)prev;
                        void (*dtor)(Target*) = (void (*)(Target*))vtbl->dtor;
                        dtor(prev);
                    }
                }
                self->m_other = old;
            }
        }
    }
}
