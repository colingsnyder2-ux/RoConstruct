// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
class HuffmanEncodingTree {
public:
    ~HuffmanEncodingTree();
};

class RakPeer {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual bool IsActive() const;
    virtual bool DeleteCompressionLayer(bool inputLayer);
    char pad[0x9f4 - 4];
    HuffmanEncodingTree* inputTree;
    HuffmanEncodingTree* outputTree;
};

bool RakPeer::DeleteCompressionLayer(bool inputLayer)
{
    if (IsActive())
        return false;

    if (inputLayer) {
        if (inputTree) {
            delete inputTree;
            inputTree = 0;
        }
    } else {
        if (outputTree) {
            delete outputTree;
            outputTree = 0;
        }
    }

    return true;
}
