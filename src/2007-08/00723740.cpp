// from server: 6% by colin
struct DomResourceIcon {
    unsigned short attributeTheme_size;
    unsigned short attributeTheme_data[1];
};

struct IconHandle {
    const DomResourceIcon *m_domIcon;
    int compare(const IconHandle &rhs) const;
};

int IconHandle::compare(const IconHandle &rhs) const
{
    const DomResourceIcon *lhsIcon = m_domIcon;
    const DomResourceIcon *rhsIcon = rhs.m_domIcon;

    unsigned short lhsSize = lhsIcon->attributeTheme_size;
    unsigned short rhsSize = rhsIcon->attributeTheme_size;

    int lhsPos = 0;
    int rhsPos = 0;
    int lhsBit = 7;
    int rhsBit = 4;
    int lhsLimit = lhsSize;
    int rhsLimit = rhsSize;

    if (lhsSize == 0) {
        lhsBit = 0x8a;
        rhsBit = 3;
    }

    if (lhsSize < 0)
        return 0;

    const unsigned short *lhsData = lhsIcon->attributeTheme_data;
    const unsigned short *rhsData = rhsIcon->attributeTheme_data;

    int lhsIndex = 0;
    int rhsIndex = 0;
    int lhsCount = lhsSize + 1;
    int rhsCount = rhsSize + 1;

    while (lhsCount != 0) {
        unsigned short lhsCode = lhsData[lhsIndex];
        unsigned short rhsCode = rhsData[rhsIndex];

        lhsPos += 1;
        rhsPos += 1;

        if (lhsPos >= lhsBit) {
            if (lhsPos >= rhsBit) {
                if (lhsCode != rhsCode)
                    return (lhsCode < rhsCode) ? -1 : 1;
            }
        }

        if (lhsPos < rhsBit) {
            while (lhsPos < rhsBit) {
                unsigned short lhsVal = lhsData[lhsIndex];
                unsigned short rhsVal = rhsData[rhsIndex];
                (void)lhsVal;
                (void)rhsVal;
                lhsPos += 1;
            }
        }

        lhsIndex += 1;
        rhsIndex += 1;
        lhsCount -= 1;
    }

    return 0;
}
