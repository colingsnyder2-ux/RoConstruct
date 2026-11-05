// from server: 100% by colin
struct type_info {};

extern const type_info target_type;
extern bool (__thiscall *type_equal)(const type_info*, const type_info&);

union Buffer {
    unsigned int words[6];
    const type_info* type;
    const Buffer* pointer;
};

void __cdecl manage(const Buffer* source, Buffer* destination, int operation)
{
    if (operation == 0) {
        if (destination) {
            destination->words[0] = source->words[0];
            destination->words[1] = source->words[1];
            destination->words[2] = source->words[2];
            destination->words[3] = source->words[3];
            destination->words[4] = source->words[4];
            destination->words[5] = source->words[5];
        }
    } else if (operation != 1) {
        destination->pointer =
            type_equal(destination->type, target_type) ? source : 0;
    }
}
