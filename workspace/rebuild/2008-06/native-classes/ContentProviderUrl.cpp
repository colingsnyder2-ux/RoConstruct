#include "util/ContentProvider.h"

bool RBX::ContentProvider::isUrl(const std::string& value)
{
    if (value.find("http://") == 0) return true;
    if (value.find("https://") == 0) return true;
    return false;
}
