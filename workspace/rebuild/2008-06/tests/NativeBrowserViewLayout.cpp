#include <stddef.h>
#include "CBrowserView.h"
#include "CBrowserDoc.h"
#include "CBrowserViewExternal.h"
// Sizes from CRuntimeClass 0080cf58/0080cf74/0080cf90 (0x2d0) and operator new(0x2d0) in 00410d60/00410dc0/00410e20.
// Base: CSecureHtmlView 0xf8 (CRuntimeClass 0081b840); XTP CXTPCommandBarsSiteBase adds m_pCommandBars at +0xf8
// (constructor 004108b0 clears it, template destructor 0040e230 InternalReleases it, 0040e290/0040e320 read it).
// Members from the constructor 004108b0 and destructor 00410950 (both exact), and the bodies that use them:
// +0xfc std::list<std::string> (ctor 00410830, dtor 0055e5f0, _Myhead +0x110, _Mysize +0x114 in 004109e0/00410ea0),
// +0x118 CXTPControlComboBox* (0040e670 new(0x1e0)), +0x11c CXTPToolBar (ctor 006c1da0, dtor 006c1eb0; m_hWnd +0x13c),
// +0x2c4 CComPtr<IDispatch> (0040fff0), +0x2c8/+0x2c9 bools (0040dfe0), +0x2cc CString (00410c40/00410cd0 assign).
typedef char HtmlViewSize[sizeof(CHtmlView) == 0xf4 ? 1 : -1];
typedef char SecureHtmlViewSize[sizeof(CSecureHtmlView) == 0xf8 ? 1 : -1];
typedef char SiteSize[sizeof(CXTPCommandBarsSiteBase<CSecureHtmlView>) == 0xfc ? 1 : -1];
typedef char BrowserViewSize[sizeof(CBrowserView) == 0x2d0 ? 1 : -1];
typedef char IDEBrowserViewSize[sizeof(CIDEBrowserView) == 0x2d0 ? 1 : -1];
typedef char PlayBrowserViewSize[sizeof(CPlayBrowserView) == 0x2d0 ? 1 : -1];
typedef char HistoryOffset[offsetof(CBrowserView, history) == 0xfc ? 1 : -1];
typedef char HistorySize[sizeof(std::list<std::string>) == 0x1c ? 1 : -1];
typedef char ComboOffset[offsetof(CBrowserView, addressCombo) == 0x118 ? 1 : -1];
typedef char ToolBarOffset[offsetof(CBrowserView, toolBar) == 0x11c ? 1 : -1];
typedef char ToolBarSize[sizeof(CXTPToolBar) == 0x1a8 ? 1 : -1];
typedef char ExternalOffset[offsetof(CBrowserView, external) == 0x2c4 ? 1 : -1];
typedef char BackOffset[offsetof(CBrowserView, canGoBack) == 0x2c8 ? 1 : -1];
typedef char ForwardOffset[offsetof(CBrowserView, canGoForward) == 0x2c9 ? 1 : -1];
typedef char HomeOffset[offsetof(CBrowserView, homeUrl) == 0x2cc ? 1 : -1];
typedef char ComboSize[sizeof(CXTPControlComboBox) == 0x1e0 ? 1 : -1];
// CBrowserDoc: CRuntimeClass 0080cfac (0x58), CreateObject 0040e4f0 (CDocument ctor, +0x54 = 0).
typedef char DocumentSize[sizeof(CDocument) == 0x54 ? 1 : -1];
typedef char BrowserDocSize[sizeof(CBrowserDoc) == 0x58 ? 1 : -1];
typedef char BrowserDocView[offsetof(CBrowserDoc, view) == 0x54 ? 1 : -1];
// CComObjectNoLock<CBrowserViewExternal>: operator new(0x20) in 0040fbf0, RTTI base offsets of vtable 0080d778.
typedef char ExternalObjectSize[sizeof(ATL::CComObjectNoLock<CBrowserViewExternal>) == 0x20 ? 1 : -1];
typedef char ExternalIsIDE[offsetof(CBrowserViewExternal, isIDE) == 0x1c ? 1 : -1];
#include "CBrowserFrameWnd.h"
// CBrowserFrameWnd: CRuntimeClass 00811e90 (0xec), CreateObject 00433280 operator new(0xec).
typedef char BrowserFrameWndSize[sizeof(CBrowserFrameWnd) == 0xec ? 1 : -1];
