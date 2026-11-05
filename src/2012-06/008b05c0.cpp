// from server: 100% by Intel
struct PluginMouse {
    int getValue() const;
};

int PluginMouse::getValue() const {
    return *(const short*)((const char*)this + 0xFE);
}
