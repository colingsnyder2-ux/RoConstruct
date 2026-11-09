// from server: 100% by tester
extern "C" void* sub_00643980();

int sub_006439b0()
{
    char* p = (char*)sub_00643980();
    if (p)
        return *(int*)(p + 0x5c);
    return 0;
}
