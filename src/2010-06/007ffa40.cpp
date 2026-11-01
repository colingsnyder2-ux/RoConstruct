// from server: 100% by atomic.potato
typedef int BOOL;
typedef struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;

extern "C" BOOL (__stdcall *SetRectEmpty)(RECT *);

struct S {
    void *vftable;
    void *field4;
    RECT rect;
    S *f(void *);
};

S *S::f(void *value)
{
    field4 = value;
    SetRectEmpty(&rect);
    vftable = 0;
    return this;
}
