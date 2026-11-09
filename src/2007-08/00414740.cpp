// from server: 100% by colin
struct DHTMLWindow {
    void* m_pUnknown;
    char m_pad[4];
    void* m_pInner;
    DHTMLWindow* Init(void* arg);
};

extern "C" void* __stdcall sub_56da00();

struct Inner {
    void Init(void* arg);
};

DHTMLWindow* DHTMLWindow::Init(void* arg)
{
    m_pUnknown = sub_56da00();
    ((Inner*)&m_pad[0])->Init(arg);
    return this;
}
