// from server: 53% by Intel
struct VideoControl
{
    void f(int);
};

void VideoControl::f(int arg)
{
    int vtable_ptr = *(int*)((char*)this + 0x10c);
    int vtable = *(int*)vtable_ptr;
    int (__thiscall *func1)(void*) = (int (__thiscall*)(void*))*(int*)(vtable + 0xc);
    int result = func1((void*)vtable_ptr);
    if (result)
    {
        int arg2 = *(int*)((char*)this + 0x11c);
        int vtable2 = *(int*)vtable_ptr;
        int (__thiscall *func2)(void*, int, int) = (int (__thiscall*)(void*, int, int))*(int*)(vtable2 + 0x14);
        func2((void*)vtable_ptr, arg2, arg);
    }
}
