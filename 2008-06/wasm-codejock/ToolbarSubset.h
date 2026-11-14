#pragma once
// Browser declarations for the selected source methods. Not MFC/Windows ABI.
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
using BOOL = int;
using UINT = unsigned;
using DWORD = uint32_t;
using COLORREF = uint32_t;
using WPARAM = uintptr_t;
using LPARAM = intptr_t;
using LRESULT = intptr_t;
using HWND = class CWnd*;
using LPCTSTR = const char*;
constexpr BOOL TRUE = 1, FALSE = 0, TRUE_KEYBOARD = 2;
constexpr int TRANSPARENT = 1;
constexpr UINT WM_MOUSEMOVE = 0x200, WM_LBUTTONDOWN = 0x201, WM_LBUTTONUP = 0x202,
    WM_COMMAND = 0x111, WM_TIMER = 0x113, WM_KEYDOWN = 0x100, WM_SIZE = 5, WM_CANCELMODE = 0x1f;
constexpr DWORD LM_HORZDOCK = 0x8, LM_VERTDOCK = 0x10, LM_POPUP = 0x100,
    LM_HIDEWRAP = 0x80, LM_STRETCH = 1;
constexpr DWORD LM_COMMIT=0x40,xtpFlagSmartLayout=0x200000;
constexpr DWORD LM_MRUWIDTH=4,LM_LENGTHY=0x20,xtpFlagRightAlign=1,xtpFlagControlStretched=32;
constexpr int XTP_ID_TOOLBAR_EXPAND=9148,XTP_ID_TOOLBAR_HIDE=9149,xtpHideGeneric=1,
    xtpNoHide=0,xtpIdleLayout=1,xtpButtonExpandToolbar=0;
constexpr DWORD xtpFlagWrapRow = 128;
enum XTPBarPosition {xtpBarTop, xtpBarBottom, xtpBarLeft, xtpBarRight, xtpBarFloating, xtpBarPopup};
enum XTPBarType {xtpBarTypeMenuBar, xtpBarTypeNormal, xtpBarTypePopup};
enum XTPControlType {xtpControlError,xtpControlButton,xtpControlPopup,xtpControlButtonPopup,
    xtpControlSplitButtonPopup,xtpControlComboBox,xtpControlEdit,xtpControlCustom,
    xtpControlLabel,xtpControlCheckBox,xtpControlGallery,xtpControlRadioButton};
enum XTPButtonStyle {xtpButtonUndefined=-1,xtpButtonAutomatic,xtpButtonCaption,xtpButtonIcon,
    xtpButtonIconAndCaption,xtpButtonIconAndCaptionBelow,xtpButtonCaptionAndDescription};
constexpr int xtpHideWrap = 2;
constexpr int COLOR_HIGHLIGHT = 13, COLOR_3DSHADOW = 16, COLOR_BTNHILIGHT = 20,
    COLOR_3DHIGHLIGHT = 20, COLOR_BTNFACE = 15, COLOR_BTNTEXT = 18;
constexpr int COLOR_3DFACE=15,COLOR_3DDKSHADOW=21,COLOR_GRAYTEXT=17,COLOR_HIGHLIGHTTEXT=14;
constexpr int TRUE_SPLITDROPDOWN=4;
constexpr UINT DT_SINGLELINE = 0x20, DT_CENTER = 1, DT_LEFT = 0, DT_VCENTER = 4,
    DT_NOPREFIX = 0x800, DT_NOCLIP = 0x100;
