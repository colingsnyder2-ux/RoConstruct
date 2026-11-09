// from server: 50% by atomic.potato
extern "C" void call_40df20(void *, const char *, int);
extern "C" void call_a404c8(void *, void *);

void *global_a404c8;

void *function_00419680(void *arg1, const char *arg2, void *arg3)
{
    void *temporary = 0;
    call_40df20(&temporary, arg2, 0);
    call_a404c8(arg3, temporary);
    return arg3;
}
