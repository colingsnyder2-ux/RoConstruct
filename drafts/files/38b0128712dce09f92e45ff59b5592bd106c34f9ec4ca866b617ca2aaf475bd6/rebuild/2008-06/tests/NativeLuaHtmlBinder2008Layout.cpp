#include <stddef.h>
#include "LuaHtmlBinder2008/LuaHtmlBinder2008.h"

// CLuaHtmlView::Binder: 0042c8c0 news 0x34 before the constructor 0042c0d0; constructor/destructor (0042c3c0) field
// accesses: weak_ptr +4/+8, list +0xc (aux +0xc, head +0x20, size +0x24), updatePending +0x28, handler +0x2c,
// element +0x30. RTTI 00810654: enable_shared_from_this<Binder> at +4.
struct LuaHtmlBinderLayout : CLuaHtmlView::Binder {
    static void check();
};
void LuaHtmlBinderLayout::check()
{
    typedef char Size[sizeof(CLuaHtmlView::Binder) == 0x34 ? 1 : -1];
    typedef char ListSize[sizeof(std::list<boost::shared_ptr<CLuaHtmlView::Binder::PropBinding> >) == 0x1c ? 1 : -1];
    typedef char Bindings[offsetof(LuaHtmlBinderLayout, bindings) == 0x0c ? 1 : -1];
    typedef char Pending[offsetof(LuaHtmlBinderLayout, updatePending) == 0x28 ? 1 : -1];
    typedef char Handler[offsetof(LuaHtmlBinderLayout, handler) == 0x2c ? 1 : -1];
    typedef char Element[offsetof(LuaHtmlBinderLayout, element) == 0x30 ? 1 : -1];
}
int luaHtmlBinderSharedFromThisOffset(CLuaHtmlView::Binder* binder)
{
    // 0042c52b: shared_from_this() is called with ecx = this + 4.
    return (int)static_cast<boost::enable_shared_from_this<CLuaHtmlView::Binder>*>(binder) - (int)binder;
}

// CLuaHtmlView::Binder::PropBinding: Binder::bind (0042c760) news 0x20 before the constructor 0042c630, which writes
// instance +0/+4, descriptor +8 and the scoped_connection +0xc..+0x1c.
struct LuaHtmlPropBindingLayout : CLuaHtmlView::Binder::PropBinding {
    static void check();
};
void LuaHtmlPropBindingLayout::check()
{
    typedef char Size[sizeof(CLuaHtmlView::Binder::PropBinding) == 0x20 ? 1 : -1];
    typedef char Instance[offsetof(LuaHtmlPropBindingLayout, instance) == 0x00 ? 1 : -1];
    typedef char Descriptor[offsetof(LuaHtmlPropBindingLayout, descriptor) == 0x08 ? 1 : -1];
    typedef char Connection[offsetof(LuaHtmlPropBindingLayout, connection) == 0x0c ? 1 : -1];
    typedef char ConnectionSize[sizeof(boost::signals::scoped_connection) == 0x14 ? 1 : -1];
}
