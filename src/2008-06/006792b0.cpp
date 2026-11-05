// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_resource_release_4709ef25b50fc1eb.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreResourceManager.h>
#include <OgreResourceGroupManager.h>
#include <OgreStringConverter.h>
#include <OgreString.h>
#include <OgreLogManager.h>
#include <vector>

namespace Ogre {
void releaseUnusedResources(ResourceManager& manager, const String& type,
                            const StringVector& keepPatterns) {
    StringVector names;
    ResourceManager::ResourceMapIterator it = manager.getResourceIterator();
    while (it.hasMoreElements()) {
        ResourcePtr resource = it.getNext();
        const String& name = resource->getName();
        if (resource.useCount() == ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS + 1
                && resource->getGroup() != ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME) {
            for (int i = 0; i < static_cast<int>(keepPatterns.size()); ++i) {
                if (StringUtil::match(name, keepPatterns[i], true))
                    goto nextResource;
            }
            names.push_back(name);
        } else if (resource.useCount() <= ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS) {
            LogManager::getSingleton().logMessage("Strange rc: " + StringConverter::toString(resource.useCount())
                                                  + "for " + name);
        }
    nextResource:;
    }
    for (int i = 0; i < static_cast<int>(names.size()); ++i) {
        ResourcePtr resource = manager.getByName(names[i]);
        manager.remove(resource);
        if (resource.useCount() != 1)
            LogManager::getSingleton().logMessage(String("Wrong ref count ")
                + StringConverter::toString(resource.useCount()) + " for " + type + " " + resource->getName());
        else
            LogManager::getSingleton().logMessage(String("delete: ") + type + " " + resource->getName());
    }
}
}
