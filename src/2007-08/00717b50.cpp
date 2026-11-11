// from server: 100% by EspClaude
// from server: 98% by EspClaude
// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /MD /GS /EHsc
// roc-lib: xtp-11.2.2-shared-mfc roc_claude_8539e570afc1f2ce.cpp

// Candidate translation unit (score above; library headers required).
// MFC 9.0 afxwin.h copy; only change: CWnd/CFrameWnd GetMenu/SetMenu not virtual (MFC 8.0 / VS2005), proven by CWnd vtable slots 8 bytes lower in 2007-08 targets.

#ifndef __AFXWIN_H__
#ifndef RC_INVOKED
#define __AFXWIN_H__

#ifndef __AFX_H__
	#include <afx.h>
#endif

#ifndef NTDDI_LONGHORN
#define NTDDI_LONGHORN 0x06000000
#if (WINVER >= 0x0600) || (_WIN32_WINNT >= 0x0600)
#error Your version of the Windows SDK is earlier than 6.0. Try setting the 'WINVER' and '_WIN32_WINNT' definitions in your project to less than 0x0600.
#endif
#endif

#ifndef _INC_SHELLAPI
	#include <shellapi.h>
#endif

#ifndef __AFXRES_H__
	#include <afxres.h>     // standard resource IDs
#endif

#ifndef __AFXCOLL_H__
	#include <afxcoll.h>    // standard collections
#endif

#ifndef _OBJBASE_H_
	#include <objbase.h> //needed for commdlg.h (STDMETHOD)
#endif

#ifndef _INC_COMMDLG
	#include <commdlg.h>    // common dialog APIs
#endif

#ifdef GetFileTitle
#undef GetFileTitle
AFX_INLINE short APIENTRY GetFileTitle(LPCTSTR lpszFile, LPTSTR lpszTitle, WORD cbBuf)
#ifdef UNICODE
	{ return ::GetFileTitleW(lpszFile, lpszTitle, cbBuf); }
#else
	{ return ::GetFileTitleA(lpszFile, lpszTitle, cbBuf); }
#endif
#endif

#ifndef _AFX_NO_AFXCMN_SUPPORT
#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif
#include <afxcomctl32.h>
#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
#endif

#if (_WIN32_WINNT >= 0x501)
#include <uxtheme.h>

#if ((NTDDI_VERSION >= NTDDI_LONGHORN || defined(__VSSYM32_H__)) && !defined(SCHEMA_VERIFY_VSSYM32))
#include <vssym32.h>
#else
#include <tmschema.h>
#endif
#endif	// (_WIN32_WINNT >= 0x501)

#if (_WIN32_WINNT >= 0x600)
#ifndef _WINSOCK2API_
#ifdef _WINSOCKAPI_
	#error MFC requires use of Winsock2.h
#endif
	#include <winsock2.h>
#endif

#ifndef _WS2IPDEF_
	#include <ws2ipdef.h>
#endif

#ifndef _WINDNS_INCLUDED_
	#include <windns.h>
#endif

#ifndef __IPHLPAPI_H__
	#include <iphlpapi.h>
#endif
#endif	// (_WIN32_WINNT >= 0x600)

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

#ifndef _AFX_NOFORCE_LIBS
#pragma comment(lib, "uuid.lib")
#endif

#ifdef _INC_WINDOWSX
#undef SubclassWindow
#undef CopyRgn
#endif

#include <htmlhelp.h>

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#pragma warning( push )
#pragma warning( disable: 4121 )

			class CResourceException;// Win resource failure exception
			class CUserException;    // Message Box alert and stop operation

	class CGdiObject;            // CDC drawing tool
		class CPen;              // a pen / HPEN wrapper
		class CBrush;            // a brush / HBRUSH wrapper
		class CFont;             // a font / HFONT wrapper
		class CBitmap;           // a bitmap / HBITMAP wrapper
		class CPalette;          // a palette / HPALLETE wrapper
		class CRgn;              // a region / HRGN wrapper

	class CDC;                   // a Display Context / HDC wrapper
		class CClientDC;         // CDC for client of window
		class CWindowDC;         // CDC for entire window
		class CPaintDC;          // embeddable BeginPaint struct helper

	class CImageList;            // an image list / HIMAGELIST wrapper

	class CMenu;                 // a menu / HMENU wrapper

	class CCmdTarget;            // a target for user commands
		class CWnd;                 // a window / HWND wrapper
			class CDialog;          // a dialog

			class CStatic;          // Static control
			class CButton;          // Button control
			class CListBox;         // ListBox control
				class CCheckListBox;// special listbox with checks
			class CComboBox;        // ComboBox control
			class CEdit;            // Edit control
			class CScrollBar;       // ScrollBar control

			class CFrameWnd;        // standard SDI frame
				class CMDIFrameWnd; // standard MDI frame
				class CMDIChildWnd; // standard MDI child
				class CMiniFrameWnd;// half-height caption frame wnd

			class CView;            // a view on a document
				class CScrollView;  // a scrolling view

		class CWinThread;           // thread base class
			class CWinApp;          // application base class

		class CDocTemplate;         // template for document creation
			class CSingleDocTemplate;// SDI support
			class CMultiDocTemplate; // MDI support

		class CDocument;            // main document abstraction

class CCmdUI;           // Menu/button enabling
class CDataExchange;    // Data exchange and validation context
class CCommandLineInfo; // CommandLine parsing helper
class CDocManager;      // CDocTemplate manager object

struct COleControlSiteOrWnd; // ActiveX dialog control helper

class CControlCreationInfo; //Used in CWnd::CreateControl overloads.

class CVariantBoolConverter;

enum AFX_HELP_TYPE
{
	afxWinHelp = 0,
	afxHTMLHelp = 1
};

#ifndef afx_msg
#define afx_msg         // intentional placeholder
#endif

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA

#ifndef __ATLTYPES_H__
#include <atltypes.h>
#endif

#ifdef _DEBUG
CDumpContext& AFXAPI operator<<(CDumpContext& dc, SIZE size);
CDumpContext& AFXAPI operator<<(CDumpContext& dc, POINT point);
CDumpContext& AFXAPI operator<<(CDumpContext& dc, const RECT& rect);
#endif //_DEBUG

CArchive& AFXAPI operator<<(CArchive& ar, SIZE size);
CArchive& AFXAPI operator<<(CArchive& ar, POINT point);
CArchive& AFXAPI operator<<(CArchive& ar, const RECT& rect);
CArchive& AFXAPI operator>>(CArchive& ar, SIZE& size);
CArchive& AFXAPI operator>>(CArchive& ar, POINT& point);
CArchive& AFXAPI operator>>(CArchive& ar, RECT& rect);

class CResourceException : public CSimpleException    // resource failure
{
	DECLARE_DYNAMIC(CResourceException)
public:
	CResourceException();

public:
	explicit CResourceException(BOOL bAutoDelete);
	CResourceException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CResourceException();
};

class CUserException : public CSimpleException   // general user visible alert
{
	DECLARE_DYNAMIC(CUserException)
public:
	CUserException();

public:
	explicit CUserException(BOOL bAutoDelete);
	CUserException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CUserException();
};

void AFXAPI AfxThrowResourceException();
void AFXAPI AfxThrowUserException();

void AFXAPI AfxGetGrayBitmap(const CBitmap &rSrc, CBitmap *pDest, COLORREF crBackground);
void AFXAPI AfxDrawGrayBitmap(CDC *pDC, int x, int y, const CBitmap &rSrc, COLORREF crBackground);
void AFXAPI AfxGetDitheredBitmap(const CBitmap &rSrc, CBitmap *pDest, COLORREF cr1, COLORREF cr2);
void AFXAPI AfxDrawDitheredBitmap(CDC *pDC, int x, int y, const CBitmap &rSrc, COLORREF cr1, COLORREF cr2);

class CGdiObject : public CObject
{
	DECLARE_DYNCREATE(CGdiObject)
public:

	HGDIOBJ m_hObject;                  // must be first data member
	operator HGDIOBJ() const;
	HGDIOBJ GetSafeHandle() const;

	static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HGDIOBJ hObject);
	HGDIOBJ Detach();

	CGdiObject(); // must Create a derived class object
	BOOL DeleteObject();

#pragma push_macro("GetObject")
#undef GetObject
	int _AFX_FUNCNAME(GetObject)(int nCount, LPVOID lpObject) const;
	int GetObject(int nCount, LPVOID lpObject) const;
#pragma pop_macro("GetObject")
	UINT GetObjectType() const;
	BOOL CreateStockObject(int nIndex);
	BOOL UnrealizeObject();
	BOOL operator==(const CGdiObject& obj) const;
	BOOL operator!=(const CGdiObject& obj) const;

public:
	virtual ~CGdiObject();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
};

class CPen : public CGdiObject
{
	DECLARE_DYNAMIC(CPen)

public:
	static CPen* PASCAL FromHandle(HPEN hPen);

	CPen();
	CPen(int nPenStyle, int nWidth, COLORREF crColor);
	CPen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
		int nStyleCount = 0, const DWORD* lpStyle = NULL);
	BOOL CreatePen(int nPenStyle, int nWidth, COLORREF crColor);
	BOOL CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
		int nStyleCount = 0, const DWORD* lpStyle = NULL);
	BOOL CreatePenIndirect(LPLOGPEN lpLogPen);

	operator HPEN() const;
	int GetLogPen(LOGPEN* pLogPen);
	int GetExtLogPen(EXTLOGPEN* pLogPen);

public:
	virtual ~CPen();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CBrush : public CGdiObject
{
	DECLARE_DYNAMIC(CBrush)

public:
	static CBrush* PASCAL FromHandle(HBRUSH hBrush);

	CBrush();
	CBrush(COLORREF crColor);             // CreateSolidBrush
	CBrush(int nIndex, COLORREF crColor); // CreateHatchBrush
	explicit CBrush(CBitmap* pBitmap);          // CreatePatternBrush

	BOOL CreateSolidBrush(COLORREF crColor);
	BOOL CreateHatchBrush(int nIndex, COLORREF crColor);
	BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
	BOOL CreatePatternBrush(CBitmap* pBitmap);
	BOOL CreateDIBPatternBrush(HGLOBAL hPackedDIB, UINT nUsage);
	BOOL CreateDIBPatternBrush(const void* lpPackedDIB, UINT nUsage);
	BOOL CreateSysColorBrush(int nIndex);

	operator HBRUSH() const;
	int GetLogBrush(LOGBRUSH* pLogBrush);

public:
	virtual ~CBrush();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CFont : public CGdiObject
{
	DECLARE_DYNAMIC(CFont)

public:
	static CFont* PASCAL FromHandle(HFONT hFont);

	CFont();
	BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
	BOOL CreateFont(int nHeight, int nWidth, int nEscapement,
			int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
			BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
			BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily,
			LPCTSTR lpszFacename);
	BOOL CreatePointFont(int nPointSize, LPCTSTR lpszFaceName, CDC* pDC = NULL);
	BOOL CreatePointFontIndirect(const LOGFONT* lpLogFont, CDC* pDC = NULL);

	operator HFONT() const;
	int GetLogFont(LOGFONT* pLogFont);

public:
	virtual ~CFont();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CBitmap : public CGdiObject
{
	DECLARE_DYNAMIC(CBitmap)

public:
	static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);

	CBitmap();

	BOOL LoadBitmap(LPCTSTR lpszResourceName);
	BOOL LoadBitmap(UINT nIDResource);
	BOOL LoadOEMBitmap(UINT nIDBitmap); // for OBM_/OCR_/OIC_
#ifndef _AFX_NO_AFXCMN_SUPPORT
	BOOL LoadMappedBitmap(UINT nIDBitmap, UINT nFlags = 0,
		LPCOLORMAP lpColorMap = NULL, int nMapSize = 0);
#endif
	BOOL CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount,
			const void* lpBits);
	BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
	BOOL CreateCompatibleBitmap(CDC* pDC, int nWidth, int nHeight);
	BOOL CreateDiscardableBitmap(CDC* pDC, int nWidth, int nHeight);

	operator HBITMAP() const;
	int GetBitmap(BITMAP* pBitMap);

	DWORD SetBitmapBits(DWORD dwCount, const void* lpBits);
	DWORD GetBitmapBits(DWORD dwCount, LPVOID lpBits) const;
	CSize SetBitmapDimension(int nWidth, int nHeight);
	CSize GetBitmapDimension() const;

public:
	virtual ~CBitmap();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CPalette : public CGdiObject
{
	DECLARE_DYNAMIC(CPalette)

public:
	static CPalette* PASCAL FromHandle(HPALETTE hPalette);

	CPalette();
	BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
	BOOL CreateHalftonePalette(CDC* pDC);

	operator HPALETTE() const;
	int GetEntryCount();
	UINT GetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors) const;
	UINT SetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors);

	void AnimatePalette(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors);
	UINT GetNearestPaletteIndex(COLORREF crColor) const;
	BOOL ResizePalette(UINT nNumEntries);

	virtual ~CPalette();
};

class CRgn : public CGdiObject
{
	DECLARE_DYNAMIC(CRgn)

public:
	static CRgn* PASCAL FromHandle(HRGN hRgn);
	operator HRGN() const;

	CRgn();
	BOOL CreateRectRgn(int x1, int y1, int x2, int y2);
	BOOL CreateRectRgnIndirect(LPCRECT lpRect);
	BOOL CreateEllipticRgn(int x1, int y1, int x2, int y2);
	BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
	BOOL CreatePolygonRgn(LPPOINT lpPoints, int nCount, int nMode);
	BOOL CreatePolyPolygonRgn(LPPOINT lpPoints, LPINT lpPolyCounts,
			int nCount, int nPolyFillMode);
	BOOL CreateRoundRectRgn(int x1, int y1, int x2, int y2, int x3, int y3);
	BOOL CreateFromPath(CDC* pDC);
	BOOL CreateFromData(const XFORM* lpXForm, int nCount,
		const RGNDATA* pRgnData);

	void SetRectRgn(int x1, int y1, int x2, int y2);
	void SetRectRgn(LPCRECT lpRect);
	int CombineRgn(const CRgn* pRgn1, const CRgn* pRgn2, int nCombineMode);
	int CopyRgn(const CRgn* pRgnSrc);
	BOOL EqualRgn(const CRgn* pRgn) const;
	int OffsetRgn(int x, int y);
	int OffsetRgn(POINT point);
	int GetRgnBox(LPRECT lpRect) const;
	BOOL PtInRegion(int x, int y) const;
	BOOL PtInRegion(POINT point) const;
	BOOL RectInRegion(LPCRECT lpRect) const;
	int GetRegionData(LPRGNDATA lpRgnData, int nCount) const;

	virtual ~CRgn();
};

class CDC : public CObject
{
	DECLARE_DYNCREATE(CDC)
public:

	HDC m_hDC;          // The output DC (must be first data member)
	HDC m_hAttribDC;    // The Attribute DC
	operator HDC() const;
	HDC GetSafeHdc() const; // Always returns the Output DC
	CWnd* GetWindow() const;

	static CDC* PASCAL FromHandle(HDC hDC);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HDC hDC);   // Attach/Detach affects only the Output DC
	HDC Detach();

	virtual void SetAttribDC(HDC hDC);  // Set the Attribute DC
	virtual void SetOutputDC(HDC hDC);  // Set the Output DC
	virtual void ReleaseAttribDC();     // Release the Attribute DC
	virtual void ReleaseOutputDC();     // Release the Output DC

	BOOL IsPrinting() const;            // TRUE if being used for printing

	CPen* GetCurrentPen() const;
	CBrush* GetCurrentBrush() const;
	CPalette* GetCurrentPalette() const;
	CFont* GetCurrentFont() const;
	CBitmap* GetCurrentBitmap() const;

	DWORD GetLayout() const;
	DWORD SetLayout(DWORD dwLayout);

	CDC();
	BOOL CreateDC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
		LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateIC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
		LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateCompatibleDC(CDC* pDC);

	BOOL DeleteDC();

	virtual int SaveDC();
	virtual BOOL RestoreDC(int nSavedDC);
	int GetDeviceCaps(int nIndex) const;
	UINT SetBoundsRect(LPCRECT lpRectBounds, UINT flags);
	UINT GetBoundsRect(LPRECT lpRectBounds, UINT flags);
	BOOL ResetDC(const DEVMODE* lpDevMode);

	CPoint GetBrushOrg() const;
	CPoint SetBrushOrg(int x, int y);
	CPoint SetBrushOrg(POINT point);
	int EnumObjects(int nObjectType,
			int (CALLBACK* lpfn)(LPVOID, LPARAM), LPARAM lpData);

public:
	virtual CGdiObject* SelectStockObject(int nIndex);
	CPen* SelectObject(CPen* pPen);
	CBrush* SelectObject(CBrush* pBrush);
	virtual CFont* SelectObject(CFont* pFont);
	CBitmap* SelectObject(CBitmap* pBitmap);
	int SelectObject(CRgn* pRgn);       // special return for regions
	CGdiObject* SelectObject(CGdiObject* pObject);

	COLORREF GetNearestColor(COLORREF crColor) const;
	CPalette* SelectPalette(CPalette* pPalette, BOOL bForceBackground);
	UINT RealizePalette();
	void UpdateColors();

	COLORREF GetBkColor() const;
	int GetBkMode() const;
	int GetPolyFillMode() const;
	int GetROP2() const;
	int GetStretchBltMode() const;
	COLORREF GetTextColor() const;

	virtual COLORREF SetBkColor(COLORREF crColor);
	int SetBkMode(int nBkMode);
	int SetPolyFillMode(int nPolyFillMode);
	int SetROP2(int nDrawMode);
	int SetStretchBltMode(int nStretchMode);
	virtual COLORREF SetTextColor(COLORREF crColor);

	BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) const;
	BOOL SetColorAdjustment(const COLORADJUSTMENT* lpColorAdjust);

#if (_WIN32_WINNT >= 0x0500)

	COLORREF GetDCBrushColor() const;
	COLORREF SetDCBrushColor(COLORREF crColor);

	COLORREF GetDCPenColor() const;
	COLORREF SetDCPenColor(COLORREF crColor);

#endif

	int SetGraphicsMode(int iMode);
	int GetGraphicsMode() const;

	BOOL SetWorldTransform(const XFORM* pXform);
	BOOL ModifyWorldTransform(const XFORM* pXform,DWORD iMode);
	BOOL GetWorldTransform(XFORM* pXform) const;

	int GetMapMode() const;
	CPoint GetViewportOrg() const;
	virtual int SetMapMode(int nMapMode);
	virtual CPoint SetViewportOrg(int x, int y);
			CPoint SetViewportOrg(POINT point);
	virtual CPoint OffsetViewportOrg(int nWidth, int nHeight);

	CSize GetViewportExt() const;
	virtual CSize SetViewportExt(int cx, int cy);
			CSize SetViewportExt(SIZE size);
	virtual CSize ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom);

	CPoint GetWindowOrg() const;
	CPoint SetWindowOrg(int x, int y);
	CPoint SetWindowOrg(POINT point);
	CPoint OffsetWindowOrg(int nWidth, int nHeight);

	CSize GetWindowExt() const;
	virtual CSize SetWindowExt(int cx, int cy);
			CSize SetWindowExt(SIZE size);
	virtual CSize ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom);

	void DPtoLP(LPPOINT lpPoints, int nCount = 1) const;
	void DPtoLP(LPRECT lpRect) const;
	void DPtoLP(LPSIZE lpSize) const;
	void LPtoDP(LPPOINT lpPoints, int nCount = 1) const;
	void LPtoDP(LPRECT lpRect) const;
	void LPtoDP(LPSIZE lpSize) const;

	void DPtoHIMETRIC(LPSIZE lpSize) const;
	void LPtoHIMETRIC(LPSIZE lpSize) const;
	void HIMETRICtoDP(LPSIZE lpSize) const;
	void HIMETRICtoLP(LPSIZE lpSize) const;

	BOOL FillRgn(CRgn* pRgn, CBrush* pBrush);
	BOOL FrameRgn(CRgn* pRgn, CBrush* pBrush, int nWidth, int nHeight);
	BOOL InvertRgn(CRgn* pRgn);
	BOOL PaintRgn(CRgn* pRgn);

	virtual int GetClipBox(LPRECT lpRect) const;
	virtual BOOL PtVisible(int x, int y) const;
			BOOL PtVisible(POINT point) const;
	virtual BOOL RectVisible(LPCRECT lpRect) const;
			int SelectClipRgn(CRgn* pRgn);
			int ExcludeClipRect(int x1, int y1, int x2, int y2);
			int ExcludeClipRect(LPCRECT lpRect);
			int ExcludeUpdateRgn(CWnd* pWnd);
			int IntersectClipRect(int x1, int y1, int x2, int y2);
			int IntersectClipRect(LPCRECT lpRect);
			int OffsetClipRgn(int x, int y);
			int OffsetClipRgn(SIZE size);
	int SelectClipRgn(CRgn* pRgn, int nMode);

	CPoint GetCurrentPosition() const;
	CPoint MoveTo(int x, int y);
	CPoint MoveTo(POINT point);
	BOOL LineTo(int x, int y);
	BOOL LineTo(POINT point);
	BOOL Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Arc(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polyline(const POINT* lpPoints, int nCount);

	BOOL AngleArc(int x, int y, int nRadius, float fStartAngle, float fSweepAngle);
	BOOL ArcTo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL ArcTo(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	int GetArcDirection() const;
	int SetArcDirection(int nArcDirection);

	BOOL PolyDraw(const POINT* lpPoints, const BYTE* lpTypes, int nCount);
	BOOL PolylineTo(const POINT* lpPoints, int nCount);
	BOOL PolyPolyline(const POINT* lpPoints,
		const DWORD* lpPolyPoints, int nCount);

	BOOL PolyBezier(const POINT* lpPoints, int nCount);
	BOOL PolyBezierTo(const POINT* lpPoints, int nCount);

	void FillRect(LPCRECT lpRect, CBrush* pBrush);
	void FrameRect(LPCRECT lpRect, CBrush* pBrush);
	void InvertRect(LPCRECT lpRect);
	BOOL DrawIcon(int x, int y, HICON hIcon);
	BOOL DrawIcon(POINT point, HICON hIcon);
	BOOL DrawState(CPoint pt, CSize size, HBITMAP hBitmap, UINT nFlags,
		HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, CBitmap* pBitmap, UINT nFlags,
		CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
		HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
		CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
		BOOL bPrefixText = TRUE, int nTextLen = 0, HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
		BOOL bPrefixText = TRUE, int nTextLen = 0, CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
		LPARAM lData, UINT nFlags, HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
		LPARAM lData, UINT nFlags, CBrush* pBrush = NULL);

	BOOL Chord(int x1, int y1, int x2, int y2, int x3, int y3,
		int x4, int y4);
	BOOL Chord(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	void DrawFocusRect(LPCRECT lpRect);
	BOOL Ellipse(int x1, int y1, int x2, int y2);
	BOOL Ellipse(LPCRECT lpRect);
	BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Pie(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polygon(const POINT* lpPoints, int nCount);
	BOOL PolyPolygon(const POINT* lpPoints, const INT* lpPolyCounts, int nCount);
	BOOL Rectangle(int x1, int y1, int x2, int y2);
	BOOL Rectangle(LPCRECT lpRect);
	BOOL RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
	BOOL RoundRect(LPCRECT lpRect, POINT point);

	BOOL PatBlt(int x, int y, int nWidth, int nHeight, DWORD dwRop);
	BOOL BitBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, DWORD dwRop);
	BOOL StretchBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop);
	COLORREF GetPixel(int x, int y) const;
	COLORREF GetPixel(POINT point) const;
	COLORREF SetPixel(int x, int y, COLORREF crColor);
	COLORREF SetPixel(POINT point, COLORREF crColor);
	BOOL FloodFill(int x, int y, COLORREF crColor);
	BOOL ExtFloodFill(int x, int y, COLORREF crColor, UINT nFillType);
	BOOL MaskBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, CBitmap& maskBitmap, int xMask, int yMask,
		DWORD dwRop);
	BOOL PlgBlt(LPPOINT lpPoint, CDC* pSrcDC, int xSrc, int ySrc,
		int nWidth, int nHeight, CBitmap& maskBitmap, int xMask, int yMask);
	BOOL SetPixelV(int x, int y, COLORREF crColor);
	BOOL SetPixelV(POINT point, COLORREF crColor);
   BOOL GradientFill(TRIVERTEX* pVertices, ULONG nVertices,
	  void* pMesh, ULONG nMeshElements, DWORD dwMode);
   BOOL TransparentBlt(int xDest, int yDest, int nDestWidth, int nDestHeight,
	  CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight,
	  UINT clrTransparent);
   BOOL AlphaBlend(int xDest, int yDest, int nDestWidth, int nDestHeight,
	  CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight,
	  BLENDFUNCTION blend);

	virtual BOOL TextOut(int x, int y, LPCTSTR lpszString, int nCount);
			BOOL TextOut(int x, int y, const CString& str);
	virtual BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
				LPCTSTR lpszString, UINT nCount, LPINT lpDxWidths);
			BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
				const CString& str, LPINT lpDxWidths);
	virtual CSize TabbedTextOut(int x, int y, LPCTSTR lpszString, int nCount,
				int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);
			CSize TabbedTextOut(int x, int y, const CString& str,
				int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);

