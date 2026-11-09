// from server: 45% by atomic.potato
typedef void (__cdecl *Callback)(void *, void *, void *);

extern "C" int __cdecl sub_66E240(Callback, void *, void *);

int __cdecl sub_5E8580(void *a, void *b, void *c)
{
    int result = 0;
    sub_66E240((Callback)0x5E7430, &result, a);
    return result;
}
