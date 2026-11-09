// from server: 100% by atomic.potato
typedef unsigned char Boolean;

extern "C" Boolean __cdecl sub_005b6300(void *);
extern "C" Boolean __cdecl sub_005b5830(void *);

Boolean sub_005b6720(void *value)
{
    if (sub_005b6300(value))
        return 1;
    return sub_005b5830(value) != 0;
}