#pragma push_macro("DrawText")
#pragma push_macro("DrawTextEx")
#undef DrawText
#undef DrawTextEx
	virtual int _AFX_FUNCNAME(DrawText)(LPCTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat);
			int _AFX_FUNCNAME(DrawText)(const CString& str, LPRECT lpRect, UINT nFormat);

	virtual int _AFX_FUNCNAME(DrawTextEx)(LPTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
			int _AFX_FUNCNAME(DrawTextEx)(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);

			int DrawText(LPCTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat);
			int DrawText(const CString& str, LPRECT lpRect, UINT nFormat);

			int DrawTextEx(LPTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
			int DrawTextEx(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
#pragma pop_macro("DrawText")
#pragma pop_macro("DrawTextEx")

	CSize GetTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetTextExtent(const CString& str) const;
	CSize GetOutputTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetOutputTextExtent(const CString& str) const;
	CSize GetTabbedTextExtent(LPCTSTR lpszString, int nCount,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetTabbedTextExtent(const CString& str,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(LPCTSTR lpszString, int nCount,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(const CString& str,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	virtual BOOL GrayString(CBrush* pBrush,
		BOOL (CALLBACK* lpfnOutput)(HDC, LPARAM, int), LPARAM lpData,
			int nCount, int x, int y, int nWidth, int nHeight);
	UINT GetTextAlign() const;
	UINT SetTextAlign(UINT nFlags);
	int GetTextFace(_In_ int nCount, _Out_z_cap_post_count_(nCount, return) LPTSTR lpszFacename) const;
	int GetTextFace(CString& rString) const;
#pragma push_macro("GetTextMetrics")
#undef GetTextMetrics
	BOOL _AFX_FUNCNAME(GetTextMetrics)(LPTEXTMETRIC lpMetrics) const;
	BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) const;
#pragma pop_macro("GetTextMetrics")
	BOOL GetOutputTextMetrics(LPTEXTMETRIC lpMetrics) const;
	int SetTextJustification(int nBreakExtra, int nBreakCount);
	int GetTextCharacterExtra() const;
	int SetTextCharacterExtra(int nCharExtra);

	DWORD GetCharacterPlacement(LPCTSTR lpString, int nCount, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;
	DWORD GetCharacterPlacement(CString& str, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;

#if (_WIN32_WINNT >= 0x0500)

	BOOL GetTextExtentExPointI(LPWORD pgiIn, int cgi, int nMaxExtent, LPINT lpnFit, LPINT alpDx, _Out_opt_ LPSIZE lpSize) const;
	BOOL GetTextExtentPointI(LPWORD pgiIn, int cgi, _Out_opt_ LPSIZE lpSize) const;

#endif

	BOOL DrawEdge(LPRECT lpRect, UINT nEdge, UINT nFlags);
	BOOL DrawFrameControl(LPRECT lpRect, UINT nType, UINT nState);

	BOOL ScrollDC(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip,
		CRgn* pRgnUpdate, LPRECT lpRectUpdate);

	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	BOOL GetOutputCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	DWORD SetMapperFlags(DWORD dwFlag);
	CSize GetAspectRatioFilter() const;

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABC lpabc) const;
	DWORD GetFontData(DWORD dwTable, DWORD dwOffset, LPVOID lpData, DWORD cbData) const;
	int GetKerningPairs(int nPairs, LPKERNINGPAIR lpkrnpair) const;
	UINT GetOutlineTextMetrics(UINT cbData, LPOUTLINETEXTMETRIC lpotm) const;
	DWORD GetGlyphOutline(UINT nChar, UINT nFormat, LPGLYPHMETRICS lpgm,
		DWORD cbBuffer, LPVOID lpBuffer, const MAT2* lpmat2) const;

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar,
		LPABCFLOAT lpABCF) const;
	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar,
		float* lpFloatBuffer) const;

	DWORD GetFontLanguageInfo() const;

#if (_WIN32_WINNT >= 0x0500)

	BOOL GetCharABCWidthsI(UINT giFirst, UINT cgi, LPWORD pgi, LPABC lpabc) const;
	BOOL GetCharWidthI(UINT giFirst, UINT cgi, LPWORD pgi, LPINT lpBuffer) const;

#endif

	virtual int Escape(_In_ int nEscape, _In_ int nCount,
		_In_bytecount_(nCount) LPCSTR lpszInData, _In_ LPVOID lpOutData);
	int Escape(_In_ int nEscape, _In_ int nInputSize, _In_bytecount_(nInputSize) LPCSTR lpszInputData,
		_In_ int nOutputSize, _Out_bytecap_(nOutputSize) LPSTR lpszOutputData);
	int DrawEscape(int nEscape, int nInputSize, LPCSTR lpszInputData);

	int StartDoc(LPCTSTR lpszDocName);  // old Win3.0 version
	int StartDoc(LPDOCINFO lpDocInfo);
	int StartPage();
	int EndPage();
	int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int));
	int AbortDoc();
	int EndDoc();

	BOOL PlayMetaFile(HMETAFILE hMF);
	BOOL PlayMetaFile(HENHMETAFILE hEnhMetaFile, LPCRECT lpBounds);
	BOOL AddMetaFileComment(UINT nDataSize, const BYTE* pCommentData);

	BOOL AbortPath();
	BOOL BeginPath();
	BOOL CloseFigure();
	BOOL EndPath();
	BOOL FillPath();
	BOOL FlattenPath();
	BOOL StrokeAndFillPath();
	BOOL StrokePath();
	BOOL WidenPath();
	float GetMiterLimit() const;
	BOOL SetMiterLimit(float fMiterLimit);
	int GetPath(LPPOINT lpPoints, LPBYTE lpTypes, int nCount) const;
	BOOL SelectClipPath(int nMode);

	static CBrush* PASCAL GetHalftoneBrush();
	void DrawDragRect(LPCRECT lpRect, SIZE size,
		LPCRECT lpRectLast, SIZE sizeLast,
		CBrush* pBrush = NULL, CBrush* pBrushLast = NULL);
	void FillSolidRect(LPCRECT lpRect, COLORREF clr);
	void FillSolidRect(int x, int y, int cx, int cy, COLORREF clr);
	void Draw3dRect(LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);
	void Draw3dRect(int x, int y, int cx, int cy,
		COLORREF clrTopLeft, COLORREF clrBottomRight);

public:
	virtual ~CDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	BOOL m_bPrinting;
	HGDIOBJ SelectObject(HGDIOBJ);      // do not use for regions

protected:
	static CGdiObject* PASCAL SelectGdiObject(HDC hDC, HGDIOBJ h);
};

class CPaintDC : public CDC
{
	DECLARE_DYNAMIC(CPaintDC)

public:
	explicit CPaintDC(CWnd* pWnd);   // BeginPaint

protected:
	HWND m_hWnd;
public:
	PAINTSTRUCT m_ps;       // actual paint struct!

public:
	virtual ~CPaintDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CClientDC : public CDC
{
	DECLARE_DYNAMIC(CClientDC)

public:
	explicit CClientDC(CWnd* pWnd);

protected:
	HWND m_hWnd;

public:
	virtual ~CClientDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CWindowDC : public CDC
{
	DECLARE_DYNAMIC(CWindowDC)

public:
	explicit CWindowDC(CWnd* pWnd);

protected:
	HWND m_hWnd;

public:
	virtual ~CWindowDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CImageList : public CObject
{
	DECLARE_DYNCREATE(CImageList)

public:
	CImageList();
	BOOL Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow);
	BOOL Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(CImageList& imagelist1, int nImage1, CImageList& imagelist2,
		int nImage2, int dx, int dy);
	BOOL Create(CImageList* pImageList);

	HIMAGELIST m_hImageList;            // must be first data member
	operator HIMAGELIST() const;
	HIMAGELIST GetSafeHandle() const;

	static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
	static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HIMAGELIST hImageList);
	HIMAGELIST Detach();

	int GetImageCount() const;
	COLORREF SetBkColor(COLORREF cr);
	COLORREF GetBkColor() const;
	BOOL GetImageInfo(int nImage, IMAGEINFO* pImageInfo) const;

	BOOL DeleteImageList();
	BOOL SetImageCount(UINT uNewCount);

	int Add(CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(CBitmap* pbmImage, COLORREF crMask);
	BOOL Remove(int nImage);
	BOOL Replace(int nImage, CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(HICON hIcon);
	int Replace(int nImage, HICON hIcon);
	HICON ExtractIcon(int nImage);
	BOOL Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle);
	BOOL DrawEx(CDC* pDC, int nImage, POINT pt, SIZE sz, COLORREF clrBk, COLORREF clrFg, UINT nStyle);
	BOOL SetOverlayImage(int nImage, int nOverlay);
	BOOL Copy(int iDst, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL Copy(int iDst, CImageList* pSrc, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);
	BOOL DrawIndirect(CDC* pDC, int nImage, POINT pt, SIZE sz, POINT ptOrigin,
			UINT fStyle = ILD_NORMAL, DWORD dwRop = SRCCOPY,
			COLORREF rgbBack = CLR_DEFAULT, COLORREF rgbFore = CLR_DEFAULT,
			DWORD fState = ILS_NORMAL, DWORD Frame = 0, COLORREF crEffect = CLR_DEFAULT);

#ifndef _AFX_NO_OLE_SUPPORT
	BOOL Read(CArchive* pArchive);
	BOOL Write(CArchive* pArchive);
#endif

	BOOL BeginDrag(int nImage, CPoint ptHotSpot);
	static void PASCAL EndDrag();
	static BOOL PASCAL DragMove(CPoint pt);
	BOOL SetDragCursorImage(int nDrag, CPoint ptHotSpot);
	static BOOL PASCAL DragShowNolock(BOOL bShow);
	static CImageList* PASCAL GetDragImage(LPPOINT lpPoint, LPPOINT lpPointHotSpot);
	static BOOL PASCAL DragEnter(CWnd* pWndLock, CPoint point);
	static BOOL PASCAL DragLeave(CWnd* pWndLock);

public:
	virtual ~CImageList();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
};

class CMenu : public CObject
{
	DECLARE_DYNCREATE(CMenu)
public:

	CMenu();

	BOOL CreateMenu();
	BOOL CreatePopupMenu();
	BOOL LoadMenu(LPCTSTR lpszResourceName);
	BOOL LoadMenu(UINT nIDResource);
	BOOL LoadMenuIndirect(const void* lpMenuTemplate);
	BOOL DestroyMenu();

	HMENU m_hMenu;          // must be first data member
	HMENU GetSafeHmenu() const;
	operator HMENU() const;

	static CMenu* PASCAL FromHandle(HMENU hMenu);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HMENU hMenu);
	HMENU Detach();

	BOOL DeleteMenu(UINT nPosition, UINT nFlags);
	BOOL TrackPopupMenu(UINT nFlags, int x, int y,
						CWnd* pWnd, LPCRECT lpRect = 0);
	BOOL TrackPopupMenuEx(UINT fuFlags, int x, int y, CWnd* pWnd, LPTPMPARAMS lptpm);

#if(WINVER >= 0x0500)

	BOOL SetMenuInfo(LPCMENUINFO lpcmi);
	BOOL GetMenuInfo(LPMENUINFO lpcmi) const;

#endif

	BOOL operator==(const CMenu& menu) const;
	BOOL operator!=(const CMenu& menu) const;

	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);
	UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);
	UINT GetMenuItemCount() const;
	UINT GetMenuItemID(int nPos) const;
	UINT GetMenuState(UINT nID, UINT nFlags) const;
	int GetMenuString(_In_ UINT nIDItem, _Out_z_cap_(nMaxCount) LPTSTR lpString, _In_ int nMaxCount,
					_In_ UINT nFlags) const;
	int GetMenuString(UINT nIDItem, CString& rString, UINT nFlags) const;
	BOOL GetMenuItemInfo(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	BOOL SetMenuItemInfo(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	CMenu* GetSubMenu(int nPos) const;
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem,
					const CBitmap* pBmp);
	BOOL InsertMenuItem(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem,
					const CBitmap* pBmp);
	BOOL RemoveMenu(UINT nPosition, UINT nFlags);
	BOOL SetMenuItemBitmaps(UINT nPosition, UINT nFlags,
					const CBitmap* pBmpUnchecked, const CBitmap* pBmpChecked);
	BOOL CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags);
	BOOL SetDefaultItem(UINT uItem, BOOL fByPos = FALSE);
	UINT GetDefaultItem(UINT gmdiFlags, BOOL fByPos = FALSE);

	BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
	DWORD GetMenuContextHelpId() const;

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

public:
	virtual ~CMenu();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	static CMenu* PASCAL CMenu::FromHandlePermanent(HMENU hMenu);
};

struct AFX_MSGMAP_ENTRY;       // declared below after CWnd

struct AFX_MSGMAP
{
	const AFX_MSGMAP* (PASCAL* pfnGetBaseMap)();
	const AFX_MSGMAP_ENTRY* lpEntries;
};

#define DECLARE_MESSAGE_MAP() \
protected: \
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); \
	virtual const AFX_MSGMAP* GetMessageMap() const; \

#define BEGIN_TEMPLATE_MESSAGE_MAP(theClass, type_name, baseClass)			\
	PTM_WARNING_DISABLE														\
	template < typename type_name >											\
	const AFX_MSGMAP* theClass< type_name >::GetMessageMap() const			\
		{ return GetThisMessageMap(); }										\
	template < typename type_name >											\
	const AFX_MSGMAP* PASCAL theClass< type_name >::GetThisMessageMap()		\
	{																		\
		typedef theClass< type_name > ThisClass;							\
		typedef baseClass TheBaseClass;										\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =					\
		{

#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
	PTM_WARNING_DISABLE \
	const AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	const AFX_MSGMAP* PASCAL theClass::GetThisMessageMap() \
	{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{

#define END_MESSAGE_MAP() \
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
		static const AFX_MSGMAP messageMap = \
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
		return &messageMap; \
	}								  \
	PTM_WARNING_RESTORE

#include <afxmsg_.h>

class COleControlSite;

class CDataExchange
{
public:
	BOOL m_bSaveAndValidate;   // TRUE => save and validate data
	CWnd* m_pDlgWnd;           // container usually a dialog

	HWND PrepareCtrl(int nIDC);
	HWND PrepareEditCtrl(int nIDC);
	void Fail();                    // will throw exception

	CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate);

#ifndef _AFX_NO_OCC_SUPPORT
	COleControlSite* PrepareOleCtrl(int nIDC); // for OLE controls in dialog
#endif

   UINT m_idLastControl;      // last control used (for validation)
	BOOL m_bEditLastControl;   // last control was an edit item
};

#include <afxdd_.h>     // standard DDX_ and DDV_ routines

typedef LONG HRESULT;

struct IUnknown;
typedef IUnknown* LPUNKNOWN;

struct IDispatch;
typedef IDispatch* LPDISPATCH;

struct IConnectionPoint;
typedef IConnectionPoint* LPCONNECTIONPOINT;

struct IEnumOLEVERB;
typedef IEnumOLEVERB* LPENUMOLEVERB;

typedef struct _GUID GUID;
typedef GUID IID;
typedef GUID CLSID;
#ifndef _REFCLSID_DEFINED
#define REFCLSID const CLSID &
#endif

typedef long DISPID;
typedef unsigned short VARTYPE;
typedef long SCODE;

typedef WCHAR OLECHAR;
typedef OLECHAR* BSTR;

struct tagDISPPARAMS;
typedef tagDISPPARAMS DISPPARAMS;

struct tagVARIANT;
typedef tagVARIANT VARIANT;

struct ITypeInfo;
typedef ITypeInfo* LPTYPEINFO;

struct ITypeLib;
typedef ITypeLib* LPTYPELIB;

struct IAccessible;
struct IAccessibleProxy;
struct IAccessibleServer;
struct IEnumVARIANT;

struct tagEXCEPINFO;
typedef tagEXCEPINFO EXCEPINFO;

struct AFX_CMDHANDLERINFO;  // info about where the command is handled
struct AFX_EVENT;           // info about an event
class CTypeLibCache;        // cache for OLE type libraries

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_INTERFACEMAP_ENTRY
{
	const void* piid;       // the interface id (IID) (NULL for aggregate)
	size_t nOffset;         // offset of the interface vtable from m_unknown
};

struct AFX_INTERFACEMAP
{
#ifdef _AFXDLL
	const AFX_INTERFACEMAP* (PASCAL* pfnGetBaseMap)(); // NULL is root class
#else
	const AFX_INTERFACEMAP* pBaseMap;
#endif
	const AFX_INTERFACEMAP_ENTRY* pEntry; // map for this class
};

#ifdef _AFXDLL
#define DECLARE_INTERFACE_MAP() \
private: \
	static const AFX_INTERFACEMAP_ENTRY _interfaceEntries[]; \
protected: \
	static const AFX_INTERFACEMAP interfaceMap; \
	static const AFX_INTERFACEMAP* PASCAL GetThisInterfaceMap(); \
	virtual const AFX_INTERFACEMAP* GetInterfaceMap() const; \

#else
#define DECLARE_INTERFACE_MAP() \
private: \
	static const AFX_INTERFACEMAP_ENTRY _interfaceEntries[]; \
protected: \
	static const AFX_INTERFACEMAP interfaceMap; \
	virtual const AFX_INTERFACEMAP* GetInterfaceMap() const; \

#endif

#define METHOD_PROLOGUE(theClass, localClass) \
	theClass* pThis = \
		((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
	AFX_MANAGE_STATE(pThis->m_pModuleState) \
	pThis; // avoid warning from compiler \

#define METHOD_PROLOGUE_(theClass, localClass) \
	theClass* pThis = \
		((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
	pThis; // avoid warning from compiler \

#ifndef _AFX_NO_NESTED_DERIVATION
#define METHOD_PROLOGUE_EX(theClass, localClass) \
	theClass* pThis = ((theClass*)((BYTE*)this - m_nOffset)); \
	AFX_MANAGE_STATE(pThis->m_pModuleState) \
	pThis; // avoid warning from compiler \

#define METHOD_PROLOGUE_EX_(theClass, localClass) \
	theClass* pThis = ((theClass*)((BYTE*)this - m_nOffset)); \
	pThis; // avoid warning from compiler \

#else
#define METHOD_PROLOGUE_EX(theClass, localClass) \
	METHOD_PROLOGUE(theClass, localClass) \

#define METHOD_PROLOGUE_EX_(theClass, localClass) \
	METHOD_PROLOGUE_(theClass, localClass) \

#endif

#define METHOD_MANAGE_STATE(theClass, localClass) \
	METHOD_PROLOGUE_EX(theClass, localClass) \

#define BEGIN_INTERFACE_PART(localClass, baseClass) \
	class X##localClass : public baseClass \
	{ \
	public: \
		STDMETHOD_(ULONG, AddRef)(); \
		STDMETHOD_(ULONG, Release)(); \
		STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppvObj); \

#ifndef _AFX_NO_NESTED_DERIVATION
#define BEGIN_INTERFACE_PART_DERIVE(localClass, baseClass) \
	class X##localClass : public baseClass \
	{ \
	public: \

#else
#define BEGIN_INTERFACE_PART_DERIVE(localClass, baseClass) \
	BEGIN_INTERFACE_PART(localClass, baseClass) \

#endif

#ifndef _AFX_NO_NESTED_DERIVATION
#define INIT_INTERFACE_PART(theClass, localClass) \
		size_t m_nOffset; \
		INIT_INTERFACE_PART_DERIVE(theClass, localClass) \

#define INIT_INTERFACE_PART_DERIVE(theClass, localClass) \
		X##localClass() \
			{ m_nOffset = offsetof(theClass, m_x##localClass); } \

#else
#define INIT_INTERFACE_PART(theClass, localClass)
#define INIT_INTERFACE_PART_DERIVE(theClass, localClass)

#endif

#define END_INTERFACE_PART(localClass) \
	} m_x##localClass; \
	friend class X##localClass; \

struct CInterfacePlaceHolder
{
	DWORD_PTR m_vtbl;   // filled in with USE_INTERFACE_PART
	CInterfacePlaceHolder() { m_vtbl = 0; }
};

#define END_INTERFACE_PART_OPTIONAL(localClass) \
	}; \
	CInterfacePlaceHolder m_x##localClass; \
	friend class X##localClass; \

#ifdef _AFXDLL
#define END_INTERFACE_PART_STATIC END_INTERFACE_PART
#else
#define END_INTERFACE_PART_STATIC END_INTERFACE_PART
#endif

#define USE_INTERFACE_PART(localClass) \
	m_x##localClass.m_vtbl = *(DWORD_PTR*)&X##localClass(); \

#define USE_INTERFACE_PART_STD(localClass) \
	X##localClass tmp##localClass; \
	m_x##localClass.m_vtbl = *(DWORD_PTR*)&tmp##localClass;

#ifdef _AFXDLL
#define BEGIN_INTERFACE_MAP(theClass, theBase) \
	const AFX_INTERFACEMAP* PASCAL theClass::GetThisInterfaceMap() \
		{ return &theClass::interfaceMap; } \
	const AFX_INTERFACEMAP* theClass::GetInterfaceMap() const \
		{ return &theClass::interfaceMap; } \
	AFX_COMDAT const AFX_INTERFACEMAP theClass::interfaceMap = \
		{ &theBase::GetThisInterfaceMap, &theClass::_interfaceEntries[0], }; \
	AFX_COMDAT const AFX_INTERFACEMAP_ENTRY theClass::_interfaceEntries[] = \
	{ \

#else
#define BEGIN_INTERFACE_MAP(theClass, theBase) \
	const AFX_INTERFACEMAP* theClass::GetInterfaceMap() const \
		{ return &theClass::interfaceMap; } \
	AFX_COMDAT const AFX_INTERFACEMAP theClass::interfaceMap = \
		{ &theBase::interfaceMap, &theClass::_interfaceEntries[0], }; \
	AFX_COMDAT const AFX_INTERFACEMAP_ENTRY theClass::_interfaceEntries[] = \
	{ \

#endif

#define INTERFACE_PART(theClass, iid, localClass) \
		{ &iid, offsetof(theClass, m_x##localClass) }, \

#define INTERFACE_AGGREGATE(theClass, theAggr) \
		{ NULL, offsetof(theClass, theAggr) }, \

#define END_INTERFACE_MAP() \
		{ NULL, (size_t)-1 } \
	}; \

#endif //!_AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_DISPMAP_ENTRY;

struct AFX_DISPMAP
{
#ifdef _AFXDLL
	const AFX_DISPMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_DISPMAP* pBaseMap;
#endif
	const AFX_DISPMAP_ENTRY* lpEntries;
	UINT* lpEntryCount;
	DWORD* lpStockPropMask;
};

#ifdef _AFXDLL
#define DECLARE_DISPATCH_MAP() \
private: \
	static const AFX_DISPMAP_ENTRY _dispatchEntries[]; \
	static UINT _dispatchEntryCount; \
	static DWORD _dwStockPropMask; \
protected: \
	static const AFX_DISPMAP dispatchMap; \
	static const AFX_DISPMAP* PASCAL GetThisDispatchMap(); \
	virtual const AFX_DISPMAP* GetDispatchMap() const; \

#else
#define DECLARE_DISPATCH_MAP() \
private: \
	static const AFX_DISPMAP_ENTRY _dispatchEntries[]; \
	static UINT _dispatchEntryCount; \
	static DWORD _dwStockPropMask; \
protected: \
	static const AFX_DISPMAP dispatchMap; \
	virtual const AFX_DISPMAP* GetDispatchMap() const; \

#endif

#endif //!_AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DOCOBJECT_SUPPORT

struct AFX_OLECMDMAP_ENTRY
{
   const GUID* pguid;   // id of the command group
   ULONG       cmdID;   // OLECMD ID
   UINT        nID;     // corresponding WM_COMMAND message ID
};

struct AFX_OLECMDMAP
{
#ifdef _AFXDLL
	const AFX_OLECMDMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_OLECMDMAP* pBaseMap;
#endif
	const AFX_OLECMDMAP_ENTRY* lpEntries;
};

#ifdef _AFXDLL
#define DECLARE_OLECMD_MAP() \
private: \
	static const AFX_OLECMDMAP_ENTRY _commandEntries[]; \
protected: \
	static const AFX_OLECMDMAP commandMap; \
	static const AFX_OLECMDMAP* PASCAL GetThisCommandMap(); \
	virtual const AFX_OLECMDMAP* GetCommandMap() const; \

#else
#define DECLARE_OLECMD_MAP() \
private: \
	static const AFX_OLECMDMAP_ENTRY _commandEntries[]; \
protected: \
	static const AFX_OLECMDMAP commandMap; \
	virtual const AFX_OLECMDMAP* GetCommandMap() const; \

#endif

#ifdef _AFXDLL
#define BEGIN_OLECMD_MAP(theClass, baseClass) \
	const AFX_OLECMDMAP* PASCAL theClass::GetThisCommandMap() \
		{ return &theClass::commandMap; } \
	const AFX_OLECMDMAP* theClass::GetCommandMap() const \
		{ return &theClass::commandMap; } \
	AFX_COMDAT const AFX_OLECMDMAP theClass::commandMap = \
	{ &baseClass::GetThisCommandMap, &theClass::_commandEntries[0] }; \
	AFX_COMDAT const AFX_OLECMDMAP_ENTRY theClass::_commandEntries[] = \
	{ \

#else
#define BEGIN_OLECMD_MAP(theClass, baseClass) \
	const AFX_OLECMDMAP* theClass::GetCommandMap() const \
		{ return &theClass::commandMap; } \
	AFX_COMDAT const AFX_OLECMDMAP theClass::commandMap = \
	{ &baseClass::commandMap, &theClass::_commandEntries[0] }; \
	AFX_COMDAT const AFX_OLECMDMAP_ENTRY theClass::_commandEntries[] = \
	{ \

#endif

#define END_OLECMD_MAP() \
		{NULL, 0, 0} \
	}; \

class COleCmdUI;

#endif //!_AFX_NO_DOCOBJECT_SUPPORT

#ifndef _AFX_NO_OCC_SUPPORT

struct AFX_EVENTSINKMAP_ENTRY;

struct AFX_EVENTSINKMAP
{
#ifdef _AFXDLL
	const AFX_EVENTSINKMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_EVENTSINKMAP* pBaseMap;
#endif
	const AFX_EVENTSINKMAP_ENTRY* lpEntries;
	UINT* lpEntryCount;
};

#ifdef _AFXDLL
#define DECLARE_EVENTSINK_MAP() \
private: \
	static const AFX_EVENTSINKMAP_ENTRY _eventsinkEntries[]; \
	static UINT _eventsinkEntryCount; \
protected: \
	static const AFX_EVENTSINKMAP eventsinkMap; \
	static const AFX_EVENTSINKMAP* PASCAL GetThisEventSinkMap(); \
	virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const; \

#else
#define DECLARE_EVENTSINK_MAP() \
private: \
	static const AFX_EVENTSINKMAP_ENTRY _eventsinkEntries[]; \
	static UINT _eventsinkEntryCount; \
protected: \
	static const AFX_EVENTSINKMAP eventsinkMap; \
	virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const; \

#endif

#endif //!_AFX_NO_OCC_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_CONNECTIONMAP_ENTRY
{
	const void* piid;   // the interface id (IID)
	size_t nOffset;         // offset of the interface vtable from m_unknown
};

struct AFX_CONNECTIONMAP
{
#ifdef _AFXDLL
	const AFX_CONNECTIONMAP* (PASCAL* pfnGetBaseMap)(); // NULL is root class
#else
	const AFX_CONNECTIONMAP* pBaseMap;
#endif
	const AFX_CONNECTIONMAP_ENTRY* pEntry; // map for this class
};

#ifdef _AFXDLL
#define DECLARE_CONNECTION_MAP() \
private: \
	static const AFX_CONNECTIONMAP_ENTRY _connectionEntries[]; \
protected: \
	static const AFX_CONNECTIONMAP connectionMap; \
	static const AFX_CONNECTIONMAP* PASCAL GetThisConnectionMap(); \
	virtual const AFX_CONNECTIONMAP* GetConnectionMap() const; \

#else
#define DECLARE_CONNECTION_MAP() \
private: \
	static const AFX_CONNECTIONMAP_ENTRY _connectionEntries[]; \
protected: \
	static const AFX_CONNECTIONMAP connectionMap; \
	virtual const AFX_CONNECTIONMAP* GetConnectionMap() const; \

#endif

#endif //!_AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_OCC_SUPPORT
class COccManager;      // forward reference (see ..\src\occimpl.h)
#endif

class AFX_NOVTABLE CCmdTarget : public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)
protected:

public:
	CCmdTarget();

	LPDISPATCH GetIDispatch(BOOL bAddRef);
	static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
	BOOL IsResultExpected();

	void EnableAutomation();
	void EnableConnections();

	void BeginWaitCursor();
	void EndWaitCursor();
	void RestoreWaitCursor();       // call after messagebox

#ifndef _AFX_NO_OLE_SUPPORT
	BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
	BOOL DoOleVerb(LONG iVerb, LPMSG lpMsg, HWND hWndParent, LPCRECT lpRect);
#endif

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);

#ifndef _AFX_NO_OLE_SUPPORT
	virtual void OnFinalRelease();
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	virtual BOOL IsInvokeAllowed(DISPID dispid);
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	void EnableTypeLib();
	HRESULT GetTypeInfoOfGuid(LCID lcid, const GUID& guid,
		LPTYPEINFO* ppTypeInfo);
	virtual BOOL GetDispatchIID(IID* pIID);
	virtual UINT GetTypeInfoCount();
	virtual CTypeLibCache* GetTypeLibCache();
	virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB* ppTypeLib);
#endif

public:
	virtual ~CCmdTarget() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
#ifndef _AFX_NO_OLE_SUPPORT
	void GetNotSupported();
	void SetNotSupported();
#endif

protected:
	friend class CView;

	CView* GetRoutingView();
	CFrameWnd* GetRoutingFrame();
	static CView* PASCAL GetRoutingView_();
	static CFrameWnd* PASCAL GetRoutingFrame_();
	DECLARE_MESSAGE_MAP()       // base class - no {{ }} macros

#ifndef _AFX_NO_DOCOBJECT_SUPPORT
	DECLARE_OLECMD_MAP()
	friend class COleCmdUI;
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	DECLARE_DISPATCH_MAP()
	DECLARE_CONNECTION_MAP()
	DECLARE_INTERFACE_MAP()

#ifndef _AFX_NO_OCC_SUPPORT
	DECLARE_EVENTSINK_MAP()
#endif // !_AFX_NO_OCC_SUPPORT

public:
	long m_dwRef;
	LPUNKNOWN m_pOuterUnknown;  // external controlling unknown if != NULL
	DWORD_PTR m_xInnerUnknown;  // place-holder for inner controlling unknown

public:
	void EnableAggregation();       // call to enable aggregation
	void ExternalDisconnect();      // forcibly disconnect
	LPUNKNOWN GetControllingUnknown();

	DWORD InternalQueryInterface(const void*, LPVOID* ppvObj);
	DWORD InternalAddRef();
	DWORD InternalRelease();
	DWORD ExternalQueryInterface(const void*, LPVOID* ppvObj);
	DWORD ExternalAddRef();
	DWORD ExternalRelease();

	LPUNKNOWN GetInterface(const void*);
	LPUNKNOWN QueryAggregates(const void*);

	virtual BOOL OnCreateAggregates();
	virtual LPUNKNOWN GetInterfaceHook(const void*);

protected:
	struct XDispatch
	{
		DWORD_PTR m_vtbl;   // place-holder for IDispatch vtable
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
#endif
	} m_xDispatch;
	BOOL m_bResultExpected;

	void GetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
		VARIANT* pvarResult, UINT* puArgErr);
	SCODE SetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
		DISPPARAMS* pDispParams, UINT* puArgErr);

	static UINT PASCAL GetEntryCount(const AFX_DISPMAP* pDispMap);
	const AFX_DISPMAP_ENTRY* PASCAL GetDispEntry(LONG memid);
	static LONG PASCAL MemberIDFromName(const AFX_DISPMAP* pDispMap, LPCTSTR lpszName);

	static UINT PASCAL GetStackSize(const BYTE* pbParams, VARTYPE vtResult);
#ifdef _SHADOW_DOUBLES
	SCODE PushStackArgs(BYTE* pStack, const BYTE* pbParams,
		void* pResult, VARTYPE vtResult, DISPPARAMS* pDispParams,
		UINT* puArgErr, VARIANT* rgTempVars, UINT nSizeArgs,CVariantBoolConverter* pTempStackArgs = NULL);
#else
	SCODE PushStackArgs(BYTE* pStack, const BYTE* pbParams,
		void* pResult, VARTYPE vtResult, DISPPARAMS* pDispParams,
		UINT* puArgErr, VARIANT* rgTempVars,CVariantBoolConverter* pTempStackArgs = NULL);
#endif
	SCODE CallMemberFunc(const AFX_DISPMAP_ENTRY* pEntry, WORD wFlags,
		VARIANT* pvarResult, DISPPARAMS* pDispParams, UINT* puArgErr);

	friend class COleDispatchImpl;

#ifndef _AFX_NO_OCC_SUPPORT
public:
	BOOL OnEvent(UINT idCtrl, AFX_EVENT* pEvent,
		AFX_CMDHANDLERINFO* pHandlerInfo);
protected:
	const AFX_EVENTSINKMAP_ENTRY* PASCAL GetEventSinkEntry(UINT idCtrl,
		AFX_EVENT* pEvent);
#endif // !_AFX_NO_OCC_SUPPORT

	struct XConnPtContainer
	{
		DWORD_PTR m_vtbl;   // place-holder for IConnectionPointContainer vtable
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
#endif
	} m_xConnPtContainer;

	AFX_MODULE_STATE* m_pModuleState;
	friend class CInnerUnknown;
	friend UINT APIENTRY _AfxThreadEntry(void* pParam);

	virtual BOOL GetExtraConnectionPoints(CPtrArray* pConnPoints);
	virtual LPCONNECTIONPOINT GetConnectionHook(const IID& iid);

	friend class COleConnPtContainer;

#endif //!_AFX_NO_OLE_SUPPORT
};

class CCmdUI        // simple helper class
{
public:
	UINT m_nID;
	UINT m_nIndex;          // menu item or other index

	CMenu* m_pMenu;         // NULL if not a menu
	CMenu* m_pSubMenu;      // sub containing menu item

	CWnd* m_pOther;         // NULL if a menu or not a CWnd

	virtual void Enable(BOOL bOn = TRUE);
	virtual void SetCheck(int nCheck = 1);   // 0, 1 or 2 (indeterminate)
	virtual void SetRadio(BOOL bOn = TRUE);
	virtual void SetText(LPCTSTR lpszText);

	void ContinueRouting();

	CCmdUI();
	BOOL m_bEnableChanged;
	BOOL m_bContinueRouting;
	UINT m_nIndexMax;       // last + 1 for iterating m_nIndex

	CMenu* m_pParentMenu;   // NULL if parent menu not easily determined

	BOOL DoUpdate(CCmdTarget* pTarget, BOOL bDisableIfNoHndler);
};

#ifndef AFX_MSG_CALL
#define AFX_MSG_CALL
#endif
typedef void (AFX_MSG_CALL CCmdTarget::*AFX_PMSG)(void);

enum AFX_DISPMAP_FLAGS
{
	afxDispCustom = 0,
	afxDispStock = 1
};

#pragma warning( disable: 4121 )
struct AFX_DISPMAP_ENTRY
{
	LPCTSTR lpszName;       // member/property name
	long lDispID;           // DISPID (may be DISPID_UNKNOWN)
	LPCSTR lpszParams;      // member parameter description
	WORD vt;                // return value type / or type of property
	AFX_PMSG pfn;           // normal member On<membercall> or, OnGet<property>
	AFX_PMSG pfnSet;        // special member for OnSet<property>
	size_t nPropOffset;     // property offset
	AFX_DISPMAP_FLAGS flags;// flags (e.g. stock/custom)
};
#pragma warning( default: 4121 )

struct AFX_EVENTSINKMAP_ENTRY
{
	AFX_DISPMAP_ENTRY dispEntry;
	UINT nCtrlIDFirst;
	UINT nCtrlIDLast;
};

enum DSCSTATE
{
	dscNoState = 0,
	dscOKToDo,
	dscCancelled,
	dscSyncBefore,
	dscAboutToDo,
	dscFailedToDo,
	dscSyncAfter,
	dscDidEvent
};

enum DSCREASON
{
	dscNoReason = 0,
	dscClose,
	dscCommit,
	dscDelete,
	dscEdit,
	dscInsert,
	dscModify,
	dscMove
};

struct CCreateContext;      // context for creating things
struct CPrintInfo;          // print preview customization info

struct AFX_MSGMAP_ENTRY
{
	UINT nMessage;   // windows message
	UINT nCode;      // control code or WM_NOTIFY code
	UINT nID;        // control ID (or 0 for windows messages)
	UINT nLastID;    // used for entries specifying a range of control id's
	UINT_PTR nSig;       // signature type (action) or pointer to message #
	AFX_PMSG pfn;    // routine to call (or special value)
};

class COleDropTarget;   // for more information see AFXOLE.H
class COleControlContainer;
class COleControlSite;

#define WF_TOOLTIPS         0x0001  // window is enabled for tooltips
#define WF_TEMPHIDE         0x0002  // window is temporarily hidden
#define WF_STAYDISABLED     0x0004  // window should stay disabled
#define WF_MODALLOOP        0x0008  // currently in modal loop
#define WF_CONTINUEMODAL    0x0010  // modal loop should continue running
#define WF_OLECTLCONTAINER  0x0100  // some descendant is an OLE control
#define WF_TRACKINGTOOLTIPS 0x0400  // window is enabled for tracking tooltips

#define WF_STAYACTIVE       0x0020  // look active even though not active
#define WF_NOPOPMSG         0x0040  // ignore WM_POPMESSAGESTRING calls
#define WF_MODALDISABLE     0x0080  // window is disabled
#define WF_KEEPMINIACTIVE   0x0200  // stay activate even though you are deactivated

#define WF_NOWIN32ISDIALOGMSG   0x0800
#define WF_ISWINFORMSVIEWWND    0x1000

#define MLF_NOIDLEMSG       0x0001  // don't send WM_ENTERIDLE messages
#define MLF_NOKICKIDLE      0x0002  // don't send WM_KICKIDLE messages
#define MLF_SHOWONIDLE      0x0004  // show window if not visible at idle time

#define TTF_NOTBUTTON       0x80000000L // no status help on buttondown
#define TTF_ALWAYSTIP       0x40000000L // always show the tip even if not active

class CWnd : public CCmdTarget
{
	DECLARE_DYNCREATE(CWnd)
protected:
	static const MSG* PASCAL GetCurrentMessage();

public:
	HWND m_hWnd;            // must be first data member
	operator HWND() const;
	BOOL operator==(const CWnd& wnd) const;
	BOOL operator!=(const CWnd& wnd) const;

	HWND GetSafeHwnd() const;
	DWORD GetStyle() const;
	DWORD GetExStyle() const;
	BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
	BOOL ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);

	CWnd* GetOwner() const;
	void SetOwner(CWnd* pOwnerWnd);

#if(WINVER >= 0x0500)

	BOOL GetWindowInfo(PWINDOWINFO pwi) const;
	BOOL GetTitleBarInfo(PTITLEBARINFO pti) const;

#endif	// WINVER >= 0x0500

	CWnd();

	static CWnd* PASCAL FromHandle(HWND hWnd);
	static CWnd* PASCAL FromHandlePermanent(HWND hWnd);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HWND hWndNew);
	HWND Detach();

	virtual void PreSubclassWindow();
	BOOL SubclassWindow(HWND hWnd);
	BOOL SubclassDlgItem(UINT nID, CWnd* pParent);
	HWND UnsubclassWindow();

	BOOL ExecuteDlgInit(LPCTSTR lpszResourceName);
	BOOL ExecuteDlgInit(LPVOID lpResource);

public:
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL);

	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		int x, int y, int nWidth, int nHeight,
		HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL);

	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		LPVOID lpParam = NULL);

#ifndef _AFX_NO_OCC_SUPPORT
	BOOL CreateControl(REFCLSID clsid, LPCTSTR pszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID, CFile* pPersist=NULL,
		BOOL bStorage=FALSE, BSTR bstrLicKey=NULL);

	BOOL CreateControl(LPCTSTR pszClass, LPCTSTR pszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID, CFile* pPersist=NULL,
		BOOL bStorage=FALSE, BSTR bstrLicKey=NULL);

   BOOL CreateControl( REFCLSID clsid, LPCTSTR pszWindowName, DWORD dwStyle,
	  const POINT* ppt, const SIZE* psize, CWnd* pParentWnd, UINT nID,
	  CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL );

   BOOL CreateControl(const CControlCreationInfo& creationInfo, DWORD dwStyle,
	const POINT* ppt, const SIZE* psize, CWnd* pParentWnd, UINT nID);

	LPUNKNOWN GetControlUnknown();
	BOOL PaintWindowlessControls(CDC *pDC);
#endif

	virtual BOOL DestroyWindow();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);

	int GetDlgCtrlID() const;
	int SetDlgCtrlID(int nID);
	CWnd* GetDlgItem(int nID) const;
	void GetDlgItem(int nID, HWND* phWnd) const;
	CWnd* GetDescendantWindow(int nID, BOOL bOnlyPerm = FALSE) const;
	void SendMessageToDescendants(UINT message, WPARAM wParam = 0,
		LPARAM lParam = 0, BOOL bDeep = TRUE, BOOL bOnlyPerm = FALSE);
	CFrameWnd* GetParentFrame() const;
	CFrameWnd* EnsureParentFrame() const;
	CWnd* GetTopLevelParent() const;
	CWnd* EnsureTopLevelParent() const;
	CWnd* GetTopLevelOwner() const;
	CWnd* GetParentOwner() const;
	CFrameWnd* GetTopLevelFrame() const;
	static CWnd* PASCAL GetSafeOwner(CWnd* pParent = NULL, HWND* pWndTop = NULL);

#if(WINVER >= 0x0500)

	CWnd* GetAncestor(UINT gaFlags) const;

#endif	// WINVER >= 0x0500

#pragma push_macro("SendMessage")
#undef SendMessage
	LRESULT _AFX_FUNCNAME(SendMessage)(UINT message, WPARAM wParam = 0, LPARAM lParam = 0) const;
	LRESULT SendMessage(UINT message, WPARAM wParam = 0, LPARAM lParam = 0) const;
#pragma pop_macro("SendMessage")
	BOOL PostMessage(UINT message, WPARAM wParam = 0, LPARAM lParam = 0);

	BOOL SendNotifyMessage(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL SendChildNotifyLastMsg(LRESULT* pResult = NULL);

	BOOL DragDetect(POINT pt) const;

	BOOL IsDialogMessage(LPMSG lpMsg);

	void SetWindowText(LPCTSTR lpszString);
	int GetWindowText(_Out_z_cap_post_count_(nMaxCount, return + 1) LPTSTR lpszStringBuf, _In_ int nMaxCount) const;
	void GetWindowText(CString& rString) const;
	int GetWindowTextLength() const;
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

	CMenu* GetMenu() const;
	BOOL SetMenu(CMenu* pMenu);
	void DrawMenuBar();
	CMenu* GetSystemMenu(BOOL bRevert) const;
	BOOL HiliteMenuItem(CMenu* pMenu, UINT nIDHiliteItem, UINT nHilite);

	BOOL IsIconic() const;
	BOOL IsZoomed() const;
	void MoveWindow(int x, int y, int nWidth, int nHeight,
				BOOL bRepaint = TRUE);
	void MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE);
	int SetWindowRgn(HRGN hRgn, BOOL bRedraw);
	int GetWindowRgn(HRGN hRgn) const;

	static AFX_DATA const CWnd wndTop; // SetWindowPos's pWndInsertAfter
	static AFX_DATA const CWnd wndBottom; // SetWindowPos's pWndInsertAfter
	static AFX_DATA const CWnd wndTopMost; // SetWindowPos pWndInsertAfter
	static AFX_DATA const CWnd wndNoTopMost; // SetWindowPos pWndInsertAfter

	BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y,
				int cx, int cy, UINT nFlags);
	UINT ArrangeIconicWindows();
	void BringWindowToTop();
	void GetWindowRect(LPRECT lpRect) const;
	void GetClientRect(LPRECT lpRect) const;

	BOOL GetWindowPlacement(WINDOWPLACEMENT* lpwndpl) const;
	BOOL SetWindowPlacement(const WINDOWPLACEMENT* lpwndpl);

	void ClientToScreen(LPPOINT lpPoint) const;
	void ClientToScreen(LPRECT lpRect) const;
	void ScreenToClient(LPPOINT lpPoint) const;
	void ScreenToClient(LPRECT lpRect) const;
	void MapWindowPoints(CWnd* pwndTo, LPPOINT lpPoint, UINT nCount) const;
	void MapWindowPoints(CWnd* pwndTo, LPRECT lpRect) const;

	CDC* BeginPaint(LPPAINTSTRUCT lpPaint);
	void EndPaint(LPPAINTSTRUCT lpPaint);
	CDC* GetDC();
	CDC* GetWindowDC();
	int ReleaseDC(CDC* pDC);
	void Print(CDC* pDC, DWORD dwFlags) const;
	void PrintClient(CDC* pDC, DWORD dwFlags) const;

	void UpdateWindow();
	void SetRedraw(BOOL bRedraw = TRUE);
	BOOL GetUpdateRect(LPRECT lpRect, BOOL bErase = FALSE);
	int GetUpdateRgn(CRgn* pRgn, BOOL bErase = FALSE);
	void Invalidate(BOOL bErase = TRUE);
	void InvalidateRect(LPCRECT lpRect, BOOL bErase = TRUE);
	void InvalidateRgn(CRgn* pRgn, BOOL bErase = TRUE);
	void ValidateRect(LPCRECT lpRect);
	void ValidateRgn(CRgn* pRgn);
	BOOL ShowWindow(int nCmdShow);
	BOOL IsWindowVisible() const;
	void ShowOwnedPopups(BOOL bShow = TRUE);

	CDC* GetDCEx(CRgn* prgnClip, DWORD flags);
	BOOL LockWindowUpdate();
	void UnlockWindowUpdate();
	BOOL RedrawWindow(LPCRECT lpRectUpdate = NULL,
		CRgn* prgnUpdate = NULL,
		UINT flags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
	BOOL EnableScrollBar(int nSBFlags, UINT nArrowFlags = ESB_ENABLE_BOTH);

	BOOL DrawAnimatedRects(int idAni, CONST RECT *lprcFrom, CONST RECT *lprcTo);
	BOOL DrawCaption(CDC* pDC, LPCRECT lprc, UINT uFlags);

#if(WINVER >= 0x0500)

	BOOL AnimateWindow(DWORD dwTime, DWORD dwFlags);

#endif	// WINVER >= 0x0500

#if(_WIN32_WINNT >= 0x0501)

	BOOL PrintWindow(CDC* pDC, UINT nFlags) const;

#endif	// _WIN32_WINNT >= 0x0501

#if(_WIN32_WINNT >= 0x0500)

	BOOL SetLayeredWindowAttributes(COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
	BOOL UpdateLayeredWindow(CDC* pDCDst, POINT *pptDst, SIZE *psize,
		CDC* pDCSrc, POINT *pptSrc, COLORREF crKey, BLENDFUNCTION *pblend, DWORD dwFlags);

#endif	// _WIN32_WINNT >= 0x0500

#if(_WIN32_WINNT >= 0x0501)

	BOOL GetLayeredWindowAttributes(COLORREF *pcrKey, BYTE *pbAlpha, DWORD *pdwFlags) const;

#endif	// _WIN32_WINNT >= 0x0501

	UINT_PTR SetTimer(UINT_PTR nIDEvent, UINT nElapse,
		void (CALLBACK* lpfnTimer)(HWND, UINT, UINT_PTR, DWORD));
	BOOL KillTimer(UINT_PTR nIDEvent);

	BOOL EnableToolTips(BOOL bEnable = TRUE);
	BOOL EnableTrackingToolTips(BOOL bEnable = TRUE);
	static void PASCAL CancelToolTips(BOOL bKeys = FALSE);
	void FilterToolTipMessage(MSG* pMsg);

	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;

	BOOL IsWindowEnabled() const;
	BOOL EnableWindow(BOOL bEnable = TRUE);

	static CWnd* PASCAL GetActiveWindow();
	CWnd* SetActiveWindow();

	BOOL SetForegroundWindow();
	static CWnd* PASCAL GetForegroundWindow();

	static CWnd* PASCAL GetCapture();
	CWnd* SetCapture();
	static CWnd* PASCAL GetFocus();
	CWnd* SetFocus();

	static CWnd* PASCAL GetDesktopWindow();

	void CloseWindow();
	BOOL OpenIcon();

	void CheckDlgButton(int nIDButton, UINT nCheck);
	void CheckRadioButton(int nIDFirstButton, int nIDLastButton,
					int nIDCheckButton);
	int GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton) const;
	int DlgDirList(_Inout_z_ LPTSTR lpPathSpec, _In_ int nIDListBox,
					_In_ int nIDStaticPath, _In_ UINT nFileType);
	int DlgDirListComboBox(_Inout_z_ LPTSTR lpPathSpec, _In_ int nIDComboBox,
					_In_ int nIDStaticPath, _In_ UINT nFileType);
	AFX_DEPRECATED("CWnd::DlgDirSelect(lpszOut, nControlId) is no longer supported. Instead, use CWnd::DlgDirSelect(lpszOut, nSize, nControlId)")
		BOOL DlgDirSelect(_Out_z_cap_c_(_MAX_PATH) LPTSTR lpString, _In_ int nIDListBox);
	BOOL DlgDirSelect(_Out_z_cap_(nSize) LPTSTR lpString, _In_ int nSize, _In_ int nIDListBox);
	AFX_DEPRECATED("CWnd::DlgDirSelectComboBox(lpszOut, nControlId) is no longer supported. Instead, use CWnd::DlgDirSelectComboBox(lpszOut, nSize, nControlId)")
		BOOL DlgDirSelectComboBox(_Out_z_cap_c_(_MAX_PATH) LPTSTR lpString, _In_ int nIDComboBox);
	BOOL DlgDirSelectComboBox(_Out_z_cap_(nSize) LPTSTR lpString, _In_ int nSize, _In_ int nIDComboBox);

	UINT GetDlgItemInt(int nID, BOOL* lpTrans = NULL,
					BOOL bSigned = TRUE) const;
	int GetDlgItemText(_In_ int nID, _Out_z_cap_post_count_(nMaxCount, return + 1) LPTSTR lpStr, _In_ int nMaxCount) const;
	int GetDlgItemText(int nID, CString& rString) const;
	CWnd* GetNextDlgGroupItem(CWnd* pWndCtl, BOOL bPrevious = FALSE) const;
	COleControlSiteOrWnd* GetNextDlgGroupItem(COleControlSiteOrWnd *pCurSiteOrWnd = NULL) const;
	COleControlSiteOrWnd* GetPrevDlgGroupItem(COleControlSiteOrWnd *pCurSiteOrWnd = NULL) const;
	void RemoveRadioCheckFromGroup(const COleControlSiteOrWnd *pSiteOrWnd) const;
	CWnd* GetNextDlgTabItem(CWnd* pWndCtl, BOOL bPrevious = FALSE) const;
	COleControlSiteOrWnd* GetNextDlgTabItem(COleControlSiteOrWnd *pCurSiteOrWnd, BOOL bPrevious) const;
	UINT IsDlgButtonChecked(int nIDButton) const;
	LRESULT SendDlgItemMessage(int nID, UINT message,
					WPARAM wParam = 0, LPARAM lParam = 0);
	void SetDlgItemInt(int nID, UINT nValue, BOOL bSigned = TRUE);
	void SetDlgItemText(int nID, LPCTSTR lpszString);
	POSITION FindSiteOrWnd(const COleControlSiteOrWnd *pSiteOrWnd) const;
	POSITION FindSiteOrWndWithFocus() const;

	int GetScrollPos(int nBar) const;
	void GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const;
	void ScrollWindow(int xAmount, int yAmount,
					LPCRECT lpRect = NULL,
					LPCRECT lpClipRect = NULL);
	int SetScrollPos(int nBar, int nPos, BOOL bRedraw = TRUE);
	void SetScrollRange(int nBar, int nMinPos, int nMaxPos,
			BOOL bRedraw = TRUE);
	void ShowScrollBar(UINT nBar, BOOL bShow = TRUE);
	void EnableScrollBarCtrl(int nBar, BOOL bEnable = TRUE);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;

	int ScrollWindowEx(int dx, int dy,
				LPCRECT lpRectScroll, LPCRECT lpRectClip,
				CRgn* prgnUpdate, LPRECT lpRectUpdate, UINT flags);
	BOOL SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo,
		BOOL bRedraw = TRUE);
	BOOL GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL);
	int GetScrollLimit(int nBar);

