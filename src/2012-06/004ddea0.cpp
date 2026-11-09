// from server: 100% by tajop
namespace Ogre {
struct TexturePtr {
    TexturePtr& operator=(const TexturePtr& r);
    char pad[16];
};
}

typedef Ogre::TexturePtr& (Ogre::TexturePtr::*TexAssignFn)(const Ogre::TexturePtr&);
extern TexAssignFn g_TexturePtr_assign;

struct Elem {
    float a;
    float b;
    Ogre::TexturePtr tex;
};

Elem* copy_backward_elem(Elem* first, Elem* last, Elem* dest)
{
    while (first != last) {
        --last;
        --dest;
        dest->a = last->a;
        dest->b = last->b;
        (dest->tex.*g_TexturePtr_assign)(last->tex);
    }
    return dest;
}
