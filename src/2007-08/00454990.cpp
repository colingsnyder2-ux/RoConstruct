// from server: 22% by colin
struct MarshaledListener
{
    char pad[0x130];
    void* begin;
    void* end;
    void* capacity;

    void* get();
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void* __cdecl sub_453620();
extern "C" void* __cdecl sub_453540();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_40e470();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_402a60();
extern "C" void __cdecl sub_554de0();
extern "C" void __stdcall sub_77e6d8();

void* MarshaledListener::get()
{
    sub_725520((void*)0x8bbf14, (void*)0x453990);
    sub_453620();
    int idx = (int)sub_453620();

    void* result = 0;

    if (this->end == 0)
    {
        if ((unsigned)(idx + 1) > 0)
        {
            sub_40e470();
        }
    }
    else
    {
        int count = ((char*)this->end - (char*)this->begin) >> 3;
        if ((unsigned)idx < (unsigned)count)
        {
            result = ((void**)this->begin)[idx];
        }
        else
        {
            sub_77e6d8();
        }
    }

    if (result == 0)
    {
        if ((*(unsigned char*)0x8bbfa8 & 1) == 0)
        {
            *(unsigned*)0x8bbfa8 |= 1;
            sub_725520((void*)0x8bbf10, (void*)0x453980);
            void* a = sub_453540();
            void* b = sub_52cb30();
            *(unsigned char*)0x8bbfa4 = (a == b);
        }

        if (*(unsigned char*)0x8bbfa4 == 0)
        {
            sub_725520((void*)0x8bbf10, (void*)0x453980);
            void* a = sub_453540();
            sub_554de0();
        }
        return 0;
    }

    return result;
}