#if(WINVER >= 0x0500)

	BOOL GetScrollBarInfo(LONG idObject, PSCROLLBARINFO psbi) const;

#endif	// WINVER >= 0x0500

	CWnd* ChildWindowFromPoint(POINT point) const;
	CWnd* ChildWindowFromPoint(POINT point, UINT nFlags) const;
	static CWnd* PASCAL FindWindow(LPCTSTR lpszClassName, LPCTSTR lpszWindowName);
	static CWnd* FindWindowEx(HWND hwndParent, HWND hwndChildAfter, LPCTSTR lpszClass, LPCTSTR lpszWindow);

	CWnd* GetNextWindow(UINT nFlag = GW_HWNDNEXT) const;
	CWnd* GetTopWindow() const;

	CWnd* GetWindow(UINT nCmd) const;
	CWnd* GetLastActivePopup() const;

	BOOL IsChild(const CWnd* pWnd) const;
	CWnd* GetParent() const;
	CWnd* SetParent(CWnd* pWndNewParent);
	static CWnd* PASCAL WindowFromPoint(POINT point);

	BOOL FlashWindow(BOOL bInvert);
#pragma push_macro("MessageBox")
#undef MessageBox
	int _AFX_FUNCNAME(MessageBox)(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
			UINT nType = MB_OK);
	int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
			UINT nType = MB_OK);
#pragma pop_macro("MessageBox")

#if(WINVER >= 0x0500)

	BOOL FlashWindowEx(DWORD dwFlags, UINT  uCount, DWORD dwTimeout);

#endif	// WINVER >= 0x0500

	BOOL ChangeClipboardChain(HWND hWndNext);
	HWND SetClipboardViewer();
	BOOL OpenClipboard();
	static CWnd* PASCAL GetClipboardOwner();
	static CWnd* PASCAL GetClipboardViewer();
	static CWnd* PASCAL GetOpenClipboardWindow();

	void CreateCaret(CBitmap* pBitmap);
	void CreateSolidCaret(int nWidth, int nHeight);
	void CreateGrayCaret(int nWidth, int nHeight);
	static CPoint PASCAL GetCaretPos();
	static void PASCAL SetCaretPos(POINT point);
	void HideCaret();
	void ShowCaret();

	void DragAcceptFiles(BOOL bAccept = TRUE);

	HICON SetIcon(HICON hIcon, BOOL bBigIcon);
	HICON GetIcon(BOOL bBigIcon) const;

	BOOL SetWindowContextHelpId(DWORD dwContextHelpId);
	DWORD GetWindowContextHelpId() const;

public:
	BOOL UpdateData(BOOL bSaveAndValidate = TRUE);

	afx_msg void OnHelp();          // F1 (uses current context)
	afx_msg void OnHelpIndex();     // ID_HELP_INDEX
	afx_msg void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
	afx_msg void OnHelpUsing();     // ID_HELP_USING
	virtual void WinHelp(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);
	virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd = 0x000F);
	virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);

public:
	enum RepositionFlags
		{ reposDefault = 0, reposQuery = 1, reposExtra = 2, reposNoPosLeftOver=0x8000 };
	void RepositionBars(UINT nIDFirst, UINT nIDLast, UINT nIDLeftOver,
		UINT nFlag = reposDefault, LPRECT lpRectParam = NULL,
		LPCRECT lpRectClient = NULL, BOOL bStretch = TRUE);

	void UpdateDialogControls(CCmdTarget* pTarget, BOOL bDisableIfNoHndler);
	void CenterWindow(CWnd* pAlternateOwner = NULL);
	int RunModalLoop(DWORD dwFlags = 0);
	virtual BOOL ContinueModal();
	virtual void EndModalLoop(int nResult);

#ifndef _AFX_NO_OCC_SUPPORT
   COleControlSite* GetOleControlSite(UINT idControl) const;
	void AFX_CDECL InvokeHelper(DISPID dwDispID, WORD wFlags,
		VARTYPE vtRet, void* pvRet, const BYTE* pbParamInfo, ...);
	void AFX_CDECL SetProperty(DISPID dwDispID, VARTYPE vtProp, ...);
	void GetProperty(DISPID dwDispID, VARTYPE vtProp, void* pvProp) const;
	IUnknown* GetDSCCursor();
	void BindDefaultProperty(DISPID dwDispID, VARTYPE vtProp, LPCTSTR szFieldName, CWnd* pDSCWnd);
	void BindProperty(DISPID dwDispId, CWnd* pWndDSC);
#endif

public :
	void EnableActiveAccessibility();
	void NotifyWinEvent(DWORD event, LONG idObjectType, LONG idObject);

protected :
	bool m_bEnableActiveAccessibility;
	IAccessible* m_pStdObject;
	typedef VOID (WINAPI *PFNNOTIFYWINEVENT)(DWORD, HWND, LONG, LONG);
	static PFNNOTIFYWINEVENT m_pfnNotifyWinEvent;
	friend BOOL AFXAPI AfxWinInit(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
		_In_z_ LPTSTR lpCmdLine, _In_ int nCmdShow);

protected:
	IAccessibleProxy* m_pProxy;
	afx_msg LRESULT OnGetObject(WPARAM, LPARAM);

#ifndef _AFX_NO_OLE_SUPPORT
	DECLARE_INTERFACE_MAP()
#endif

	class XAccessible //: public IAccessible
	{
	public:
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
		XAccessible()
			{ m_nOffset = offsetof(CWnd, m_xAccessible); }
#endif
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
		virtual HRESULT __stdcall QueryInterface(REFIID iid, LPVOID* ppvObj);
		virtual HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
		virtual HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR *, UINT, LCID, DISPID *);
		virtual HRESULT __stdcall GetTypeInfoCount(unsigned int *);
		virtual HRESULT __stdcall GetTypeInfo(unsigned int, LCID, ITypeInfo**);
		virtual HRESULT __stdcall get_accParent(IDispatch **ppdispParent);
		virtual HRESULT __stdcall get_accChildCount(long *pcountChildren);
		virtual HRESULT __stdcall get_accChild(VARIANT varChild, IDispatch **ppdispChild);
		virtual HRESULT __stdcall get_accName(VARIANT varChild, BSTR *pszName);
		virtual HRESULT __stdcall get_accValue(VARIANT varChild, BSTR *pszValue);
		virtual HRESULT __stdcall get_accDescription(VARIANT varChild, BSTR *pszDescription);
		virtual HRESULT __stdcall get_accRole(VARIANT varChild, VARIANT *pvarRole);
		virtual HRESULT __stdcall get_accState(VARIANT varChild, VARIANT *pvarState);
		virtual HRESULT __stdcall get_accHelp(VARIANT varChild, BSTR *pszHelp);
		virtual HRESULT __stdcall get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
		virtual HRESULT __stdcall get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
		virtual HRESULT __stdcall get_accFocus(VARIANT *pvarChild);
		virtual HRESULT __stdcall get_accSelection(VARIANT *pvarChildren);
		virtual HRESULT __stdcall get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
		virtual HRESULT __stdcall accSelect(long flagsSelect, VARIANT varChild);
		virtual HRESULT __stdcall accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
		virtual HRESULT __stdcall accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
		virtual HRESULT __stdcall accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
		virtual HRESULT __stdcall accDoDefaultAction(VARIANT varChild);
		virtual HRESULT __stdcall put_accName(VARIANT varChild, BSTR szName);
		virtual HRESULT __stdcall put_accValue(VARIANT varChild, BSTR szValue);
	} m_xAccessible;
	friend class XAccessible;

	class XAccessibleServer //: public IAccessibleServer
	{
	public:
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
		XAccessibleServer()
			{ m_nOffset = offsetof(CWnd, m_xAccessibleServer); }
#endif
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
		virtual HRESULT __stdcall QueryInterface(REFIID iid, LPVOID* ppvObj);
		virtual HRESULT __stdcall SetProxy(IAccessibleProxy *pProxy);
		virtual HRESULT __stdcall GetHWND(HWND *phWnd);
		virtual HRESULT __stdcall GetEnumVariant(IEnumVARIANT **ppEnumVariant);
	} m_xAccessibleServer;
	friend class XAccessibleServer;

public :
	virtual HRESULT EnsureStdObj();

	virtual HRESULT get_accParent(IDispatch **ppdispParent);
	virtual HRESULT get_accChildCount(long *pcountChildren);
	virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
	virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accHelp(VARIANT varChild, BSTR *pszHelp);
	virtual HRESULT get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
	virtual HRESULT get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
	virtual HRESULT get_accFocus(VARIANT *pvarChild);
	virtual HRESULT get_accSelection(VARIANT *pvarChildren);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT accSelect(long flagsSelect, VARIANT varChild);
	virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
	virtual HRESULT accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
	virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual HRESULT put_accName(VARIANT varChild, BSTR szName);
	virtual HRESULT put_accValue(VARIANT varChild, BSTR szValue);
	virtual HRESULT SetProxy(IAccessibleProxy *pProxy);
	virtual HRESULT CreateAccessibleProxy(WPARAM wParam, LPARAM lParam, LRESULT *pResult);

	long GetWindowLessChildCount();
	long GetWindowedChildCount();
	long GetAccessibleChildCount();
	HRESULT GetAccessibleChild(VARIANT varChild, IDispatch** ppdispChild);
	HRESULT GetAccessibleName(VARIANT varChild, BSTR* pszName);
	HRESULT GetAccessibilityLocation(VARIANT varChild, long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight);
	HRESULT GetAccessibilityHitTest(long xLeft, long yTop, VARIANT *pvarChild);

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	afx_msg LRESULT OnActivateTopLevel(WPARAM, LPARAM);
	afx_msg void OnCancelMode();
	afx_msg void OnChildActivate();
	afx_msg void OnClose();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pos);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnDestroy();
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnSyncPaint();
	afx_msg void OnParentNotify(UINT message, LPARAM lParam);
	afx_msg UINT OnNotifyFormat(CWnd* pWnd, UINT nCommand);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnQueryEndSession();
	afx_msg BOOL OnQueryNewPalette();
	afx_msg BOOL OnQueryOpen();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTCard(UINT idAction, DWORD dwActionData);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnSessionChange(UINT nSessionState, UINT nId);

	afx_msg void OnChangeUIState(UINT nAction, UINT nUIElement);
	afx_msg void OnUpdateUIState(UINT nAction, UINT nUIElement);
	afx_msg UINT OnQueryUIState();

	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcDestroy();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseHover(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseLeave();
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnNcRButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcXButtonDown(short zHitTest, UINT nButton, CPoint point);
	afx_msg void OnNcXButtonUp(short zHitTest, UINT nButton, CPoint point);
	afx_msg void OnNcXButtonDblClk(short zHitTest, UINT nButton, CPoint point);

	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnPaletteIsChanging(CWnd* pRealizeWnd);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnSysDeadChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnAppCommand(CWnd* pWnd, UINT nCmd, UINT nDevice, UINT nKey);
#if(_WIN32_WINNT >= 0x0501)
	afx_msg void OnRawInput(UINT nInputCode, HRAWINPUT hRawInput);
#endif
	afx_msg void OnCompacting(UINT nCpuTime);
	afx_msg void OnDevModeChange(_In_z_ LPTSTR lpDeviceName);
	afx_msg void OnFontChange();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg void OnSpoolerStatus(UINT nStatus, UINT nJobs);
	afx_msg void OnSysColorChange();
	afx_msg void OnTimeChange();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnWinIniChange(LPCTSTR lpszSection);
	afx_msg UINT OnPowerBroadcast(UINT nPowerEvent, UINT nEventData);
	afx_msg void OnUserChanged();
	afx_msg void OnInputLangChange(UINT nCharSet, UINT nLocaleId);
	afx_msg void OnInputLangChangeRequest(UINT nFlags, UINT nLocaleId);
	afx_msg void OnInputDeviceChange(unsigned short nFlags);

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDeadChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUniChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnXButtonDblClk(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonUp(UINT nFlags, UINT nButton, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnInitMenu(CMenu* pMenu);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnUnInitMenuPopup(CMenu* pPopupMenu, UINT nFlags);

	afx_msg void OnAskCbFormatName(_In_ UINT nMaxCount, _Out_z_cap_(nMaxCount) LPTSTR lpszString);
	afx_msg void OnChangeCbChain(HWND hWndRemove, HWND hWndAfter);
	afx_msg void OnDestroyClipboard();
	afx_msg void OnDrawClipboard();
	afx_msg void OnHScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos);
	afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
	afx_msg void OnRenderAllFormats();
	afx_msg void OnRenderFormat(UINT nFormat);
	afx_msg void OnSizeClipboard(CWnd* pClipAppWnd, HGLOBAL hRect);
	afx_msg void OnVScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos);
	afx_msg void OnClipboardUpdate();

	afx_msg int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	afx_msg void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg int OnCharToItem(UINT nChar, CListBox* pListBox, UINT nIndex);
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);

	afx_msg void OnMDIActivate(BOOL bActivate,
		CWnd* pActivateWnd, CWnd* pDeactivateWnd);

	afx_msg void OnEnterMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg void OnExitMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg void OnMenuRButtonUp(UINT nPos, CMenu* pMenu);
	afx_msg UINT OnMenuDrag(UINT nPos, CMenu* pMenu);
#if(WINVER >= 0x0500)
	afx_msg UINT OnMenuGetObject(MENUGETOBJECTINFO* pMenuGetObjectInfo);
#endif
	afx_msg void OnMenuCommand(UINT nPos, CMenu* pMenu);
	afx_msg void OnNextMenu(UINT nKey, LPMDINEXTMENU lpMdiNextMenu);

	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	afx_msg void OnMoving(UINT nSide, LPRECT lpRect);
	afx_msg void OnEnterSizeMove();
	afx_msg void OnExitSizeMove();
	afx_msg void OnCaptureChanged(CWnd* pWnd);
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD_PTR dwData);

	afx_msg void OnCompositionChanged();
	afx_msg void OnNcRenderingChanged(BOOL bIsRendering);
	afx_msg void OnColorizationColorChanged(DWORD dwColorizationColor, BOOL bOpacity);
	afx_msg void OnWindowMaximizedChange(BOOL bIsMaximized);

protected:
	virtual WNDPROC* GetSuperWndProcAddr();

	virtual void DoDataExchange(CDataExchange* pDX);

public:
	virtual void BeginModalState();
	virtual void EndModalState();

	virtual BOOL PreTranslateMessage(MSG* pMsg);

#ifndef _AFX_NO_OCC_SUPPORT
	virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid,
		VARIANT* pvar);
#endif

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	LRESULT Default();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	virtual void PostNcDestroy();

	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL ReflectChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	static BOOL PASCAL ReflectLastMsg(HWND hWndChild, LRESULT* pResult = NULL);

public:
	virtual ~CWnd();
	virtual BOOL CheckAutoCenter();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	static BOOL PASCAL GrayCtlColor(HDC hDC, HWND hWnd, UINT nCtlColor,
		HBRUSH hbrGray, COLORREF clrText);

	BOOL HandleFloatingSysCommand(UINT nID, LPARAM lParam);
	BOOL IsTopParentActive() const;
	void ActivateTopParent();
	static BOOL PASCAL WalkPreTranslateTree(HWND hWndStop, MSG* pMsg);
	static CWnd* PASCAL GetDescendantWindow(HWND hWnd, int nID,
		BOOL bOnlyPerm);
	static void PASCAL SendMessageToDescendants(HWND hWnd, UINT message,
		WPARAM wParam, LPARAM lParam, BOOL bDeep, BOOL bOnlyPerm);
	virtual BOOL IsFrameWnd() const; // IsKindOf(RUNTIME_CLASS(CFrameWnd)))
	virtual void OnFinalRelease();
	BOOL PreTranslateInput(LPMSG lpMsg);
	static BOOL PASCAL ModifyStyle(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
		UINT nFlags);
	static BOOL PASCAL ModifyStyleEx(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
		UINT nFlags);
	static void PASCAL _FilterToolTipMessage(MSG* pMsg, CWnd* pWnd);
	BOOL _EnableToolTips(BOOL bEnable, UINT nFlag);
	static HWND PASCAL GetSafeOwner_(HWND hWnd, HWND* pWndTop);
	void PrepareForHelp();

	COleControlContainer* GetControlContainer();

public:
	HWND m_hWndOwner;   // implementation of SetOwner and GetOwner
	UINT m_nFlags;      // see WF_ flags above

protected:
	WNDPROC m_pfnSuper; // for subclassing of controls
	static const UINT m_nMsgDragList;
	int m_nModalResult; // for return values from CWnd::RunModalLoop

	COleDropTarget* m_pDropTarget;  // for automatic cleanup of drop target
	friend class COleDropTarget;
	friend class CFrameWnd;

	BOOL CreateDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd);
	BOOL CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
		HINSTANCE hInst);

#ifndef _AFX_NO_OCC_SUPPORT
	COleControlContainer* m_pCtrlCont;  // for containing OLE controls
	COleControlSite* m_pCtrlSite;       // for wrapping an OLE control
	friend class COccManager;
	friend class COleControlSite;
	friend class COleControlContainer;
	BOOL InitControlContainer(BOOL bCreateFromResource=FALSE);
   virtual BOOL CreateControlContainer(COleControlContainer** ppContainer);
   virtual BOOL CreateControlSite(COleControlContainer* pContainer,
	  COleControlSite** ppSite, UINT nID, REFCLSID clsid);
	virtual BOOL SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO* pOccDialogInfo);
	virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
	void AttachControlSite(CHandleMap* pMap);
public:
	void AttachControlSite(CWnd* pWndParent, UINT nIDC = 0);
	COleControlSite* GetControlSite() const
	{
		return m_pCtrlSite;
	}
#endif

protected:
	friend LRESULT CALLBACK _AfxSendMsgHook(int, WPARAM, LPARAM);
	friend void AFXAPI _AfxStandardSubclass(HWND);
	friend LRESULT CALLBACK _AfxCbtFilterHook(int, WPARAM, LPARAM);
	friend LRESULT AFXAPI AfxCallWndProc(CWnd*, HWND, UINT, WPARAM, LPARAM);

	afx_msg LRESULT OnNTCtlColor(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisplayChange(WPARAM, LPARAM);
	afx_msg LRESULT OnDragList(WPARAM, LPARAM);

	template <class TReturnType, class TCchType >
	TReturnType EnlargeBufferGetText(_In_ TReturnType errCode, LPTSTR& pszText, TCchType& cch, TCchType cchBegin, TCchType cchEnd, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		ENSURE(::IsWindow(m_hWnd));
		ENSURE(cchBegin < cchEnd);
		ENSURE(cchEnd <= INT_MAX); // CString only support up to INT_MAX
		TReturnType retCode = errCode;
		strOut = CString("");
		cch = cchBegin;
		do
		{
			pszText = strOut.GetBufferSetLength(cch);
			retCode = static_cast<TReturnType>(this->SendMessage(uMsg, wParam, lParam));
			strOut.ReleaseBuffer();
			pszText = NULL;

			if (retCode == errCode)
			{
				strOut = CString("");
				cch=0;
				break;
			}
			if (static_cast<TCchType>(strOut.GetLength()) < cch-1)
			{
				cch = strOut.GetLength();
				break;
			}
		}
		while( (::ATL::AtlMultiply(&cch, cch, 2) == S_OK) && (cch < cchEnd));
		return retCode;
	}

	template <class TReturnType>
	inline TReturnType EnlargeBufferGetText(TReturnType errCode, LPTSTR& pszText, int& pcch, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		return EnlargeBufferGetText<TReturnType, int>(errCode, pszText, pcch, 256, INT_MAX, uMsg, wParam, lParam, strOut);
	}

	template <class TReturnType>
	inline TReturnType EnlargeBufferGetText(TReturnType errCode, LPTSTR& pszText, UINT& pcch, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		return EnlargeBufferGetText<TReturnType, UINT>(errCode, pszText, pcch, 256, INT_MAX, uMsg, wParam, lParam, strOut);
	}

	DECLARE_MESSAGE_MAP()

private:
	CWnd(HWND hWnd);    // just for special initialization
};

LPCTSTR AFXAPI AfxRegisterWndClass(UINT nClassStyle,
	HCURSOR hCursor = 0, HBRUSH hbrBackground = 0, HICON hIcon = 0);

BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);

BOOL AFXAPI AfxInitRichEdit();
BOOL AFXAPI AfxInitRichEdit2();

LRESULT CALLBACK AfxWndProc(HWND, UINT, WPARAM, LPARAM);

WNDPROC AFXAPI AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

typedef void (AFX_MSG_CALL CWnd::*AFX_PMSGW)(void);

typedef void (AFX_MSG_CALL CWinThread::*AFX_PMSGT)(void);

class CDialog : public CWnd
{
	DECLARE_DYNAMIC(CDialog)

public:
	CDialog();

	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	virtual BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd = NULL,
		void* lpDialogInit = NULL);
	virtual BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd = NULL);

public:
	explicit CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	explicit CDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	BOOL InitModalIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd = NULL,
		void* lpDialogInit = NULL);
	BOOL InitModalIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd = NULL);

public:
	void MapDialogRect(LPRECT lpRect) const;
	void SetHelpID(UINT nIDR);

public:
	virtual INT_PTR DoModal();

	void NextDlgCtrl() const;
	void PrevDlgCtrl() const;
	void GotoDlgCtrl(CWnd* pWndCtrl);

	void SetDefID(UINT nID);
	DWORD GetDefID() const;

	void EndDialog(int nResult);

	virtual BOOL OnInitDialog();
	virtual void OnSetFont(CFont* pFont);
protected:
	virtual void OnOK();
	virtual void OnCancel();

public:
	virtual ~CDialog();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual BOOL CheckAutoCenter();

protected:
	UINT m_nIDHelp;                 // Help ID (0 for none, see HID_BASE_RESOURCE)

	LPCTSTR m_lpszTemplateName;     // name or MAKEINTRESOURCE
	HGLOBAL m_hDialogTemplate;      // indirect (m_lpDialogTemplate == NULL)
	LPCDLGTEMPLATE m_lpDialogTemplate;  // indirect if (m_lpszTemplateName == NULL)
	void* m_lpDialogInit;           // DLGINIT resource data
	CWnd* m_pParentWnd;             // parent/owner window
	HWND m_hWndTop;                 // top level parent window (may be disabled)

#ifndef _AFX_NO_OCC_SUPPORT
	_AFX_OCC_DIALOG_INFO* m_pOccDialogInfo;
	virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
	virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
#endif
	virtual void PreInitDialog();

	HWND PreModal();
	void PostModal();

	BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
		void* lpDialogInit, HINSTANCE hInst);
	BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd,
		HINSTANCE hInst);

protected:
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT HandleInitDialog(WPARAM, LPARAM);
	afx_msg LRESULT HandleSetFont(WPARAM, LPARAM);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

#define CModalDialog    CDialog

class CStatic : public CWnd
{
	DECLARE_DYNAMIC(CStatic)

public:
	CStatic();
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	HICON SetIcon(HICON hIcon);
	HICON GetIcon() const;

	HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
	HENHMETAFILE GetEnhMetaFile() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	HCURSOR SetCursor(HCURSOR hCursor);
	HCURSOR GetCursor();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

public:
	virtual ~CStatic();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

class CButton : public CWnd
{
	DECLARE_DYNAMIC(CButton)

public:
	CButton();
	virtual BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID);

	UINT GetState() const;
	void SetState(BOOL bHighlight);
	int GetCheck() const;
	void SetCheck(int nCheck);
	UINT GetButtonStyle() const;
	void SetButtonStyle(UINT nStyle, BOOL bRedraw = TRUE);

	HICON SetIcon(HICON hIcon);
	HICON GetIcon() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	HCURSOR SetCursor(HCURSOR hCursor);
	HCURSOR GetCursor();

#if (_WIN32_WINNT >= 0x501)
	AFX_ANSI_DEPRECATED BOOL GetIdealSize(_Out_ LPSIZE psize) const;
	AFX_ANSI_DEPRECATED BOOL SetImageList(_In_ PBUTTON_IMAGELIST pbuttonImagelist);
	AFX_ANSI_DEPRECATED BOOL GetImageList(_In_ PBUTTON_IMAGELIST pbuttonImagelist) const;
	AFX_ANSI_DEPRECATED BOOL SetTextMargin(_In_ LPRECT pmargin);
	AFX_ANSI_DEPRECATED BOOL GetTextMargin(_Out_ LPRECT pmargin) const;
#endif  // (_WIN32_WINNT >= 0x501)

#if ( _WIN32_WINNT >= 0x0600 ) && defined(UNICODE)
	CString GetNote() const;
	_Check_return_ BOOL GetNote(_Out_z_cap_(*pcchNote) LPTSTR lpszNote, _Inout_ UINT* pcchNote) const;
	BOOL SetNote(_In_z_ LPCTSTR lpszNote);
	UINT GetNoteLength() const;
	BOOL GetSplitInfo(_Out_ PBUTTON_SPLITINFO pInfo) const;
	BOOL SetSplitInfo(_In_ PBUTTON_SPLITINFO pInfo);
	UINT GetSplitStyle() const;
	BOOL SetSplitStyle(_In_ UINT nStyle);
	BOOL GetSplitSize(_Out_ LPSIZE pSize) const;
	BOOL SetSplitSize(_In_ LPSIZE pSize);
	CImageList* GetSplitImageList() const;
	BOOL SetSplitImageList(_In_ CImageList* pSplitImageList);
	TCHAR GetSplitGlyph() const;
	BOOL SetSplitGlyph(_In_ TCHAR chGlyph);
	BOOL SetDropDownState(_In_ BOOL fDropDown);

	HICON SetShield(_In_ BOOL fElevationRequired);
#endif // ( _WIN32_WINNT >= 0x600 ) && defined(UNICODE)

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

public:
	virtual ~CButton();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

#if (_WIN32_WINNT >= 0x600) && defined(UNICODE)
class CSplitButton : public CButton
{
	DECLARE_DYNAMIC(CSplitButton)

public:
	CSplitButton();
	CSplitButton(UINT nMenuId, UINT nSubMenuId);
	CSplitButton(CMenu* pMenu);

	~CSplitButton();

	virtual BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID);

	void SetDropDownMenu(UINT nMenuId, UINT nSubMenuId);
	void SetDropDownMenu(CMenu* pMenu);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDropDown(NMHDR* /*pNMHDR*/, LRESULT *pResult);

	void Cleanup();

	CMenu * m_pMenu;
	UINT m_nMenuId;
	UINT m_nSubMenuId;
};

#endif // (_WIN32_WINNT >= 0x600) && defined(CSplitButton)

class CListBox : public CWnd
{
	DECLARE_DYNAMIC(CListBox)

public:
	CListBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	int GetCount() const;
	int GetHorizontalExtent() const;
	void SetHorizontalExtent(int cxExtent);
	int GetTopIndex() const;
	int SetTopIndex(int nIndex);
	LCID GetLocale() const;
	LCID SetLocale(LCID nNewLocale);
	int InitStorage(int nItems, UINT nBytes);
	UINT ItemFromPoint(CPoint pt, BOOL& bOutside) const;

#if(WINVER >= 0x0500)
	DWORD GetListBoxInfo() const;
#endif	// WINVER >= 0x0500

	int GetCurSel() const;
	int SetCurSel(int nSelect);

	int GetSel(int nIndex) const;           // also works for single-selection
	int SetSel(int nIndex, BOOL bSelect = TRUE);
	int GetSelCount() const;
	int GetSelItems(int nMaxItems, LPINT rgIndex) const;
	void SetAnchorIndex(int nIndex);
	int GetAnchorIndex() const;

	DWORD_PTR GetItemData(int nIndex) const;
	int SetItemData(int nIndex, DWORD_PTR dwItemData);
	void* GetItemDataPtr(int nIndex) const;
	int SetItemDataPtr(int nIndex, void* pData);
	int GetItemRect(int nIndex, LPRECT lpRect) const;
	int GetText(_In_ int nIndex, _Pre_notnull_ _Post_z_ LPTSTR lpszBuffer) const;
	void GetText(int nIndex, CString& rString) const;
	int GetTextLen(int nIndex) const;

	void SetColumnWidth(int cxWidth);
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops);
	void SetTabStops();
	BOOL SetTabStops(const int& cxEachStop);    // takes an 'int'

	int SetItemHeight(int nIndex, UINT cyItemHeight);
	int GetItemHeight(int nIndex) const;
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const;
	int GetCaretIndex() const;
	int SetCaretIndex(int nIndex, BOOL bScroll = TRUE);

	int AddString(LPCTSTR lpszItem);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszItem);
	void ResetContent();
	int Dir(UINT attr, LPCTSTR lpszWildCard);

	int FindString(int nStartAfter, LPCTSTR lpszItem) const;
	int SelectString(int nStartAfter, LPCTSTR lpszItem);
	int SelItemRange(BOOL bSelect, int nFirstItem, int nLastItem);

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	virtual int VKeyToItem(UINT nKey, UINT nIndex);
	virtual int CharToItem(UINT nKey, UINT nIndex);

public:
	virtual ~CListBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

class CCheckListBox : public CListBox
{
	DECLARE_DYNAMIC(CCheckListBox)

public:
	CCheckListBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	void SetCheckStyle(UINT nStyle);
	UINT GetCheckStyle();
	void SetCheck(int nIndex, int nCheck);
	int GetCheck(int nIndex);
	void Enable(int nIndex, BOOL bEnabled = TRUE);
	BOOL IsEnabled(int nIndex);

	virtual CRect OnGetCheckPosition(CRect rectItem, CRect rectCheckBox);

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

protected:
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void PreMeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	int PreCompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	void PreDeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	bool PreDrawItemThemed(CDC* pDC, DRAWITEMSTRUCT &drawItem, int nCheck, int cyItem);
	void PreDrawItemNonThemed(CDC* pDC, DRAWITEMSTRUCT &drawItem, int nCheck, int cyItem);
	void PreDrawItemHelper(LPDRAWITEMSTRUCT lpDrawItemStruct);

	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);

   void SetSelectionCheck( int nCheck );

	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT accDoDefaultAction(VARIANT varChild);

#ifdef _DEBUG
	virtual void PreSubclassWindow();
#endif

	int CalcMinimumItemHeight();
	void InvalidateCheck(int nIndex);
	void InvalidateItem(int nIndex);
	int CheckFromPoint(CPoint point, BOOL& bInCheck);

	int m_cyText;
	UINT m_nStyle;

protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnSetFont(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBAddString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBFindString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBFindStringExact(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBGetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBGetText(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBInsertString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSelectString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemHeight(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

class CComboBox : public CWnd
{
	DECLARE_DYNAMIC(CComboBox)

public:
	CComboBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	int GetCount() const;
	int GetCurSel() const;
	int SetCurSel(int nSelect);
	LCID GetLocale() const;
	LCID SetLocale(LCID nNewLocale);
	int GetTopIndex() const;
	int SetTopIndex(int nIndex);
	int InitStorage(int nItems, UINT nBytes);
	void SetHorizontalExtent(UINT nExtent);
	UINT GetHorizontalExtent() const;
	int SetDroppedWidth(UINT nWidth);
	int GetDroppedWidth() const;

#if(WINVER >= 0x0500)
	BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;
#endif	// WINVER >= 0x0500

#if (_WIN32_WINNT >= 0x501) && defined(UNICODE)
	BOOL SetMinVisibleItems(_In_ int iMinVisible);

	int GetMinVisible() const;

#ifdef CB_SETCUEBANNER
	BOOL SetCueBanner(_In_z_ LPCTSTR lpszText);

	CString GetCueBanner() const;
	BOOL GetCueBanner(_Out_z_cap_(cchText) LPTSTR lpszText, _In_ int cchText) const;
#endif  // CB_SETCUEBANNER
#endif  // (_WIN32_WINNT >= 0x501) && defined(UNICODE)

	DWORD GetEditSel() const;
	BOOL LimitText(int nMaxChars);
	BOOL SetEditSel(int nStartChar, int nEndChar);

	DWORD_PTR GetItemData(int nIndex) const;
	int SetItemData(int nIndex, DWORD_PTR dwItemData);
	void* GetItemDataPtr(int nIndex) const;
	int SetItemDataPtr(int nIndex, void* pData);
	int GetLBText(_In_ int nIndex, _Pre_notnull_ _Post_z_ LPTSTR lpszText) const;
	void GetLBText(int nIndex, CString& rString) const;
	int GetLBTextLen(int nIndex) const;

	int SetItemHeight(int nIndex, UINT cyItemHeight);
	int GetItemHeight(int nIndex) const;
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const;
	int SetExtendedUI(BOOL bExtended = TRUE);
	BOOL GetExtendedUI() const;
	void GetDroppedControlRect(LPRECT lprect) const;
	BOOL GetDroppedState() const;

	void ShowDropDown(BOOL bShowIt = TRUE);

	int AddString(LPCTSTR lpszString);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszString);
	void ResetContent();
	int Dir(UINT attr, LPCTSTR lpszWildCard);

	int FindString(int nStartAfter, LPCTSTR lpszString) const;
	int SelectString(int nStartAfter, LPCTSTR lpszString);

	void Clear();
	void Copy();
	void Cut();
	void Paste();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);

public:
	virtual ~CComboBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

class CEdit : public CWnd
{
	DECLARE_DYNAMIC(CEdit)

public:
	CEdit();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	BOOL CanUndo() const;
	int GetLineCount() const;
	BOOL GetModify() const;
	void SetModify(BOOL bModified = TRUE);
	void GetRect(LPRECT lpRect) const;
	DWORD GetSel() const;
	void GetSel(int& nStartChar, int& nEndChar) const;
	HLOCAL GetHandle() const;
	void SetHandle(HLOCAL hBuffer);
	void SetMargins(UINT nLeft, UINT nRight);
	DWORD GetMargins() const;
	void SetLimitText(UINT nMax);
	UINT GetLimitText() const;
	CPoint PosFromChar(UINT nChar) const;
	int CharFromPos(CPoint pt) const;

	int GetLine(_In_ int nIndex, _Out_ LPTSTR lpszBuffer) const;
	int GetLine(_In_ int nIndex, _Out_cap_post_count_(nMaxLength, return) LPTSTR lpszBuffer, _In_ int nMaxLength) const;

#if (_WIN32_WINNT >= 0x501)
	AFX_ANSI_DEPRECATED BOOL SetCueBanner(_In_z_ LPCWSTR lpszText, _In_ BOOL fDrawIfFocused = FALSE);
	AFX_ANSI_DEPRECATED BOOL GetCueBanner(_Out_z_cap_(cchText) LPWSTR lpszText, _In_ int cchText) const;

#if defined(UNICODE)
	CString GetCueBanner() const;

	BOOL ShowBalloonTip(_In_z_ LPCWSTR lpszTitle, _In_z_ LPCWSTR lpszText, _In_ INT ttiIcon = TTI_NONE);
	BOOL ShowBalloonTip(_In_ PEDITBALLOONTIP pEditBalloonTip);
	BOOL HideBalloonTip();
#endif  // (UNICODE)
#endif  // (_WIN32_WINNT >= 0x501)

#if (_WIN32_WINNT >= 0x0600) && defined(UNICODE)
	void SetHighlight(_In_ int ichStart, _In_ int ichEnd);

	BOOL GetHighlight(_Out_ int* pichStart, _Out_ int* pichEnd) const;
#endif  // (_WIN32_WINNT >= 0x0600) && defined(UNICODE)

	void EmptyUndoBuffer();
	BOOL FmtLines(BOOL bAddEOL);

	void LimitText(int nChars = 0);
	int LineFromChar(int nIndex = -1) const;
	int LineIndex(int nLine = -1) const;
	int LineLength(int nLine = -1) const;
	void LineScroll(int nLines, int nChars = 0);
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
	void SetPasswordChar(TCHAR ch);
	void SetRect(LPCRECT lpRect);
	void SetRectNP(LPCRECT lpRect);
	void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE);
	void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll = FALSE);
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops);
	void SetTabStops();
	BOOL SetTabStops(const int& cxEachStop);    // takes an 'int'

	BOOL Undo();
	void Clear();
	void Copy();
	void Cut();
	void Paste();

	BOOL SetReadOnly(BOOL bReadOnly = TRUE);
	int GetFirstVisibleLine() const;
	TCHAR GetPasswordChar() const;

public:
	virtual ~CEdit();
};

