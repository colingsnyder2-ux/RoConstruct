// from server: 59% by atomic.potato
struct LogManager
{
    void *get_0042cdf0();
};

extern "C" void *G1_func_004de800();

void *LogManager::get_0042cdf0()
{
    void *value = *(void **)((char *)this + 0x2c);
    if (value)
        return G1_func_004de800();
    return 0;
}
