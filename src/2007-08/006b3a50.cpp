// from server: 57% by colin
// roc 2007-08 006b3a50  unit: CXTPControlComboBoxGalleryPopupBar  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b3a50

struct CXTPControlComboBoxGalleryPopupBar {
    int OnKeyDown(unsigned int nChar, unsigned int nRepCnt);
};

extern "C" int __stdcall sub_644720(int);
extern "C" int __stdcall sub_647530();
extern "C" int __stdcall sub_6b3960();

int CXTPControlComboBoxGalleryPopupBar::OnKeyDown(unsigned int nChar, unsigned int nRepCnt) {
    int* p = *(int**)((char*)this + 0x180);
    if (p == 0) {
        return sub_647530();
    }
    if (nChar == 0x1b) {
        int r = ((int (__thiscall*)(int*))*(int*)(*(int*)p + 0x74))(p);
        if (r != 0) {
            return 0;
        }
        return sub_647530();
    }
    if (nChar == 9) {
        return 0;
    }
    if (nChar == 0xd) {
        int a = sub_644720(*(int*)((char*)this + 0xc8));
        int b = sub_6b3960();
        if (a == b) {
            int* q = *(int**)((char*)this + 0x180);
            ((void (__thiscall*)(int*))*(int*)(*(int*)q + 0x98))(q);
            return (int)(nChar - 0xc);
        }
    }
    int r = ((int (__thiscall*)(void*, unsigned int, unsigned int, int*))*(int*)(*(int*)this + 0x210))(this, nChar, nRepCnt, p);
    return r;
}
