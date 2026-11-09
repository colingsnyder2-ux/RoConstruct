// from server: 68% by atomic.potato
struct CXTPControlPopup {
    char pad0[0x178];
    void* m_pPopup;
    void SetPopup(void* p);
};

struct CXTPToolBar {
    char pad0[0x17c];
    void* m_pSomething;
    void* Find(void* p);
    void Remove(void* p);
    void DoAction(void* p);
};

void CXTPControlPopup::SetPopup(void* p) {
    if (m_pPopup) {
        extern void __stdcall sub_7f3ddc(void*);
        sub_7f3ddc(m_pPopup);
    }
    m_pPopup = p;
}

void* CXTPToolBar::Find(void* p) {
    extern void* __stdcall sub_804a30(void*, void*);
    return sub_804a30(this, p);
}

void CXTPToolBar::Remove(void* p) {
    extern void __stdcall sub_83b650(void*, void*);
    sub_83b650(this, p);
}

void CXTPToolBar::DoAction(void* p) {
    if (m_pSomething) {
        void* obj = Find(m_pSomething);
        if (obj) {
            Remove(obj);
            m_pSomething = 0;
            void** vtbl = *(void***)obj;
            void (__stdcall *fn)(void*, void*) = (void (__stdcall *)(void*, void*))vtbl[0x1ec/4];
            fn(obj, p);
        }
    }
}
