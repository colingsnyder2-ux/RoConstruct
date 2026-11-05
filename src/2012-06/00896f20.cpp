// from server: 72% by atomic.potato
typedef const char * LPCSTR;

struct BasicString
{
    BasicString(LPCSTR);
};

struct AdvArrowToolBase_00896f20
{
    char pad0[53];
    unsigned char m_opened;
    BasicString *f(BasicString *);
};

BasicString *AdvArrowToolBase_00896f20::f(BasicString *result)
{
    BasicString temp(m_opened ? "advCursor-openedHand" : "advCursor-default");
    *result = temp;
    return result;
}
