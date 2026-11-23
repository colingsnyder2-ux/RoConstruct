// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace Ogre {
class Matrix4;
class __declspec(dllimport) Camera {
public:
    const Matrix4& getViewMatrix(bool) const;
};
}

#define P4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();

// INFERRED: vtable layout from slot offsets 0x68/0x6c (sink) and 0x148 (camera); padding slots unused
struct ViewSink {
    P4(a) P4(b) P4(c) P4(d) P4(e) P4(f)
    virtual void padg(); virtual void padh();
    virtual void setViewMatrix(const Ogre::Matrix4* m);
    virtual void setSecond(const void* p);
};

struct CameraV {
    P4(a) P4(b) P4(c) P4(d) P4(e) P4(f) P4(g) P4(h) P4(i) P4(j)
    P4(k) P4(l) P4(m) P4(n) P4(o) P4(p) P4(q) P4(r) P4(s)
    virtual void padt(); virtual void padu();
    virtual const void* getSecond();
};

// INFERRED: layout from disassembly
struct ViewOwner {
    char pad0[0x34];
    ViewSink* sink;
    char pad1[0xb8 - 0x38];
    Ogre::Camera* camera;
    char pad2[0x41d8 - 0xbc];
    bool dirtyView;
    bool dirtySecond;
};

extern "C" void __fastcall fn_0068c480(ViewOwner* self, int unusedEdx)
{
    if (self->dirtyView) {
        self->sink->setViewMatrix(&self->camera->getViewMatrix(true));
        self->dirtyView = false;
    }
    if (self->dirtySecond) {
        self->sink->setSecond(((CameraV*)self->camera)->getSecond());
        self->dirtySecond = false;
    }
}
