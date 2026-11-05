// from server: 44% by colin
struct CSelectionPropGrid;

struct CSelectionPropGrid
{
    void func_0043ae20(void*);
};

extern "C" void* __stdcall sub_699000(int);
extern "C" void __stdcall sub_699320(void*, int, void*);
extern "C" void* __stdcall sub_4397d0(void*, int);
extern "C" void __stdcall sub_438e10(void*, void*);
extern "C" void __stdcall sub_4339d0(void*, void*);
extern "C" void __stdcall sub_464ec0(void*, void*);

extern "C" int (__stdcall *p_77dd98)();
extern "C" int (__stdcall *p_77dcb8)(void*, int);
extern "C" void (__stdcall *p_77ddbc)(void*);

void CSelectionPropGrid::func_0043ae20(void* arg)
{
    int* obj = (int*)sub_4397d0(this, *(int*)(*(int*)((char*)arg + 0x124) + 8));
    int i = 0;
    if (*(int*)((char*)*(int*)((char*)obj + 0xb8) + 0x28) > 0)
    {
        do
        {
            void* v1;
            sub_438e10(sub_699000(i), &v1);
            void* v2;
            sub_438e10(arg, &v2);
            int r = p_77dcb8(v2, p_77dd98());
            p_77ddbc(&v2);
            p_77ddbc(&v1);
            if (r < 0)
                break;
            i++;
        } while (i < *(int*)((char*)*(int*)((char*)obj + 0xb8) + 0x28));
    }
    sub_699320(obj, i, arg);
    int* tmp;
    sub_4339d0((char*)this + 0x19c, &tmp);
    tmp = (int*)((char*)arg + 0x10c);
    sub_464ec0((char*)this + 0x18c, &tmp);
}
