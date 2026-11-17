"""Write a FactoryProduct creator-initializer unit: python write_unit.py OUT.cpp main|solo:N [mfc]"""
import json, sys
plan = json.load(open('creator-partition/plan.json'))
out_path, which = sys.argv[1], sys.argv[2]
rows = plan['main'] if which == 'main' else [plan['solo'][int(k)] for k in which.split(':')[1].split(',')]
incs, insts = [], []
for i, inst in rows:
    incs += [x for x in i if x not in incs]
    insts.append(inst)
mfc = len(sys.argv) > 3
out = ['// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL',
       '// 2008-06 native FactoryProduct<C, D, N>::creator static members: their dynamic initializers (??__E?creator@...)',
       '// and atexit destructors (??__F?creator@...) in 007ee760..007fe8b0 (inactive). The donor 2007 util/Object.h defines',
       '// Creator()/~Creator() and `creator` in the header; the native util/Object.h only declares them, so this unit is',
       '// their definition (the pattern of AppUnit400_2008Creators.cpp for Creator::create()). Creator() ends with',
       '// isConstructed = 666: iOS 2013 Object.h asserts Creator::wasConstructed() (isConstructed == 0x29a) and each 2008',
       '// initializer stores 0x29a to its own instantiation. Byte-proved per class by native_creator_gate.py.']
out += (['#include <afxwin.h>'] if mfc else []) + ['#include "%s"' % i for i in incs]
out += ['', 'namespace RBX', '{',
        '\ttemplate<typename Class, typename DerivedClass, const char* ClassName>',
        '\tconst Name& FactoryProduct<Class, DerivedClass, ClassName>::className()', '\t{',
        '\t\treturn Name::declare<ClassName>();', '\t}', '',
        '\ttemplate<typename Class, typename DerivedClass, const char* ClassName>',
        '\tFactoryProduct<Class, DerivedClass, ClassName>::Creator::Creator()', '\t{',
        '\t\tgetCreators()[&className()] = this;', '\t\tisConstructed = 666;', '\t}', '',
        '\ttemplate<typename Class, typename DerivedClass, const char* ClassName>',
        '\tFactoryProduct<Class, DerivedClass, ClassName>::Creator::~Creator()', '\t{',
        '\t\tgetCreators().erase(&className());', '\t}', '',
        '\ttemplate<typename Class, typename DerivedClass, const char* ClassName>',
        '\tconst typename FactoryProduct<Class, DerivedClass, ClassName>::Creator FactoryProduct<Class, DerivedClass, ClassName>::creator;',
        '}', '', "// One explicit instantiation per class (getCreator() is public; creator is private): it instantiates that class's creator object, initializer and atexit destructor."]
out += ['template const RBX::ICreator& %s::getCreator();' % i for i in insts]
open(out_path, 'w', encoding='utf-8').write('\n'.join(out) + '\n')
print(out_path, len(incs), 'includes', len(insts), 'instances')
