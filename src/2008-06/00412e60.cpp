// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_framesizevirtual324b5686eef01153.cpp

// Candidate translation unit (score above; library headers required).
// from server: 90% by king_originala
extern "C" {
    extern int (__stdcall *IsZoomed)(void *);
}

struct SizeSource {
    int get_19c(int *out);
};

SizeSource *func_00412d50();

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct CChildFrame;
typedef void (__thiscall *RectFunction)(CChildFrame *, Rect *, int);

struct FrameTable {
    RectFunction entries[29];
};

struct CChildFrame {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void adjust(Rect*,int);
    char padding[0x1c];
    void *window;

    void func_006a0c68();
    int func_006a0974();
    void func_00412e60(int *param);
};

void CChildFrame::func_00412e60(int *param)
{
    func_006a0c68();
    int value = func_006a0974();
    int *p = param;

    if (value != 0 &&
        *(char *)(value + 0xf8) != 0 &&
        *(int *)(*(int *)(value + 0xec) + 0x84) == 0)
    {
        p[2] += 40;
        p[3] += 40;
        p[8] += 40;
        p[9] += 40;
    }

    if (IsZoomed(window) == 0)
    {
        func_00412d50()->get_19c((int *)&param);

        Rect rect;
        rect.right = ((short *)&param)[0];
        rect.bottom = ((short *)&param)[1];
        rect.left = 0;
        rect.top = 0;

        adjust(&rect, 0);

        p[8] = rect.right - rect.left;
        p[9] = rect.bottom - rect.top;
    }
}
