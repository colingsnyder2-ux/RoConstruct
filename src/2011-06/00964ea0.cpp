// from server: 73% by atomic.potato
extern "C" void G1_func_007f8e90(void*, void*);

void* func_00964ea0(void* first, void* last, void* destination)
{
    while (first != last)
    {
        last = (char*)last - 4;
        destination = (char*)destination - 4;
        G1_func_007f8e90(destination, last);
    }
    return destination;
}
