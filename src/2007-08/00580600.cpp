// from server: 12% by colin
struct Log {
    char pad[0x14];
    int field14;
    Log* ensure();
};

extern "C" void __cdecl sub_580320(Log*);

Log* Log::ensure() {
    if (field14 == 0) {
        sub_580320(this);
    }
    return this;
}
