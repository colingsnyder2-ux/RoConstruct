// from server: 27% by atomic.potato
struct T4_0041b6d0 {
    char pad0[0x18];
    char* m_18;
    int m_1c;
    char pad20[0x20];
    char m_40;

    bool f_0041b6d0(char* arg);
};

extern "C" void __stdcall f_007052b0(void*);
extern "C" void __stdcall f_00705300(void*);
extern "C" void __stdcall f_00402500(void*);
extern "C" void* __stdcall f_00418060(void*);
extern "C" void __stdcall f_0041b160(void*);
extern "C" void __stdcall f_0089e9ac(void);

bool T4_0041b6d0::f_0041b6d0(char* arg)
{
    char local[8];
    f_007052b0(&m_40);
    int count = m_1c;
    if (count == 0) {
        f_00705300(local);
        return false;
    }
    char* base = m_18;
    char* end = base + count;
    if (base > end)
        f_0089e9ac();
    void* v = *(void**)this;
    *(void**)local = v;
    *(char**)(local + 4) = base;
    char* r = (char*)f_00418060(local);
    arg[0] = r[0];
    *(int*)(arg + 4) = *(int*)(r + 4);
    f_00402500(r + 8);
    f_0041b160(this);
    f_00705300(local);
    return true;
}
