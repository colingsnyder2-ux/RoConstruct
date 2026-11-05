// from server: 55% by colin
struct PropertyDescriptor {
    int m_value;
    int m_getter;
    int m_setter;
    unsigned m_attributes;
    unsigned m_seenAttributes;
};

struct TypedPropertyDescriptor : PropertyDescriptor {
    int m_getset;
    void checkFlags();
    void update();
};

extern "C" int __stdcall type_info_equal(void*, void*);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*, unsigned int);
extern "C" int __cdecl getIntValue(int*);
extern "C" bool __cdecl getBoolValue(int*);
extern "C" double __cdecl getDoubleValue(int*);
extern "C" int __cdecl createDescriptor();

void TypedPropertyDescriptor::update() {
    if (type_info_equal(*(void**)this, (void*)0x8827d4)) {
        int v = getIntValue(&m_getset);
        double d = (double)v;
        void* p = operator_new(0x10);
        if (p) {
            *(int*)p = 0x7a9fb4;
            *(double*)((char*)p + 8) = d;
        } else {
            p = 0;
        }
        int old = m_getset;
        m_getset = (int)p;
        if (old) {
            (*(void(__thiscall**)(int, int))old)(old, 1);
        }
        *(int*)this = createDescriptor();
    }
    if (type_info_equal(*(void**)this, (void*)0x8827e0)) {
        bool b = getBoolValue(&m_getset);
        int v = b ? 1 : 0;
        double d = (double)v;
        void* p = operator_new(0x10);
        if (p) {
            *(int*)p = 0x7a9fb4;
            *(double*)((char*)p + 8) = d;
        } else {
            p = 0;
        }
        int old = m_getset;
        m_getset = (int)p;
        if (old) {
            (*(void(__thiscall**)(int, int))old)(old, 1);
        }
        *(int*)this = createDescriptor();
    }
    if (type_info_equal(*(void**)this, (void*)0x8827ec)) {
        double d = getDoubleValue(&m_getset);
        void* p = operator_new(0x10);
        if (p) {
            *(int*)p = 0x7a9fb4;
            *(double*)((char*)p + 8) = d;
        } else {
            p = 0;
        }
        int old = m_getset;
        m_getset = (int)p;
        if (old) {
            (*(void(__thiscall**)(int, int))old)(old, 1);
        }
        *(int*)this = createDescriptor();
    }
    checkFlags();
}
