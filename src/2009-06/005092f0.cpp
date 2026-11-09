// from server: 100% by why2
extern "C" void __cdecl sub_718A32(void*);

struct Job {
    char pad[0x10];
    void* field_10;
    void* field_14;
    void method();
};

void Job::method() {
    if (field_10 != 0) {
        sub_718A32(field_14);
    }
}
