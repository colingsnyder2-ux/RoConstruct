// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct GetSet {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

struct ChildVec {
    void* begin;
    void* end;
};

struct Workspace {
    char pad[0xc0];
    ChildVec* children;
};

struct RefPropDescriptor {
    int build();
};

int RefPropDescriptor::build() {
    Workspace* ws = (Workspace*)this;
    GetSet* gs = 0;
    unsigned i = 0;
    unsigned count = ((unsigned (__thiscall*)(Workspace*))0x487c10)(ws);
    while (i < count) {
        ChildVec* cv = ws->children;
        void* begin = cv->begin;
        if (begin) {
            unsigned n = ((char*)cv->end - (char*)begin) >> 3;
            if (i >= n) {
                _invalid_parameter_noinfo();
            }
        } else {
            _invalid_parameter_noinfo();
        }
        void* child = ((void**)cv->begin)[i];
        if (!((bool (__cdecl*)(void*))0x574b80)(child)) {
            ((void (__thiscall*)(GetSet*, void*, int))0x562300)(gs, child, 1);
            ((void (__thiscall*)(void*))0x532f50)(child);
        }
        i++;
        count = ((unsigned (__thiscall*)(Workspace*))0x487c10)(ws);
    }
    if (gs) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)gs + 4), -1) == 1) {
            gs->vf1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)gs + 8), -1) == 1) {
                gs->vf2();
            }
        }
    }
    return 0;
}
