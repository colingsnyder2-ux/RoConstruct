// from server: 34% by atomic.potato
struct HVCXTPPropertyGridItem
{
    bool __stdcall XItem(int a, int b, int c, int d, int e);
};

extern "C" void __stdcall sub_a404d0();
extern "C" void __stdcall sub_a42e08();

bool __stdcall HVCXTPPropertyGridItem::XItem(int a, int b, int c, int d, int e)
{
    sub_a404d0();
    sub_a42e08();
    return a != 0;
}
