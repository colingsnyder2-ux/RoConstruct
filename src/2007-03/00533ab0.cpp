// from server: 100% by tester
struct T_func_005a4830 {
    void m();
};

void T_func_005a4830::m()
{
    int* p = *(int**)((char*)this + 4);
    *(int*)this = 0x7a5084;
    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 4) = 0x7a507c;
}