class CScrollBar : public CWnd
{
	DECLARE_DYNAMIC(CScrollBar)

public:
	CScrollBar();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	int GetScrollPos() const;
	int SetScrollPos(int nPos, BOOL bRedraw = TRUE);
	void GetScrollRange(LPINT lpMinPos, LPINT lpMaxPos) const;
	void SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE);
	void ShowScrollBar(BOOL bShow = TRUE);

	BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);

	BOOL SetScrollInfo(LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE);
	BOOL GetScrollInfo(LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL);
	int GetScrollLimit();

#if(_WIN32_WINNT >= 0x0501)
	BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;
#endif	// _WIN32_WINNT >= 0x0501

public:
	virtual ~CScrollBar();
};

#define FWS_ADDTOTITLE  0x00008000L // modify title based on content
#define FWS_PREFIXTITLE 0x00004000L // show document name before app name
#define FWS_SNAPTOBARS  0x00002000L // snap size to size of contained bars

#define AFX_MBV_KEEPVISIBLE    0x01L // always visible
#define AFX_MBV_DISPLAYONFOCUS 0x02L // toggle state on ALT
#define AFX_MBV_DISPLAYONF10   0x04L // display on F10

#define AFX_MBS_VISIBLE 0x01L // visible
#define AFX_MBS_HIDDEN  0x02L // hidden

struct CPrintPreviewState;  // forward reference (see afxext.h)
class CControlBar;          // forward reference (see afxext.h)
class CReBar;               // forward reference (see afxext.h)

class CDockBar;             // forward reference (see afxpriv.h)
class CMiniDockFrameWnd;    // forward reference (see afxpriv.h)
class CDockState;           // forward reference (see afxpriv.h)

class COleFrameHook;        // forward reference (see ..\src\oleimpl2.h)

class CFrameWnd : public CWnd
{
	DECLARE_DYNCREATE(CFrameWnd)

public:
	static AFX_DATA const CRect rectDefault;
	CFrameWnd();

	BOOL LoadAccelTable(LPCTSTR lpszResourceName);
	virtual BOOL Create(LPCTSTR lpszClassName,
				LPCTSTR lpszWindowName,
				DWORD dwStyle = WS_OVERLAPPEDWINDOW,
				const RECT& rect = rectDefault,
				CWnd* pParentWnd = NULL,        // != NULL for popups
				LPCTSTR lpszMenuName = NULL,
				DWORD dwExStyle = 0,
				CCreateContext* pContext = NULL);

	virtual BOOL LoadFrame(UINT nIDResource,
				DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
				CWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);

	CWnd* CreateView(CCreateContext* pContext, UINT nID = AFX_IDW_PANE_FIRST);

	virtual CDocument* GetActiveDocument();

	CView* GetActiveView() const;           // active view or NULL
	void SetActiveView(CView* pViewNew, BOOL bNotify = TRUE);

	virtual CFrameWnd* GetActiveFrame();

	virtual void GetMessageString(UINT nID, CString& rMessage) const;

	BOOL m_bAutoMenuEnable;

	BOOL IsTracking() const;

	virtual void RecalcLayout(BOOL bNotify = TRUE);
	virtual void ActivateFrame(int nCmdShow = -1);
	void InitialUpdateFrame(CDocument* pDoc, BOOL bMakeVisible);
	void SetTitle(LPCTSTR lpszTitle);
	CString GetTitle() const;
	CMenu* GetMenu() const;
	BOOL SetMenu(CMenu* pMenu);

	virtual void SetMenuBarVisibility(DWORD dwStyle);
	virtual DWORD GetMenuBarVisibility() const;

	virtual BOOL SetMenuBarState(DWORD dwState);
	virtual DWORD GetMenuBarState() const;

#if WINVER >= 0x0500
	BOOL GetMenuBarInfo(LONG idObject, LONG idItem, PMENUBARINFO pmbi) const;
#endif

	void SetMessageText(LPCTSTR lpszText);
	void SetMessageText(UINT nID);

	void EnableDocking(DWORD dwDockStyle);
	void DockControlBar(CControlBar* pBar, UINT nDockBarID = 0,
		LPCRECT lpRect = NULL);
	void FloatControlBar(CControlBar* pBar, CPoint point,
		DWORD dwStyle = CBRS_ALIGN_TOP);
	CControlBar* GetControlBar(UINT nID);

	virtual void BeginModalState();
	virtual void EndModalState();
	BOOL InModalState() const;
	void ShowOwnedWindows(BOOL bShow);

	void LoadBarState(LPCTSTR lpszProfileName);
	void SaveBarState(LPCTSTR lpszProfileName) const;
	void ShowControlBar(CControlBar* pBar, BOOL bShow, BOOL bDelay);
	void SetDockState(const CDockState& state);
	void GetDockState(CDockState& state) const;

	virtual void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState);
	virtual CWnd* GetMessageBar();

	enum BorderCmd
		{ borderGet = 1, borderRequest = 2, borderSet = 3 };
	virtual BOOL NegotiateBorderSpace(UINT nBorderCmd, LPRECT lpRectBorder);

protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

public:
	afx_msg void OnContextHelp();   // for Shift+F1 help
	afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnBarCheck(UINT nID);

public:
	virtual ~CFrameWnd();
	int m_nWindow;  // general purpose window number - display as ":n"

	HMENU m_hMenuDefault;       // default menu resource for this frame
	HACCEL m_hAccelTable;       // accelerator table
	DWORD m_dwPromptContext;    // current help prompt context for message box
	BOOL m_bHelpMode;           // if TRUE, then Shift+F1 help mode is active
	CFrameWnd* m_pNextFrameWnd; // next CFrameWnd in app global list
	CRect m_rectBorder;         // for OLE border space negotiation
	COleFrameHook* m_pNotifyHook;

	CPtrList m_listControlBars; // array of all control bars that have this
	int m_nShowDelay;           // SW_ command for delay show/hide

	CMiniDockFrameWnd* CreateFloatingFrame(DWORD dwStyle);
	DWORD CanDock(CRect rect, DWORD dwDockStyle,
		CDockBar** ppDockBar = NULL); // called by CDockContext
	void AddControlBar(CControlBar *pBar);
	void RemoveControlBar(CControlBar *pBar);
	void DockControlBar(CControlBar* pBar, CDockBar* pDockBar,
		LPCRECT lpRect = NULL);
	void ReDockControlBar(CControlBar* pBar, CDockBar* pDockBar,
		LPCRECT lpRect = NULL);
	void NotifyFloatingWindows(DWORD dwFlags);
	void DestroyDockBars();

protected:
	UINT m_nIDHelp;             // Help ID (0 for none, see HID_BASE_RESOURCE)
	UINT m_nIDTracking;         // tracking command ID or string IDS
	UINT m_nIDLastMessage;      // last displayed message string IDS
	CView* m_pViewActive;       // current active view
	BOOL (CALLBACK* m_lpfnCloseProc)(CFrameWnd* pFrameWnd);
	UINT m_cModalStack;         // BeginModalState depth
	HWND* m_phWndDisable;       // windows disabled because of BeginModalState
	HMENU m_hMenuAlt;           // menu to update to (NULL means default)
	CString m_strTitle;         // default title (original)
	BOOL m_bInRecalcLayout;     // avoid recursion in RecalcLayout
	CRuntimeClass* m_pFloatingFrameClass;
	static const DWORD dwDockBarMap[4][2];
    DWORD m_dwMenuBarVisibility;      // menu bar visibility style
	DWORD m_dwMenuBarState;           // menu bar visibility state
	HMENU m_hMenu;                    // backed menu for restoring from the hidden state
	BOOL  m_bTempShowMenu;            // temporarily show the menu bar to enable menu access keys
	BOOL  m_bMouseHitMenu;            // if TRUE, the mouse is hitting the menu bar

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL IsFrameWnd() const;
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual void OnUpdateFrameMenu(HMENU hMenuAlt);
	virtual HACCEL GetDefaultAccelerator();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	enum IdleFlags
		{ idleMenu = 1, idleTitle = 2, idleNotify = 4, idleLayout = 8 };
	UINT m_nIdleFlags;          // set of bit flags for idle processing
	virtual void DelayUpdateFrameMenu(HMENU hMenuAlt);
	void DelayUpdateFrameTitle();
	void DelayRecalcLayout(BOOL bNotify = TRUE);

	BOOL CanEnterHelpMode();
	virtual void ExitHelpMode();

public:
	void UpdateFrameTitleForDocument(LPCTSTR lpszDocName);
protected:
	LPCTSTR GetIconWndClass(DWORD dwDefaultStyle, UINT nIDResource);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void PostNcDestroy();   // default to delete this.
	int OnCreateHelper(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	void BringToTop(int nCmdShow);

	BOOL ProcessHelpMsg(MSG& msg, DWORD* pContext);
	HWND SetHelpCapture(POINT point, BOOL* pbDescendant);

	void AddFrameWnd();
	void RemoveFrameWnd();

	virtual void OnShowMenuBar();
	virtual void OnHideMenuBar();

	friend class CWnd;  // for access to m_bModalDisable
	friend class CReBar; // for access to m_bInRecalcLayout

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnInitMenu(CMenu*);
	afx_msg void OnInitMenuPopup(CMenu*, UINT, BOOL);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);
	afx_msg LRESULT OnPopMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpPromptAddr(WPARAM wParam, LPARAM lParam);
	afx_msg void OnIdleUpdateCmdUI();
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnActivateTopLevel(WPARAM wParam, LPARAM lParam);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateKeyIndicator(CCmdUI* pCmdUI);
	afx_msg void OnHelp();
	afx_msg void OnUpdateContextHelp(CCmdUI* pCmdUI);
	afx_msg BOOL OnChevronPushed(UINT id, NMHDR *pnm, LRESULT *result);
protected:
	afx_msg LRESULT OnDDEInitiate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDDEExecute(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDDETerminate(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	friend class CWinApp;
};

class CMDIFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMDIFrameWnd)

public:
	CMDIFrameWnd();

	void MDIActivate(CWnd* pWndActivate);
	CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
	void MDIIconArrange();
	void MDIMaximize(CWnd* pWnd);
	void MDINext();
	void MDIPrev();
	void MDIRestore(CWnd* pWnd);
	CMenu* MDISetMenu(CMenu* pFrameMenu, CMenu* pWindowMenu);
	void MDITile();
	void MDICascade();
	void MDITile(int nType);
	void MDICascade(int nType);
	CMDIChildWnd* CreateNewChild(CRuntimeClass* pClass, UINT nResource,
		HMENU hMenu = NULL, HACCEL hAccel = NULL);

	virtual BOOL CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu);
	virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);

public:
	HWND m_hWndMDIClient;       // MDI Client window handle

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource,
				DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
				CWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnUpdateFrameMenu(HMENU hMenuAlt);
	virtual void DelayUpdateFrameMenu(HMENU hMenuAlt);
	virtual CFrameWnd* GetActiveFrame();
	virtual void SetMenuBarVisibility(DWORD dwStyle);
	virtual BOOL SetMenuBarState(DWORD dwState);

protected:
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUpdateMDIWindowCmd(CCmdUI* pCmdUI);
	afx_msg BOOL OnMDIWindowCmd(UINT nID);
	afx_msg void OnWindowNew();
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void OnIdleUpdateCmdUI();
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT, CMenu*);
	DECLARE_MESSAGE_MAP()
};

class CMDIChildWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMDIChildWnd)

public:
	CMDIChildWnd();

	virtual BOOL Create(LPCTSTR lpszClassName,
				LPCTSTR lpszWindowName,
				DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				const RECT& rect = rectDefault,
				CMDIFrameWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);

	CMDIFrameWnd* GetMDIFrame();

	void MDIDestroy();
	void MDIActivate();
	void MDIMaximize();
	void MDIRestore();
	void SetHandles(HMENU hMenu, HACCEL hAccel);

protected:
	HMENU m_hMenuShared;        // menu when we are active

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle,
					CWnd* pParentWnd, CCreateContext* pContext = NULL);
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void ActivateFrame(int nCmdShow = -1);
	virtual void OnUpdateFrameMenu(BOOL bActive, CWnd* pActivateWnd,
		HMENU hMenuAlt);

	BOOL m_bPseudoInactive;     // TRUE if window is MDI active according to

protected:
	virtual CWnd* GetMessageBar();
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	BOOL UpdateClientEdge(LPRECT lpRect = NULL);

	afx_msg void OnMDIActivate(BOOL bActivate, CWnd*, CWnd*);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(LPWINDOWPOS lpWndPos);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnDestroy();
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};

#define MFS_SYNCACTIVE      0x00000100L // syncronize activation w/ parent
#define MFS_4THICKFRAME     0x00000200L // thick frame all around (no tiles)
#define MFS_THICKFRAME      0x00000400L // use instead of WS_THICKFRAME
#define MFS_MOVEFRAME       0x00000800L // no sizing, just moving
#define MFS_BLOCKSYSMENU    0x00001000L // block hit testing on system menu

#pragma warning( push )

#pragma warning( disable: 4263 )
#pragma warning( disable: 4264 )
class CMiniFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMiniFrameWnd)

public:
	CMiniFrameWnd();
	virtual BOOL Create(LPCTSTR lpClassName, LPCTSTR lpWindowName,
		DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd = NULL, UINT nID = 0);
	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName,
		DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd = NULL, UINT nID = 0);

public:
	~CMiniFrameWnd();

	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* pMMI);
	afx_msg LRESULT OnFloatStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnQueryCenterWnd(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpcs);
	DECLARE_MESSAGE_MAP()

public:
	static void PASCAL CalcBorders(LPRECT lpClientRect,
		DWORD dwStyle = WS_THICKFRAME | WS_CAPTION, DWORD dwExStyle = 0);

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	BOOL m_bSysTracking;
	BOOL m_bInSys;
	BOOL m_bActive;
	CString m_strCaption;
};

#pragma warning( pop )

class CPrintDialog;     // forward reference (see afxdlgs.h)
class CPreviewView;     // forward reference (see afxpriv.h)
class CSplitterWnd;     // forward reference (see afxext.h)
class COleServerDoc;    // forward reference (see afxole.h)

typedef DWORD DROPEFFECT;
class COleDataObject;   // forward reference (see afxole.h)

class AFX_NOVTABLE CView : public CWnd
{
	DECLARE_DYNAMIC(CView)

protected:
	CView();

public:
	CDocument* GetDocument() const;

public:
	BOOL DoPreparePrinting(CPrintInfo* pInfo);

public:
	virtual BOOL IsSelected(const CObject* pDocItem) const; // support for OLE

	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);

	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual void OnDragLeave();
	virtual BOOL OnDrop(COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDropEx(COleDataObject* pDataObject,
		DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point);
	virtual DROPEFFECT OnDragScroll(DWORD dwKeyState, CPoint point);

	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);

	virtual void OnInitialUpdate(); // called first time after construct

protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView,
					CView* pDeactiveView);
	virtual void OnActivateFrame(UINT nState, CFrameWnd* pFrameWnd);

	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnDraw(CDC* pDC) = 0;

	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point,
		CPreviewView* pView);

public:
	virtual ~CView() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

	BOOL DoPrintPreview(UINT nIDResource, CView* pPrintView,
			CRuntimeClass* pPreviewViewClass, CPrintPreviewState* pState);

	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	static CSplitterWnd* PASCAL GetParentSplitter(
		const CWnd* pWnd, BOOL bAnyState);

protected:
	CDocument* m_pDocument;

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void PostNcDestroy();

	friend class CDocument;
	friend class CDocTemplate;
	friend class CPreviewView;
	friend class CFrameWnd;
	friend class CMDIFrameWnd;
	friend class CMDIChildWnd;
	friend class CSplitterWnd;
	friend class COleServerDoc;
	friend class CDocObjectServer;

	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnUpdateSplitCmd(CCmdUI* pCmdUI);
	afx_msg BOOL OnSplitCmd(UINT nID);
	afx_msg void OnUpdateNextPaneMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnNextPaneCmd(UINT nID);

	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	DECLARE_MESSAGE_MAP()
};

class AFX_NOVTABLE CCtrlView : public CView
{
	DECLARE_DYNCREATE(CCtrlView)

public:
	CCtrlView(LPCTSTR lpszClass, DWORD dwStyle);

protected:
	CString m_strClass;
	DWORD m_dwDefaultStyle;

	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	~CCtrlView() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

class _AFX_MOUSEANCHORWND;

class CScrollView : public CView
{
	DECLARE_DYNAMIC(CScrollView)

protected:
	CScrollView();

public:
	static AFX_DATA const SIZE sizeDefault;

	void SetScaleToFitSize(SIZE sizeTotal);
	void SetScrollSizes(int nMapMode, SIZE sizeTotal,
				const SIZE& sizePage = sizeDefault,
				const SIZE& sizeLine = sizeDefault);

public:
	CPoint GetScrollPosition() const;       // upper corner of scrolling
	CSize GetTotalSize() const;             // logical size

	void CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const;

	CPoint GetDeviceScrollPosition() const;
	void GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal,
			SIZE& sizePage, SIZE& sizeLine) const;

public:
	void ScrollToPosition(POINT pt);    // set upper left position
	void FillOutsideRect(CDC* pDC, CBrush* pBrush);
	void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
	BOOL DoMouseWheel(UINT fFlags, short zDelta, CPoint point);

protected:
	_AFX_MOUSEANCHORWND* m_pAnchorWindow; // window for wheel mouse anchor
	friend class _AFX_MOUSEANCHORWND;
	int m_nMapMode;				 // mapping mode for window creation
	CSize m_totalLog;           // total size in logical units (no rounding)
	CSize m_totalDev;           // total size in device units
	CSize m_pageDev;            // per page scroll size in device units
	CSize m_lineDev;            // per line scroll size in device units

	BOOL m_bCenter;             // Center output if larger than total size
	BOOL m_bInsideUpdate;       // internal state for OnSize callback
	void CenterOnPoint(CPoint ptCenter);
	void ScrollToDevicePosition(POINT ptDev); // explicit scrolling no checking

protected:
	virtual void OnDraw(CDC* pDC) = 0;      // pass on pure virtual

	void UpdateBars();          // adjust scrollbars etc
	BOOL GetTrueClientSize(CSize& size, CSize& sizeSb);
	void GetScrollBarSizes(CSize& sizeSb);
	void GetScrollBarState(CSize sizeClient, CSize& needSb,
		CSize& sizeRange, CPoint& ptMove, BOOL bInsideClient);

public:
	virtual ~CScrollView();
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG
	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);

	virtual CSize GetWheelScrollDistance(CSize sizeDistance,
		BOOL bHorz, BOOL bVert);

	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT fFlags, short zDelta, CPoint point);
	afx_msg LRESULT HandleMButtonDown(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

typedef UINT (AFX_CDECL *AFX_THREADPROC)(LPVOID);

class COleMessageFilter;        // forward reference (see afxole.h)

BOOL AFXAPI AfxPumpMessage();
LRESULT AFXAPI AfxProcessWndProcException(CException*, const MSG* pMsg);
BOOL __cdecl AfxPreTranslateMessage(MSG* pMsg);
BOOL __cdecl AfxIsIdleMessage(MSG* pMsg);

class CWinThread : public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)

	friend BOOL AfxInternalPreTranslateMessage(MSG* pMsg);

public:
	CWinThread();
	BOOL CreateThread(DWORD dwCreateFlags = 0, UINT nStackSize = 0,
		LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

	CWnd* m_pMainWnd;       // main window (usually same AfxGetApp()->m_pMainWnd)
	CWnd* m_pActiveWnd;     // active main window (may not be m_pMainWnd)
	BOOL m_bAutoDelete;     // enables 'delete this' after thread termination

	HANDLE m_hThread;       // this thread's HANDLE
	operator HANDLE() const;
	DWORD m_nThreadID;      // this thread's ID

	int GetThreadPriority();
	BOOL SetThreadPriority(int nPriority);

	DWORD SuspendThread();
	DWORD ResumeThread();
	BOOL PostThreadMessage(UINT message, WPARAM wParam, LPARAM lParam);

	virtual BOOL InitInstance();

	virtual int Run();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PumpMessage();     // low level message pump
	virtual BOOL OnIdle(LONG lCount); // return TRUE if more idle processing
	virtual BOOL IsIdleMessage(MSG* pMsg);  // checks for special messages

	virtual int ExitInstance(); // default will 'delete this'

	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);

	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);

	virtual CWnd* GetMainWnd();

public:
	virtual ~CWinThread();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CommonConstruct();
	virtual void Delete();

public:
	CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);

	LPVOID m_pThreadParams; // generic parameters passed to starting function
	AFX_THREADPROC m_pfnThreadProc;

	void (AFXAPI* m_lpfnOleTermOrFreeLib)(BOOL, BOOL);
	COleMessageFilter* m_pMessageFilter;

protected:
	BOOL DispatchThreadMessageEx(MSG* msg);  // helper
	void DispatchThreadMessage(MSG* msg);  // obsolete
};

CWinThread* AFXAPI AfxBeginThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam,
	int nPriority = THREAD_PRIORITY_NORMAL, UINT nStackSize = 0,
	DWORD dwCreateFlags = 0, LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
CWinThread* AFXAPI AfxBeginThread(CRuntimeClass* pThreadClass,
	int nPriority = THREAD_PRIORITY_NORMAL, UINT nStackSize = 0,
	DWORD dwCreateFlags = 0, LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

CWinThread* AFXAPI AfxGetThread();
MSG* AFXAPI AfxGetCurrentMessage();

void AFXAPI AfxEndThread(UINT nExitCode, BOOL bDelete = TRUE);

void AFXAPI AfxInitThread();
void AFXAPI AfxTermThread(HINSTANCE hInstTerm = NULL);

#define afxCurrentWinApp    AfxGetModuleState()->m_pCurrentWinApp
#define afxCurrentInstanceHandle    AfxGetModuleState()->m_hCurrentInstanceHandle
#define afxCurrentResourceHandle    AfxGetModuleState()->m_hCurrentResourceHandle
#define afxCurrentAppName   AfxGetModuleState()->m_lpszCurrentAppName
#define afxContextIsDLL     AfxGetModuleState()->m_bDLL
#define afxRegisteredClasses    AfxGetModuleState()->m_fRegisteredClasses
#define afxAmbientActCtx    AfxGetModuleState()->m_bSetAmbientActCtx

#ifndef _AFX_NO_OCC_SUPPORT
#define afxOccManager   AfxGetModuleState()->m_pOccManager
#endif

#ifndef _AFX_NO_AFXCMN_SUPPORT
#define _AFX_COMCTL32_ISOLATION_WRAPPER_INDEX 0
#define afxComCtlWrapper static_cast<CComCtlWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMCTL32_ISOLATION_WRAPPER_INDEX])
#endif

#define _AFX_COMMDLG_ISOLATION_WRAPPER_INDEX 1
#define afxCommDlgWrapper static_cast<CCommDlgWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMMDLG_ISOLATION_WRAPPER_INDEX])

#define _AFX_SHELL_ISOLATION_WRAPPER_INDEX 2
#define afxShellWrapper static_cast<CShellWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_SHELL_ISOLATION_WRAPPER_INDEX])

#define _AFX_ISOLATION_WRAPPER_ARRAY_SIZE 3

BOOL AFXAPI AfxWinInit(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
	_In_z_ LPTSTR lpCmdLine, _In_ int nCmdShow);
void AFXAPI AfxWinTerm();

#ifdef _AFXDLL
ULONG AFXAPI AfxGetDllVersion();
#endif

CWinApp* AFXAPI AfxGetApp();
CWnd* AFXAPI AfxGetMainWnd();
HINSTANCE AFXAPI AfxGetInstanceHandle();
HINSTANCE AFXAPI AfxGetResourceHandle();
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);
LPCTSTR AFXAPI AfxGetAppName();
AFX_DEPRECATED("AfxLoadLangResourceDLL(LPCTSTR pszFormat) has been deprecated, use AfxLoadLangResourceDLL(LPCTSTR pszFormat, LPCTSTR pszPath) instead")
	HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat);
HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat, LPCTSTR pszPath);

void AFXAPI AfxPostQuitMessage(int nExitCode);

#ifndef _AFXDLL
#define AfxFindResourceHandle(lpszResource, lpszType) AfxGetResourceHandle()
#else
HINSTANCE AFXAPI AfxFindResourceHandle(LPCTSTR lpszName, LPCTSTR lpszType);
#endif

LONG AFXAPI AfxDelRegTreeHelper(HKEY hParentKey, const CString& strKeyName);

class CRecentFileList;          // forward reference (see afxadv.h)

COleMessageFilter* AFXAPI AfxOleGetMessageFilter();

class CCommandLineInfo : public CObject
{
public:
	CCommandLineInfo();

	virtual void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
#ifdef _UNICODE
	virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
#endif

	BOOL m_bShowSplash;
	BOOL m_bRunEmbedded;
	BOOL m_bRunAutomated;
	BOOL m_bRegisterPerUser;
	enum { FileNew, FileOpen, FilePrint, FilePrintTo, FileDDE, AppRegister,
		AppUnregister, FileNothing = -1 } m_nShellCommand;

	CString m_strFileName;

	CString m_strPrinterName;
	CString m_strDriverName;
	CString m_strPortName;

	~CCommandLineInfo();
protected:
	void ParseParamFlag(const char* pszParam);
	void ParseParamNotFlag(const TCHAR* pszParam);
#ifdef _UNICODE
	void ParseParamNotFlag(const char* pszParam);
#endif
	void ParseLast(BOOL bLast);
};

class CDocManager : public CObject
{
	DECLARE_DYNAMIC(CDocManager)
public:

	CDocManager();

	virtual void AddDocTemplate(CDocTemplate* pTemplate);
	virtual POSITION GetFirstDocTemplatePosition() const;
	virtual CDocTemplate* GetNextDocTemplate(POSITION& pos) const;
	virtual void RegisterShellFileTypes(BOOL bCompat);
	void UnregisterShellFileTypes();
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName); // open named file
	virtual BOOL SaveAllModified(); // save before exit
	virtual void CloseAllDocuments(BOOL bEndSession); // close documents before exiting
	virtual int GetOpenDocumentCount();

	virtual BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);

	virtual BOOL OnDDECommand(_In_z_ LPTSTR lpszCommand);
	virtual void OnFileNew();
	virtual void OnFileOpen();

protected:
	CPtrList m_templateList;
	int GetDocumentCount(); // helper to count number of total documents

public:
	static CPtrList* pStaticList;       // for static CDocTemplate objects
	static BOOL bStaticInit;            // TRUE during static initialization
	static CDocManager* pStaticDocManager;  // for static CDocTemplate objects

public:
	virtual ~CDocManager();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

#define _AFX_MRU_COUNT   4      // default support for 4 entries in file MRU
#define _AFX_MRU_MAX_COUNT 16   // currently allocated id range supports 16

#define _AFX_SYSPOLICY_NOTINITIALIZED			0
#define _AFX_SYSPOLICY_NORUN					1
#define _AFX_SYSPOLICY_NODRIVES					2
#define _AFX_SYSPOLICY_RESTRICTRUN				4
#define _AFX_SYSPOLICY_NONETCONNECTDISCONNECTD	8
#define _AFX_SYSPOLICY_NOENTIRENETWORK			16
#define _AFX_SYSPOLICY_NORECENTDOCHISTORY		32
#define _AFX_SYSPOLICY_NOCLOSE					64
#define _AFX_SYSPOLICY_NOPLACESBAR				128
#define _AFX_SYSPOLICY_NOBACKBUTTON				256
#define _AFX_SYSPOLICY_NOFILEMRU				512

struct _AfxSysPolicyData
{
	LPCTSTR szPolicyName;
	DWORD dwID;
};

struct _AfxSysPolicies
{
	LPCTSTR szPolicyKey;
	_AfxSysPolicyData *pData;
};

class CWinApp : public CWinThread
{
	DECLARE_DYNAMIC(CWinApp)
public:

	/* explicit */ CWinApp(LPCTSTR lpszAppName = NULL);     // app name defaults to EXE name

	HINSTANCE m_hInstance;

	LPTSTR m_lpCmdLine;

	int m_nCmdShow;

	LPCTSTR m_pszAppName;

	LPCTSTR m_pszRegistryKey;

	CDocManager* m_pDocManager;

	BOOL m_bHelpMode;

public:

	LPCTSTR m_pszExeName;

	LPCTSTR m_pszHelpFilePath;

	LPCTSTR m_pszProfileName;

	void EnableHtmlHelp();

	void SetHelpMode( AFX_HELP_TYPE eHelpType );
	AFX_HELP_TYPE GetHelpMode();

	AFX_HELP_TYPE m_eHelpType;

protected:
	void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);

	void EnableShellOpen();

	AFX_DEPRECATED("CWinApp::SetDialogBkColor is no longer supported. Instead, handle WM_CTLCOLORDLG in your dialog")
			void SetDialogBkColor(COLORREF clrCtlBk = RGB(192, 192, 192), COLORREF clrCtlText = RGB(0, 0, 0));

	void SetRegistryKey(LPCTSTR lpszRegistryKey);
	void SetRegistryKey(UINT nIDRegistryKey);

	AFX_DEPRECATED("CWinApp::Enable3dControls is no longer needed. You should remove this call.")
			BOOL Enable3dControls();
#ifndef _AFXDLL
	AFX_DEPRECATED("CWinApp::Enable3dControlsStatic is no longer needed. You should remove this call.")
			BOOL Enable3dControlsStatic();
#endif

	void RegisterShellFileTypes(BOOL bCompat = FALSE);

	void UnregisterShellFileTypes();

public:
	HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;
	HCURSOR LoadCursor(UINT nIDResource) const;

	HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;

	HCURSOR LoadOEMCursor(UINT nIDCursor) const;

	HICON LoadIcon(LPCTSTR lpszResourceName) const;
	HICON LoadIcon(UINT nIDResource) const;

	HICON LoadStandardIcon(LPCTSTR lpszIconName) const;

	HICON LoadOEMIcon(UINT nIDIcon) const;

	UINT GetProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefault);

	BOOL WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue);

	CString GetProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPCTSTR lpszDefault = NULL);

	BOOL WriteProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPCTSTR lpszValue);

	BOOL GetProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPBYTE* ppData, UINT* pBytes);

	BOOL WriteProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPBYTE pData, UINT nBytes);

	virtual void InitLibId();

	virtual BOOL Register();

	virtual BOOL Unregister();

	LONG DelRegTree(HKEY hParentKey, const CString& strKeyName);

	void AddDocTemplate(CDocTemplate* pTemplate);
	POSITION GetFirstDocTemplatePosition() const;
	CDocTemplate* GetNextDocTemplate(POSITION& pos) const;

	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName);

	virtual void AddToRecentFileList(LPCTSTR lpszPathName);

	void SelectPrinter(HANDLE hDevNames, HANDLE hDevMode,
		BOOL bFreeOld = TRUE);

	BOOL CreatePrinterDC(CDC& dc);

BOOL GetPrinterDeviceDefaults(PRINTDLG* pPrintDlg);

	BOOL RunEmbedded();

	BOOL RunAutomated();

	void ParseCommandLine(CCommandLineInfo& rCmdInfo);

	BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);

	virtual BOOL InitApplication();

	virtual BOOL SaveAllModified(); // save before exit
	void HideApplication();
	void CloseAllDocuments(BOOL bEndSession); // close documents before exiting

	virtual int DoMessageBox(LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt);
	virtual void DoWaitCursor(int nCode); // 0 => restore, 1=> begin, -1=> end

	virtual BOOL OnDDECommand(_In_z_ LPTSTR lpszCommand);

	virtual void WinHelp(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);
	virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd = 0x000F);
	virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);

protected:
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();

	afx_msg void OnFilePrintSetup();

	afx_msg void OnContextHelp();   // shift-F1
	afx_msg void OnHelp();          // F1 (uses current context)
	afx_msg void OnHelpIndex();     // ID_HELP_INDEX
	afx_msg void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
	afx_msg void OnHelpUsing();     // ID_HELP_USING

protected:
	HGLOBAL m_hDevMode;             // printer Dev Mode
	HGLOBAL m_hDevNames;            // printer Device Names
	DWORD m_dwPromptContext;        // help context override for message box

	HINSTANCE m_hLangResourceDLL;  // Satellite resource DLL

	int m_nWaitCursorCount;         // for wait cursor (>0 => waiting)
	HCURSOR m_hcurWaitCursorRestore; // old cursor to restore after wait cursor

	CRecentFileList* m_pRecentFileList;

	void UpdatePrinterSelection(BOOL bForceDefaults);
	void SaveStdProfileSettings();  // save options to .INI file

public: // public for implementation access
	CCommandLineInfo* m_pCmdInfo;

	ATOM m_atomApp, m_atomSystemTopic;   // for DDE open
	UINT m_nNumPreviewPages;        // number of default printed pages

	size_t  m_nSafetyPoolSize;      // ideal size

	void (AFXAPI* m_lpfnDaoTerm)();

	void DevModeChange(_In_z_ LPTSTR lpDeviceName);
	void SetCurrentHandles();

	int GetOpenDocumentCount();

	BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);
	INT_PTR DoPrintDialog(CPrintDialog* pPD);

	void EnableModeless(BOOL bEnable); // to disable OLE in-place dialogs

	virtual BOOL InitInstance();
	virtual int ExitInstance(); // return app exit code
	virtual int Run();
	virtual BOOL OnIdle(LONG lCount); // return TRUE if more idle processing
	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);
	virtual HINSTANCE LoadAppLangResourceDLL();

	static int ShowAppMessageBox(CWinApp *pApp, LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt);
	static void DoEnableModeless(BOOL bEnable); // to disable OLE in-place dialogs

public:
	virtual ~CWinApp();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	HKEY GetSectionKey(LPCTSTR lpszSection);
	HKEY GetAppRegistryKey();

protected:
	afx_msg void OnAppExit();
	afx_msg void OnUpdateRecentFileMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnOpenRecentFile(UINT nID);
	DECLARE_MESSAGE_MAP()
public :
	virtual BOOL LoadSysPolicies(); // Override to load policies other than the system policies that MFC loads.
	BOOL GetSysPolicyValue(DWORD dwPolicyID, BOOL *pbValue); // returns the policy's setting in the out parameter
protected :
	BOOL _LoadSysPolicies() throw(); // Implementation helper
	DWORD m_dwPolicies;				// block for storing boolean system policies
};

class CWaitCursor
{
public:
	CWaitCursor();
	~CWaitCursor();

public:
	void Restore();
};

class AFX_NOVTABLE CDocTemplate : public CCmdTarget
{
	DECLARE_DYNAMIC(CDocTemplate)

protected:
	CDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

public:
	virtual void LoadTemplate();

public:
	void SetContainerInfo(UINT nIDOleInPlaceContainer);

	void SetServerInfo(UINT nIDOleEmbedding, UINT nIDOleInPlaceServer = 0,
		CRuntimeClass* pOleFrameClass = NULL, CRuntimeClass* pOleViewClass = NULL);

	virtual POSITION GetFirstDocPosition() const = 0;
	virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;

public:
	virtual void AddDocument(CDocument* pDoc);      // must override
	virtual void RemoveDocument(CDocument* pDoc);   // must override

