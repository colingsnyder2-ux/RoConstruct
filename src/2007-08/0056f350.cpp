// from server: 45% by colin
struct PropertyDescriptor {
    void* m_value;
    void* m_getter;
    void* m_setter;
    unsigned m_attributes;
    unsigned m_seenAttributes;
};

struct TypedPropertyDescriptor : PropertyDescriptor {
    void* getset;
    void checkFlags();
    void __cdecl copyValue(const TypedPropertyDescriptor& other);
};

extern "C" {
    int __stdcall MSVCP80_0x77e708(void*);
    void __stdcall MSVCP80_0x77e6ac(void*);
}

void* __cdecl sub_56E460(void*);
void* __cdecl sub_44CF10(void*);
void* __cdecl sub_56DD30(void*);
void* __cdecl sub_56D990();
void __cdecl sub_56E530(void*);

void TypedPropertyDescriptor::copyValue(const TypedPropertyDescriptor& other)
{
    if (MSVCP80_0x77e708((void*)0x8827f8)) {
        void* tmp = sub_56E460((void*)&other.m_value);
        void* tmp2 = sub_44CF10(tmp);
        void* tmp3 = sub_56DD30(tmp2);
        void* v = *(void**)&this->m_value;
        *(void**)&this->m_value = *(void**)tmp3;
        *(void**)tmp3 = v;
        if (tmp) {
            (*(void(__thiscall**)(void*, int))*(void**)tmp)(tmp, 1);
        }
        MSVCP80_0x77e6ac(&tmp2);
        MSVCP80_0x77e6ac(&tmp);
        this->m_value = sub_56D990();
    }
    sub_56E530(this);
}
