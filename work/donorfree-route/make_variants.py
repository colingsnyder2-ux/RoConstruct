import json
from pathlib import Path
head = Path('rebuild/2008-06/native-classes/TypedPropertyContentIdWritersB2008.cpp').read_text().split('namespace RBX')[0]
bodies = {
    'A': 'ContentId copy(getValue(instance));\n\telement->setValue(copy);',
    'B': 'element->setValue(ContentId(getValue(instance)));',
    'C': 'ContentId v = getValue(instance);\n\telement->setValue(ContentId(v));',
    'D': 'const ContentId& v = getValue(instance);\n\telement->setValue(ContentId(v));',
}
for k, b in bodies.items():
    text = head + 'namespace RBX {\nnamespace Reflection {\ntemplate<>\nvoid TypedPropertyDescriptor<ContentId>::writeValue(const DescribedBase* instance, XmlElement* element) const\n{\n\t' + b + '\n}\n}\n}\n'
    Path('work/donorfree-route/variants/cw_%s.cpp' % k).write_text(text)
jobs = [{'source': '../../work/donorfree-route/variants/cw_%s.cpp' % k} for k in bodies]
Path('work/donorfree-route/cwv.json').write_text(json.dumps({'compiler_build': 21022, 'jobs': jobs}))
print(len(jobs))
