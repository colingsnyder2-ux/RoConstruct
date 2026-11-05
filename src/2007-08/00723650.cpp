// from server: 44% by colin
struct DomResourceIcon {
    unsigned short attributeTheme() const;
};

struct IconHandle {
    const DomResourceIcon* m_domIcon;
    int compare(const IconHandle& rhs) const;
};

int IconHandle::compare(const IconHandle& rhs) const
{
    const DomResourceIcon* a = m_domIcon;
    const DomResourceIcon* b = rhs.m_domIcon;

    unsigned short prev = a->attributeTheme();
    int last = -1;
    int i = 0;
    int limit = 7;
    int limit2 = 4;
    if (prev == 0) {
        limit = 0x8a;
        limit2 = 3;
    }

    int count = (int)(unsigned int)this;
    *(unsigned short*)((char*)a + count * 4 + 6) = 0xffff;

    if (count < 0)
        return 0;

    const unsigned short* p = (const unsigned short*)((char*)a + 6);
    int n = count + 1;
    int step = 1;
    do {
        unsigned short cur = *p;
        i += step;
        if (i < limit && prev == cur) {
            // equal case
        } else if (i < limit2) {
            *(unsigned short*)((char*)b + prev * 4 + 0xa7c) += (unsigned short)i;
        } else if (prev != 0) {
            if (prev != last)
                *(unsigned short*)((char*)b + prev * 4 + 0xa7c) += (unsigned short)step;
            *(unsigned short*)((char*)b + 0xabc) += (unsigned short)step;
        } else {
            if (i <= 0xa)
                *(unsigned short*)((char*)b + 0xac0) += (unsigned short)step;
            else
                *(unsigned short*)((char*)b + 0xac4) += (unsigned short)step;
        }

        i = 0;
        last = prev;
        prev = cur;
        if (cur == 0) {
            limit = 0x8a;
            limit2 = 3;
        } else if (prev == cur) {
            limit = 6;
            limit2 = 3;
        } else {
            limit = 7;
            limit2 = 4;
        }

        p++;
        n -= step;
    } while (n != 0);

    return 0;
}
