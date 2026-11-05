// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <deque>
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; ~shared_ptr(); }; }
namespace RBX { namespace Network {
class Item;
class Base { public: ~Base(); char pad[0x1d0]; };
class Streamer : public Base {
public:
    std::deque<boost::shared_ptr<Item> > queue;
    ~Streamer();
};
Streamer::~Streamer() {}
}}
