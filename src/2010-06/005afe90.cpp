// from server: 32% by atomic.potato
extern "C" {
    typedef unsigned int DWORD;
    void* __stdcall sub_9EA89C(void*);
    int __stdcall sub_9EA8D8(void*, const char*);
    void __stdcall sub_40A530(void*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

struct placeholder_any {
    virtual void f();
};

struct W4Axis {
    virtual void f();
};

struct EnumDesc {
    void func(void*);
};

void EnumDesc::func(void* p)
{
    if (p) {
        placeholder_any* pa = *(placeholder_any**)p;
        const type_info* ti;
        if (pa) {
            ti = (const type_info*)(*(void***)pa)[1];
            ((void (__thiscall*)(placeholder_any*))ti)(pa);
        } else {
            ti = (const type_info*)0xb7930c;
        }
        if (sub_9EA8D8((void*)ti, (const char*)0xba124c)) {
            if ((char*)p + 4) {
                return;
            }
        }
    }
    char buf[8];
    sub_9EA89C(buf);
    *(void**)(buf + 4) = (void*)0xa00a4c;
    *(DWORD*)(buf + 16) = 0;
    sub_40A530(buf + 4);
}
