#include "NativeInsertServiceTrial.cpp"
class CXTPImageManagerIcon { public: static HBITMAP __cdecl LoadBitmapFromResource(LPCTSTR, BOOL*); };
CClassImages::CClassImages() {
    BOOL alpha = FALSE;
    HBITMAP loaded = CXTPImageManagerIcon::LoadBitmapFromResource(MAKEINTRESOURCE(133), &alpha);
    CBitmap bitmap;
    bitmap.Attach(loaded);
    if (alpha) {
        if (!Create(16, 16, 32, 0, 0)) throw std::runtime_error("Unable to create CClassImages");
        if (Add(&bitmap, &bitmap) == -1) throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
    } else {
        if (!Create(16, 16, 255, 0, 0)) throw std::runtime_error("Unable to create CClassImages");
        if (Add(&bitmap, RGB(255, 0, 255)) == -1) throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
    }
}
CClassImages::~CClassImages() {}
