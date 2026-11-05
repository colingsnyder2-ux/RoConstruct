// from server: 37% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" int __stdcall type_info_equal(void*, void*);

struct Inner {
    char pad0[8];
    void* field8;
    char padC[4];
    void* field10;
};

struct Outer {
    void* field0;
    char pad4[4];
};

struct S {
};

void* __cdecl f(void* arg1, void* arg2)
{
    void* result = 0;
    if (arg1 == 0) {
        void* src = *(void**)arg2;
        Inner* p = (Inner*)operator_new(0x38);
        if (p != 0) {
            void* r = ((void* (__thiscall*)(void*, void*))0x518f20)(p, src);
            *(void**)arg2 = r;
        } else {
            *(void**)arg2 = 0;
        }
        return result;
    }
    if (arg1 == (void*)1) {
        void* src = *(void**)arg2;
        *(void**)arg2 = src;
        *(void**)arg2 = 0;
        return result;
    }
    if (arg1 == (void*)2) {
        Inner* p = *(Inner**)arg2;
        if (p != 0) {
            if (p->field8 != 0) {
                void* vt = *(void**)p->field8;
                void* ecx = (char*)p + 0x10;
                if (vt != 0) {
                    ((void (__thiscall*)(void*, int, void*))vt)(ecx, 2, ecx);
                }
                p->field8 = 0;
            }
            operator_delete(p);
        }
        *(void**)arg2 = 0;
        return result;
    }
    if (arg1 == (void*)3) {
        void* p = *(void**)arg2;
        if (type_info_equal((void*)0xb19438, p)) {
            *(void**)arg2 = *(void**)arg2;
        } else {
            *(void**)arg2 = 0;
        }
        return result;
    }
    *(void**)arg2 = (void*)0xb19438;
    *((char*)arg2 + 4) = 0;
    *((char*)arg2 + 5) = 0;
    return result;
}