	enum DocStringIndex
	{
		windowTitle,        // default window title
		docName,            // user visible name for default document
		fileNewName,        // user visible name for FileNew
		filterName,         // user visible name for FileOpen
		filterExt,          // user visible extension for FileOpen
		regFileTypeId,      // REGEDIT visible registered file type identifier
		regFileTypeName,    // Shell visible registered file type name
	};
	virtual BOOL GetDocString(CString& rString,
		enum DocStringIndex index) const; // get one of the info strings
	CFrameWnd* CreateOleFrame(CWnd* pParentWnd, CDocument* pDoc,
		BOOL bCreateView);

public:
	enum Confidence
	{
		noAttempt,
		maybeAttemptForeign,
		maybeAttemptNative,
		yesAttemptForeign,
		yesAttemptNative,
		yesAlreadyOpen
	};
	virtual Confidence MatchDocType(LPCTSTR lpszPathName,
					CDocument*& rpDocMatch);
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
	virtual void InitialUpdateFrame(CFrameWnd* pFrame, CDocument* pDoc,
		BOOL bMakeVisible = TRUE);
	virtual BOOL SaveAllModified();     // for all documents
	virtual void CloseAllDocuments(BOOL bEndSession);
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE) = 0;
	virtual void SetDefaultTitle(CDocument* pDocument) = 0;

public:
	BOOL m_bAutoDelete;
	virtual ~CDocTemplate() = 0;

	CObject* m_pAttachedFactory;

	HMENU m_hMenuInPlace;
	HACCEL m_hAccelInPlace;

	HMENU m_hMenuEmbedding;
	HACCEL m_hAccelEmbedding;

	HMENU m_hMenuInPlaceServer;
	HACCEL m_hAccelInPlaceServer;

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif
	virtual void OnIdle();             // for all documents
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);

protected:
	UINT m_nIDResource;                 // IDR_ for frame/menu/accel as well
	UINT m_nIDServerResource;           // IDR_ for OLE inplace frame/menu/accel
	UINT m_nIDEmbeddingResource;        // IDR_ for OLE open frame/menu/accel
	UINT m_nIDContainerResource;        // IDR_ for container frame/menu/accel

	CRuntimeClass* m_pDocClass;         // class for creating new documents
	CRuntimeClass* m_pFrameClass;       // class for creating new frames
	CRuntimeClass* m_pViewClass;        // class for creating new views
	CRuntimeClass* m_pOleFrameClass;    // class for creating in-place frame
	CRuntimeClass* m_pOleViewClass;     // class for creating in-place view

	CString m_strDocStrings;    // '\n' separated names
};

class CSingleDocTemplate : public CDocTemplate
{
	DECLARE_DYNAMIC(CSingleDocTemplate)

public:
	CSingleDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

public:
	virtual ~CSingleDocTemplate();
	virtual void AddDocument(CDocument* pDoc);
	virtual void RemoveDocument(CDocument* pDoc);
	virtual POSITION GetFirstDocPosition() const;
	virtual CDocument* GetNextDoc(POSITION& rPos) const;
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:  // standard implementation
	CDocument* m_pOnlyDoc;
};

class CMultiDocTemplate : public CDocTemplate
{
	DECLARE_DYNAMIC(CMultiDocTemplate)

public:
	CMultiDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

public:
	HMENU m_hMenuShared;
	HACCEL m_hAccelTable;

	virtual ~CMultiDocTemplate();
	virtual void LoadTemplate();
	virtual void AddDocument(CDocument* pDoc);
	virtual void RemoveDocument(CDocument* pDoc);
	virtual POSITION GetFirstDocPosition() const;
	virtual CDocument* GetNextDoc(POSITION& rPos) const;
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:  // standard implementation
	CPtrList m_docList;          // open documents of this type
	UINT m_nUntitledCount;   // start at 0, for "Document1" title
};

class AFX_NOVTABLE CDocument : public CCmdTarget
{
	DECLARE_DYNAMIC(CDocument)

public:
	CDocument();

public:
	const CString& GetTitle() const;
	virtual void SetTitle(LPCTSTR lpszTitle);
	const CString& GetPathName() const;
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);

	CDocTemplate* GetDocTemplate() const;
	virtual BOOL IsModified();
	virtual void SetModifiedFlag(BOOL bModified = TRUE);

	void AddView(CView* pView);
	void RemoveView(CView* pView);
	virtual POSITION GetFirstViewPosition() const;
	virtual CView* GetNextView(POSITION& rPosition) const;

	void UpdateAllViews(CView* pSender, LPARAM lHint = 0L,
		CObject* pHint = NULL);

	virtual void OnChangedViewList(); // after Add or Remove view
	virtual void DeleteContents(); // delete doc items etc

	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual void ReportSaveLoadException(LPCTSTR lpszPathName,
				CException* e, BOOL bSaving, UINT nIDPDefault);
	virtual CFile* GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
		CFileException* pError);
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);

	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	virtual BOOL SaveModified(); // return TRUE if ok to continue
	virtual void PreCloseFrame(CFrameWnd* pFrame);

protected:
	CString m_strTitle;
	CString m_strPathName;
	CDocTemplate* m_pDocTemplate;
	CPtrList m_viewList;                // list of views
	BOOL m_bModified;                   // changed since last saved

public:
	BOOL m_bAutoDelete;     // TRUE => delete document when no more views
	BOOL m_bEmbedded;       // TRUE => document is being created by OLE

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG
	virtual ~CDocument() = 0;

	virtual BOOL DoSave(LPCTSTR lpszPathName, BOOL bReplace = TRUE);
	virtual BOOL DoFileSave();
	virtual void UpdateFrameCounts();
	void DisconnectViews();
	void SendInitialUpdate();

	virtual HMENU GetDefaultMenu(); // get menu depending on state
	virtual HACCEL GetDefaultAccelerator();
	virtual void OnIdle();
	virtual void OnFinalRelease();

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	friend class CDocTemplate;

protected:
	afx_msg void OnFileClose();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileSendMail();
	afx_msg void OnUpdateFileSendMail(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifdef _DEBUG
extern AFX_DATA UINT afxTraceFlags;
#endif // _DEBUG

#ifdef _DEBUG
#define DECLARE_AFX_TRACE_CATEGORY( name ) extern AFX_DATA ATL::CTraceCategory name;
#else
#define DECLARE_AFX_TRACE_CATEGORY( name ) const DWORD_PTR name = 0;
#endif

DECLARE_AFX_TRACE_CATEGORY( traceAppMsg )        // main message pump trace (includes DDE)
DECLARE_AFX_TRACE_CATEGORY( traceWinMsg )        // Windows message tracing
DECLARE_AFX_TRACE_CATEGORY( traceCmdRouting )    // Windows command routing trace
DECLARE_AFX_TRACE_CATEGORY( traceOle )          // special OLE callback trace
DECLARE_AFX_TRACE_CATEGORY( traceDatabase )     // special database trace
DECLARE_AFX_TRACE_CATEGORY( traceInternet )     // special Internet client trace
DECLARE_AFX_TRACE_CATEGORY( traceDumpContext )	// traces from CDumpContext
DECLARE_AFX_TRACE_CATEGORY( traceMemory )		// generic non-kernel memory traces
DECLARE_AFX_TRACE_CATEGORY( traceHtml )			// Html traces
DECLARE_AFX_TRACE_CATEGORY( traceSocket )		// Socket traces

void AFXAPI AfxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1);
void AFXAPI AfxFormatString2(CString& rString, UINT nIDS,
				LPCTSTR lpsz1, LPCTSTR lpsz2);
int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK,
				UINT nIDHelp = 0);
int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK,
				UINT nIDHelp = (UINT)-1);

void AFXAPI AfxFormatStrings(CString& rString, UINT nIDS,
				LPCTSTR const* rglpsz, int nString);
void AFXAPI AfxFormatStrings(CString& rString, LPCTSTR lpszFormat,
				LPCTSTR const* rglpsz, int nString);
BOOL AFXAPI AfxExtractSubString(CString& rString, LPCTSTR lpszFullString,
				int iSubString, TCHAR chSep = '\n');

#ifdef _AFXDLL
	#include <afxdll_.h>
#endif

#define AfxEnableWin30Compatibility()
#define AfxEnableWin31Compatibility()
#define AfxEnableWin40Compatibility()

void AFXAPI AfxLockTempMaps();
BOOL AFXAPI AfxUnlockTempMaps(BOOL bDeleteTemps = TRUE);

void AFXAPI AfxOleOnReleaseAllObjects();
BOOL AFXAPI AfxOleCanExitApp();
void AFXAPI AfxOleLockApp();
void AFXAPI AfxOleUnlockApp();

void AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl);
BOOL AFXAPI AfxOleGetUserCtrl();

#ifndef _AFX_NO_OCC_SUPPORT
BOOL AFXAPI AfxOleLockControl(REFCLSID clsid);
BOOL AFXAPI AfxOleUnlockControl(REFCLSID clsid);
BOOL AFXAPI AfxOleLockControl(LPCTSTR lpszProgID);
BOOL AFXAPI AfxOleUnlockControl(LPCTSTR lpszProgID);
void AFXAPI AfxOleUnlockAllControls();
#endif

#define _RICHEDIT_VER 0x0210

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#include <afxcomctl32.inl>

#ifdef _AFX_ENABLE_INLINES
#define _AFXWIN_INLINE AFX_INLINE
#include <afxwin1.inl>
#include <afxwin2.inl>
#include <afxwin3.inl>
#endif

#include <afxwin4.inl>

#undef AFX_DATA
#define AFX_DATA

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#else //RC_INVOKED
#include <afxres.h>     // standard resource IDs
#endif //RC_INVOKED

#ifdef _M_CEE
    #include <atliface.h>
    #include <afxole.h>
#endif

#pragma warning( pop )

#endif //__AFXWIN_H__

// XTToolkitPro.h prelude (verbatim order) so the following header copy sees the same declarations.
#pragma warning(disable : 4786)
#pragma warning(push)
#pragma pack(push, 8)
#include <afxole.h>
#include <afxpriv.h>
#include <afxtempl.h>
#include <afxcview.h>
#include <shlobj.h>
#ifndef AFX_STATIC
#define AFX_STATIC static
#endif
#undef _XTP_EXT_CLASS
#if !defined(_AFXDLL) || defined(_XTP_STATICLINK)
#define _XTP_EXT_CLASS
#else
#define _XTP_EXT_CLASS  __declspec(dllimport)
#endif
#include "Common/Includes.h"
#include "TabManager/Includes.h"
#include "GraphicLibrary/Includes.h"
#include "Controls/Includes.h"
// XTPPaintManager.h copy; only change: 2007-08 CXTPPaintManager vtable (RTTI vtable 0x7c658c, CXTPOffice2007Theme 0x7d66b4; ret sizes per slot) has no DrawStatusBarPaneBorder and no DrawPopupResizeGripper slot

#if !defined(__XTPPAINTMANAGER_H__)
#define __XTPPAINTMANAGER_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CommandBars/XTPCommandBarsDefines.h"
#include "Common/XTPWinThemeWrapper.h"
#include "Common/XTPColorManager.h"
#include "Common/XTPDrawHelpers.h"

class CXTPControlButton;
class CXTPControlPopup;
class CXTPControl;
class CXTPToolBar;
class CXTPCommandBar;
class CXTPCommandBars;
class CXTPPopupBar;
class CXTPControlComboBox;
class CXTPTabControl;
class CXTPDockBar;
class CXTPControlEdit;
class CXTPImageManagerIcon;
class CXTPStatusBar;
class CXTPStatusBarPane;
class CXTPDialogBar;
class CXTPCommandBarKeyboardTip;

class CXTPBufferDC;
class CXTPControlGalleryPaintManager;

enum XTPSpecialControl
{
	xtpButtonExpandToolbar, // Control is option button of docking toolbar.
	xtpButtonExpandMenu,    // Control is expand button of popup bar.
	xtpButtonHideFloating,  // Control is hide button of floating toolbar.
	xtpButtonExpandFloating // Control is option button of floating toolbar.
};

enum XTPShadowOptions
{
	xtpShadowOfficeAlpha = 1,           // Office alpha shadow
	xtpShadowShowPopupControl = 2       // Draw shadow for popup controls
};

struct XTP_COMMANDBARS_ICONSINFO
{
	BOOL bUseFadedIcons;    // If TRUE, Icons will appear faded.
	BOOL bUseDisabledIcons; // If TRUE, disabled icons will be used when the control is disabled.
	BOOL bIconsWithShadow;  // If TRUE, when the mouse pointer is moved over a command bar control, the icons will appear to "jump" away from the screen casting a shadow.
	BOOL bOfficeStyleDisabledIcons;  // If TRUE, Office 2003 style disabled icons will be drawn when using disabled icons.
};

class _XTP_EXT_CLASS CXTPPaintManagerFont : public CFont
{
public:

	CXTPPaintManagerFont()
	{
		m_bStandardFont = TRUE;
	}

	BOOL SetCustomFont(const LOGFONT* lpLogFont)
	{
		m_bStandardFont = (lpLogFont == NULL);
		if (lpLogFont)
		{
			DeleteObject();
			return CreateFontIndirect(lpLogFont);
		}
		return TRUE;
	}

	void SetCustomFont(BOOL bCustomFont)
	{
		m_bStandardFont = !bCustomFont;
	}

	BOOL SetStandardFont(const LOGFONT* lpLogFont)
	{
		if (lpLogFont && (m_bStandardFont || !GetSafeHandle()))
		{
			DeleteObject();
			return CreateFontIndirect(lpLogFont);
		}
		return TRUE;
	}

protected:
	BOOL m_bStandardFont; // TRUE to use standard font;
};

class _XTP_EXT_CLASS CXTPPaintManager : public CXTPCmdTarget
{
private:
	friend class CXTPPaintManager* XTPPaintManager();
	class CPaintManagerDestructor;

public:
	CSize DrawControl(CDC* pDC, CXTPControl* pButton, BOOL bDraw = TRUE);

	virtual CSize DrawControlPopupParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);

	virtual CSize DrawControlToolBarParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);

	virtual void DrawSplitButtonFrame(CDC* pDC, CXTPControl* pButton, CRect rc) = 0;

	virtual CSize DrawControlComboBox(CDC* pDC, CXTPControlComboBox* pCombo, BOOL bDraw);

	virtual COLORREF GetControlEditBackColor(CXTPControl* pControl);

	virtual CSize DrawControlEdit(CDC* pDC, CXTPControlEdit* pEdit, BOOL bDraw);

	virtual CSize DrawListBoxControl(CDC* pDC, CXTPControl* pButton, CRect rc, BOOL bSelected, BOOL bDraw, CXTPCommandBars* pCommandBars = 0) = 0;

	virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar) = 0;

	virtual void DrawControlEntry(CDC* pDC, CXTPControl* pButton);

	virtual COLORREF GetControlTextColor(CXTPControl* pButton);

	virtual COLORREF GetRectangleTextColor(BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition) = 0;

	virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition) = 0;

	virtual CSize DrawCommandBarGripper(CDC* pDC, CXTPCommandBar* pBar, BOOL bDraw = TRUE);

	virtual CSize DrawCommandBarSeparator(CDC* pDC, CXTPCommandBar* pBar, CXTPControl* pControl, BOOL bDraw = TRUE) = 0;

	virtual void AdjustExcludeRect(CRect& rc, CXTPControl* pControl, BOOL bVertical) = 0;

	virtual void DrawStatusBarPaneEntry(CDC* pDC, CRect rcItem, CXTPStatusBarPane* pPane);

	virtual void DrawStatusBarButtonFace(CDC* pDC, CRect rcItem, CXTPStatusBarPane* pPane);

	virtual void DrawStatusBarGripper(CDC* pDC, CRect rcClient);

	virtual void FillDockBar(CDC* pDC, CXTPDockBar* pBar);

	virtual void FillStatusBar(CDC* pDC, CXTPStatusBar* pBar);

	virtual void RefreshMetrics();

	int GetShadowOptions() const;

	virtual CSize DrawSpecialControl(CDC* pDC, XTPSpecialControl controlType, CXTPControl* pButton, CXTPCommandBar* pBar, BOOL bDraw, LPVOID lpParam);

	virtual CRect GetCommandBarBorders(CXTPCommandBar* pBar);

	virtual CSize DrawTearOffGripper(CDC* pDC, CRect rcGripper, BOOL bSelected, BOOL bDraw) = 0;

	virtual void DrawImage(CDC* pDC, CPoint pt, CSize sz, CXTPImageManagerIcon* pImage, BOOL bSelected, BOOL bPressed, BOOL bEnabled = TRUE, BOOL bChecked = FALSE, BOOL bPopuped = FALSE, BOOL bToolBarImage = TRUE) = 0;

	virtual CSize DrawDialogBarGripper(CDC* pDC, CXTPDialogBar* pBar, BOOL bDraw) = 0;

	virtual CRect GetSplitButtonCommandRect(CXTPControl* pButton);

	virtual void SetCommandBarRegion(CXTPCommandBar* pCommandBar);

	virtual CSize DrawControlCheckBoxMark(CDC* pDC, CRect rc, BOOL bDraw, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bEnabled);

	virtual CSize DrawControlRadioButtonMark(CDC* pDC, CRect rc, BOOL bDraw, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bEnabled);

	virtual void DrawPopupBarGripper(CDC* pDC, int xPos, int yPos, int cx, int cy, BOOL bExpanded = FALSE);

public:

	static CXTPPaintManager* AFX_CDECL CreateTheme(XTPPaintTheme paintTheme);

	static void AFX_CDECL SetTheme(XTPPaintTheme paintTheme);

	static void AFX_CDECL SetCustomTheme(CXTPPaintManager* pTheme);

	XTPPaintTheme GetCurrentTheme() { return m_themeCurrent;}

	static void AFX_CDECL Done();

	virtual XTPPaintTheme BaseTheme() = 0;

public:

	virtual CFont* GetCommandBarFont(CXTPCommandBar* pBar, BOOL bBold = FALSE);

	static void AFX_CDECL Triangle(CDC* pDC, CPoint pt0, CPoint pt1, CPoint pt2, COLORREF clr);

	virtual void UpdateFonts();

	void SetCommandBarsFontIndirect(LOGFONT* pLogFont, BOOL bUseStandardFont = FALSE);

	CFont* GetRegularFont();

	CFont* GetRegularBoldFont();

	CFont* GetIconFont();

	CFont* GetSmCaptionFont();

	void UseOfficeFont(bool bUseOfficeFont);

	int GetControlHeight() const;

	void Rectangle(CDC* pDC, CRect rc, int nPen, int nBrush);

	void Draw3dRect(CDC* pDC, CRect rc, int nTopLeft, int nBottomRight);

	virtual void DrawCheckMark(CDC* pDC, CRect rcCheck, COLORREF clr = 0);

	virtual void DrawRadioMark(CDC* pDC, CRect rcCheck, COLORREF clr = 0);

	virtual void DrawComboExpandMark(CDC* pDC, CRect rc, COLORREF clr);

	void Line(CDC* pDC, CPoint p0, CPoint p1);
	void Line(CDC* pDC, int x0, int y0, int x1, int y1, int nPen); //<combine CXTPPaintManager::Line@CDC*@CPoint@CPoint>
	void HorizontalLine(CDC* pDC, int x0, int y0, int x1, COLORREF clrPen); //<combine CXTPPaintManager::Line@CDC*@CPoint@CPoint>
	void VerticalLine(CDC* pDC, int x0, int y0, int y1, COLORREF clrPen); //<combine CXTPPaintManager::Line@CDC*@CPoint@CPoint>

	virtual void DrawDropDownGlyph(CDC* pDC, CXTPControl* pControl, CPoint pt, BOOL bSelected, BOOL bPopuped, BOOL bEnabled, BOOL bVert);

	void Pixel(CDC* pDC, int xPos, int yPos, int nPen);

	void GradientFill(CDC* pDC, LPRECT lpRect, COLORREF crFrom, COLORREF crTo, BOOL bHorz, LPCRECT lpRectClip = NULL);

	XTP_COMMANDBARS_ICONSINFO* GetIconsInfo();

	virtual void Animate(CDC* pDestDC, CDC* pSrcDC, CRect rc, XTPAnimationType animationType);

	virtual void AnimateExpanding(CXTPCommandBar* pCommandBar, CDC* pDestDC, CDC* pSrcDC, BOOL bExpandDown);

	void SetAnimationDelay(int nAnimationSteps, int nAnimationTime);

	COLORREF GetXtremeColor(UINT nIndex);

	void SetColors(int cElements, CONST INT* lpaElements, CONST COLORREF* lpaRgbValues);

public:

	CSize DrawControlText(CDC* pDC, CXTPControl* pControl, CRect rcText, BOOL bDraw, BOOL bVert, BOOL bCentered, BOOL bTriangled);

	static BOOL AFX_CDECL FontExists(LPCTSTR lpszFaceName);

	static void AFX_CDECL StripMnemonics(CString& strClear);

public:

	virtual void UpdateRTLCaption(CString& strCaption);

	XTPCurrentSystemTheme GetCurrentSystemTheme();

	void SetLunaTheme(XTPCurrentSystemTheme systemTheme);

	virtual int GetPopupBarGripperWidth(CXTPCommandBar* pBar);

	CXTPControlGalleryPaintManager* GetGalleryPaintManager() const;

public:
	void ShowKeyboardCues(BOOL bShow);

	CFont* GetIconBoldFont()
	{
		return &m_fontIconBold;
	}
	virtual void FillWorkspace(CDC* pDC, CRect rc, CRect rcExclude);

	virtual void DrawKeyboardTip(CDC* pDC, CXTPCommandBarKeyboardTip* pWnd, BOOL bSetRegion);

	CSize GetAutoIconSize(BOOL bLarge) const;

	static void AFX_CDECL FillCompositeAlpha(CDC* pDC, CRect rc);
	_XTP_DEPRECATE("This function or variable is no longer available. Please use 'DrawControlText' instead")
	CSize DrawTextEx(CDC*, CString, CRect, BOOL, BOOL, BOOL, BOOL, BOOL = FALSE, BOOL = FALSE) {
		return CSize(0, 0);
	}
	int GetSplitDropDownHeight() const;
	void AlphaEllipse(CDC* pDC, CRect rc, COLORREF clrBorder, COLORREF clrFace);

protected:
	void AlphaBlendU(PBYTE pDest, PBYTE pSrcBack, int cx, int cy, PBYTE pSrc, BYTE byAlpha);
	void _DrawCheckMark(CDC* pDC, CRect rcCheck, COLORREF clr = 0, BOOL bLayoutRTL = FALSE);

	CSize DrawControlText2(CDC* pDC, CXTPControl* pControl, CRect rcText, BOOL bDraw, BOOL bVert, BOOL bTrangled);
	void DrawControlText3(CDC* pDC, CXTPControl* pControl, const CString& str, const CString& strClear, CRect rcText, BOOL bVert, BOOL bCentered);
	void SplitString(const CString& str, CString& strFirstRow, CString& strSecondRow);

	CSize DrawControlText(CDC* pDC, CXTPControl* pControl, CRect rcText, BOOL bDraw, BOOL bTriangled, CSize szButton, BOOL bDrawImage);
	BOOL IsFlatToolBar(CXTPCommandBar* pCommandBar);
	CSize GetControlSize(CXTPControl* pControl, CSize sz, BOOL bVert);
	virtual CSize GetPopupBarImageSize(CXTPCommandBar* pBar);
	virtual void DrawPopupBarText(CDC* pDC, const CString& strText, CRect& rcText, UINT nFlags, BOOL bDraw, BOOL bSelected, BOOL bEnabled);

	CSize GetIconSize(CXTPControl* pButton);

public:
	COLORREF m_clrShadowFactor;             // Shadow color
	COLORREF m_clrStatusTextColor;          // Status bar test color
	CXTPPaintManagerColorGradient m_clrDisabledIcon;    // Disabled icons color
	CXTPPaintManagerColor m_clrFloatingGripper;     // Gripper color of floating toolbar.
	CXTPPaintManagerColor m_clrFloatingGripperText; // Gripper text color of floating toolbar.

	BOOL m_bThickCheckMark;             // TRUE to draw thick check mark
	BOOL m_bShowShadow;                 // TRUE to show shadow
	BOOL m_bThemedStatusBar;            // TRUE to draw status bar using WinXP theme.
	BOOL m_bThemedCheckBox;             // TRUE to draw check box using WinXP theme.
	BOOL m_bClearTypeTextQuality;       // TRUE to enable ClearType text for the font.
	BOOL m_bResourceCharSet;            // TRUE to use font CharSet from loaded resources.

	BOOL m_bFlatToolBar;                // TRUE to draw toolbars flat
	BOOL m_bFlatMenuBar;                // TRUE to draw menubar flat
	int m_nPopupBarTextPadding;         // Distance between gripper and control text.
	BOOL m_bSelectImageInPopupBar;      // TRUE to select image as in explorer theme.
	BOOL m_bEnableAnimation;            // TRUE to enable animation for all toolbars

	BOOL m_bOffice2007Padding;          // TRUE if Office2007 metrics used
	BOOL m_bOffsetPopupLabelText;       // TRUE if labels in popups drawn with offset
	BOOL m_bWrapCaptionBelowText;       // Wrap text for xtpButtonIconAndCaptionBelow buttons

	CXTPPaintManagerFont m_fontSmCaption;   // Small caption font.
	CXTPPaintManagerFont m_fontIcon;        // Icon font.
	CXTPPaintManagerFont m_fontIconBold;    // Icon bold font.
	CXTPPaintManagerFont m_fontToolTip;     // Tooltip font

	int   m_nSplitButtonDropDownWidth;      // Split button drop down width in toolbars
	int   m_nSplitButtonPopupWidth;         // Split button drop down width in popups
	BOOL  m_bAutoResizeIcons;               // TRUE to automatically resize icons using current DPI
	int m_nStatusBarMinHeight;
	CXTPControlGalleryPaintManager* m_pGalleryPaintManager;         // Gallery paint manager
	PVOID m_pfnSetLayeredWindowAttributes;  // point to Transparency proc in USER32.dll module

	CRect m_rcStatusButtonMargins;

protected:
	CFont m_fontRegular;                // Regular font.
	CFont m_fontRegularBold;            // Regular bold font.
	CFont m_fontVert;                   // Vertical font.
	CFont m_fontVertBold;               // Vertical font.

	int   m_nTextHeight;                // Text height of the regular font.
	int   m_nEditHeight;                // Edit text height
	BOOL  m_bUseOfficeFont;             // TRUE to use Tahoma font.
	CString m_strOfficeFont;            // Office font
	BOOL  m_bUseStandardFont;           // TRUE to use system font.
	BOOL  m_bEmbossedDisabledText;      // TRUE to draw disabled text embossed
	int   m_nShadowOptions;             // Shadow options

	CXTPWinThemeWrapper m_themeStatusBar;   // StatusBar theme helper.
	CXTPWinThemeWrapper m_themeButton;      // Buttons theme helper.

	XTPPaintTheme m_themeCurrent;           // Current theme.
	static CXTPPaintManager* s_pInstance;   // Instance of the manager.

	XTP_COMMANDBARS_ICONSINFO m_iconsInfo;  // Specific icons options.

	int m_nAnimationSteps;                  // Steps of the animation.
	int m_nAnimationTime;                   // Time of the animation.

	BOOL m_bShowKeyboardCues;               // TRUE to show keyboard cues - deprecated.

	CXTPPaintManagerColor m_arrColor[XPCOLOR_LAST + 1];  // Self colors array.
	XTPCurrentSystemTheme m_systemTheme;   // Current system theme.

protected:

	CXTPPaintManager();

	virtual ~CXTPPaintManager();

public:
	struct _XTP_EXT_CLASS CLogFont : public LOGFONT
	{
		CLogFont();
	};

	struct _XTP_EXT_CLASS CNonClientMetrics : public NONCLIENTMETRICS
	{
		CNonClientMetrics();
	};

	friend class CCommandBarsCtrl;
	friend class CXTPCommandBarsOptions;
	friend class CXTPCommandBars;
};

CXTPPaintManager* XTPPaintManager();

AFX_INLINE CXTPPaintManager* XTPPaintManager() {
	if (CXTPPaintManager::s_pInstance == NULL)
	{
		CXTPPaintManager::SetTheme(xtpThemeOffice2000);
	}
	return CXTPPaintManager::s_pInstance;
}

namespace XTPPaintThemes
{
	class _XTP_EXT_CLASS CXTPOfficeTheme : public CXTPPaintManager
	{
	public:

		CXTPOfficeTheme();

		virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);

		virtual COLORREF GetRectangleTextColor(BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		virtual CSize DrawCommandBarGripper(CDC* pDC, CXTPCommandBar* pBar, BOOL bDraw = TRUE);

		virtual CSize DrawCommandBarSeparator(CDC* pDC, CXTPCommandBar* pBar, CXTPControl* pControl, BOOL bDraw = TRUE);

		virtual CSize DrawListBoxControl(CDC* pDC, CXTPControl* pButton, CRect rc, BOOL bSelected, BOOL bDraw, CXTPCommandBars* pCommandBars = 0);

		virtual void AdjustExcludeRect(CRect& rc, CXTPControl* pControl, BOOL bVertical);

		virtual CSize DrawTearOffGripper(CDC* pDC, CRect rcGripper, BOOL bSelected, BOOL bDraw);
		virtual void DrawPopupResizeGripper(CDC* pDC, CRect rcGripper, int nFlags);

		virtual CSize DrawDialogBarGripper(CDC* pDC, CXTPDialogBar* pBar, BOOL bDraw);

	protected:

		virtual void DrawPopupBarGripper(CDC* pDC, int xPos, int yPos, int cx, int cy, BOOL bExpanded = FALSE);

		virtual CSize DrawControlPopupParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);

		virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		virtual void DrawImage(CDC* pDC, CPoint pt, CSize sz, CXTPImageManagerIcon* pImage, BOOL bSelected, BOOL bPressed, BOOL bEnabled = TRUE, BOOL bChecked = FALSE, BOOL bPopuped = FALSE, BOOL bToolBarImage = TRUE);

		virtual CSize DrawControlComboBox(CDC* pDC, CXTPControlComboBox* pComboBox, BOOL bDraw);

		virtual CSize DrawControlEdit(CDC* pDC, CXTPControlEdit* pEdit, BOOL bDraw);

		void FillIntersectRect(CDC* pDC, CXTPPopupBar* pPopupBar, COLORREF clr);

		virtual void DrawStatusBarPaneBorder(CDC* pDC, CRect rc, CXTPStatusBarPane* pPane, BOOL bGripperPane);

		XTPPaintTheme BaseTheme() { return xtpThemeOfficeXP; }

		virtual void DrawSplitButtonFrame(CDC* pDC, CXTPControl* pButton, CRect rc);

		virtual CSize DrawControlCheckBoxMark(CDC* pDC, CRect rc, BOOL bDraw, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bEnabled);

		virtual CSize DrawControlRadioButtonMark(CDC* pDC, CRect rc, BOOL bDraw, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bEnabled);
	protected:
		virtual void DrawSplitButtonPopup(CDC* pDC, CXTPControl* pButton);
		virtual void DrawControlPopupGlyph(CDC* pDC, CXTPControl* pButton);
		virtual void FillPopupLabelEntry(CDC* pDC, CRect rc);
	};

	class _XTP_EXT_CLASS CXTPDefaultTheme : public CXTPPaintManager
	{
	public:
		CXTPDefaultTheme();

		virtual void RefreshMetrics();

		virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);

		virtual COLORREF GetRectangleTextColor(BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		virtual CSize DrawCommandBarGripper(CDC* pDC, CXTPCommandBar* pBar, BOOL bDraw = TRUE);

		virtual CSize DrawCommandBarSeparator(CDC* pDC, CXTPCommandBar* pBar, CXTPControl* pControl, BOOL bDraw = TRUE);

		virtual void AdjustExcludeRect(CRect& rc, CXTPControl* pControl, BOOL bVertical);

		virtual CRect GetCommandBarBorders(CXTPCommandBar* pBar);

		virtual CSize DrawListBoxControl(CDC* pDC, CXTPControl* pButton, CRect rc, BOOL bSelected, BOOL bDraw, CXTPCommandBars* pCommandBars = 0);

		virtual CSize DrawSpecialControl(CDC* pDC, XTPSpecialControl controlType, CXTPControl* pButton, CXTPCommandBar* pBar, BOOL bDraw, LPVOID lpParam);

		virtual CSize DrawTearOffGripper(CDC* pDC, CRect rcGripper, BOOL bSelected, BOOL bDraw);
		virtual void DrawPopupResizeGripper(CDC* pDC, CRect rcGripper, int nFlags);

	protected:
		virtual CSize DrawControlPopupParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);

		virtual void DrawSplitButtonFrame(CDC* pDC, CXTPControl* pButton, CRect rcButton);

		virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		virtual void DrawImage(CDC* pDC, CPoint pt, CSize sz, CXTPImageManagerIcon* pImage, BOOL bSelected, BOOL bPressed, BOOL bEnabled = TRUE, BOOL bChecked = FALSE, BOOL bPopuped = FALSE, BOOL bToolBarImage = TRUE);

		virtual CSize DrawControlComboBox(CDC* pDC, CXTPControlComboBox* pComboBox, BOOL bDraw);

		virtual CSize DrawControlEdit(CDC* pDC, CXTPControlEdit* pEdit, BOOL bDraw);

		virtual CSize DrawDialogBarGripper(CDC* pDC, CXTPDialogBar* pBar, BOOL bDraw);

		virtual void DrawControlEditFrame(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bSelected);

		virtual void DrawControlComboBoxButton(CDC* pDC, CRect rcBtn, BOOL bEnabled, BOOL bSelected, BOOL bDropped);

		virtual void DrawControlEditSpin(CDC* pDC, CXTPControlEdit* pControlEdit);

		XTPPaintTheme BaseTheme() { return xtpThemeOffice2000; }

	protected:
		void DrawShadedRect(CDC* pDC, CRect& rect);
		virtual CSize GetPopupBarImageSize(CXTPCommandBar* pBar);

	protected:
		int m_nPopupBarText;    // Popup bar text index.
	};

	class _XTP_EXT_CLASS CXTPOffice2003Theme : public CXTPOfficeTheme
	{
	public:
		CXTPOffice2003Theme();

		virtual ~CXTPOffice2003Theme();

		static HBITMAP AFX_CDECL GetModernBitmap(UINT nIDResource);

		static BOOL AFX_CDECL LoadModernToolbarIcons(UINT nIDResource);
		static BOOL AFX_CDECL LoadModernToolbarIcons(UINT nIDResource, UINT* pCommands, int nCount, CSize szIcon = CSize(16, 15)); // <combine CXTPOffice2003Theme::LoadModernToolbarIcons@UINT>

		void ExcludeCorners(CDC* pDC, CRect rc);

	protected:
		virtual void RefreshMetrics();

		virtual void DrawPopupBarGripper(CDC* pDC, int xPos, int yPos, int cx, int cy, BOOL bExpanded = FALSE);

		virtual void FillDockBar(CDC* pDC, CXTPDockBar* pBar);

		virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);

		virtual CSize DrawCommandBarSeparator(CDC* pDC, CXTPCommandBar* pBar, CXTPControl* pControl, BOOL bDraw = TRUE);

		virtual CSize DrawCommandBarGripper(CDC* pDC, CXTPCommandBar* pBar, BOOL bDraw = TRUE);

		virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		virtual CSize DrawSpecialControl(CDC* pDC, XTPSpecialControl controlType, CXTPControl* pButton, CXTPCommandBar* pBar, BOOL bDraw, LPVOID lpParam);

		virtual CRect GetCommandBarBorders(CXTPCommandBar* pBar);

		virtual CSize DrawTearOffGripper(CDC* pDC, CRect rcGripper, BOOL bSelected, BOOL bDraw);

		virtual void DrawStatusBarGripper(CDC* pDC, CRect rcClient);

		virtual void DrawStatusBarPaneBorder(CDC* pDC, CRect rc, CXTPStatusBarPane* pPane, BOOL bGripperPane);

		virtual CSize DrawDialogBarGripper(CDC* pDC, CXTPDialogBar* pBar, BOOL bDraw);

		XTPPaintTheme BaseTheme() { return xtpThemeOffice2003; }

		void CreateGradientCircle();

		virtual BOOL HasFloatingBarGradientEntry(CXTPCommandBar* pBar);

	protected:
		void DrawExpandSymbols(CDC* pDC, BOOL bVertical, CRect rc, BOOL bHiddenExists, COLORREF clr);
		void RectangleEx(CDC* pDC, CRect rc, int nColorBorder, BOOL bHoriz, CXTPPaintManagerColorGradient& color);

	public:
		CXTPPaintManagerColorGradient m_clrDockBar;             // Color of dockbar face
		CXTPPaintManagerColorGradient m_clrCommandBar;          // Color of commandbar face
		CXTPPaintManagerColorGradient m_clrToolbarExpand;       // Toolbar Expand button color.
		CXTPPaintManagerColorGradient m_clrMenuExpand;          // MenuBar Expand button color.
		CXTPPaintManagerColorGradient m_clrMenuExpandedGripper; // Color of popup bar gripper
		CXTPPaintManagerColorGradient m_clrPopupControl;        // color of popup control

		CXTPPaintManagerColor m_clrToolbarShadow;    // Toolbar bottom shadow color
		CXTPPaintManagerColor m_clrStatusPane;       // Color of status bar cell..
		CXTPPaintManagerColor m_clrTearOffGripper;  // TearOff gripper color

		BOOL     m_bLunaTheme;                       // TRUE if luna theme is active.
		BOOL     m_bPlainSeparators;                 // TRUE to draw plain separators

		CImageList m_ilGradientCircle;               // Gradient circle holder.
		CXTPPaintManagerColorGradient m_grcLunaChecked;         // Background color of checked button
		CXTPPaintManagerColorGradient m_grcLunaPushed;          // Background color of pushed button
		CXTPPaintManagerColorGradient m_grcLunaSelected;        // Background color of selected button

	};

	class _XTP_EXT_CLASS CXTPWhidbeyTheme : public CXTPOffice2003Theme
	{
	public:

		CXTPWhidbeyTheme();

		virtual ~CXTPWhidbeyTheme();

		void RefreshMetrics();

	public:

		XTPPaintTheme BaseTheme() { return xtpThemeWhidbey; }

	};

	class _XTP_EXT_CLASS CXTPNativeXPTheme : public CXTPDefaultTheme
	{
	public:

		CXTPNativeXPTheme();

		~CXTPNativeXPTheme();

	protected:

		virtual void RefreshMetrics();

		virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);

		virtual void DrawRectangle(CDC* pDC, CRect rc, BOOL bSelected, BOOL bPressed, BOOL bEnabled, BOOL bChecked, BOOL bPopuped, XTPBarType barType, XTPBarPosition barPosition);

		void DrawControlEntry(CDC* pDC, CXTPControl* pButton);

		COLORREF GetControlTextColor(CXTPControl* pButton);

		virtual CSize DrawCommandBarGripper(CDC* pDC, CXTPCommandBar* pBar, BOOL bDraw = TRUE);

		virtual void FillDockBar(CDC* pDC, CXTPDockBar* pBar);

		void FillDockBarRect(CDC* pDC, CWnd* pWnd, CWnd* pFrame);

		void AdjustExcludeRect(CRect& rc, CXTPControl* pControl, BOOL bVertical);

		void DrawSplitButtonFrame(CDC* pDC, CXTPControl* pButton, CRect rcButton);

		virtual void DrawControlEditFrame(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bSelected);

		virtual void DrawControlComboBoxButton(CDC* pDC, CRect rcBtn, BOOL bEnabled, BOOL bSelected, BOOL bDropped);

		virtual CSize DrawDialogBarGripper(CDC* pDC, CXTPDialogBar* pBar, BOOL bDraw);

		virtual CSize DrawCommandBarSeparator(CDC* pDC, CXTPCommandBar* pBar, CXTPControl* pControl, BOOL bDraw = TRUE);

		XTPPaintTheme BaseTheme() { return xtpThemeNativeWinXP; }

		BOOL IsThemeEnabled() const;

		virtual void DrawControlEditSpin(CDC* pDC, CXTPControlEdit* pControlEdit);

		virtual CSize DrawSpecialControl(CDC* pDC, XTPSpecialControl controlType, CXTPControl* pButton, CXTPCommandBar* pBar, BOOL bDraw, LPVOID lpParam);

	protected:
		CXTPWinThemeWrapper m_themeRebar;           // Rebar theme helper
		CXTPWinThemeWrapper m_themeToolbar;         // Toolbar theme helper
		CXTPWinThemeWrapper m_themeCombo;           // ComboBox theme helper
		CXTPWinThemeWrapper m_themeWindow;          // Window theme helper
		CXTPWinThemeWrapper m_themeSpin;          // Window theme helper
		COLORREF            m_clrEdgeShadowColor;   // Color of toolbar bottom line
		COLORREF            m_clrEdgeHighLightColor;// Color of toolbar top line
		BOOL                m_bFlatMenus;           // TRUE if OS flat menu option enabled
	};

	template <class TBase>
	class CXTPReBarPaintManager : public TBase
	{
	public:

		CXTPReBarPaintManager()
		{
			RefreshMetrics();
		}

		void RefreshMetrics()
		{
			TBase::RefreshMetrics();

			m_themeRebar.OpenThemeData(0, L"REBAR");
		}

		void FillCommandBarEntry (CDC* pDC, CXTPCommandBar* pBar)
		{
			if (pBar->GetPosition() != xtpBarFloating && pBar->GetPosition() != xtpBarPopup)
			{
				if (m_themeRebar.IsAppThemed())
				{
					CXTPWindowRect rcClient(pBar->GetParent());
					pBar->ScreenToClient(&rcClient);

					m_themeRebar.DrawThemeBackground(pDC->GetSafeHdc(), 0, 0, &rcClient, 0);
				}
				else
					pDC->FillSolidRect(CXTPClientRect(pBar), GetSysColor(COLOR_3DFACE));
			}
			else
			{
				TBase::FillCommandBarEntry(pDC, pBar);
			}
		}

	protected:
		CXTPWinThemeWrapper m_themeRebar;  // ReBar theme helper.
	};

}
using namespace XTPPaintThemes;

