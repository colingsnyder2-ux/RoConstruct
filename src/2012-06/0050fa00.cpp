// from server: 26% by Intel
struct NodeData {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

bool __cdecl CheckNode(const unsigned char* node, const NodeData* data) {
    unsigned char flags = *node;
    unsigned char type = flags & 7;
    unsigned char group = flags >> 6;
    bool result = false;

    if (type <= 4) {
        switch (type) {
        case 0: {
            unsigned char neighborFlags = node[data->field_C];
            result = (neighborFlags & 0x38) == 0x28;
            break;
        }
        case 1:
        case 2:
        case 3: {
            int offset;
            if (group == 0) offset = data->field_C + (int)node - 1;
            else if (group == 1) offset = data->field_C + data->field_8 + (int)node;
            else if (group == 2) offset = data->field_C - data->field_8 + (int)node;
            else offset = data->field_C + (int)node + 1;

            unsigned char neighborFlags = *(unsigned char*)offset;
            unsigned char neighborType = (neighborFlags >> 3) & 7;

            if (neighborType != 5) {
                if (neighborType == 1) {
                    unsigned char neighborGroup = neighborFlags >> 6;
                    if (neighborGroup != group) {
                        result = true;
                    }
                }
            }
            break;
        }
        case 4: {
            unsigned char neighborFlags = node[data->field_C];
            unsigned char neighborType = (neighborFlags >> 3) & 7;
            if (neighborType != 5 && neighborType != 4) {
                result = true;
            }
            break;
        }
        }
    }

    if (!result && group <= 3) {
        switch (group) {
        case 0: {
            unsigned char neighborFlags = node[data->field_C];
            unsigned char neighborType = (neighborFlags >> 3) & 7;
            if (neighborType != 5 && neighborType != 4) {
                result = true;
            }
            break;
        }
        case 1: {
            int index = data->field_C + data->field_8;
            unsigned char neighborFlags = node[index];
            unsigned char neighborType = (neighborFlags >> 3) & 7;
            if (neighborType != 5 && neighborType != 4) {
                result = true;
            }
            break;
        }
        case 2: {
            int index = data->field_C - data->field_8;
            unsigned char neighborFlags = node[index];
            unsigned char neighborType = (neighborFlags >> 3) & 7;
            if (neighborType != 5 && neighborType != 4) {
                result = true;
            }
            break;
        }
        case 3: {
            int index = data->field_C + data->field_8;
            unsigned char neighborFlags = node[index];
            unsigned char neighborType = (neighborFlags >> 3) & 7;
            if (neighborType != 5 && neighborType != 4) {
                result = true;
            }
            break;
        }
        }
    }

    return result;
}
