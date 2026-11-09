// from server: 91% by atomic.potato
extern "C" int __cdecl sub_007F4AAA(void *, void *, void *, int, int);

int __stdcall sub_00717D90(int value)
{
    return !!sub_007F4AAA((void *)value, (void *)0x00AFFE40, (void *)0x00B4C274, 0, 0);
}
