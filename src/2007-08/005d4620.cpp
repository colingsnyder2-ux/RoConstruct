// from server: 100% by colin
struct Mouse {
    char pad[0x16c];
    int field_16c;
    void sub_5d44a0(int);
    void sub_444710(const char*);
    void setCommand(int value);
};

void Mouse::setCommand(int value) {
    if (value != this->field_16c) {
        this->sub_5d44a0(value);
        this->sub_444710((const char*)0x8c69f0);
    }
}
