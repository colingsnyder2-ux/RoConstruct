// from server: 58% by atomic.potato
struct XOleCommandTarget
{
    int Execute(int, int);
};

int XOleCommandTarget::Execute(int a, int b)
{
    return 0;
}

extern "C" int Target(XOleCommandTarget *, int, int);

int __stdcall Function(int, XOleCommandTarget *p, int a)
{
    return Target((XOleCommandTarget *)((char *)p - 240), a, (int)p);
}
