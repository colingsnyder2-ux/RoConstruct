// from server: 37% by colin
struct XTextHost {
    int TxGetAcceleratorPos(long *pPos);
};

struct XTPRichRender {
    int GetAcceleratorPos(long *pPos);
};

extern "C" void __stdcall sub_62FF3E(void *p);
extern "C" void __stdcall sub_62FF38(void *p, int n);
extern "C" int __stdcall sub_738BAA(XTextHost *pThis, long *pPos, int n);

int XTextHost::TxGetAcceleratorPos(long *pPos)
{
    int result;
    void *p;
    int n;
    int saved;

    sub_62FF3E(&p);
    n = 0;
    result = sub_738BAA(this - 8, pPos, n);
    if (p != 0) {
        sub_62FF38(p, 0);
    }
    return result;
}
