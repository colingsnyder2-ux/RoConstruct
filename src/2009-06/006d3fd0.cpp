// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace boost {
struct once_flag { unsigned long epoch; };
template<typename Function> void call_once(once_flag& flag, Function f);
}
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    float length() const { return sqrtf(x * x + y * y + z * z); }
};
}
namespace RBX {
struct BlockTemplate { G3D::Vector3 corner; };
class BlockTemplateCache {
public:
    const BlockTemplate* getTemplate(const G3D::Vector3& key);
};
static BlockTemplateCache* blockCache;
static boost::once_flag blockCacheFlag;
void initBlockCache();
class Block {
public:
    virtual ~Block();
    G3D::Vector3 size;
    const BlockTemplate* blockTemplate;
    float radius;
    void buildBlock();
};
void Block::buildBlock()
{
    G3D::Vector3 key = size * -0.5f;
    boost::call_once(blockCacheFlag, &initBlockCache);
    blockTemplate = blockCache->getTemplate(key);
    radius = blockTemplate->corner.length();
}
}
