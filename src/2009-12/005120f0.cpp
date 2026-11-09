// from server: 64% by atomic.potato
extern "C" int __stdcall CloseHandle(void*);

struct S
{
    int value0;
    int value1;
    int value2;
    int value3;
    void f();
};

void S::f()
{
    *(int*)this = 0x9bb20c;

    int h = *(int*)((char*)this + 0x0c);
    if (h != 0 && h != -1)
        CloseHandle((void*)h);

    h = *(int*)((char*)this + 0x08);
    if (h != 0 && h != -1)
        CloseHandle((void*)h);
}
