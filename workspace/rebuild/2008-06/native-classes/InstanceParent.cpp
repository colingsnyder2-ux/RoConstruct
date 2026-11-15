// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/InstanceEvents.h"
#include <G3D/format.h>
#include <stdexcept>
#include <algorithm>
namespace RBX {
__declspec(noinline) bool Instance::contains(const Instance* child) const { while (child) { if (child == this) return true; child = child->getParent(); } return false; }
void Instance::setParent(Instance*newParent){
 Instance*previousParent=parent;
 if(newParent==previousParent)return;
 if(this==newParent){std::string message=G3D::format("Attempt to set %s as its own parent",getFullName().c_str());throw std::runtime_error(message);}
 if(isAncestorOf(newParent)){std::string message=G3D::format("Attempt to set parent of %s to %s results in circular reference",getFullName().c_str(),newParent->getFullName().c_str());throw std::runtime_error(message);}
 boost::shared_ptr<Instance>oldParent=shared_from(previousParent);
 boost::shared_ptr<Instance>self=shared_from_this();
 if(oldParent){
  if(!oldParent->contains(newParent))signalDescendentRemoving(self,oldParent.get(),newParent);
  oldParent->onChildRemoving(this);
  boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >&c=oldParent->children.write();
  c->erase(std::find(c->begin(),c->end(),self));
  if(c->size()==0)oldParent->children.reset();
  parent=0;
  event_childRemoved.fire(oldParent.get(),self);
  oldParent->Notifier<Instance,ChildRemoved>::raise(ChildRemoved(this));
  oldParent->onChildRemoved(this);
  if(oldParent->numChildren()==0)oldParent->onLastChildRemoved();
 }
 if(newParent)newParent->children.write()->push_back(self);
 parent=newParent;
 if(newParent){
  newParent->onChildAdded(this);
  if(!newParent->contains(oldParent.get()))signalDescendentAdded(this,newParent,oldParent.get());
  newParent->Notifier<Instance,ChildAdded>::raise(ChildAdded(this));
  event_childAdded.fire(newParent,self);
 }
 onAncestorChanged(AncestorChanged(this,oldParent.get(),newParent));raisePropertyChanged(propParent);
}
}
