// from server: 100% by colin
struct CXTPRibbonBar {
    int IsFrameHelper();
};

int CXTPRibbonBar::IsFrameHelper()
{
    int* p = *(int**)((char*)this + 0x5c);
    return *(int*)((char*)p + 0x274) == (int)this;
}
