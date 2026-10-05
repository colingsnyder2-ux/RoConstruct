#include <stdio.h>

int add_score(int score, int points);
int clamp_health(int health);
int player_is_alive(int health);

int main(void) {
    printf("tiny sandbox: score=%d health=%d alive=%d\n",
           add_score(10, 5), clamp_health(125), player_is_alive(100));
    return 0;
}
