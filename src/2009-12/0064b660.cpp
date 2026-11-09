// from server: 32% by atomic.potato
extern "C" {
    int __stdcall sub_40A1D0(void*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

extern "C" {
    void* __stdcall sub_98B768(void*, void*);
    void* __stdcall sub_98B7A4(void*, void*);
}

struct S {
    void f(void*);
};

void S::f(void* p)
{
    if (p != 0) {
        void* q = *(void**)p;
        if (q != 0) {
            void* vt = *(void**)q;
            void* fn = *(void**)((char*)vt + 4);
            typedef void* (__stdcall *F)(void*);
            ((F)fn)(q);
        } else {
            q = (void*)0xb0030c;
        }
        if (sub_98B768(q, (void*)0xb2c670)) {
            if ((char*)p + 4 != 0) {
                return;
            }
        }
    }
    sub_98B7A4((void*)0x99fe9c, (void*)0);
    *(void**)0x99fe94 = (void*)0x99fe94;
    sub_40A1D0((void*)0x99fe94);
}
