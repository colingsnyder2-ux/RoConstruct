// from server: 69% by atomic.potato
extern "C" void __cdecl update_value(void *, int);

struct S
{
    char data[0xcc];
    int value;
    void update(int);
};

void S::update(int value)
{
    if (this->value == value)
        return;

    this->value = value;
    update_value((char *)this + 0x144, 0xe19d3c);
}
