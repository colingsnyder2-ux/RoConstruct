import sys
sys.path.insert(0, r'C:\Users\colin\RoConstruct')
from roc.refsource import build_index
index = build_index(force=True)
print('Index built successfully')
print('Classes:', len(index[0]))
print('Funcs:', len(index[1]))