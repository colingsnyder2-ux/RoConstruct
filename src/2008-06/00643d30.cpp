// from server: 100% by atomic.potato
struct HumanoidState
{
    int getValue();
    int padding24[9];
    int field24;
};

int HumanoidState::getValue()
{
    if (field24)
        return field24 + 0x228;
    return 0;
}
