// from server: 12% by atomic.potato
struct BallBlockConnector
{
    int state;
    int get();
};

int BallBlockConnector::get()
{
    if (state == 2)
        goto state_one;
    if (state == 1)
        goto done;
    goto fallback;

state_one:
    goto done;

fallback:
    goto done;

done:
    return state;
}
