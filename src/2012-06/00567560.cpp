// from server: 52% by Intel
struct VRegistry {
    unsigned int field_0;
    int field_4;
    int field_8;
    int field_C;

    bool __stdcall func_567560(char* out);
};

bool __stdcall VRegistry::func_567560(char* out) {
    int v0 = this->field_8;
    int v1 = v0 + 1;
    if (v1 > this->field_0) {
        return false;
    }
    int bit = v0 & 7;
    int mask = 0x80 >> bit;
    int byteIndex = v0 >> 3;
    unsigned char* bits = reinterpret_cast<unsigned char*>(this->field_C);
    bool result = (bits[byteIndex] & mask) != 0;
    *out = result;
    this->field_8 = v1;
    return true;
}
