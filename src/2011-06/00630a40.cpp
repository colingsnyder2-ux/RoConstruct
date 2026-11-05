// from server: 90% by atomic.potato
struct Tool {
    char pad[0x220];
    int value220;
    int value224;
    int value228;
    void get(int* result);
};

void Tool::get(int* result) {
    result[0] = value220;
    result[1] = value224;
    result[2] = value228;
}
