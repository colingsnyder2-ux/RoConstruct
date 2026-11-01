// from server: 100% by colin
struct CXTSplitterWnd {
    int method(int, int);
};

extern "C" int __cdecl func_0063023e();

int CXTSplitterWnd::method(int a, int b)
{
    if (*(unsigned char*)((char*)this + 0x108) & 8)
        return 0x12;
    return func_0063023e();
}
