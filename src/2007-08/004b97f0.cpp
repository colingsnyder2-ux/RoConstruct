// from server: 100% by tajop
struct BigNum4
{
    unsigned int word[4];
};

bool greaterThan(const BigNum4* a, const BigNum4* b)
{
    for (int i = 3; i >= 0; --i)
    {
        if (a->word[i] > b->word[i])
            return true;
        if (a->word[i] < b->word[i])
            return false;
    }
    return false;
}
