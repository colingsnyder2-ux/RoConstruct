// from server: 35% by colin
// roc 2007-08 00420940  unit: CRobloxTreeCtrl  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00420940

extern "C" unsigned long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CXTTreeBase {
    void* vfptr;
    char pad[0x50];
    void* m_pTree;      // +0x54
    char pad2[0x50];
    void* m_pItems;     // +0xa8
    void* m_pItemsEnd;  // +0xac
    char pad3[0x50];
    void* m_hWnd;       // +0x20
};

struct CRobloxTreeCtrl {
    void* vfptr;
    char pad[0x1c];
    void* m_hWnd;       // +0x20
    char pad2[0x30];
    CXTTreeBase m_tree; // +0x54
    char pad3[0x50];
    void* m_pItems;     // +0xa8
    void* m_pItemsEnd;  // +0xac

    int sub_420940(unsigned int);
};

extern "C" int __stdcall sub_63023e(void*);
extern "C" void* __stdcall sub_64afa0(void*, int);
extern "C" int __stdcall sub_630238(void*, void*);
extern "C" void* __stdcall sub_6304a2(void*, int, int, int, int);
extern "C" void __stdcall sub_63022c(void*);
extern "C" int __stdcall sub_41fb00(void*, void*, void*);
extern "C" void* __stdcall sub_62ff02(void*, void*, int);
extern "C" void __stdcall sub_41eeb0(void*, void*);
extern "C" void* __stdcall sub_63049c(void*);

int CRobloxTreeCtrl::sub_420940(unsigned int arg)
{
    int result;
    void* p;
    void* q;
    void* r;
    int local;

    result = sub_63023e(&m_tree);
    if (result == -1)
        return -1;

    (*(void (__stdcall**)(void*))(*(void***)&m_tree)[0x44/4])(&m_tree);

    local = 0;
    p = sub_64afa0(&local, 0x85);
    local = 0;
    q = (void*)0x788300;
    r = 0;
    sub_630238(&q, p);

    if (local != 0) {
        p = sub_6304a2(&m_pItems, 0x10, 0x10, 0x20, 0);
        if (p == 0) {
            q = (void*)0x7864c8;
            sub_63022c(&q);
            return -1;
        }
        sub_41fb00(&m_pItems, &q, p);
        if (result == -1) {
            q = (void*)0x7864c8;
            sub_63022c(&q);
            return -1;
        }
    } else {
        p = sub_6304a2(&m_pItems, 0x10, 0x10, 0xff, 0);
        if (p == 0) {
            q = (void*)0x7864c8;
            sub_63022c(&q);
            return -1;
        }
        r = sub_62ff02(m_pItemsEnd, q, 0xff00ff);
        sub_41eeb0(*(void**)r, r);
    }

    if (m_pItems != 0)
        m_pItems = *(void**)((char*)m_pItems + 4);

    SendMessageA(m_hWnd, 0x1109, 0, (long)m_pItems);
    sub_63049c((void*)0);

    q = (void*)0x7864c8;
    sub_63022c(&q);

    (*(void (__stdcall**)(void*, int))(*(void***)&m_tree)[0x3c/4])(&m_tree, 1);
    (*(void (__stdcall**)(void*))(*(void***)this)[0x15c/4])(this);

    return 0;
}
