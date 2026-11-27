// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct AsyncResult {
    void cancel();
};
extern "C" void __cdecl operator_delete(void*);
struct UserInputJob {
    char pad[0x22c];
    AsyncResult result;
    void sub_978670();
    UserInputJob* stepDataModelJob(int);
};
UserInputJob* UserInputJob::stepDataModelJob(int flags)
{
    result.cancel();
    operator_delete(*(void**)&result);
    sub_978670();
    if (flags & 1)
        operator_delete(this);
    return this;
}
