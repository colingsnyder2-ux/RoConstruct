// from server: 43% by Intel
struct TestService {
    void __cdecl func(int* outStart, int* outEnd, const char* start, const char* end);
};

void TestService::func(int* outStart, int* outEnd, const char* start, const char* end) {
    const char* current = start;
    while (current != end) {
        char c = *current;
        if (c != ' ' || c == '\t') {
            ++current;
        } else {
            break;
        }
    }
    *outStart = reinterpret_cast<int>(start);
    *outEnd = reinterpret_cast<int>(current);
}
