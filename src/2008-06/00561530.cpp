// from server: 100% by king_originala_sol_resume_medium
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_resume_medium_b137cae6347a62cf.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlSerializer.h", "roc_xml_native_legacy_parser_headerb864cade0382cfdc.cpp")
#include "v8xml/SerializerV2.h"
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <istream>
typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;
typedef boost::shared_ptr<Instances> Shared;
typedef char NativeInstancesSize[sizeof(Instances)==24?1:-1];
typedef char NativeParserSize[sizeof(TextXmlParser)==72?1:-1];
typedef boost::function<void(int,Shared)> Callback;
typedef char NativeCallbackSize[sizeof(Callback)==32?1:-1];
void __cdecl parseContent(int mode,std::istream* stream,Callback callback)
{
    Shared value(new Instances);
    if(mode==1) {
        TextXmlParser reader(stream->rdbuf());
        boost::scoped_ptr<XmlElement> object(reader.parse());
        SerializerV2().loadInstances(object.get(),*value);
    }
    callback(mode,value);
}
