"""Small, measured repair-pattern registry used for deterministic ranking."""
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
REGISTRY = ROOT / "docs" / "repair-patterns.json"


def load():
    try:
        rows = json.loads(REGISTRY.read_text())
    except (OSError, ValueError):
        return []
    return [row for row in rows if isinstance(row, dict) and row.get("name")]


def rank_categories(diagnosis, categories):
    """Return categories in evidence/history order; unknowns keep input order."""
    diagnosis = diagnosis or {}
    labels = set()
    for row in diagnosis.get("classifications", []):
        labels.add(row.get("category"))
    if diagnosis.get("mismatch_class"):
        labels.add(diagnosis["mismatch_class"])
    patterns = load()
    weights = {}
    for row in patterns:
        if labels.intersection(row.get("evidence", [])):
            for category in row.get("categories", []):
                weights[category] = max(weights.get(category, 0),
                                        int(row.get("exact", 0)) * 100 + int(row.get("improved", 0)))
    return sorted(enumerate(categories), key=lambda item: (-weights.get(item[1], 0), item[0]))
