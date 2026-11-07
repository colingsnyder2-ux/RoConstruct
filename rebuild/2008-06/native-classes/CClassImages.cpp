// >>> native-status (generated) -- do not edit >>>
// CClassImages | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src d699077e | roc native-status --write
#include "CClassImages.h"
#include <XTToolkitPro.h>
#include <stdexcept>
#include <string>

// Original 00413230: IDB_CLASSIMAGES (133) through the XTP alpha-aware bitmap loader.
CClassImages::CClassImages()
{
    BOOL alpha = FALSE;
    HBITMAP handle = CXTPImageManagerIcon::LoadBitmapFromResource(MAKEINTRESOURCE(133), &alpha);
    CBitmap bitmap;
    bitmap.Attach(handle);
    if (alpha) {
        if (!Create(16, 16, ILC_COLOR32, 0, 0))
            throw std::runtime_error("Unable to create CClassImages");
        if (Add(&bitmap, &bitmap) == -1)
            throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
    } else {
        if (!Create(16, 16, 0xff, 0, 0))
            throw std::runtime_error("Unable to create CClassImages");
        if (Add(&bitmap, RGB(255, 0, 255)) == -1)
            throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
    }
}

CClassImages::~CClassImages() {}
