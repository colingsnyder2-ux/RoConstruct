// from server: 100% by colin
// from server: 80% by colin




namespace RBX {

struct Message {
    char pad[0x17c];
    bool flag;
    char pad2[0x1a4 - 0x17d];
    struct Cost { float x, y, z; };
    Cost getPersistentDataCost() const;
};

Message::Cost Message::getPersistentDataCost() const {
    const Cost* source;
    if (flag)
        source = reinterpret_cast<const Cost*>((const char*)this + 0x198);
    else
        source = reinterpret_cast<const Cost*>((const char*)this + 0x1a4);
    Cost result;
    result.x = source->x;
    result.y = source->y;
    result.z = source->z;
    return result;
}

}
