namespace RBX {
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = 0;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        Class* service = static_cast<Class*>(serviceArray[index].get());
        if (service) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
    if (!item) return 0;
    Class* service = static_cast<Class*>(item.get());
    serviceArray[index] = item;
    return service;
}
template PhysicsService* ServiceProvider::find<PhysicsService>() const;
}
