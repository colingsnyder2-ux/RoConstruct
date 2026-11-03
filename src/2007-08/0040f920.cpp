// from server: 81% by EspClaude
// roc 2007-08 0040f920  std::vector<{std::string,int,int}> instantiation (_Uninit_copy / _Insert_n)
#include <string>
#include <vector>

struct HistoryEntry {
    std::string text;
    int a;
    int b;
};

template class std::vector<HistoryEntry>;
