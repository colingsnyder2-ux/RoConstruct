#pragma once
// 2008-06 native RBX::MeshId class. Inherits from ContentId.

#include "util/ContentProvider.h"

namespace RBX
{
    class MeshId : public ContentId
    {
    public:
        MeshId() : ContentId() {}
        MeshId(const std::string& id) : ContentId(id) {}
        MeshId(const char* id) : ContentId(id) {}
        MeshId(const ContentId& id) : ContentId(id) {}
    };
}