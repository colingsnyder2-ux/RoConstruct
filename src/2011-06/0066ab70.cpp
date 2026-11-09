// from server: 22% by atomic.potato
struct EventDesc
{
    int value;
    int get();
};

int EventDesc::get()
{
    return value;
}
