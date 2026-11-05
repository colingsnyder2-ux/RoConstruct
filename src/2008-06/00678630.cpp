// from server: 100% by king_originala
struct HistoryBuffer {
    int position;
    int reserved;
    char entries[100][20];
    char* get(int offset);
};

char* HistoryBuffer::get(int offset) {
    int index = position - offset - 1;
    return entries[index % 100];
}
