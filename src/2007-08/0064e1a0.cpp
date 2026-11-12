// from server: 88% by EspClaude
// from server: 86% by EspClaude
// from server: 100% by colin
// from server: 91% by coldek
// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /MD /GS /EHsc
// roc-lib: xtp-15.2.1-shared-mfc roc_claude_41f31ed4d71c9459.cpp

// Candidate translation unit (score above; library headers required).
// XTPImageManager.cpp : implementation of the CXTPImageManager class.
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2011 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

// Prelude mirroring XTToolkitPro.h up to Common/XTPImageManager.h so the 2007-08 layout copy below wins its include guard.
#pragma warning(disable : 4786)
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>
#endif
#ifdef _MFC_OVERRIDES_NEW
#define _INC_MALLOC
#endif
#include <afxpriv.h>
#include <afxtempl.h>
#include <afxcview.h>
#include <afxmt.h>
#ifndef AFX_STATIC
#define AFX_STATIC static
#endif
#undef _XTP_EXT_CLASS
#if !defined(_AFXDLL) || defined(_XTP_STATICLINK)
#define _XTP_EXT_CLASS
#else
#define _XTP_EXT_CLASS  __declspec(dllimport)
#endif
#include "Common/XTPVersion.h"
#include "Common/Resource.h"
#include "Common/Tmschema.h"
#include "Common/UxTheme.h"
#include "Common/XTPMacros.h"
#include "Common/XTPVC80Helpers.h"
#include "Common/XTPSystemHelpers.h"
#include "Common/XTPResourceManager.h"
#include "Common/XTPColorManager.h"
#include "Common/XTPWinThemeWrapper.h"
#include "Common/XTPDrawHelpers.h"
// 2007-08 layout: m_nCustomID at this+0x54 (target 0064e22b add [esi+0x54]); resource members not before it
// XTPImageManager.h : interface for the CXTPImageManager class.
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2011 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPIMAGEMANAGER_H__)
#define __XTPIMAGEMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//-----------------------------------------------------------------------
// Summary:
//     Image state enumerators.
// Example:
// <code>
// // Set Icons
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, xtpImageNormal);
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, IDR_MAINFRAME_HOT, xtpImageHot);
// </code>
// See Also: CXTPImageManager::SetIcon, CXTPImageManager::SetIcons
//
// <KEYWORDS xtpImageNormal, xtpImageDisabled, xtpImageHot, xtpImageChecked>
//-----------------------------------------------------------------------
enum XTPImageState
{
	xtpImageNormal,     // Normal image.
	xtpImageDisabled,   // Disabled image.
	xtpImageHot,        // Hot image.
	xtpImageChecked,    // Checked(selected) image.
	xtpImagePressed     // Pressed image.
};


class CXTPImageManager;
class CXTPImageManagerIconSet;
class CXTPImageManagerImageList;
class CXTPImageManagerIconHandle;
class CXTPImageManagerResource;
class CXTPPropExchange;

//-----------------------------------------------------------------------
// Summary:
//     This structure is used to define position and style of the icon in resources
//-----------------------------------------------------------------------
struct XTP_IMAGERESOURCE_INFO
{
	BOOL bAlpha; // TRUE if icon has alpha layer, otherwise m_hbmpMask used to draw its mask.
	CRect rc;    // Position of the icon inside resource's m_hbmpImage bitmap
	CXTPImageManagerResource* pResource; // Pointer to owner resources
};

