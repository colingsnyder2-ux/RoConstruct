// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_workspace_write_538b899f2fc1c362.cpp

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
  boost::shared_ptr<boost::recursive_mutex> mutex;
  boost::recursive_mutex::scoped_lock* lock;
 public:
  Lock(boost::shared_ptr<const DataModel>);
  ~Lock();
 };
};
}
class SerializerV2 {public: static XmlElement* newRootElement();};
struct VCWorkspaceNativeView {
 char prefix[0x24];
 boost::shared_ptr<RBX::DataModel> dataModel;
 boost::shared_ptr<RBX::DataModel> getDataModel();
 std::auto_ptr<XmlElement> writeXmlModel();
};
std::auto_ptr<XmlElement> VCWorkspaceNativeView::writeXmlModel() {
 std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
 RBX::DataModel::Lock lock(dataModel);
 getDataModel()->writeChildren(root.get());
 return root;
}
