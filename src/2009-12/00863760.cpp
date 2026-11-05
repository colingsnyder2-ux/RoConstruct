// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);

struct CXTPToolTipContextToolTip
{
    int member_placeholder[16];
    CXTPToolTipContextToolTip* f(const void*);
};

CXTPToolTipContextToolTip* CXTPToolTipContextToolTip::f(const void* p)
{
    this->member_placeholder[15] = 0;
    memcpy_s(this, 60, p, 60);
    return this;
}