AFX_INLINE void CXTPPaintManager::SetAnimationDelay(int nAnimationSteps, int nAnimationTime) {
	m_nAnimationSteps = nAnimationSteps;
	m_nAnimationTime = nAnimationTime;
}
AFX_INLINE CFont* CXTPPaintManager::GetRegularFont() {
	return this == NULL ? CFont ::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT)): &m_fontRegular;
}
AFX_INLINE CFont* CXTPPaintManager::GetRegularBoldFont() {
	return &m_fontRegularBold;
}
AFX_INLINE CFont* CXTPPaintManager::GetIconFont() {
	return &m_fontIcon;
}
AFX_INLINE CFont* CXTPPaintManager::GetSmCaptionFont() {
	return &m_fontSmCaption;
}
AFX_INLINE void CXTPPaintManager::ShowKeyboardCues(BOOL bShow) {
	m_bShowKeyboardCues = bShow;
}
AFX_INLINE int CXTPPaintManager::GetShadowOptions() const {
	return m_nShadowOptions;
}
AFX_INLINE CXTPControlGalleryPaintManager* CXTPPaintManager::GetGalleryPaintManager() const {
	return m_pGalleryPaintManager;
}

#endif // #if !defined(__XTPPAINTMANAGER_H__)

// XTPCommandBar.h copy; only changes from 2007-08 bytes: CXTPToolBar vtable 0x7c7384 (ret sizes) has no OnTrackLost/OnTrackEnter/IsResizable/OnPopupRButtonUp slots (Clone follows PreviewAccel at 0x1e8); CXTPCommandBar ctor 0x643f20 stores m_bTrackOnHover at +0x160 (after m_nLockRedraw), m_bGrabFocus at +0xc0

#if !defined(__XTPCOMMANDBAR_H__)
#define __XTPCOMMANDBAR_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Common/XTPSystemHelpers.h"
#include "CommandBars/XTPCommandBarsDefines.h"
#include "CommandBars/XTPHookManager.h"

class CXTPDockBar;
class CXTPControls;
class CXTPControl;
class CXTPControlPopup;
class CXTPCommandBars;
class CXTPCommandBar;
class CXTPCommandBarAnimation;
class CXTPPaintManager;
class CXTPImageManager;
class CXTPPropExchange;
struct XTP_COMMANDBARS_PROPEXCHANGE_PARAM;
class CXTPToolTipContext;
class CXTPCommandBarAnimation;
class CXTPCommandBarKeyboardTip;

#define XTP_TID_HOVER    112223
#define XTP_TID_EXPANDED_POPUP 112224
#define XTP_BOOL_DEFAULT 2
#define XTP_TID_SHOWKEYBOARDTIPS 0xCCCA

class _XTP_EXT_CLASS CXTPCommandBarList : public CXTPCmdTarget
{
public:

	CXTPCommandBarList(CXTPCommandBars* pCommandBars)
	{
		m_pCommandBars = pCommandBars;
	}

	virtual ~CXTPCommandBarList();

public:
	CXTPCommandBar* FindCommandBar(UINT nBarID) const;

	CXTPCommandBars* GetCommandBars() const { return m_pCommandBars; }

	CXTPCommandBar* GetAt(int nIndex) const;

	int GetCount() const;

	virtual CXTPCommandBar* Add(CXTPCommandBar* pCommandBar);

	BOOL Lookup(CXTPCommandBar* pCommandBar) const;

	void RemoveAll();

	void Remove(CXTPCommandBar* pCommandBar);

protected:
	CXTPCommandBars* m_pCommandBars;            // Parent CXTPCommandBars object
	CArray<CXTPCommandBar*, CXTPCommandBar*> m_arrBars;         // Array of CommandBars
};

class _XTP_EXT_CLASS CXTPCommandBar : public CWnd, public CXTPHookManagerHookAble, public CXTPAccessible
{
protected:
	CXTPCommandBar();

	virtual ~CXTPCommandBar();

public:

	int IsTrackingMode() const;

	CXTPControls* GetControls() const;

	void SetControls(CXTPControls* pControls);

	XTPBarType GetType() const;

	XTPBarPosition GetPosition() const;

	void DelayLayout();

	virtual void DelayRedraw();

	virtual BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);

	virtual BOOL LoadMenu(CMenu* pMenu, BOOL bRemoveControls = TRUE);

	CXTPControl* GetControl(int nIndex) const;

	int GetControlCount() const;

	virtual BOOL SetSelected(int nSelected, BOOL bKeyboard = FALSE);

	BOOL SetPopuped(int nPopuped, BOOL bKeyboard = FALSE);

	void SetTitle(LPCTSTR lpszTitle);

	CString GetTitle() const;

	CXTPCommandBars* GetCommandBars() const;

	void SetCommandBars(CXTPCommandBars* pCommandBars);

	CWnd* GetSite() const;

	CFrameWnd* GetFrameSite() const;

	void SetFlags(DWORD dwFlagsAdd, DWORD dwFlagsRemove = 0);

	BOOL SetButtons(UINT* pButtons, int nCount);

	virtual BOOL LoadToolBar(UINT nIDResource, BOOL bLoadIcons = TRUE);

	void SetIconSize(CSize size);

	virtual CSize GetIconSize() const;

	CSize GetLargeIconSize(BOOL bAutoSize) const;

	void SetButtonSize(CSize size);

	virtual CSize GetButtonSize() const;

	void ShowTextBelowIcons(BOOL bTextBelow = TRUE);

	BOOL IsTextBelowIcons() const;

	virtual BOOL Popup(CXTPControlPopup* pControlPopup, BOOL bSelectFirst = FALSE);

	HWND GetTrackFocus() const;

	void SetTrackFocus(HWND hwnd);

	virtual void SetVisible(BOOL bVisible);

	virtual BOOL IsVisible() const;

	virtual BOOL SetPosition(XTPBarPosition barPosition);

	int FindAccel(TCHAR chAccel) const;

	int FindAccelEx(UINT chAccel, BOOL& bSelectOnly) const;

	BOOL IsCustomizeMode() const;

	virtual DROPEFFECT OnCustomizeDragEnter(CXTPControl* pDataObject, CPoint point);

	virtual void OnCustomizeDragLeave();

	virtual DROPEFFECT OnCustomizeDragOver(CXTPControl* pDataObject, CPoint point);

	virtual void OnCustomizeDrop(CXTPControl* pDataObject, DROPEFFECT& dropEffect, CPoint ptDrop, CPoint ptDrag);

	virtual BOOL IsCustomizable() const;

	void EnableCustomization(BOOL bEnable = TRUE);

	virtual void OnRecalcLayout();

	void OnTrackLost();

	void OnTrackEnter();

	CWnd* GetOwnerSite() const;

	void InvalidateParents();

	DWORD GetFlags() const;

	UINT GetBarID() const;

	void SetBarID(UINT nID);

	virtual void OnControlSelected(BOOL bSelected, CXTPControl* pControl);

	BOOL SetStatusText(const CString& strDescription);

	void SetCommandBarData(DWORD_PTR dwData);

	DWORD_PTR GetCommandBarData() const;

	virtual CXTPCommandBar* GetParentCommandBar() const;

	CXTPCommandBar* GetRootParent() const;

	CXTPPaintManager* GetPaintManager() const;

	CXTPImageManager* GetImageManager() const;

	void SetWidth(int nWidth);

	int GetWidth() const;

	void SetPaintManager(CXTPPaintManager* pPaintManager);

	void SetImageManager(CXTPImageManager* pImageManager);

	BOOL IsLayoutRTL() const;

	virtual BOOL IsDialogBar() const;

	virtual BOOL IsRibbonBar() const;

	virtual BOOL IsPopupBar() const;

	virtual void DoPropExchange(CXTPPropExchange* pPX);

	virtual BOOL IsKeyboardCuesVisible() const;

	void SetGrabFocus(BOOL bGrabFocus);

	virtual void Redraw(LPCRECT lpRect = 0, BOOL bAnimate = TRUE);

	virtual void DrawCommandBar(CDC* pDC, CRect rcClipBox);

	void EnableAnimation(BOOL bEnable = TRUE);

	void EnableDoubleBuffer(BOOL bEnable = TRUE);

	BOOL IsAnimationEnabled() const;

	virtual int OnHookMessage(HWND hWnd, UINT nMessage, WPARAM& wParam, LPARAM& lParam, LRESULT& lResult);

	virtual void EnsureVisible(CXTPControl* pControl);

	XTPButtonStyle GetDefaultButtonStyle() const;

	void SetDefaultButtonStyle(XTPButtonStyle buttonStyle);

	void LockRedraw();

	void UnlockRedraw();

	void SetShowGripper(BOOL bShow);

	BOOL GetShowGripper() const;

	virtual CRect GetBorders();

	virtual void FillCommandBarEntry(CDC* pDC);

	BOOL IsResizable() const;

public:
	BOOL IsKeyboardTipsVisible() const;

	virtual void CreateKeyboardTips();

	void OnKeyboardTipChar(UINT chAccel);

	virtual void OnKeyboardTip(CXTPCommandBarKeyboardTip* pTip);

	void HideKeyboardTips();

protected:
	virtual BOOL OnHookKeyDown(UINT nChar, LPARAM lParam);

	virtual CSize CalcDynamicLayout(int nLength, DWORD dwMode);

	virtual BOOL ProcessSpecialKey(XTPSpecialKey key);

	virtual void OnControlsChanged();

	virtual void Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive = FALSE);

	virtual int OnMouseHitTest(CPoint pt);

	virtual void UpdateShortcuts();

protected:

	UINT GetActiveDocTemplate() const;

protected:

	virtual void GenerateCommandBarList(DWORD& nID, CXTPCommandBarList* pCommandBarList, XTP_COMMANDBARS_PROPEXCHANGE_PARAM* pParam);

	virtual void RestoreCommandBarList(CXTPCommandBarList* pCommandBarList);

	BOOL IsHelpMode() const;

	virtual void OnRemoved();

protected:
	void CustomizeFindDropIndex(CXTPControl* pDataObject, const CPoint& point, CRect& rcMarker, int& nDropIndex, BOOL& bDropAfter);
	void CustomizeDrawMarker(CDC* pDC);
	void UpdateDocTemplateControls();
	BOOL IsMouseLocked() const;
	CSize GetAutoIconSize(BOOL bLarge) const;

protected:
	virtual HRESULT GetAccessibleParent(IDispatch** ppdispParent);
	virtual HRESULT GetAccessibleChildCount(long* pcountChildren);
	virtual HRESULT GetAccessibleChild(VARIANT varChild, IDispatch** ppdispChild);
	virtual HRESULT GetAccessibleName(VARIANT varChild, BSTR* pszName);
	virtual HRESULT GetAccessibleRole(VARIANT varChild, VARIANT* pvarRole);
	virtual HRESULT AccessibleLocation(long *pxLeft, long *pyTop, long *pcxWidth, long* pcyHeight, VARIANT varChild);
	virtual HRESULT AccessibleHitTest(long xLeft, long yTop, VARIANT* pvarChild);
	virtual HRESULT GetAccessibleState(VARIANT varChild, VARIANT* pvarState);
	virtual CCmdTarget* GetAccessible();

