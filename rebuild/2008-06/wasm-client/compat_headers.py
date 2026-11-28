from pathlib import Path
root=Path(__import__('sys').argv[1])
def change(path,changes):
 p=root/path; s=p.read_text()
 for old,new in changes:
  if old not in s: raise RuntimeError(f'missing {path}: {old[:70]}')
  s=s.replace(old,new)
 p.write_text(s)
change('util/Utilities.h', [('template<typename Class>\n\t\tfriend class Parent;', 'template<typename ParentClass>\n\t\tfriend class Parent;')])
change('util/Association.h', [('std::vector<Item*>::iterator', 'typename std::vector<Item*>::iterator')])
change('reflection/member.h', [('CollectionType::iterator bound', 'typename CollectionType::iterator bound'),('std::vector<MemberDescriptorContainer*>::iterator iter','typename std::vector<MemberDescriptorContainer*>::iterator iter'),('for (CollectionType::const_iterator iter','for (typename CollectionType::const_iterator iter')])
change('reflection/type.h', [('const type_info&','const std::type_info&')])
file=root/'util/Events.h'; s=file.read_text().replace('std::vector<Listener<Class, Event>*>::iterator iter','typename std::vector<Listener<Class, Event>*>::iterator iter')
start=s.index('\t\tvoid raise(Event event, Listener<Class, Event>* listener) const\n\t\t{'); end=s.index('\n\t\tvoid raise(Event event) const throw()',start)
body=s[start:end]; s=s[:start]+'\t\tvoid raise(Event event, Listener<Class, Event>* listener) const;\n'+s[end:]; file.write_text(s)
body=body.replace('\t\tvoid raise(Event event, Listener<Class, Event>* listener) const','\ttemplate<typename Class, typename Event>\n\tvoid Notifier<Class, Event>::raise(Event event, Listener<Class, Event>* listener) const')
p=root/'util/standardout.h'; s=p.read_text().replace('__time64_t time;', 'time_t time;').replace('_time64(&time);', '::time(&time);'); s += '\nnamespace RBX {\n'+body+'\n}\n';p.write_text(s)
p=root/'reflection/signal.h';s=p.read_text().replace('\t\tclass GenericSlotWrapper\n','\t\ttemplate<typename T> class TGenericSlotWrapper;\n\t\tclass GenericSlotWrapper\n',1)
start=s.index('\t\t\ttemplate<typename T>\n\t\t\tboost::signals::connection connectGeneric(T slot,'); end=s.index('\n\t\t};',start)
body=s[start:end];s=s[:start]+'\t\t\ttemplate<typename T>\n\t\t\tboost::signals::connection connectGeneric(T slot, boost::signals::connect_position pos);\n'+s[end:]
body=body.replace('boost::signals::connection connectGeneric(', 'boost::signals::connection SignalInstance::connectGeneric(')
needle='\n\t\tclass Signal\n\t\t{';pos=s.index(needle);s=s[:pos]+'\n'+body+'\n'+s[pos:]
s=s.replace(': TSignalDesc(classDescriptor, name)',': TSignalDesc<CallbackSignature>(classDescriptor, name)').replace('TSignalInstance* instance = findSig(source);','typename TSignalDesc<CallbackSignature>::TSignalInstance* instance = this->findSig(source);')
s=s.replace(': SignalDescImpl(Class::classDescriptor(), name)',': SignalDescImpl<boost::function_traits<CallbackSignature>::arity, CallbackSignature>(Class::classDescriptor(), name)').replace('signature.arguments.push_back','this->signature.arguments.push_back')
p.write_text(s)
change('reflection/signal.h', [('typename const boost::function_traits', 'const typename boost::function_traits')])
change('reflection/enumconverter.h', [('const type_info&', 'const std::type_info&'),
    ('std::map<const Name*, Enum>::const_iterator', 'typename std::map<const Name*, Enum>::const_iterator')])
change('reflection/reflection.h', [
    ('const type_info&', 'const std::type_info&'),
    (': Described(arg0)   // INFERRED', ': Reflection::Described<Class, ClassName, FactoryProduct<Class, DerivedClass, ClassName> >(arg0)   // INFERRED'),
    (': Described()', ': Reflection::Described<Class, ClassName, NonFactoryProduct<DerivedClass, ClassName> >()'),
    (': Described(arg0)\n', ': Reflection::Described<Class, ClassName, NonFactoryProduct<DerivedClass, ClassName> >(arg0)\n'),
    ('class BoundProp : public TypedPropertyDescriptor<PropType>\n\t\t{', 'class BoundProp : public TypedPropertyDescriptor<PropType>\n\t\t{\n            typedef typename TypedPropertyDescriptor<PropType>::GetSet GetSet;'),
    ('class PropDescriptor : public TypedPropertyDescriptor<ReturnType>\n\t\t{', 'class PropDescriptor : public TypedPropertyDescriptor<ReturnType>\n\t\t{\n            typedef typename TypedPropertyDescriptor<ReturnType>::GetSet GetSet;'),
    ('Functionality flags', 'PropertyDescriptor::Functionality flags'),
    (': TypedPropertyDescriptor(Class::classDescriptor(), name, category, std::auto_ptr<GetSet>(), flags)', ': TypedPropertyDescriptor<PropType>(Class::classDescriptor(), name, category, std::auto_ptr<GetSet>(), flags)'),
    (': TypedPropertyDescriptor(Class::classDescriptor(), name, category, getset(get, set), flags)', ': TypedPropertyDescriptor<ReturnType>(Class::classDescriptor(), name, category, getset(get, set), flags)'),
    ('\n\t\t\t\tgetset.reset(', '\n\t\t\t\tthis->getset.reset('),
    ('typename GetFunction get', 'GetFunction get'), ('typename SetFunction set', 'SetFunction set'),
    ('::getset<GetFunction, SetFunction>', '::template getset<GetFunction, SetFunction>')])
change('reflection/reflection.h', [
    ('virtual size_t getIndexValue(', 'virtual unsigned getIndexValue('),
    ('typename result_type', 'result_type'), ('typename FunctionSig', 'FunctionSig'),
    ('typename Arg1', 'Arg1'), ('typename Arg2', 'Arg2'),
    ('typename Arg3', 'Arg3'), ('typename Arg4', 'Arg4'),
    ('Arguments& arguments', 'FunctionDescriptor::Arguments& arguments'),
    ('signature.resultType', 'this->signature.resultType'),
    ('signature.addArgument', 'this->signature.addArgument'),
    (': FuncDesc(name, security)', ': FuncDesc<Class>(name, security)'),
    ('Security security', 'FunctionDescriptor::Security security')])
change('reflection/member.h', [('Iterator::Iterator(', 'Iterator('),
                                ('ConstIterator::ConstIterator(', 'ConstIterator(')])
change('util/Object.h', [('\tprivate:\n\t\tstatic void* operator new(size_t size)',
                          '\tprotected:\n\t\tstatic void* operator new(size_t size)')])

