// from server: 29% by colin
extern "C" void __stdcall _invalid_parameter_noinfo();

struct EnumDescriptor;

struct Item {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad0[4];
    Item** allItemsBegin;
    Item** allItemsEnd;
    char pad1[0x100 - 0x0C];
    bool convertToIndex(int value, unsigned int* index) const;
};

bool EnumDescriptor::convertToIndex(int value, unsigned int* index) const {
    Item** it = allItemsBegin;
    Item** end = allItemsEnd;
    if (it > end) {
        _invalid_parameter_noinfo();
    }
    Item** last = allItemsEnd;
    if (allItemsBegin > last) {
        _invalid_parameter_noinfo();
    }
    Item** cur = allItemsBegin;
    if (cur != 0) {
        if (cur != cur) {
            _invalid_parameter_noinfo();
        }
    } else {
        _invalid_parameter_noinfo();
    }
    while (it != last) {
        if (cur == 0) {
            _invalid_parameter_noinfo();
        }
        if (it < cur) {
            _invalid_parameter_noinfo();
        }
        Item* item = *it;
        unsigned int idx;
        if (convertToIndex(item->value, &idx)) {
            if (idx != 0) {
                *index = idx;
                return true;
            }
        }
        if (it < cur) {
            _invalid_parameter_noinfo();
        }
        ++it;
    }
    *index = 0;
    return false;
}
