// from server: 46% by atomic.potato
struct S
{
    float value;
    unsigned short word;
    void f(void* dst, const S* src);
};

void S::f(void* dst, const S* src)
{
    S* out = (S*)dst;
    out->value = src->value + value;
    out->word = (unsigned short)(src->word + word);
}
