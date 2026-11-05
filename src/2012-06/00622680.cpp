// from server: 100% by Viper
struct WedgeBuilder {
    int f(int arg);
};

int WedgeBuilder::f(int arg) {
    if (arg == *(int*)this) {
        return *(int*)((char*)this + 0x74);
    }
    if (arg == *(int*)((char*)this + 4)) {
        return *(int*)((char*)this + 0x78);
    }
    if (arg == *(int*)((char*)this + 8)) {
        return *(int*)((char*)this + 0x7c);
    }
    if (arg == *(int*)((char*)this + 0xc)) {
        return *(int*)((char*)this + 0x80);
    }
    if (arg == *(int*)((char*)this + 0x10)) {
        return *(int*)((char*)this + 0x84);
    }
    return 0;
}