//===========================================================================
// Summary:
//     Standalone class used to manage Image resources.
//===========================================================================
class CXTPImageManagerResource
{
protected:
	//-------------------------------------------------------------------
	// Summary:
	//      Helper class derived from CDC contained m_hbmpImage or m_hbmpMask bitmaps
	//-------------------------------------------------------------------
	class CBitmapDC : public CDC
	{
	public:
		//---------------------------------------------------------------
		// Summary:
		//      Constructs CBitmapDC
		//---------------------------------------------------------------
		CBitmapDC()
		{
			m_hOldBitmap = 0;
		}
		//---------------------------------------------------------------
		// Summary:
		//     Destroys CBitmapDC class, restores device context
		//---------------------------------------------------------------
		~CBitmapDC()
		{
			if (m_hOldBitmap)
			{
				::SelectObject(GetSafeHdc(), m_hOldBitmap);
			}
		}
		//---------------------------------------------------------------
		// Summary:
		//     This method is called to select bitmap into device context
		// Parameters:
		//      hBitmap : Bitmap to select bitmap into device context; NULL to restore it.
		//---------------------------------------------------------------
		void SetBitmap(HBITMAP hBitmap)
		{
			if (hBitmap)
			{
				m_hOldBitmap = (HBITMAP)::SelectObject(GetSafeHdc(), hBitmap);
			}
			else if (m_hOldBitmap)
			{
				::SelectObject(GetSafeHdc(), m_hOldBitmap);
				m_hOldBitmap = NULL;
			}

		}
		HBITMAP m_hOldBitmap; // Old bitmap was selected in device context
	};

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerResource object used to create common bitmap for all icons of image manager
	// Parameters:
	//      pImageManager : Pointer to Parent ImageManager class
	//      szIcon : Size of images that will be managed by this resource
	//---------------------------------------------------------------
	CXTPImageManagerResource(CXTPImageManager* pImageManager, CSize szIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerResource object, handles cleanup and de-
	//     allocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerResource();

	//---------------------------------------------------------------
	// Summary:
	//      This method is called to add new icon to common bitmap fo resource manger
	// Parameters:
	//      hHandle : Handle of image to add
	// Returns:
	//      Returns pointer to XTP_IMAGERESOURCE_INFO contained position and style of new icon.
	//---------------------------------------------------------------
	XTP_IMAGERESOURCE_INFO* Add(const CXTPImageManagerIconHandle& hHandle);

	//---------------------------------------------------------------
	// Summary:
	//     Clears image in specified position
	// Parameters:
	//      pRInfo : Posiotion of image to clear
	//---------------------------------------------------------------
	void Clear(XTP_IMAGERESOURCE_INFO* pRInfo);

	//---------------------------------------------------------------
	// Summary:
	//     This method is called to draw image.
	// Parameters:
	//      pDC - Pointer to a valid device context.
	//      pRInfo : pointer to XTP_IMAGERESOURCE_INFO
	//      pt : point to start draw
	//      szIcon : size of icon
	//      bDrawComposited : BOOL flag of composite or not way of draw
	//---------------------------------------------------------------
	void Draw(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon, BOOL bDrawComposited);

	//---------------------------------------------------------------
	// Summary:
	//      Creates new icon from bitmap specified by pRInfo parameter
	// Parameters:
	//      hHandle : Handle of icon to be created
	//      pRInfo : Posiotion of icon inside m_hbmpImage to create
	//---------------------------------------------------------------
	void CreateIcon(CXTPImageManagerIconHandle& hHandle, XTP_IMAGERESOURCE_INFO* pRInfo);
	//---------------------------------------------------------------
	// Summary:
	//     Returns size of iconsmanaged by this Resource
	// Returns:
	//      Size of images contained inside m_hbmpImage
	//---------------------------------------------------------------
	CSize GetExtent() const;

private:
	XTP_IMAGERESOURCE_INFO* AllocBitmap();
	void RemoveAll();
	void DrawIconComposited(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon);

protected:
	HBITMAP m_hbmpImage; // Handle of bitmap contained all images of the resources
	HBITMAP m_hbmpMask;  // Handle of bitmap contained mask for images of the resources
	CBitmapDC m_dc;      // Helper device context class for quick image select

	BYTE* m_pBits;       // Bits of m_hbmpImage
	CXTPImageManager* m_pImageManager; // Parent CXTPImageManager object
	CSize m_szIcon;                    // Size of images of the resources
	int m_nAllocWidth;                 // Total allocated with of the resources
	CArray<XTP_IMAGERESOURCE_INFO*, XTP_IMAGERESOURCE_INFO*> m_arrIcons; // List of used icons
	CArray<XTP_IMAGERESOURCE_INFO*, XTP_IMAGERESOURCE_INFO*> m_arrAlloc; // List of free icons
	CRITICAL_SECTION m_cs; // Critical section for multithreading support.

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIconHandle;
	friend class CXTPImageManagerIcon;
};

//===========================================================================
// Summary:
//     CXTPImageManagerIconHandle is HICON wrapper class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconHandle
{
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconHandle object
	// Parameters:
	//     hIcon - Icon handle
	//     hBitmap - Bitmap handle
	//     hHandle - CXTPImageManagerIconHandle reference
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle();
	CXTPImageManagerIconHandle(HICON hIcon, BOOL bUseResources = TRUE); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	CXTPImageManagerIconHandle(HBITMAP hBitmap); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	CXTPImageManagerIconHandle(const CXTPImageManagerIconHandle& hHandle); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconHandle object, handles cleanup and deallocation
	//-------------------------------------------------------------------------
	~CXTPImageManagerIconHandle();

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator returns a HICON object whose value is copied from this CXTPImageManagerIconHandle object.
	// Returns:
	//     HICON handle.
	//-----------------------------------------------------------------------
	operator HICON() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies data from an HBITMAP or CXTPImageManagerIconHandle object
	// Parameters:
	//     handle - CXTPImageManagerIconHandle object
	//     hBitmap - Alpha bitmap handler
	//-----------------------------------------------------------------------
	void CopyHandle(HBITMAP hBitmap);
	void CopyHandle(const CXTPImageManagerIconHandle& handle); // <combine CXTPImageManagerIconHandle::CopyHandle@HBITMAP>

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns TRUE if class has no icon.
	// Returns:
	//     TRUE if m_hIcon member is NULL.
	//-----------------------------------------------------------------------
	BOOL IsEmpty() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves bitmap handle
	// Returns:
	//     32bit alpha bitmap
	//-----------------------------------------------------------------------
	HBITMAP GetBitmap() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	HICON GetIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;

	//---------------------------------------------------------------
	// Summary:
	//      Call this method to draw icons
	// Parameters:
	//      pDC : Pointer to device context to draw into
	//      pt : Positing of icon to draw
	//      szIcon : Size of icon to draw
	//      bDrawComposited : TRUE to draw inside Vista Composited area.
	//---------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CSize szIcon, BOOL bDrawComposited = FALSE);

public:

	//-------------------------------------------------------------------------
	// Summary:
	//     Release bitmap and icon handlers
	//-------------------------------------------------------------------------
	void Clear();

	//-------------------------------------------------------------------------
	// Summary:
	//     Creates an icon from resource bits describing the icon.
	// Parameters:
	//     hInst - Application instance handler
	//     lpszResourceName - Resource name identifier
	//     szIcon - Specifies the desired width and height, in pixels, of the icon.
	//     bGroupResource - TRUE to check if RT_GROUP_ICON resource exists.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-------------------------------------------------------------------------
	BOOL CreateIconFromResource(LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource = TRUE);
	BOOL CreateIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource); // <combine CXTPImageManagerIconHandle::CreateIconFromResource@LPCTSTR@CSize@BOOL>

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the icon handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hIcon - source icon handler
	//-----------------------------------------------------------------------
	const CXTPImageManagerIconHandle& operator=(const HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the alpha bitmap handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	const CXTPImageManagerIconHandle& operator=(const HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Create alpha bitmap with valid alpha layer.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	LPBYTE PreMultiply();

	void Detach();

protected:
	//---------------------------------------------------------------
	// Summary:
	//      Initializes icons
	//---------------------------------------------------------------
	void Init();

private:
	const CXTPImageManagerIconHandle& operator=(const CXTPImageManagerIconHandle&);
	CSize _GetExtent() const;


protected:
	HICON   m_hIcon;          // The underlying HICON handler for this CXTPImageManagerIconHandle object.
	HBITMAP m_hBitmap;        // The underlying Alpha bitmap handler for this CXTPImageManagerIconHandle object.
	LPBYTE m_pBits;           // Alpha bitmap bits;
	BOOL    m_bClearHandles;  // TRUE if object must destroy handlers.
	CXTPImageManager* m_pImageManager;  // Pointer to parent Image Manager
	XTP_IMAGERESOURCE_INFO* m_pRInfo;   // Pointer to resource info if icon is part of common resources
	CSize m_szIcon;                     // Size of the icon
	BOOL m_bUseResources;               // TRUE to use common resources

private:
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerResource;
};

//===========================================================================
// Summary:
//     Icons holder class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIcon : public CXTPCmdTarget
{
private:
	struct ICONDIRENTRY;
	struct ICONDIRHEADER;
	struct ICONIMAGE;
	struct GRPICONDIRENTRY;
	struct GRPICONDIR;

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIcon object.
	// Parameters:
	//     nID - Icon identifier.
	//     nWidth - Initial width for the icon.
	//     nHeight - Initial height for the icon.
	//     pIconSet - Parent icon set icon will belong.
	//     pImageList - Parent icon set icon will belong.
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerIconSet* pIconSet = NULL);
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerImageList* pImageList); //<combine CXTPImageManagerIcon::CXTPImageManagerIcon@UINT@int@int@CXTPImageManagerIconSet*>

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIcon object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the image identifier.
	// Returns:
	//     Identifier of the image
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if icons was scaled from another CXTPImageManagerIcon object.
	//-------------------------------------------------------------------------
	BOOL IsScaled() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Parameters:
	//     imageState - Image state for icon to retrieve
	// Returns:
	//     Icon handle.
	// See Also: XTPImageState
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetIcon();
	CXTPImageManagerIconHandle& GetIcon(XTPImageState imageState); // <combine CXTPImageManagerIcon::GetIcon>

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the faded icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetFadedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetShadowIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetCheckedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the pressed icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetPressedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves hot icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetHotIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the disabled icon.
	// Parameters:
	//     bCreateIfNotExists - Create if image not exists.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetDisabledIcon(BOOL bCreateIfNotExists = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if disabled icon exists
	// Returns:
	//     TRUE if disabled icon exists
	//-----------------------------------------------------------------------
	BOOL HasDisabledIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates a disabled icon.
	// Parameters:
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark -  The darkest color of icon to generate
	//-----------------------------------------------------------------------
	void CreateDisabledIcon(COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//     imageState - State of the icon
	//     nWidth - Width of icon.
	//     nHeight - Height of icon.
	//     nIDResourceIcon - Icon resource identifier.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon);
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle&amp;>
	// -----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon, XTPImageState imageState);
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle&amp;>
	// -----------------------------------------------------------------------
	BOOL SetIcon(UINT nIDResourceIcon, int nWidth, int nHeight);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the disabled icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the hot icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetHotIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the checked icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetNormalIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the pressed icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetPressedIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Parameters:
	//     hIcon - Icon handle.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;
	static CSize AFX_CDECL GetExtent(HICON hIcon); // <COMBINE CXTPImageManagerIcon::GetExtent@const>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is alpha bitmap.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is alpha bitmap
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is png image.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is png image
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads alpha bitmap from icon file.
	// Parameters:
	//     pszFileName - File path.
	//     nWidth - Icon width to load.
	// Returns:
	//     Alpha bitmap if icon with specified width was found; otherwise returns NULL.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaIcon(LPCTSTR pszFileName, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     nIDResource - Resource identifier
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap to be loaded.
	//     lpszResource - Long pointer to a null-terminated string that contains the name of the bitmap resource to be loaded
	// Remarks:
	//     Don't use LoadImage to load alpha bitmap, it loose alpha channel in some Windows.
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaBitmap(UINT nIDResource);
	static HBITMAP AFX_CDECL LoadAlphaBitmap(HMODULE hModule, LPCTSTR lpszResource); // <combine CXTPImageManagerIcon::LoadAlphaBitmap@UINT>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads bitmap from file on disk
	// Parameters:
	//     lpszFileName - File name of bitmap or png file
	//     lbAlphaBitmap - Determines if bitmap contained alpha layer
	// Remarks:
	//     This method loads png or bitmap from file
	// Returns:
	//     Bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromFile(LPCTSTR lpszFileName, BOOL* lbAlphaBitmap = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap to be loaded.
	//     lpszResource - Long pointer to a null-terminated string that contains the name of the bitmap resource to be loaded
	//     lbAlphaBitmap - Determines if bitmap contained alpha layer
	// Remarks:
	//     This method loads png or bitmap resource from file
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromResource(LPCTSTR lpszResource, BOOL* lbAlphaBitmap);
	static HBITMAP AFX_CDECL LoadBitmapFromResource(HMODULE hModule, LPCTSTR lpszResource, BOOL* lbAlphaBitmap); // <combine CXTPImageManagerIcon::LoadBitmapFromResource@LPCTSTR@BOOL*>

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap has alpha channel; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource is png resource.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap is png resource; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     The DrawAlphaBitmap function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     pDC     - Pointer to destination device context
	//     ptDest      - upper-left corner of the  destination rectangle
	//     ptSrc      - upper-left corner of the source rectangle
	//     hBitmap - Alpha bitmap handler
	//     szDest  - Destination size
	//     szSrc   - Source size
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawAlphaBitmap(CDC* pDC, HBITMAP hBitmap, CPoint ptDest, CSize szDest, CPoint ptSrc = 0, CSize szSrc = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates valid alpha bits to use in AlphaBlend.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	// Returns:
	//     Valid alpha bits
	// See Also: BLENDFUNCTION, AlphaBlend
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL PreMultiplyAlphaBitmap(HBITMAP hBitmap, BOOL* pbAlpha = NULL, LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to create mirror copy of bitmap
	// Parameters:
	//     hBitmap - Bitmap handle to make copy
	// Returns: new mirror bitmap
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL InvertAlphaBitmap(HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method retrieves information about alpha bitmap and its alpha bits.
	// Parameters:
	//     dcSrc   - Reference to CDC
	//     hBitmap - Alpha bitmap
	//     pbmi    - Bitmap information
	//     pBits   - Bitmap bits
	//     nSize   - Size of bits array
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL GetBitmapBits(CDC& dcSrc, HBITMAP hBitmap, PBITMAPINFO& pbmi, LPVOID& pBits, UINT& nSize);

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies alpha bitmap.
	// Parameters:
	//     hBitmap - Bitmap handler to be copied.
	// Returns:
	//     new alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL CopyAlphaBitmap(HBITMAP hBitmap, LPBYTE* lpBits = NULL);

	static BOOL AFX_CDECL IsAlphaIconHandle(HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon height.
	// Returns:
	//     Height of the icon.
	//-----------------------------------------------------------------------
	int GetHeight() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon width.
	// Returns:
	//     Width of the icon.
	//-----------------------------------------------------------------------
	int GetWidth() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);

	void Copy(CXTPImageManagerIcon* pIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     hIcon - Icon to be serialized
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void SerializeIcon(CXTPImageManagerIconHandle& hIcon, CArchive& ar, long nSchema);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image in specified location.
	// Parameters:
	//     pDC    - Destination device context.
	//     pt     - Specifies the location of the image
	//     hIcon  - A handle to an icon.
	//     szIcon - Specifies the size of the image.
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt);
	void Draw(CDC* pDC, CPoint pt, CSize szIcon);
//  void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon = 0);
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon = 0, COLORREF clrBK = CLR_NONE, COLORREF clrFG = CLR_NONE, UINT uiFlags = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image using the brush specified by the clrBrush parameter.
	// Parameters:
	//     pDC      - Destination device context.
	//     pt       - Specifies the location of the image.
	//     hIcon    - A handle to an icon.
	//     clrBrush - color of the brush used to draw the image.
	//-----------------------------------------------------------------------
	void DrawMono(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon, COLORREF clrBrush);

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraw Fade and Shadow icons.
	//-------------------------------------------------------------------------
	void Refresh();


public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Use this method to scale icon.
	// Parameters:
	//     hIcon - Icon to be scaled.
	//     szExtent - Source icon size.
	//     nWidth - With of result icon.
	//-----------------------------------------------------------------------
	static HICON AFX_CDECL ScaleToFit(HICON hIcon, CSize szExtent, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to draw non-alpha icon in composited Vista Glass rectangle
	// Parameters:
	//     pDC - Pointer to device context
	//     pt - Pointer to draw icon
	//     szIcon - Size of the icon
	//     hIcon - Icon handle to draw
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawIconComposited(CDC* pDC, CPoint pt, CSize szIcon, HICON hIcon);

private:
	void InitBimaps(CImageList& imageList, int nIndex);
	void CreateFadedIcon();
	void CreateShadowIcon();

	void Clear(BOOL bIcon = FALSE);
	COLORREF LightenColor(COLORREF clr, double factor);

	BOOL GetDIBBitmap(HBITMAP hBitmap, PBYTE& pBits, UINT& nBitsSize, PBITMAPINFO& pBitmapInfo, UINT& nBitmapInfoSize);
	HBITMAP ReadDIBBitmap(CArchive& ar, LPBYTE* pBits1);
	void WriteDIBBitmap(CArchive& ar, HBITMAP hBitmap);

	CXTPImageManager* GetImageManager() const;

private:
	CXTPImageManagerIcon(const CXTPImageManagerIcon&): m_nID(0) {};
	const CXTPImageManagerIcon& operator=(const CXTPImageManagerIcon&) {return *this;};

public:
	BOOL m_bDrawComposited; // Draw on Vista composited rects.

private:
	const UINT m_nID;
	UINT m_nWidth;
	UINT m_nHeight;
	CXTPImageManagerIconHandle m_hIcon;
	CXTPImageManagerIconHandle m_hFaded;
	CXTPImageManagerIconHandle m_hShadow;
	CXTPImageManagerIconHandle m_hHot;
	CXTPImageManagerIconHandle m_hChecked;
	CXTPImageManagerIconHandle m_hPressed;
	CXTPImageManagerIconHandle m_hDisabled;
	CXTPImageManagerIconHandle m_hDisabledAuto;
	CXTPImageManagerIconSet* m_pIconSet;
	CXTPImageManagerImageList* m_pImageList;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIconSet;
	friend class CXTPImageManagerIconHandle;

};


//===========================================================================
// Summary:
//     CXTPImageManagerIconSet represents the collection of icons for specified identifier.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconSet : public CXTPCmdTarget
{
public:
	typedef CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*> CIconSetMap; // Icons collection.

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconSet object.
	// Parameters:
	//     nID - Icon set identifier.
	//     pImageManager - Parent image manager CXTPImageManagerIconSet belongs.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet(UINT nID, CXTPImageManager* pImageManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconSet object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIconSet();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icon with the specified width
	// Parameters:
	//     nWidth - Width of the icon to retrieve.
	//     bScaled - TRUE to scale icon.
	// Returns:
	//     A pointer to a CXTPImageManagerIcon object
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetIcon(UINT nWidth, BOOL bScaled = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the collection of icons
	// Returns:
	//     A pointer to a CIconSetMap object
	//-----------------------------------------------------------------------
	CIconSetMap* GetIcons();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the identifier of the collection set.
	// Returns:
	//     Identifier of icons.
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Removes all icons
	//-------------------------------------------------------------------------
	void RemoveAll();

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-------------------------------------------------------------------------
	void RefreshAll();

private:
	CXTPImageManagerIcon* CreateIcon(UINT nWidth);
	void SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetHotIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetPressedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);



private:
	CXTPImageManagerIconSet(const CXTPImageManagerIconSet&): m_nID(0) {};
	const CXTPImageManagerIconSet& operator=(const CXTPImageManagerIconSet&) {return *this;};

private:
	CIconSetMap m_mapIcons;
	const UINT m_nID;
	CXTPImageManager* m_pImageManager;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIcon;
};

//===========================================================================
// Summary:
//     This class is used to connect ImageManager with specified HIMAGELIST
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerImageList
{
public:
	//---------------------------------------
	// Summary:
	//      Constructs  CXTPImageManagerImageList class
	//---------------------------------------
	CXTPImageManagerImageList();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerImageList object, handles cleanup and de-
	//     allocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerImageList();

public:
	//---------------------------------------
	// Summary:
	//      Call this method to determine of ImageList handles nCommand Id
	// Parameters:
	//      nCommand : Command to check
	// Returns:
	//      TRUE if imagelist contais nCommand.
	//---------------------------------------
	BOOL Lookup(UINT nCommand);

	//---------------------------------------
	// Summary:
	//      Creates temporary CXTPImageManagerIcon for command nCommand to draw using HIMAGELIST
	// Parameters:
	//      nCommand : Command to create icon for
	// Returns:
	//      Returns CXTPImageManagerIcon tat can be used to draw specified nCommand icon
	//---------------------------------------
	CXTPImageManagerIcon* GetIcon(UINT nCommand);

	//---------------------------------------
	// Summary:
	//      Call this method to draw specified pIcon
	// Parameters:
	//      pDC : Device context to draw into
	//      pt : Position of icon to draw
	//      pIcon : Pointer to icon to draw
	//      szIcon : Size of the icon
	//      clrBK : Background color of the image.
	//      clrFG : Foreground color of the image
	//      uiFlags : Drawing style and, optionally, the overlay image
	//---------------------------------------
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIcon* pIcon, CSize szIcon, COLORREF clrBK = CLR_NONE, COLORREF clrFG = CLR_NONE, UINT uiFlags = 0);

	//---------------------------------------
	// Summary:
	//     Cleans all temporary icons
	//---------------------------------------
	void RemoveAll();

	//---------------------------------------
	// Summary:
	//     Returns size of images inside HIMAGELIST
	// Returns:
	//     Size of images inside connected m_hImageList;
	//---------------------------------------
	CSize GetIconSize() const;

private:
	HIMAGELIST m_hImageList;
	BOOL m_bDestroyImageList;
	UINT m_nBaseCommand;
	CXTPImageManager* m_pImageManager;
	CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*> m_mapIcons;

	friend class CXTPImageManager;
};

//===========================================================================
// Summary:
//     CXTPImageManager is a stand alone class. It is used to manipulate icons.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManager : public CXTPCmdTarget
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManager object.
	//-----------------------------------------------------------------------
	CXTPImageManager();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManager object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManager();
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons.
	// Parameters:
	//     nIDResourceBitmap  - Bitmap resource identifier
	//     lpszResourceBitmap - Bitmap resource identifier
	//     nIDResourceToolBar - Toolbar resource identifier
	//     bmpIcons           - Bitmap containing icons to be added.
	//     imlIcons           - Image list containing the icons to be added.
	//     pCommands          - Pointer to an array of IDs.
	//     nCount             - Number of elements in the array pointed to by lpIDArray.
	//     szIcon             - Size of the icons.
	//     imageState         - Images state.
	//     bAlpha             - TRUE if bitmap has alpha channel.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// Example:
	// <code>
	//
	// static UINT buttons[] =
	// {
	//     ID_BACK,
	//     ID_FORWARD,
	//     ID_STOP,
	//     ID_REFRESH,
	//     ID_HOME
	// }
	//
	// XTPImageManager()->SetMaskColor(RGB(0, 0xFF, 0));
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_SMALL, buttons, _countof(buttons), CSize(16, 16), xtpImageNormal);
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_SMALL, buttons, _countof(buttons), CSize(16, 16), xtpImageHot);
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_LARGE, buttons, _countof(buttons), CSize(24, 24), xtpImageNormal);
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_LARGE, buttons, _countof(buttons), CSize(24, 24), xtpImageHot);
	// </code>
	// See Also: XTPImageState, SetIcon
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, XTPImageState imageState = xtpImageNormal);
	BOOL SetIcons(UINT nIDResourceToolBar, UINT nIDResourceBitmap, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(CBitmap& bmpIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal, BOOL bAlpha = FALSE); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceToolBar, CBitmap& bmpIcons, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(LPCTSTR lpszResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(CImageList& imlIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceToolBar, CImageList& imlIcons, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads icon from ico file
	// Parameters:
	//     lpszFileName - Path to ico file
	//     nIDCommand   - Icon command
	//     szIcon       - Size of the icons.
	//     imageState   - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIconFromIcoFile(LPCTSTR lpszFileName, UINT nIDCommand, CSize szIcon, XTPImageState imageState);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to attach images from a HIMAGELIST control to the image manager
	// Parameters:
	//     hImageList - Pointer to an imagelist that holds icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     bDestoryImageList - Destroy imagelist control after the icons are copied to the imagemanager
	//-----------------------------------------------------------------------
	BOOL SetImageList(HIMAGELIST hImageList, int nBaseCommand, BOOL bDestoryImageList = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to create system HIMAGELIST from bitmap and add it to image manager
	// Parameters:
	//     nIDResourceBitmap - Bitmap resource identifier
	//     cx - Width of the icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     clrMask - Mask color for bitmap
	// Remarks:
	//     SetIcons method loads bitmaps and creates HICON for each icon in bitmap, SetImageList creates only
	//     one HIMAGELIST. use SetImageList to create only one GDI object for all icons.
	// See Also: SetIcons
	//-----------------------------------------------------------------------
	BOOL SetImageList(UINT nIDResourceBitmap, int cx, int nBaseCommand = 0, COLORREF clrMask = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons from another image manager.
	// Parameters:
	//     pImageManager - A pointer to another image manager. The icons in pImageManager will be added to this image manager.
	//-----------------------------------------------------------------------
	void AddIcons(CXTPImageManager* pImageManager);
	void AddIcons(CXTPImageManagerIconSet* pIconSet);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icon.
	// Parameters:
	//     hIcon           - Icon handle to add
	//     nIDResourceIcon - Icon resource identifier
	//     lpszResourceIcon - Icon resource identifier
	//     nIDCommand      - Icon identifier.
	//     szIcon          - Size of the icons.
	//     imageState      - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: XTPImageState, SetIcons
	//-----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nIDCommand, CSize szIcon = 0, XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcon@CXTPImageManagerIconHandle&amp;@UINT@CSize@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetIcon(UINT nIDResourceIcon, UINT nIDCommand, CSize szIcon = 0, XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcon@CXTPImageManagerIconHandle&amp;@UINT@CSize@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetIcon(LPCTSTR lpszResourceIcon, UINT nIDCommand, CSize szIcon = 0, XTPImageState imageState = xtpImageNormal);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set the color mask of the bitmaps that will be added.
	// Parameters:
	//     clrMask - Mask color to be set.
	// Returns:
	//     Previous color mask.
	//-----------------------------------------------------------------------
	COLORREF SetMaskColor(COLORREF clrMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color mask.
	// Returns:
	//     Current color mask.
	//-----------------------------------------------------------------------
	COLORREF GetMaskColor() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Mirrors images around the y-axis, useful in RTL (Right-To-Left) Languages.
	// Parameters:
	//     bDrawReverted - If TRUE, images are "flipped" or Mirrored.
	//                     This should be used when displaying images in an
	//                     application that uses RTL (Right-To-Left) Languages.
	//-----------------------------------------------------------------------
	void DrawReverted(BOOL bDrawReverted);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes all icons.
	//-----------------------------------------------------------------------
	void RemoveAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes the specified icon.
	// Parameters:
	//     nIDCommand - Id of icon to be removed
	//-----------------------------------------------------------------------
	void RemoveIcon(UINT nIDCommand);

	//-----------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-----------------------------------------------------------------------
	void RefreshAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method used by CommandBars to add custom icons
	// Parameters:
	//     hIcon - Icon Handler to be added
	// Returns:
	//     Identifier of new added icon.
	//-----------------------------------------------------------------------
	UINT AddCustomIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons with the specified Id and width.
	// Parameters:
	//     nCommand - ID of the icon to be retrieved
	//     nWidth - Width of the icon to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIcon
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetImage(UINT nCommand, int nWidth = 16) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to determine if non scaled image exists in image manager
	// Parameters:
	//     nCommand - Image identifier to check
	//     nWidth - Image width to check
	// Returns:
	//     TRUE if image non scaled image exists.
	// See Also: GetImage
	//-----------------------------------------------------------------------
	BOOL IsPrimaryImageExists(UINT nCommand, int nWidth) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIconSet object
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet* GetIconSet(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id from an image list.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerImageList object
	//-----------------------------------------------------------------------
	CXTPImageManagerImageList* GetImageList(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a collection of images.
	// Returns:
	//     A CMap object
	//-----------------------------------------------------------------------
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* GetImages();

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if icons set exists with the specified ID.
	// Parameters:
	//     nCommand - Identifier needed to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL Lookup(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the icons are drawn mirrored\reverted.
	// Returns:
	//     TRUE if icons are drawn reverted; FALSE if drawn normal.
	//-----------------------------------------------------------------------
	BOOL IsDrawReverted() const;
	BOOL IsDrawReverted(CDC* pDC) const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Returns resources for specified size
	// Parameters:
	//     szIcon - Size for resources to retrieve
	// Returns:
	//     Returns pointer to CXTPImageManagerResource contained all icons of specified size
	//-----------------------------------------------------------------------
	CXTPImageManagerResource* GetResource(CSize szIcon);

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);
	void Serialize(UINT nCommand, CArchive& ar); //<COMBINE CXTPImageManager::Serialize@CArchive&>

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);
	void DoPropExchange(UINT nCommand, CXTPPropExchange* pPX); //<COMBINE CXTPImageManager::DoPropExchange@CXTPPropExchange*>

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     nIDResourceBitmap - Resource identifier of the bitmap to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(UINT nIDResourceBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if nIDResourceBitmap resource contains PNG image
	// Parameters:
	//     nIDResourceBitmap - Id of resources to check
	// Returns:
	//     TRUE if resources contains PNG image
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapResource(UINT nIDResourceBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha icons.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	// See Also: IsAlphaIconsImageListSupported
	//-----------------------------------------------------------------------
	BOOL IsAlphaIconsSupported() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha image list.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: IsAlphaIconsSupported
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaIconsImageListSupported();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color of top-left pixel.
	// Parameters:
	//     bmp       - CBitmap reference.
	//     nIDBitmap - Bitmap identifier.
	//     pt        - location of pixel to retrieve.
	// Returns:
	//     COLORREF that will be used as transparent color.
	//-----------------------------------------------------------------------
	static COLORREF AFX_CDECL GetBitmapMaskColor(CBitmap& bmp, CPoint pt = 0);
	static COLORREF AFX_CDECL GetBitmapMaskColor(UINT nIDBitmap, CPoint pt = 0); // <COMBINE CXTPImageManager::GetBitmapMaskColor@CBitmap&@CPoint>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method creates 24bit bitmap from 32bit alpha bitmaps to draw it in old OSes
	// Parameters:
	//     bmpAlpha - Resource bitmap identifier.
	//     clrMask  - Mask color to be used
	//     nIDBitmap - Resource bitmap identifier.
	// Returns:
	//     Reduced bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL ResampleAlphaLayer(HBITMAP bmpAlpha, COLORREF clrMask);
	static HBITMAP AFX_CDECL ResampleAlphaLayer(UINT nIDBitmap, COLORREF clrMask); // <COMBINE CXTPImageManager::ResampleAlphaLayer@HBITMAP@COLORREF>

	//-----------------------------------------------------------------------
	// Summary:
	//     The TransparentBlt function performs a bit-block transfer of the color data corresponding to
	//     a rectangle of pixels from the specified source device context into a destination device context.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	//     crTransparent - color to make transparent
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: AlphaBlend
	//-----------------------------------------------------------------------
	BOOL TransparentBlt(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc, UINT crTransparent) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: TransparentBlt
	//-----------------------------------------------------------------------
	BOOL AlphaBlend(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	//     Transparency - Transparency for whole image to draw
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: TransparentBlt
	//-----------------------------------------------------------------------
	BOOL AlphaBlend2(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc, BYTE Transparency) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as disabled.
	// Parameters:
	//     hDC              - A handle to DC
	//     rcRect           - A rectangle to be disabled
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark  - The darkest color of icon to generate
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: BlackWhiteBitmap
	//-----------------------------------------------------------------------
	BOOL DisableBitmap(HDC hDC, const CRect& rcRect, COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as gray scale.
	// Parameters:
	//     hDC                    - A handle to DC
	//     rcRect                 - A rectangle to be disabled
	//     nBlackAndWhiteContrast - Black-white contrast as integer from 0 to 255
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: DisableBitmap
	//-----------------------------------------------------------------------
	BOOL BlackWhiteBitmap(HDC hDC, const CRect& rcRect, int nBlackAndWhiteContrast = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method creates 32bit bitmap
	// Parameters:
	//     hDC - Pointer to valid context (can be NULL)
	//     iWidth - Width of bitmap
	//     iHeight - Height of bitmap
	//     lpBits - Pointer to bits to return
	// Returns:
	//     Bitmap handle was created.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL Create32BPPDIBSection(HDC hDC, int iWidth, int iHeight, LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method adds all icons from resources with specified size
	// Parameters:
	//     hInst - Module instance to load icons from
	//     lpszResourceName - Icon resource identifier
	//     nIDCommand - Command to assign for the icon
	//     szIcon - Size of icon to load (0 to load all formats)
	//     imageState - Image state to assign for the icon
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	//-----------------------------------------------------------------------
	BOOL SetIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, UINT nIDCommand, CSize szIcon, XTPImageState imageState);


	//-----------------------------------------------------------------------
	// Summary:
	//     Fall back for systems without MSIMG32.DLL
	//-----------------------------------------------------------------------
	static BOOL McTransparentBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest,
		int nWidthDest, int nHeightDest, HDC hdcSrc,
		int nXOriginSrc, int nYOriginSrc, int nWidthSrc,
		int nHeightSrc, UINT crTransparent);

private:
	BOOL LoadToolbar(UINT nIDResourceToolBar, UINT*& pItems, int& nCount, CSize& szIcon) const;

	UINT PasteCustomImage(COleDataObject& data);
	void CopyImage(UINT nCommand);
	BOOL SplitBitmap(HBITMAP hbmSource, int nCount, HBITMAP* pDest) const;
	BOOL IsWindow2000() const;
	BOOL BitmapsCompatible(LPBITMAP lpbm1, LPBITMAP lpbm2) const;


	BOOL BlendImages(HBITMAP hbmSrc1, BOOL bRTL1, HBITMAP hbmSrc2, BOOL bRTL2, HBITMAP hbmDst) const;
	BOOL DoAlphaBlend(HDC hdcDest, int nXOriginDest, int nYOriginDest,
		int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc,
		int nYOriginSrc, int nWidthSrc, int nHeightSrc) const;
	BOOL DoDisableBitmap(HBITMAP hBmp, COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1,
						 int nBlackAndWhiteContrast = -1);

public:
	static double m_dDisabledBrightnessFactor;  // Brightness factor of disabled icons.
	static double m_dDisabledAlphaFactor;       // Alpha factor of disabled icons.
	static BOOL   m_bAutoResample;              // TRUE to automatically re-sample alpha bitmaps if msimg32 not found.
	static CLIPFORMAT m_nImageClipFormat;       // Clipboard format of icons.
	static CLIPFORMAT m_nAlphaClipFormat;       // Clipboard format of icons.

private:
	COLORREF m_clrMask;
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*> m_mapImages;
	CArray<CXTPImageManagerImageList*, CXTPImageManagerImageList*> m_arrImageList;

	UINT m_nCustomID;
	BOOL m_bDrawReverted;
	CMap<DWORD, DWORD, CXTPImageManagerResource*, CXTPImageManagerResource*> m_mapResources;
public:
	BOOL   m_bUseResources;                     // TRUE to create single bitmap for all icons
private:

private:
	friend _XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();
	friend class CXTPCustomizeSheet;
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerIconHandle;

};

//===========================================================================
// Summary:
//    CXTPTempColorMask class can be used to temporarily set the color mask
//    used by XTPImageManager when using images with different color masks.
//    When the destructor is called the default mask is reset for
//    XTPImageManager.
// Example:
//    The following example demonstrates using CXTPTempColorMask.
// <code>
//    // temporarily change the mask color.
//    CXTPTempColorMask mask(RGB(0,255,0));
//    XTPImageManager()->SetIcons(IDB_FAVORITES,
//        icons, _countof(icons) CSize(16,16));
//
//    // set another mask color, CXTPTempColorMask will handle resetting
//    // the default color mask when it is destroyed.
//    XTPImageManager()->SetMaskColor(RGB(255,0,255));
//    XTPImageManager()->SetIcons(IDR_TOOLBAR_MASKED,
//        buttons, _countof(buttons), CSize(16,16), xtpImageNormal);
// </code>
// See Also:
//    CXTPImageManager::GetMaskColor, CXTPImageManager::SetMaskColor,
//    CXTPPaintManagerColor::GetStandardColor
//========================================================================
class _XTP_EXT_CLASS CXTPTempColorMask
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTempColorMask object and initializes the
	//     application defined mask color and saves the default mask color
	//     used by XTPImageManager.
	// Parameters:
	//     crNewMask - An RGB value that represents the new color mask value used
	//                 by XTPImageManager.
	//-----------------------------------------------------------------------
	CXTPTempColorMask(COLORREF crNewMask);
	CXTPTempColorMask(CXTPImageManager* pImageManager, COLORREF crNewMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destructor for CXTPTempColorMask. Resets the default mask color
	//     used by XTPImageManager back to its original color value.
	//-----------------------------------------------------------------------
	~CXTPTempColorMask();

private:
	COLORREF m_crMask;
	CXTPImageManager* m_pImageManager;
};

//===========================================================================
// Summary:
//     XTPImageManager returns pointer to common CXTPImageManager class
// Returns:
//     Returns pointer to common CXTPImageManager class
// See Also:
//    CXTPImageManager
//===========================================================================
_XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();


//////////////////////////////////////////////////////////////////////////

AFX_INLINE CXTPImageManagerIconHandle::operator HICON() const {
	return m_hIcon;
}

AFX_INLINE UINT CXTPImageManagerIconSet::GetID() const {
	return m_nID;
}
AFX_INLINE BOOL CXTPImageManagerIcon::IsScaled() const {
	return FALSE;
}



AFX_INLINE CXTPImageManagerIconSet::CIconSetMap* CXTPImageManagerIconSet::GetIcons() {
	return &m_mapIcons;
}
AFX_INLINE CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* CXTPImageManager::GetImages() {
	return  &m_mapImages;
}

AFX_INLINE void CXTPImageManager::DrawReverted(BOOL bDrawReverted) {
	m_bDrawReverted = bDrawReverted;
}
AFX_INLINE BOOL CXTPImageManager::IsDrawReverted() const {
	return m_bDrawReverted;
}

AFX_INLINE CXTPTempColorMask::CXTPTempColorMask(COLORREF crNewMask) {
	m_pImageManager = XTPImageManager();
	m_crMask = m_pImageManager->SetMaskColor(crNewMask);
}
AFX_INLINE CXTPTempColorMask::CXTPTempColorMask(CXTPImageManager* pImageManager, COLORREF crNewMask) {
	m_pImageManager = pImageManager;
	m_crMask = m_pImageManager->SetMaskColor(crNewMask);
}

AFX_INLINE CXTPTempColorMask::~CXTPTempColorMask() {
	m_pImageManager->SetMaskColor(m_crMask);
}

#endif //#if !defined(__XTPIMAGEMANAGER_H__)


#include "stdafx.h"
#include <math.h>

#include "Common/XTPVC80Helpers.h"
#include "Common/XTPColorManager.h"
#include "Common/XTPDrawHelpers.h"
#include "Common/XTPSystemHelpers.h"
#include "Common/XTPMacros.h"
#include "Common/XTPPropExchange.h"
#include "Common/XTPImageManager.h"
#include "Common/XTPResourceManager.h"

#ifdef _XTP_INCLUDE_GRAPHICLIBRARY
#include "GraphicLibrary/XTPGraphicBitmapPng.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DESTROYICON(hIcon) if (hIcon) { ::DestroyIcon(hIcon); hIcon = 0; }
#define FREE(hHandle) if (hHandle) { free(hHandle); hHandle = 0; }

double CXTPImageManager::m_dDisabledAlphaFactor = 1.0;
double CXTPImageManager::m_dDisabledBrightnessFactor = 0.5;
BOOL CXTPImageManager::m_bAutoResample = FALSE;
CLIPFORMAT CXTPImageManager::m_nImageClipFormat = (CLIPFORMAT)RegisterClipboardFormat(_T("Xtreme ToolBar Image"));
CLIPFORMAT CXTPImageManager::m_nAlphaClipFormat = (CLIPFORMAT)RegisterClipboardFormat(_T("Alpha Bitmap Image"));

#ifndef NOMIRRORBITMAP
#define NOMIRRORBITMAP      (DWORD)0x80000000 /* Do not Mirror the bitmap in this call */
#endif

#define  IMAGE_PLACEHOLDER 0xDEADBEAF

//---------------------------------------------------------------------------
//    Should be a prime number:
// 37, 53, 79 , 101, 127, 199, 503, 1021, 1511, 2003, 3001, 4001, 5003, 6007, 8009, 12007, 16001, 32003, 48017, 64007
#define XTP_IMAGEMAN_HASH_TABLE_SIZE 127

//////////////////////////////////////////////////////////////////////////
// Common

// Based on http://support.microsoft.com/kb/303916/en-us
BOOL CXTPImageManager::BitmapsCompatible(LPBITMAP lpbm1, LPBITMAP lpbm2) const
{
	if (lpbm1->bmBitsPixel != lpbm2->bmBitsPixel)
		return FALSE;

	if (lpbm1->bmPlanes != lpbm2->bmPlanes)
		return FALSE;

	if (lpbm1->bmWidth != lpbm2->bmWidth)
		return FALSE;

	if (lpbm1->bmHeight != lpbm2->bmHeight)
		return FALSE;

	return TRUE;
}

// Based on http://www.rsdn.ru/article/files/Functions/mctranspblt.xml
BOOL CXTPImageManager::McTransparentBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest,
	int nWidthDest, int nHeightDest, HDC hdcSrc,
	int nXOriginSrc, int nYOriginSrc, int nWidthSrc,
	int nHeightSrc, UINT crTransparent)
{

	BOOL bResult = FALSE;

	if (!hdcDest || !hdcSrc)
		return FALSE;

	HDC hdcMask = NULL;
	HDC hdcTmpSrc = NULL;
	HBITMAP hbmTransMask = NULL;
	HBITMAP oldhbmTransMask = NULL;
	HBITMAP hbmTmpSrc = NULL;
	HBITMAP oldhbmTmpSrc = NULL;


	COLORREF OldBkColor = ::SetBkColor(hdcDest, RGB(255, 255, 255));
	COLORREF OldTextColor = ::SetTextColor(hdcDest, RGB(0, 0, 0));

	if ((hdcMask = ::CreateCompatibleDC(hdcDest)) == NULL)
	{
		goto ClearUp;
	}

	if ((hdcTmpSrc = ::CreateCompatibleDC(hdcSrc))==NULL)
	{
		goto ClearUp;
	}

	if ((hbmTmpSrc = ::CreateCompatibleBitmap(hdcDest,nWidthSrc,nHeightSrc))==NULL)
	{
		goto ClearUp;
	}

	oldhbmTmpSrc = (HBITMAP)::SelectObject(hdcTmpSrc,hbmTmpSrc);

	if (!::BitBlt(hdcTmpSrc, 0, 0, nWidthSrc, nHeightSrc, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY))
	{
		goto ClearUp;
	}

	if ((hbmTransMask = ::CreateBitmap(nWidthSrc, nHeightSrc, 1, 1, NULL)) == NULL)
	{
		goto ClearUp;
	}

	oldhbmTransMask = (HBITMAP)::SelectObject(hdcMask,hbmTransMask);

	::SetBkColor(hdcTmpSrc,crTransparent);
	if (!::BitBlt(hdcMask, 0, 0, nWidthSrc, nHeightSrc, hdcTmpSrc, 0, 0, SRCCOPY))
	{
		goto ClearUp;
	}

	if (crTransparent != RGB(0, 0, 0))
	{
		::SetBkColor(hdcTmpSrc, RGB(0, 0, 0));
		::SetTextColor(hdcTmpSrc, RGB(255, 255, 255));

		if (!::BitBlt(hdcTmpSrc, 0, 0, nWidthSrc, nHeightSrc, hdcMask, 0, 0, SRCAND))
		{
			goto ClearUp;
		}
	}

	if ((nWidthDest == nWidthSrc) && (nHeightDest == nHeightSrc))
	{
		if (!::BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthSrc, nHeightSrc, hdcMask, 0, 0, SRCAND))
		{
			goto ClearUp;
		}
		if (!::BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthSrc, nHeightSrc, hdcTmpSrc, 0, 0, SRCPAINT))
		{
			goto ClearUp;
		}
	}
	else
	{
		if (!::StretchBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcMask, 0, 0, nWidthSrc, nHeightSrc,SRCAND))
		{
			goto ClearUp;
		}
		if (!::StretchBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcTmpSrc, 0, 0,  nWidthSrc, nHeightSrc,SRCPAINT))
		{
			goto ClearUp;
		}
	}
	bResult = TRUE;

ClearUp:
	if (hdcMask)
	{
		if (oldhbmTransMask)
			::SelectObject(hdcMask,oldhbmTransMask);
		::DeleteDC(hdcMask);
	}

	if (hbmTmpSrc)
	{
		if (oldhbmTmpSrc)
			::SelectObject(hdcTmpSrc,oldhbmTmpSrc);
		::DeleteObject(hbmTmpSrc);
	}

	if (hdcTmpSrc)
		::DeleteDC(hdcTmpSrc);

	if (hbmTransMask)
		::DeleteObject(hbmTransMask);

	::SetBkColor(hdcDest, OldBkColor);
	::SetTextColor(hdcDest,OldTextColor);

	return bResult;
}

BOOL CXTPImageManager::IsWindow2000() const
{
	return XTPSystemVersion()->IsWin2KOrGreater();
}

BOOL CXTPImageManager::TransparentBlt(HDC hdcDest, const CRect& rcDest,HDC hdcSrc,
	const CRect& rcSrc, UINT crTransparent) const
{
	if (IsWindow2000() && XTPDrawHelpers()->m_pfnTransparentBlt)
	{
		return XTPDrawHelpers()->m_pfnTransparentBlt(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
			hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height(), crTransparent);
	}

	return McTransparentBlt(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
		hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height(), crTransparent);
}

// Based on http://support.microsoft.com/kb/303916/en-us
BOOL CXTPImageManager::BlendImages(HBITMAP hbmSrc1, BOOL bRTL1, HBITMAP hbmSrc2, BOOL bRTL2, HBITMAP hbmDst) const
{
	BITMAP bmSrc1, bmSrc2, bmDst;
	RGBQUAD *lprgbSrc1, *lprgbSrc2, *lprgbDst;
	DWORD dwWidthBytes;
	int x, y;

	// Get weighting value for second source image.

	// Get information about the surfaces you were passed.
	if (!GetObject(hbmSrc1, sizeof(BITMAP), &bmSrc1)) return FALSE;
	if (!GetObject(hbmSrc2, sizeof(BITMAP), &bmSrc2)) return FALSE;
	if (!GetObject(hbmDst,  sizeof(BITMAP), &bmDst))  return FALSE;

	// Make sure you have data that meets your requirements.
	if (!BitmapsCompatible(&bmSrc1, &bmSrc2)) return FALSE;
	if (!BitmapsCompatible(&bmSrc1, &bmDst))  return FALSE;
	if (bmSrc1.bmBitsPixel != 32) return FALSE;
	if (bmSrc1.bmPlanes != 1) return FALSE;
	if (!bmSrc1.bmBits || !bmSrc2.bmBits || !bmDst.bmBits) return FALSE;

	dwWidthBytes = bmDst.bmWidthBytes;

	// Initialize the surface pointers.
	lprgbSrc1 = (RGBQUAD*)bmSrc1.bmBits;
	lprgbSrc2 = (RGBQUAD*)bmSrc2.bmBits;
	lprgbDst  = (RGBQUAD*)bmDst.bmBits;

	#define F(a)  BYTE(gbSrc1.##a + (255 - gbSrc1.rgbReserved) * gbSrc2.##a / 255)

	for (y = 0; y < bmDst.bmHeight; y++)
	{
		for (x = 0; x < bmDst.bmWidth; x++)
		{
			RGBQUAD& gbSrc1 = bRTL1 ? lprgbSrc1[bmDst.bmWidth - 1 - x] : lprgbSrc1[x];
			RGBQUAD& gbSrc2 = bRTL2 ? lprgbSrc2[bmDst.bmWidth - 1 - x] : lprgbSrc2[x];

			lprgbDst[x].rgbRed   = F(rgbRed);
			lprgbDst[x].rgbGreen = F(rgbGreen);
			lprgbDst[x].rgbBlue  = F(rgbBlue);
		}

		// Move to next scan line.
		lprgbSrc1 = (RGBQUAD *)((LPBYTE)lprgbSrc1 + dwWidthBytes);
		lprgbSrc2 = (RGBQUAD *)((LPBYTE)lprgbSrc2 + dwWidthBytes);
		lprgbDst  = (RGBQUAD *)((LPBYTE)lprgbDst  + dwWidthBytes);
	}

	return TRUE;
}

// Based on http://support.microsoft.com/kb/303916/en-us
HBITMAP AFX_CDECL CXTPImageManager::Create32BPPDIBSection(HDC hDC, int iWidth, int iHeight, LPBYTE* lpBits)
{
	BITMAPINFO bmi;
	HBITMAP hbm;
	LPBYTE pBits;

	// Initialize header to 0s.
	ZeroMemory(&bmi, sizeof(bmi));

	// Fill out the fields you care about.
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = iWidth;
	bmi.bmiHeader.biHeight = iHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	// Create the surface.
	hbm = CreateDIBSection(hDC, &bmi, DIB_RGB_COLORS, (LPVOID*)&pBits, NULL, 0);

	if (lpBits)
	{
		*lpBits = pBits;
	}

	return(hbm);
}

// Based on http://support.microsoft.com/kb/303916/en-us
BOOL CXTPImageManager::DoAlphaBlend(HDC hdcDest,                 // Handle to destination DC.
	int nXOriginDest,            // X-coord of upper-left corner.
	int nYOriginDest,            // Y-coord of upper-left corner.
	int nWidthDest,              // Destination width.
	int nHeightDest,             // Destination height.
	HDC hdcSrc,                  // Handle to source DC.
	int nXOriginSrc,             // X-coord of upper-left corner.
	int nYOriginSrc,             // Y-coord of upper-left corner.
	int nWidthSrc,               // Source width.
	int nHeightSrc              // Source height.
) const
{
	HDC      hdcSrc1 = NULL;
	HDC      hdcSrc2 = NULL;
	HBITMAP  hbmSrc1 = NULL, hbmOldSrc1 = NULL;
	HBITMAP  hbmSrc2 = NULL, hbmOldSrc2 = NULL;
	HBITMAP  hbmDst  = NULL;
	BOOL     bReturn = FALSE;
	BOOL     bRTLSrc    = XTPDrawHelpers()->IsContextRTL(hdcSrc);
	BOOL     bRTLDest   = XTPDrawHelpers()->IsContextRTL(hdcDest);

	// Create surfaces for sources and destination images.
	hbmSrc1 = CXTPImageManager::Create32BPPDIBSection(hdcDest, nWidthDest,nHeightDest);
	if (!hbmSrc1) goto HANDLEERROR;

	hbmSrc2 = CXTPImageManager::Create32BPPDIBSection(hdcDest, nWidthDest,nHeightDest);
	if (!hbmSrc2) goto HANDLEERROR;

	hbmDst  = CXTPImageManager::Create32BPPDIBSection(hdcDest, nWidthDest,nHeightDest);
	if (!hbmDst) goto HANDLEERROR;

	// Create HDCs to hold our surfaces.
	hdcSrc1 = CreateCompatibleDC(hdcSrc);
	if (!hdcSrc1) goto HANDLEERROR;

	hdcSrc2 = CreateCompatibleDC(hdcSrc);
	if (!hdcSrc2) goto HANDLEERROR;

	XTPDrawHelpers()->SetContextRTL(hdcSrc2, FALSE);
	XTPDrawHelpers()->SetContextRTL(hdcSrc1, FALSE);

	// Prepare the surfaces for drawing.
	hbmOldSrc1 = (HBITMAP)SelectObject(hdcSrc1, hbmSrc1);
	hbmOldSrc2 = (HBITMAP)SelectObject(hdcSrc2, hbmSrc2);
	SetStretchBltMode(hdcSrc1, COLORONCOLOR);
	SetStretchBltMode(hdcSrc2, COLORONCOLOR);


	// Capture a copy of the source area.
	if (!StretchBlt(hdcSrc1, 0,0,nWidthDest,nHeightDest,
		hdcSrc,  nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc,
		SRCCOPY))
		goto HANDLEERROR;


	// Capture a copy of the destination area.
	if (!BitBlt(hdcSrc2, 0, 0, nWidthDest, nHeightDest,
		hdcDest, nXOriginDest, nYOriginDest, SRCCOPY))
		goto HANDLEERROR;



	SelectObject(hdcSrc1, hbmOldSrc1); hbmOldSrc1 = NULL;
	SelectObject(hdcSrc2, hbmOldSrc2); hbmOldSrc2 = NULL;

	// Blend the two source areas to create the destination image.
	bReturn = BlendImages(hbmSrc1, bRTLSrc, hbmSrc2, bRTLDest, hbmDst);


	// Display the blended (destination) image to the target HDC.
	if (bReturn)
	{
		hbmOldSrc1 = (HBITMAP)SelectObject(hdcSrc1, hbmDst);

		BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest,
			hdcSrc1, 0,0, SRCCOPY | (bRTLDest ? NOMIRRORBITMAP : 0));

		SelectObject(hdcSrc1, hbmOldSrc1);
		hbmOldSrc1 = NULL;
	}

	// Clean up the rest of the objects you created.

HANDLEERROR:

	if (hbmOldSrc1) SelectObject(hdcSrc1, hbmOldSrc1);
	if (hbmOldSrc2) SelectObject(hdcSrc2, hbmOldSrc2);
	if (hdcSrc1) DeleteDC(hdcSrc1);
	if (hdcSrc2) DeleteDC(hdcSrc2);
	if (hbmSrc1) DeleteObject(hbmSrc1);
	if (hbmSrc2) DeleteObject(hbmSrc2);
	if (hbmDst) DeleteObject(hbmDst);

	return bReturn;
}


BOOL CXTPImageManager::AlphaBlend(HDC hdcDest, const CRect& rcDest, HDC hdcSrc, const CRect& rcSrc) const
{
	if (XTPDrawHelpers()->IsContextRTL(hdcDest) && XTPSystemVersion()->IsWin9x())
	{
		return DoAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
			hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height());
	}

	if (XTPDrawHelpers()->m_pfnAlphaBlend && (IsWindow2000() || (rcSrc.top == 0 && rcSrc.left == 0 && rcDest.top >= 0)))
	{
		BLENDFUNCTION bf;
		ZeroMemory(&bf, sizeof(BLENDFUNCTION));

		bf.AlphaFormat  = 0x01;
		bf.SourceConstantAlpha = 255;
		bf.BlendOp = AC_SRC_OVER;

		return XTPDrawHelpers()->m_pfnAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
			hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height(), bf);

	}
	return DoAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
		hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height());
}

