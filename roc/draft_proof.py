"""Strict gate for coordinator-generated native draft proof receipts."""

import math
import re


BASE_CHECKS = (
    "compile", "code", "relocations", "data", "strings", "abi",
    "dependencies", "preservation", "batch_symbols", "regressions",
)
ACTIVATION_CHECKS = ("provider_selection", "link", "p5", "p6", "runtime")
SOURCE_CHECKS = ('compile', 'existing_code_preserved', 'existing_data_preserved',
                 'layout_preserved', 'provider_review', 'new_method_bodies', 'source_review', 'no_activation')


def _valid_values(value):
    if value is None or type(value) in (str, bool, int):
        return True
    if isinstance(value, float):
        return math.isfinite(value)
    if isinstance(value, dict):
        return all(isinstance(key, str) and _valid_values(item) for key, item in value.items())
    if isinstance(value, list):
        return all(_valid_values(item) for item in value)
    return False


def _method_set(value, field, blockers):
    if not isinstance(value, list) or any(not isinstance(item, str) or not item for item in value):
        blockers.append(f"{field} must be a list of nonempty stable method IDs")
        return set()
    if len(set(value)) != len(value):
        blockers.append(f"{field} contains duplicate method IDs")
    return set(value)


def validate_receipt(receipt, expected):
    """Return blockers; empty list means this receipt satisfies the requested gate."""
    blockers = []
    if not isinstance(expected, dict):
        return ["expected identity must be a mapping"]
    required_identity = ("candidate_sha256", "input_key", "client", "verifier_sha256")
    missing = [key for key in required_identity if key not in expected]
    if missing:
        return ["expected identity missing: " + ", ".join(missing)]
    if not isinstance(receipt, dict):
        return ["receipt must be a mapping"]
    if not _valid_values(receipt):
        blockers.append("receipt contains non-JSON or non-finite data")
    for key, wanted in expected.items():
        if key == "activate":
            if type(wanted) is not bool:
                blockers.append("expected activate must be a boolean")
            continue
        if not isinstance(wanted, str) or not wanted:
            blockers.append(f"expected {key} must be a nonempty string")
        elif receipt.get(key) != wanted:
            blockers.append(f"{key} does not match expected identity")
        if key in ("candidate_sha256", "input_key", "verifier_sha256") and (not isinstance(wanted, str) or not re.fullmatch(r"[0-9a-f]{64}", wanted)):
            blockers.append(f"expected {key} must be 64 lowercase hex characters")
    if type(receipt.get("schema")) is not int or receipt["schema"] != 1:
        blockers.append("schema must be 1")
    if receipt.get("kind") != "independent-draft-proof":
        blockers.append("kind must be independent-draft-proof")

    before = _method_set(receipt.get("before_methods"), "before_methods", blockers)
    after = _method_set(receipt.get("after_methods"), "after_methods", blockers)
    gains = after - before
    losses = before - after
    if not gains:
        blockers.append("no newly verified methods")
    if losses:
        blockers.append("verified method losses: " + ", ".join(sorted(losses)))

    checks = receipt.get("checks")
    required = BASE_CHECKS + (ACTIVATION_CHECKS if expected.get("activate") is True else ())
    if not isinstance(checks, dict):
        blockers.append("checks must be a mapping")
    else:
        for name in required:
            if type(checks.get(name)) is not bool or checks[name] is not True:
                blockers.append(f"{name} check must be true boolean")
    return blockers


def rank_receipts(receipts, expected):
    """Deterministic order: eligible, more gains, broader true-check coverage, identity."""
    def key(receipt):
        blockers = validate_receipt(receipt, expected)
        before_raw = receipt.get("before_methods", []) if isinstance(receipt, dict) else []
        after_raw = receipt.get("after_methods", []) if isinstance(receipt, dict) else []
        before = {item for item in before_raw if isinstance(item, str)} if isinstance(before_raw, list) else set()
        after = {item for item in after_raw if isinstance(item, str)} if isinstance(after_raw, list) else set()
        checks = receipt.get("checks", {}) if isinstance(receipt, dict) and isinstance(receipt.get("checks"), dict) else {}
        coverage = sum(value is True for value in checks.values())
        identity = str(receipt.get("candidate_sha256", "")) if isinstance(receipt, dict) else ""
        return (bool(blockers), -(len(after - before)), -coverage, identity)

    return sorted(receipts, key=key)


def validate_source_improvement(receipt, expected):
    """Reviewed inactive improvements need scoped evidence, not complete class/runtime proof."""
    if not isinstance(receipt, dict) or not isinstance(expected, dict):
        return ['Source receipt and expected identity must be mappings']
    blockers = []
    if not _valid_values(receipt):
        blockers.append('Source receipt contains invalid JSON values')
    for name in ('candidate_sha256', 'input_key', 'client', 'verifier_sha256'):
        wanted = expected.get(name)
        if not isinstance(wanted, str) or not wanted or receipt.get(name) != wanted:
            blockers.append('Source identity mismatch: ' + name)
        if name != 'client' and (not isinstance(wanted, str) or not re.fullmatch('[0-9a-f]{64}', wanted)):
            blockers.append('Source identity must be SHA256: ' + name)
    for name, value in expected.items():
        if name != 'activate' and receipt.get(name) != value:
            blockers.append('Source identity mismatch: ' + name)
    if (expected.get('activate', False) is not False or receipt.get('inactive') is not True
            or receipt.get('activate', False) is not False):
        blockers.append('Reviewed source improvements cannot authorize executable activation')
    if type(receipt.get('schema')) is not int or receipt['schema'] != 1 or receipt.get('kind') != 'reviewed-source-improvement':
        blockers.append('Invalid reviewed source improvement schema/kind')
    before = _method_set(receipt.get('before_methods'), 'before_methods', blockers)
    after = _method_set(receipt.get('after_methods'), 'after_methods', blockers)
    if not after - before:
        blockers.append('No new source method bodies')
    if before - after:
        blockers.append('Existing source method losses')
    checks = receipt.get('checks', {})
    for name in SOURCE_CHECKS:
        if not isinstance(checks, dict) or checks.get(name) is not True:
            blockers.append('Source check must be true boolean: ' + name)
    for name in ('reviewer', 'rationale', 'scope'):
        if not isinstance(receipt.get(name), str) or not receipt[name].strip():
            blockers.append('Source review missing: ' + name)
    for name in ('inferences', 'open_questions'):
        if not isinstance(receipt.get(name), list) or any(not isinstance(row, str) for row in receipt[name]):
            blockers.append('Source review notes must be string lists: ' + name)
    return blockers


def validate_adapter(adapter, receipt, expected):
    if adapter in ('original-msvc-method-v1', 'original-msvc-family-v1'):
        return validate_receipt(receipt, expected)
    if adapter == 'reviewed-inactive-methods-v1':
        return validate_source_improvement(receipt, expected)
    return ['Unregistered proof adapter: ' + adapter]
