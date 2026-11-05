// from server: 100% by tajop
struct BigNum16
{
    unsigned int word[16];
};

bool greaterThan(const BigNum16* a, const BigNum16* b)
{
    for (int i = 15; i >= 0; --i)
    {
        if (a->word[i] > b->word[i])
            return true;
        if (a->word[i] < b->word[i])
            return false;
    }
    return false;
}
