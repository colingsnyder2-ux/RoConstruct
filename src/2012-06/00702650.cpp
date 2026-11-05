// from server: 66% by atomic.potato
struct basic_streambuf {
    int sgetc();
    int sbumpc();
};

struct ChangeHistoryService {
    char pad[4];
    basic_streambuf* stream;
    void func();
};

extern char g_table[];

void ChangeHistoryService::func() {
    int c = stream->sgetc();
    while (c != -1) {
        if (g_table[(signed char)c] != 0) {
            stream->sbumpc();
            c = stream->sgetc();
            if (c != -1)
                continue;
        }
        break;
    }
}
