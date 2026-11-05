// from server: 100% by atomic.potato
struct CXTPCommandBar
{
    unsigned char padding[0xf0];
    unsigned int flags;
    unsigned int GetFlag() const;
};

unsigned int CXTPCommandBar::GetFlag() const
{
    return (flags >> 22) & 1;
}
