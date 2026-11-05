// from server: 100% by king_originala
extern "C" int (__cdecl *memmove_s)(void *, unsigned int,
                                   const void *, unsigned int);

struct Item {
    virtual void slot0();
    virtual bool flag();
    unsigned char padding[196];
    float value;
};

#pragma float_control(precise, off)

Item **__cdecl merge(Item **first1, Item **last1,
                     Item **first2, Item **last2, Item **result)
{
    while (first1 != last1 && first2 != last2) {
        Item *left = *first1;
        Item *right = *first2;

        bool takeRight = false;
        if (right != left) {
            if (right->flag() != left->flag())
                takeRight = right->flag();
            else
                takeRight = right->value < left->value;
        }

        if (takeRight)
            *result = *first2++;
        else
            *result = *first1++;
        ++result;
    }

    int (__cdecl *copy)(void *, unsigned int, const void *, unsigned int)
        = memmove_s;

    int count1 = last1 - first1;
    Item **next = result + count1;
    if (count1 > 0)
        copy(result, count1 * 4, first1, count1 * 4);

    int count2 = last2 - first2;
    Item **end = next + count2;
    if (count2 > 0)
        copy(next, count2 * 4, first2, count2 * 4);

    return end;
}