BOOL CXTPImageManager::AlphaBlend2(HDC hdcDest, const CRect& rcDest, HDC hdcSrc, const CRect& rcSrc, BYTE Transparency) const
{
	if (XTPDrawHelpers()->IsContextRTL(hdcDest) && XTPSystemVersion()->IsWin9x())
	{
		return DoAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
			hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height());
	}

	if (XTPDrawHelpers()->m_pfnAlphaBlend && (IsWindow2000() || (rcSrc.top == 0 && rcSrc.left == 0)))
	{
		BLENDFUNCTION bf;
		ZeroMemory(&bf, sizeof(BLENDFUNCTION));

		bf.AlphaFormat  = 0;
		bf.SourceConstantAlpha = Transparency;
		bf.BlendOp = AC_SRC_OVER;

		return XTPDrawHelpers()->m_pfnAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
			hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height(), bf);

	}
	return DoAlphaBlend(hdcDest, rcDest.left, rcDest.top, rcDest.Width(), rcDest.Height(),
		hdcSrc, rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height());
}



//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerImageList

CXTPImageManagerImageList::CXTPImageManagerImageList()
{
	m_hImageList = NULL;
	m_bDestroyImageList = FALSE;
	m_nBaseCommand = 0;
	m_pImageManager = NULL;
}

CXTPImageManagerImageList::~CXTPImageManagerImageList()
{
	if (m_hImageList && m_bDestroyImageList)
	{
		ImageList_Destroy(m_hImageList);
	}

	RemoveAll();
}

void CXTPImageManagerImageList::RemoveAll()
{
	UINT nCommand;
	CXTPImageManagerIcon* pIcon;

	POSITION pos = m_mapIcons.GetStartPosition();
	while (pos)
	{
		m_mapIcons.GetNextAssoc(pos, nCommand, pIcon);
		pIcon->InternalRelease();
	}

	m_mapIcons.RemoveAll();
}

BOOL CXTPImageManagerImageList::Lookup(UINT nCommand)
{
	return ((nCommand >= m_nBaseCommand) &&
		(nCommand < m_nBaseCommand + ImageList_GetImageCount(m_hImageList)));
}

CSize CXTPImageManagerImageList::GetIconSize() const
{
	int nWidth = 0, nHeight = 0;
	VERIFY(ImageList_GetIconSize(m_hImageList, &nWidth, &nHeight));

	return CSize(nWidth, nHeight);
}

CXTPImageManagerIcon* CXTPImageManagerImageList::GetIcon(UINT nCommand)
{
	CXTPImageManagerIcon* pImage = NULL;

	if (m_mapIcons.Lookup(nCommand, pImage))
	{
		return pImage;
	}

	CSize sz = GetIconSize();

	pImage = new CXTPImageManagerIcon(nCommand, sz.cx, sz.cy, this);
	m_mapIcons.SetAt(nCommand, pImage);

	return pImage;
}

void CXTPImageManagerImageList::Draw(CDC* pDC, CPoint pt, CXTPImageManagerIcon* pIcon, CSize szIcon, COLORREF clrBK, COLORREF clrFG, UINT uiFlags)
{
	ImageList_DrawEx(m_hImageList, pIcon->GetID() - m_nBaseCommand, pDC->GetSafeHdc(),
		pt.x, pt.y, szIcon.cx, szIcon.cy, clrBK, clrFG, ILD_TRANSPARENT | ILD_NORMAL | uiFlags);
}

//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerIcon


struct CXTPImageManagerIcon::ICONIMAGE
{
	BITMAPINFOHEADER    icHeader;   // DIB header
	RGBQUAD             icColors[1];// Color table
	BYTE                icXOR[1];   // DIB bits for XOR mask
	BYTE                icAND[1];   // DIB bits for AND mask
};

#pragma pack(push, 2)
// resources are WORD-aligned

struct CXTPImageManagerIcon::ICONDIRENTRY
{
	BYTE        bWidth;             // Width, in pixels, of the image
	BYTE        bHeight;            // Height, in pixels, of the image
	BYTE        bColorCount;        // Number of colors in image (0 if >= 8bpp)
	BYTE        bReserved;          // Reserved (must be 0)
	WORD        wPlanes;            // Color Planes
	WORD        wBitCount;          // Bits per pixel
	DWORD       dwBytesInRes;       // How many bytes in this resource ?
	DWORD       dwImageOffset;      // Where in the file is this image ?
};

struct CXTPImageManagerIcon::ICONDIRHEADER
{
	WORD            idReserved;     // Reserved (must be 0)
	WORD            idType;         // Resource Type (1 for icons)
	WORD            idCount;        // How many images ?
};

struct CXTPImageManagerIcon::GRPICONDIRENTRY
{
	BYTE   bWidth;                  // Width, in pixels, of the image
	BYTE   bHeight;                 // Height, in pixels, of the image
	BYTE   bColorCount;             // Number of colors in image (0 if >= 8bpp)
	BYTE   bReserved;               // Reserved
	WORD   wPlanes;                 // Color Planes
	WORD   wBitCount;               // Bits per pixel
	DWORD  dwBytesInRes;            // how many bytes in this resource ?
	WORD   nID;                     // the ID
};

struct CXTPImageManagerIcon::GRPICONDIR
{
	WORD              idReserved;   // Reserved (must be 0)
	WORD              idType;       // Resource type (1 for icons)
	WORD              idCount;      // How many images ?
	GRPICONDIRENTRY   idEntries[1]; // The entries for each image
};

#pragma pack(pop)

BOOL CXTPImageManagerIcon::IsAlphaBitmapFile(LPCTSTR pszFileName)
{
	HANDLE hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	DWORD dwBytesRead;

	BITMAPFILEHEADER fileHeader;

	if (!ReadFile(hFile, &fileHeader, sizeof(BITMAPFILEHEADER), &dwBytesRead, 0) || dwBytesRead != sizeof(BITMAPFILEHEADER))
	{
		CloseHandle(hFile);
		return FALSE;
	}

	BITMAPINFOHEADER infoHeader;

	if (!ReadFile(hFile, &infoHeader, sizeof(BITMAPINFOHEADER), &dwBytesRead, 0) || dwBytesRead != sizeof(BITMAPINFOHEADER))
	{
		CloseHandle(hFile);
		return FALSE;
	}

	BOOL bResult = infoHeader.biBitCount == 32;

	CloseHandle(hFile);

	return bResult;
}

BOOL CXTPImageManagerIcon::IsPngBitmapFile(LPCTSTR pszFileName)
{
	HANDLE hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	DWORD dwBytesRead;

	BYTE fileHeader[4];
	BYTE png_signature[4] = {137, 80, 78, 71};

	if (!ReadFile(hFile, &fileHeader, sizeof(fileHeader), &dwBytesRead, 0) || dwBytesRead != sizeof(fileHeader))
	{
		CloseHandle(hFile);
		return FALSE;
	}

	BOOL bResult = memcmp(&fileHeader, &png_signature, 4) == 0;

	CloseHandle(hFile);

	return bResult;
}


HBITMAP AFX_CDECL CXTPImageManagerIcon::LoadBitmapFromFile(LPCTSTR lpszFileName, BOOL* lbAlphaBitmap)
{
#ifdef _XTP_INCLUDE_GRAPHICLIBRARY
	BOOL bPngBitmap = CXTPImageManagerIcon::IsPngBitmapFile(lpszFileName);

	if (bPngBitmap)
	{
		CXTPGraphicBitmapPng bmp;
		if (!bmp.LoadFromFile(lpszFileName))
			return NULL;

		if (lbAlphaBitmap)
		{
			*lbAlphaBitmap = bmp.IsAlpha();
		}
		return (HBITMAP)bmp.Detach();
	}
#endif
	BOOL bAlphaBitmap = CXTPImageManagerIcon::IsAlphaBitmapFile(lpszFileName);

	HBITMAP hBmp = (HBITMAP)LoadImage(0, lpszFileName,
		IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | (bAlphaBitmap ? LR_CREATEDIBSECTION : 0) | LR_LOADFROMFILE);

	if (hBmp)
	{
		if (lbAlphaBitmap)
		{
			*lbAlphaBitmap = bAlphaBitmap;
		}
		return hBmp;
	}

	LPPICTURE pPict = NULL;

	if (OleLoadPicturePath((LPOLESTR)XTP_CT2CW(lpszFileName), NULL, 0, 0, IID_IPicture, (LPVOID*)&pPict) == S_OK)
	{
		CDC dc;
		dc.CreateCompatibleDC(NULL);

		long hmWidth;
		long hmHeight;

		pPict->get_Width(&hmWidth);
		pPict->get_Height(&hmHeight);

		int cx = MulDiv(dc.GetDeviceCaps(LOGPIXELSX), (int)hmWidth, 2540);
		int cy = MulDiv(dc.GetDeviceCaps(LOGPIXELSY), (int)hmHeight, 2540);

		HBITMAP hbmpImage = CXTPImageManager::Create32BPPDIBSection(NULL, cx, cy);

		HGDIOBJ hOldBitmap = ::SelectObject(dc, hbmpImage);
		dc.FillSolidRect(0, 0, cx, cy, GetSysColor(COLOR_3DFACE));

		pPict->Render(dc, 0, 0, cx, cy, 0, hmHeight-1, hmWidth, -hmHeight, 0);

		::SelectObject(dc, hOldBitmap);

		pPict->Release();

		return hbmpImage;
	}

	return NULL;
}


BOOL AFX_CDECL CXTPImageManagerIcon::IsPngBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName)
{
	BYTE png_signature[4] = {137, 80, 78, 71};

	HRSRC hResource = ::FindResource(hModule, lpBitmapName, _T("PNG"));

	if (hResource == NULL)
		return FALSE;

	HGLOBAL hGlobal = LoadResource(hModule, hResource);
	if (hGlobal == NULL)
		return FALSE;

	LPBYTE pBitmapInfoHeader = (LPBYTE)::LockResource(hGlobal);
	BOOL bPngBitmap = memcmp(pBitmapInfoHeader, &png_signature, 4) == 0;

	UnlockResource(hGlobal);
	FreeResource(hGlobal);

	return (bPngBitmap);
}

BOOL AFX_CDECL CXTPImageManagerIcon::IsAlphaBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName)
{
	HRSRC hResource = ::FindResource(hModule, lpBitmapName, RT_BITMAP);

	if (hResource == NULL)
		return FALSE;

	HGLOBAL hGlobal = LoadResource(hModule, hResource);
	if (hGlobal == NULL)
		return FALSE;

	LPBITMAPINFOHEADER pBitmapInfoHeader = (LPBITMAPINFOHEADER)::LockResource(hGlobal);
	ASSERT(pBitmapInfoHeader != NULL);
	if (!pBitmapInfoHeader)
		return FALSE;

	BOOL bAlpahBitmap = pBitmapInfoHeader->biBitCount == 32;
	UnlockResource(hGlobal);
	FreeResource(hGlobal);

	return (bAlpahBitmap);
}

