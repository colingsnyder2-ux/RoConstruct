// from server: 41% by colin
struct CSelectionTreeCtrl {
    char pad[0x98];
    void* m_list;      // 0x98
    char pad2[0x14];
    void* m_lock;      // 0xb0
    char pad3[0x24];
    void* m_map;       // 0xd8

    void func(void* arg);
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern void __fastcall sub_725750(void* p);
extern void __fastcall sub_725770(void* p);
extern void __fastcall sub_44f4c0(void* p, void* a, void* b);
extern void __fastcall sub_4a9660(void* p, void* a, void* b);

void CSelectionTreeCtrl::func(void* arg)
{
    sub_725750(&m_lock);
    void* local = 0;
    sub_44f4c0(&m_list, &local, arg);
    void* ebx = local;
    void* edx = *(void**)((char*)&m_list + 4);
    void* saved = edx;
    if (ebx != 0 && ebx != &m_list)
        _invalid_parameter_noinfo();
    void* esi = local;
    if (esi != saved) {
        if (ebx == 0)
            _invalid_parameter_noinfo();
        if (esi == *(void**)((char*)ebx + 4))
            _invalid_parameter_noinfo();
        esi = (char*)esi + 0x10;
        sub_4a9660(&m_map, &esi, esi);
    }
    sub_725770(&m_lock);
}
