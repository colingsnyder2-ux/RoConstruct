// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_workspacecameracall_f1bc359cfb700d43.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace RBX {
    class Instance {public:
        virtual ~Instance();
    };

    struct ServiceProvider;

    class HopperBin {public:
        virtual ~HopperBin();
        void activate(ServiceProvider*);
    };

    typedef G3D::CoordinateFrame Frame;

    class ILocation {public:
        virtual Frame getFrame() = 0;
    };

    class IRenderable {public:
        virtual ~IRenderable();
    };
}

RBX::ServiceProvider* __cdecl func_00590d80(RBX::Instance*);


extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern unsigned char instanceType;
extern unsigned char hopperType;
extern unsigned char locationType;
extern unsigned char renderableType;

struct Result {
    void finish(const RBX::Frame&,int);
};

struct Processor {
    virtual void reserved();
    virtual Result* get() const;
};

typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;

struct Workspace {
    unsigned char padding0[0x108];
    Children* children;
    unsigned char padding1[0x17c];
    Processor processor;
    unsigned char padding2[0x1b0];
    int state;

    void prepare();
    unsigned int count();
    int update(int);
};

int Workspace::update(int argument) {
    prepare();
    RBX::HopperBin* selected = 0;

    for (unsigned int i = 0; i < count(); ++i) {
        RBX::HopperBin* hopper = dynamic_cast<RBX::HopperBin*>((*children)[i].get());
        RBX::ILocation* location = dynamic_cast<RBX::ILocation*>((*children)[i].get());
        RBX::IRenderable* renderable = dynamic_cast<RBX::IRenderable*>((*children)[i].get());

        if (location && renderable) {
            RBX::Frame frame = location->getFrame();
            Processor* p = &processor;
            p->get()->finish(frame, argument);
        }

        if (hopper)
            selected = hopper;
    }

    if (selected)
        selected->activate(
            func_00590d80(reinterpret_cast<RBX::Instance*>(this)));

    return state = state <= 0;
}