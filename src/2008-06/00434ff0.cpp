// from server: 100% by user
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_declarationaccess_98f9113324c95267.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
struct Text {char storage[28];const char* c_str()const;};
extern const char* (__thiscall* textAccess)(const Text*);
inline const char* Text::c_str()const{return textAccess(this);}
struct Name {
    int unused;
    Text text;
};

struct Node {
    int unused;
    Name* name;
    char padding[0x9c];
    std::vector<Node*> children;
};

struct Target {
    int invoke(int, int);
};

struct Manager {
    char padding[0x130];
    Target* target;
    int invoke(int, int);
};

typedef boost::shared_ptr<Manager> Shared;

Shared __cdecl getManager();

struct Declaration {
    char padding[0x130];
    unsigned char visible;
    unsigned char restricted;
    unsigned char special;
};

struct Settings {
    char padding[0x130];
    unsigned char allowRestricted;
    unsigned char allowSpecial;
};

Settings* __cdecl getSettings();

struct ViewBase1 {};
struct ViewBase2 {};

struct __multiple_inheritance CDeclarationView : ViewBase1, ViewBase2 {
    void func(Node*);
    void* insert(int, const char*, int, int, int, int, int, unsigned int, unsigned int);
    void setItem(void*, int, int, int, int, int, int, Node*);
    void configure(void*, Declaration*);
};

void CDeclarationView::func(Node* node) {
    Declaration* declaration;
    {
        declaration = reinterpret_cast<Declaration*>(
            getManager()->invoke(reinterpret_cast<int>(node), 0));
    }

    bool show = true;
    if (declaration) {
        Settings* settings = getSettings();
        if (declaration->restricted && !settings->allowRestricted)
            show = false;
        else if (declaration->special && !settings->allowSpecial)
            show = false;
        else if (!declaration->visible)
            show = false;
    }

    if (show) {
        Name* n = node->name;
        const char* label = n->text.c_str();
        void* item = insert(0x23, label,
                            3, 3, 0, 0, 0, 0xffff0000, 0xffff0002);
        setItem(item, 4, 0, 0, 0, 0, 0, node);
        configure(item, declaration);
    }

    std::for_each(node->children.begin(),node->children.end(),boost::bind(&CDeclarationView::func,this,_1));
}
