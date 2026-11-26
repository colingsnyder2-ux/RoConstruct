// from server: 100% by Xemicl
// from server: 100% by Xemicl
// copied from an identical function in another client (function ??1Bucket@AggregatingSceneManager@Render@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX { namespace Render {
class BucketBase { public: ~BucketBase(); char data[0x48]; };
class AggregatingSceneManager { public:
    class Bucket : public BucketBase {
    public:
        ~Bucket();
        std::string name;
    };
};
AggregatingSceneManager::Bucket::~Bucket() {}
} }
