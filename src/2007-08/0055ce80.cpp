// from server: 100% by EspClaude
// roc 2007-08 0055ce80  data-state history: more than 10 entries
#include <string>
#include <vector>

struct HistoryEntry {
    std::string text;
    int a;
    int b;
};

class History {
    int reserved;
    int current;
    std::vector<HistoryEntry> entries;
public:
    bool isLong() const;
};

bool History::isLong() const
{
    return entries.size() > 10;
}
