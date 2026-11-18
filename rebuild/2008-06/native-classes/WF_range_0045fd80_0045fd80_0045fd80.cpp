// native-flags: /O2
#include <afxwin.h>

extern "C" void _ReadWriteBarrier();

struct Interface
{
    virtual ~Interface();
};

// NEEDS-DECL: void CRobloxWnd::sub_0045beb0();
class CRobloxWnd : public CWnd
{
public:
    void sub_0045beb0();
    void setDataModel(void*);
    void f();
};

class range_0045fd80_0045fd80 : public CRobloxWnd
{
public:
    char padding[0x5c - sizeof(CWnd)];
    int state;
    char padding2[0xb4 - 0x60];
    Interface* first;
    Interface* second;

    void sub_0045fd80();
};

void range_0045fd80_0045fd80::sub_0045fd80()
{
    sub_0045beb0();
    setDataModel(0);

    if (state == 2)
    {
        f();
        CWnd::OnDestroy();
        return;
    }

    if (second)
    {
        if (first)
            delete first;
        first = 0;
        _ReadWriteBarrier();
        if (second)
            delete second;
    }

    CWnd::OnDestroy();
}
