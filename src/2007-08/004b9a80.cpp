// from server: 100% by tajop
struct BigNum8
{
    unsigned int word[8];
};

bool greaterThan(const BigNum8* a, const BigNum8* b)
{
    for (int i = 7; i >= 0; --i)
    {
        if (a->word[i] > b->word[i])
            return true;
        if (a->word[i] < b->word[i])
            return false;
    }
    return false;
}
