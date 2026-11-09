// from server: 76% by atomic.potato
struct S
{
    void Set(unsigned char value);
    unsigned char field_90[146];
};

void S::Set(unsigned char value)
{
    if (field_90[145] == value)
        return;

    field_90[145] = value;
    *(unsigned long *)0x00412264 = 0xcd2264;
}
