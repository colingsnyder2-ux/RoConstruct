// from server: 40% by atomic.potato
extern "C" {
    void* __stdcall func_9ea89c(void*);
    int __stdcall func_9ea8d8(void*, const void*);
    void __stdcall func_40a530(void*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

extern "C" void __stdcall bad_cast_ctor(bad_cast*, const char*);

struct EnumDesc {
    void* vtable;
    void* get();
};

extern char placeholder_name;
extern char enum_name;
extern char bad_cast_str;

struct CRenderSettings_W4MaterialQuality_EnumDesc {
    void* field0;
    void* get_type();
};

void* CRenderSettings_W4MaterialQuality_EnumDesc_get(CRenderSettings_W4MaterialQuality_EnumDesc* self);

void CRenderSettings_W4MaterialQuality_EnumDesc_get_impl(CRenderSettings_W4MaterialQuality_EnumDesc* self)
{
    void* p = self->field0;
    void* t;
    if (p) {
        void** vt = *(void***)p;
        t = ((void*(*)(void*))vt[1])(p);
    } else {
        t = &placeholder_name;
    }
    if (func_9ea8d8(t, &enum_name)) {
        void* q = self->field0;
        if ((char*)q + 4) {
            return;
        }
    }
    char buf[8];
    func_9ea89c(buf);
    *(void**)(buf + 4) = &bad_cast_str;
    *(int*)(buf + 16) = 0;
    func_40a530(buf + 4);
}
