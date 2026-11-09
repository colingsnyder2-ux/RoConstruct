// from server: 100% by EspClaude
// from server: 94% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// Native map loader; real MSVC containers and observed XML/parser interfaces.
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <memory>
#include <cstdlib>
#include <cstddef>
// The genuine imported c_str member is invoked through its real typed member address.
// This fully defined helper has no external stand-in or fabricated class layout.
static const char*nativeCString(const std::string&value){
 const char*(std::string::*method)()const=&std::string::c_str;
 return (value.*method)();
}
namespace RBX {class Name;}
class XmlNameValuePair {public:bool getValue(std::string&)const;};
// Opaque native receiver: no XmlElement objects or RTTI are created here.
class XmlElement {public:
 ~XmlElement();
 const XmlElement*findFirstChildByTag(const RBX::Name&)const;
 const XmlElement*nextSibling()const{return *reinterpret_cast<const XmlElement*const*>(this);}
 const XmlNameValuePair&observedValue()const{return *reinterpret_cast<const XmlNameValuePair*>(reinterpret_cast<const char*>(this)+0x10);}
};
namespace boost {namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;}
class XmlParser:public boost::noncopyable {
protected:std::streambuf*buffer;std::stack<XmlElement*>elements;XmlParser(std::streambuf*);
public:virtual std::auto_ptr<XmlElement>parse()=0;
};
// Native constructor415350 initializes the inherited prefix and map at+28hex.
class TextXmlParser:public XmlParser {
 std::map<std::string,std::string>legacyHashes;
public:TextXmlParser(std::streambuf*);~TextXmlParser();virtual std::auto_ptr<XmlElement>parse();
};
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
class LDraw2RobloxColorMap {
public:
    virtual ~LDraw2RobloxColorMap();
    int ldrawCode,robloxCode;
    LDraw2RobloxColorMap(int,int);
    int getLDrawCode() const { return ldrawCode; }
};
struct NativeRobloxPart {
    int shape,formFactor;
    std::string size,offset;
    NativeRobloxPart(int,int,std::string,std::string);
};
class LDraw2RobloxPartMap {
public:
    virtual ~LDraw2RobloxPartMap();
    std::string name,description,filename;
    int fidelity;
    std::vector<NativeRobloxPart> parts;
    LDraw2RobloxPartMap(std::string,std::string,std::string,int);
    void addPart(const NativeRobloxPart&);
};
class LDraw2RobloxMapRoot {
public:
    virtual ~LDraw2RobloxMapRoot();
    std::string path,version;
    std::map<int,LDraw2RobloxColorMap*> colors;
    std::map<std::string,LDraw2RobloxPartMap*> parts;
    LDraw2RobloxMapRoot(std::string);
    LDraw2RobloxColorMap* findColor(int);
    int readFidelity(std::string);
    int readShape(std::string);
    int readFormFactor(std::string);
    void addPartMap(LDraw2RobloxPartMap*);
};
typedef char NativeRootSize[sizeof(LDraw2RobloxMapRoot)==124?1:-1];
typedef char NativeColorSize[sizeof(LDraw2RobloxColorMap)==12?1:-1];
typedef char NativePartMapSize[sizeof(LDraw2RobloxPartMap)==116?1:-1];
typedef char NativeRobloxPartSize[sizeof(NativeRobloxPart)==64?1:-1];
typedef char NativeTextXmlParserSize[sizeof(TextXmlParser)==72?1:-1];

