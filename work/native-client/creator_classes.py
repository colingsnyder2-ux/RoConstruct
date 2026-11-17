"""Resolve FactoryProduct Creator::create rows (registry gives one shared wrong name) to their class: the code
that installs the Creator vtable whose slot 0 is the function names FactoryProduct<C,D,N>.  -> creator-classes.json"""
import json,sys,struct,bisect,re,collections
sys.argv=['x']; sys.path.insert(0,'.')
import native_llm as m
from roc import match
reg=m.load_registry(); cl=json.load(open('remaining-classified.json'))
base,image=match._image('2008-06'); relocs=sorted(match._base_relocs('2008-06'))
fns=match._functions('2008-06'); starts=sorted(int(a,16) for a in fns)
def dw(va): o=va-base; return struct.unpack_from('<I',image,o)[0]
val=collections.defaultdict(list)
for r in relocs:
    try: val[dw(r)].append(r)
    except struct.error: pass
def owner(va):
    i=bisect.bisect_right(starts,va)-1; return '%08x'%starts[i] if i>=0 else None
todo=[a for a in cl if 'Creator::create' in ((reg.get(a) or {}).get('signature') or '')]
out={}; stat=collections.Counter()
for a in todo:
    slots=val.get(int(a,16),[])
    names=set()
    for s in slots:
        for ref in val.get(s,[]):           # code storing the vtable pointer (slot 0 = vtable start)
            f=owner(ref); n=(reg.get(f) or {}).get('signature') or ''
            if 'FactoryProduct<' in n: names.add(n)
    fp={re.search(r'FactoryProduct<(.*?)>::',n).group(1) for n in names if re.search(r'FactoryProduct<(.*?)>::',n)}
    stat[len(fp)]+=1
    if len(fp)==1: out[a]=fp.pop()
print(stat); print(list(out.items())[:3])
json.dump(out,open('creator-classes.json','w'),indent=1)
