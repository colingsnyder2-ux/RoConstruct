// from server: 60% by atomic.potato
extern "C" void sub_44B810(int);
extern "C" int sub_7F44EA(void *, int, int);

struct CRbxDocTemplate
{
    int f(int, int);
};

int CRbxDocTemplate::f(int a, int b)
{
    sub_44B810(1);
    return sub_7F44EA(this, a, b);
}