HBITMAP AFX_CDECL CXTPImageManagerIcon::LoadBitmapFromResource(LPCTSTR lpszResource, BOOL* lbAlphaBitmap)
{
	HMODULE hModule;

#ifdef _XTP_INCLUDE_GRAPHICLIBRARY
	hModule = AfxFindResourceHandle(lpszResource, _T("PNG"));

	BOOL bPngBitmap = IsPngBitmapResource(hModule, lpszResource);
	if (bPngBitmap)
	{
		CXTPGraphicBitmapPng bmpIcons;

		HRSRC hResource = ::FindResource(hModule, lpszResource, _T("PNG"));

		if (!bmpIcons.LoadFromResource(hModule, hResource))
			return NULL;

		if (lbAlphaBitmap)
		{
			*lbAlphaBitmap = bmpIcons.IsAlpha();
		}

		return (HBITMAP)bmpIcons.Detach();
	}
#endif

	hModule = AfxFindResourceHandle(lpszResource, RT_BITMAP);

	CBitmap bmpIcons;
	BOOL bAlphaBitmap = IsAlphaBitmapResource(hModule, lpszResource);

	if (lbAlphaBitmap)
	{
		*lbAlphaBitmap = bAlphaBitmap;
	}

	if (bAlphaBitmap)
	{
		return LoadAlphaBitmap(hModule, lpszResource);
	}

	return (HBITMAP)LoadImage(hModule, lpszResource, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
}

HBITMAP AFX_CDECL CXTPImageManagerIcon::LoadBitmapFromResource(HMODULE hModule, LPCTSTR lpszResource, BOOL* lbAlphaBitmap)
{
#ifdef _XTP_INCLUDE_GRAPHICLIBRARY

	BOOL bPngBitmap = IsPngBitmapResource(hModule, lpszResource);
	if (bPngBitmap)
	{
		CXTPGraphicBitmapPng bmpIcons;

		HRSRC hResource = ::FindResource(hModule, lpszResource, _T("PNG"));

		if (!bmpIcons.LoadFromResource(hModule, hResource))
			return NULL;

		if (lbAlphaBitmap)
		{
			*lbAlphaBitmap = bmpIcons.IsAlpha();
		}

		return (HBITMAP)bmpIcons.Detach();
	}
#endif

	CBitmap bmpIcons;
	BOOL bAlphaBitmap = IsAlphaBitmapResource(hModule, lpszResource);

	if (lbAlphaBitmap)
	{
		*lbAlphaBitmap = bAlphaBitmap;
	}

	if (bAlphaBitmap)
	{
		return LoadAlphaBitmap(hModule, lpszResource);
	}

	return (HBITMAP)LoadImage(hModule, lpszResource, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
}

HBITMAP CXTPImageManagerIcon::LoadAlphaBitmap(UINT nIDResource)
{
	return LoadAlphaBitmap(AfxFindResourceHandle(MAKEINTRESOURCE(nIDResource), RT_BITMAP),
		MAKEINTRESOURCE(nIDResource));
}

HBITMAP CXTPImageManagerIcon::LoadAlphaBitmap(HMODULE hModule, LPCTSTR lpszResource)
{
	HRSRC hResource = ::FindResource(hModule, lpszResource, RT_BITMAP);
	if (hResource == NULL)
		return NULL;

	HGLOBAL hGlobal = LoadResource(hModule, hResource);
	if (hGlobal == NULL)
		return NULL;

	LPBITMAPINFO pResourceInfo = (LPBITMAPINFO)::LockResource(hGlobal);
	ASSERT(pResourceInfo != NULL);
	if (!pResourceInfo)
		return NULL;

	int biSizeImage = pResourceInfo->bmiHeader.biHeight * pResourceInfo->bmiHeader.biWidth * 4;

	HBITMAP hbmResult = NULL;

	if (pResourceInfo->bmiHeader.biBitCount == 32 &&
		SizeofResource(hModule, hResource) >= int(biSizeImage + sizeof(BITMAPINFOHEADER)))
	{
		CDC dcSrc;
		dcSrc.CreateCompatibleDC(NULL);

		PBITMAPINFO pBitmapInfo = (PBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + sizeof(COLORREF) * 3);
		ASSERT(pBitmapInfo != NULL);
		if (!pBitmapInfo)
			return NULL;

		MEMCPY_S(pBitmapInfo, &pResourceInfo->bmiHeader, sizeof(BITMAPINFOHEADER));
		pBitmapInfo->bmiHeader.biSizeImage = biSizeImage;

		BYTE* pDestBits = NULL;
		HBITMAP hBmp = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pDestBits, NULL, 0);

		if (hBmp && pDestBits)
		{
			MEMCPY_S(pDestBits, &pResourceInfo->bmiColors, biSizeImage);
			hbmResult = hBmp;
		}
		FREE(pBitmapInfo);
	}

	UnlockResource(hGlobal);
	FreeResource(hGlobal);

	return hbmResult;

}



HBITMAP CXTPImageManagerIcon::LoadAlphaIcon(LPCTSTR pszFileName, int nWidth)
{

	HANDLE hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	ICONDIRHEADER idh;

	DWORD dwBytesRead = 0;
	if (!ReadFile(hFile, &idh, sizeof(ICONDIRHEADER) , &dwBytesRead, NULL) || dwBytesRead != sizeof(ICONDIRHEADER))
	{
		CloseHandle(hFile);
		return FALSE;
	}

	if (idh.idType != 1 || idh.idCount == 0)
	{
		CloseHandle(hFile);
		return FALSE;
	}


	ICONDIRENTRY* pEntries = (ICONDIRENTRY*)malloc(sizeof(ICONDIRENTRY) * idh.idCount);

	if (pEntries == NULL)
	{
		CloseHandle(hFile);
		return FALSE;
	}

	if (!ReadFile(hFile, pEntries, idh.idCount * sizeof(ICONDIRENTRY), &dwBytesRead, NULL)
		|| dwBytesRead != idh.idCount * sizeof(ICONDIRENTRY))
	{
		free(pEntries);
		CloseHandle(hFile);
		return FALSE;
	}

	HBITMAP hBitmap = 0;

	for (int i = 0; i < idh.idCount; i++)
	{
		if (pEntries[i].wBitCount == 32 && (((int)pEntries[i].bWidth == nWidth) || (nWidth == 0)))
		{
			if (!SetFilePointer(hFile, pEntries[i].dwImageOffset,
				NULL, FILE_BEGIN))
				continue;

			ICONIMAGE* pIconImage = (ICONIMAGE*)malloc(pEntries[i].dwBytesInRes);
			if (pIconImage == NULL)
				continue;

			dwBytesRead = 0;
			BOOL bResult = ReadFile(hFile, pIconImage, pEntries[i].dwBytesInRes,
				&dwBytesRead, NULL);

			if (!bResult || (dwBytesRead != pEntries[i].dwBytesInRes) || (pIconImage->icHeader.biBitCount != 32))
			{
				free(pIconImage);
				continue;
			}

			CDC dcSrc;
			dcSrc.CreateCompatibleDC(NULL);

			pIconImage->icHeader.biHeight /= 2;
			pIconImage->icHeader.biSizeImage = pIconImage->icHeader.biHeight * pIconImage->icHeader.biWidth * 4;

			BYTE* pDest = NULL;
			HBITMAP hBmp = CreateDIBSection(dcSrc, (BITMAPINFO*)&pIconImage->icHeader, DIB_RGB_COLORS, (void**)&pDest, NULL, 0);

			if (pDest != NULL && hBmp != NULL)
			{
				MEMCPY_S(pDest, &pIconImage->icColors, pIconImage->icHeader.biSizeImage);
				hBitmap = hBmp;

				free(pIconImage);
				break;
			}

			free(pIconImage);
		}
	}
	free(pEntries);
	CloseHandle(hFile);

	return hBitmap;

}

BOOL CXTPImageManager::SetIconFromIcoFile(LPCTSTR pszFileName, UINT nIDCommand, CSize szIcon, XTPImageState imageState)
{
	HANDLE hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	CXTPImageManagerIcon::ICONDIRHEADER idh;

	DWORD dwBytesRead = 0;
	if (!ReadFile(hFile, &idh, sizeof(CXTPImageManagerIcon::ICONDIRHEADER) , &dwBytesRead, NULL) || dwBytesRead != sizeof(CXTPImageManagerIcon::ICONDIRHEADER))
	{
		CloseHandle(hFile);
		return FALSE;
	}

	if (idh.idType != 1 || idh.idCount == 0)
	{
		CloseHandle(hFile);
		return FALSE;
	}


	CXTPImageManagerIcon::ICONDIRENTRY* pEntries = (CXTPImageManagerIcon::ICONDIRENTRY*)malloc(sizeof(CXTPImageManagerIcon::ICONDIRENTRY) * idh.idCount);

	if (pEntries == NULL)
	{
		CloseHandle(hFile);
		return FALSE;
	}

	if (!ReadFile(hFile, pEntries, idh.idCount * sizeof(CXTPImageManagerIcon::ICONDIRENTRY), &dwBytesRead, NULL)
		|| dwBytesRead != idh.idCount * sizeof(CXTPImageManagerIcon::ICONDIRENTRY))
	{
		free(pEntries);
		CloseHandle(hFile);
		return FALSE;
	}

	BOOL bResult = FALSE;

	for (int i = 0; i < idh.idCount; i++)
	{
		CSize szResourceIcon((int)pEntries[i].bWidth, (int)pEntries[i].bHeight);
		CXTPImageManagerIconHandle hIcon;

		if ((szIcon == szResourceIcon) || (szIcon == CSize(0, 0)))
		{
			if (!SetFilePointer(hFile, pEntries[i].dwImageOffset,
				NULL, FILE_BEGIN))
				continue;

			CXTPImageManagerIcon::ICONIMAGE* pIconImage = (CXTPImageManagerIcon::ICONIMAGE*)malloc(pEntries[i].dwBytesInRes);
			if (pIconImage == NULL)
				continue;

			dwBytesRead = 0;
			BOOL bReadFile = ReadFile(hFile, pIconImage, pEntries[i].dwBytesInRes,
				&dwBytesRead, NULL);

			if (!bReadFile || (dwBytesRead != pEntries[i].dwBytesInRes))
			{
				free(pIconImage);
				continue;
			}

			if (pIconImage->icHeader.biBitCount == 32)
			{

				CDC dcSrc;
				dcSrc.CreateCompatibleDC(NULL);

				pIconImage->icHeader.biHeight /= 2;
				pIconImage->icHeader.biSizeImage = pIconImage->icHeader.biHeight * pIconImage->icHeader.biWidth * 4;

				BYTE* pDest = NULL;
				HBITMAP hBitmap = CreateDIBSection(dcSrc, (BITMAPINFO*)&pIconImage->icHeader, DIB_RGB_COLORS, (void**)&pDest, NULL, 0);

				if (pDest != NULL && hBitmap != NULL)
				{
					MEMCPY_S(pDest, &pIconImage->icColors, pIconImage->icHeader.biSizeImage);

					hIcon = hBitmap;
				}
			}
			else
			{
				hIcon = CreateIconFromResourceEx((PBYTE)pIconImage, pEntries[i].dwBytesInRes, TRUE,
					0x00030000, szResourceIcon.cx, szResourceIcon.cy, LR_DEFAULTCOLOR);
			}

			if (!hIcon.IsEmpty())
			{
				SetIcon(hIcon, nIDCommand, szResourceIcon, imageState);
				bResult = TRUE;
			}

			free(pIconImage);
		}
	}
	free(pEntries);
	CloseHandle(hFile);

	return bResult;
}

//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerResource

CXTPImageManagerResource::CXTPImageManagerResource(CXTPImageManager* pImageManager, CSize szIcon)
{
	m_pImageManager = pImageManager;
	m_szIcon = szIcon;
	m_pBits = NULL;
	m_nAllocWidth = 0;

	m_hbmpImage = 0;
	m_hbmpMask = 0;

	HDC hdcScreen = ::GetDC(HWND_DESKTOP);
	m_dc.Attach(::CreateCompatibleDC(hdcScreen));
	ReleaseDC(HWND_DESKTOP, hdcScreen);

	::InitializeCriticalSection(&m_cs);
}

CXTPImageManagerResource::~CXTPImageManagerResource()
{
	RemoveAll();

	::DeleteCriticalSection(&m_cs);
}

void CXTPImageManagerResource::RemoveAll()
{
	int i;
	for (i = 0; i < (int)m_arrIcons.GetSize(); i++)
	{
		delete m_arrIcons[i];
	}
	m_arrIcons.RemoveAll();

	for (i = 0; i < (int)m_arrAlloc.GetSize(); i++)
	{
		delete m_arrAlloc[i];
	}
	m_arrAlloc.RemoveAll();


	if (m_hbmpImage)
	{
		DeleteObject(m_hbmpImage);
		m_hbmpImage = NULL;
	}
	if (m_hbmpMask)
	{
		DeleteObject(m_hbmpMask);
		m_hbmpMask = NULL;
	}

	m_nAllocWidth = 0;
	m_pBits = NULL;
}


CXTPImageManagerResource* CXTPImageManager::GetResource(CSize szIcon)
{
	DWORD dwSize = MAKELONG(szIcon.cx, szIcon.cy);

	CXTPImageManagerResource* pResource = NULL;
	if (m_mapResources.Lookup(dwSize, pResource))
		return pResource;

	pResource = new CXTPImageManagerResource(this, szIcon);
	m_mapResources.SetAt(dwSize, pResource);

	return pResource;
}

XTP_IMAGERESOURCE_INFO* CXTPImageManagerResource::AllocBitmap()
{
	if (m_arrAlloc.GetSize() > 0)
	{
		XTP_IMAGERESOURCE_INFO* pRInfo = m_arrAlloc[m_arrAlloc.GetSize() - 1];
		m_arrAlloc.RemoveAt(m_arrAlloc.GetSize() - 1);
		m_arrIcons.Add(pRInfo);
		return pRInfo;
	}

	if (!m_hbmpImage && !m_hbmpMask)
	{
		m_hbmpImage = CXTPImageManager::Create32BPPDIBSection(NULL, m_szIcon.cx, m_szIcon.cy, &m_pBits);
		m_hbmpMask = CreateBitmap(m_szIcon.cx, m_szIcon.cy, 1, 1, NULL);

		m_nAllocWidth = m_szIcon.cx;

		if (!m_hbmpImage || !m_hbmpMask)
			return NULL;

		XTP_IMAGERESOURCE_INFO* pRInfo = new XTP_IMAGERESOURCE_INFO();
		pRInfo->pResource = this;
		pRInfo->bAlpha = FALSE;
		pRInfo->rc = CRect(0, 0, m_szIcon.cx, m_szIcon.cy);

		m_arrIcons.Add(pRInfo);
		return pRInfo;
	}

	LPBYTE pBits = NULL;
	HBITMAP hbmpImage = CXTPImageManager::Create32BPPDIBSection(NULL, m_szIcon.cx + m_nAllocWidth, m_szIcon.cy, &pBits);
	HBITMAP hbmpMask = CreateBitmap(m_szIcon.cx + m_nAllocWidth, m_szIcon.cy, 1, 1, NULL);

	if (hbmpImage && pBits)
	{
		LPBYTE pBitsI = pBits;

		for (int y = 0; y < m_szIcon.cy; y++)
		{
			memcpy(pBitsI, m_pBits, m_nAllocWidth * 4);
			m_pBits += m_nAllocWidth * 4;
			pBitsI += (m_szIcon.cx + m_nAllocWidth) * 4;
		}
	}
	else
	{
		return NULL;
	}

	if (hbmpMask)
	{
		m_dc.SetBitmap(hbmpMask);
		m_dc.DrawState(CPoint(0, 0), CSize(0, 0), m_hbmpMask, 0, 0);
		m_dc.SetBitmap(NULL);
	}
	else
	{
		return NULL;
	}

	DeleteObject(m_hbmpImage);
	DeleteObject(m_hbmpMask);

	m_hbmpImage = hbmpImage;
	m_hbmpMask = hbmpMask;
	m_pBits = pBits;

	XTP_IMAGERESOURCE_INFO* pRInfo = new XTP_IMAGERESOURCE_INFO();
	pRInfo->pResource = this;
	pRInfo->bAlpha = FALSE;
	pRInfo->rc = CRect(m_nAllocWidth, 0, m_nAllocWidth + m_szIcon.cx, m_szIcon.cy);
	m_arrIcons.Add(pRInfo);

	m_nAllocWidth += m_szIcon.cx;

	return pRInfo;
}

void CXTPImageManagerResource::Clear(XTP_IMAGERESOURCE_INFO* pRInfo)
{
	CXTPLockGuard lock(m_cs);

	for (int i = 0; i < (int)m_arrIcons.GetSize(); i++)
	{
		if (m_arrIcons[i] == pRInfo)
		{
			m_arrIcons.RemoveAt(i);
			m_arrAlloc.Add(pRInfo);

			if (m_arrAlloc.GetSize() * m_szIcon.cx == m_nAllocWidth)
			{
				ASSERT(m_arrIcons.GetSize() == 0);
				RemoveAll();
			}
			return;
		}
	}
}

BOOL AFX_CDECL CXTPImageManagerIcon::IsAlphaIconHandle(HICON hIcon)
{
	if (!hIcon)
		return FALSE;

	ICONINFO iconInfo;
	if ((CXTPImageManager::IsAlphaIconsImageListSupported() || XTPSystemVersion()->IsWinXPOrGreater())
		&& GetIconInfo(hIcon, &iconInfo))
	{
		LPBYTE pBitsI = NULL;
		BOOL bAlpha = -1;
		HBITMAP hBitmap = CXTPImageManagerIcon::PreMultiplyAlphaBitmap(iconInfo.hbmColor, &bAlpha, &pBitsI);

		DeleteObject(iconInfo.hbmColor);
		DeleteObject(iconInfo.hbmMask);

		if (bAlpha == TRUE && pBitsI)
		{
			DeleteObject(hBitmap);
			return TRUE;
		}

		if (hBitmap) DeleteObject(hBitmap);
	}

	return FALSE;
}

XTP_IMAGERESOURCE_INFO* CXTPImageManagerResource::Add(const CXTPImageManagerIconHandle& hHandle)
{
	CXTPLockGuard lock(m_cs);

	ASSERT(hHandle.m_pRInfo == NULL);
	ASSERT(!hHandle.IsEmpty());
	if (hHandle.IsEmpty())
		return NULL;

	if (hHandle.GetExtent() != GetExtent())
		return NULL;

	if (!hHandle.m_hIcon && !hHandle.m_hBitmap)
		return NULL;

	XTP_IMAGERESOURCE_INFO* pRInfo = AllocBitmap();
	if (pRInfo == NULL)
		return NULL;

	if (hHandle.m_hIcon)
	{
		ICONINFO iconInfo;
		if (CXTPImageManager::IsAlphaIconsImageListSupported() && GetIconInfo(hHandle.m_hIcon, &iconInfo))
		{
			LPBYTE pBitsI = NULL;
			BOOL bAlpha = -1;
			HBITMAP hBitmap = CXTPImageManagerIcon::PreMultiplyAlphaBitmap(iconInfo.hbmColor, &bAlpha, &pBitsI);

			DeleteObject(iconInfo.hbmColor);
			DeleteObject(iconInfo.hbmMask);

			if (bAlpha == TRUE && pBitsI)
			{
				for (int y = 0; y < m_szIcon.cy; y++)
				{
					LPBYTE pBitsRow = m_pBits + ((y * m_nAllocWidth + pRInfo->rc.left) * 4);
					memcpy(pBitsRow, pBitsI, m_szIcon.cx * 4);
					pBitsI += m_szIcon.cx * 4;
				}

				pRInfo->bAlpha = TRUE;

				DeleteObject(hBitmap);
				return pRInfo;
			}

			if (hBitmap) DeleteObject(hBitmap);
		}

		if (m_hbmpImage)
		{
			m_dc.SetBitmap(m_hbmpImage);
			m_dc.FillSolidRect(pRInfo->rc, 0);
			DrawIconEx(m_dc, pRInfo->rc.left, pRInfo->rc.top, hHandle.m_hIcon, 0, 0, 0, NULL, DI_NORMAL);
			m_dc.SetBitmap(NULL);
		}

		if (m_hbmpMask)
		{
			m_dc.SetBitmap(m_hbmpMask);
			m_dc.FillSolidRect(pRInfo->rc, 0);
			DrawIconEx(m_dc, pRInfo->rc.left, pRInfo->rc.top, hHandle.m_hIcon, 0, 0, 0, NULL, DI_MASK);
			m_dc.SetBitmap(NULL);
		}

		pRInfo->bAlpha = FALSE;
	}
	else
	{
		LPBYTE pBitsI = ((CXTPImageManagerIconHandle&)hHandle).PreMultiply();
		if (!pBitsI)
			return NULL;

		for (int y = 0; y < m_szIcon.cy; y++)
		{
			LPBYTE pBitsRow = m_pBits + ((y * m_nAllocWidth + pRInfo->rc.left) * 4);
			memcpy(pBitsRow, pBitsI, m_szIcon.cx * 4);
			pBitsI += m_szIcon.cx * 4;
		}

		pRInfo->bAlpha = TRUE;
	}

	return pRInfo;
}

BOOL CXTPImageManager::IsDrawReverted(CDC* pDC) const
{
	if (m_bDrawReverted == 1)
		return TRUE;
	if (m_bDrawReverted == 2)
		return CXTPDrawHelpers::IsContextRTL(pDC);
	return FALSE;
}

void CXTPImageManagerResource::CreateIcon(CXTPImageManagerIconHandle& hHandle, XTP_IMAGERESOURCE_INFO* pRInfo)
{
	CXTPLockGuard lock(m_cs);

	hHandle.Clear();

	HBITMAP hBitmap = 0;
	LPBYTE pBits = 0;


	{
		hBitmap = CXTPImageManager::Create32BPPDIBSection(NULL, m_szIcon.cx, m_szIcon.cy, &pBits);
		if (!hBitmap || !pBits)
			return;

		LPBYTE pBitsI = pBits;

		for (int y = 0; y < m_szIcon.cy; y++)
		{
			LPBYTE pBitsRow = m_pBits + ((y * m_nAllocWidth + pRInfo->rc.left) * 4);
			memcpy(pBitsI, pBitsRow, m_szIcon.cx * 4);
			pBitsI += m_szIcon.cx * 4;
		}
	}

	if (pRInfo->bAlpha)
	{
		hHandle.m_hBitmap = hBitmap;
		hHandle.m_pBits = pBits;
	}
	else
	{
		HBITMAP hbmpMask = CreateBitmap(m_szIcon.cx, m_szIcon.cy, 1, 1, NULL);
		{
			CXTPCompatibleDC dc(0, hbmpMask);
			m_dc.SetBitmap(m_hbmpMask);
			dc.BitBlt(0, 0, m_szIcon.cx, m_szIcon.cy, &m_dc, pRInfo->rc.left, 0, SRCCOPY);
			m_dc.SetBitmap(NULL);
		}

		ICONINFO ii;
		ii.fIcon    = TRUE;
		ii.xHotspot = 0;
		ii.yHotspot = 0;
		ii.hbmColor = hBitmap;
		ii.hbmMask  = hbmpMask;
		hHandle.m_hIcon = CreateIconIndirect(&ii);

		DeleteObject(hBitmap);
		DeleteObject(hbmpMask);
	}

	hHandle.m_bClearHandles = TRUE;
}


void CXTPImageManagerResource::DrawIconComposited(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon)
{
	CBitmap bmp;
	LPDWORD lpBits = 0;
	bmp.Attach(CXTPImageManager::Create32BPPDIBSection(pDC->GetSafeHdc(), szIcon.cx, szIcon.cy, (LPBYTE*)&lpBits));
	if (!lpBits)
		return;

	CXTPCompatibleDC dc(&m_dc, &bmp);

	dc.SetBkColor(0xFFFFFF);
	dc.SetTextColor(0);

	if (m_hbmpMask)
	{
		m_dc.SetBitmap(m_hbmpMask);
		StretchBlt(dc, 0, 0, szIcon.cx, szIcon.cy, m_dc, pRInfo->rc.left, 0, m_szIcon.cx, m_szIcon.cy, SRCCOPY);
		m_dc.SetBitmap(NULL);
	}

	for (int i = 0; i < szIcon.cx * szIcon.cy; i++)
	{
		*lpBits =  (*lpBits == 0) ? 0xFF000000 : 0;
		lpBits++;
	}

	if (m_hbmpImage)
	{
		m_dc.SetBitmap(m_hbmpImage);
		StretchBlt(dc, 0, 0, szIcon.cx, szIcon.cy, m_dc, pRInfo->rc.left, 0, m_szIcon.cx, m_szIcon.cy, SRCINVERT);
		m_dc.SetBitmap(NULL);
	}

	XTPImageManager()->AlphaBlend(*pDC, CRect(pt, szIcon), dc, CRect(0, 0, szIcon.cx, szIcon.cy));
}


void CXTPImageManagerResource::Draw(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon, BOOL bDrawComposited)
{
	CXTPLockGuard lock(m_cs);

	if (!pRInfo->bAlpha)
	{
		pDC->SetStretchBltMode(COLORONCOLOR);

		if (bDrawComposited)
		{
			DrawIconComposited(pDC, pRInfo, pt, szIcon);
			return;
		}

		if (m_pImageManager->IsDrawReverted(pDC))
		{
			pt.x += szIcon.cx;
			szIcon.cx = -szIcon.cx;
		}

		if (m_hbmpMask)
		{
			m_dc.SetBitmap(m_hbmpMask);
			m_dc.SetTextColor(0);
			m_dc.SetBkColor(0xFFFFFF);

			COLORREF clrOldText = pDC->SetTextColor(0);
			COLORREF clrOldBk = pDC->SetBkColor(0xFFFFFF);

			StretchBlt(pDC->GetSafeHdc(), pt.x, pt.y, szIcon.cx, szIcon.cy, m_dc, pRInfo->rc.left,  0,  m_szIcon.cx, m_szIcon.cy, SRCAND);

			pDC->SetBkColor(clrOldBk);
			pDC->SetTextColor(clrOldText);
			m_dc.SetBitmap(NULL);
		}

		if (m_hbmpImage)
		{
			m_dc.SetBitmap(m_hbmpImage);
			StretchBlt(pDC->GetSafeHdc(), pt.x, pt.y, szIcon.cx, szIcon.cy, m_dc, pRInfo->rc.left,  0,  m_szIcon.cx, m_szIcon.cy, SRCINVERT);
			m_dc.SetBitmap(NULL);
		}
	}
	else
	{
		m_dc.SetBitmap(m_hbmpImage);
		XTPImageManager()->AlphaBlend(pDC->GetSafeHdc(), CRect(pt, szIcon),
			m_dc, CRect(pRInfo->rc.TopLeft(), m_szIcon));
		m_dc.SetBitmap(NULL);
	}
}

CSize CXTPImageManagerResource::GetExtent() const
{
	return m_szIcon;
}


//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerIconHandle

void CXTPImageManagerIconHandle::Init()
{
	m_hIcon = NULL;
	m_hBitmap = NULL;
	m_pBits = NULL;
	m_bClearHandles = FALSE;
	m_pImageManager = NULL;
	m_pRInfo = NULL;
	m_szIcon = CSize(0, 0);
	m_bUseResources = TRUE;
}

CXTPImageManagerIconHandle::CXTPImageManagerIconHandle()
{
	Init();
}

CXTPImageManagerIconHandle::CXTPImageManagerIconHandle(HICON hIcon, BOOL bUseResources)
{
	Init();

	m_hIcon = hIcon;
	m_bClearHandles = FALSE;
	m_szIcon = _GetExtent();
	m_bUseResources = bUseResources;
}

CXTPImageManagerIconHandle::CXTPImageManagerIconHandle(HBITMAP hBitmap)
{
	Init();

	m_hBitmap = hBitmap;
	m_bClearHandles = FALSE;
	m_szIcon = _GetExtent();
}

CXTPImageManagerIconHandle::CXTPImageManagerIconHandle(const CXTPImageManagerIconHandle& hHandle)
{
	Init();

	m_hIcon = hHandle.m_hIcon;
	m_hBitmap = hHandle.m_hBitmap;
	m_pBits = hHandle.m_pBits;
	m_pRInfo = hHandle.m_pRInfo;
	m_pImageManager = hHandle.m_pImageManager;
	m_bUseResources = hHandle.m_bUseResources;

	m_bClearHandles = FALSE;
	m_szIcon = hHandle.GetExtent();
}


void CXTPImageManagerIconHandle::CopyHandle(HBITMAP hBitmap)
{
	Clear();
	m_hBitmap = CXTPImageManagerIcon::CopyAlphaBitmap(hBitmap);

	m_szIcon = _GetExtent();
	m_bClearHandles = TRUE;
}

void CXTPImageManagerIconHandle::CopyHandle(const CXTPImageManagerIconHandle& hHandle)
{
	Clear();

	if (m_pImageManager && !hHandle.IsEmpty() && m_pImageManager->m_bUseResources && hHandle.m_bUseResources)
	{
		CXTPImageManagerResource* pResource = m_pImageManager->GetResource(hHandle.GetExtent());

		if (hHandle.m_pRInfo == NULL)
		{
			m_pRInfo = pResource->Add(hHandle);
		}
		else
		{
			CXTPImageManagerIconHandle iconClear;
			iconClear.CopyHandle(hHandle);
			m_pRInfo = pResource->Add(iconClear);
		}
	}
	else
	{
		if (hHandle.m_hIcon) m_hIcon = CopyIcon(hHandle.m_hIcon);
		if (hHandle.m_hBitmap) m_hBitmap = CXTPImageManagerIcon::CopyAlphaBitmap(hHandle.m_hBitmap, hHandle.m_pBits ? &m_pBits : NULL);
		if (hHandle.m_pRInfo)
		{
			hHandle.m_pRInfo->pResource->CreateIcon(*this, hHandle.m_pRInfo);
		}
	}
	m_bUseResources = hHandle.m_bUseResources;

	m_bClearHandles = TRUE;
	m_szIcon = hHandle.GetExtent();
}

const CXTPImageManagerIconHandle& CXTPImageManagerIconHandle::operator=(const HICON hIcon)
{
	Clear();
	m_hIcon = hIcon;
	m_bClearHandles = TRUE;
	m_szIcon = _GetExtent();

	return *this;
}
const CXTPImageManagerIconHandle& CXTPImageManagerIconHandle::operator=(const HBITMAP hBitmap)
{
	Clear();

	m_hBitmap = hBitmap;
	m_bClearHandles = TRUE;
	m_szIcon = _GetExtent();

	return *this;
}

CXTPImageManagerIconHandle::~CXTPImageManagerIconHandle()
{
	Clear();
}

BOOL CXTPImageManagerIconHandle::IsEmpty() const
{
	return (m_hIcon == 0 && m_hBitmap == 0 && m_pRInfo == NULL) || (m_szIcon == CSize(0, 0));
}

BOOL CXTPImageManagerIconHandle::IsAlpha() const
{
	return m_hBitmap != 0 || (m_pRInfo && m_pRInfo->bAlpha);
}

HBITMAP CXTPImageManagerIconHandle::GetBitmap() const
{
	ASSERT(IsAlpha());

	if (m_hBitmap)
		return m_hBitmap;

	if (m_pRInfo && m_pRInfo->pResource && m_pRInfo->pResource->m_hbmpImage)
		return m_pRInfo->pResource->m_hbmpImage;

	ASSERT(FALSE);
	return NULL;
}

HICON CXTPImageManagerIconHandle::GetIcon() const
{
	return m_hIcon;
}

void CXTPImageManagerIconHandle::Detach()
{
	m_bClearHandles = FALSE;
	Clear();
}

void CXTPImageManagerIconHandle::Clear()
{
	if (m_bClearHandles)
	{
		if (m_hIcon)
		{
			DestroyIcon(m_hIcon);
		}

		if (m_hBitmap)
		{
			DeleteObject(m_hBitmap);
		}

		if (m_pRInfo)
		{
			m_pRInfo->pResource->Clear(m_pRInfo);
			m_pRInfo = NULL;
		}
	}

	m_hIcon = 0;
	m_hBitmap = 0;
	m_pBits = 0;
	m_pRInfo = NULL;
	m_bClearHandles = FALSE;
}

CSize CXTPImageManagerIconHandle::GetExtent() const
{
	return m_szIcon;
}

CSize CXTPImageManagerIconHandle::_GetExtent() const
{
	if (m_pRInfo != NULL)
		return m_pRInfo->pResource->GetExtent();

	if (m_hIcon)
		return CXTPImageManagerIcon::GetExtent(m_hIcon);

	if (m_hBitmap)
	{
		BITMAP bmpinfo;
		if (::GetObject(m_hBitmap, sizeof(bmpinfo), &bmpinfo))
		{
			return CSize((int)bmpinfo.bmWidth, (int)bmpinfo.bmHeight);
		}
	}
	return 0;
}



void CXTPImageManagerIconHandle::Draw(CDC* pDC, CPoint pt, CSize szIcon, BOOL bDrawComposited)
{
	if (IsEmpty())
		return;

	if (m_pRInfo)
	{
		m_pRInfo->pResource->Draw(pDC, m_pRInfo, pt, szIcon, bDrawComposited);
	}
	else if (!IsAlpha())
	{
		CXTPImageManager* pImageManager = m_pImageManager ? m_pImageManager : XTPImageManager();

		if (pImageManager->IsDrawReverted(pDC))
		{
			pt.x += szIcon.cx;
			szIcon.cx = -szIcon.cx;
		}

		if (!bDrawComposited)
		{
			DrawIconEx(pDC->GetSafeHdc(), pt.x, pt.y, GetIcon(), szIcon.cx, szIcon.cy, 0, 0, DI_NORMAL);
		}
		else
		{
			CXTPImageManagerIcon::DrawIconComposited(pDC, pt, szIcon, GetIcon());
		}
	}
	else if (PreMultiply())
	{
		if (pt.y < 0 && (szIcon.cy == (int)m_szIcon.cy))
		{
			if (pt.y + m_szIcon.cy > 0)
			{
				CXTPImageManagerIcon::DrawAlphaBitmap(pDC, m_hBitmap, CPoint(pt.x, 0),
					CSize(szIcon.cx, m_szIcon.cy + pt.y), CPoint(0, -pt.y), CSize(m_szIcon.cx, m_szIcon.cy + pt.y));
			}
		}
		else
		{
			CXTPImageManagerIcon::DrawAlphaBitmap(pDC, m_hBitmap, pt, szIcon, CPoint(0, 0), m_szIcon);
		}
	}
}

BOOL CXTPImageManagerIconHandle::CreateIconFromResource(LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource)
{
	if (bGroupResource)
	{
		HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName, RT_GROUP_ICON);
		if (hInst)
			return CreateIconFromResource(hInst, lpszResourceName, szIcon, TRUE);
	}

	HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName, RT_ICON);
	if (hInst)
		return CreateIconFromResource(hInst, lpszResourceName, szIcon, FALSE);

	return FALSE;

}

