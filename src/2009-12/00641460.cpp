// from server: 100% by atomic.potato
extern "C" char __cdecl sub_00641090(void *);
extern "C" char __cdecl sub_00640d90(void *);

char function_00641460(void *value)
{
    if (sub_00641090(value))
        return 1;
    return sub_00640d90(value) != 0;
}
