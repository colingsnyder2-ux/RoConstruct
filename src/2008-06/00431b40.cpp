// from server: 100% by king_originala
struct Rect {
    int left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *GetWindowRect)(void *, Rect *);
    extern int (__stdcall *CopyRect)(Rect *, const Rect *);
    extern int (__stdcall *IsRectEmpty)(const Rect *);
}

struct CDataModelPropGrid;

struct PropGridVTable {
    char padding[0x158];
    void (__thiscall *update)(CDataModelPropGrid *, int);
};

struct CDataModelPropGrid {
    PropGridVTable *vtable;
    char padding04[0x1C];
    void *window;
    char padding24[0xD4];
    unsigned char flagF8;
    char paddingF9[0x2F];
    Rect savedRect;

    void restore();
    void configure();
    void position(void *, int, int, int, int, unsigned int);
    void f(unsigned char);
};

void CDataModelPropGrid::f(unsigned char value)
{
    Rect rect;

    if (flagF8 != value) {
        flagF8 = value;

        if (value) {
            GetWindowRect(window, &savedRect);
            CopyRect(&rect, &savedRect);
            configure();
        } else {
            restore();
            CopyRect(&rect, &savedRect);
            if (!IsRectEmpty(&rect)) {
                position(0, rect.left, rect.top,
                         rect.right - rect.left,
                         rect.bottom - rect.top, 0x260);
            }
        }

        vtable->update(this, 1);
    }
}
