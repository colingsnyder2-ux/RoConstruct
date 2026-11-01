// from server: 34% by Intel
struct SequenceBase {
    int __cdecl findLastMatch(char* start, char* end, char*& outStart, char*& outEnd, int(__cdecl* predicate)(char));
};

int SequenceBase::findLastMatch(char* start, char* end, char*& outStart, char*& outEnd, int(__cdecl* predicate)(char)) {
    char* current = end;
    while (current != start) {
        char c = current[-1];
        --current;
        if (predicate(c)) {
            break;
        }
    }
    outStart = start;
    outEnd = current + 1;
    return 0;
}
