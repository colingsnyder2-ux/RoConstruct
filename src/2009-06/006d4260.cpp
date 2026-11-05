// from server: 100% by why2
struct RBX_Ball {
    char pad[0x3c];
    char field_0x3c;
    void setField(char value, int extra);
};

void RBX_Ball::setField(char value, int extra) {
    field_0x3c = value;
}
