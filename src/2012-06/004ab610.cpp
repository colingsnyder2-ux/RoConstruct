// from server: 93% by tester
struct AsyncResult {
    void cancel();
};

struct UserInputJob {
    char pad[0x22c];
    AsyncResult result;
    UserInputJob* stepDataModelJob(int);
};

extern "C" void __cdecl operator_delete(void*);
extern "C" void __stdcall sub_978670(void*);

UserInputJob* UserInputJob::stepDataModelJob(int flags)
{
    result.cancel();
    operator_delete(*(void**)&result);
    sub_978670(this);
    if (flags & 1)
        operator_delete(this);
    return this;
}
