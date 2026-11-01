// from server: 66% by colin
struct CDeclarationView
{
    void updateDeclarationView(int a, int b, int c, int d, int e, int f);
};

void CDeclarationView::updateDeclarationView(int a, int b, int c, int d, int e, int f)
{
    int* p = (int*)a;
    int* q = (int*)b;
    int* r = (int*)c;
    int* s = (int*)d;
    int* t = (int*)e;
    int* u = (int*)f;

    while (p != q)
    {
        ((void (__cdecl*)(int*, int*, int*))t)(u, r, p + 2);
        p = (int*)*p;
    }

    int* out = (int*)s;
    out[0] = (int)t;
    out[1] = (int)u;
    out[2] = (int)r;
    out[3] = (int)f;
}
