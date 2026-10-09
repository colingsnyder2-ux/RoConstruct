import sys
sys.path.insert(0, r'C:\Users\colin\RoConstruct')

# Import - note: _INDEX will be whatever it is in the module at import time
from roc.refsource import TREE, CACHE, build_index

print("=== Before build_index ===")
# Access the module's globals directly
import roc.refsource as rs
print("Module _INDEX:", rs._INDEX)
print("Module _INDEX_KEY:", rs._INDEX_KEY)

# Now actually call it
print("\n=== Calling build_index(force=False) ===")
result = build_index(force=False)

print("\n=== After build_index ===")
print("Module _INDEX:", rs._INDEX)
print("Module _INDEX_KEY:", rs._INDEX_KEY)
print("result len classes:", len(result[0]) if result else 0)