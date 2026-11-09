// from server: 45% by atomic.potato
extern "C" int __stdcall CloseHandle(void*);

struct CSelectionTreeCtrl
{
    void* field0;
    void* field1;
    void* field2;
    void* field3;
    void f();
};

void CSelectionTreeCtrl::f()
{
    void* h = field3;
    field3 = 0;
    if (h)
        CloseHandle(h);
}
