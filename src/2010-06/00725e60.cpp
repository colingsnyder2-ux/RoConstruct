// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_720F50(void *);
extern "C" void __cdecl sub_724F70(void *, void *, int);
extern "C" void __cdecl sub_402090(void *, void *);
extern "C" void __cdecl sub_5A10C0(void *);
extern "C" void *__cdecl sub_4B8580(void *);
extern "C" void *__cdecl sub_60F270(void *, void *);
extern "C" int __cdecl sub_4BFA00(void *, void *);
extern "C" int __cdecl sub_4BFA60(void *, void *);
extern "C" void *__cdecl sub_4D97C0(void *, void *);
extern "C" void *__cdecl sub_614CF0(void *, void *, void *, void *, void *);
extern "C" void __cdecl sub_721700(void *, void *);
extern "C" void __cdecl sub_7A89B2(void *, void *);
extern "C" int __cdecl sub_7A8BEA(void *, void *, void *, void *, void *);
extern "C" void __cdecl sub_4093B0(void *, void *);
extern "C" void *__cdecl sub_9EA410(void *);

struct RefCounted
{
    void *vtable;
    volatile long refcount;
    volatile long weakrefcount;
};

struct LuaArguments
{
    int Lock(void *player);
};

int LuaArguments::Lock(void *player)
{
    int n = sub_720F50(player);
    if (n < 1)
        goto cleanup;

    {
        void *arg1 = 0;
        sub_724F70(&arg1, player, 1);

        void *local = 0;
        RefCounted *ref = 0;

        if (arg1 != 0)
        {
            if (n >= 2)
            {
                void *tmp = 0;
                sub_724F70(&tmp, player, 2);
                void *src = *(void **)tmp;
                void *p = (char *)tmp + 4;
                sub_402090(&local, p);
                sub_5A10C0(&tmp);
                ref = (RefCounted *)local;
            }

            void *inst = sub_4B8580(arg1);
            void *playerInst = sub_60F270(inst, player);

            if (playerInst != 0)
            {
                if (sub_4BFA00(arg1, playerInst) && playerInst != *(void **)((char *)inst + 0x15c))
                {
                    void *s = sub_9EA410((void *)0xa4d1e8);
                    void *str = 0;
                    sub_4093B0(&str, s);
                    sub_7A89B2(&str, (void *)0xb03074);
                }
            }
            else
            {
                if (sub_4BFA60(arg1, playerInst))
                {
                    if (ref != 0)
                    {
                        if (sub_7A8BEA(ref, (void *)0xb78e40, (void *)0xb85b2c, 0, 0) != 0)
                            goto after_checks;
                    }
                    void *s = sub_9EA410((void *)0xa4d138);
                    void *str = 0;
                    sub_4093B0(&str, s);
                    sub_7A89B2(&str, (void *)0xb03074);
                }
            }

        after_checks:
            {
                void *tmp2 = 0;
                sub_4D97C0(&tmp2, playerInst);
                void *src = *(void **)tmp2;
                void *p = (char *)tmp2 + 4;
                sub_402090(&local, p);
                sub_5A10C0(&tmp2);
                ref = (RefCounted *)local;
            }

            {
                RefCounted *a = ref;
                RefCounted *b = 0;
                if (a)
                    _InterlockedExchangeAdd(&a->refcount, 1);
                if (b)
                    _InterlockedExchangeAdd(&b->refcount, 1);
                void *r = sub_614CF0(player, a, b, 0, 0);
                sub_5A10C0(&local);
                sub_5A10C0(&arg1);
                sub_721700(player, 0);
                return 1;
            }
        }

        sub_5A10C0(&arg1);
    }

cleanup:
    sub_721700(player, 0);
    return 1;
}
