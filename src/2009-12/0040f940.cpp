// from server: 27% by atomic.potato
extern "C" int __cdecl sub_7F4AAA(void*, void*, void*, void*, void*);

struct ChatEnter
{
    int f(int);
};

int ChatEnter::f(int value)
{
    int result = sub_7F4AAA((void*)0, (void*)0, (void*)0, (void*)0, (void*)0);
    return ((int (__thiscall*)(int, int))(*(int**)result + 0x58))(result, value);
}
