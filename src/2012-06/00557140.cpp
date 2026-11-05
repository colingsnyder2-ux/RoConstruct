// from server: 88% by atomic.potato
struct S
{
    void *method(void *);
    void *helper(void *);
};

void *S::method(void *arg)
{
    void *value = helper((char *)arg + 4);
    void *result = *(void **)value;
    return helper(&result);
}
