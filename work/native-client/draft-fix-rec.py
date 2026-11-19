import json,sys,os
addr,file,cls=sys.argv[1:4]
p='work/native-client/draft-fixes.json'
d=json.load(open(p)) if os.path.exists(p) else []
d=[x for x in d if x['addr']!=addr]+[{'addr':addr,'file':file,'class_or_free':cls}]
json.dump(d,open(p,'w'),indent=1)
