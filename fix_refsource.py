import re

with open(r'C:\Users\colin\RoConstruct\roc\draft.py', 'r', encoding='utf-8') as f:
    content = f.read()

old = """    if ref:
        p += ["", "The same class in Roblox's 2016 source (real names; layout may have changed since):",
              "```cpp", ref, "```"]"""

new = """    if ref:
        # Only include 2016 source hint in legacy mode; in lean mode require strong evidence
        if prompt_style == "lean":
            # Check if facts provide strong evidence (byte-identical or shape-identical)
            facts = facts or {}
            has_strong = facts.get("byte_identical") or facts.get("shape_identical")
            if not has_strong:
                ref = None  # Skip generic class-name matches
        if ref:
            p += ["", "The same class in Roblox's 2016 source (real names; layout may have changed since):",
                  "```cpp", ref, "```"]"""

if old in content:
    content = content.replace(old, new, 1)
    with open(r'C:\Users\colin\RoConstruct\roc\draft.py', 'w', encoding='utf-8') as f:
        f.write(content)
    print('SUCCESS: Added prompt_style check for 2016 source hint')
else:
    print('ERROR: Could not find target string')
    # Show surrounding context
    idx = content.find('if ref:')
    if idx >= 0:
        print('Found at index', idx)
        print(content[idx-50:idx+150])