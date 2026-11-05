// from server: 100% by tester
struct Ball {
    void setFlag(unsigned char value, int dummy);
};

void Ball::setFlag(unsigned char value, int dummy) {
    *(unsigned char*)((char*)this + 0x40) = value;
}
