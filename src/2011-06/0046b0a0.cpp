// from server: 60% by atomic.potato
struct ViewUpdateJob
{
    int run(int);
};

extern "C" void initialize_0046b020(void*, void*, int);
extern "C" void execute_004222f0(void*);

int ViewUpdateJob::run(int value)
{
    *(int*)this = 0;
    initialize_0046b020(this, (void*)0x46afe0, value);
    execute_004222f0(*(void**)((char*)this + 0x1e8));
    return 1;
}
