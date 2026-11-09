// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Conn {
    void* p0;
    void* p1;
};

struct Slot {
    void* p0;
    void* p1;
};

struct List {
    Slot* begin;
    Slot* end;
};

struct Obj {
    char pad[0x3c];
    void* field3c;
};

struct VModelInstance {
    void func(void*);
};

extern "C" void __cdecl sub_4289E0(Conn* out, void* src);

void VModelInstance::func(void* arg) {
    Obj* self = (Obj*)this;
    if (self->field3c == 0)
        return;
    Conn c;
    sub_4289E0(&c, self->field3c);
    List* lst = (List*)&c;
    Slot* it = lst->begin;
    Slot* end = lst->end;
    if (it != end) {
        void** p = (void**)arg;
        do {
            void* a = p[1];
            void* b = it->p0;
            void* d = it->p1;
            void* tmp[2];
            tmp[0] = b;
            tmp[1] = d;
            if (d)
                _InterlockedExchangeAdd((volatile long*)((char*)d + 4), 1);
            ((void (__thiscall*)(void*, void*, void*))p[0])(p, tmp[0], tmp[1]);
            void* e = it->p0;
            ((VModelInstance*)e)->func(arg);
            it++;
        } while (it != end);
    }
    void* r = c.p0;
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            void** vt = *(void***)r;
            ((void (__thiscall*)(void*))vt[1])(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                void** vt2 = *(void***)r;
                ((void (__thiscall*)(void*))vt2[2])(r);
            }
        }
    }
}
