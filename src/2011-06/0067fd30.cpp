// from server: 84% by atomic.potato
struct FilteredSelection
{
};

extern "C" void *__cdecl sub_0080b2ea(void *, void *, void *, void *, int *);

void * __cdecl f(void *value)
{
    if (value)
    {
        void *result = sub_0080b2ea((int *)value, 0, (void *)0x00c071f8,
                                    (void *)0x00c1a934, 0);
        if (result)
            return result;
    }
    return 0;
}
