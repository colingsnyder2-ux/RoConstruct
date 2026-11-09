// from server: 100% by atomic.potato
struct ActionStation
{
    int getValue();
    char _padding[0x288];
    int value;
};

int ActionStation::getValue()
{
    switch (value)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 1;
    }
}
