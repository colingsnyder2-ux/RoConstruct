// from server: 67% by colin
struct CXTPCommandBar {
    char pad0[0x4c];
    void* m_p4c;
    char pad1[0x5c - 0x50];
    int m_5c;
    char pad2[0x84 - 0x60];
    int m_84;
    char pad3[0xa0 - 0x88];
    void* m_a0;
    char pad4[0xb8 - 0xa4];
    int m_b8;
    int OnCommand(int, int, int, int);
};

extern "C" void* __stdcall GetFocus();
extern "C" int __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
extern "C" int __stdcall RedrawWindow(void*, const void*, void*, unsigned int);

void* __stdcall sub_00668F70();
void __stdcall sub_0066A160(void*);
void* __stdcall sub_006301C0(void*);
int __stdcall sub_006301F0(void*, void*);
void* __stdcall sub_00635A60();
void __stdcall sub_0064C800(void*);

int CXTPCommandBar::OnCommand(int nID, int nCode, int nArg, int bNotify)
{
    if (nID == 0x363) {
        int i = 0;
        while (i < m_84) {
            void* p = ((void* (__thiscall*)(CXTPCommandBar*, int))0x632910)(this, i);
            if (*(int*)((char*)p + 0xfc) == 4) {
                (*(void (__thiscall**)(void*, int, int))(*(int*)p + 0x1e0))(p, 1, 1);
            }
            i++;
        }
        return 0;
    }
    if (nID == 0x15) {
        void* p = sub_00668F70();
        sub_0066A160(p);
        void* q = ((void* (__thiscall*)(CXTPCommandBar*))0x6321d0)(this);
        (*(void (__thiscall**)(void*))(*(int*)q + 0xa8))(q);
        void* r = ((void* (__thiscall*)(CXTPCommandBar*))0x6321f0)(this);
        sub_0064C800(r);
        SendMessageA(*(void**)((char*)m_a0 + 0x20), 0x105, 0, 0);
        ((void (__thiscall*)(CXTPCommandBar*))0x6333a0)(this);
        return 0;
    }
    if (nID == 0x1a) {
        void* q = ((void* (__thiscall*)(CXTPCommandBar*))0x6321d0)(this);
        (*(void (__thiscall**)(void*))(*(int*)q + 0xa8))(q);
        SendMessageA(*(void**)((char*)m_a0 + 0x20), 0x105, 0, 0);
        ((void (__thiscall*)(CXTPCommandBar*))0x6333a0)(this);
        return 0;
    }
    if (nID == 0x10) {
        if (*(int*)((char*)m_p4c + 0x14) == 0)
            return 0;
        return 1;
    }
    if (nID == 0x111) {
        void* focus = GetFocus();
        void* p = sub_006301C0(focus);
        if (p != 0) {
            void* h = sub_00635A60();
            if (sub_006301F0(p, h) != 0) {
                int r = (*(int (__thiscall**)(void*, int, int))(*(int*)p + 0xf0))(p, nCode, nArg);
                if (r != 0) {
                    if (bNotify != 0)
                        *(int*)bNotify = 1;
                    return 1;
                }
            }
        }
        if ((unsigned short)nCode == 0xe146) {
            if (m_b8 > 0) {
                int val = 0;
                int r = (*(int (__thiscall**)(void*, unsigned int, int, int, int*))(*(int*)m_a0 + 0x14))(m_a0, 0xe146, 0, 0, &val);
                if (r != 0) {
                    SendMessageA(*(void**)((char*)m_a0 + 0x20), 0x365, 0, m_b8 + 0x10000);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (nID == 0x1c) {
        if (nArg == 0)
            ((void (__thiscall*)(CXTPCommandBar*))0x633c70)(this);
        return 0;
    }
    if (nID == 0x112) {
        if (nArg != 0 && (unsigned short)nArg == 0)
            return 0;
        if (nArg == 0xf100)
            return 0;
        if (m_5c != 0)
            return 0;
        ((void (__thiscall*)(CXTPCommandBar*))0x633c70)(this);
        return 0;
    }
    return 0;
}
