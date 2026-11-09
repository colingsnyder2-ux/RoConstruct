// from server: 67% by atomic.potato
struct CXTColorBase
{
    virtual ~CXTColorBase();
};

extern "C" void CXTColorBase_008dd680();

CXTColorBase::~CXTColorBase()
{
    CXTColorBase_008dd680();
    *(unsigned long *)this = 0x00a0b704;
    *(unsigned long *)((char *)this + 0x7c) = 0;
    *(unsigned long *)((char *)this + 0x78) = 0x009a2218;
}
