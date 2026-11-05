// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX { namespace Render {
class BucketBase { public: ~BucketBase(); char data[0x20]; };
class AggregatingSceneManager { public:
    class Bucket : public BucketBase {
    public:
        ~Bucket();
        std::string name;
    };
};
AggregatingSceneManager::Bucket::~Bucket() {}
} }
