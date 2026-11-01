// from server: 100% by colin
struct VCApp {
    int CComObject(int a, int b, int c);
};

extern "C" int __stdcall SomeFunction(int a, int b, int c, int d);

int VCApp::CComObject(int a, int b, int c) {
    return SomeFunction(a, 0x7851e8, b, c);
}
