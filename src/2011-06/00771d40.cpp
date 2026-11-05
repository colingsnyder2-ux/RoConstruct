// from server: 37% by atomic.potato
struct type_info {
    bool operator==(const type_info&) const;
};

struct bad_cast {
    bad_cast(const char*);
};

extern "C" void* __stdcall sub_a40a10(void*);
extern "C" bool __stdcall sub_a40a50(void*, void*);
extern "C" void sub_40d9d0(void*);

struct S {
};

void __cdecl f(void* a) {
    if (a != 0) {
        void* p = *(void**)a;
        void* q;
        if (p != 0) {
            q = (*(void***)p)[1];
            ((void (__thiscall*)(void*))q)(p);
        } else {
            q = (void*)0xc07a44;
        }
        if (sub_a40a50(q, (void*)0xc54430)) {
            void* r = *(void**)a;
            r = (char*)r + 4;
            if (r != 0) {
                return;
            }
        }
    }
    sub_a40a10((void*)0xa5c10c);
    *(void**)0xa5c104 = (void*)0xa5c104;
    sub_40d9d0((void*)0xa5c104);
}
