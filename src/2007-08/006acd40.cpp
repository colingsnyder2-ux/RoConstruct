// from server: 93% by colin
// roc 2007-08 006acd40  unit: CXTPRibbonBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006acd40

extern "C" int __cdecl sub_630d23(int);

struct CXTPRibbonBar
{
    void* getSomething();
};

void* CXTPRibbonBar::getSomething()
{
    sub_630d23(0);
    return (void*)0x8c9324;
}
