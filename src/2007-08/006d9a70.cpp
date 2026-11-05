// from server: 53% by colin
struct CXTPDockingPaneAutoHidePanel {
    char pad0[0x60];
    int m_field60;
    void Process(int a1, int a2);
};

extern "C" void* __stdcall sub_0065E560(int a1, int a2);
extern "C" void* __stdcall sub_0071FA60(void* a1, void* a2);

void CXTPDockingPaneAutoHidePanel::Process(int a1, int a2)
{
    void* p = sub_0065E560(0x7c89cf8b, 0x4e8954c7);
    if (p == 0)
        return;

    int* it = (int*)sub_0071FA60(this, &p);
    while (true) {
        int* obj = (int*)*it;
        int (*fn1)(void*) = *(int (**)(void*))((char*)obj + 0x14);
        int r = fn1(it);
        if (r != 0 && a2 != 0)
            break;

        int (*fn2)(void*, int, int, int) = *(int (**)(void*, int, int, int))((char*)obj + 0x44);
        int v = fn2(it, m_field60, a2, 0);
        int (*fn3)(void*, int) = *(int (**)(void*, int))((char*)this + 0x140);
        fn3(this, v);

        if (*(int*)&p == 0)
            break;
    }
}
