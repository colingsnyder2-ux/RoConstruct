"""Fail-closed readiness summary for native integration automation.

The current integration verifier does not emit independently validated receipts
for every provider, ABI, no-loss, P5/P6, and runtime gate. This module reports
that gap; it never starts integration or selects an executable.
"""

from collections.abc import Mapping


REQUIRED_GATES = (
    "provider_selection",
    "abi",
    "link",
    "no_loss",
    "p5",
    "p6",
    "runtime",
)

_CURRENT_GATE_LABEL = "M2/M4a/M5, size, base, linked ownership passed"


def assess_gate_result(result):
    """Report blockers without treating caller-supplied flags as proof.

    `result` is the summary shape returned by the current promotion verifier.
    Its accepted/gates fields describe local candidate checks, not complete
    independently validated receipts for the required activation gates.
    """
    known_candidate_checks = bool(
        isinstance(result, Mapping)
        and result.get("accepted") is True
        and result.get("gates") == _CURRENT_GATE_LABEL
    )
    return {
        "outcome": "pending_external_evidence",
        "known_candidate_checks": known_candidate_checks,
        "missing_gates": list(REQUIRED_GATES),
        "integration_started": False,
        "activation_allowed": False,
        "reason": "Current verifier has no machine-validated receipt schema for all required gates.",
    }
