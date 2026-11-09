// from server: 89% by atomic.potato
extern "C" int __cdecl func_00982ff0(int);

extern "C" int __stdcall SendMessageA(int, unsigned int, int, int);

struct S
{
    char padding[0x19c];
    int field_19c;
    int f();
};

int S::f()
{
    int value = func_00982ff0(0x412);
    int result = SendMessageA(*(int*)((char*)value + 0x20), 0xf0, 0, 0);
    field_19c = result != 0;
    return field_19c;
}
