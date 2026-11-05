// from server: 100% by tester
struct CXTPCommandBar
{
    int getFlag() const;
};

int CXTPCommandBar::getFlag() const
{
    return (*(const unsigned int*)((const char*)this + 0xe8) >> 0x16) & 1;
}