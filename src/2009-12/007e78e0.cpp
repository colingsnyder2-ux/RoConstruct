// from server: 73% by atomic.potato
typedef long LONG;
typedef void* HANDLE;

extern "C" LONG __stdcall InterlockedDecrement(LONG*);
extern "C" int __stdcall CloseHandle(HANDLE);
extern "C" void __stdcall Function_0098b208(const void*);

struct S
{
    LONG value;
    void Release();
};

void S::Release()
{
    if (value)
    {
        CloseHandle((HANDLE)value);
        value = 0;
        Function_0098b208((const void*)0x00b99b4c);
    }
}
