// from server: 100% by tester
struct CXTPControlComboBoxGalleryPopupBar
{
    void* GetSite();
    void* GetGallery();
};

void* CXTPControlComboBoxGalleryPopupBar::GetSite()
{
    return 0;
}

void* CXTPControlComboBoxGalleryPopupBar::GetGallery()
{
    return 0;
}

extern "C" void* __fastcall sub_006b7b50(void* p);

void* __fastcall sub_006b7bc0(CXTPControlComboBoxGalleryPopupBar* self, int, int arg)
{
    void* p = sub_006b7b50(self);
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(void*, void*, int);
    Fn fn = (Fn)vtbl[0x1dc / 4];
    fn(p, self, arg);
    return p;
}