protected:

	public:
	virtual void OnFinalRelease();
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	void FilterToolTipMessage(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreviewAccel(UINT chAccel);

	afx_msg void OnUpdateCmdUI();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	void OnPopupRButtonUp(CXTPCommandBar* pCommandBar, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseLeave();
	afx_msg void OnPaint();
	afx_msg LRESULT OnPrintClient(WPARAM wParam, LPARAM);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnHelpHitTest(WPARAM, LPARAM lParam);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg LRESULT OnGetObject(WPARAM wParam, LPARAM lParam);

public:
	int              m_nStateFlags;         // State of the command bars.
	static int       s_nHoverDelay;         // Hover delay time
	static int       s_nExpandDelay;        // Expand delay time
	static int       s_nExpandHoverDelay;   // Expand hover delay
	BOOL             m_bComboBar;           // TRUE if it is combo box list

protected:
	BOOL             m_bGrabFocus;          // TRUE to grab current focus.
	int              m_nMRUWidth;           // Recent width.
	int              m_nSelected;           // Selected control index.
	int              m_nPopuped;            // Popuped control index.
	HWND             m_hwndFocus;           // The handle of the window that currently has focus.
	UINT             m_nBarID;              // Command bar's identifier.
	BOOL             m_bVisible;            // TRUE if the command bar is visible.
	BOOL             m_bTracking;           // TRUE if the command bar is in tracking mode.
	CWnd*            m_pSite;               // Command bar's site.
	DWORD            m_nIdleFlags;          // Idle flags.
	DWORD            m_dwFlags;             // Command bar's flags.
	DWORD            m_dwStyle;             // Command bar's styles.
	CString          m_strTitle;            // Command bar's caption.
	XTPBarType       m_barType;             // Type of the command bar.
	CXTPControls*    m_pControls;           // A pointer to controls collection.
	XTPBarPosition   m_barPosition;         // Position of the command bar.
	CXTPCommandBars* m_pCommandBars;        // parent command bars class.
	CWnd*            m_pOwner;              // Owner window.
	CSize            m_szIcons;             // Size of the command bar's icons.
	CSize            m_szButtons;           // Size of the command bar's icons.
	BOOL             m_bTextBelow;          // TRUE if text is shown below the CommandBar buttons.
	BOOL             m_bExecOnRButton;      // TRUE if the control button is executed on a right-click
	BOOL             m_bIgnoreUpdateHandler;// TRUE to skip update handler for all child controls
	BOOL             m_bRecursePopup;       // TRUE if popup bar was opened recursively. See TPM_RECURSE flag description.
	int              m_nLockRecurse;        // TRUE if another popup bar is opened recursively.
	BOOL             m_bKeyboardSelect;     // TRUE if last item was selected by keyboard.
	BOOL             m_bCloseable;          // TRUE if the CommandBar can be closed and\or Hidden
	BOOL             m_bCustomizable;       // TRUE if command bar is customizable.
	CRect            m_rcMarker;            // Marker position.
	BOOL             m_bVerticalMarker;     // TRUE to draw marker vertically.
	DWORD_PTR        m_dwData;              // The 32-bit value associated with the command bar.
	UINT*            m_pReturnCmd;          // Return command holder.
	BOOL             m_bCustomizeDialogPresent; // TRUE if the command bar is present in Customize dialog.
	BOOL             m_bAnimatePopup;       // TRUE to animate popup bar.
	BOOL             m_nLockRedraw;         // TRUE if all drawing routines skipped
public:
	BOOL             m_bTrackOnHover;       // TRUE to select item if mouse stay over control
protected:

	CXTPPaintManager* m_pPaintManager;      // Selected paint manager for command bar
	CXTPImageManager* m_pImageManager;      // Selected image manager for command bar
	BOOL             m_bMultiLine;          // True if multi line commandbar
	XTPButtonStyle   m_buttonStyle;         // Default button Style

	CXTPToolTipContext* m_pToolTipContext;  // Tool tip Context.
	CXTPCommandBarAnimation* m_pAnimation;  // Animation context
private:
	int m_nClickedControl;

	DECLARE_MESSAGE_MAP()
	DECLARE_XTP_COMMANDBAR(CXTPCommandBar)

	class CCommandBarCmdUI;

	DECLARE_INTERFACE_MAP()

	friend class CXTPCommandBars;
	friend class CXTPDockBar;
	friend class CCommandBarCmdUI;
	friend class CXTPControl;
	friend class CXTPControls;
	friend class CXTPControlPopup;
	friend class CXTPToolBar;
	friend class CXTPMouseManager;
	friend class CXTPPopupBar;
	friend class CXTPCustomizeSheet;
	friend class CXTPPaintManager;

};

AFX_INLINE int CXTPCommandBar::IsTrackingMode() const{
	return m_bTracking;
}
AFX_INLINE CXTPControls* CXTPCommandBar::GetControls() const {
	return m_pControls;
}
AFX_INLINE XTPBarType CXTPCommandBar::GetType() const {
	return m_barType;
}
AFX_INLINE XTPBarPosition CXTPCommandBar::GetPosition() const {
	return m_barPosition;
}
AFX_INLINE void CXTPCommandBar::DelayLayout() {
	m_nIdleFlags |= xtpIdleLayout;
}

AFX_INLINE void CXTPCommandBar::DelayRedraw() {
	m_nIdleFlags |= xtpIdleRedraw;
}

AFX_INLINE void CXTPCommandBar::SetTitle(LPCTSTR lpszTitle) {
	m_strTitle = lpszTitle;
	Redraw();
}
AFX_INLINE CString CXTPCommandBar::GetTitle() const {
	return m_strTitle;
}
AFX_INLINE void CXTPCommandBar::SetCommandBars(CXTPCommandBars* pCommandBars){
	m_pCommandBars = pCommandBars;
}
AFX_INLINE HWND CXTPCommandBar::GetTrackFocus() const {
	return m_hwndFocus;
}
AFX_INLINE void CXTPCommandBar::SetTrackFocus(HWND hwnd) {
	m_hwndFocus = hwnd;
}
AFX_INLINE void CXTPCommandBar::SetVisible(BOOL /*bVisible*/) {
}
AFX_INLINE BOOL CXTPCommandBar::IsVisible() const {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::SetPosition(XTPBarPosition /*barPosition*/) {
	return FALSE;
}
AFX_INLINE CSize CXTPCommandBar::CalcDynamicLayout(int, DWORD /*nMode*/) {
	return CSize(0, 0);
}
AFX_INLINE CXTPCommandBar* CXTPCommandBar::GetParentCommandBar() const {
	return NULL;
}
AFX_INLINE void CXTPCommandBar::OnRecalcLayout() {

}
AFX_INLINE BOOL CXTPCommandBar::IsCustomizable() const{
	return m_bCustomizable;
}
AFX_INLINE BOOL CXTPCommandBar::IsDialogBar() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::EnableCustomization(BOOL bEnable) {
	if (!IsDialogBar()) m_bCustomizable = bEnable;
}

AFX_INLINE void CXTPCommandBar::SetIconSize(CSize size) {
	m_szIcons = size;
}
AFX_INLINE void CXTPCommandBar::SetButtonSize(CSize size) {
	m_szButtons = size;
}

AFX_INLINE DWORD CXTPCommandBar::GetFlags() const {
	return m_dwFlags;
}

AFX_INLINE UINT CXTPCommandBar::GetBarID() const {
	return m_nBarID;
}
AFX_INLINE void CXTPCommandBar::SetCommandBarData(DWORD_PTR dwData) {
	m_dwData = dwData;
}
AFX_INLINE DWORD_PTR CXTPCommandBar::GetCommandBarData() const {
	return m_dwData;
}
AFX_INLINE void CXTPCommandBar::LockRedraw() {
	m_nLockRedraw ++;
}
AFX_INLINE void CXTPCommandBar::UnlockRedraw() {
	m_nLockRedraw --;
	if (m_nLockRedraw == 0 && (m_nIdleFlags & xtpIdleRedraw))
		Redraw();
}
AFX_INLINE void CXTPCommandBar::SetGrabFocus(BOOL bGrabFocus) {
	m_bGrabFocus = bGrabFocus;
}
AFX_INLINE BOOL CXTPCommandBar::PreviewAccel(UINT) {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::IsRibbonBar() const {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::IsPopupBar() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::SetBarID(UINT nID) {
	m_nBarID = nID;
}
AFX_INLINE XTPButtonStyle CXTPCommandBar::GetDefaultButtonStyle() const {
	return m_buttonStyle;
}

AFX_INLINE void CXTPCommandBar::SetDefaultButtonStyle(XTPButtonStyle buttonStyle) {
	m_buttonStyle = buttonStyle;
}
AFX_INLINE BOOL CXTPCommandBar::IsResizable() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::OnPopupRButtonUp(CXTPCommandBar* /*pCommandBar*/, CPoint /*point*/) {

}

#endif //#if !defined(__XTPCOMMANDBAR_H__)

// XTPControl.h copy; only changes from 2007-08 bytes: CXTPControl has no m_strKeyboardTip (ctor 0x63c810 builds 7 CStrings 0xd8..0xf0, Copy 0x63cb00 assigns 5 after m_strCaption, SetPrompt 0x639e20 has no index-3 extract) and no m_szIcon (new CControlButtonHide passes 0x168; ctor's last field 0x164); inline bodies that used them dropped

#if !defined(__XTPCONTROL_H__)
#define __XTPCONTROL_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Common/XTPSystemHelpers.h"
#include "CommandBars/XTPCommandBarsDefines.h"

class CXTPControl;
class CXTPControls;
class CXTPCommandBar;
class CXTPImageManager;
class CXTPImageManagerIcon;
class CXTPPaintManager;
class CXTPPropExchange;
class CXTPRibbonGroup;
class CXTPCommandBarList;
class CXTPCommandBars;
struct XTP_COMMANDBARS_PROPEXCHANGE_PARAM;

class CXTPControlActions;

class _XTP_EXT_CLASS CXTPControlAction : public CXTPCmdTarget
{
	DECLARE_DYNAMIC(CXTPControlAction)
protected:
	CXTPControlAction(CXTPControlActions* pActions);

	~CXTPControlAction();

public:
	void SetCaption(LPCTSTR lpszCaption);
	void SetCaption(UINT nIDCaption);// <combine CXTPControl::SetCaption@LPCTSTR>

	int GetID() const;

	CString GetCaption() const;

	void SetDescription(LPCTSTR lpszDescription);

	void SetPrompt(LPCTSTR lpszPrompt);

	CString GetDescription() const;

	void SetIconId(int nId);

	int GetIconId() const;

	void SetHelpId(int nId);

	int GetHelpId() const;

	void SetEnabled(BOOL bEnabled);

	BOOL GetEnabled() const;

	void SetChecked(BOOL bChecked);

	BOOL GetChecked() const;

	BOOL IsVisible() const;

	void SetVisible(BOOL bVisible);

	void SetTag(DWORD_PTR dwTag);

	DWORD_PTR GetTag() const;

	void SetCategory(LPCTSTR lpszCategory);

	CString GetCategory() const;

	void SetTooltip(LPCTSTR lpszTooltip);

	CString GetTooltip() const;

	void SetShortcutText(LPCTSTR lpszShortcutText);

	CString GetShortcutText() const;

	void SetKeyboardTip(LPCTSTR lpszKeyboardTip);

	CString GetKeyboardTip() const;

	void SetEditHint(LPCTSTR lpszEditHint);

	CString GetEditHint() const;

	CXTPCommandBars* GetCommandBars() const;

public:
	CXTPControl* GetControl(int nIndex) const;

	int GetCount() const;

public:
	void RedrawControls();

	void RepositionControls();

public:
	void DoPropExchange(CXTPPropExchange* pPX);

protected:

	void AddControl(CXTPControl* pControl);

	void RemoveControl(CXTPControl* pControl);

	void OnRemoved();

	void OnChanged(int nProperty);

	void OnChanging(int nProperty);

public:
	CCmdTarget* m_pTarget;          // Parameter of action

protected:
	DWORD_PTR m_nTag;               // Action tag.
	int m_nId;                      // Identifier of the action.
	int m_nIconId;                  // Identifier of the action's image.
	int m_nHelpId;                  // Help identifier
	BOOL m_bEnabled;                // TRUE if the action is enabled.
	BOOL m_bChecked;                // TRUE if the action is checked.
	BOOL m_bVisible;                // TRUE if action is visible
	CString m_strCaption;           // Caption of the action.
	CString m_strTooltipText;       // Tooltip text.
	CString m_strDescriptionText;   // Description text.
	CString m_strCategory;          // Category of the action.
	CString m_strShortcutText;      // Shortcut text
	CString m_strEditHint;          // Edit Hint for Combo and Edit Controls
	CString m_strKeyboardTip;       // Keyboard tip

	CArray<CXTPControl*, CXTPControl*> m_arrControls;   // Associated controls
	CXTPControlActions* m_pActions; // Parent actions object

private:
	friend class CXTPControl;
	friend class CXTPControls;
	friend class CXTPControlActions;
};

AFX_INLINE void CXTPControlAction::SetShortcutText(LPCTSTR lpszShortcutText) {
	m_strShortcutText = lpszShortcutText;
}
AFX_INLINE CString CXTPControlAction::GetShortcutText() const {
	return m_strShortcutText;
}
AFX_INLINE void CXTPControlAction::SetDescription(LPCTSTR lpszDescription) {
	m_strDescriptionText = lpszDescription;
}
AFX_INLINE CString CXTPControlAction::GetDescription() const {
	return m_strDescriptionText;
}
AFX_INLINE CString CXTPControlAction::GetTooltip() const {
	return m_strTooltipText;
}
AFX_INLINE void CXTPControlAction::SetTooltip(LPCTSTR lpszTooltip) {
	m_strTooltipText = lpszTooltip;
}
AFX_INLINE CString CXTPControlAction::GetCaption() const {
	return m_strCaption.IsEmpty() ? m_strTooltipText : m_strCaption;
}
AFX_INLINE CString CXTPControlAction::GetEditHint() const {
	return m_strEditHint;
}
AFX_INLINE int CXTPControlAction::GetID () const {
	return m_nId;
}
AFX_INLINE void CXTPControlAction::SetIconId(int nId) {
	if (m_nIconId != nId) {m_nIconId = nId; RedrawControls();}
}
AFX_INLINE int CXTPControlAction::GetIconId() const {
	return m_nIconId <= 0 ? m_nId : m_nIconId;
}
AFX_INLINE void CXTPControlAction::SetHelpId(int nId) {
	m_nHelpId = nId;
}
AFX_INLINE int CXTPControlAction::GetHelpId() const {
	return m_nHelpId <= 0 ? m_nId : m_nHelpId;
}

AFX_INLINE void CXTPControlAction::SetEnabled(BOOL bEnabled) {
	if (m_bEnabled != bEnabled) {m_bEnabled = bEnabled; OnChanged(0); RedrawControls();}
}
AFX_INLINE BOOL CXTPControlAction::GetChecked() const {
	return m_bChecked;
}
AFX_INLINE void CXTPControlAction::SetChecked(BOOL bChecked) {
	if (m_bChecked != bChecked) {m_bChecked = bChecked; OnChanged(1); RedrawControls();}
}
AFX_INLINE BOOL CXTPControlAction::IsVisible() const {
	return m_bVisible;
}
AFX_INLINE void CXTPControlAction::SetVisible(BOOL bVisible) {
	if (m_bVisible != bVisible) { m_bVisible = bVisible; OnChanged(2); RepositionControls();}
}
AFX_INLINE void CXTPControlAction::SetCategory(LPCTSTR lpszCategory) {
	m_strCategory = lpszCategory;
}
AFX_INLINE CString CXTPControlAction::GetCategory() const {
	return m_strCategory;
}
AFX_INLINE void CXTPControlAction::SetTag(DWORD_PTR dwTag) {
	m_nTag = dwTag;
}
AFX_INLINE DWORD_PTR CXTPControlAction::GetTag() const {
	return m_nTag;
}
AFX_INLINE void CXTPControlAction::SetKeyboardTip(LPCTSTR lpszKeyboardTip) {
	m_strKeyboardTip = lpszKeyboardTip;
}
AFX_INLINE CString CXTPControlAction::GetKeyboardTip() const {
	return m_strKeyboardTip;
}

class _XTP_EXT_CLASS CXTPControlActions : public CXTPCmdTarget
{
protected:
	CXTPControlActions(CXTPCommandBars* pCommandBars);

	~CXTPControlActions();

public:
	CXTPControlAction* GetAt(int nIndex) const;

	int GetCount() const;

	CXTPControlAction* FindAction(int nId) const;

	CXTPControlAction* Add(int nId);
	CXTPControlAction* Add(int nId, CXTPControlAction* pAction); // <combine CXTPControlActions::Add@int>

	void DoPropExchange(CXTPPropExchange* pPX);

	void RemoveAll();

	void CreateFromMenu(CMenu* pMenu);

protected:

private:
	void Insert(CXTPControlAction* pAction);

protected:
	CArray<CXTPControlAction*, CXTPControlAction*> m_arrActions;    // Actions array
	CXTPCommandBars* m_pCommandBars;        // Parent CommandBars object

	friend class CXTPCommandBars;
	friend class CXTPControlAction;
};

class _XTP_EXT_CLASS CXTPControl : public CXTPCmdTarget, public CXTPAccessible
{
private:
	class CDocTemplateMap : public CMap<UINT, UINT, BOOL, BOOL>
	{
	public:
		void Copy(CDocTemplateMap& map);
	};

protected:
	CXTPControl();

	virtual ~CXTPControl();

public:
	void SetStyle(XTPButtonStyle buttonStyle);

	XTPButtonStyle GetStyle()  const;

public:

	void SetCaption(LPCTSTR lpszCaption);
	void SetCaption(UINT nIDCaption);// <combine CXTPControl::SetCaption@LPCTSTR>

	virtual CString GetCaption() const;

	void SetShortcutText(LPCTSTR lpszShortcutText);

	CString GetShortcutText() const;

	void SetDescription(LPCTSTR lpszDescription);

	virtual CString GetDescription() const;

	void SetTooltip(LPCTSTR lpszTooltip);

	virtual CString GetTooltip() const;

	void SetKeyboardTip(LPCTSTR lpszKeyboardTip);

	CString GetKeyboardTip() const;

	void SetParameter(LPCTSTR lpszParameter);

	CString GetParameter() const;

	void SetID(int nId);

	int GetID() const;

	long GetIndex() const;

	void SetIconId(int nId);

	int GetIconId() const;

	void SetHelpId(int nId);

	int GetHelpId() const;

	virtual void SetBeginGroup(BOOL bBeginGroup);

	BOOL GetBeginGroup() const;

	virtual void SetEnabled(BOOL bEnabled);

	BOOL GetEnabled() const;

	void SetChecked(BOOL bChecked);

	BOOL GetChecked() const;

	virtual int GetSelected() const;

	virtual void SetFocused(BOOL bFocused);

	virtual BOOL IsFocused() const;

	void SetPressed(BOOL bPressed);

	virtual BOOL GetPressed() const;

	virtual void SetRect(CRect rcControl);

	CRect GetRect() const;

	CXTPCommandBar* GetParent() const;

	virtual BOOL IsVisible(DWORD dwSkipFlags = 0) const;

	virtual BOOL IsCaptionVisible() const;

	void SetVisible(BOOL bVisible);

	CXTPControls* GetControls() const;

	XTPControlType GetType() const;

	void SetFlags(DWORD dwFlags);

	DWORD GetFlags() const;

	void SetTag(DWORD_PTR dwTag);

	DWORD_PTR GetTag() const;

	virtual BOOL Compare(CXTPControl* pOther);

	virtual CXTPCommandBar* GetCommandBar() const;

	void SetCloseSubMenuOnClick(BOOL bCloseOnClick);

	BOOL GetCloseSubMenuOnClick() const;

	void SetExecuteOnPressInterval(int nExecuteOnPressInterval);

	int GetExecuteOnPressInterval() const;

	CXTPRibbonGroup* GetRibbonGroup() const;

	virtual BOOL IsTransparent() const { return FALSE;}

public:

	void SetHideWrap(BOOL bHide);

	virtual void SetHideFlags(DWORD dwFlags);

	BOOL SetHideFlag(XTPControlHideFlags dwFlag, BOOL bSet);

	DWORD GetHideFlags() const;

	CRect GetRowRect() const;

	BOOL GetWrap() const;

	void SetRowRect(CRect rcRow);

	void SetWrap(BOOL bWrap);

	BOOL GetExpanded() const;

	BOOL IsCursorOver() const;

	virtual void OnExecute();

	virtual CSize GetSize(CDC* pDC);

	virtual void Draw(CDC* pDC);

	virtual void OnCalcDynamicSize(DWORD dwMode);

	void DelayRedrawParent();

	void DelayLayoutParent();

	void SetCategory(LPCTSTR lpszCategory);

	CString GetCategory() const;

	CXTPImageManager* GetImageManager() const;

	CXTPPaintManager* GetPaintManager() const;

	virtual CXTPImageManagerIcon* GetImage(int nWidth = 16) const;

	void AssignDocTemplate(UINT nIDResource);

	void ExcludeDocTemplate(UINT nIDResource);

	BOOL IsItemDefault()  const;

	void SetItemDefault(BOOL bDefault);

	BOOL IsTemporary() const;

	void Reset();

	void SetPrompt(LPCTSTR lpszPrompt);

	static CXTPControl* AFX_CDECL FromUI(CCmdUI* pCmdUI);

	void SetCustomIcon(HICON hIcon);

	virtual void DoPropExchange(CXTPPropExchange* pPX);

	virtual void OnUnderlineActivate();

	virtual BOOL GetPopuped() const;

	void RedrawParent(BOOL bAnimate = TRUE);

	LRESULT NotifySite(UINT code);
	LRESULT NotifySite(UINT code, NMXTPCONTROL* pNM);
	LRESULT NotifySite(CWnd* pSite, UINT code, NMXTPCONTROL* pNM);

	virtual void SetAction(CXTPControlAction* pAction);

	CXTPControlAction* GetAction() const;

	virtual void OnThemeChanged();

	virtual void SetWidth(int nWidth);

	virtual void SetHeight(int nHeight);

	int GetWidth() const;

	int GetHeight() const;

	BOOL HasDwmCompositedRect() const;

	virtual CSize GetButtonSize() const;

	virtual CSize GetIconSize() const;

	void SetIconSize(CSize szIcon);

protected:

	virtual BOOL IsFocusable() const;

	void SetIndex(int nIndex) { m_nIndex = nIndex; }

	void SetExpanded(BOOL bExpanded);

	virtual BOOL OnHookKeyDown(UINT nChar, LPARAM lParam);

	virtual BOOL OnHookMouseWheel(UINT nFlags, short zDelta, CPoint point);

	virtual void SetParent(CXTPCommandBar* pParent) { m_pParent = pParent;}

	void ScreenToClient(CPoint* point);

	void ClickToolBarButton(CRect rcActiveRect = CRect(0, 0, 0, 0));

	virtual void Copy(CXTPControl* pControl, BOOL bRecursive = FALSE);

	virtual BOOL OnSetPopup(BOOL bPopup);

	virtual void OnClick(BOOL bKeyboard = FALSE, CPoint pt = CPoint(0, 0));

	virtual void OnLButtonUp(CPoint point);

	virtual BOOL OnRButtonDown(CPoint point);

	virtual BOOL OnRButtonUp(CPoint point);

	virtual BOOL OnLButtonDblClk(CPoint point);

	virtual void OnMouseMove(CPoint point);

	virtual void OnMouseHover();

	virtual BOOL OnSetSelected(int bSelected);

	BOOL IsCustomizeMode() const;

	virtual void CustomizeStartDrag(CPoint point);

	virtual BOOL CustomizeStartResize(CPoint point);

	virtual void OnCustomizeDragOver(CXTPControl* pDataObject, CPoint point, DROPEFFECT& dropEffect);

	virtual BOOL IsCustomizeDragOverAvail(CXTPCommandBar* pCommandBar, CPoint point, DROPEFFECT& dropEffect);

	virtual BOOL IsCustomizeResizeAllow() const;

	virtual int GetCustomizeMinWidth() const;
	virtual int GetCustomizeMinHeight() const;

	void OnCustomizeMouseMove(CPoint point);

	virtual void OnIdleUpdate();

	virtual void OnRemoved();

	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;

protected:
	virtual BOOL IsCustomizeMovable() const;

	virtual void RestoreCommandBarList(CXTPCommandBarList* pCommandBarList);

	virtual void GenerateCommandBarList(DWORD& nID, CXTPCommandBarList* pCommandBarList, XTP_COMMANDBARS_PROPEXCHANGE_PARAM* pParam);

	virtual void OnActionChanged(int nProperty);

	virtual void OnActionChanging(int nProperty);

protected:
	virtual HRESULT GetAccessibleParent(IDispatch** ppdispParent);
	virtual HRESULT GetAccessibleDescription(VARIANT varChild, BSTR* pszDescription);
	virtual HRESULT GetAccessibleChildCount(long* pcountChildren);
	virtual HRESULT GetAccessibleChild(VARIANT varChild, IDispatch** ppdispChild);
	virtual HRESULT GetAccessibleName(VARIANT varChild, BSTR* pszName);
	virtual HRESULT GetAccessibleRole(VARIANT varChild, VARIANT* pvarRole);
	virtual HRESULT AccessibleLocation(long *pxLeft, long *pyTop, long *pcxWidth, long* pcyHeight, VARIANT varChild);
	virtual HRESULT AccessibleHitTest(long xLeft, long yTop, VARIANT* pvarChild);
	virtual HRESULT GetAccessibleState(VARIANT varChild, VARIANT* pvarState);
	virtual CCmdTarget* GetAccessible();
	virtual HRESULT GetAccessibleDefaultAction(VARIANT varChild, BSTR* pszDefaultAction);
	virtual HRESULT AccessibleDoDefaultAction(VARIANT varChild);
	virtual HRESULT AccessibleSelect(long flagsSelect, VARIANT varChild);

	DECLARE_INTERFACE_MAP()

private:
	void OnInvertTracker(CDC* pDC, CRect rect);
	BOOL NeedPressOnExecute() const;

protected:
	DWORD_PTR m_nTag;               // Control tag.
	int m_nIndex;                   // Index of the control.
	int m_nId;                      // Identifier of the control.
	int m_nIconId;                  // Identifier of the control's image.
	int m_nHelpId;                  // Help identifier
	int m_nCustomIconId;            // Identifier of the control's custom image.
	BOOL m_bWrap;                   // TRUE if the control is wrapped.
	BOOL m_bBeginGroup;             // TRUE if the control starts new group.
	BOOL m_bEnabled;                // TRUE if the control is enabled.
	BOOL m_bChecked;                // TRUE if the control is checked.
	BOOL m_bSelected;               // TRUE if the control is selected.
	BOOL m_bPressed;                // TRUE if the control is pushed.
	BOOL m_bTemporary;              // TRUE if the control is temporary.
	CRect m_rcRow;                  // Bounding rectangle of the control's row.
	CRect m_rcControl;              // Bounding rectangle of the control.
	DWORD m_dwHideFlags;            // Hidden flags.
	DWORD m_dwFlags;                // Flags of the control.
	CString m_strCaption;           // Caption of the control.
	CString m_strCustomCaption;     // User defined caption.
	CString m_strShortcutText;      // Shortcut text.
	CString m_strShortcutTextAuto;  // Shortcut text.
	CString m_strTooltipText;       // Tooltip text.
	CString m_strDescriptionText;   // Description text.
	CString m_strParameter;         // Parameter text.
	CXTPControls* m_pControls;      // Parent control collection
	XTPControlType m_controlType;   // Type of the control.
	CXTPCommandBar* m_pParent;      // The Parent command bar.
	BOOL m_bExpanded;               // TRUE if the control is expanded.

	CString m_strCategory;          // Category of the control.
	BOOL m_bDefaultItem;            // TRUE if the item is default popup item;

	CDocTemplateMap m_mapDocTemplatesAssigned;  // Assigned templates.
	CDocTemplateMap m_mapDocTemplatesExcluded;  // Excluded templates.

	XTPButtonStyle m_buttonStyle;   // Button Style.
	XTPButtonStyle m_buttonCustomStyle;         // User defined style of button.
	XTPButtonStyle m_buttonRibbonStyle;         // User defined style of button.

	BOOL m_bCloseSubMenuOnClick;        // TRUE is sub-menus are closed as soon as a control is clicked.
	CXTPRibbonGroup* m_pRibbonGroup;    // Ribbon group of control

	CXTPControlAction* m_pAction;       // Action of the control.
	int m_nWidth;                       // Width of the control.
	int m_nHeight;                      // Height of the control.

	int m_nExecuteOnPressInterval;      // Delay between each message when control is pressed.

private:

	DECLARE_XTP_CONTROL(CXTPControl)

	friend class CXTPControls;
	friend class CXTPCommandBar;
	friend class CXTPToolBar;
	friend class CXTPPopupBar;
	friend class CXTPCustomizeSheet;
	friend class CXTPCustomizeDropSource;
	friend class CXTPRibbonGroup;
	friend class CXTPRibbonGroups;
	friend class CXTPRibbonBar;
	friend class CXTPRibbonControls;
	friend class CXTPControlAction;
	friend class CXTPRibbonQuickAccessControls;
};

AFX_INLINE long CXTPControl::GetIndex() const {
	return m_nIndex;
}
AFX_INLINE void CXTPControl::SetShortcutText(LPCTSTR lpszShortcutText) {
	m_strShortcutText = lpszShortcutText;
}
AFX_INLINE CString CXTPControl::GetShortcutText() const {
	return !m_strShortcutText.IsEmpty() ? m_strShortcutText :
	m_pAction && !m_pAction->GetShortcutText().IsEmpty()  ? m_pAction->GetShortcutText() : m_strShortcutTextAuto;
}
AFX_INLINE void CXTPControl::SetDescription(LPCTSTR lpszDescription) {
	m_strDescriptionText = lpszDescription;
}
AFX_INLINE CString CXTPControl::GetDescription() const {
	return !m_strDescriptionText.IsEmpty() ? m_strDescriptionText : m_pAction ? m_pAction->GetDescription() : _T("");
}
AFX_INLINE CString CXTPControl::GetTooltip() const {
	return !m_strTooltipText.IsEmpty() ? m_strTooltipText : m_pAction ? m_pAction->GetTooltip() : _T("");
}
AFX_INLINE void CXTPControl::SetTooltip(LPCTSTR lpszTooltip) {
	m_strTooltipText = lpszTooltip;
}
AFX_INLINE CString CXTPControl::GetCaption() const {
	return !m_strCustomCaption.IsEmpty() ? m_strCustomCaption : !m_strCaption.IsEmpty() ? m_strCaption : m_pAction ? m_pAction->GetCaption() : _T("");
}
AFX_INLINE void CXTPControl::SetParameter(LPCTSTR lpszParameter) {
	m_strParameter = lpszParameter;
}
AFX_INLINE CString CXTPControl::GetParameter() const {
	return m_strParameter;
}
AFX_INLINE int CXTPControl::GetID () const {
	return m_nId;
}
AFX_INLINE void CXTPControl::SetIconId(int nId) {
	if (m_nIconId != nId) {m_nIconId = nId; RedrawParent();}
}
AFX_INLINE int CXTPControl::GetIconId() const {
	return m_nCustomIconId != 0 ? m_nCustomIconId : m_nIconId > 0 ? m_nIconId : m_pAction ? m_pAction->GetIconId() : m_nId;
}
AFX_INLINE void CXTPControl::SetHelpId(int nId) {
	m_nHelpId = nId;
}
AFX_INLINE int CXTPControl::GetHelpId() const {
	return m_nHelpId > 0 ? m_nHelpId : m_pAction ? m_pAction->GetHelpId() : m_nId;
}
AFX_INLINE void CXTPControl::SetBeginGroup(BOOL bBeginGroup) {
	if (m_bBeginGroup != bBeginGroup) {m_bBeginGroup = bBeginGroup; DelayLayoutParent();}
}
AFX_INLINE BOOL CXTPControl::GetBeginGroup() const {
	return m_bBeginGroup;
}
AFX_INLINE BOOL CXTPControl::GetEnabled() const {
	return m_bEnabled == -1 && m_pAction ? m_pAction->GetEnabled() : m_bEnabled;
}
AFX_INLINE void CXTPControl::SetEnabled(BOOL bEnabled) {
	if (m_bEnabled != bEnabled) {m_bEnabled = bEnabled; RedrawParent();}
}
AFX_INLINE BOOL CXTPControl::GetChecked() const {
	return m_bChecked == -1 && m_pAction ? m_pAction->GetChecked() : m_bChecked;
}
AFX_INLINE void CXTPControl::SetChecked(BOOL bChecked) {
	if (m_bChecked != bChecked) {m_bChecked = bChecked; RedrawParent();}
}
AFX_INLINE int CXTPControl::GetSelected() const {
	return m_bSelected;
}
AFX_INLINE BOOL CXTPControl::GetPressed() const {
	return m_bPressed;
}
AFX_INLINE void CXTPControl::SetPressed(BOOL bPressed) {
	m_bPressed = bPressed;
}
AFX_INLINE void CXTPControl::SetRect(CRect rcControl) {
	m_rcControl = rcControl;
}
AFX_INLINE CRect CXTPControl::GetRect() const {
	return m_rcControl;
}
AFX_INLINE CXTPCommandBar* CXTPControl::GetParent() const {
	return m_pParent;
}
AFX_INLINE BOOL CXTPControl::IsVisible(DWORD dwSkipFlags) const {
	if (m_pAction && !m_pAction->IsVisible()) return FALSE;
	return (m_dwHideFlags & ~dwSkipFlags) == xtpNoHide;
}
AFX_INLINE void CXTPControl::SetHideFlags(DWORD dwFlags) {
	m_dwHideFlags = dwFlags;
}
AFX_INLINE BOOL CXTPControl::SetHideFlag(XTPControlHideFlags dwFlag, BOOL bHide) {
	DWORD dwHideFlags = m_dwHideFlags;
	if (bHide) SetHideFlags (m_dwHideFlags | dwFlag); else SetHideFlags(m_dwHideFlags & ~dwFlag);
	return dwHideFlags != m_dwHideFlags;
}

AFX_INLINE void CXTPControl::SetHideWrap(BOOL bHide) {
	SetHideFlag(xtpHideWrap, bHide);
}
AFX_INLINE DWORD CXTPControl::GetHideFlags() const {
	return m_dwHideFlags;
}
AFX_INLINE CRect CXTPControl::GetRowRect() const {
	return m_rcRow;
}
AFX_INLINE void CXTPControl::SetRowRect(CRect rcRow) {
	m_rcRow = rcRow;
}
AFX_INLINE BOOL CXTPControl::GetWrap() const {
	return m_bWrap;
}
AFX_INLINE void CXTPControl::SetWrap(BOOL bWrap) {
	m_bWrap = bWrap;
}
AFX_INLINE CXTPControls* CXTPControl::GetControls() const {
	return m_pControls;
}

AFX_INLINE BOOL CXTPControl::IsTemporary() const {
	return m_bTemporary;
}
AFX_INLINE XTPControlType CXTPControl::GetType() const {
	return m_controlType;
}
AFX_INLINE BOOL CXTPControl::GetExpanded() const {
	return m_bExpanded;
}
AFX_INLINE void CXTPControl::SetCategory(LPCTSTR lpszCategory) {
	m_strCategory = lpszCategory;
}
AFX_INLINE CString CXTPControl::GetCategory() const {
	return !m_strCategory.IsEmpty() ? m_strCategory : m_pAction ? m_pAction->GetCategory() : _T("");
}
AFX_INLINE void CXTPControl::SetTag(DWORD_PTR dwTag) {
	m_nTag = dwTag;
}
AFX_INLINE DWORD_PTR CXTPControl::GetTag() const {
	return m_nTag;
}
AFX_INLINE void CXTPControl::AssignDocTemplate(UINT nIDResource) {
	m_mapDocTemplatesAssigned.SetAt(nIDResource, TRUE);
}
AFX_INLINE void CXTPControl::ExcludeDocTemplate(UINT nIDResource) {
	m_mapDocTemplatesExcluded.SetAt(nIDResource, TRUE);
}
AFX_INLINE void CXTPControl::OnClick(BOOL /*bKeyboard = FALSE*/, CPoint /*pt = CPoint(0, 0)*/) {
}
AFX_INLINE void CXTPControl::SetStyle(XTPButtonStyle buttonStyle) {
	if (m_buttonStyle != buttonStyle)
	{
		m_buttonStyle = buttonStyle;
		DelayLayoutParent();
	}
}
AFX_INLINE CXTPCommandBar* CXTPControl::GetCommandBar() const {
	return NULL;
}
AFX_INLINE void CXTPControl::SetCloseSubMenuOnClick(BOOL bCloseOnClick) {
	m_bCloseSubMenuOnClick = bCloseOnClick;
}

AFX_INLINE BOOL CXTPControl::GetCloseSubMenuOnClick() const {
	return m_bCloseSubMenuOnClick;
}
AFX_INLINE int CXTPControl::GetCustomizeMinWidth() const {
	return 0;
}
AFX_INLINE int CXTPControl::GetCustomizeMinHeight() const {
	return 0;
}
AFX_INLINE void CXTPControl::SetWidth(int nWidth) {
	if (m_nWidth != nWidth) {
		m_nWidth = nWidth;
		DelayLayoutParent();
	}
}
AFX_INLINE void CXTPControl::SetHeight(int nHeight) {
	if (m_nHeight != nHeight) {
		m_nHeight = nHeight;
		DelayLayoutParent();
	}
}
AFX_INLINE BOOL CXTPControl::OnHookKeyDown(UINT /*nChar*/, LPARAM /*lParam*/) {
	return FALSE;
}
AFX_INLINE BOOL CXTPControl::OnSetPopup(BOOL /*bPopup*/) {
	return FALSE;
}
AFX_INLINE void CXTPControl::OnLButtonUp(CPoint /*point*/) {
}
AFX_INLINE BOOL CXTPControl::OnRButtonDown(CPoint /*point*/) {
	return FALSE;
}
AFX_INLINE BOOL CXTPControl::OnRButtonUp(CPoint /*point*/) {
	return FALSE;
}
AFX_INLINE void CXTPControl::OnMouseMove(CPoint /*point*/) {
}
AFX_INLINE BOOL CXTPControl::IsFocusable() const {
	return FALSE;
}
AFX_INLINE void CXTPControl::SetFocused(BOOL /*bFocused*/) {
}
AFX_INLINE BOOL CXTPControl::IsFocused() const{
	return FALSE;
}
AFX_INLINE void CXTPControl::OnCalcDynamicSize(DWORD /*dwMode*/) {
}

AFX_INLINE CXTPRibbonGroup* CXTPControl::GetRibbonGroup() const {
	return m_pRibbonGroup;
}
AFX_INLINE BOOL CXTPControl::OnHookMouseWheel(UINT /*nFlags*/, short /*zDelta*/, CPoint /*pt*/) {
	return FALSE;
}
AFX_INLINE BOOL CXTPControl::GetPopuped() const {
	return FALSE;
}
AFX_INLINE void CXTPControl::OnIdleUpdate() {

}
AFX_INLINE CXTPControlAction* CXTPControl::GetAction() const {
	return m_pAction;
}
AFX_INLINE void CXTPControl::OnThemeChanged() {

}
AFX_INLINE int CXTPControl::GetWidth() const {
	return m_nWidth;
}
AFX_INLINE int CXTPControl::GetHeight() const {
	return m_nHeight;
}
AFX_INLINE void CXTPControl::OnActionChanged(int /*nProperty*/) {

}
AFX_INLINE void CXTPControl::OnActionChanging(int /*nProperty*/) {

}
AFX_INLINE void CXTPControl::SetExecuteOnPressInterval(int nExecuteOnPressInterval) {
	m_nExecuteOnPressInterval = nExecuteOnPressInterval;
}
AFX_INLINE int CXTPControl::GetExecuteOnPressInterval() const {
	return m_nExecuteOnPressInterval;
}
AFX_INLINE INT_PTR CXTPControl::OnToolHitTest(CPoint /*point*/, TOOLINFO* /*pTI*/) const {
	return -1;
}

#endif // #if !defined(__XTPCONTROL_H__)

// XTPPopupBar.h copy; only change from 2007-08 bytes: CXTPPopupBar ctor 0x67a190 has no m_rcResizeGripper/m_bResizable (m_rcTearOffGripper +0x1b4, m_strTearOffCaption +0x1dc, m_scrollInfo +0x204)

#if !defined(__XTPPOPUPBAR_H__)
#define __XTPPOPUPBAR_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CommandBars/XTPCommandBar.h"

class CXTPControlPopup;
class CXTPCommandBars;

class _XTP_EXT_CLASS CXTPPopupBar : public CXTPCommandBar
{
	DECLARE_XTP_COMMANDBAR(CXTPPopupBar)

private:
	class CControlExpandButton;

protected:
	CXTPPopupBar();

	~CXTPPopupBar();

public:
	static CXTPPopupBar* AFX_CDECL CreatePopupBar(CXTPCommandBars* pCommandBars);

public:
	void SetTearOffPopup(LPCTSTR lpszCaption, UINT nID, int nWidth = 400);

	BOOL IsTearOffPopup(CString& strCaption, UINT& nID, int& nWidth);

	BOOL IsVisible() const;

	BOOL Popup(int xPos, int yPos, LPCRECT rcExclude);
	BOOL Popup(CXTPControlPopup* pControlPopup, BOOL bSelectFirst = FALSE); // <combine CXTPPopupBar::Popup@int@int@LPCRECT>

	CXTPControlPopup* GetControlPopup() const;

	void ExpandBar();

	BOOL DestroyWindow();

	void SetPopupToolBar(BOOL bToolBarType);

	void SetDefaultItem(UINT uItem, BOOL fByPos = FALSE);

	UINT GetDefaultItem(UINT gmdiFlags, BOOL fByPos = FALSE);

	BOOL IsDoubleGripper() const;

	void SetDoubleGripper(BOOL bDoubleGripper = TRUE);

	virtual BOOL IsPopupBar() const;

	BOOL IsContextMenu() const;

protected:

	void DelayRedraw() { Redraw(); }

	CSize CalcDynamicLayout(int nLength, DWORD dwMode);

	BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);

	BOOL SetSelected(int nSelected, BOOL bKeyboard = FALSE);

	BOOL Create();

	void UpdateLocation(CSize sz);

	virtual CRect CalculatePopupRect(CSize sz);

	virtual void UpdateFlags();

	void UpdateExpandingState();

	void DrawCommandBar(CDC* pDC, CRect rcClipBox);

	virtual void OnControlsChanged();

	void OnRecalcLayout();

	CXTPCommandBar* GetParentCommandBar() const;

	virtual void DoPropExchange(CXTPPropExchange* pPX);

	virtual void Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive = FALSE);

	virtual BOOL OnHookKeyDown(UINT nChar, LPARAM lParam);

	void PumpMessage();

	virtual void AdjustExcludeRect(CRect& rc, BOOL bVertical);

public:
	void SetBorders(CRect rcBorders);

	void DisableShadow();

	BOOL IsResizable() const;

protected:
	DECLARE_MESSAGE_MAP()

	virtual CRect GetBorders();

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	LRESULT OnFloatStatus(WPARAM wParam, LPARAM);

private:
	void AdjustScrolling(LPSIZE lpSize, BOOL bDown = FALSE, BOOL bInvalidate = FALSE);
	void TrackTearOff();
	void TrackResize();
	void RecalcSizeLayout();
	void SwitchTearOffTracking(BOOL bShow, CPoint point);
	void _MakeSameWidth(int nStart, int nLast, int nWidth);
	BOOL _MouseInResizeGripper(const POINT& pt);

	void Animate();
	XTPAnimationType GetAnimationType() const;

public:
	static double m_dMaxWidthDivisor;   // Maximum available width of popup

protected:
	CXTPControlPopup* m_pControlPopup;  // Control that popuped the bar.
	CPoint m_ptPopup;                   // Position of the bar.
	CRect m_rcExclude;                  // Excluded area.
	int  m_popupFlags;                  // Flags of the bar.
	BOOL m_bDynamicLayout;              // TRUE if DynamicLayout routine executed.
	BOOL m_bCollapsed;                  // TRUE if popupbar is collapsed.
	BOOL m_bExpanded;                   // TRUE if popupbar is expanded.
	BOOL m_bExpanding;                  // TRUE if popupbar is expanding.

	BOOL m_bTearOffPopup;               // TRUE if popupbar has tear-off option.
	CRect m_rcTearOffGripper;           // Tear-off gripper position.

	BOOL m_bTearOffSelected;            // TRUE if gripper selected.
	UINT_PTR m_nTearOffTimer;           // Tear-off timer.
	BOOL m_bTearOffTracking;            // Tear-off tracking mode.
	CSize m_szTearOffBar;               // Size of the bar.
	CXTPToolBar* m_pTearOffBar;         // Tear-off toolbar pointer.
	CString m_strTearOffCaption;        // Caption of the Tear-off toolbar.
	UINT m_nTearOffID;                  // ID of the Tear-off toolbar.
	int m_nTearOffWidth;                // Width of the Tear-off toolbar.
	BOOL m_bShowShadow;                 // TRUE to show the shadow.
	CRect m_rcBorders;                  // Borders of the bar.
	BOOL m_bDoubleGripper;              // TRUE if popup is state popup type
	BOOL m_bContextMenu;                // TRUE if popup bar is context menu

private:

	struct SCROLLINFO
	{
		struct BTNSCROLL
		{
			void Init(CWnd* pParent, UINT nID)
			{
				m_pParent = pParent;
				m_nID = nID;
				m_rc.SetRectEmpty();
				m_nTimer = 0;
			}

			CRect m_rc;
			UINT m_nTimer;
			CWnd* m_pParent;
			UINT m_nID;

			void KillTimer() { m_pParent->KillTimer(m_nTimer); m_nTimer = 0;}
			void SetTimer() { if (m_nTimer == 0) m_nTimer = (UINT)m_pParent->SetTimer(m_nID, 80, 0); }
			BOOL OnMouseMove(CPoint point)
			{
				if (m_rc.PtInRect(point))
				{
					SetTimer();
					return TRUE;
				} else if (m_nTimer) KillTimer();
				return FALSE;
			}
		};

		BOOL bScroll;
		int nScrollFirst, nScrollLast;
		BTNSCROLL btnUp;
		BTNSCROLL btnDown;

		void Init(CWnd* pWnd, UINT nIDUp, UINT nIDDown)
		{
			btnUp.Init(pWnd, nIDUp);
			btnDown.Init(pWnd, nIDDown);
			bScroll = nScrollFirst = nScrollLast = 0;
		}
	} m_scrollInfo;

private:
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);

	friend class CControlExpandButton;
	friend class CXTPControlPopup;
	friend class CXTPCommandBars;
	friend class CXTPCommandBar;
	friend class CXTPCommandBarsContextMenus;
};

class _XTP_EXT_CLASS CXTPPopupToolBar : public CXTPPopupBar
{
	DECLARE_XTP_COMMANDBAR(CXTPPopupToolBar)

	CXTPPopupToolBar();

public:

	static CXTPPopupToolBar* AFX_CDECL CreatePopupToolBar(CXTPCommandBars* pCommandBars);

protected:

	CSize CalcDynamicLayout(int nLength, DWORD dwMode);
};

AFX_INLINE void CXTPPopupBar::DisableShadow() {
	m_bShowShadow = FALSE;
}
AFX_INLINE void CXTPPopupBar::SetBorders(CRect rcBorders) {
	m_rcBorders = rcBorders;
}
AFX_INLINE BOOL CXTPPopupBar::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) {
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
AFX_INLINE BOOL CXTPPopupBar::IsDoubleGripper() const {
	return m_bDoubleGripper;
}
AFX_INLINE void CXTPPopupBar::SetDoubleGripper(BOOL bDoubleGripper /*= TRUE*/) {
	m_bDoubleGripper = bDoubleGripper;
}
AFX_INLINE CXTPControlPopup* CXTPPopupBar::GetControlPopup() const {
	return m_pControlPopup;
}
AFX_INLINE BOOL CXTPPopupBar::IsPopupBar() const {
	return TRUE;
}
AFX_INLINE BOOL CXTPPopupBar::IsContextMenu() const {
	return m_bContextMenu;
}

#endif // #if !defined(__XTPPOPUPBAR_H__)

// XTPMenuBar.h copy; only change from 2007-08 bytes: CXTPRibbonBar vtable 0x7d51dc starts its own slots (GetTabsHeight) at 0x208 right after LoadMenuBar 0x204, so RefreshSysButtons has no slot

#if !defined(__XTPMENUBAR_H__)
#define __XTPMENUBAR_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CommandBars/XTPToolBar.h"
#include "CommandBars/XTPCommandBarsDefines.h"

#define XTP_IDR_MENUBAR                 1

class CXTPCommandBars;

class CXTPMenuBarMDIMenuInfo : public CXTPCmdTarget
{
public:
	CXTPMenuBarMDIMenuInfo(CXTPCommandBars* pCommandBars, UINT nIDResource);
	~CXTPMenuBarMDIMenuInfo();

public:
	CXTPControls* m_pControls;  // Menu controls
	CString m_strTitle;         // Title of MDI menu
	CString m_strDescription;   // Description of MDI menu
	HICON m_hIcon;              // Menu Icon
	UINT m_nIDResource;         // Template identifier
	BOOL m_bChanged;            // TRUE if menu was changed.

};

class CXTPMenuBar;

class _XTP_EXT_CLASS CXTPMenuBarMDIMenus : public CXTPCmdTarget
{
public:

	CXTPMenuBarMDIMenus(CXTPMenuBar* pMenuBar);

	~CXTPMenuBarMDIMenus();

public:

	int GetCount() const;

	void SetAt(UINT nIDResource, CXTPMenuBarMDIMenuInfo* pInfo);
	CXTPMenuBarMDIMenuInfo* Lookup(UINT nIDResource) const;
	void Remove(UINT nIDResource);
	void RemoveAll();
	POSITION GetStartPosition() const;
	void GetNextMenu(POSITION& pos, CXTPMenuBarMDIMenuInfo*& pInfo) const;

protected:
	CMap<UINT, UINT, CXTPMenuBarMDIMenuInfo*, CXTPMenuBarMDIMenuInfo*> m_mapMenus;          // Menu map
	CXTPMenuBar* m_pMenuBar;            // Parent Menu Bar
};

class _XTP_EXT_CLASS CXTPMenuBar : public CXTPToolBar
{
public:
	CXTPMenuBar();

	~CXTPMenuBar();

public:

	virtual BOOL LoadMenuBar(UINT nIDResource);

	void FreeMDIMenus();

	void RefreshMenu();

	UINT GetCurrentMenuResource() const;

	UINT GetDefaultMenuResource() const;

	CXTPMenuBarMDIMenus* GetMDIMenus() const;

	void SwitchMDIMenu(UINT nIDMenu, CMenu* pMenu = NULL);

	CXTPMenuBarMDIMenuInfo* AddMDIMenu(UINT nIDResource);

	void SwitchActiveMenu();

protected:
	int OnHookMessage(HWND hWnd, UINT nMessage, WPARAM& wParam, LPARAM& lParam, LRESULT& lResult);

	virtual void Reset(BOOL bShowWarningMessage);

	void DoPropExchange(CXTPPropExchange* pPX);

	virtual void Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive = FALSE);

protected:

	void SetupHook();

	HWND GetActiveMdiChildWnd(BOOL* bMaximized = NULL);

	void SyncActiveMdiChild();

	void RefreshSysButtons();

	void SwitchMDIMenu(HMENU hMenu);

	void GenerateCommandBarList(DWORD& nID, CXTPCommandBarList* pCommandBarList, XTP_COMMANDBARS_PROPEXCHANGE_PARAM* pParam);

	void RestoreCommandBarList(CXTPCommandBarList* pCommandBarList);

	BOOL ShouldSerializeBar();

protected:

	DECLARE_MESSAGE_MAP()

	afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
	void AddSysButton(CXTPControl* pControl, int nId, LPCTSTR lpszParameter, int nBefore = -1);
	BOOL IsMDIMenusChanged();
	BOOL IsOleDocumentActive(HWND hWndActiveChild) const;

protected:
	BOOL m_bMdiApp;             // TRUE if parent frame is CMDIFrameWnd derived.
	HWND m_hWndActiveChild;     // Active MDI window handle.
	HMENU m_hMenuDefault;       // Default menu handle.

	UINT m_nIDResource;         // Resource of default menu.
	UINT m_nIDResourceCurrent;  // Currently active menu.
	CXTPMenuBarMDIMenus* m_pMDIMenus;   // MDI menus.

private:
	BOOL m_bDirtyMenu;

private:
	DECLARE_XTP_COMMANDBAR(CXTPMenuBar)

	class CControlMDIButton;
	class CControlMDISysMenuPopup;

	friend class CXTPCommandBars;
	friend class CControlMDIButton;
	friend class CCommandBarsSite;
	friend class CCommandBarsCtrl;
};

AFX_INLINE UINT CXTPMenuBar::GetCurrentMenuResource() const {
	return m_nIDResourceCurrent;
}
AFX_INLINE UINT CXTPMenuBar::GetDefaultMenuResource() const {
	return m_nIDResource;
}
AFX_INLINE CXTPMenuBarMDIMenus* CXTPMenuBar::GetMDIMenus() const {
	return m_pMDIMenus;
}

#endif //#if !defined(__XTPMENUBAR_H__)

// XTPRibbonPopups.h copy; only changes from 2007-08 bytes: CXTPRibbonScrollableBar vtable 0x7df600 has 2 slots (ret 4, ret 4: no HitTestGroup), InitScrollableBar 0x6a87f0 uses +4..+0x10 only and m_pRibbonTab sits at +0x14 (0x25c-0x248): no m_pHighlightedGroup

#if !defined(__XTPRIBBONPOPUPS_H__)
#define __XTPRIBBONPOPUPS_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXTPRibbonTheme;
class CXTPRibbonQuickAccessControls;
class CXTPRibbonTab;
class CXTPRibbonControlTab;
class CXTPTabPaintManager;
class CXTPRibbonBar;
class CXTPRibbonGroup;
class CXTPOffice2007FrameHook;
class CXTPRibbonTabContextHeaders;
class CXTPRibbonGroups;

#include "CommandBars/XTPControls.h"
#include "CommandBars/XTPMenuBar.h"
#include "CommandBars/XTPPopupBar.h"

class CXTPRibbonScrollableBar
{
public:
	CXTPRibbonScrollableBar();
private:
	class CControlGroupsScroll;

protected:
	void InitScrollableBar(CXTPCommandBar* pParent);

	void ShowScrollableRect(CXTPRibbonGroups* pGroups, CRect rc);

public:
	void EnableGroupsScroll(BOOL bScrollLeft, BOOL bScrollRight);
	virtual void OnGroupsScroll(BOOL bScrollLeft) = 0;
	virtual CRect GetGroupsRect() const = 0;

	void CreateGroupKeyboardTips(CXTPRibbonTab* pSelectedTab);

	CXTPRibbonGroup* GetHighlightedGroup() const;

	void HighlightGroup(CXTPRibbonGroup* pHighlightedGroup);

protected:
	void CreateControlKeyboardTips(CXTPControl* pControl, LPCTSTR lpszPrefix, BOOL bVisible);

public:
	int m_nGroupsScrollPos;         // Groups scroll position

protected:
	CXTPCommandBar* m_pParent;
	CXTPControl* m_pControlScrollGroupsLeft;    // Control to draw left scroll
	CXTPControl* m_pControlScrollGroupsRight;   // Control to draw right scroll

};

CXTPRibbonScrollableBar* AFX_CDECL GetScrollableBar(CXTPCommandBar* pCommandBar);

class _XTP_EXT_CLASS CXTPRibbonTabPopupToolBar : public CXTPPopupToolBar, public CXTPRibbonScrollableBar
{
	DECLARE_DYNAMIC(CXTPRibbonTabPopupToolBar)
public:
	CXTPRibbonTabPopupToolBar(CXTPRibbonTab* pRibbonTab);

	~CXTPRibbonTabPopupToolBar();

public:
	CRect GetGroupsRect() const;
	void OnGroupsScroll(BOOL bScrollLeft);
	void EnsureVisible(CXTPControl* pControl);
	void CreateKeyboardTips();
	CSize CalcDynamicLayout(int, DWORD /*nMode*/);
	void DrawCommandBar(CDC* pDC, CRect rcClipBox);
	virtual CSize GetButtonSize() const;
	virtual CSize GetIconSize() const;
	virtual CRect CalculatePopupRect(CSize sz);
	CXTPRibbonGroup* HitTestGroup(CPoint point) const;
	virtual BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);
	void OnKeyboardTip(CXTPCommandBarKeyboardTip* pTip);
	BOOL IsKeyboardCuesVisible() const;
	INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;

protected:
	void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

	DECLARE_MESSAGE_MAP()

public:
	CXTPRibbonTab* m_pRibbonTab;
	CXTPRibbonBar* m_pRibbonBar;
	CRect m_rcGroups;

};

class CXTPRibbonBarMorePopupToolBar : public CXTPPopupToolBar
{
	DECLARE_DYNAMIC(CXTPRibbonBarMorePopupToolBar)

public:
	CXTPRibbonBarMorePopupToolBar(CXTPRibbonBar* pRibbonBar);

public:
	void FillCommandBarEntry(CDC* pDC);
	CSize GetIconSize() const;
	CSize GetButtonSize() const;

public:
	CXTPRibbonBar* m_pRibbonBar;
};

class CXTPRibbonGroupPopupToolBar : public CXTPPopupToolBar, public CXTPRibbonScrollableBar
{
	DECLARE_XTP_COMMANDBAR(CXTPRibbonGroupPopupToolBar)
public:
	CXTPRibbonGroupPopupToolBar(CXTPRibbonGroup* pRibbonGroup = NULL);
	~CXTPRibbonGroupPopupToolBar();

public:
	CSize CalcDynamicLayout(int, DWORD /*nMode*/);
	void DrawCommandBar(CDC* pDC, CRect rcClipBox);
	void CreateKeyboardTips();
	CSize GetIconSize() const;
	CSize GetButtonSize() const;
	virtual void OnGroupsScroll(BOOL bScrollLeft);
	virtual CRect GetGroupsRect() const;
	virtual BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);
	virtual CXTPRibbonGroup* HitTestGroup(CPoint point) const;
	BOOL IsKeyboardCuesVisible() const;
protected:
	void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

	DECLARE_MESSAGE_MAP()

public:
	CXTPRibbonGroup* m_pRibbonGroup;
	CXTPRibbonBar* m_pRibbonBar;

	CXTPRibbonGroup* m_pParentGroup;
};

#endif // !defined(__XTPRIBBONPOPUPS_H__)

// XTPRibbonBar.h copy; only changes from 2007-08 bytes: no SetRibbonMinimized slot (CXTPRibbonBar vtable 0x7d51dc: GetTabsHeight 0x208, GetGroupsHeight 0x20c, CalcGroupsHeight 0x210); GetHighlightedGroup bodies dropped (no m_pHighlightedGroup)

#if !defined(__XTPRIBBONBAR_H__)
#define __XTPRIBBONBAR_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXTPRibbonTheme;
class CXTPRibbonQuickAccessControls;
class CXTPRibbonTab;
class CXTPRibbonControlTab;
class CXTPTabPaintManager;
class CXTPRibbonBar;
class CXTPRibbonGroup;
class CXTPOffice2007FrameHook;
class CXTPRibbonTabContextHeaders;
class CXTPRibbonGroups;

