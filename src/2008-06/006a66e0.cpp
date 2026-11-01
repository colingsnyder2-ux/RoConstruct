// from server: 100% by atomic.potato
struct CXTPCommandBarsOptions
{
    void f(unsigned int* values, int count);
    void hide(unsigned int value);
};

void CXTPCommandBarsOptions::f(unsigned int* values, int count)
{
    if (values != 0)
    {
        int i = 0;
        while (i < count)
        {
            hide(values[i]);
            ++i;
        }
    }
}
