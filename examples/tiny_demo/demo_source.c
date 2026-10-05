/* Tiny non-Roblox target. Ground truth for demo verification. */
int add_score(int score, int points) {
    return score + points;
}

int clamp_health(int health) {
    if (health < 0) return 0;
    if (health > 100) return 100;
    return health;
}

int player_is_alive(int health) {
    return health > 0;
}
