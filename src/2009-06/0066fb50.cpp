// from server: 100% by why2
struct Geometry {
    char pad[0xf2];
    unsigned char field_f2;
    void setFlag(unsigned char value);
};

void Geometry::setFlag(unsigned char value) {
    if (value != field_f2) {
        field_f2 = value;
    }
}
