// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void *__stdcall GetCapture();
extern "C" __declspec(dllimport) int __stdcall ReleaseCapture();

extern "C" void *__stdcall sub_6301c0(void *);

struct CXTPDockingPaneTabbedContainer {
    char pad[0x1a4];
    void *field1a4;
    void f(int a, int b, int c);
    void sub_63023e();
};

void CXTPDockingPaneTabbedContainer::f(int a, int b, int c)
{
    if (this->field1a4 != 0) {
        this->field1a4 = 0;
        void *cap = GetCapture();
        if (sub_6301c0(cap) == this)
            ReleaseCapture();
    }
    sub_63023e();
}
