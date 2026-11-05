// from server: 71% by atomic.potato
struct PartDropTool {
    char pad[8];
    unsigned char field_8;
    char pad2[8];
    int field_14;
    int __cdecl method(double value);
};

int PartDropTool::method(double value) {
    if (value == 0.0) {
        return field_14;
    }
    unsigned int total = *(unsigned int*)&value + *((unsigned int*)&value + 1);
    unsigned int mask = (1u << field_8) - 1;
    mask |= 1;
    unsigned int rem = total % mask;
    return (int)(rem << 5) + field_14;
}
