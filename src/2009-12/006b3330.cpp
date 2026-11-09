// from server: 36% by atomic.potato
struct S_func_006b3330 {
    char pad0[4];
    void* m_ptr;
    char pad8[0x28];
    int f();
};

extern "C" int __stdcall sub_4f5590(void*, void*);
extern "C" int __stdcall sub_6b3040(void*, void*);
extern "C" void __stdcall sub_64caf0(void*, void*);
extern "C" void* __stdcall sub_65e090();
extern "C" void __stdcall sub_6b32f0(void*);
extern "C" void __stdcall sub_7e20e0(void*, const char*, void*, void*);
extern "C" void __stdcall sub_7f4878(void*, void*);
extern "C" int __stdcall sub_98b768(void*, const char*);

int S_func_006b3330::f()
{
    char buf[0x18];
    void* p = m_ptr;
    if (p != 0) {
        void* q = *(void**)p;
        if (q != 0) {
            int (*fn)(void*) = *(int(**)(void*))((char*)q + 4);
            q = (void*)fn(q);
        } else {
            q = (void*)0xb0030c;
        }
        if (sub_98b768(q, (const char*)0xb2cb0c)) {
            if ((char*)p + 4 != 0) {
                return 0;
            }
        }
    }
    if (sub_98b768(*(void**)(*(char**)this + 8), (const char*)0xb033e8)) {
        sub_4f5590(buf, &m_ptr);
        if (sub_6b3040(buf, 0)) {
            sub_64caf0(&m_ptr, buf);
            ++*(int*)0xb90098;
            *(void**)this = sub_65e090();
            sub_6b32f0(&m_ptr);
            return 0;
        }
    }
    ++*(int*)0xb90098;
    void* r = sub_65e090();
    void* a = *(void**)((char*)r + 0xc);
    if (*(unsigned*)((char*)a + 0x18) < 0x10) a = (char*)a + 4; else a = *(void**)((char*)a + 4);
    void* b = *(void**)(*(char**)this + 0xc);
    if (*(unsigned*)((char*)b + 0x18) < 0x10) b = (char*)b + 4; else b = *(void**)((char*)b + 4);
    sub_7e20e0(buf, (const char*)0x9bab84, b, a);
    sub_7f4878(buf, (void*)0xa904f0);
    return 0;
}
