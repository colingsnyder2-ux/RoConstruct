// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: no headers were provided, so the minimal Ogre-style declarations
// needed by this function are declared locally. The virtual slot order is
// taken from the vtable offsets used in the disassembly.

// INFERRED: the disassembly pushes only one argument (0x38) although the
// inferred prototype lists 8 arguments, so it is declared with one argument.
extern "C" void* fn_006a0920(int size);

namespace Ogre {

class HardwareVertexBuffer;

class __declspec(dllimport) HardwareVertexBufferSharedPtr {
public:
    HardwareVertexBufferSharedPtr& operator=(const HardwareVertexBufferSharedPtr& r);
    virtual ~HardwareVertexBufferSharedPtr();
private:
    // INFERRED: 16-byte shared pointer layout (vtable, rep, use count, mutex)
    void* pRep;
    unsigned* pUseCount;
    void* pMutex;
};

class VertexDeclaration {
public:
    virtual ~VertexDeclaration() {}
    virtual const void* addElement(unsigned short source, unsigned offset, int type, int semantic, unsigned short index);
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual unsigned getVertexSize(unsigned short source);
};

class VertexBufferBinding {
public:
    virtual ~VertexBufferBinding() {}
    virtual void setBinding(unsigned short index, const HardwareVertexBufferSharedPtr& buf);
};

class __declspec(dllimport) VertexData {
public:
    VertexData();
    VertexDeclaration* vertexDeclaration;
    VertexBufferBinding* vertexBufferBinding;
    unsigned vertexStart;
    unsigned vertexCount;
    char pad[0x38 - 0x10];
};

class __declspec(dllimport) VertexElement {
public:
    static unsigned getTypeSize(int type);
};

class HardwareBufferManagerBase {
public:
    virtual ~HardwareBufferManagerBase() {}
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual HardwareVertexBufferSharedPtr createVertexBuffer(unsigned vertexSize, unsigned numVerts, int usage, bool useShadowBuffer);
};

class __declspec(dllimport) HardwareBufferManager : public HardwareBufferManagerBase {
public:
    static HardwareBufferManager& getSingleton();
};

} // namespace Ogre

struct VertexHolder {
    char pad0[0x10];
    Ogre::VertexData* vertexData;               // +0x10
    int count;                                  // +0x14
    char flag;                                  // +0x18
    char pad1[0x24 - 0x19];
    Ogre::HardwareVertexBufferSharedPtr buffer; // +0x24
};

extern "C" void __fastcall fn_006829a0(VertexHolder* self, int unusedEdx, int numVerts)
{
    void* mem = fn_006a0920(0x38);
    Ogre::VertexData* vd = 0;
    if (mem)
        vd = new (mem) Ogre::VertexData();
    self->vertexData = vd;
    vd->vertexStart = 0;

    Ogre::VertexDeclaration* decl = self->vertexData->vertexDeclaration;
    decl->addElement(0, 0, 2, 1, 0);
    unsigned offset = Ogre::VertexElement::getTypeSize(2);
    decl->addElement(0, offset, 4, 5, 0);
    offset += Ogre::VertexElement::getTypeSize(4);
    decl->addElement(0, offset, 1, 7, 0);

    Ogre::HardwareBufferManager& mgr = Ogre::HardwareBufferManager::getSingleton();
    self->buffer = mgr.createVertexBuffer(decl->getVertexSize(0), numVerts, 0xe, false);

    self->vertexData->vertexBufferBinding->setBinding(0, self->buffer);
    self->flag = 0;
    self->count = 4;
}
