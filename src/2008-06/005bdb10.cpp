// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <string>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    shared_ptr() : px(0), pn() {}
};

namespace RBX {
class Sound;

class StockSound {
public:
    char pad[0x13c];
    std::map<int, shared_ptr<Sound> > sounds;
    void removeAllChildren();
    void addSound(int id, std::string path);
    void loadSounds();
};

void StockSound::loadSounds()
{
    sounds.clear();
    removeAllChildren();
    addSound(1, "Sounds\\bass.wav");
    addSound(2, "Sounds\\collide.wav");
    addSound(3, "Sounds\\glassbreak.wav");
    addSound(4, "Sounds\\switch.wav");
    addSound(5, "Sounds\\clickfast.wav");
    addSound(6, "Sounds\\Rubber band sling shot.wav");
    addSound(7, "Sounds\\pageturn.wav");
    addSound(8, "Sounds\\electronicpingshort.wav");
    addSound(9, "Sounds\\snap.wav");
    addSound(10, "Sounds\\splat.wav");
    addSound(11, "Sounds\\SWITCH3.wav");
    addSound(12, "Sounds\\flashbulb.wav");
    addSound(13, "Sounds\\swoosh.wav");
    addSound(14, "Sounds\\victory.wav");
}
}
