// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-inline-nothrow /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-dialog
#include "CInsertObjectDialog.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/DataModel.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/bind.hpp>

#include <algorithm>

// Recovered 004202b0; pointer recursion and explicit list insertion arguments.
void CInsertObjectDialog::addClasses(const RBX::Reflection::ClassDescriptor* descriptor)
{
    if (descriptor->name != RBX::Name::declare<RBX::sDataModel>()) {
        RBX::Reflection::Metadata::Class* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor, false);
        AuthoringSettings& settings = AuthoringSettings::singleton();
        bool show = metadata && (!metadata->unknown_131 || settings.showDepricatedObjects)
            && (!metadata->unknown_132 || settings.showPreliminaryObjects) && metadata->unknown_130;
        if (show) {
            boost::shared_ptr<RBX::Instance> instance;
            try {
                instance = RBX::AbstractFactoryProduct<RBX::Instance>::create(descriptor->name);
            } catch (std::exception&) {
            }
            if (instance) {
                bool allowed;
                if (parent)
                    allowed = instance->canSetParent(parent.get());
                else
                    allowed = dynamic_cast<RBX::Service*>(instance.get()) != NULL;
                if (allowed) {
                    instances.push_back(instance);
                    int image = metadata->getImageIndex();
                    const char* label = descriptor->name.c_str();
                    int item = list.InsertItem(LVIF_TEXT | LVIF_IMAGE, 0, label, 0, 0, image, 0);
                    list.SetItem(item, 0, LVIF_PARAM, NULL, 0, 0, 0, reinterpret_cast<LPARAM>(instance.get()));
                    if (descriptor->name.name.compare(className) == 0)
                        list.SetItemState(item, LVIS_SELECTED, LVIS_SELECTED);
                }
            }
        }
    }
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&CInsertObjectDialog::addClasses, this, _1));
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::value<CInsertObjectDialog *>;
template class boost::_mfi::mf1<void,CInsertObjectDialog,RBX::Reflection::ClassDescriptor const *>;
template class boost::shared_ptr<RBX::Metadata::Reflection>;
template class std::_Vector_const_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >;
template class std::map<RBX::Name const *,RBX::ICreator const *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::ICreator const *> > >;
