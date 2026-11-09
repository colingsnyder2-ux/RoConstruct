// from server: 100% by tajop
struct RECT_ { int left; int top; int right; int bottom; };
struct PT16 { short x; short y; };
struct POINT_ { int x; int y; };

struct MINMAXINFO_ {
    POINT_ ptReserved;
    POINT_ ptMaxSize;
    POINT_ ptMaxPosition;
    POINT_ ptMinTrackSize;
    POINT_ ptMaxTrackSize;
};

struct ViewObj {
    char pad[0xe0];
    char flag_e0;
};

struct GetterObj {
    int get();
};

extern "C" int (__stdcall *IsZoomed)(void*);
extern "C" GetterObj* __stdcall sub_40f060(PT16*);

struct CChildFrame {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void CalcWindowRect(RECT_* r, unsigned int type);
    char pad[0x1c];
    void* m_hWnd;
    void sub_63023e();
    ViewObj* sub_62ff50();
    void OnGetMinMaxInfo(MINMAXINFO_* mmi);
};

void CChildFrame::OnGetMinMaxInfo(MINMAXINFO_* mmi)
{
    sub_63023e();
    ViewObj* v = sub_62ff50();
    if (v && v->flag_e0) {
        POINT_ p;
        p.x = 0x7918;
        p.y = 0x7918;
        mmi->ptMaxTrackSize = p;
        mmi->ptMaxSize = p;
    }
    if (!IsZoomed(m_hWnd)) {
        PT16 pt;
        sub_40f060(&pt)->get();
        RECT_ r;
        r.right = pt.x;
        r.bottom = pt.y;
        r.left = 0;
        r.top = 0;
        CalcWindowRect(&r, 0);
        mmi->ptMaxTrackSize.x = r.right - r.left;
        mmi->ptMaxTrackSize.y = r.bottom - r.top;
    }
}
