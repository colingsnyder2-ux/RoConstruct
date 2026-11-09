// from server: 100% by atomic.potato
struct Tool
{
    int get() const;
};

int Tool::get() const
{
    return *(const int*)((const char*)this + 0x1f4) >= 5;
}
