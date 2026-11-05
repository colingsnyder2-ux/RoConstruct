// from server: 75% by atomic.potato
extern "C" void __cdecl Function473980(void *object, int value);
extern "C" int __cdecl Function982DF8(void *object, int first, int second);

struct CRbxDocTemplate {
    int f(int first, int second);
};

int CRbxDocTemplate::f(int first, int second)
{
    Function473980((void *)0x00E1A0D0, 1);
    return Function982DF8(this, first, second);
}