BOOL CXTPImageManagerIconHandle::CreateIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource)
{
	HRSRC hRsrc = ::FindResource(hInst, lpszResourceName, RT_GROUP_ICON);

	if (hRsrc != NULL && bGroupResource)
	{
		// Load and Lock to get a pointer to a GRPICONDIR
		HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
		if (!hGlobal)
			return FALSE;

		CXTPImageManagerIcon::GRPICONDIR* lpGrpIconDir = (CXTPImageManagerIcon::GRPICONDIR*)LockResource(hGlobal);
		if (!lpGrpIconDir)
			return FALSE;

		for (int i = (int)lpGrpIconDir->idCount - 1; i >= 0; i--)
		{
			if (lpGrpIconDir->idEntries[i].bWidth == szIcon.cx && lpGrpIconDir->idEntries[i].bHeight == szIcon.cy)
			{
				if (CreateIconFromResource(hInst, MAKEINTRESOURCE(lpGrpIconDir->idEntries[i].nID), szIcon, FALSE))
					return TRUE;
			}
		}

		return FALSE;
	}

	hRsrc = ::FindResource(hInst, lpszResourceName, RT_ICON);

	if (hRsrc == NULL)
		return FALSE;

	HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
	if (!hGlobal)
		return FALSE;
	CXTPImageManagerIcon::ICONIMAGE* lpIconImage = (CXTPImageManagerIcon::ICONIMAGE*)LockResource(hGlobal);

	if (lpIconImage == NULL)
		return FALSE;

	DWORD dwResourceSize = SizeofResource(hInst, hRsrc);

	if (lpIconImage->icHeader.biBitCount == 32)
	{
		CDC dcSrc;
		dcSrc.CreateCompatibleDC(0);

		BITMAPINFOHEADER* pBitmapInfo = (BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER) + sizeof(COLORREF) * 3);
		if (!pBitmapInfo)
			return FALSE;

		*pBitmapInfo = lpIconImage->icHeader;

		pBitmapInfo->biHeight /= 2;
		pBitmapInfo->biSizeImage = pBitmapInfo->biHeight * pBitmapInfo->biWidth * 4;

		BYTE* pDest = NULL;
		HBITMAP hBitmap = CreateDIBSection(dcSrc, (BITMAPINFO*)pBitmapInfo, DIB_RGB_COLORS, (void**)&pDest, NULL, 0);

		if (pDest == NULL || hBitmap == NULL)
		{
			free(pBitmapInfo);
			return FALSE;
		}

		ASSERT(pBitmapInfo->biSizeImage <= dwResourceSize - sizeof(BITMAPINFOHEADER));

		MEMCPY_S(pDest, &lpIconImage->icColors, pBitmapInfo->biSizeImage);

		*this = hBitmap; // NOTE: it call DeleteObejct in destructor
		free(pBitmapInfo);
	}
	else
	{
		*this = CreateIconFromResourceEx((PBYTE)lpIconImage, dwResourceSize, TRUE,
			0x00030000, szIcon.cx, szIcon.cy, LR_DEFAULTCOLOR);
	}

	return !IsEmpty();
}


LPBYTE CXTPImageManagerIconHandle::PreMultiply()
{
	if (m_pBits != NULL)
		return m_pBits;

	if (m_hBitmap == 0)
		return NULL;

	LPBYTE pBits = NULL;

	HBITMAP hBitmapAlpha =  CXTPImageManagerIcon::PreMultiplyAlphaBitmap(m_hBitmap, NULL, &pBits);
	if (!hBitmapAlpha || (pBits == NULL))
		return NULL;

	Clear();

	m_hBitmap = hBitmapAlpha;
	m_pBits = pBits;
	m_bClearHandles = TRUE;
	m_szIcon = _GetExtent();

	return m_pBits;
}

BOOL CXTPImageManagerIcon::IsAlpha() const
{
	return m_hIcon.IsAlpha();
}

HBITMAP CXTPImageManagerIcon::InvertAlphaBitmap(HBITMAP hBitmap)
{

	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	DWORD* pBits = 0;
	PBITMAPINFO pBitmapInfo = 0;

	HBITMAP hBitmapAlpha = 0;

	TRY
	{
		UINT nSize;
		if (!GetBitmapBits(dcSrc, hBitmap, pBitmapInfo, (LPVOID&)pBits, nSize))
			return 0;

		DWORD* pDest = NULL;

		hBitmapAlpha = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pDest, NULL, 0);
		if (pDest == NULL || hBitmapAlpha == NULL)
			AfxThrowMemoryException();

		int cy = pBitmapInfo->bmiHeader.biHeight;
		int cx = pBitmapInfo->bmiHeader.biWidth;

		for (int y = 0; y < cy; y++)
		{
			DWORD* pBitsRow = &pBits[y * cx + cx - 1];

			for (int x = 0; x < cx; x++)
			{
				*pDest++ = *pBitsRow--;
			}
		}
	}
	CATCH (CMemoryException, e)
	{
		TRACE(_T("Failed -- Memory exception thrown."));
	}
	END_CATCH

	FREE(pBits);
	FREE(pBitmapInfo);

	return hBitmapAlpha;
}

HBITMAP CXTPImageManagerIcon::PreMultiplyAlphaBitmap(HBITMAP hBitmap, BOOL* pbAlpha, LPBYTE* lpBits)
{
	if (lpBits) *lpBits = NULL;

	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	PBYTE pBitsSrc = 0;
	PBITMAPINFO pBitmapInfo = 0;

	HBITMAP hBitmapAlpha = 0;

	TRY
	{
		UINT nSize;
		if (!GetBitmapBits(dcSrc, hBitmap, pBitmapInfo, (LPVOID&)pBitsSrc, nSize))
			return 0;

		BYTE* pBitsDest = NULL;

		hBitmapAlpha = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pBitsDest, NULL, 0);
		if (pBitsDest == NULL || hBitmapAlpha == NULL)
			AfxThrowMemoryException();

		MEMCPY_S(pBitsDest, pBitsSrc, nSize);

		BOOL bAlpha0Found = FALSE;

		BYTE* pBitsI = pBitsDest;
		UINT nCount = nSize / 4;

		for (UINT i = 0; i < nCount; i++)
		{
			int nAlpha = pBitsI[3];
			pBitsI[0] = BYTE(pBitsI[0] * nAlpha / 255);
			pBitsI[1] = BYTE(pBitsI[1] * nAlpha / 255);
			pBitsI[2] = BYTE(pBitsI[2] * nAlpha / 255);

			if (pbAlpha)
			{
				if (nAlpha == 0)
					bAlpha0Found = TRUE;

				if ((nAlpha != 255 && nAlpha != 0) || (nAlpha == 255 && bAlpha0Found) || (nAlpha == 255 && *pbAlpha == -1))
					*pbAlpha = TRUE;
			}
			pBitsI += 4;
		}

		if (pbAlpha && (*pbAlpha == FALSE))
		{
			MEMCPY_S(pBitsDest, pBitsSrc, nSize);
		}

		if (lpBits)
		{
			*lpBits = pBitsDest;
		}

	}
	CATCH (CMemoryException, e)
	{
		TRACE(_T("Failed -- Memory exception thrown."));
	}
	END_CATCH

	FREE(pBitsSrc);
	FREE(pBitmapInfo);

	return hBitmapAlpha;
}

BOOL CXTPImageManagerIcon::GetBitmapBits(CDC& dcSrc, HBITMAP hBitmap, PBITMAPINFO& pBitmapInfo, LPVOID& pBits, UINT& nSize)
{
	if (hBitmap == 0)
		return FALSE;

	BITMAPINFO  bmi;
	memset(&bmi, 0, sizeof(bmi));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);


	if (GetDIBits(dcSrc, hBitmap, 0, 0, NULL, (BITMAPINFO*)&bmi, DIB_RGB_COLORS) == 0)
		return FALSE;

	if (bmi.bmiHeader.biBitCount != 32)
		return FALSE;

	nSize = bmi.bmiHeader.biHeight * bmi.bmiHeader.biWidth * 4;
	pBits = (PBYTE)malloc(nSize);
	if (pBits == NULL)
		return FALSE;

	if ((pBitmapInfo = (PBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + 3 * sizeof(COLORREF))) == NULL)
	{
		FREE(pBits);
		return FALSE;
	}

	MEMCPY_S(pBitmapInfo, &bmi, sizeof(BITMAPINFOHEADER));

	if (GetDIBits(dcSrc, hBitmap, 0, bmi.bmiHeader.biHeight, pBits, pBitmapInfo, DIB_RGB_COLORS) == NULL)
	{
		FREE(pBits);
		FREE(pBitmapInfo);
		return FALSE;
	}
	return TRUE;
}

HBITMAP CXTPImageManagerIcon::CopyAlphaBitmap(HBITMAP hBitmap, LPBYTE* lpBits)
{
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	PBYTE pBitsSrc = 0;
	PBITMAPINFO pBitmapInfo = 0;
	UINT nSize;

	if (!GetBitmapBits(dcSrc, hBitmap, pBitmapInfo, (LPVOID&)pBitsSrc, nSize))
		return 0;

	BYTE* pBitsDest = NULL;
	HBITMAP hBmp = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pBitsDest, NULL, 0);

	if (pBitsDest != NULL && hBmp != NULL)
	{
		MEMCPY_S(pBitsDest, pBitsSrc, nSize);
	}

	FREE(pBitsSrc);
	FREE(pBitmapInfo);

	if (lpBits)
	{
		*lpBits = pBitsDest;
	}

	return hBmp;

}




//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerIcon
CXTPImageManagerIcon::CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerIconSet* pIconSet)
	: m_nID(nID)
	, m_nWidth(nWidth)
	, m_nHeight(nHeight)
	, m_pIconSet(pIconSet)
	, m_pImageList(NULL)
{
	m_bDrawComposited = FALSE;

	if (m_pIconSet)
	{
		m_hIcon.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hFaded.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hShadow.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hHot.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hChecked.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hPressed.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hDisabled.m_pImageManager = m_pIconSet->m_pImageManager;
		m_hDisabledAuto.m_pImageManager = m_pIconSet->m_pImageManager;
	}

}

CXTPImageManagerIcon::CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerImageList* pImageList)
	: m_nID(nID)
	, m_nWidth(nWidth)
	, m_nHeight(nHeight)
	, m_pIconSet(NULL)
	, m_pImageList(pImageList)
{
}


CXTPImageManagerIcon::~CXTPImageManagerIcon()
{
	Clear(TRUE);
}

UINT CXTPImageManagerIcon::GetID() const
{
	return m_nID;
}

int CXTPImageManagerIcon::GetHeight() const
{
	return m_nHeight;
}

int CXTPImageManagerIcon::GetWidth() const
{
	return m_nWidth;
}

void CXTPImageManagerIcon::Clear(BOOL bIcon /* = FALSE */)
{
	if (bIcon)
	{
		m_hIcon.Clear();
	}
	m_hFaded.Clear();
	m_hShadow.Clear();
	m_hHot.Clear();
	m_hChecked.Clear();
	m_hPressed.Clear();
	m_hDisabled.Clear();
	m_hDisabledAuto.Clear();
}

