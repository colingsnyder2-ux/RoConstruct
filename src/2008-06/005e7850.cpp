// from server: 100% by king_originala
struct Ball {
    char padding[0xB8];
    int values[1];
    void set(int index, int value);
};

void Ball::set(int index, int value) {
    if (values[index] != value)
        values[index] = value;
}
