// from server: 100% by colin
struct Ball {
    char pad[0x5c];
    int field_5c;
    void setField(int value);
};

void Ball::setField(int value) {
    if (value != field_5c) {
        field_5c = value;
    }
}