void CXTPImageManagerIcon::Refresh()
{
	m_hFaded.Clear();
	m_hShadow.Clear();
	m_hDisabledAuto.Clear();
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetIcon()
{
	return m_hIcon;
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetIcon(XTPImageState imageState)
{
	return imageState == xtpImageDisabled ? GetDisabledIcon() : imageState == xtpImageHot? GetHotIcon() :
		imageState == xtpImageChecked? GetCheckedIcon() : imageState == xtpImagePressed? GetPressedIcon() : GetIcon();
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetFadedIcon()
{
	if (m_hFaded.IsEmpty())
	{
		CreateFadedIcon();
	}
	return m_hFaded.IsEmpty() ? m_hIcon : m_hFaded;
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetShadowIcon()
{
	if (m_hShadow.IsEmpty())
	{
		CreateShadowIcon();
	}
	return m_hShadow;
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetHotIcon()
{
	return !m_hHot.IsEmpty() ? m_hHot : m_hIcon;
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetCheckedIcon()
{
	return !m_hChecked.IsEmpty() ? m_hChecked : GetHotIcon();
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetPressedIcon()
{
	return !m_hPressed.IsEmpty() ? m_hPressed : GetHotIcon();
}

BOOL CXTPImageManagerIcon::HasDisabledIcon() const
{
	if (!m_hDisabled.IsEmpty())
		return TRUE;

	if (!m_hDisabledAuto.IsEmpty())
		return TRUE;

	return FALSE;
}

CXTPImageManagerIconHandle& CXTPImageManagerIcon::GetDisabledIcon(BOOL bCreateIfNotExists /*= TRUE*/)
{
	if (!m_hDisabled.IsEmpty())
		return m_hDisabled;

	if (!m_hDisabledAuto.IsEmpty())
		return m_hDisabledAuto;

	if (bCreateIfNotExists)
	{
		CreateDisabledIcon();
	}

	return m_hDisabledAuto;
}

BOOL CXTPImageManagerIcon::SetIcon(const CXTPImageManagerIconHandle& iconHandle, XTPImageState imageState)
{
	switch (imageState)
	{
		case xtpImageNormal:
			SetNormalIcon(iconHandle);
			break;
		case xtpImageHot:
			SetHotIcon(iconHandle);
			break;
		case xtpImageChecked:
			SetCheckedIcon(iconHandle);
			break;
		case xtpImageDisabled:
			SetDisabledIcon(iconHandle);
			break;
		case xtpImagePressed:
			SetPressedIcon(iconHandle);
			break;
		default:
			return FALSE;
	}

	return TRUE;
}


BOOL CXTPImageManagerIcon::SetIcon(const CXTPImageManagerIconHandle& hIcon)
{
	ASSERT(!hIcon.IsEmpty());
	Clear(TRUE);
	m_hIcon.CopyHandle(hIcon);
	CSize sz = GetExtent();

	m_nHeight = sz.cy;
	m_nWidth = sz.cx;

	if (m_pIconSet)
		m_pIconSet->RefreshAll();

	return TRUE;
}

BOOL CXTPImageManagerIcon::SetIcon(UINT nIDResourceIcon, int nWidth, int nHeight)
{
	Clear(TRUE);

	ASSERT(nWidth != 0 && nHeight != 0);

	if (!m_hIcon.CreateIconFromResource(MAKEINTRESOURCE(nIDResourceIcon), CSize(nWidth, nHeight)))
		return FALSE;

	m_nHeight = nHeight;
	m_nWidth = nWidth;

	return TRUE;
}

void CXTPImageManagerIcon::SetNormalIcon(const CXTPImageManagerIconHandle& hIcon)
{
	ASSERT(!hIcon.IsEmpty());

	Refresh();
	m_hIcon.CopyHandle(hIcon);


#ifdef _DEBUG
	CSize sz = GetExtent();

	ASSERT((int)m_nHeight == sz.cy);
	ASSERT((int)m_nWidth == sz.cx);

#endif
}

void CXTPImageManagerIcon::SetHotIcon(const CXTPImageManagerIconHandle& hIcon)
{
	Refresh();
	m_hHot.CopyHandle(hIcon);
}

void CXTPImageManagerIcon::SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon)
{
	Refresh();
	m_hChecked.CopyHandle(hIcon);
}

void CXTPImageManagerIcon::SetPressedIcon(const CXTPImageManagerIconHandle& hIcon)
{
	Refresh();
	m_hPressed.CopyHandle(hIcon);
}

void CXTPImageManagerIcon::SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon)
{
	Refresh();
	m_hDisabled.CopyHandle(hIcon);
}


COLORREF CXTPImageManagerIcon::LightenColor(COLORREF clr, double factor)
{
	return RGB(
		factor * 255 + (1.0 - factor) * GetRValue(clr),
		factor * 255 + (1.0 - factor) * GetGValue(clr),
		factor * 255 + (1.0 - factor) * GetBValue(clr)) ;
}

void CXTPImageManagerIcon::CreateFadedIcon()
{
	ASSERT(m_hFaded.IsEmpty());

	if (!m_hIcon.m_bUseResources)
		return;

	CXTPImageManagerIconHandle hFaded;
	hFaded.CopyHandle(m_hIcon);

	if (!hFaded.IsAlpha())
	{
		ICONINFO info;
		if (GetIconInfo(hFaded.GetIcon(), &info))
		{
			if (!CXTPDrawHelpers::IsLowResolution())
			{
				CXTPCompatibleDC dc(NULL, CBitmap::FromHandle(info.hbmColor));
				CXTPCompatibleDC dcMask(NULL, CBitmap::FromHandle(info.hbmMask));

				BITMAP bmp;
				::GetObject(info.hbmColor, sizeof(BITMAP), &bmp);

				for (int i = 0; i < bmp.bmWidth; i++)
				for (int j = 0; j < bmp.bmHeight; j++)
				{
					COLORREF clr = dc.GetPixel(i, j);
					COLORREF clrMask = dcMask.GetPixel(i, j);
					if (clrMask == 0)
						dc.SetPixel(i, j, LightenColor(clr, .3));
				}
			}

			hFaded = CreateIconIndirect(&info);

			::DeleteObject(info.hbmColor);
			::DeleteObject(info.hbmMask);
		}
	}
	else if (hFaded.PreMultiply())
	{
		PBYTE pBits = hFaded.PreMultiply();
		CSize szIcon = hFaded.GetExtent();

		UINT nCount = szIcon.cx * szIcon.cy;

		for (UINT i = 0; i < nCount; i++)
		{
			int nAlpha = pBits[3];
			if (nAlpha != 0)
			{
				pBits[0] = BYTE(.3 * nAlpha + (1.0 - .3) * pBits[0]);
				pBits[1] = BYTE(.3 * nAlpha + (1.0 - .3) * pBits[1]);
				pBits[2] = BYTE(.3 * nAlpha + (1.0 - .3) * pBits[2]);
			}
			pBits += 4;
		}
	}

	m_hFaded.CopyHandle(hFaded);
}

void CXTPImageManagerIcon::CreateShadowIcon()
{
	ASSERT(m_hShadow.IsEmpty());

	if (!m_hIcon.m_bUseResources)
		return;

	COLORREF clrBackground = GetXtremeColor(XPCOLOR_HIGHLIGHT);
	COLORREF clrShadow = RGB(GetRValue(clrBackground) * .75, GetGValue(clrBackground) * .75, GetBValue(clrBackground) * .75);

	CXTPImageManagerIconHandle hShadow;
	hShadow.CopyHandle(GetHotIcon());

	if (!hShadow.IsAlpha())
	{
		ICONINFO info;
		if (GetIconInfo(hShadow.GetIcon(), &info))
		{
			{
				CXTPCompatibleDC dc(NULL, CBitmap::FromHandle(info.hbmColor));
				CXTPCompatibleDC dcMask(NULL, CBitmap::FromHandle(info.hbmMask));

				BITMAP bmp;
				::GetObject(info.hbmColor, sizeof(BITMAP), &bmp);

				for (int i = 0; i < bmp.bmWidth; i++)
				for (int j = 0; j < bmp.bmHeight; j++)
				{
					COLORREF clrMask = dcMask.GetPixel(i, j);
					if (clrMask == 0)
						dc.SetPixel(i, j, clrShadow);
				}
			}

			hShadow = CreateIconIndirect(&info);

			::DeleteObject(info.hbmMask);
			::DeleteObject(info.hbmColor);
		}
	}
	else if (hShadow.PreMultiply())
	{
		PBYTE pBits = hShadow.PreMultiply();
		CSize szIcon = hShadow.GetExtent();

		UINT nCount = szIcon.cx * szIcon.cy;

		for (UINT i = 0; i < nCount; i++)
		{
			int nAlpha = pBits[3];
			pBits[0] = BYTE(GetRValue(clrShadow) * nAlpha / 255);
			pBits[1] = BYTE(GetGValue(clrShadow) * nAlpha / 255);
			pBits[2] = BYTE(GetBValue(clrShadow) * nAlpha / 255);
			pBits += 4;
		}
	}

	m_hShadow.CopyHandle(hShadow);
}

void CXTPImageManagerIcon::CreateDisabledIcon(COLORREF clrDisabledLight /*= (COLORREF)-1*/, COLORREF clrDisabledDark /*= (COLORREF)-1*/)
{
	if (!m_hDisabledAuto.IsEmpty())
		return;

	BOOL bOfficeDisabledIcons = clrDisabledLight != (COLORREF)-1 && clrDisabledDark != (COLORREF)-1;

	CXTPImageManagerIconHandle hDisabled;
	hDisabled.CopyHandle(m_hIcon);

	if (!hDisabled.IsAlpha())
	{
		ICONINFO info;
		if (GetIconInfo(hDisabled.GetIcon(), &info))
		{
			{
				CXTPCompatibleDC dc(NULL, CBitmap::FromHandle(info.hbmColor));
				CXTPCompatibleDC dcMask(NULL, CBitmap::FromHandle(info.hbmMask));

				BITMAP bmp;
				::GetObject(info.hbmColor, sizeof(BITMAP), &bmp);

				for (int i = 0; i < bmp.bmWidth; i++)
				for (int j = 0; j < bmp.bmHeight; j++)
				{
					COLORREF clrMask = dcMask.GetPixel(i, j);
					COLORREF clr = dc.GetPixel(i, j);

					if (clrMask == 0)
					{
						if (bOfficeDisabledIcons)
						{
							double dGray = (GetRValue(clr) * 0.299 + GetGValue(clr) * 0.587 + GetBValue(clr) * 0.114)/255;
							double dLight = 1.0 - dGray;

							clr = RGB(dLight * GetRValue(clrDisabledDark) + dGray * GetRValue(clrDisabledLight),
								dLight * GetGValue(clrDisabledDark) + dGray * GetGValue(clrDisabledLight),
								dLight * GetBValue(clrDisabledDark) + dGray * GetBValue(clrDisabledLight));

							dc.SetPixel(i, j, clr);
						}
						else
						{
							double dGray = GetRValue(clr) * 0.299 + GetGValue(clr) * 0.587 + GetBValue(clr) * 0.114;
							int nGray = (BYTE)(pow(dGray / 255.0, CXTPImageManager::m_dDisabledBrightnessFactor) * 255.0);

							dc.SetPixel(i, j, RGB(nGray, nGray, nGray));
						}
					}
				}
			}

			hDisabled = CreateIconIndirect(&info);
			::DeleteObject(info.hbmMask);
			::DeleteObject(info.hbmColor);

		}
	}
	else if (hDisabled.PreMultiply())
	{
		PBYTE pBits = hDisabled.PreMultiply();
		CSize szIcon = hDisabled.GetExtent();

		UINT nCount = szIcon.cx * szIcon.cy;

		for (UINT i = 0; i < nCount; i++)
		{
			int nAlpha = pBits[3];
			if (nAlpha != 0)
			{
				int R = pBits[0] * 255 / nAlpha;
				int G = pBits[1] * 255 / nAlpha;
				int B = pBits[2] * 255 / nAlpha;

				if (bOfficeDisabledIcons)
				{
					double dGray = (R * 0.114 + G * 0.587 + B * 0.299)/255.0;
					double dLight = 1.0 - dGray;

					R = BYTE(dLight * GetBValue(clrDisabledDark) + dGray * GetBValue(clrDisabledLight));
					G = BYTE(dLight * GetGValue(clrDisabledDark) + dGray * GetGValue(clrDisabledLight));
					B = BYTE(dLight * GetRValue(clrDisabledDark) + dGray * GetRValue(clrDisabledLight));
				}
				else
				{
					double dGray = R * 0.114 + G * 0.587 + B * 0.299;
					R = G = B = (BYTE)(pow(dGray / 255.0, CXTPImageManager::m_dDisabledBrightnessFactor) * 255.0);
					nAlpha = BYTE(nAlpha / CXTPImageManager::m_dDisabledAlphaFactor);
				}

				pBits[0] = BYTE(R * nAlpha / 255);
				pBits[1] = BYTE(G * nAlpha / 255);
				pBits[2] = BYTE(B * nAlpha / 255);
			}

			pBits += 4;
		}
	}

	m_hDisabledAuto.CopyHandle(hDisabled);
}

CSize CXTPImageManagerIcon::GetExtent() const
{
	return m_hIcon.GetExtent();
}

CSize CXTPImageManagerIcon::GetExtent(HICON hIcon)
{
	ASSERT(hIcon);

	CSize extent(0);
	if (hIcon)
	{
		ICONINFO iconinfo;
		if (::GetIconInfo(hIcon, &iconinfo))
		{
			BITMAP bmpinfo;
			if (::GetObject(iconinfo.hbmMask, sizeof(bmpinfo), &bmpinfo))
			{
				extent.cx = (int)bmpinfo.bmWidth;
				extent.cy = (int)bmpinfo.bmHeight;
				if (!iconinfo.hbmColor)
				{
					// b/w icons have double size for XOR and AND masks
					extent.cy /= 2;
				}
			}
			// cleanup GDI
			if (iconinfo.hbmMask) ::DeleteObject(iconinfo.hbmMask);
			if (iconinfo.hbmColor) ::DeleteObject(iconinfo.hbmColor);
		}
	}
	return extent;
}


HICON CXTPImageManagerIcon::ScaleToFit(HICON hIcon, CSize szExtent, int nWidth)
{
	if (nWidth == 0 || szExtent == CSize(0))
	{
		// invalid arg
		return NULL;
	}
	if (nWidth == szExtent.cx)
		return ::CopyIcon(hIcon);

	CSize szDesiredExtent(nWidth, MulDiv(szExtent.cy, nWidth, szExtent.cx));

	// scale the icon
	CImageList images;
	VERIFY(images.Create(szDesiredExtent.cx, szDesiredExtent.cy, ILC_COLOR32 | ILC_MASK, 1, 1));
	images.Add(hIcon);
	return images.ExtractIcon(0);
}

BOOL CXTPImageManagerIcon::GetDIBBitmap(HBITMAP hBitmap, PBYTE& pBits, UINT& nBitsSize, PBITMAPINFO& pBitmapInfo, UINT& nBitmapInfoSize)
{
	pBits = 0;
	pBitmapInfo = 0;

	BITMAPINFO  bmi;
	memset(&bmi, 0, sizeof(bmi));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	TRY
	{
		if (GetDIBits(dcSrc, hBitmap, 0, 0, NULL, (BITMAPINFO*)&bmi, DIB_RGB_COLORS) == 0)
			AfxThrowMemoryException();

		nBitsSize = bmi.bmiHeader.biSizeImage != 0? bmi.bmiHeader.biSizeImage :
			bmi.bmiHeader.biHeight * bmi.bmiHeader.biWidth * 4;

		pBits = (PBYTE)malloc(nBitsSize);
		if (pBits == NULL)
			AfxThrowMemoryException();

		int nColorTableSize = bmi.bmiHeader.biBitCount == 4 ? 16 : bmi.bmiHeader.biBitCount == 8 ? 256 : 3;

		nBitmapInfoSize = sizeof(BITMAPINFOHEADER) + nColorTableSize * sizeof(COLORREF);
		if ((pBitmapInfo = (PBITMAPINFO)malloc(nBitmapInfoSize)) == NULL)
			AfxThrowMemoryException();

		MEMCPY_S(pBitmapInfo, &bmi, sizeof(BITMAPINFOHEADER));

		if (GetDIBits(dcSrc, hBitmap, 0, bmi.bmiHeader.biHeight, pBits, pBitmapInfo, DIB_RGB_COLORS) == NULL)
			AfxThrowMemoryException();
	}
	CATCH (CMemoryException, e)
	{
		TRACE(_T("Failed -- Memory exception thrown."));
		return FALSE;
	}
	END_CATCH

	return TRUE;
}

HBITMAP CXTPImageManagerIcon::ReadDIBBitmap(CArchive& ar, LPBYTE* lpBits)
{
	PBITMAPINFO pBitmapInfo = 0;
	PBYTE pBitsSrc = 0;

	DWORD dwCount = (DWORD) ar.ReadCount();
	DWORD dwBitsCount = 0;

	if (dwCount > 0)
	{
		pBitmapInfo = (PBITMAPINFO)malloc(dwCount);
		ar.Read(pBitmapInfo, dwCount);

		dwBitsCount = (DWORD) ar.ReadCount();
		pBitsSrc = (PBYTE)malloc(dwBitsCount);
		ar.Read(pBitsSrc, dwBitsCount);
	}
	else
	{
		return NULL;
	}

	if (!pBitmapInfo || dwBitsCount == 0)
	{
		FREE(pBitsSrc);
		FREE(pBitmapInfo);
		return NULL;
	}

	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	if (pBitmapInfo->bmiHeader.biSizeImage == 0)
	{
		pBitmapInfo->bmiHeader.biSizeImage = dwBitsCount;
	}

	BYTE* pBitsDest = NULL;
	HBITMAP hBmp = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pBitsDest, NULL, 0);

	if (!pBitsDest || !hBmp)
	{
		FREE(pBitsSrc);
		FREE(pBitmapInfo);
		return NULL;
	}

	MEMCPY_S(pBitsDest, pBitsSrc, min(dwBitsCount, pBitmapInfo->bmiHeader.biSizeImage));

	FREE(pBitsSrc);
	FREE(pBitmapInfo);

	if (lpBits)
	{
		*lpBits = pBitsDest;
	}

	return hBmp;
}

void CXTPImageManagerIcon::WriteDIBBitmap(CArchive& ar, HBITMAP hBitmap)
{
	PBYTE pBits = 0;
	PBITMAPINFO pBitmapInfo = 0;
	UINT nBitsSize;
	UINT nBitmapInfoSize;

	if (GetDIBBitmap(hBitmap, pBits, nBitsSize, pBitmapInfo, nBitmapInfoSize))
	{
		ar.WriteCount(nBitmapInfoSize);
		ar.Write(pBitmapInfo, nBitmapInfoSize);
		ar.WriteCount(nBitsSize);
		ar.Write(pBits, nBitsSize);
	}
	else
	{
		ar.WriteCount(0);
	}
	FREE(pBits);
	FREE(pBitmapInfo);
}

void CXTPImageManagerIcon::SerializeIcon(CXTPImageManagerIconHandle& hIcon, CArchive& ar, long nSchema)
{
	if (ar.IsStoring())
	{
		CXTPImageManagerIconHandle hHandle;
		hHandle.CopyHandle(hIcon);
		hHandle.PreMultiply();

		ICONINFO info;

		if (!hHandle.IsEmpty())
		{
			if (hHandle.IsAlpha())
			{
				WriteDIBBitmap(ar, hHandle.GetBitmap());
				ar.WriteCount(0);
			}
			else if (GetIconInfo(hHandle.GetIcon(), &info))
			{
				WriteDIBBitmap(ar, info.hbmColor);
				WriteDIBBitmap(ar, info.hbmMask);

				::DeleteObject(info.hbmColor);
				::DeleteObject(info.hbmMask);

			}
			else
			{
				ar.WriteCount(0);
				ar.WriteCount(0);
			}
		}
		else
		{
			ar.WriteCount(0);
			ar.WriteCount(0);
		}
	}
	else
	{
		CXTPImageManagerIconHandle hHandle;

		LPBYTE lpBits = NULL;
		HBITMAP hbmColor = ReadDIBBitmap(ar, &lpBits);
		HBITMAP hbmMask = ReadDIBBitmap(ar, NULL);

		if (hbmColor)
		{
			if (hbmMask == 0)
			{
				hHandle = hbmColor;

				if (nSchema > _XTP_SCHEMA_112)
				{
					hHandle.m_pBits = lpBits;
				}
				hbmColor = 0;
			}
			else
			{
				BITMAP bmp;
				::GetObject(hbmColor, sizeof(BITMAP), &bmp);

				CImageList il;
				il.Create(bmp.bmWidth, bmp.bmHeight, ILC_COLOR24 | ILC_MASK, 0, 1);
				il.Add(CBitmap::FromHandle(hbmColor), hbmMask == 0 ? (CBitmap*)NULL : CBitmap::FromHandle(hbmMask));
				hHandle = il.ExtractIcon(0);
			}

			if (hbmColor) ::DeleteObject(hbmColor);
			if (hbmMask) ::DeleteObject(hbmMask);
		}

		hIcon.CopyHandle(hHandle);
	}

}

void CXTPImageManagerIcon::Serialize(CArchive& ar)
{
	long nSchema = _XTP_SCHEMA_CURRENT;

	if (ar.IsStoring())
	{
		ar << m_nHeight;
		ar << nSchema;

	}
	else
	{
		ar >> m_nHeight;
		ar >> nSchema;
	}
	SerializeIcon(m_hIcon, ar, nSchema);
	SerializeIcon(m_hDisabled, ar, nSchema);
	SerializeIcon(m_hHot, ar, nSchema);

	if (nSchema > _XTP_SCHEMA_875)
	{
		SerializeIcon(m_hChecked, ar, nSchema);
	}
	if (nSchema > _XTP_SCHEMA_98)
	{
		SerializeIcon(m_hPressed, ar, nSchema);
	}
}

void CXTPImageManagerIcon::Copy(CXTPImageManagerIcon* pIcon)
{
	ASSERT(m_nID == pIcon->GetID());
	m_nWidth = pIcon->m_nWidth;
	m_nHeight = pIcon->m_nHeight;

	m_hIcon.CopyHandle(pIcon->m_hIcon);
	m_hDisabled.CopyHandle(pIcon->m_hDisabled);
	m_hHot.CopyHandle(pIcon->m_hHot);
	m_hChecked.CopyHandle(pIcon->m_hChecked);
	m_hPressed.CopyHandle(pIcon->m_hPressed);

	m_hFaded.Clear();
	m_hShadow.Clear();
	m_hDisabledAuto.Clear();
}

void CXTPImageManagerIcon::DrawAlphaBitmap(CDC* pDC, HBITMAP hBitmap, CPoint ptDest, CSize szDest, CPoint ptSrc, CSize szSrc)
{
	if (szSrc == CSize(0))
		szSrc = szDest;

	CXTPCompatibleDC dc(NULL, CBitmap::FromHandle(hBitmap));

	XTPImageManager()->AlphaBlend(pDC->GetSafeHdc(), CRect(ptDest, szDest),
		dc, CRect(ptSrc, szSrc));

}
CXTPImageManager* CXTPImageManagerIcon::GetImageManager() const
{
	if (m_pIconSet)
	{
		ASSERT(m_pIconSet->m_pImageManager);
		return m_pIconSet->m_pImageManager;
	}

	return XTPImageManager();
}

void CXTPImageManagerIcon::DrawMono(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon, COLORREF clrBrush)
{
	if (hIcon.IsAlpha())
		return;

	if (szIcon.cx == 0)
		szIcon.cx = m_nWidth;

	if (szIcon.cy == 0)
		szIcon.cy = m_nHeight * szIcon.cx / m_nWidth;

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, szIcon.cx, szIcon.cy);
	{
		CXTPCompatibleDC dc(pDC, &bmp);
		dc.FillSolidRect(0, 0, szIcon.cx, szIcon.cy, 0xFFFFFF);

		Draw(&dc, CPoint(0, 0), hIcon, szIcon);
	}
	pDC->DrawState(pt, szIcon, bmp, (UINT)DSS_MONO, CBrush(clrBrush));
}

void CXTPImageManagerIcon::Draw(CDC* pDC, CPoint pt, CSize szIcon)
{
	Draw(pDC, pt, GetIcon(), szIcon);
}

void CXTPImageManagerIcon::Draw(CDC* pDC, CPoint pt)
{
	Draw(pDC, pt, GetIcon());
}

void CXTPImageManagerIcon::DrawIconComposited(CDC* pDC, CPoint pt, CSize szIcon, HICON hIcon)
{
	CRect rcDest;
	if (szIcon.cx < 0)
	{
		rcDest.SetRect(pt.x + szIcon.cx, pt.y, pt.x, pt.y + szIcon.cy);
	}
	else
	{
		rcDest.SetRect(pt.x, pt.y, pt.x + szIcon.cx, pt.y + szIcon.cy);
	}

	CSize sz(rcDest.Width(), rcDest.Height());
	CBitmap bmp;
	LPDWORD lpBits;
	bmp.Attach(CXTPImageManager::Create32BPPDIBSection(pDC->GetSafeHdc(), sz.cx, sz.cy, (LPBYTE*)&lpBits));

	CXTPCompatibleDC dc(pDC, &bmp);

	CRect rcDestOrig(0, 0, sz.cx, sz.cy);

	dc.FillSolidRect(rcDestOrig, 0xFF00FF);
	DrawIconEx(dc, szIcon.cx > 0 ? 0 : -szIcon.cx, 0, hIcon, szIcon.cx, szIcon.cy, 0, 0, DI_NORMAL);

	for (int i = 0; i < sz.cx * sz.cy; i++)
	{
		if (lpBits[0] == 0xFF00FF)
		{
			lpBits[0] = 0;
		}
		else
		{
			lpBits[0] |= 0xFF000000;
		}
		lpBits++;
	}

	XTPImageManager()->AlphaBlend(*pDC, rcDest, dc, rcDestOrig);
}

void CXTPImageManagerIcon::Draw(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon /*= 0*/, COLORREF clrBK, COLORREF clrFG, UINT uiFlags)
{
	if (szIcon.cx == 0)
		szIcon.cx = m_nWidth;

	if (szIcon.cy == 0)
		szIcon.cy = m_nHeight * szIcon.cx / m_nWidth;

	if (m_pImageList)
	{
		m_pImageList->Draw(pDC, pt, this, szIcon,clrBK, clrFG, uiFlags);
		return;
	}

	hIcon.Draw(pDC, pt, szIcon, m_bDrawComposited);
}



//////////////////////////////////////////////////////////////////////////
// CXTPImageManagerIconSet

CXTPImageManagerIconSet::CXTPImageManagerIconSet(UINT nID, CXTPImageManager* pImageManager)
	: m_nID(nID)
{
	ASSERT(pImageManager);
	m_pImageManager = pImageManager;


}

CXTPImageManagerIconSet::~CXTPImageManagerIconSet()
{
	RemoveAll();
}

void CXTPImageManagerIconSet::RemoveAll()
{
	UINT nWidth;
	CXTPImageManagerIcon* pIcon;

	POSITION pos = m_mapIcons.GetStartPosition();
	while (pos)
	{
		m_mapIcons.GetNextAssoc(pos, nWidth, pIcon);
		pIcon->Clear(TRUE);
		pIcon->InternalRelease();
	}
	m_mapIcons.RemoveAll();
}

CXTPImageManagerIcon* CXTPImageManagerIconSet::CreateIcon(UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = 0;
	if (m_mapIcons.Lookup(nWidth, pIcon))
	{
		ASSERT(pIcon->m_nID == m_nID);
		ASSERT(pIcon->m_nWidth == nWidth);
	}
	else
	{
		pIcon = new CXTPImageManagerIcon(m_nID, nWidth, 15, this);
		m_mapIcons.SetAt(nWidth, pIcon);
	}

	ASSERT(pIcon);

	return pIcon;
}

void CXTPImageManagerIconSet::SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = CreateIcon(nWidth);
	pIcon->SetIcon(hIcon);
}

void CXTPImageManagerIconSet::SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = CreateIcon(nWidth);
	pIcon->SetDisabledIcon(hIcon);
}

void CXTPImageManagerIconSet::SetHotIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = CreateIcon(nWidth);
	pIcon->SetHotIcon(hIcon);
}

