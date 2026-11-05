// from server: 100% by tester
struct InsertModelFromRobloxVerb {
    char pad[0x2c];
    void* field_c;
    bool method();
};

bool InsertModelFromRobloxVerb::method() {
    return *(int*)((char*)field_c + 0x1d0) != 0;
}