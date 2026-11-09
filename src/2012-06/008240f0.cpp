// from server: 40% by atomic.potato
struct TypeInfo {
    bool operator==(const TypeInfo&) const;
};

struct PropDescriptor {
    void* vfptr;
    void* field4;
    char pad8[8];
};

struct SurfaceEnumPropDescriptor {
    void* vfptr;
    void* field4;
    char pad8[8];
    int getValue();
};

extern "C" void* __stdcall sub_76AA40(void*);
extern "C" void* __stdcall sub_823BD0(void*);

extern TypeInfo typeinfo_0xDBA86C;
extern void* vtbl_0xB229EC;

int SurfaceEnumPropDescriptor::getValue()
{
    void* p = *(void**)this;
    void* t = *(void**)((char*)p + 0x10);
    if (t != &typeinfo_0xDBA86C) {
        typedef bool (__stdcall *CmpFn)(void*, void*);
        CmpFn fn = *(CmpFn*)&vtbl_0xB229EC;
        if (!fn(t, &typeinfo_0xDBA86C))
            goto slow;
    }
    {
        void* a = sub_76AA40((char*)this + 4);
        return *(int*)a;
    }
slow:
    {
        void* local4 = *(void**)this;
        void* local8 = 0;
        void* e = *(void**)((char*)this + 4);
        if (e) {
            typedef void (__stdcall *Fn)(void*, void*);
            Fn fn = *(Fn*)((char*)e + 8);
            fn((char*)this + 8, (char*)&local8 + 4);
        }
        local8 = *(void**)((char*)this + 4);
        int result = *(int*)sub_823BD0(&local4);
        void* ee = local8;
        if (ee) {
            typedef void (__stdcall *Fn2)(void*);
            Fn2 fn2 = *(Fn2*)((char*)ee + 4);
            fn2((char*)&local8 + 4);
        }
        return result;
    }
}
