// Browser implementation of the platform operations used by selected Codejock
// methods. JS presents GDI primitives and supplies events; no DOM toolbar exists.
#include "ToolbarSubset.h"
#include <emscripten.h>
#include <emscripten/html5.h>
#include <deque>
#include <map>
#include <cstdio>

static std::deque<MSG> messages;
static HWND capture=nullptr;
static CXTPToolBar* toolbar;
static bool dirty=true;
static int width=960;
static int commands=0,lastCommand=0;
static bool embedded=false,running=true;
static double displayFps=0,displayClock=14*3600;
static float cameraPosition[3]={},cameraRotation[3]={};
struct Timer { HWND window; UINT interval; double next; };
static std::map<UINT,Timer> timers;

EM_JS(void, gdi_fill, (int x,int y,int w,int h,unsigned rgb), {
    var c=Module.gdi;
    c.fillStyle='#'+(rgb&0xffffff).toString(16).padStart(6,'0');
    c.fillRect(x,y,w,h);
});
EM_JS(int, gdi_measure, (const char* text), {
    return Math.ceil(Module.gdi.measureText(UTF8ToString(text)).width);
});
EM_JS(void, gdi_text, (const char* text,int x,int y,unsigned rgb), {
    Module.gdi.fillStyle='#'+(rgb&0xffffff).toString(16).padStart(6,'0');
    Module.gdi.fillText(UTF8ToString(text),x,y);
});
COLORREF GetXtremeColor(int color) {
    switch(color) {
    case COLOR_BTNFACE: return 0xd4d0c8;
    case COLOR_BTNTEXT: return 0x000000;
    case COLOR_BTNHILIGHT: return 0xffffff;
    case COLOR_3DSHADOW: return 0x808080;
    case COLOR_HIGHLIGHT: return 0x0a246a;
    case COLOR_GRAYTEXT: return 0x808080;
    case COLOR_3DDKSHADOW: return 0x404040;
    case COLOR_HIGHLIGHTTEXT: return 0xffffff;
    default: Unported("GDI system color");
    }
}
void CDC::FillSolidRect(CRect r,COLORREF rgb) { gdi_fill(r.left,r.top,r.Width(),r.Height(),rgb); }
void CDC::Draw3dRect(CRect r,COLORREF a,COLORREF b) {
    FillSolidRect({r.left,r.top,r.right-1,r.top+1},a);
    FillSolidRect({r.left,r.top,r.left+1,r.bottom-1},a);
    FillSolidRect({r.left,r.bottom-1,r.right,r.bottom},b);
    FillSolidRect({r.right-1,r.top,r.right,r.bottom},b);
}
CSize CDC::GetTextExtent(const CString& text) { return {gdi_measure(text.c_str()),16}; }
int CDC::SetBkMode(int mode) {
    if(mode!=TRANSPARENT) Unported("opaque GDI text background");
    return TRANSPARENT;
}
COLORREF CDC::SetBkColor(COLORREF color) {
    return EM_ASM_INT({var old=Module.gdiBackground||0xffffff;Module.gdiBackground=$0;return old;},color);
}
CXTPFontDC::CXTPFontDC(CDC*,CFont* font) {
    EM_ASM({Module.gdi.save();Module.gdi.font=($0?"bold ":"")+$1+"px "+UTF8ToString($2);},font->bold,font->size,font->family);
}
CXTPFontDC::~CXTPFontDC() {EM_ASM({Module.gdi.restore();});}
void CDC::DrawText(const CString& text,CRect r,UINT flags) {
    CString display=text;
    if(!(flags&DT_NOPREFIX)) StripMnemonics(display);
    int x=r.left,y=r.top;
    if(flags&DT_CENTER) x+=(r.Width()-GetTextExtent(display).cx)/2;
    if(flags&DT_VCENTER) y+=(r.Height()-16)/2;
    gdi_text(display.c_str(),x,y+13,GetTextColor());
}
void StripMnemonics(CString& text) {
    std::string output;
    for(size_t i=0;i<text.size();++i) {
        if(text[i]=='&') { if(i+1<text.size()&&text[i+1]=='&') ++i; else continue; }
        output+=text[i];
    }
    text=output;
}
void DrawTextApi(CDC* dc,const CString& s,CRect* r,UINT f,BOOL composited) {
    if(composited) Unported("DWM text");
    dc->DrawText(s,*r,f);
}
void CXTPPaintManager::DrawShadedRect(CDC* dc,CRect r) {
    // GDI checker brush used for a latched classic toolbar button.
    for(int y=r.top;y<r.bottom;++y) for(int x=r.left;x<r.right;++x)
        dc->FillSolidRect({x,y,x+1,y+1},((x+y)&1)?0xffffff:GetXtremeColor(COLOR_BTNFACE));
}
void BrowserQueue(HWND hwnd,UINT message,WPARAM w,LPARAM l) { messages.push_back({hwnd,message,w,l}); }
HWND GetCapture() { return capture; }
void CWnd::SetCapture() { capture=this; BrowserState(); }
void ReleaseCapture() { capture=nullptr; BrowserState(); }
void CWnd::SetTimer(UINT id,UINT interval,void*) {
    timers[id]={this,interval,emscripten_get_now()+interval};
}
void CWnd::KillTimer(UINT id) { timers.erase(id); }
BOOL GetMessage(MSG* result,HWND filterWindow,UINT first,UINT last) {
    if(filterWindow||first||last) Unported("filtered GetMessage");
    while(messages.empty()) {
        double now=emscripten_get_now();
        for(auto& timer:timers) if(now>=timer.second.next) {
            BrowserQueue(timer.second.window,WM_TIMER,timer.first,0);
            timer.second.next=now+timer.second.interval;
        }
        BrowserPresent();
        if(messages.empty()) emscripten_sleep(8);
    }
    *result=messages.front(); messages.pop_front(); return TRUE;
}
void DispatchMessage(MSG* m) { m->hwnd->SendMessage(m->message,m->wParam,m->lParam); }
LRESULT CWnd::SendMessage(UINT message,WPARAM w,LPARAM) {
    if(message!=WM_COMMAND) Unported("host window message");
    ++commands; lastCommand=w;
    for(auto* c:toolbar->controls.controls) if(c->id==int(w)&&c->id==100) c->checked=!c->checked;
    EM_ASM({if(Module.onToolbarCommand)Module.onToolbarCommand($0);},w);
    dirty=true; BrowserState(); return 0;
}
BOOL CXTPControl::IsCustomizeMode() const { return m_pParent->IsCustomizeMode(); }
void CXTPControl::RedrawParent(BOOL) { dirty=true; BrowserPresent(); }
void CXTPCommandBar::Redraw() {dirty=true;BrowserPresent();}
CXTPPaintManager* CXTPControl::GetPaintManager() const {return m_pParent->GetPaintManager();}
void NotifyExecute(CXTPControl* control,CWnd* owner) { owner->SendMessage(WM_COMMAND,control->GetID()); }
void CXTPCommandBar::OnControlSelected(BOOL,CXTPControl*) { dirty=true; }
void CXTPCommandBar::SetSelected(int index) {
    if(index==m_nSelected) return;
    if(m_nSelected>=0) controls.GetAt(m_nSelected)->OnSetSelected(FALSE);
    m_nSelected=index;
    if(index>=0) controls.GetAt(index)->OnSetSelected(TRUE);
    dirty=true;
}
void CXTPCommandBar::Paint() {
    CDC dc;
    dc.FillSolidRect({0,0,width,320},0xf4f4f4);
    CSize size=static_cast<CXTPToolBar*>(this)->CalcDockingLayout(width,LM_HORZDOCK|LM_COMMIT);
    clientWidth=width;clientHeight=size.cy;
    DrawCommandBar(&dc,{0,0,width,size.cy});
    if(embedded) {
        int statusTop=size.cy;
        dc.FillSolidRect({0,statusTop,width,statusTop+46},GetXtremeColor(COLOR_BTNFACE));
        dc.Draw3dRect({2,statusTop+2,width-2,statusTop+44},0x808080,0xffffff);
        dc.SetTextColor(0);
        int seconds=int(displayClock);
        char text[160];std::snprintf(text,sizeof(text),"CASTLE ISLAND  |  %02d:%02d %s  |  %.1f FPS  |  Drag: orbit   Wheel: zoom",seconds/3600,seconds/60%60,running?"Running":"Paused",displayFps);
        dc.DrawText(text,{8,statusTop+4,width-8,statusTop+22},DT_SINGLELINE|DT_NOPREFIX);
        std::snprintf(text,sizeof(text),"Position: %.3f, %.3f, %.3f   Rotation (pitch/yaw/roll): %.3f, %.3f, %.3f deg",cameraPosition[0],cameraPosition[1],cameraPosition[2],cameraRotation[0],cameraRotation[1],cameraRotation[2]);
        dc.DrawText(text,{8,statusTop+24,width-8,statusTop+42},DT_SINGLELINE|DT_NOPREFIX);
        EM_ASM({if(Module.reportHeight)Module.reportHeight($0);},statusTop+46);
        return;
    }
    dc.SetTextColor(0x333333);
    dc.DrawText("Codejock C++ -> Wasm: original layout / hit-test / click tracking / classic theme",{16,90,width,115},DT_SINGLELINE|DT_NOPREFIX);
    char status[160];std::snprintf(status,sizeof(status),"WM_COMMAND: %d   Last ID: %d   Capture: %s",commands,lastCommand,capture?"active":"released");
    dc.DrawText(status,{16,120,width,145},DT_SINGLELINE|DT_NOPREFIX);
}
LRESULT CXTPCommandBar::SendMessage(UINT message,WPARAM w,LPARAM l) {
    CPoint p(LOWORD(l),HIWORD(l));
    if(message==WM_MOUSEMOVE) { auto* c=controls.HitTest(p);SetSelected(c?c->GetIndex():-1); }
    else if(message==WM_LBUTTONDOWN) {
        if(auto* c=controls.HitTest(p)) c->OnClick(FALSE,p);
    } else if(message==WM_KEYDOWN) {
        if(w==27) ReleaseCapture();
        else if((w==13||w==32)&&m_nSelected>=0) controls.GetAt(m_nSelected)->OnClick(TRUE,p);
        else if(w==39||w==37) SetSelected((m_nSelected+(w==39?1:controls.GetCount()-1)+controls.GetCount())%controls.GetCount());
    } else if(message==WM_CANCELMODE) ReleaseCapture();
    else if(message==WM_SIZE) { width=w; dirty=true; }
    else if(message!=WM_LBUTTONUP && message!=WM_TIMER) Unported("toolbar window message");
    BrowserPresent();return 0;
}
void BrowserState() {
    EM_ASM({Module.toolbarState=({commands:$0,lastCommand:$1,capture:!!$2,selected:$3,buttons:$4});},
        commands,lastCommand,capture!=nullptr,toolbar->m_nSelected,toolbar->controls.GetCount());
    EM_ASM({Module.toolbarState.controls=[];});
    for(auto* control:toolbar->controls.controls) {
        CRect r=control->GetRect();
        EM_ASM({Module.toolbarState.controls.push(({id:$0,left:$1,top:$2,right:$3,bottom:$4,pressed:!!$5,checked:!!$6,enabled:!!$7}));},
            control->id,r.left,r.top,r.right,r.bottom,control->m_bPressed,control->checked,control->enabled);
    }
}
void BrowserPresent() { if(toolbar&&dirty) { dirty=false;toolbar->Paint();BrowserState(); } }
static EM_BOOL mouse(int type,const EmscriptenMouseEvent* event,void*) {
    UINT message=type==EMSCRIPTEN_EVENT_MOUSEDOWN?WM_LBUTTONDOWN:type==EMSCRIPTEN_EVENT_MOUSEUP?WM_LBUTTONUP:WM_MOUSEMOVE;
    if(message!=WM_MOUSEMOVE&&event->button!=0) return FALSE;
    int x=event->clientX-EM_ASM_INT({return Module.canvas.getBoundingClientRect().left;});
    int y=event->clientY-EM_ASM_INT({return Module.canvas.getBoundingClientRect().top;});
    BrowserQueue(toolbar,message,0,uint32_t(x&0xffff)|(uint32_t(y&0xffff)<<16));return TRUE;
}
static EM_BOOL key(int,const EmscriptenKeyboardEvent* event,void*) {
    if(event->keyCode!=13&&event->keyCode!=27&&event->keyCode!=32&&event->keyCode!=37&&event->keyCode!=39) return FALSE;
    BrowserQueue(toolbar,WM_KEYDOWN,event->keyCode,0);return TRUE;
}
static EM_BOOL resize(int,const EmscriptenUiEvent*,void*) {
    int w=EM_ASM_INT({var w=Math.max(160,window.innerWidth-(Module.toolbarEmbedded?0:16));Module.canvas.width=w;Module.gdi.font='13px Tahoma, sans-serif';return w;});
    BrowserQueue(toolbar,WM_SIZE,w,0);return TRUE;
}
static EM_BOOL blur(int,const EmscriptenFocusEvent*,void*) { BrowserQueue(toolbar,WM_CANCELMODE,0,0);return FALSE; }
void BrowserInit(CXTPToolBar* bar) {
    toolbar=bar;
    embedded=EM_ASM_INT({return !!Module.toolbarEmbedded;});
    EM_ASM({Module.gdi=Module.canvas.getContext('2d');Module.gdi.font='13px Tahoma, sans-serif';Module.canvas.focus();});
    emscripten_set_mousedown_callback("#canvas",nullptr,TRUE,mouse);
    emscripten_set_mousemove_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr,TRUE,mouse);
    emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr,TRUE,mouse);
    emscripten_set_keydown_callback("#canvas",nullptr,TRUE,key);
    emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr,TRUE,resize);
    emscripten_set_blur_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr,TRUE,blur);
    resize(0,nullptr,nullptr);
}
extern "C" EMSCRIPTEN_KEEPALIVE void toolbar_status(double fps,double clock,int cycle,int shadows,int orbit,int wire,int celestial,int hud,int fullscreen) {
    displayFps=fps;displayClock=clock;running=cycle;
    int checked[10]={cycle,!cycle,0,shadows,orbit,celestial,wire,0,hud,fullscreen};
    for(auto* control:toolbar->controls.controls) if(control->id>=100&&control->id<=109)
        control->checked=checked[control->id-100];
    dirty=true;
}
extern "C" EMSCRIPTEN_KEEPALIVE void toolbar_camera(float x,float y,float z,float pitch,float yaw,float roll) {
    cameraPosition[0]=x;cameraPosition[1]=y;cameraPosition[2]=z;
    cameraRotation[0]=pitch;cameraRotation[1]=yaw;cameraRotation[2]=roll;dirty=true;
}