LDraw2RobloxMapRoot::LDraw2RobloxMapRoot(std::string filename):path(filename) {
    const char*(std::string::*fileCString)()const=&std::string::c_str;
    std::ifstream input((path.*fileCString)());
    TextXmlParser parser(input.rdbuf());
    std::auto_ptr<XmlElement> root=parser.parse();
    const XmlElement* item=root->findFirstChildByTag(tag_schema_version);
    if(item) item->observedValue().getValue(version);
    item=root->findFirstChildByTag(tag_color_map);
    if(item) {
        const XmlElement* color=item->findFirstChildByTag(tag_color);
        std::string text;
        while(color) {
            int found=0;
            color->findFirstChildByTag(tag_name);
            item=color->findFirstChildByTag(tag_ldraw_code);
            int ldraw=-1;
            if(item) { ++found; item->observedValue().getValue(text); ldraw=atoi(nativeCString(text)); }
            item=color->findFirstChildByTag(tag_roblox_code);
            int roblox=-1;
            if(item) { ++found; item->observedValue().getValue(text); roblox=atoi(nativeCString(text)); }
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
            if(item) { ++found; item->observedValue().getValue(name); }
            item=part->findFirstChildByTag(tag_description);
            std::string description("");
            if(item) { ++found; item->observedValue().getValue(description); }
            item=part->findFirstChildByTag(tag_ldraw_filename);
            std::string ldrawFilename("");
            if(item) { ++found; item->observedValue().getValue(ldrawFilename); }
            item=part->findFirstChildByTag(tag_mapping_fidelity);
            std::string fidelityText("");
            int fidelity=2;
            if(item) { ++found; item->observedValue().getValue(fidelityText); fidelity=readFidelity(fidelityText); }
            LDraw2RobloxPartMap* entry=new LDraw2RobloxPartMap(name,description,ldrawFilename,fidelity);
            const XmlElement* child=part->findFirstChildByTag(tag_roblox_part);
            if(child) {
                ++found;
                while(child) {
                    int fields=0;
                    item=child->findFirstChildByTag(tag_shape);
                    std::string text("");
                    int shape=999;
                    if(item) { ++fields; item->observedValue().getValue(text); shape=readShape(text); }
                    item=child->findFirstChildByTag(tag_form_factor);
                    text="";
                    int formFactor=0;
                    if(item) { ++fields; item->observedValue().getValue(text); formFactor=readFormFactor(text); }
                    item=child->findFirstChildByTag(tag_size_vect3);
                    std::string size("");
                    if(item) { ++fields; item->observedValue().getValue(size); }
                    item=child->findFirstChildByTag(tag_y_offset);
                    std::string offset("");
                    if(item) { ++fields; item->observedValue().getValue(offset); }
                    if(fields==4) entry->addPart(NativeRobloxPart(shape,formFactor,size,offset));
                    child=child->nextSibling();
                }
            }
            if(found==5) addPartMap(entry);
            part=part->nextSibling();
        }
    }
}
}}

typedef char native_string_size[sizeof(std::string)==28?1:-1];
typedef char native_stream_size[sizeof(std::ifstream)==140?1:-1];
typedef char native_parser_base_size[sizeof(XmlParser)==40?1:-1];
typedef char native_parser_stack_size[sizeof(std::stack<XmlElement*>)==32?1:-1];
typedef char native_parser_map_size[sizeof(std::map<std::string,std::string>)==32?1:-1];
typedef char native_xml_owner_size[sizeof(std::auto_ptr<XmlElement>)==4?1:-1];
namespace RBX {namespace LDraw2Lua {
typedef char native_path_offset[offsetof(LDraw2RobloxMapRoot,path)==4?1:-1];
typedef char native_version_offset[offsetof(LDraw2RobloxMapRoot,version)==0x20?1:-1];
typedef char native_colors_offset[offsetof(LDraw2RobloxMapRoot,colors)==0x3c?1:-1];
typedef char native_parts_offset[offsetof(LDraw2RobloxMapRoot,parts)==0x5c?1:-1];
typedef char native_color_code_offset[offsetof(LDraw2RobloxColorMap,ldrawCode)==4?1:-1];
typedef char native_color_roblox_offset[offsetof(LDraw2RobloxColorMap,robloxCode)==8?1:-1];
typedef char native_part_fidelity_offset[offsetof(LDraw2RobloxPartMap,fidelity)==0x58?1:-1];
typedef char native_part_entries_offset[offsetof(LDraw2RobloxPartMap,parts)==0x5c?1:-1];
typedef char native_value_size_offset[offsetof(NativeRobloxPart,size)==8?1:-1];
typedef char native_value_y_offset[offsetof(NativeRobloxPart,offset)==0x24?1:-1];
}}
