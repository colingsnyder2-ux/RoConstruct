import sys
sys.path.insert(0, r"C:\Users\colin\RoConstruct")
from roc import draft, match, clients

# Get function data
row = match._functions("2008-06").get("005d73a0")
if not row:
    print("Function not found")
    sys.exit(1)

# Get assembly
code, relocs, _ = match.target("2008-06", "005d73a0")
asm = match.disasm(code, int("005d73a0", 16))

# Get facts
facts = draft.facts_from_asm(asm)

# Generate prompt with legacy style
prompt = draft.prompt_for(
    client="2008-06",
    addr="005d73a0",
    row=row,
    asm=asm,
    hint=None,
    attempt=None,
    flags=None,
    examples=(),
    source_hints=(),
    facts=facts,
    strategy="direct",
    compact_rules=False,  # Use full RULES for legacy
    binary_only=False,
    minimal_layout=False,
    family_exemplars=False,
    near_repair=False,
    remill_evidence=None,
    prompt_style="legacy"
)

# Check if RULES (not COMPACT_RULES) are used
has_rules = "Rules:" in prompt and "Inline asm is forbidden" in prompt
has_compact = "Generate byte-exact x86 C++ for Microsoft Visual C++" in prompt
print(f"Using full RULES (legacy): {has_rules}")
print(f"Using COMPACT_RULES: {has_compact}")

# Check for ECX receiver note
has_ecx_note = "ECX live on entry means this" in prompt
print(f"ECX receiver note present: {has_ecx_note}")

# Check for near-repair mode (should not be active since score < 90)
has_near_repair = "NEAR-REPAIR MODE" in prompt
print(f"Near-repair mode active: {has_near_repair}")

# Print first 25 lines
lines = prompt.split("\n")
for i, line in enumerate(lines[:25]):
    print(f"{i+1:3d}: {line}")