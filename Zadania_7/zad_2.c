#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract and compute the maximum dice of each color from game entries
int main() {
    FILE *file;
    char line[1024];
    int game_id, sum_of_ids = 0, sum_of_all_powers = 0;

    file = fopen("input2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        int red = 0, green = 0, blue = 0;
        int max_red = 0, max_green = 0, max_blue = 0;
        int possible = 1;

        // Extract game id
        sscanf(line, "Game %d:", &game_id);

        // Initialize position to parse each token after ":"
        char *token = strtok(line, ":");
        token = strtok(NULL, "");

        while (token && *token) {
            char *color_token = strtok(token, ";");
            while (color_token) {
                int count;
                char color[7];
                if (sscanf(color_token, "%d %s", &count, color) == 2) {
                    if (strstr(color, "red")) {
                        if (count > max_red) max_red = count;
                    } else if (strstr(color, "green")) {
                        if (count > max_green) max_green = count;
                    } else if (strstr(color, "blue")) {
                        if (count > max_blue) max_blue = count;
                    }
                }
                color_token = strtok(NULL, ";");
            }
            token = strtok(NULL, "");
        }

        // Check game possibility with given constraints
        if (max_red <= 12 && max_green <= 13 && max_blue <= 14) {
            sum_of_ids += game_id;
        } else {
            possible = 0;
        }

        int power = max_red * max_green * max_blue;
        sum_of_all_powers += power;

        if (possible) {
            printf("Game %d is possible. Min needs: R=%d, G=%d, B=%d, Power=%d\n", game_id, max_red, max_green, max_blue, power);
        } else {
            printf("Game %d is not possible. Would need min: R=%d, G=%d, B=%d, Power=%d\n", game_id, max_red, max_green, max_blue, power);
        }
    }

    fclose(file);

    printf("Sum of IDs of possible games: %d\n", sum_of_ids);
    printf("Sum of power of cube sets for all games: %d\n", sum_of_all_powers);

    return 0;
}
