// from server: 19% by Intel
typedef int DWORD;

struct VCEvent
{
    DWORD data4c;
    DWORD data48;
};

extern "C" void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" void __stdcall LeaveCriticalSection(void* lpCriticalSection);
extern "C" int* __stdcall func_009782e0(void* arg1);

int __sp_counted_impl_p(VCEvent* this_)
{
    int result = 0;
    DWORD diff = this_->data4c - this_->data48;

    if ((diff & 0xfffffff8) == 0)
    {
        result = 0;
    }
    else
    {
        EnterCriticalSection((void*)0xb221b8);

        DWORD buffer[4];
        buffer[0] = this_->data4c;
        buffer[1] = (DWORD)(this_ + 0x2c);
        buffer[2] = this_->data48;
        buffer[3] = (DWORD)0x455850;

        int* res = func_009782e0(buffer);
        DWORD val1 = *res;

        LeaveCriticalSection((void*)0xb221b8);

        if (val1 != this_->data4c)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }

    return result;
}
