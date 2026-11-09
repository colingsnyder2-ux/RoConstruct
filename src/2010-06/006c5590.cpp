// from server: 62% by atomic.potato
typedef int Handle;

extern "C" Handle __stdcall sub_6c53a0(void *value);

struct FlagStandService
{
    void f(void *value);
};

void sub_6c4f30(Handle value);

void FlagStandService::f(void *value)
{
    Handle result = sub_6c53a0(value);
    if (result)
        sub_6c4f30(result);
}
