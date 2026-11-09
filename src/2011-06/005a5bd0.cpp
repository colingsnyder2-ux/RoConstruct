// from server: 43% by atomic.potato
struct SoundChannel
{
    int get();
};

int SoundChannel::get()
{
    if (*(void **)((char *)this + 148))
        return (**(int (**)(void))(*(void **)((char *)this + 148)))();
    return 0;
}
