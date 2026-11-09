// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_77E69C(void*);
extern "C" void* __stdcall sub_77E660(void*, const char*);
extern "C" void* __stdcall sub_77E6A8(void*);
extern "C" void* __stdcall sub_77E6AC(void*);

extern "C" void* __cdecl sub_444B70(void*);
extern "C" void* __cdecl sub_443390(void*, void*);
extern "C" void __cdecl sub_436490(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_436450();
extern "C" void* __cdecl sub_630634();
extern "C" void* __cdecl sub_63063A();
extern "C" void __cdecl sub_630A1E();
extern "C" void __cdecl sub_434C70();

struct CDeclarationView
{
    void updateDeclarationView(void* item);
};

void CDeclarationView::updateDeclarationView(void* item)
{
    char buf[0x40];
    void* v;
    void* p;
    void* q;
    void* str;
    int n;

    if (*(char*)((char*)this + 0xa8) == 0)
    {
        if (*(int*)((char*)item + 0xc) != *(int*)((char*)this + 0xac))
            return;
    }

    v = sub_444B70(buf);
    p = *(void**)v;

    q = sub_443390(p, item);

    if (q != 0)
    {
        if (*(char*)((char*)q + 0xe8) == 0)
            return;
    }

    sub_77E69C((char*)item + 4);
    sub_77E660(buf, (const char*)0x78cc4c);

    str = (char*)item + 0x18;
    sub_436490(0, 0, 0, 0, 0);

    n = (*(int*)((char*)item + 0x10) != 0) ? 5 : 4;

    sub_77E660(buf, (const char*)0x78cc48);
    sub_77E6A8(buf);

    sub_630634();
    sub_63063A();
    sub_434C70();
    sub_77E6AC(buf);
}
