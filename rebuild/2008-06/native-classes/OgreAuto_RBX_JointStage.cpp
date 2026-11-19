// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/v8world/JointStage2008.h"
#include "../native-headers/AppUnit658/Edge.h"

namespace RBX {
void JointStage::insertToListAndMap(RBX::Edge* e)
{
    Joint* value = reinterpret_cast<Joint*>(e);
    incompleteJoints.insert(value);

    Primitive* key = e->getPrimitive(0);
    if (key)
    {
        std::pair<Primitive* const, Joint*> entry(key, reinterpret_cast<Joint*>(e));
        jointMap.insert(entry);
    }

    key = e->getPrimitive(1);
    if (key)
    {
        std::pair<Primitive* const, Joint*> entry(key, reinterpret_cast<Joint*>(e));
        jointMap.insert(entry);
    }
}
}