void CXTPImageManagerIconSet::SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = CreateIcon(nWidth);
	pIcon->SetCheckedIcon(hIcon);
}

void CXTPImageManagerIconSet::SetPressedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth)
{
	CXTPImageManagerIcon* pIcon = CreateIcon(nWidth);
	pIcon->SetPressedIcon(hIcon);
}

CXTPImageManagerIcon* CXTPImageManagerIconSet::GetIcon(UINT nWidth, BOOL bScaled)
{
	ASSERT(m_mapIcons.GetCount() > 0);

	CXTPImageManagerIcon* pIcon = NULL;
	BOOL bSpecial = (nWidth == ICON_BIG) || (nWidth == ICON_SMALL);

	if (!bSpecial)
	{
		if (m_mapIcons.Lookup(nWidth, pIcon))
		{
			return pIcon;
		}
		if (!bScaled)
			return NULL;
	}

	UINT nDelta = 0;

	POSITION pos = m_mapIcons.GetStartPosition();
	while (pos)
	{
		UINT nWidthScale;
		CXTPImageManagerIcon* pIconScale;

		m_mapIcons.GetNextAssoc(pos, nWidthScale, pIconScale);

		if (bSpecial)
		{
			if (((nDelta == 0) || ((nWidth == ICON_SMALL && nWidthScale < nDelta)
				|| (nWidth == ICON_BIG && nWidthScale > nDelta))))
			{
				pIcon = pIconScale;
				nDelta = nWidthScale;
			}
		}
		else if (nDelta == 0 || (UINT)abs(int(nWidthScale - nWidth)) < nDelta)
		{
			pIcon = pIconScale;
			nDelta = (UINT)abs(int(nWidthScale - nWidth));
		}
	}

	ASSERT(pIcon != 0);
	if (!pIcon)
		return NULL;

	return pIcon;
}


void CXTPImageManagerIconSet::RefreshAll()
{
	POSITION pos = m_mapIcons.GetStartPosition();
	UINT nWidth;
	CXTPImageManagerIcon* pIcon;

	while (pos)
	{
		m_mapIcons.GetNextAssoc(pos, nWidth, pIcon);

		pIcon->Refresh();
	}
}



//////////////////////////////////////////////////////////////////////////
// CXTPImageManager

CXTPImageManager::CXTPImageManager()
{
	m_clrMask = (COLORREF)-1;

	m_nCustomID = 0x10AAA;

	m_mapImages.InitHashTable(XTP_IMAGEMAN_HASH_TABLE_SIZE, FALSE);

	m_bDrawReverted = 2;

	m_bUseResources = TRUE;


}

CXTPImageManager* AFX_CDECL XTPImageManager()
{
	static CXTPImageManager s_managerInstance;
	return &s_managerInstance;
}

CXTPImageManager::~CXTPImageManager()
{
	RemoveAll();
}

BOOL CXTPImageManager::LoadToolbar(UINT nIDResourceToolBar, UINT*& pItems, int& nCount, CSize& szIcon) const
{
	LPCTSTR lpszResourceName = MAKEINTRESOURCE(nIDResourceToolBar);

	struct CToolBarData
	{
		WORD wVersion;
		WORD wWidth;
		WORD wHeight;
		WORD wItemCount;

		WORD* items()
		{
			return (WORD*)(this + 1);
		}
	};

	ASSERT(lpszResourceName != NULL);
	if (!lpszResourceName)
		return FALSE;

	// determine location of the bitmap in resource fork
	HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName, RT_TOOLBAR);
	HRSRC hRsrc = ::FindResource(hInst, lpszResourceName, RT_TOOLBAR);
	if (hRsrc == NULL)
		return FALSE;

	HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
	if (hGlobal == NULL)
		return FALSE;

	CToolBarData* pData = (CToolBarData*)LockResource(hGlobal);
	if (pData == NULL)
		return FALSE;

	ASSERT(pData->wVersion == 1);

	pItems = new UINT[pData->wItemCount];

	nCount = 0;
	for (int i = 0; i < pData->wItemCount; i++)
		if (pData->items()[i]) pItems[nCount++] = pData->items()[i];

	szIcon = CSize(pData->wWidth, pData->wHeight);

	UnlockResource(hGlobal);
	FreeResource(hGlobal);
	return TRUE;
}

BOOL CXTPImageManager::SetIcons(UINT nIDResourceToolBar, CBitmap& bmpIcons, XTPImageState imageState)
{
	UINT* pItems = NULL;
	CSize szIcon(0);
	int nCount = 0;
	BOOL bResult = LoadToolbar(nIDResourceToolBar, pItems, nCount, szIcon);

	if (bResult && !SetIcons(bmpIcons, pItems, nCount, szIcon, imageState))
		bResult = FALSE;

	if (pItems)
	{
		delete[] pItems;
	}

	return bResult;
}
BOOL CXTPImageManager::SetIcons(UINT nIDResourceToolBar, UINT nIDResourceBitmap, XTPImageState imageState)
{
	UINT* pItems = NULL;
	CSize szIcon(0);
	int nCount = 0;
	BOOL bResult = LoadToolbar(nIDResourceToolBar, pItems, nCount, szIcon);

	if (bResult && !SetIcons(nIDResourceBitmap, pItems, nCount, CSize(0, 0), imageState))
		bResult = FALSE;

	if (pItems)
	{
		delete[] pItems;
	}

	return bResult;

}


BOOL CXTPImageManager::SetIcons(UINT nIDResourceToolBar, XTPImageState imageState)
{
	return SetIcons(nIDResourceToolBar, nIDResourceToolBar, imageState);
}

BOOL CXTPImageManager::SetIcons(UINT nIDResourceToolBar, CImageList& imlIcons, XTPImageState imageState)
{
	UINT* pItems = NULL;
	CSize szIcon(0);
	int nCount = 0;
	BOOL bResult = LoadToolbar(nIDResourceToolBar, pItems, nCount, szIcon);

	if (bResult && !SetIcons(imlIcons, pItems, nCount, szIcon, imageState))
		bResult = FALSE;

	if (pItems)
	{
		delete[] pItems;
	}

	return bResult;

}

BOOL CXTPImageManager::SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nIDCommand, CSize szIcon, XTPImageState imageState)
{
	if (hIcon.IsEmpty())
		return FALSE;

	if (szIcon == CSize(0))
	{
		szIcon = hIcon.GetExtent();
	}
	if (szIcon == CSize(0))
		return FALSE;

	CXTPImageManagerIconSet* pIconSet;
	if (m_mapImages.Lookup(nIDCommand, pIconSet))
	{
		if (imageState == xtpImageNormal) pIconSet->SetIcon(hIcon, szIcon.cx);
		if (imageState == xtpImageDisabled) pIconSet->SetDisabledIcon(hIcon, szIcon.cx);
		if (imageState == xtpImageHot) pIconSet->SetHotIcon(hIcon, szIcon.cx);
		if (imageState == xtpImageChecked) pIconSet->SetCheckedIcon(hIcon, szIcon.cx);
		if (imageState == xtpImagePressed) pIconSet->SetPressedIcon(hIcon, szIcon.cx);
	}
	else if (imageState == xtpImageNormal)
	{
		pIconSet = new CXTPImageManagerIconSet(nIDCommand, this);
		pIconSet->SetIcon(hIcon, szIcon.cx);
		m_mapImages.SetAt(nIDCommand, pIconSet);
	}
	else return FALSE;

	return TRUE;
}

BOOL CXTPImageManager::SetIcon(UINT nIDResourceIcon, UINT nIDCommand, CSize szIcon, XTPImageState imageState)
{
	return SetIcon(MAKEINTRESOURCE(nIDResourceIcon), nIDCommand, szIcon, imageState);
}

BOOL CXTPImageManager::SetIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, UINT nIDCommand, CSize szIcon, XTPImageState imageState)
{
	// determine location of the bitmap in resource fork
	HRSRC hRsrc = ::FindResource(hInst, lpszResourceName, RT_GROUP_ICON);
	if (hRsrc != NULL)
	{
		// Load and Lock to get a pointer to a GRPICONDIR
		HGLOBAL hGlobal = LoadResource(hInst, hRsrc);
		if (!hGlobal)
			return FALSE;

		CXTPImageManagerIcon::GRPICONDIR* lpGrpIconDir = (CXTPImageManagerIcon::GRPICONDIR*)
			LockResource(hGlobal);
		if (!lpGrpIconDir)
			return FALSE;

		for (WORD i = 0; i < lpGrpIconDir->idCount; i++)
		{
			CXTPImageManagerIconHandle hIcon;
			CSize szResourceIcon(lpGrpIconDir->idEntries[i].bWidth, lpGrpIconDir->idEntries[i].bHeight);

			if ((szIcon == szResourceIcon) || (szIcon == CSize(0, 0)))
			{
				if (!hIcon.CreateIconFromResource(hInst, MAKEINTRESOURCE(lpGrpIconDir->idEntries[i].nID),
					szResourceIcon, FALSE))
				{
					return FALSE;
				}

				if (!SetIcon(hIcon, nIDCommand, szResourceIcon, imageState))
				{
					return FALSE;
				}
			}
		}
	}
	else
	{
		CXTPImageManagerIconHandle hIcon;

		if (!hIcon.CreateIconFromResource(hInst, lpszResourceName, szIcon, FALSE))
		{
			return FALSE;
		}

		return SetIcon(hIcon, nIDCommand, szIcon, imageState);
	}
	return TRUE;
}


BOOL CXTPImageManager::SetIcon(LPCTSTR lpszResourceName, UINT nIDCommand, CSize szIcon, XTPImageState imageState)
{
	// determine location of the bitmap in resource fork
	HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName, RT_GROUP_ICON);
	HRSRC hRsrc = ::FindResource(hInst, lpszResourceName, RT_GROUP_ICON);

	if (hRsrc != NULL)
	{
		SetIconFromResource(hInst, lpszResourceName, nIDCommand, szIcon, imageState);
	}
	else
	{
		CXTPImageManagerIconHandle hIcon;

		if (!hIcon.CreateIconFromResource(lpszResourceName, szIcon, FALSE))
		{
			return FALSE;
		}

		return SetIcon(hIcon, nIDCommand, szIcon, imageState);
	}
	return TRUE;
}


BOOL CXTPImageManager::SetIcons(CImageList& imlIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState)
{
	if (!imlIcons.GetSafeHandle())
		return FALSE;

	if ((nCount == 0) && (pCommands == 0))
	{
		nCount = imlIcons.GetImageCount();
	}

	if (szIcon == CSize(0) && nCount > 0)
	{
		IMAGEINFO imageInfo;
		imlIcons.GetImageInfo(0, &imageInfo);
		szIcon = CRect(imageInfo.rcImage).Size();
	}

	BOOL bIncludeAll = imlIcons.GetImageCount() == nCount;
	int j = 0;

	for (int i = 0; i < nCount; i++)
	{
		if ((pCommands == NULL) || bIncludeAll || (pCommands[i] != 0 && pCommands[i] != IMAGE_PLACEHOLDER))
		{
			HICON hIcon = imlIcons.ExtractIcon(j);
			if (hIcon)
			{
				SetIcon(hIcon, pCommands ? pCommands[i]: i, szIcon, imageState);
				DestroyIcon(hIcon);
			}
			else
			{
				return FALSE;
			}
			j++;
		}
	}
	return TRUE;
}


BOOL CXTPImageManager::SplitBitmap(HBITMAP hbmSource, int nCount, HBITMAP* pDest) const
{
	ASSERT(pDest != NULL);
	ASSERT(sizeof(int) == 4);

	if (!pDest)
		return FALSE;

	BITMAPINFO  bmi;
	memset(&bmi, 0, sizeof(bmi));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	PINT pBits = 0;
	PBITMAPINFO pBitmapInfo = 0;

	BOOL bResult = TRUE;
	int i;

	TRY
	{
		if (GetDIBits(dcSrc, hbmSource, 0, 0, NULL, (BITMAPINFO*)&bmi, DIB_RGB_COLORS) == 0)
			AfxThrowMemoryException();

		UINT nSize = bmi.bmiHeader.biHeight * bmi.bmiHeader.biWidth * 4;
		pBits = (PINT)malloc(nSize);
		if (pBits == NULL)
			AfxThrowMemoryException();

		if ((pBitmapInfo = (PBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + 3 * sizeof(COLORREF))) == NULL)
			AfxThrowMemoryException();

		MEMCPY_S(pBitmapInfo, &bmi, sizeof(BITMAPINFOHEADER));

		if (GetDIBits(dcSrc, hbmSource, 0, bmi.bmiHeader.biHeight, pBits, pBitmapInfo, DIB_RGB_COLORS) == NULL)
			AfxThrowMemoryException();

		ASSERT(pBitmapInfo->bmiHeader.biWidth % nCount == 0);

		pBitmapInfo->bmiHeader.biWidth /= nCount;
		pBitmapInfo->bmiHeader.biSizeImage /= nCount;

		PINT* pDestBits = new PINT[nCount];
		for (i = 0; i < nCount; i++)
		{
			pDest[i] = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pDestBits[i], NULL, 0);
			if (!pDest[i])
			{
				for (int j = 0; j < i; j++)
					DeleteObject(pDest[j]);

				delete[] pDestBits;

				AfxThrowMemoryException();
			}
		}

		PINT pBitsIter = pBits;

		for (int y = 0; y < pBitmapInfo->bmiHeader.biHeight; y++)
		{
			for (i = 0; i < nCount; i++)
			{
				for (int x = 0; x < pBitmapInfo->bmiHeader.biWidth; x++)
				{
					*pDestBits[i]++ = *pBitsIter++;
				}
			}
		}
		delete[] pDestBits;

	}
	CATCH (CMemoryException, e)
	{
		TRACE(_T("Failed -- Memory exception thrown."));
		bResult = FALSE;
	}
	END_CATCH

	FREE(pBits);
	FREE(pBitmapInfo);

	return bResult;

}

COLORREF CXTPImageManager::GetBitmapMaskColor(CBitmap& bmpIcons, CPoint pt)
{
	CXTPCompatibleDC dc(NULL, &bmpIcons);
	return dc.GetPixel(pt);
}

COLORREF CXTPImageManager::GetBitmapMaskColor(UINT nIDBitmap, CPoint pt)
{
	CBitmap bmp;
	VERIFY(bmp.LoadBitmap(nIDBitmap));
	return GetBitmapMaskColor(bmp, pt);
}


HBITMAP CXTPImageManager::ResampleAlphaLayer(UINT nIDBitmap, COLORREF clrMask)
{
	HBITMAP hbmAlpha = CXTPImageManagerIcon::LoadAlphaBitmap(nIDBitmap);
	if (!hbmAlpha)
		return 0;

	CBitmap bmp;
	bmp.Attach(hbmAlpha);

	return CXTPImageManager::ResampleAlphaLayer(bmp, clrMask);
}

HBITMAP CXTPImageManager::ResampleAlphaLayer(HBITMAP bmpAlpha, COLORREF clrMask)
{
	CDC dcSrc;
	dcSrc.CreateCompatibleDC(NULL);

	PBYTE pBits = 0;
	PBITMAPINFO pBitmapInfo = 0;
	UINT nSize;

	if (!CXTPImageManagerIcon::GetBitmapBits(dcSrc, bmpAlpha, pBitmapInfo, (LPVOID&)pBits, nSize))
		return 0;

	PBYTE pTarget = NULL;
	PBYTE pSource = pBits;
	pBitmapInfo->bmiHeader.biBitCount = 24;
	pBitmapInfo->bmiHeader.biSizeImage = 0;
	pBitmapInfo->bmiHeader.biCompression = BI_RGB;

	HBITMAP hBitmapResult = CreateDIBSection(dcSrc, pBitmapInfo, DIB_RGB_COLORS, (void**)&pTarget, NULL, 0);

	if (pTarget && pSource && hBitmapResult)
	{
		BYTE byMaskRed = GetRValue(clrMask);
		BYTE byMaskGreen = GetGValue(clrMask);
		BYTE byMaskBlue = GetBValue(clrMask);

		for (int i = 0; i < pBitmapInfo->bmiHeader.biHeight; i ++)
		{
			for (int j = 0; j < pBitmapInfo->bmiHeader.biWidth; j ++)
			{
				int iAlpha = pSource[3];

				if (iAlpha < 120) // Transparent
				{
					pTarget[0] = byMaskRed;
					pTarget[1] = byMaskGreen;
					pTarget[2] = byMaskBlue;
				}
				else if (iAlpha == 255) // Opaque
				{
					pTarget[0] = pSource[0];
					pTarget[1] = pSource[1];
					pTarget[2] = pSource[2];
				}
				else
				{
					pTarget[0] = (BYTE)((pSource[0] * (255 - iAlpha) + pSource[0] * iAlpha) >> 8);
					pTarget[1] = (BYTE)((pSource[1] * (255 - iAlpha) + pSource[1] * iAlpha) >> 8);
					pTarget[2] = (BYTE)((pSource[2] * (255 - iAlpha) + pSource[2] * iAlpha) >> 8);
				}

				pTarget += 3;
				pSource += 4;
			}

			if (pBitmapInfo->bmiHeader.biWidth & 1)
				pTarget++;
		}
	}

	FREE(pBits);
	FREE(pBitmapInfo);

	return hBitmapResult;
}

BOOL CXTPImageManager::SetIcons(CBitmap& bmpIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState, BOOL bAlpha)
{
	if (szIcon == CSize(0) && nCount > 0)
	{
		BITMAP bmpInfo;
		bmpIcons.GetBitmap(&bmpInfo);
		szIcon = CSize(bmpInfo.bmWidth / nCount, bmpInfo.bmHeight);
	}

	if (nCount == 0 && szIcon.cx > 0)
	{
		BITMAP bmpInfo;
		bmpIcons.GetBitmap(&bmpInfo);
		nCount = bmpInfo.bmWidth / szIcon.cx;
	}

	if (szIcon.cx == 0)
		return FALSE;

	if (bAlpha && !IsAlphaIconsSupported() && m_bAutoResample)
	{
		HBITMAP hBitmap = ResampleAlphaLayer(bmpIcons, m_clrMask == COLORREF(-1) ? RGB(0, 0xFF, 0) : m_clrMask);
		if (!hBitmap)
			return FALSE;

		CBitmap bmpResample;
		bmpResample.Attach(hBitmap);
		return SetIcons(bmpResample, pCommands, nCount, szIcon, imageState, FALSE);
	}

	if (bAlpha)
	{
		BITMAP bmpInfo;
		bmpIcons.GetBitmap(&bmpInfo);
		if (bmpInfo.bmWidth % szIcon.cx != 0)
			return FALSE;

		int nIconCount = bmpInfo.bmWidth / szIcon.cx;

		HBITMAP* pDestBitmap = new HBITMAP[nIconCount];

		if (!SplitBitmap(bmpIcons, nIconCount, pDestBitmap))
		{
			delete[] pDestBitmap;
			return FALSE;
		}
		BOOL bIgnoreNulls = (nIconCount == nCount);

		int j = 0;

		for (int i = 0; i < nCount; i++)
		{
			if ((!pCommands || bIgnoreNulls || (pCommands[i] != 0 && pCommands[i] != IMAGE_PLACEHOLDER)) && j < nIconCount)
			{

				SetIcon(pDestBitmap[j], pCommands ? pCommands[i]: i, szIcon, imageState);
				j++;
			}
		}

		for (j = 0; j < nIconCount; j++)
		{
			DeleteObject(pDestBitmap[j]);
		}

		delete[] pDestBitmap;


		return TRUE;

	}
	else
	{
		CImageList imgList;


		if (!imgList.Create(szIcon.cx, szIcon.cy, ILC_COLOR24 | ILC_MASK, 0, 1))
			return FALSE;

		COLORREF clrMask = m_clrMask != (COLORREF)-1 ? m_clrMask : GetBitmapMaskColor(bmpIcons);
		imgList.Add(&bmpIcons, clrMask);

		return SetIcons(imgList, pCommands, nCount, szIcon, imageState);
	}

}


