// from server: 100% by Yeetserama
// from server: 100% by king_originala
typedef int (__thiscall *DispatchFn)(void *, int, int, int, int);

struct CWrapperView {
    char padding[0x58];
    struct {
        DispatchFn *vtable;
    } target;

    int BaseDispatch(int, int, int, int);
    int Dispatch(int, int, int, int);
};

int CWrapperView::Dispatch(int a, int b, int c, int d) {
    if (BaseDispatch(a, b, c, d))
        return 1;
    return target.vtable[5](&target, a, b, c, d);
}
