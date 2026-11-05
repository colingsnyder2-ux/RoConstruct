// from server: 47% by atomic.potato
extern "C" void std_string_ctor(void*, const char*);

struct FilteredSelection {
    int f(const char*);
};

int FilteredSelection::f(const char* p) {
    char storage[28];
    std_string_ctor(storage, "SelectionRotate");
    return 0;
}
