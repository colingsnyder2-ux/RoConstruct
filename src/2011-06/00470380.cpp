// from server: 64% by atomic.potato
struct UploadVideoVerb
{
    struct State
    {
        virtual void unused();
        virtual int ready();
    };

    char padding[0x60];
    State* state;
    int f();
};

int UploadVideoVerb::f()
{
    State* value = state;
    if (value != 0 && value->ready())
        return 1;
    return 0;
}
