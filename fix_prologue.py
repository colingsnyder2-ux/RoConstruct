import re

with open(r'C:\Users\colin\RoConstruct\roc\draft.py', 'r', encoding='utf-8') as f:
    content = f.read()

old = """    # Detect MSVC exception-handling: functions with standard prologue + calls may need destructor care
    has_standard_prologue = any(
        re.search(r"^\s*push\s+ebp", line) and re.search(r"^\s*mov\s+ebp\s*,?\s*esp", line)
        for line in asm
    )"""

new = """    # Detect MSVC exception-handling: functions with standard prologue + calls may need destructor care
    has_push_ebp = any(re.search(r"^\s*push\s+ebp", line) for line in asm)
    has_mov_ebp_esp = any(re.search(r"^\s*mov\s+ebp\s*,?\s*esp", line) for line in asm)
    has_standard_prologue = has_push_ebp and has_mov_esp"""

if old in content:
    content = content.replace(old, new, 1)
    with open(r'C:\Users\colin\RoConstruct\roc\draft.py', 'w', encoding='utf-8') as f:
        f.write(content)
    print('SUCCESS: Fixed has_standard_prologue detection')
else:
    print('ERROR: Could not find target string')