#include "CommandBars/XTPControls.h"
#include "CommandBars/XTPMenuBar.h"
#include "CommandBars/XTPPopupBar.h"
#include "Ribbon/XTPRibbonPopups.h"

class _XTP_EXT_CLASS CXTPRibbonBar : public CXTPMenuBar, public CXTPRibbonScrollableBar
{
private:
	class CControlCaptionButton;
	class CControlQuickAccessMorePopup;
	class CControlQuickAccessCommand;

private:
	DECLARE_XTP_COMMANDBAR(CXTPRibbonBar)

public:
	CXTPRibbonBar();

	virtual ~CXTPRibbonBar();

public:
	CXTPRibbonTab* AddTab(LPCTSTR lpszCaption);
	CXTPRibbonTab* AddTab(int nID); // <combine CXTPRibbonBar::AddTab@LPCTSTR>

	CXTPRibbonTab* InsertTab(int nItem, int nID);
	CXTPRibbonTab* InsertTab(int nItem, LPCTSTR lpszCaption, int nID = 0); // <combine CXTPRibbonBar::InsertTab@int@int>

	CXTPRibbonTab* GetSelectedTab() const;

	CXTPRibbonTab* GetTab(int nIndex) const;

	CXTPRibbonTab* FindTab(int nId) const;

	CXTPRibbonGroup* FindGroup(int nId) const;

	int GetTabCount() const;

	CXTPRibbonTheme* GetRibbonPaintManager() const;

	void SetCurSel(int nIndex);

	CSize GetButtonSize() const;

	int GetCurSel() const;

	CXTPTabPaintManager* GetTabPaintManager() const;

	CXTPRibbonGroup* GetHighlightedGroup() const;

	BOOL IsGroupsVisible() const;

	BOOL IsTabsVisible() const;

	BOOL IsRibbonBarVisible() const;

	virtual void SetVisible(BOOL bVisible);

	void SetGroupsVisible(BOOL bVisible);

	void SetTabsVisible(BOOL bVisible);

	CXTPRibbonControlTab* GetControlTab() const;

	void SetMinimumVisibleWidth(int nMinVisibleWidth);

	int GetMinimumVisibleWidth() const;

	CXTPRibbonQuickAccessControls* GetQuickAccessControls() const;

	CXTPControlPopup* AddSystemButton(int nID = 0);

	CXTPControlPopup* GetSystemButton() const;

	virtual BOOL IsRibbonBar() const;

	void RemoveAllTabs();

	void RemoveTab(int nIndex);

	virtual void EnsureVisible(CXTPControl* pControl);

public:
	void EnableFrameTheme(BOOL bEnable = TRUE);

	BOOL IsFrameThemeEnabled() const;

	void ShowQuickAccessBelowRibbon(BOOL bBelow = TRUE);

	BOOL IsQuickAccessBelowRibbon() const;

	void ShowQuickAccess(BOOL bShow = TRUE);

	BOOL IsQuickAccessVisible() const;

	void AllowQuickAccessDuplicates(BOOL bAllow);

	void AllowQuickAccessCustomization(BOOL bAllow);

	BOOL IsAllowQuickAccessDuplicates() const;

	void SelectNextTab(BOOL bNext);

	void SetRibbonMinimized(BOOL bMinimized);

	BOOL IsRibbonMinimized() const;

	void AllowMinimize(BOOL bAllow);

public:

	void RebuildControls(CXTPRibbonTab* pSelected);

	CRect GetTabControlRect() const;

	CRect GetCaptionRect() const;

	CRect GetCaptionTextRect() const;

	CRect GetQuickAccessRect() const;

	CXTPRibbonGroup* HitTestGroup(CPoint point) const;

	virtual int GetTabsHeight() const;

	int GetQuickAccessHeight() const;

	int CalcQuickAccessHeight();

	virtual int GetGroupsHeight();

	CRect GetGroupsRect() const;

	virtual int CalcGroupsHeight();

	void SetGroupsHeight(int nHeight);

	int GetCaptionHeight() const;

	CXTPRibbonTabContextHeaders* GetContextHeaders() const;

	BOOL IsQuickAccessControl(CXTPControl* pControl) const;

	virtual BOOL IsAllowQuickAccessControl(CXTPControl* pControl);

	virtual void DrawCommandBar(CDC* pDC, CRect rcClipBox);

	CXTPOffice2007FrameHook* GetFrameHook() const;

	BOOL IsDwmEnabled() const;

	void SetFontHeight(int nFontHeight);

	int GetFontHeight() const;

	BOOL IsCaptionVisible() const;

	void ShowCaptionAlways(BOOL bShowCaption);

	virtual CSize GetIconSize() const;

	CXTPControl* GetControlQuickAccess() const;

	BOOL IsKeyboardCuesVisible() const;

protected:
	virtual BOOL OnTabChanging(CXTPRibbonTab* pTab);

	virtual void OnTabChanged(CXTPRibbonTab* pTab);

protected:

	void GenerateCommandBarList(DWORD& nID, CXTPCommandBarList* pCommandBarList, XTP_COMMANDBARS_PROPEXCHANGE_PARAM* pParam);

	void RestoreCommandBarList(CXTPCommandBarList* pCommandBarList);

	void DoPropExchange(CXTPPropExchange* pPX);
	void Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive = FALSE);
	virtual CXTPPopupBar* CreateContextMenu(CXTPControl* pSelectedControl);
	virtual CXTPPopupBar* CreateMoreQuickAccessContextMenu();
	virtual BOOL ShouldSerializeBar();
	virtual void MergeToolBar(CXTPCommandBar* pCommandBar, BOOL bSilent);
	int HitTestCaption(CPoint point) const;
	void RepositionCaptionButtons();
	void RepositionContextHeaders();
	void AddCaptionButton(int nId, BOOL bAdd, BOOL bEnabled, CRect& rcCaption);
	BOOL ShrinkContextHeaders(int nLeft, int nRight);
	void ShowContextMenu(CPoint point, CXTPControl* pSelectedControl);
	virtual void CreateKeyboardTips();
	virtual void OnKeyboardTip(CXTPCommandBarKeyboardTip* pTip);
	virtual void OnCustomizeDrop(CXTPControl* pDataObject, DROPEFFECT& dropEffect, CPoint ptDrop, CPoint ptDrag);
	void RefreshSysButtons();

protected:

	public:
	virtual CSize CalcDockingLayout(int nLength, DWORD dwMode, int nWidth = 0);
	void Reposition(int cx, int cy);
	void RepositionGroups(CDC* pDC, CRect rcGroups);
	virtual BOOL PreviewAccel(UINT chAccel);
	virtual BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);
	int OnHookMessage(HWND /*hWnd*/, UINT nMessage, WPARAM& wParam, LPARAM& lParam, LRESULT& /*lResult*/);
	void OnRemoved();
	void OnGroupsScroll(BOOL bScrollLeft);

protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	afx_msg void OnSysColorChange();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	void OnPopupRButtonUp(CXTPCommandBar* pCommandBar, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCustomizePlaceQuickAccess(UINT nCommand);
	afx_msg LRESULT OnCustomizeCommand(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNcHitTest(CPoint point);

protected:

protected:
	CRect m_rcTabControl;           // Bounding rectangle of Tabs
	CRect m_rcGroups;               // Groups bounding rectangle
	CRect m_rcCaption;              // Caption bounding rectangle
	CRect m_rcCaptionText;          // Caption text bounding rectangle
	CRect m_rcHeader;               // Header bounding rectangle
	CRect m_rcQuickAccess;          // Quick access bounding rectangle

	BOOL m_bRibbonBarVisible;       // TRUE if ribbon bar visible
	BOOL m_bGroupsVisible;          // TRUE if groups is visible
	BOOL m_bTabsVisible;            // TRUE if tabs are visible
	BOOL m_bShowQuickAccessBelow;   // TRUE to show quick access controls below ribbon bar
	BOOL m_bShowQuickAccess;        // TRUE to show quick access
	BOOL m_bAllowQuickAccessDuplicates;         // TRUE to allow quick access duplicates
	BOOL m_bAllowQuickAccessCustomization;      // TRUE to allow quick access customization
	BOOL m_bGroupReducedChanged;    // Some group appear in resize handler
	int m_nQuickAccessHeight;           // Quick Access height
	BOOL m_bAllowMinimize;          // TRUE to allow minimize ribbon

	CXTPRibbonQuickAccessControls* m_pQuickAccessControls;      // Quick AccessControls (not used now)
	CXTPRibbonControlTab* m_pControlTab;        // Control tab pointer
	CXTPControl* m_pControlQuickAccess;         // Quick Access menu control
	CXTPControl* m_pControlQuickAccessMore;     // Quick Access more control
	CXTPControlPopup* m_pControlSystemButton;          // System button control
	BOOL m_bMinimizeOnDblClick;
	int m_nMinVisibleWidth;                     // Minimum width before ribbon bar disappears

	CXTPOffice2007FrameHook* m_pFrameHook;      // Office 2007 Frame hook

	CXTPRibbonTabContextHeaders* m_pContextHeaders;     // Context header collection
	int m_nGroupsHeight;            // Custom groups height

	BOOL m_bMinimized;              // TRUE if Ribbon currently minimized
	BOOL m_bShowCaptionAlways;      // TRUE to show caption even if EnableFrameTheme was not called.
	CString m_strCaptionText;       // Caption text

private:
	friend class CXTPRibbonControlTab;
	friend class CXTPRibbonBarControlQuickAccessPopup;
	friend class CControlQuickAccessMorePopup;
	friend class CXTPRibbonGroup;
	friend class CXTPRibbonControls;
	friend class CXTPRibbonGroups;
};

AFX_INLINE CRect CXTPRibbonBar::GetTabControlRect() const {
	return m_rcTabControl;
}

AFX_INLINE CXTPRibbonControlTab* CXTPRibbonBar::GetControlTab() const {
	return m_pControlTab;
}
AFX_INLINE void CXTPRibbonBar::SetMinimumVisibleWidth(int nMinVisibleWidth) {
	m_nMinVisibleWidth = nMinVisibleWidth;
}
AFX_INLINE int CXTPRibbonBar::GetMinimumVisibleWidth() const {
	return m_nMinVisibleWidth;
}
AFX_INLINE CRect CXTPRibbonBar::GetCaptionRect() const {
	return m_rcCaption;
}
AFX_INLINE CRect CXTPRibbonBar::GetCaptionTextRect() const {
	return m_rcCaptionText;
}
AFX_INLINE CRect CXTPRibbonBar::GetQuickAccessRect() const {
	return m_rcQuickAccess;
}
AFX_INLINE CXTPRibbonQuickAccessControls* CXTPRibbonBar::GetQuickAccessControls() const {
	return m_pQuickAccessControls;
}
AFX_INLINE CXTPControlPopup* CXTPRibbonBar::GetSystemButton() const {
	return m_pControlSystemButton;
}
AFX_INLINE BOOL CXTPRibbonBar::IsRibbonBarVisible() const {
	return m_bVisible && m_bRibbonBarVisible;
}
AFX_INLINE CXTPRibbonTabContextHeaders* CXTPRibbonBar::GetContextHeaders() const {
	return m_pContextHeaders;
}
AFX_INLINE BOOL CXTPRibbonBar::IsRibbonBar() const {
	return TRUE;
}
AFX_INLINE void CXTPRibbonBar::ShowQuickAccess(BOOL bShow) {
	m_bShowQuickAccess = bShow;
	OnRecalcLayout();
}
AFX_INLINE BOOL CXTPRibbonBar::IsQuickAccessVisible() const {
	return m_bShowQuickAccess;
}
AFX_INLINE void CXTPRibbonBar::AllowQuickAccessDuplicates(BOOL bAllow) {
	m_bAllowQuickAccessDuplicates = bAllow;
}
AFX_INLINE void CXTPRibbonBar::AllowQuickAccessCustomization(BOOL bAllow) {
	m_bAllowQuickAccessCustomization = bAllow;
}
AFX_INLINE BOOL CXTPRibbonBar::IsAllowQuickAccessDuplicates() const {
	return m_bAllowQuickAccessDuplicates;
}
AFX_INLINE void CXTPRibbonBar::SetGroupsHeight(int nHeight) {
	m_nGroupsHeight = nHeight;
}
AFX_INLINE CXTPOffice2007FrameHook* CXTPRibbonBar::GetFrameHook() const {
	return m_pFrameHook;
}
AFX_INLINE void CXTPRibbonBar::AllowMinimize(BOOL bAllow) {
	m_bAllowMinimize = bAllow;
}
AFX_INLINE CRect CXTPRibbonBar::GetGroupsRect() const {
	return m_rcGroups;
}
AFX_INLINE void CXTPRibbonBar::ShowCaptionAlways(BOOL bShowCaption) {
	m_bShowCaptionAlways = bShowCaption;
}
AFX_INLINE CXTPControl* CXTPRibbonBar::GetControlQuickAccess() const {
	return m_pControlQuickAccess;
}

#endif // !defined(__XTPRIBBONBAR_H__)

#pragma pack(pop)
#pragma warning(pop)
// XTPRibbonPopups.cpp : implementation file
//
// This file is a part of the XTREME RIBBON MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
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

#include "stdafx.h"
#include "Source/Ribbon/Resource.h"

#include "Common/XTPImageManager.h"
#include "Common/XTPResourceManager.h"
#include "Common/XTPPropExchange.h"
#include "Common/XTPToolTipContext.h"

#include "CommandBars/resource.h"
#include "CommandBars/XTPShortcutManager.h"
#include "CommandBars/XTPCommandBars.h"
#include "CommandBars/XTPPopupBar.h"
#include "CommandBars/XTPControlExt.h"
#include "CommandBars/XTPMouseManager.h"
#include "CommandBars/XTPControlPopup.h"
#include "CommandBars/XTPControlButton.h"
#include "CommandBars/XTPOffice2007FrameHook.h"
#include "CommandBars/XTPCustomizeTools.h"

#include "Source/Ribbon/XTPRibbonTab.h"
#include "Source/Ribbon/XTPRibbonTheme.h"
#include "Source/Ribbon/XTPRibbonQuickAccessControls.h"
#include "Source/Ribbon/XTPRibbonGroups.h"
#include "Source/Ribbon/XTPRibbonGroup.h"
#include "Source/Ribbon/XTPRibbonControlTab.h"
#include "Source/Ribbon/XTPRibbonBar.h"
#include "Source/Ribbon/XTPRibbonSystemButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDSYS_SCROLL 17821


class CXTPRibbonScrollableBar::CControlGroupsScroll : public CXTPControlButton
{
public:
	CControlGroupsScroll(BOOL bScrollLeft)
	{
		SetFlags(xtpFlagSkipFocus | xtpFlagNoMovable);
		m_bScrollLeft = bScrollLeft;
	}

	void Draw(CDC* pDC)
	{
		((CXTPRibbonTheme*)GetParent()->GetPaintManager())->DrawRibbonScrollButton(pDC, this, m_bScrollLeft);
	}

	virtual void OnClick(BOOL /*bKeyboard  = FALSE */, CPoint /*pt  = CPoint */)
	{
		if (GetKeyState(VK_LBUTTON) >= 0)
			return;

		m_bPressed = TRUE;

		CXTPRibbonScrollableBar* pScrollableBar = GetScrollableBar(m_pParent);

		pScrollableBar->OnGroupsScroll(m_bScrollLeft);

		int cmsTimer = GetDoubleClickTime() * 4 / 5;
		m_pParent->SetTimer(IDSYS_SCROLL, cmsTimer, NULL);
		BOOL bFirst = TRUE;

		m_pParent->SetCapture();

		while (::GetCapture() == m_pParent->GetSafeHwnd() && IsVisible())
		{
			MSG msg;

			if (!::GetMessage(&msg, NULL, 0, 0))
			{
				AfxPostQuitMessage((int)msg.wParam);
				break;
			}

			if (msg.message == WM_TIMER && msg.wParam == IDSYS_SCROLL)
			{
				pScrollableBar->OnGroupsScroll(m_bScrollLeft);

				if (bFirst)
				{
					cmsTimer = GetDoubleClickTime() / 10;
					m_pParent->SetTimer(IDSYS_SCROLL, cmsTimer, NULL);
				}
				bFirst = FALSE;
			}
			else if (msg.message == WM_LBUTTONUP)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		ReleaseCapture();
		m_pParent->KillTimer(IDSYS_SCROLL);

		m_bPressed = FALSE;
		if (!IsVisible()) m_bSelected = FALSE;
		RedrawParent(FALSE);
	}

protected:
	BOOL m_bScrollLeft;
};

CXTPRibbonBarMorePopupToolBar::CXTPRibbonBarMorePopupToolBar(CXTPRibbonBar* pRibbonBar)
{
	m_bTrackOnHover = FALSE;
	m_rcBorders = CRect(3, 3, 3, 3);
	m_pRibbonBar = pRibbonBar;
}

IMPLEMENT_DYNAMIC(CXTPRibbonBarMorePopupToolBar, CXTPPopupToolBar)

void CXTPRibbonBarMorePopupToolBar::FillCommandBarEntry(CDC* pDC)
{
	CXTPRibbonTheme* pPaintManager = (CXTPRibbonTheme*)GetPaintManager();
	pPaintManager->FillMorePopupToolBarEntry(pDC, this);
}

CSize CXTPRibbonBarMorePopupToolBar::GetIconSize() const
{
	return m_pRibbonBar->GetIconSize();
}
CSize CXTPRibbonBarMorePopupToolBar::GetButtonSize() const
{
	return m_pRibbonBar->GetButtonSize();
}

CXTPRibbonScrollableBar::CXTPRibbonScrollableBar()
{
	m_pParent = NULL;
	m_pControlScrollGroupsLeft = NULL;
	m_pControlScrollGroupsRight = NULL;
	// 2007-08: no m_pHighlightedGroup

	m_nGroupsScrollPos = 0;
}

void CXTPRibbonScrollableBar::InitScrollableBar(CXTPCommandBar* pParent)
{
	m_pControlScrollGroupsRight = pParent->GetControls()->Add(new CControlGroupsScroll(FALSE));
	m_pControlScrollGroupsLeft = pParent->GetControls()->Add(new CControlGroupsScroll(TRUE));
	m_nGroupsScrollPos = 0;
	m_pParent = pParent;
}

void CXTPRibbonScrollableBar::ShowScrollableRect(CXTPRibbonGroups* pGroups, CRect rc)
{
	int nGroupsScrollPos = pGroups->GetScrollPos();
	CRect rcGroups(GetGroupsRect());

	if (rc.left < 12 && m_pControlScrollGroupsLeft->IsVisible())
	{
		nGroupsScrollPos = nGroupsScrollPos + rc.left - 12;
		if (nGroupsScrollPos < 0) nGroupsScrollPos = 0;
	}
	else if (rc.right > rcGroups.right && m_pControlScrollGroupsRight->IsVisible())
	{
		nGroupsScrollPos = nGroupsScrollPos + rc.right - rcGroups.Width() + 12;
		if (nGroupsScrollPos < 0) nGroupsScrollPos = 0;
	}

	if (nGroupsScrollPos != m_nGroupsScrollPos)
	{
		m_nGroupsScrollPos = nGroupsScrollPos;
		pGroups->GetParentTab()->GetParent()->OnRecalcLayout();
	}
}

void CXTPRibbonScrollableBar::EnableGroupsScroll(BOOL bScrollLeft, BOOL bScrollRight)
{
	ASSERT(m_pControlScrollGroupsRight);
	ASSERT(m_pControlScrollGroupsLeft);
	if (!m_pControlScrollGroupsRight || !m_pControlScrollGroupsLeft)
		return;

	CRect rcGroups(GetGroupsRect());

	if (bScrollLeft)
	{
		m_pControlScrollGroupsLeft->SetHideFlag(xtpHideScroll, FALSE);
		m_pControlScrollGroupsLeft->SetRect(CRect(rcGroups.left - 1, rcGroups.top, rcGroups.left + 12, rcGroups.bottom));
	}
	else
	{
		m_pControlScrollGroupsLeft->SetHideFlag(xtpHideScroll, TRUE);
	}

	if (bScrollRight)
	{
		m_pControlScrollGroupsRight->SetHideFlag(xtpHideScroll, FALSE);
		m_pControlScrollGroupsRight->SetRect(CRect(rcGroups.right - 12, rcGroups.top, rcGroups.right + 1, rcGroups.bottom));
	}
	else
	{
		m_pControlScrollGroupsRight->SetHideFlag(xtpHideScroll, TRUE);
	}
}



//////////////////////////////////////////////////////////////////////////
// CXTPRibbonTabPopupToolBar

CXTPRibbonTabPopupToolBar::CXTPRibbonTabPopupToolBar(CXTPRibbonTab* pRibbonTab)
{

	InitScrollableBar(this);

	m_pRibbonBar = pRibbonTab->GetRibbonBar();
	m_pRibbonTab = (CXTPRibbonTab*)pRibbonTab->GetRuntimeClass()->CreateObject();

	m_pRibbonTab->m_pParent = this;
	m_pRibbonTab->m_pRibbonBar = m_pRibbonBar;

	m_pRibbonTab->Copy(pRibbonTab);

	m_pRibbonTab->SetRect(pRibbonTab->GetRect());

	m_bTrackOnHover = FALSE;
	SetFlags(xtpFlagSmartLayout);

	EnableAnimation(m_pRibbonBar->IsAnimationEnabled());
}

CXTPRibbonTabPopupToolBar::~CXTPRibbonTabPopupToolBar()
{
	m_pRibbonTab->OnRemoved();
	m_pRibbonTab->InternalRelease();
}

CRect CXTPRibbonTabPopupToolBar::GetGroupsRect() const
{
	return m_rcGroups;
}

void CXTPRibbonTabPopupToolBar::OnGroupsScroll(BOOL bScrollLeft)
{
	int nGroupsScrollPos = m_pRibbonTab->GetGroups()->GetScrollPos();

	SetPopuped(-1);
	HideKeyboardTips();

	if (bScrollLeft)
	{
		nGroupsScrollPos -= 40;
		if (nGroupsScrollPos < 0)
			nGroupsScrollPos = 0;
	}
	else
	{
		nGroupsScrollPos += 40;
	}

	if (nGroupsScrollPos != m_nGroupsScrollPos)
	{
		m_nGroupsScrollPos = nGroupsScrollPos;
		OnRecalcLayout();
	}
}

void CXTPRibbonTabPopupToolBar::EnsureVisible(CXTPControl* pControl)
{
	if (pControl->GetRibbonGroup() &&
		(m_pControlScrollGroupsLeft->IsVisible() || m_pControlScrollGroupsRight->IsVisible()))
	{
		ShowScrollableRect(m_pRibbonTab->GetGroups(), pControl->GetRect());
	}
}

void CXTPRibbonTabPopupToolBar::CreateKeyboardTips()
{
	CreateGroupKeyboardTips(m_pRibbonTab);
}

CSize CXTPRibbonTabPopupToolBar::CalcDynamicLayout(int, DWORD /*nMode*/)
{
	CRect rcRibbonBar;
	m_pRibbonBar->GetWindowRect(rcRibbonBar);

	CRect rcRibbonTab = m_pRibbonTab->GetRect();
	m_pRibbonBar->ClientToScreen(rcRibbonTab);

	CRect rcWork = XTPMultiMonitor()->GetWorkArea(rcRibbonTab);

	int nHeight = m_pRibbonBar->CalcGroupsHeight();
	int nWidth = rcRibbonBar.Width();

	m_ptPopup.y = m_rcExclude.bottom;
	m_ptPopup.x = rcRibbonBar.left;

	if (m_ptPopup.x < rcWork.left)
	{
		nWidth -= rcWork.left - m_ptPopup.x;
		m_ptPopup.x = rcWork.left;
	}

	if (m_ptPopup.x + nWidth > rcWork.right)
	{
		nWidth = rcWork.right - m_ptPopup.x - 4;
	}

	if (m_ptPopup.y + nHeight > rcWork.bottom)
	{
		m_ptPopup.y = m_rcExclude.top - nHeight;
	}

	CClientDC dc(this);
	CXTPFontDC font(&dc, GetPaintManager()->GetCommandBarFont(this));

	UpdateShortcuts();

	m_rcGroups.SetRect(0, 0, nWidth, nHeight);
	m_pRibbonTab->GetGroups()->CalcDynamicSize(&dc, m_rcGroups.Width(), LM_COMMIT,
		CRect(m_rcGroups.left + 4, m_rcGroups.top + 3, 6, 3));

	m_rcTearOffGripper.SetRectEmpty();


	return CSize(nWidth, nHeight);
}

void CXTPRibbonTabPopupToolBar::DrawCommandBar(CDC* pDC, CRect rcClipBox)
{
	CXTPRibbonTheme* pPaintManager = (CXTPRibbonTheme*)GetPaintManager();

	pPaintManager->FillTabPopupToolBar(pDC, this);
	pPaintManager->FillGroupRect(pDC, m_pRibbonTab, m_rcGroups);
	pDC->SetBkMode(TRANSPARENT);

	CXTPRibbonGroups* pGroups = m_pRibbonTab->GetGroups();
	for (int i = 0; i < pGroups->GetCount(); i++)
	{
		CXTPRibbonGroup* pGroup = pGroups->GetAt(i);

		if (pGroup->IsVisible() && CRect().IntersectRect(rcClipBox, pGroup->GetRect()))
		{
			pGroup->Draw(pDC, rcClipBox);
		}
	}

	if (m_pControlScrollGroupsLeft->IsVisible())
	{
		m_pControlScrollGroupsLeft->Draw(pDC);
	}

	if (m_pControlScrollGroupsRight->IsVisible())
	{
		m_pControlScrollGroupsRight->Draw(pDC);
	}
}

CSize CXTPRibbonTabPopupToolBar::GetButtonSize() const
{
	return m_pRibbonBar->GetButtonSize();
}

CSize CXTPRibbonTabPopupToolBar::GetIconSize() const
{
	return m_pRibbonBar->GetIconSize();

}

CRect CXTPRibbonTabPopupToolBar::CalculatePopupRect(CSize sz)
{
	return CRect(m_ptPopup, sz);
}

CXTPRibbonGroup* CXTPRibbonTabPopupToolBar::HitTestGroup(CPoint point) const
{
	if (!m_rcGroups.PtInRect(point))
		return NULL;

	return m_pRibbonTab->GetGroups()->HitTest(point);
}

BOOL CXTPRibbonTabPopupToolBar::IsKeyboardCuesVisible() const
{
	return m_pRibbonBar->IsKeyboardCuesVisible();
}

void CXTPRibbonTabPopupToolBar::OnKeyboardTip(CXTPCommandBarKeyboardTip* pTip)
{
	CXTPControl* pControl = DYNAMIC_DOWNCAST(CXTPControl, pTip->m_pOwner);
	if (pControl)
	{

		if (pTip->m_bVisible == FALSE && pControl->GetHideFlags() == xtpHideWrap)
		{
			CXTPRibbonGroup* pGroup = pControl->GetRibbonGroup();
			if (pGroup && pGroup->GetControlGroupPopup())
			{
				EnsureVisible(pGroup->GetControlGroupPopup());
				pGroup->GetControlGroupPopup()->OnUnderlineActivate();

				int nIndex = pGroup->IndexOf(pControl);

				CXTPCommandBar* pPopupToolBar = pGroup->GetControlGroupPopup()->GetCommandBar();
				if (pPopupToolBar && pPopupToolBar->IsTrackingMode() && nIndex >= 0 &&
					nIndex < pPopupToolBar->GetControlCount())
				{
					pPopupToolBar->GetControl(nIndex)->OnUnderlineActivate();

				}
			}

			return;
		}

		if (pControl->IsVisible())
		{
			pControl->OnUnderlineActivate();
		}

		return;
	}
}

BEGIN_MESSAGE_MAP(CXTPRibbonTabPopupToolBar, CXTPPopupToolBar)
	//{{AFX_MSG_MAP(CXTPRibbonBar)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE_VOID(WM_MOUSELEAVE, OnMouseLeave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// 2007-08: no CXTPRibbonScrollableBar::m_pHighlightedGroup (HighlightGroup body omitted)

void CXTPRibbonTabPopupToolBar::OnMouseMove(UINT nFlags, CPoint point)
{
	CXTPCommandBars* pCommandBars = GetCommandBars ();
	CXTPMouseManager* pMouseManager = pCommandBars->GetMouseManager();

	BOOL bMouseLocked = pMouseManager->IsMouseLocked() || !pMouseManager->IsTopParentActive(m_hWnd)
		|| pMouseManager->IsTrackedLock(this) || m_nPopuped != -1;

	CXTPRibbonGroup* pHighlightedGroup = bMouseLocked || !m_pRibbonBar->GetRibbonPaintManager()->m_bHotTrackingGroups ?
		NULL : HitTestGroup(point);
	pHighlightedGroup; // 2007-08: no m_pHighlightedGroup

	CXTPPopupToolBar::OnMouseMove(nFlags, point);
}

BOOL CXTPRibbonTabPopupToolBar::SetTrackingMode(int bMode, BOOL bSelectFirst, BOOL bKeyboard)
{
	HighlightGroup(NULL);

	return CXTPPopupToolBar::SetTrackingMode(bMode, bSelectFirst, bKeyboard);
}

void CXTPRibbonTabPopupToolBar::OnMouseLeave()
{
	HighlightGroup(NULL);

	CXTPPopupToolBar::OnMouseLeave();
}

INT_PTR CXTPRibbonTabPopupToolBar::OnToolHitTest(CPoint point, TOOLINFO* pTI) const
{
	INT_PTR nHit = CXTPPopupToolBar::OnToolHitTest(point, pTI);
	if (nHit == -1)
		return -1;

	if (pTI != NULL && pTI->cbSize == sizeof(XTP_TOOLTIP_TOOLINFO_EX) && m_pToolTipContext
		&& m_pToolTipContext->IsShowTitleAndDescription())
	{
		XTP_TOOLTIP_CONTEXT* tc = ((XTP_TOOLTIP_TOOLINFO_EX*)pTI)->pToolInfo;
		if (tc && tc->pObject && ((CXTPControl*)tc->pObject)->GetRibbonGroup())
		{
			tc->rcExclude = m_rcGroups;
		}
	}

	return nHit;
}

IMPLEMENT_DYNAMIC(CXTPRibbonTabPopupToolBar, CXTPPopupToolBar)

CXTPRibbonScrollableBar* AFX_CDECL GetScrollableBar(CXTPCommandBar* pCommandBar)
{
	if (pCommandBar->IsRibbonBar())
		return (CXTPRibbonScrollableBar*)(CXTPRibbonBar*)(pCommandBar);

	if (pCommandBar->IsKindOf(RUNTIME_CLASS(CXTPRibbonTabPopupToolBar)))
		return (CXTPRibbonScrollableBar*)(CXTPRibbonTabPopupToolBar*)(pCommandBar);

	if (pCommandBar->IsKindOf(RUNTIME_CLASS(CXTPRibbonGroupPopupToolBar)))
		return (CXTPRibbonScrollableBar*)(CXTPRibbonGroupPopupToolBar*)(pCommandBar);

	return 0;
}


//////////////////////////////////////////////////////////////////////////
// CXTPRibbonGroupPopupToolBar

IMPLEMENT_XTP_COMMANDBAR(CXTPRibbonGroupPopupToolBar, CXTPPopupToolBar)

CXTPRibbonGroupPopupToolBar::CXTPRibbonGroupPopupToolBar(CXTPRibbonGroup* pRibbonGroup /*= NULL*/)
{
	if (!pRibbonGroup)
	{
		m_pRibbonBar = NULL;
		m_pRibbonGroup = NULL;
		m_pParentGroup = NULL;
		return;
	}
	m_pParent = this;
	m_pRibbonBar = pRibbonGroup->GetRibbonBar();
	m_pRibbonGroup = (CXTPRibbonGroup*)pRibbonGroup->GetRuntimeClass()->CreateObject();
	m_pRibbonGroup->m_pParent = this;
	m_pRibbonGroup->m_pRibbonBar = m_pRibbonBar;
	m_pParentGroup = pRibbonGroup;

	m_pRibbonGroup->OnGroupAdded();
	m_pRibbonGroup->Copy(pRibbonGroup);

	int nHeight = m_pRibbonBar->GetRibbonPaintManager()->GetGroupCaptionHeight();
	m_rcBorders.SetRect(2, 2, 3, nHeight + 1);

	m_bTrackOnHover = FALSE;
	SetFlags(xtpFlagSmartLayout);

	EnableAnimation(m_pRibbonBar->IsAnimationEnabled());
}

CXTPRibbonGroupPopupToolBar::~CXTPRibbonGroupPopupToolBar()
{
	m_pRibbonGroup->OnGroupRemoved();
	m_pRibbonGroup->InternalRelease();
}

CSize CXTPRibbonGroupPopupToolBar::CalcDynamicLayout(int, DWORD /*nMode*/)
{
	m_bDynamicLayout = TRUE;

	CClientDC dc(this);
	CXTPFontDC font(&dc, GetPaintManager()->GetCommandBarFont(this));

	UpdateShortcuts();

	int nGroupHeight = m_pRibbonBar->CalcGroupsHeight();

	m_pRibbonGroup->OnBeforeCalcSize(&dc);
	int nWidth = m_pRibbonGroup->OnCalcDynamicSize(&dc);
	m_pRibbonGroup->OnAdjustBorders(nWidth, CRect(0, 0, 0, 0));
	m_pRibbonGroup->OnAfterCalcSize();

	m_rcTearOffGripper.SetRectEmpty();

	m_bDynamicLayout = FALSE;

	return CSize(nWidth + m_rcBorders.left + m_rcBorders.right, nGroupHeight - 7);
}

void CXTPRibbonGroupPopupToolBar::DrawCommandBar(CDC* pDC, CRect rcClipBox)
{
	m_pRibbonBar->GetRibbonPaintManager()->FillGroupPopupToolBar(pDC, m_pRibbonGroup, this);

	m_pRibbonGroup->Draw(pDC, rcClipBox);
}

void CXTPRibbonGroupPopupToolBar::CreateKeyboardTips()
{
	if (!m_pParentGroup)
		return;

	CXTPRibbonTab* pSelectedTab = m_pParentGroup->GetParentTab();

	for (int i = 0; i < pSelectedTab->GetGroups()->GetCount(); i++)
	{
		CXTPRibbonGroup* pGroup = pSelectedTab->GetGroups()->GetAt(i);
		BOOL bVisible = pGroup->IsVisible() && m_pParentGroup == pGroup;

		if (bVisible)
		{
			pGroup = m_pRibbonGroup;
		}

		for (int j = 0; j < pGroup->GetCount(); j++)
		{
			CXTPControl* pControl = pGroup->GetAt(j);
			CreateControlKeyboardTips(pControl, NULL, bVisible);
		}

		if ((pGroup->GetControlGroupOption()->GetHideFlags() & xtpHideGeneric) == 0)
		{
			CreateControlKeyboardTips(pGroup->GetControlGroupOption(), NULL, bVisible);
		}

		CreateControlKeyboardTips(pGroup->GetControlGroupPopup(), _T("Z"), bVisible);
	}
}

CXTPRibbonGroup* CXTPRibbonGroupPopupToolBar::HitTestGroup(CPoint point) const
{
	if (m_pRibbonGroup && m_pRibbonGroup->GetRect().PtInRect(point))
		return m_pRibbonGroup;

	return NULL;
}


CSize CXTPRibbonGroupPopupToolBar::GetIconSize() const
{
	return m_pRibbonBar->GetIconSize();
}

CSize CXTPRibbonGroupPopupToolBar::GetButtonSize() const
{
	return m_pRibbonBar->GetButtonSize();
}

void CXTPRibbonGroupPopupToolBar::OnGroupsScroll(BOOL /*bScrollLeft*/)
{
}

CRect CXTPRibbonGroupPopupToolBar::GetGroupsRect() const
{
	return CXTPClientRect(this);
}


BEGIN_MESSAGE_MAP(CXTPRibbonGroupPopupToolBar, CXTPPopupToolBar)
	//{{AFX_MSG_MAP(CXTPRibbonBar)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE_VOID(WM_MOUSELEAVE, OnMouseLeave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CXTPRibbonGroupPopupToolBar::OnMouseMove(UINT nFlags, CPoint point)
{
	CXTPCommandBars* pCommandBars = GetCommandBars ();
	CXTPMouseManager* pMouseManager = pCommandBars->GetMouseManager();

	BOOL bMouseLocked = pMouseManager->IsMouseLocked() || !pMouseManager->IsTopParentActive(m_hWnd)
		|| pMouseManager->IsTrackedLock(this) || m_nPopuped != -1;

	CXTPRibbonGroup* pHighlightedGroup = bMouseLocked || !m_pRibbonBar->GetRibbonPaintManager()->m_bHotTrackingGroups ?
		NULL : m_pRibbonGroup;
	pHighlightedGroup; // 2007-08: no m_pHighlightedGroup


	CXTPPopupToolBar::OnMouseMove(nFlags, point);
}

BOOL CXTPRibbonGroupPopupToolBar::SetTrackingMode(int bMode, BOOL bSelectFirst, BOOL bKeyboard)
{
	HighlightGroup(NULL);

	return CXTPPopupToolBar::SetTrackingMode(bMode, bSelectFirst, bKeyboard);
}

void CXTPRibbonGroupPopupToolBar::OnMouseLeave()
{
	HighlightGroup(NULL);

	CXTPPopupToolBar::OnMouseLeave();
}

BOOL CXTPRibbonGroupPopupToolBar::IsKeyboardCuesVisible() const
{
	return m_pRibbonBar->IsKeyboardCuesVisible();
}
