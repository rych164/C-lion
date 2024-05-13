#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("input2.txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    std::string line;
    int sum_of_ids = 0, sum_of_all_powers = 0;

    while (std::getline(file, line)) {
        int game_id;
        int max_red = 0, max_green = 0, max_blue = 0;
        bool possible = true;

        std::istringstream line_stream(line);

        // Extract game id
        std::string header;
        if (!(line_stream >> header >> game_id)) continue;

        std::getline(line_stream, line, ':'); // Skip to after the colon

        std::vector<std::string> parts;
        std::string token;
        while (std::getline(line_stream, token, ';')) {
            parts.push_back(token);
        }

        for (const auto& part : parts) {
            std::istringstream color_stream(part);
            int count;
            std::string color;

            color_stream >> count >> color;
            if (color.find("red") != std::string::npos) {
                max_red = std::max(max_red, count);
            } else if (color.find("green") != std::string::npos) {
                max_green = std::max(max_green, count);
            } else if (color.find("blue") != std::string::npos) {
                max_blue = std::max(max_blue, count);
            }
        }

        // Check game possibility with given constraints
        if (!(max_red <= 12 && max_green <= 13 && max_blue <= 14)) {
            possible = false;
        }

        int power = max_red * max_green * max_blue;
        sum_of_all_powers += power;

        if (possible) {
            std::cout << "Game " << game_id << " is possible. Min needs: R=" << max_red
                      << ", G=" << max_green << ", B=" << max_blue << ", Power=" << power << "\n";
            sum_of_ids += game_id;
        } else {
            std::cout << "Game " << game_id << " is not possible. Would need min: R=" << max_red
                      << ", G=" << max_green << ", B=" << max_blue << ", Power=" << power << "\n";
        }
    }

    file.close();

    std::cout << "Sum of IDs of possible games: " << sum_of_ids << std::endl;
    std::cout << "Sum of power of cube sets for all games: " << sum_of_all_powers << std::endl;

    return 0;
}
