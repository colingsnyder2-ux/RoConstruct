// from server: 100% by tester
namespace ns_ROCX000005 {
struct Inner
{
    char pad_0[0x18];
    int value;
};

struct CXTPCommandBar
{
    char pad_0[0x178];
    Inner* pInner;
    void SetInnerValue(int value);
};

void CXTPCommandBar::SetInnerValue(int value)
{
    pInner->value = value;
}
}