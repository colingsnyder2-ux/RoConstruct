#include <string>
#include <cctype>

int stringCompareNoCase(const std::string& left, const std::string& right)
{
    std::string::const_iterator a = left.begin();
    std::string::const_iterator b = right.begin();
    while (a != left.end() && b != right.end()) {
        if (::toupper(*a) != ::toupper(*b))
            return ::toupper(*a) < ::toupper(*b) ? -1 : 1;
        ++a;
        ++b;
    }
    unsigned int leftSize = left.size(), rightSize = right.size();
    if (leftSize == rightSize) return 0;
    return leftSize < rightSize ? -1 : 1;
}
