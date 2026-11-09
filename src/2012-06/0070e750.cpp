// from server: 61% by atomic.potato
struct RemoteEventDesc;

extern "C" int sub_4c83e0(void*);

struct RemoteEventDesc {
    int f(void*);
};

int RemoteEventDesc::f(void* value) {
    char* base = *reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x2c);
    if (value)
        return sub_4c83e0(base + (reinterpret_cast<char*>(value) - reinterpret_cast<char*>(0x1c)));
    return sub_4c83e0(base);
}
