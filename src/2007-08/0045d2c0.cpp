// from server: 100% by colin
struct ScintillaView_Inner {
    int get(int);
};

struct ScintillaView {
    char pad[0x58];
    ScintillaView_Inner inner;
    void method(int*);
};

void ScintillaView::method(int* p)
{
    int* obj = *(int**)p;
    int r = inner.get(1);
    ((void (__thiscall*)(void*, int))obj[0])(p, r);
}
