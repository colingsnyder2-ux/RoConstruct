// from server: 100% by tester
struct Log {
    char pad[0x138];
    void* stream;
    void closeStream();
};

extern "C" void __cdecl sub_612A80(void*, int, int);

void Log::closeStream() {
    if (stream) {
        sub_612A80(stream, 2, 0);
    }
}
