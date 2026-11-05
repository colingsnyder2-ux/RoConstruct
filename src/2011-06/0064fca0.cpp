// from server: 51% by atomic.potato
struct DropperTool {
    bool __cdecl replaceBackslashes(char* begin, char* end, bool flag);
};

bool DropperTool::replaceBackslashes(char* begin, char* end, bool flag) {
    char* p = begin;
    while (p != end) {
        if (*p == '\\') {
            *p = '/';
        }
        ++p;
    }
    return flag;
}
