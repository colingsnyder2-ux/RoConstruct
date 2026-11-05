// from server: 40% by atomic.potato
extern "C" void Function006eb190(void*);

struct EventDesc
{
    int f(void*);
    char* field2c;
};

int EventDesc::f(void* value)
{
    if (value != 0)
        Function006eb190(field2c +
                         (reinterpret_cast<int>(value) - 0x1c));
    else
        Function006eb190(field2c);
    return 0;
}
