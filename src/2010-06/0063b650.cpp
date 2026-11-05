// from server: 55% by colin
struct GetSet;

struct PropertyDescriptor {
    void* m_value;
    void* m_getter;
    void* m_setter;
    unsigned m_attributes;
    unsigned m_seenAttributes;
};

struct TypedPropertyDescriptor : PropertyDescriptor {
    void* getset;
    void setValue(void* value, unsigned attributes);
};

extern "C" void* __stdcall sub_63AB00(void* out, void* value);

void TypedPropertyDescriptor::setValue(void* value, unsigned attributes)
{
    void* p = *(void**)((char*)this->getset);
    void* tmp;
    sub_63AB00(&tmp, value);
    void* fn = *(void**)((char*)p + 0x10);
    typedef void (__thiscall *Fn)(void*, void*, void*);
    ((Fn)fn)(this->getset, tmp, (void*)attributes);
}
