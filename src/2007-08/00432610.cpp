// from server: 45% by colin
struct CDataModelPropGrid {
    char pad0[0xdc];
    void* m_ptr_dc;
    char pad1[8];
    void* m_ptr_e8;
    char pad2[0x100];
    char m_sub_f0[0x30];
    char m_sub_120[0x14c];
    char m_sub_26c[0x12c];
    void* m_ptr_398;
    void* m_ptr_394;
    void* m_ptr_390;
    char m_sub_39c[0x2c];
    char m_sub_3c8[0x8];

    void destroy();
};

extern "C" {
    void __stdcall sub_6301e4(void*);
    void __stdcall sub_432530(void*, void*);
    void __stdcall sub_693b60(void*);
    void __stdcall sub_691c60(void*);
    void __stdcall sub_68d3b0(void*);
    void __stdcall sub_66ded0(void*);
    void __stdcall sub_430c40(void*);
    void __stdcall sub_77ddbc(void*);
}

void CDataModelPropGrid::destroy() {
    m_ptr_dc = (void*)0x78b4fc;
    *(void**)((char*)this + 0xdc) = (void*)0x78b4f0;
    if (m_ptr_e8) {
        sub_6301e4(m_ptr_e8);
        m_ptr_e8 = 0;
    }
    sub_432530((void*)0x8a2820, (char*)this + 0xdc);
    sub_693b60((char*)this + 0x3c8);
    sub_691c60((char*)this + 0x39c);
    if (m_ptr_398) {
        (*(void(__thiscall**)(void*, int))m_ptr_398)(m_ptr_398, 1);
    }
    if (m_ptr_394) {
        (*(void(__thiscall**)(void*, int))m_ptr_394)(m_ptr_394, 1);
    }
    if (m_ptr_390) {
        (*(void(__thiscall**)(void*, int))m_ptr_390)(m_ptr_390, 1);
    }
    sub_68d3b0((char*)this + 0x26c);
    sub_66ded0((char*)this + 0x120);
    sub_77ddbc((char*)this + 0xf0);
    *(void**)((char*)this + 0xdc) = (void*)0x78a710;
    *(void**)this = (void*)0x78b174;
    sub_430c40(this);
}
