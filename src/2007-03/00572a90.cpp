// from server: 100% by tester
struct InsertModelFromRobloxVerb {
    char pad[0x1e0];
    void* field_c;
    bool method();
};

bool InsertModelFromRobloxVerb::method() {
    return *(int*)((char*)field_c + 0x6c) != 0;
}