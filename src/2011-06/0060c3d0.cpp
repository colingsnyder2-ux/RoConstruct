// from server: 54% by atomic.potato
extern "C" void __cdecl call_680010(int*, int*, int*);

int Function0060c3d0()
{
    int value = 0;
    int* global = (int*)0x60b220;
    call_680010(&value, global, &value);
    return value;
}
