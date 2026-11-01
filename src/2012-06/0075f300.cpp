// from server: 23% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    void* vftable;
    int refCount;
    int length;
    int capacity;
    char buffer[1];
};

struct TypedPercentItem {
    void* vftable;

    TypedPercentItem* func_0075f300(const char* arg);
};

extern "C" void __stdcall String_ctor(String*, const char*);
extern "C" void __stdcall String_dtor(String*);
extern "C" void __cdecl func_0075ee80(void*);
extern "C" void __cdecl func_00684200(int, TypedPercentItem*);

TypedPercentItem* TypedPercentItem::func_0075f300(const char* arg)
{
    String str;
    func_0075ee80(&str);
    String_ctor(&str, arg);

    void* vftable = str.vftable;
    void (__stdcall *vfunc)(void*, String*) = *(void (__stdcall**)(void*, String*))((char*)vftable + 4);
    vfunc(vftable, &str);

    String_dtor(&str);

    func_00684200(0, this);

    if (str.refCount) {
        long old = _InterlockedExchangeAdd((volatile long*)&str.refCount, -1);
        if (old == 1) {
            void* objVftable = str.vftable;
            void (__stdcall *dtor1)(void*) = *(void (__stdcall**)(void*))((char*)objVftable + 4);
            dtor1(objVftable);
            long old2 = _InterlockedExchangeAdd((volatile long*)((char*)&str + 8), -1);
            if (old2 == 1) {
                void (__stdcall *dtor2)(void*) = *(void (__stdcall**)(void*))((char*)objVftable + 8);
                dtor2(objVftable);
            }
        }
    }

    return this;
}
