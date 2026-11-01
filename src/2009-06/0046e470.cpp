// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_34a939efb8be8c78.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
class XmlElement;
// Consume the native out-of-line auto_ptr cleanup without defining its pointee.
namespace std { template<> auto_ptr<XmlElement>::~auto_ptr(); }
namespace RBX {
class Instance {public: void writeChildren(XmlElement*);};
class DataModel:public Instance {public:
 class Lock {
  void* lock;
 public:
  Lock(boost::shared_ptr<const DataModel>, bool);
  ~Lock();
 };
};
}
class SerializerV2 {public: static XmlElement* newRootElement();};
struct VCWorkspaceNativeView {
 char prefix[0x1c];
 boost::shared_ptr<RBX::DataModel> dataModel;
 boost::shared_ptr<RBX::DataModel> getDataModel();
 std::auto_ptr<XmlElement> writeXmlModel();
};
std::auto_ptr<XmlElement> VCWorkspaceNativeView::writeXmlModel() {
 std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
 {
 RBX::DataModel::Lock lock(dataModel, true);
 getDataModel()->writeChildren(root.get());
 }
 return root;
}

