// from server: 81% by atomic.potato
extern "C" void __cdecl sub_4A0D90(void *, void *);

void function(void *arg1, unsigned int count, void *arg2)
{
    if (count > 0)
    {
        while (count != 0)
        {
            if (arg1 != 0)
                sub_4A0D90(arg1, arg2);
            --count;
            arg1 = (char *)arg1 + 0x48;
        }
    }
}
