// from server: 100% by atomic.potato
typedef int (__thiscall *ThunkType)(void *);

extern ThunkType g_thunk;

int __stdcall RefItem(void *value)
{
    return g_thunk(&value);
}