BOOL CXTPImageManager::SetIcons(UINT nIDResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState)
{
	return SetIcons(MAKEINTRESOURCE(nIDResourceBitmap), pCommands, nCount, szIcon, imageState);
}

BOOL CXTPImageManager::SetIcons(LPCTSTR lpszResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState)
{
	BOOL bAlphaBitmap = FALSE;
	CBitmap bmpIcons;

	HBITMAP hBmp = CXTPImageManagerIcon::LoadBitmapFromResource(lpszResourceBitmap, &bAlphaBitmap);

	if (!hBmp)
		return FALSE;

	bmpIcons.Attach(hBmp);

	return SetIcons(bmpIcons, pCommands, nCount, szIcon, imageState, bAlphaBitmap);
}


BOOL CXTPImageManager::SetImageList(HIMAGELIST hImageList, int nBaseCommand, BOOL bDestoryImageList)
{
	if (!hImageList)
		return FALSE;

	CXTPImageManagerImageList* pImageList = new CXTPImageManagerImageList;
	pImageList->m_bDestroyImageList = bDestoryImageList;
	pImageList->m_hImageList = hImageList;
	pImageList->m_nBaseCommand = nBaseCommand;
	pImageList->m_pImageManager = this;

	m_arrImageList.Add(pImageList);
	return TRUE;
}

BOOL CXTPImageManager::SetImageList(UINT nBitmap, int cx, int nBaseCommand, COLORREF clrMask)
{
	BOOL bAlpha = FALSE;
	HBITMAP hBitmap = CXTPImageManagerIcon::LoadBitmapFromResource(MAKEINTRESOURCE(nBitmap), &bAlpha);
	if (!hBitmap)
		return FALSE;

	BITMAP bmpInfo;
	if (!::GetObject(hBitmap, sizeof(BITMAP), &bmpInfo))
		return FALSE;

	if (cx == 0) cx = bmpInfo.bmWidth;

	if (((bmpInfo.bmWidth % cx) != 0))
		return FALSE;

	HIMAGELIST hImageList = ImageList_Create(cx, bmpInfo.bmHeight, (bAlpha ? ILC_COLOR32 : ILC_COLOR24) |
		(clrMask == COLORREF_NULL ? 0 : ILC_MASK), 0, 1);

	if (!hImageList)
		return FALSE;

	if (bAlpha || (clrMask == COLORREF_NULL))
	{
		ImageList_Add(hImageList, hBitmap, NULL);
	}
	else
	{
		ImageList_AddMasked(hImageList, hBitmap, clrMask);
	}

	DeleteObject(hBitmap);

	return SetImageList(hImageList, nBaseCommand, TRUE);
}




BOOL CXTPImageManager::IsPngBitmapResource(UINT nIDResourceBitmap)
{
	return CXTPImageManagerIcon::IsPngBitmapResource(AfxFindResourceHandle(MAKEINTRESOURCE(nIDResourceBitmap), _T("PNG")),
		MAKEINTRESOURCE(nIDResourceBitmap));
}



BOOL CXTPImageManager::IsAlphaBitmapResource(UINT nIDResourceBitmap)
{
	return CXTPImageManagerIcon::IsAlphaBitmapResource(AfxFindResourceHandle(MAKEINTRESOURCE(nIDResourceBitmap), RT_BITMAP),
		MAKEINTRESOURCE(nIDResourceBitmap));
}

UINT CXTPImageManager::AddCustomIcon(const CXTPImageManagerIconHandle& hIcon)
{
	CSize szIcon = hIcon.GetExtent();
	m_nCustomID++;

	CXTPImageManagerIconSet* pIconSet = new CXTPImageManagerIconSet(m_nCustomID, this);
	pIconSet->SetIcon(hIcon, szIcon.cx);
	m_mapImages.SetAt(m_nCustomID, pIconSet);

	return m_nCustomID;
}

void CXTPImageManager::CopyImage(UINT nCommand)
{
	CMemFile memFile;
	CArchive ar (&memFile, CArchive::store);

	Serialize(nCommand, ar);
	ar.Flush();

	DWORD dwCount = (DWORD)memFile.GetPosition();
	BYTE* pControls = memFile.Detach();

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwCount);
	if (hGlobal != NULL)
	{
		LPVOID lpData = GlobalLock(hGlobal);

		MEMCPY_S(lpData, pControls, dwCount);

		GlobalUnlock(hGlobal);
		SetClipboardData(m_nImageClipFormat, hGlobal);
	}

	ar.Close();
	memFile.Close();
	free(pControls);
}



UINT CXTPImageManager::PasteCustomImage(COleDataObject& data)
{
#ifdef __AFXOLE_H__
	HGLOBAL hGlobal = data.GetGlobalData (m_nImageClipFormat);

	if (hGlobal == NULL) return 0;

	try
	{
		CSharedFile globFile;
		globFile.SetHandle(hGlobal, FALSE);
		CArchive ar (&globFile, CArchive::load);

		m_nCustomID++;
		Serialize(m_nCustomID, ar);

		ar.Close();

	}
	catch (COleException* pEx)
	{
		pEx->Delete ();
		return 0;
	}
	catch (CArchiveException* pEx)
	{
		pEx->Delete ();
		return 0;
	}
	return m_nCustomID;
#else
	return 0;
#endif
}

BOOL CXTPImageManager::IsPrimaryImageExists(UINT nCommand, int nWidth) const
{
	CXTPImageManagerIconSet* pIconSet = GetIconSet(nCommand);

	if (pIconSet)
	{
		CXTPImageManagerIcon* pIcon = pIconSet->GetIcon(nWidth, FALSE);
		if (pIcon)
			return TRUE;
	}

	CXTPImageManagerImageList* pImageList = GetImageList(nCommand);
	if (pImageList)
	{
		return nWidth == 0 || pImageList->GetIconSize().cx == nWidth;
	}

	return FALSE;
}

CXTPImageManagerIcon* CXTPImageManager::GetImage(UINT nCommand, int nWidth) const
{
	CXTPImageManagerIconSet* pIconSet = GetIconSet(nCommand);

	if (pIconSet)
	{
		return pIconSet->GetIcon(nWidth);
	}

	CXTPImageManagerImageList* pImageList = GetImageList(nCommand);
	if (pImageList)
	{
		return pImageList->GetIcon(nCommand);
	}

	return NULL;
}

BOOL CXTPImageManager::Lookup(UINT nCommand) const
{
	return (GetIconSet(nCommand) != NULL) || (GetImageList(nCommand) != NULL);
}

CXTPImageManagerIconSet* CXTPImageManager::GetIconSet(UINT nCommand) const
{
	CXTPImageManagerIconSet* pIconSet;
	if (m_mapImages.Lookup(nCommand, pIconSet))
	{
		return pIconSet;

	}
	return NULL;
}

CXTPImageManagerImageList* CXTPImageManager::GetImageList(UINT nCommand) const
{
	for (int i = 0; i < (int)m_arrImageList.GetSize(); i++)
	{
		CXTPImageManagerImageList* pImageList = m_arrImageList[i];

		if (pImageList->Lookup(nCommand))
			return pImageList;
	}
	return NULL;
}

void CXTPImageManager::RemoveIcon(UINT nIDCommand)
{
	CXTPImageManagerIconSet* pIconSet;
	if (m_mapImages.Lookup(nIDCommand, pIconSet))
	{
		m_mapImages.RemoveKey(nIDCommand);
		pIconSet->RemoveAll();
		pIconSet->InternalRelease();
	}
}

void CXTPImageManager::RemoveAll()
{
	POSITION pos = m_mapImages.GetStartPosition();
	UINT nID;
	CXTPImageManagerIconSet* pIconSet;
	while (pos)
	{
		m_mapImages.GetNextAssoc(pos, nID, pIconSet);
		pIconSet->RemoveAll();
		pIconSet->InternalRelease();
	}
	m_mapImages.RemoveAll();

	pos = m_mapResources.GetStartPosition();
	DWORD dwSize;
	CXTPImageManagerResource* pResource;
	while (pos)
	{
		m_mapResources.GetNextAssoc(pos, dwSize, pResource);
		delete pResource;
	}
	m_mapResources.RemoveAll();


	for (int i = 0; i < (int)m_arrImageList.GetSize(); i++)
	{
		delete m_arrImageList[i];
	}
	m_arrImageList.RemoveAll();

}

void CXTPImageManager::RefreshAll()
{
	POSITION pos = m_mapImages.GetStartPosition();
	UINT nID;
	CXTPImageManagerIconSet* pIconSet;

	while (pos)
	{
		m_mapImages.GetNextAssoc(pos, nID, pIconSet);
		pIconSet->RefreshAll();
	}

	for (int i = 0; i < (int)m_arrImageList.GetSize(); i++)
	{
		m_arrImageList[i]->RemoveAll();
	}
}

COLORREF CXTPImageManager::SetMaskColor(COLORREF clrMask)
{
	COLORREF clrReturn = m_clrMask;
	m_clrMask = clrMask;
	return clrReturn;
}
COLORREF CXTPImageManager::GetMaskColor() const
{
	return m_clrMask;
}

BOOL CXTPImageManager::IsAlphaIconsSupported() const
{
	return TRUE;

}

BOOL CXTPImageManager::IsAlphaIconsImageListSupported()
{
	DWORD dwComCtlVersion = XTPSystemVersion()->GetComCtlVersion();
	return HIWORD(dwComCtlVersion) > 5;
}

void CXTPImageManager::DoPropExchange(UINT nCommand, CXTPPropExchange* pPX)
{
#ifndef _XTP_EXCLUDE_PROPEXCHANGE
	if (nCommand > m_nCustomID)
		m_nCustomID = nCommand;

	const LPCTSTR lpszCheck = _T("CXTPImageManagerIcons");
	CString strCheck = lpszCheck;

	if (pPX->IsStoring())
	{
		PX_String(pPX, _T("CheckSum"), strCheck, lpszCheck);

		ASSERT(nCommand > 0);
//this assertion kill VB6

		CXTPImageManagerIconSet* pIconSet = GetIconSet(nCommand);

		ASSERT(pIconSet);
//this assertion kill VB6

		if (!pIconSet)
		{
			CXTPPropExchangeEnumeratorPtr pEnumerator(pPX->GetEnumerator(_T("Icon")));
			pEnumerator->GetPosition(0);
			return;
		}

		UINT nWidth;
		CXTPImageManagerIcon* pIcon;
		DWORD dwCount =(DWORD)pIconSet->m_mapIcons.GetCount();

		CXTPPropExchangeEnumeratorPtr pEnumerator(pPX->GetEnumerator(_T("Icon")));
		POSITION posEnum = pEnumerator->GetPosition(dwCount);

		POSITION pos = pIconSet->m_mapIcons.GetStartPosition();
		while (pos)
		{
			pIconSet->m_mapIcons.GetNextAssoc(pos, nWidth, pIcon);

			CXTPPropExchangeSection secIcon(pEnumerator->GetNext(posEnum));

			PX_Long(&secIcon, _T("Width"), (long&)nWidth);
			PX_Serialize(&secIcon, _T("Data"), pIcon);
		}
	}
	else
	{
		PX_String(pPX, _T("CheckSum"), strCheck, lpszCheck);

		if (strCheck != lpszCheck)
			AfxThrowArchiveException(CArchiveException::badClass);


		CXTPImageManagerIconSet* pIconSet;
		if (m_mapImages.Lookup(nCommand, pIconSet))
		{
			pIconSet->RemoveAll();
		}
		else
		{
			pIconSet = new CXTPImageManagerIconSet(nCommand, this);
			m_mapImages.SetAt(nCommand, pIconSet);
		}

		CXTPPropExchangeEnumeratorPtr pEnumerator(pPX->GetEnumerator(_T("Icon")));
		POSITION posEnum = pEnumerator->GetPosition();

		while (posEnum)
		{
			CXTPPropExchangeSection secIcon(pEnumerator->GetNext(posEnum));

			UINT nWidth = 16;
			PX_Long(&secIcon, _T("Width"), (long&)nWidth);

			CXTPImageManagerIcon* pIcon = new CXTPImageManagerIcon(nCommand, nWidth, 15, pIconSet);
			PX_Serialize(&secIcon, _T("Data"), pIcon);

			pIconSet->m_mapIcons.SetAt(nWidth, pIcon);
		}
	}
#endif
}

void CXTPImageManager::Serialize(UINT nCommand, CArchive& ar)
{
#ifndef _XTP_EXCLUDE_PROPEXCHANGE
	CXTPPropExchangeArchive px(ar);
	DoPropExchange(nCommand, &px);
#endif
}



void CXTPImageManager::DoPropExchange(CXTPPropExchange* pPX)
{
#ifndef _XTP_EXCLUDE_PROPEXCHANGE
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* pIcons = GetImages();

	CXTPPropExchangeEnumeratorPtr pEnumerator(pPX->GetEnumerator(_T("IconSet")));
	POSITION posEnum = pEnumerator->GetPosition((DWORD)pIcons->GetCount());

	if (pPX->IsStoring())
	{
		UINT nIDCommand;
		CXTPImageManagerIconSet* pIconSet;

		POSITION pos = pIcons->GetStartPosition();

		while (pos)
		{
			pIcons->GetNextAssoc(pos, nIDCommand, pIconSet);
			CXTPPropExchangeSection secIconSet(pEnumerator->GetNext(posEnum));

			PX_Long(&secIconSet, _T("Id"), (long&)nIDCommand);
			DoPropExchange(nIDCommand, &secIconSet);
		}
	}
	else
	{
		RemoveAll();

		while (posEnum)
		{
			CXTPPropExchangeSection secIconSet(pEnumerator->GetNext(posEnum));

			UINT nIDCommand = 0;
			PX_Long(&secIconSet, _T("Id"), (long&)nIDCommand);

			DoPropExchange(nIDCommand, &secIconSet);
		}
	}
#endif
}
void CXTPImageManager::Serialize(CArchive& ar)
{
#ifndef _XTP_EXCLUDE_PROPEXCHANGE
	CXTPPropExchangeArchive px(ar);
	DoPropExchange(&px);
#endif
}


void CXTPImageManager::AddIcons(CXTPImageManager* pImageManager)
{
	if (pImageManager == 0)
		return;

	POSITION pos = pImageManager->m_mapImages.GetStartPosition();
	UINT nID;
	CXTPImageManagerIconSet* pIconSet;

	while (pos)
	{
		pImageManager->m_mapImages.GetNextAssoc(pos, nID, pIconSet);

		AddIcons(pIconSet);
	}
}

void CXTPImageManager::AddIcons(CXTPImageManagerIconSet* pIconSetAdd)
{
	int nId = pIconSetAdd->GetID();

	CXTPImageManagerIconSet* pIconSet = NULL;

	if (!m_mapImages.Lookup(nId, pIconSet))
	{
		pIconSet = new CXTPImageManagerIconSet(nId, this);

		m_mapImages.SetAt(nId, pIconSet);
	}

	POSITION pos = pIconSetAdd->m_mapIcons.GetStartPosition();
	UINT nWidth;
	CXTPImageManagerIcon* pIconAdd;

	while (pos)
	{
		pIconSetAdd->m_mapIcons.GetNextAssoc(pos, nWidth, pIconAdd);

		CXTPImageManagerIcon* pIcon = NULL;
		if (!pIconSet->m_mapIcons.Lookup(nWidth, pIcon))
		{
			pIcon  = new CXTPImageManagerIcon(nId, nWidth, pIconAdd->GetHeight());
			pIconSet->m_mapIcons.SetAt(nWidth, pIcon);
		}

		pIcon->Copy(pIconAdd);
	}
}

BOOL CXTPImageManager::DoDisableBitmap(HBITMAP hBmp, COLORREF clrDisabledLight, COLORREF clrDisabledDark,
		int nBlackAndWhiteContrast)
{
	ASSERT(nBlackAndWhiteContrast == -1 ||
		(nBlackAndWhiteContrast >= 0 && nBlackAndWhiteContrast <= 255));

	BOOL bOfficeDisabledIcons = clrDisabledLight != (COLORREF)-1 && clrDisabledDark != (COLORREF)-1;

	BITMAP bmBitmap;

	// Get information about the surfaces you were passed.
	if (!GetObject(hBmp,  sizeof(BITMAP), &bmBitmap))  return FALSE;

	// Make sure you have data that meets your requirements.
	if (bmBitmap.bmBitsPixel != 32)
		return FALSE;

	if (bmBitmap.bmPlanes != 1)
		return FALSE;

	if (!bmBitmap.bmBits)
		return FALSE;

	DWORD dwWidthBytes = bmBitmap.bmWidthBytes;

	// Initialize the surface pointers.
	RGBQUAD *lprgbBitmap = (RGBQUAD*)bmBitmap.bmBits;

	//************************************************
	int x, y;
	for (y = 0; y < bmBitmap.bmHeight; y++)
	{
		for (x = 0; x < bmBitmap.bmWidth; x++)
		{
			if (bOfficeDisabledIcons)
			{
				double dGray = (lprgbBitmap[x].rgbBlue * 0.114 + lprgbBitmap[x].rgbGreen * 0.587 + lprgbBitmap[x].rgbRed * 0.299)/255.0;
				double dLight = 1.0 - dGray;

				lprgbBitmap[x].rgbBlue  = BYTE(dLight * GetBValue(clrDisabledDark) + dGray * GetBValue(clrDisabledLight));
				lprgbBitmap[x].rgbGreen = BYTE(dLight * GetGValue(clrDisabledDark) + dGray * GetGValue(clrDisabledLight));
				lprgbBitmap[x].rgbRed   = BYTE(dLight * GetRValue(clrDisabledDark) + dGray * GetRValue(clrDisabledLight));
			}
			else if (nBlackAndWhiteContrast != -1)
			{
				int nGray = (lprgbBitmap[x].rgbBlue * 114 + lprgbBitmap[x].rgbGreen * 587 + lprgbBitmap[x].rgbRed * 299) / 1000;
				nGray = nGray + (255 - nGray) * nBlackAndWhiteContrast / 255;
				nGray = min(nGray, 255);

				lprgbBitmap[x].rgbBlue = BYTE(nGray);
				lprgbBitmap[x].rgbGreen = BYTE(nGray);
				lprgbBitmap[x].rgbRed = BYTE(nGray);

				lprgbBitmap[x].rgbReserved = BYTE(lprgbBitmap[x].rgbReserved / CXTPImageManager::m_dDisabledAlphaFactor);
			}
			else
			{
				double dGray = (lprgbBitmap[x].rgbBlue * 0.114 + lprgbBitmap[x].rgbGreen * 0.587 + lprgbBitmap[x].rgbRed * 0.299)/255.0;

				lprgbBitmap[x].rgbBlue = (BYTE)(pow(dGray, CXTPImageManager::m_dDisabledBrightnessFactor) * 255.0);
				lprgbBitmap[x].rgbGreen = lprgbBitmap[x].rgbBlue;
				lprgbBitmap[x].rgbRed = lprgbBitmap[x].rgbBlue;

				lprgbBitmap[x].rgbReserved = BYTE(lprgbBitmap[x].rgbReserved / CXTPImageManager::m_dDisabledAlphaFactor);
			}
		}

		// Move to next scan line.
		lprgbBitmap = (RGBQUAD *)((LPBYTE)lprgbBitmap + dwWidthBytes);
	}

	return TRUE;
}

BOOL CXTPImageManager::DisableBitmap(HDC hDC, const CRect& rcRect, COLORREF clrDisabledLight, COLORREF clrDisabledDark)
{
	HDC      hdcDst  = NULL;
	HBITMAP  hbmDst  = NULL;
	HBITMAP  hbmpOld = NULL;

	BOOL    bReturn = FALSE;
	// Create surfaces for new image.
	hbmDst  = CXTPImageManager::Create32BPPDIBSection(hDC, rcRect.Width(), rcRect.Height());
	if (!hbmDst) goto HANDLEERROR;

	// Create HDCs to hold our surfaces.
	hdcDst  = CreateCompatibleDC(hDC);
	if (!hdcDst) goto HANDLEERROR;

	// Prepare the surfaces for drawing.
	hbmpOld = (HBITMAP)SelectObject(hdcDst,  hbmDst);

	// Capture a copy of the source area.
	if (!BitBlt(hdcDst, 0, 0, rcRect.Width(), rcRect.Height(),
		hDC, rcRect.left, rcRect.top, SRCCOPY) )
		goto HANDLEERROR;

	// Modify sourcepixels to create the destination image.
	bReturn = DoDisableBitmap(hbmDst, clrDisabledLight, clrDisabledDark);

	// Display the disabled image to the target HDC.
	if (bReturn)
	{
		BitBlt(hDC, rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height(),
			hdcDst, 0,0, SRCCOPY);
	}

HANDLEERROR:

	// Clean up the rest of the objects you created.
	if (hbmpOld) SelectObject(hdcDst, hbmpOld);
	if (hdcDst) DeleteDC(hdcDst);
	if (hbmDst) DeleteObject(hbmDst);

	return bReturn;
}

BOOL CXTPImageManager::BlackWhiteBitmap(HDC hDC, const CRect& rcRect, int nBlackAndWhiteContrast)
{
	HDC      hdcDst  = NULL;
	HBITMAP  hbmDst  = NULL;
	HBITMAP  hbmpOld = NULL;

	BOOL    bReturn = FALSE;
	// Create surfaces for new image.
	hbmDst  = CXTPImageManager::Create32BPPDIBSection(hDC, rcRect.Width(), rcRect.Height());
	if (!hbmDst) goto HANDLEERROR;

	// Create HDCs to hold our surfaces.
	hdcDst  = CreateCompatibleDC(hDC);
	if (!hdcDst) goto HANDLEERROR;

	// Prepare the surfaces for drawing.
	hbmpOld = (HBITMAP)SelectObject(hdcDst,  hbmDst);

	// Capture a copy of the source area.
	if (!BitBlt(hdcDst, 0, 0, rcRect.Width(), rcRect.Height(),
		hDC, rcRect.left, rcRect.top, SRCCOPY) )
		goto HANDLEERROR;

	// Modify sourcepixels to create the destination image.
	bReturn = DoDisableBitmap(hbmDst, (COLORREF)-1, (COLORREF)-1, nBlackAndWhiteContrast);

	// Display the disabled image to the target HDC.
	if (bReturn)
	{
		BitBlt(hDC, rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height(),
			hdcDst, 0,0, SRCCOPY);
	}

HANDLEERROR:

	// Clean up the rest of the objects you created.
	if (hbmpOld) SelectObject(hdcDst, hbmpOld);
	if (hdcDst) DeleteDC(hdcDst);
	if (hbmDst) DeleteObject(hbmDst);

	return bReturn;
}


