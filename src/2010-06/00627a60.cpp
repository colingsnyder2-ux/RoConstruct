// from server: 76% by atomic.potato
extern "C" void __cdecl Function_007a7934(int);
extern "C" void __cdecl Function_00625cd0(int);

void Function_00627a60(void* object)
{
    int* value = *(int**)((char*)object + 0x20);
    int item = *value;
    if (item != 0)
    {
        Function_007a7934(item);
        Function_00625cd0(item);
        *value = 0;
    }
}
