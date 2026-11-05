// from server: 100% by EspClaude
// roc 2007-08 0044d830  history list: copy the current entry's text (std::vector<{std::string,int,int}>)
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
    bool getCurrent(std::string& text) const;
    bool getNext(std::string& text) const;
};

bool History::getCurrent(std::string& text) const
{
    if (current >= 0) {
        text = entries[current].text;
        return true;
    }
    return false;
}

bool History::getNext(std::string& text) const
{
    if (current + 1 < (int)entries.size()) {
        text = entries[current + 1].text;
        return true;
    }
    return false;
}
