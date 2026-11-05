// from server: 38% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct SlotBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct SlotHolder {
    SlotBase* ptr;
};

struct Vec {
    int* begin;
    int* end;
    int* cap;
};

struct Slot {
    void* vtbl;
    float value;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct Signal {
    void emit(float a, float b, float c, float d);
};

void Signal::emit(float a, float b, float c, float d)
{
    Vec v;
    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    void* p = operator_new(8);
    if (p) {
        *(void**)p = (void*)0xa046c8;
        *(float*)((char*)p + 4) = a;
    } else {
        p = 0;
    }
    {
        SlotBase* old = v.begin ? *(SlotBase**)v.begin : 0;
        if (v.begin) {
            *(void**)v.begin = p;
        }
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    void* p2 = operator_new(8);
    if (p2) {
        *(void**)p2 = (void*)0xa046c8;
        *(float*)((char*)p2 + 4) = b;
    } else {
        p2 = 0;
    }
    {
        SlotBase* old = *(SlotBase**)((char*)v.begin + 4);
        if (v.begin) {
            *(void**)((char*)v.begin + 4) = p2;
        }
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    void* p3 = operator_new(8);
    if (p3) {
        *(void**)p3 = (void*)0xa046c8;
        *(float*)((char*)p3 + 4) = c;
    } else {
        p3 = 0;
    }
    {
        SlotBase* old = *(SlotBase**)((char*)v.begin + 8);
        if (v.begin) {
            *(void**)((char*)v.begin + 8) = p3;
        }
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    void** vt = *(void***)this;
    ((void (__stdcall*)(void*, Vec*))vt[1])(this, &v);

    operator_delete(v.begin);
}
