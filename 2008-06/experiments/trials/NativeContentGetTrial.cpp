#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
#include <G3D/format.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace RBX {
std::auto_ptr<std::istream> ContentProvider::getContent(ContentId ticket)
{
    CachedContent* content = loadContent(ticket, 2, NULL);
    if (!content) throw std::runtime_error(G3D::format("Unable to load %s", ticket.c_str()));
    if (content->data) return std::auto_ptr<std::istream>(new std::istringstream(*content->data));
    return std::auto_ptr<std::istream>(new std::ifstream(content->filename->c_str(), std::ios::binary | std::ios::in));
}
}
