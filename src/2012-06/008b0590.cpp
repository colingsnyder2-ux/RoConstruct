// from server: 100% by Intel
struct PluginMouse
{
    int getValue();
};

int PluginMouse::getValue()
{
    return *(short*)((char*)this + 0xF8);
}
