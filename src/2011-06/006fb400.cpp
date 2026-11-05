// from server: 66% by atomic.potato
extern "C" void __stdcall Notify(int);

struct EnumPropDescriptor {
    char pad[180];
    struct Data {
        char pad2[168];
        float value;
    } *data;

    void set(float value);
};

void EnumPropDescriptor::set(float value) {
    if (value != data->value) {
        data->value = value;
        Notify(0xcd27bc);
    }
}
