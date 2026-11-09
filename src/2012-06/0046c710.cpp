// from server: 91% by atomic.potato
extern "C" int* __cdecl GetMainFrame();
extern "C" void __cdecl CallTarget(int, const char*, const char*, int, int);

void Function()
{
    int* p = GetMainFrame();
    p = (int*)p[1];
    p = (int*)((char*)p + 0x20);
    CallTarget(*p, "WVS3", ".?AVCWnd@@", 0, 0);
}
