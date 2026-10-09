import sys
sys.path.insert(0, r'C:\Users\colin\RoConstruct')

# Import and manually trace
from roc.refsource import TREE, CACHE, build_index, _INDEX, _INDEX_KEY

print("=== Before build_index ===")
print("_INDEX:", _INDEX)
print("_INDEX_KEY:", _INDEX_KEY)

key = (str(TREE), str(CACHE))
print("key:", key)

# Simulate what build_index does
print("\nCache exists:", CACHE.exists())

if CACHE.exists():
    try:
        data = json.loads(CACHE.read_text())
        cache_files = data.get("files")
        print("cache.files:", cache_files)
        print("TREE str:", str(TREE))
        print("match:", cache_files == str(TREE))
    except Exception as e:
        print("Error reading cache:", e)

# Now actually call it
print("\n=== Calling build_index(force=False) ===")
result = build_index(force=False)

print("\n=== After build_index ===")
print("_INDEX:", _INDEX)
print("_INDEX_KEY:", _INDEX_KEY)
print("result len classes:", len(result[0]) if result else 0)