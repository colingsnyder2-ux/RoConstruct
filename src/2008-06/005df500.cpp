// from server: 100% by colin
// from server: 80% by colin
struct Message {
    char padding[0x17c];
    unsigned char flag;
    char alignment[3];
    char first[0xc];
    char second[0xc];
    struct Cost { float x, y, z; };
    Cost getPtr() const;
};

Message::Cost Message::getPtr() const {
    const Cost* source;
    if (flag)
        source = reinterpret_cast<const Cost*>(first);
    else
        source = reinterpret_cast<const Cost*>(second);
    Cost result;
    result.x = source->x;
    result.y = source->y;
    result.z = source->z;
    return result;
}
