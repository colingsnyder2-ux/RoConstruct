// from server: 100% by why2
struct CXTPCommandBar
{
    int getFlag() const;
};

int CXTPCommandBar::getFlag() const
{
    return (*(const unsigned int*)((const char*)this + 0xf0) >> 0x16) & 1;
}
