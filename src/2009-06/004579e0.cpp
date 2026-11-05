// from server: 100% by why2
struct InsertModelFromRobloxVerb {
    char pad[0xc];
    void* field_c;
    bool method();
};

bool InsertModelFromRobloxVerb::method() {
    return *(int*)((char*)field_c + 0x20c) != 0;
}
