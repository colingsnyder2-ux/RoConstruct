// from server: 100% by king_originala
struct ChatEnter {
    unsigned int words[83];

    void initialize();
    ChatEnter* construct(unsigned int value);
};

ChatEnter* ChatEnter::construct(unsigned int value)
{
    initialize();
    words[82] = value;
    words[0] = 0x84a7ac;
    words[4] = 0x84a79c;
    words[5] = 0x84a794;
    words[8] = 0x84a78c;
    words[9] = 0x84a77c;
    words[17] = 0x84a76c;
    words[25] = 0x84a75c;
    words[33] = 0x84a74c;
    words[41] = 0x84a73c;
    words[49] = 0x84a72c;
    words[76] = 0x84a724;
    return this;
}
