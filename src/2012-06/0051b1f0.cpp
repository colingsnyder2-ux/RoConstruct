// from server: 100% by Intel
struct Ogre_istreamDataStream {
    char pad[196];
    int field_c4;
    int get_field_c4_less_than_zero();
};

int Ogre_istreamDataStream::get_field_c4_less_than_zero() {
    return field_c4 < 0;
}
