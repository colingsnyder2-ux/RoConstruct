// =============================================================================
// LDraw2RobloxMapRoot.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/LDraw2RobloxMapRoot.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "util/LDrawMapRoot.h"
#include "v8xml/XmlSerializer.h"
#include <fstream>
#include <memory>
#include <cstdlib>

static const char* nativeCString(const std::string& value) {
    const char* (std::string::*method)() const = &std::string::c_str;
    return (value.*method)();
}
extern const RBX::Name& tag_schema_version;
extern const RBX::Name& tag_color_map;
extern const RBX::Name& tag_color;
extern const RBX::Name& tag_ldraw_code;
extern const RBX::Name& tag_roblox_code;
extern const RBX::Name& tag_part_map;
extern const RBX::Name& tag_part;
extern const RBX::Name& tag_name;
extern const RBX::Name& tag_description;
extern const RBX::Name& tag_ldraw_filename;
extern const RBX::Name& tag_mapping_fidelity;
extern const RBX::Name& tag_roblox_part;
extern const RBX::Name& tag_shape;
extern const RBX::Name& tag_form_factor;
extern const RBX::Name& tag_size_vect3;
extern const RBX::Name& tag_y_offset;

namespace RBX { namespace LDraw2Lua {
LDraw2RobloxMapRoot::LDraw2RobloxMapRoot(std::string filename):path(filename) {
    const char*(std::string::*fileCString)()const=&std::string::c_str;
    std::ifstream input((path.*fileCString)());
    TextXmlParser parser(input.rdbuf());
    std::auto_ptr<XmlElement> root=parser.parse();
    const XmlElement* item=root->findFirstChildByTag(tag_schema_version);
    if(item) item->getValue(version);
    item=root->findFirstChildByTag(tag_color_map);
    if(item) {
        const XmlElement* color=item->findFirstChildByTag(tag_color);
        std::string text;
        while(color) {
            int found=0;
            color->findFirstChildByTag(tag_name);
            item=color->findFirstChildByTag(tag_ldraw_code);
            int ldraw=-1;
            if(item) { ++found; item->getValue(text); ldraw=atoi(nativeCString(text)); }
            item=color->findFirstChildByTag(tag_roblox_code);
            int roblox=-1;
            if(item) { ++found; item->getValue(text); roblox=atoi(nativeCString(text)); }
            if(found==2) {
                LDraw2RobloxColorMap* entry=new LDraw2RobloxColorMap(ldraw,roblox);
                LDraw2RobloxColorMap* previous=findColor(entry->getLDrawCode());
                if(previous) delete previous;
                colors[entry->getLDrawCode()]=entry;
            }
            color=color->nextSibling();
        }
    }
    item=root->findFirstChildByTag(tag_part_map);
    if(item) {
        const XmlElement* part=item->findFirstChildByTag(tag_part);
        while(part) {
            int found=0;
            item=part->findFirstChildByTag(tag_name);
            std::string name("");
            if(item) { ++found; item->getValue(name); }
            item=part->findFirstChildByTag(tag_description);
            std::string description("");
            if(item) { ++found; item->getValue(description); }
            item=part->findFirstChildByTag(tag_ldraw_filename);
            std::string ldrawFilename("");
            if(item) { ++found; item->getValue(ldrawFilename); }
            item=part->findFirstChildByTag(tag_mapping_fidelity);
            std::string fidelityText("");
            int fidelity=2;
            if(item) { ++found; item->getValue(fidelityText); fidelity=readFidelity(fidelityText); }
            LDraw2RobloxPartMap* entry=new LDraw2RobloxPartMap(name,description,ldrawFilename,fidelity);
            const XmlElement* child=part->findFirstChildByTag(tag_roblox_part);
            if(child) {
                ++found;
                while(child) {
                    int fields=0;
                    item=child->findFirstChildByTag(tag_shape);
                    std::string text("");
                    int shape=999;
                    if(item) { ++fields; item->getValue(text); shape=readShape(text); }
                    item=child->findFirstChildByTag(tag_form_factor);
                    text="";
                    int formFactor=0;
                    if(item) { ++fields; item->getValue(text); formFactor=readFormFactor(text); }
                    item=child->findFirstChildByTag(tag_size_vect3);
                    std::string size("");
                    if(item) { ++fields; item->getValue(size); }
                    item=child->findFirstChildByTag(tag_y_offset);
                    std::string offset("");
                    if(item) { ++fields; item->getValue(offset); }
                    if(fields==4) entry->addPart(NativeRobloxPart(shape,formFactor,size,offset));
                    child=child->nextSibling();
                }
            }
            if(found==5) addPartMap(entry);
            part=part->nextSibling();
        }
    }
}
} }

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::LDraw2Lua::LDraw2RobloxPartMap *> > >;
template class std::_Tree<std::_Tmap_traits<int,RBX::LDraw2Lua::LDraw2RobloxColorMap *,std::less<int>,std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::LDraw2Lua::LDraw2RobloxPartMap *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::LDraw2Lua::LDraw2RobloxPartMap *> >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<int,RBX::LDraw2Lua::LDraw2RobloxColorMap *,std::less<int>,std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::LDraw2Lua::LDraw2RobloxPartMap *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::LDraw2Lua::LDraw2RobloxPartMap *> >,0> >::_Node *>;
template class std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::LDraw2Lua::LDraw2RobloxPartMap *> >;
template class std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::LDraw2Lua::LDraw2RobloxPartMap *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::LDraw2Lua::LDraw2RobloxPartMap *> > >;

namespace RBX { namespace LDraw2Lua {
LDraw2RobloxMapRoot::~LDraw2RobloxMapRoot()
{
    std::map<int, LDraw2RobloxColorMap*>::iterator color;
    for (color = colors.begin(); color != colors.end(); ++color) delete color->second;
    std::map<std::string, LDraw2RobloxPartMap*>::iterator part;
    for (part = parts.begin(); part != parts.end(); ++part) delete part->second;
}
} }

template class std::map<int,RBX::LDraw2Lua::LDraw2RobloxColorMap *,std::less<int>,std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> > >;
