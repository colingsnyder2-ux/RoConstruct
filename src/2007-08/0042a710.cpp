// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_00630d36(void*, void*, void*, void*, void*);
extern "C" void __cdecl func_00402a60(void*);

struct CLuaHtmlView
{
    void* field_0;
    void* field_4;
    void* construct(void* src);
};

void* CLuaHtmlView::construct(void* src)
{
    void* p = func_00630d36(*(void**)src, 0, (void*)0x881f4c, (void*)0x8865a0, 0);
    this->field_0 = p;

    void* q = *(void**)((char*)src + 4);
    this->field_4 = q;
    if (q != 0)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }

    if (this->field_0 == 0)
    {
        void* tmp = 0;
        func_00402a60(&tmp);
    }

    return this;
}