#define ASSERT assert
#define VERIFY(x) assert(x)
#define _T(x) x
#define LOWORD(x) (int16_t((x) & 0xffff))
#define HIWORD(x) (int16_t(((x) >> 16) & 0xffff))
using std::max;
struct CSize {
    int cx, cy;
    CSize(int x = 0, int y = 0) : cx(x), cy(y) {}
    CSize& operator+=(CSize s) {cx+=s.cx;cy+=s.cy;return *this;}
    CSize operator+(CSize s) const {return {cx+s.cx,cy+s.cy};}
    bool operator==(CSize s) const {return cx==s.cx&&cy==s.cy;}
};
struct CPoint {
    int x, y;
    CPoint(int a = 0, int b = 0) : x(a), y(b) {}
    CPoint& operator+=(CSize s) { x += s.cx; y += s.cy; return *this; }
};
struct CRect {
    int left, top, right, bottom;
    CRect(int l = 0, int t = 0, int r = 0, int b = 0) : left(l), top(t), right(r), bottom(b) {}
    CRect(const CRect* r) : CRect(*r) {}
    CRect(CPoint p,CSize s) : CRect(p.x,p.y,p.x+s.cx,p.y+s.cy) {}
    operator CRect*() { return this; }
    int Width() const { return right-left; }
    int Height() const { return bottom-top; }
    CPoint CenterPoint() const { return {(left+right)/2, (top+bottom)/2}; }
    BOOL PtInRect(CPoint p) const { return p.x>=left && p.x<right && p.y>=top && p.y<bottom; }
    BOOL IsRectEmpty() const { return right<=left || bottom<=top; }
    void SetRectEmpty() { left=top=right=bottom=0; }
    void SetRect(int l,int t,int r,int b) { *this={l,t,r,b}; }
    CRect operator+(CPoint p) const { return {left+p.x,top+p.y,right+p.x,bottom+p.y}; }
    void OffsetRect(int x,int y) { left+=x; right+=x; top+=y; bottom+=y; }
    void DeflateRect(int x,int y) {left+=x;top+=y;right-=x;bottom-=y;}
    BOOL IntersectRect(CRect a,CRect b) {
        *this={std::max(a.left,b.left),std::max(a.top,b.top),std::min(a.right,b.right),std::min(a.bottom,b.bottom)};
        return !IsRectEmpty();
    }
    CPoint& TopLeft() { return *reinterpret_cast<CPoint*>(&left); }
};
inline BOOL IsKeyboardSelected(int selected) { return selected>1; }
class CString : public std::string {
public:
    using std::string::string;
    CString(const std::string& s) : std::string(s) {}
    operator const char*() const { return c_str(); }
    BOOL IsEmpty() const { return empty(); }
};
class CDC {
    COLORREF text = 0;
public:
    void FillSolidRect(CRect, COLORREF);
    void Draw3dRect(CRect, COLORREF, COLORREF);
    void DrawText(const CString&, CRect, UINT);
    CSize GetTextExtent(const CString&);
    COLORREF SetTextColor(COLORREF c) { auto old=text; text=c; return old; }
    COLORREF GetTextColor() const { return text; }
    void* GetSafeHdc() {return this;}
    int SetBkMode(int);
    COLORREF SetBkColor(COLORREF);
    void DrawFocusRect(CRect) {UnimplementedFocus();}
    [[noreturn]] void UnimplementedFocus() {throw std::runtime_error("GDI focus rectangle");}
};
struct CFont { const char* family="Tahoma, sans-serif";int size=13;bool bold=false; };
class CXTPFontDC {
public:
    CXTPFontDC(CDC*,CFont*);
    ~CXTPFontDC();
};
inline CRect CXTPEmptyRect() {return {};}
COLORREF GetXtremeColor(int);
void StripMnemonics(CString&);
void DrawTextApi(CDC*, const CString&, CRect*, UINT, BOOL);
struct MSG { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; };
BOOL GetMessage(MSG*, HWND, UINT, UINT);
void DispatchMessage(MSG*);
HWND GetCapture();
void ReleaseCapture();
[[noreturn]] inline void Unported(const char* operation) { throw std::runtime_error(operation); }
class CWnd {
public:
    virtual ~CWnd() = default;
    virtual LRESULT SendMessage(UINT, WPARAM=0, LPARAM=0);
    HWND GetSafeHwnd() { return this; }
    void SetCapture();
    void SetTimer(UINT, UINT, void*);
    void KillTimer(UINT);
};
class CClientDC : public CDC {
public:
    explicit CClientDC(CWnd*) {}
};
class CXTPCommandBar;
class CXTPPaintManager;
class CXTPImageManagerIcon {
public:
    bool m_bDrawComposited=false;
    int GetHeight() {Unported("image manager");}
    int GetWidth() {Unported("image manager");}
};
class CXTPControl {
    int references=1;
public:
    CRect m_rcControl, m_rcRow;
    CXTPCommandBar* m_pParent=nullptr;
    int m_nIndex=0, m_bSelected=0, m_bPressed=0, m_nExecuteOnPressInterval=0;
    BOOL enabled=TRUE, checked=FALSE, visible=TRUE, beginGroup=FALSE, wrap=FALSE;
    DWORD m_dwFlags=0,hideFlags=0;
    int id=0;
    CString caption;
    XTPControlType m_controlType=xtpControlButton;
    BOOL automationEnabled=FALSE;
    virtual ~CXTPControl() = default;
    void EnableAutomation() { automationEnabled=TRUE; }
    virtual void OnClick(BOOL, CPoint)=0;
    virtual void OnLButtonUp(CPoint)=0;
    virtual void OnExecute()=0;
    void ClickToolBarButton(CRect=CRect());
    BOOL OnSetSelected(int);
    BOOL NeedPressOnExecute() const;
    void RedrawParent(BOOL=FALSE);
    void InternalAddRef() { ++references; }
    void InternalRelease() { if (!--references) delete this; }
    int GetIndex() const { return m_nIndex; }
    int GetID() const { return id; }
    BOOL GetEnabled() const { return enabled; }
    BOOL GetChecked() const { return checked; }
    BOOL GetSelected() const { return m_bSelected; }
    BOOL GetPressed() const { return m_bPressed; }
    BOOL GetPopuped() const { return FALSE; } // This subset has no popup controls.
    XTPControlType GetType() const { return m_controlType; }
    CXTPCommandBar* GetParent() const { return m_pParent; }
    CRect GetRect() const { return m_rcControl; }
    CRect GetRowRect() const {return m_rcRow;}
    BOOL GetWrap() const {return wrap;}
    CString GetCaption() const { return caption; }
    BOOL HasDwmCompositedRect() const { return FALSE; } // Canvas is not a DWM surface.
    BOOL IsVisible(int ignore=0) const { return visible&&!(hideFlags&~ignore); }
    BOOL GetBeginGroup() const { return beginGroup; }
    XTPButtonStyle GetStyle() const { return xtpButtonAutomatic; }
    DWORD GetFlags() const { return m_dwFlags; }
    BOOL IsCustomizeMode() const;
    void CustomizeStartDrag(CPoint) { Unported("toolbar customization"); }
    CSize GetSize(CDC*);
    void Draw(CDC*);
    CXTPPaintManager* GetPaintManager() const;
    CSize GetButtonSize() const {return {22,22};}
    CSize GetIconSize() const {return {16,16};}
    BOOL IsCaptionVisible() const;
    BOOL IsItemDefault() const {return FALSE;}
    BOOL IsTransparent() const {return FALSE;}
    int GetIconId() const {return 0;}
    CXTPImageManagerIcon* GetImage(int) const {return nullptr;} // No icons installed in this fixture.
    int GetWidth() const {return 0;}
    int GetHeight() const {return 0;}
    CXTPCommandBar* GetCommandBar() const {return nullptr;}
    void SetHideWrap(BOOL b) { hideFlags=b?(hideFlags|xtpHideWrap):(hideFlags&~xtpHideWrap); }
    void SetHideFlags(DWORD flags) {hideFlags=flags;}
    void OnCalcDynamicSize(DWORD) {} // Fixed caption controls own no per-mode resources.
    void SetRowRect(CRect r) { m_rcRow=r; }
    void SetRect(CRect r) { m_rcControl=r; }
    void SetWrap(BOOL b) { wrap=b; }
};
class CXTPControlButton : public CXTPControl {
public:
    CXTPControlButton();
    ~CXTPControlButton();
    void OnClick(BOOL, CPoint) override;
    void OnLButtonUp(CPoint) override;
};
class CXTPControls {
public:
    struct XTPBUTTONINFO;
    std::vector<CXTPControl*> controls;
    CXTPCommandBar* m_pParent=nullptr;
    int GetCount() const { return controls.size(); }
    CXTPControl* GetAt(int i) const { return controls.at(i); }
    CXTPControl* HitTest(CPoint) const;
    CSize _CalcSize(XTPBUTTONINFO*, const CSize&, BOOL=FALSE);
    int _WrapToolBar(XTPBUTTONINFO*, int, DWORD&, const CSize&);
    void _CenterControlsInRow(XTPBUTTONINFO*,int,int,int,BOOL,CSize,CRect);
    void _AdjustBorders(XTPBUTTONINFO*,CSize&,DWORD,CRect);
    void _MoveRightAlligned(XTPBUTTONINFO*,CSize,CRect,DWORD);
    void _SizePopupToolBar(XTPBUTTONINFO*,DWORD,const CSize&);
    void _SizeFloatableBar(XTPBUTTONINFO*,int,DWORD,const CSize&);
    int GetVisibleCount(BOOL=FALSE) const;
    CSize CalcDynamicSize(CDC*,int,DWORD,const CRect&,int);
    CSize _WrapSmartLayoutToolBar(CDC*,XTPBUTTONINFO*,int,DWORD) {Unported("smart ribbon layout");}
    CXTPControl* FindControl(int id) const {
        for(auto* c:controls) if(c->GetID()==id) return c;
        return nullptr;
    }
    CXTPControl* Add(CXTPControl*,int,const char*,int,BOOL) {Unported("overflow popup control");}
};
class CXTPPaintManager {
public:
    BOOL m_bEmbossedDisabledText=TRUE;
    int m_bShowKeyboardCues=-1;
    BOOL m_bOffice2007Padding=FALSE;
    int m_nEditHeight=0,m_nTextHeight=16,m_nSplitButtonDropDownWidth=11,m_nPopupBarText=COLOR_BTNTEXT;
    CFont m_fontRegular,m_fontRegularBold;
    virtual ~CXTPPaintManager() = default;
    virtual void DrawRectangle(CDC*,CRect,BOOL,BOOL,BOOL,BOOL,BOOL,XTPBarType,XTPBarPosition)=0;
    void DrawControlEntry(CDC*, CXTPControl*);
    CRect GetCommandBarBorders(CXTPCommandBar*);
    CSize DrawControlText(CDC*,CXTPControl*,CRect,BOOL,BOOL,BOOL,BOOL);
    void DrawControlText3(CDC*,CXTPControl*,const CString&,const CString&,CRect,BOOL,BOOL);
    CSize DrawControl(CDC*,CXTPControl*,BOOL=TRUE);
    CSize DrawControlToolBarParent(CDC*,CXTPControl*,BOOL);
    CSize DrawControlText(CDC*,CXTPControl*,CRect,BOOL,BOOL,CSize,BOOL);
    CSize GetControlSize(CXTPControl*,CSize,BOOL);
    CSize GetIconSize(CXTPControl*);
    int GetSplitDropDownHeight() const;
    int GetControlHeight() const {return m_nTextHeight;}
    COLORREF GetControlTextColor(CXTPControl*);
    virtual COLORREF GetRectangleTextColor(BOOL,BOOL,BOOL,BOOL,BOOL,XTPBarType,XTPBarPosition)=0;
    virtual void FillCommandBarEntry(CDC*,CXTPCommandBar*)=0;
    virtual CSize DrawCommandBarSeparator(CDC*,CXTPCommandBar*,CXTPControl*,BOOL=TRUE)=0;
    CFont* GetCommandBarFont(CXTPCommandBar*,BOOL bold=FALSE) {return bold?&m_fontRegularBold:&m_fontRegular;}
    CSize DrawCommandBarGripper(CDC*,CXTPCommandBar*,BOOL=TRUE) { Unported("toolbar gripper"); }
    CSize DrawControlEdit(CDC*,class CXTPControlEdit*,BOOL) {Unported("edit control");}
    CSize DrawControlComboBox(CDC*,class CXTPControlComboBox*,BOOL) {Unported("combo control");}
    CSize DrawControlPopupParent(CDC*,CXTPControl*,BOOL) {Unported("popup control");}
    CSize DrawControlCheckBoxMark(CDC*,CRect,BOOL,BOOL,BOOL,BOOL,BOOL) {Unported("checkbox");}
    CSize DrawControlRadioButtonMark(CDC*,CRect,BOOL,BOOL,BOOL,BOOL,BOOL) {Unported("radio button");}
    void DrawSplitButtonFrame(CDC*,CXTPControl*,CRect) {Unported("split button");}
    CSize DrawControlText2(CDC*,CXTPControl*,CRect,BOOL,BOOL,BOOL) {Unported("two-row caption");}
    void DrawImage(CDC*,CPoint,CSize,CXTPImageManagerIcon*,BOOL,BOOL,BOOL,BOOL,BOOL) {Unported("image manager");}
    void DrawDropDownGlyph(CDC*,CXTPControl*,CPoint,BOOL,BOOL,BOOL,BOOL) { Unported("popup glyph"); }
    void DrawSpecialControl(CDC*,int,CXTPControl*,CXTPCommandBar*,BOOL,CSize*) {Unported("overflow control");}
    void Draw3dRect(CDC* dc,CRect r,int top,int bottom) { dc->Draw3dRect(r,GetXtremeColor(top),GetXtremeColor(bottom)); }
    void Rectangle(CDC* dc,CRect r,int border,int fill) {
        dc->FillSolidRect(r,GetXtremeColor(fill));
        dc->Draw3dRect(r,GetXtremeColor(border),GetXtremeColor(border));
    }
    void DrawShadedRect(CDC*,CRect);
};
class CXTPDefaultTheme : public CXTPPaintManager {
public:
    void DrawRectangle(CDC*,CRect,BOOL,BOOL,BOOL,BOOL,BOOL,XTPBarType,XTPBarPosition) override;
    void FillCommandBarEntry(CDC*,CXTPCommandBar*) override;
    CSize DrawCommandBarSeparator(CDC*,CXTPCommandBar*,CXTPControl*,BOOL=TRUE) override;
    COLORREF GetRectangleTextColor(BOOL,BOOL,BOOL,BOOL,BOOL,XTPBarType,XTPBarPosition) override;
    BOOL IsFlatToolBar(CXTPCommandBar*) {return FALSE;}
    BOOL IsVerticalPosition(XTPBarPosition p) {return p==xtpBarLeft||p==xtpBarRight;}
};
inline BOOL IsControlCommandEnabled(BOOL b) {return b!=FALSE&&b!=TRUE_SPLITDROPDOWN;}
inline BOOL IsControlDropDownEnabled(BOOL b) {return b!=FALSE;}
class CXTPCommandBars {
public:
    struct Options {BOOL bShowExpandButtonAlways=FALSE;} options;
    CXTPControl* m_pDragSelected=nullptr;
    BOOL IsCustomizeMode() const {return FALSE;}
    Options* GetCommandBarsOptions() {return &options;}
};
class CXTPCommandBar : public CWnd {
public:
    CXTPControls controls;
    CXTPControls* m_pControls=&controls;
    CXTPDefaultTheme painter;
    CWnd* owner=nullptr;
    int m_nPopuped=-1, m_nSelected=-1, m_nClickedControl=-1;
    bool customize=false;
    int clientWidth=960,clientHeight=30;
    CRect m_rcMarker;
    int m_nMRUWidth=0,m_nIdleFlags=0;
    XTPBarType GetType() const { return xtpBarTypeNormal; }
    XTPBarPosition GetPosition() const { return xtpBarTop; }
    CXTPPaintManager* GetPaintManager() { return &painter; }
    CWnd* GetOwnerSite() { return owner; }
    BOOL IsKeyboardCuesVisible() const { return TRUE; }
    BOOL IsTextBelowIcons() const {return FALSE;}
    CSize GetLargeIconSize(BOOL) const {return {32,32};}
    CXTPCommandBars* GetCommandBars() const {return nullptr;}
    int GetControlCount() const {return controls.GetCount();}
    CXTPControl* GetControl(int i) const {return controls.GetAt(i);}
    DWORD GetFlags() const {return 0;}
    BOOL GetShowGripper() const {return FALSE;}
    void GetClientRect(CRect* r) const {*r={0,0,clientWidth,clientHeight};}
    void FillCommandBarEntry(CDC*);
    void DrawCommandBar(CDC*,CRect);
    void CustomizeDrawMarker(CDC*) {Unported("customization marker");}
    BOOL IsCustomizeMode() const { return customize; }
    void SetPopuped(int index) { if(index!=-1) Unported("popup tracking"); m_nPopuped=index; }
    void SetSelected(int);
    void OnControlSelected(BOOL,CXTPControl*);
    void Paint();
    void Redraw();
    LRESULT SendMessage(UINT,WPARAM=0,LPARAM=0) override;
};
class CXTPToolBar : public CXTPCommandBar {
public:
    BOOL m_bShowExpandButton=FALSE; // Explicit fixture option: overflow is unported.
    class CControlButtonExpand;
    CRect GetBorders();
    CSize CalcDockingLayout(int,DWORD,int=0);
    BOOL GetShowGripper() const { return FALSE; } // Fixed first toolbar, no docking yet.
};
class CXTPControlPopup : public CXTPControlButton {
public:
    void OnExecute() override {Unported("popup execution");}
};
class CXTPToolBar::CControlButtonExpand : public CXTPControlPopup {
public:
    CControlButtonExpand() {Unported("overflow popup");}
    BOOL IsHiddenExists() {Unported("overflow popup");}
};
void NotifyExecute(CXTPControl*, CWnd*);
void BrowserPresent();
void BrowserInit(CXTPToolBar*);
void BrowserQueue(HWND,UINT,WPARAM,LPARAM);
void BrowserState();
