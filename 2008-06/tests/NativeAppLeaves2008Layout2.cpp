#include <stddef.h>
#include "AppLeaves2008/RobloxModule2008.h"
#include "AppLeaves2008/Marshaller2008.h"
#include "AppLeaves2008/RBXImage2008.h"
#include "AppLeaves2008/Exposer2008.h"

// CRobloxModule: the global at 0096dbb4 ends where theApp (0096dbe0) begins; the dynamic initializer 007ef7d0
// writes _ATL_MODULE70::cbSize at +4 (0096dbb8) and inits the critical section at +0x10 (0096dbc4); the atexit
// destructor 007fae10 reads m_pTermFuncs +0xc (0096dbc0) and m_pGIT +0x28 (0096dbdc).
struct RobloxModuleLayout : CRobloxModule {
    static void check();
};
void RobloxModuleLayout::check()
{
    typedef char Size[sizeof(CRobloxModule) == 0x2c ? 1 : -1];
    typedef char MfcSize[sizeof(ATL::CAtlMfcModule) == 0x2c ? 1 : -1];
    typedef char CbSize[offsetof(RobloxModuleLayout, cbSize) == 0x04 ? 1 : -1];
    typedef char TermFuncs[offsetof(RobloxModuleLayout, m_pTermFuncs) == 0x0c ? 1 : -1];
    typedef char Section[offsetof(RobloxModuleLayout, m_csStaticDataInitAndTypeInfo) == 0x10 ? 1 : -1];
    typedef char Git[offsetof(RobloxModuleLayout, m_pGIT) == 0x28 ? 1 : -1];
}

// Marshaller: operator new(0x54) at 0041b7c5; constructor 0041b310 and destructor 0041a250 field accesses.
struct MarshallerLayout : Marshaller {
    static void check();
};
void MarshallerLayout::check()
{
    typedef char Size[sizeof(Marshaller) == 0x54 ? 1 : -1];
    typedef char Hwnd[offsetof(MarshallerLayout, m_hWnd) == 0x04 ? 1 : -1];
    typedef char Thunk[offsetof(MarshallerLayout, m_thunk) == 0x08 ? 1 : -1];
    typedef char CurrentMsg[offsetof(MarshallerLayout, m_pCurrentMsg) == 0x18 ? 1 : -1];
    typedef char State[offsetof(MarshallerLayout, m_dwState) == 0x1c ? 1 : -1];
    typedef char Super[offsetof(MarshallerLayout, m_pfnSuperWindowProc) == 0x20 ? 1 : -1];
    typedef char UseCount[offsetof(MarshallerLayout, useCount) == 0x24 ? 1 : -1];
    typedef char ThreadId[offsetof(MarshallerLayout, threadId) == 0x28 ? 1 : -1];
    typedef char Queue[offsetof(MarshallerLayout, queue) == 0x2c ? 1 : -1];
    typedef char Mutex[offsetof(MarshallerLayout, mutex) == 0x4c ? 1 : -1];
}

// RBXImage: constructor 00442c90 writes +0..+0x2c.
struct RBXImageLayout {
    static void check();
};
void RBXImageLayout::check()
{
    typedef char Size[sizeof(RBXImage) == 0x30 ? 1 : -1];
    typedef char Bitmap[offsetof(RBXImage, m_hBitmap) == 0x04 ? 1 : -1];
    typedef char Bits[offsetof(RBXImage, m_pBits) == 0x08 ? 1 : -1];
    typedef char Width[offsetof(RBXImage, m_nWidth) == 0x0c ? 1 : -1];
    typedef char Height[offsetof(RBXImage, m_nHeight) == 0x10 ? 1 : -1];
    typedef char Pitch[offsetof(RBXImage, m_nPitch) == 0x14 ? 1 : -1];
    typedef char Bpp[offsetof(RBXImage, m_nBPP) == 0x18 ? 1 : -1];
    typedef char Dib[offsetof(RBXImage, m_bIsDIBSection) == 0x1c ? 1 : -1];
    typedef char Alpha[offsetof(RBXImage, m_bHasAlphaChannel) == 0x1d ? 1 : -1];
    typedef char Transparent[offsetof(RBXImage, m_iTransparentColor) == 0x20 ? 1 : -1];
    typedef char Dc[offsetof(RBXImage, m_hDC) == 0x24 ? 1 : -1];
    typedef char DcRef[offsetof(RBXImage, m_nDCRefCount) == 0x28 ? 1 : -1];
    typedef char OldBitmap[offsetof(RBXImage, m_hOldBitmap) == 0x2c ? 1 : -1];
}

// Exposer: IDTOString 0049f180 builds it in a 0x20c-byte frame (PacketLogger has no other members).
typedef char ExposerSize[sizeof(Exposer) == sizeof(PacketLogger) ? 1 : -1];
