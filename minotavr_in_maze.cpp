#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <string>

enum DIRECTION {
    LEFT,
    RIGHT,
    UP,
    BOTTOM
};

void DetectDirection(int* direction, int x, int y, int x1, int y1) {
    if (x < x1) {
        *direction = RIGHT;
    } else if (x > x1) {
        *direction = LEFT;
    } else if (y < y1) {
        *direction = BOTTOM;
    } else {
        *direction = UP;
    }
}

std::pair<int, int> FireNextCell(int K, int direction, std::set<std::pair<int, int>> visited, int* number_of_turns) {
    std::cout << 3 << '\n';

    std::vector<std::vector<char>> maze_piece(2 * K + 1, std::vector<char>(2 * K + 1));
    for(size_t i = 0; i < 2 * K + 1; ++i) {
        std::string curr_line;
        std::cin >> curr_line;
        for(size_t j = 0; j < 2 * K + 1; ++j) {
            maze_piece[i][j] = curr_line[j];
        }
    }


    int current_position_x = K;
    int current_position_y = K;

    // if (maze_piece[current_position_x + 1][current_position_y] == '_' && visited.find({current_position_x + 1, current_position_y}) == visited.end()) {            // если клетка справа свободна и не посещена
    //     number_of_turns += CalcTurns(direction, RIGHT);
    //     return {current_position_x + 1, current_position_y};
    // }
    // if (maze_piece[current_position_x][current_position_y + 1] == '_' && visited.find({current_position_x, current_position_y + 1}) == visited.end()) {            // если клетка справа свободна и не посещена
    //     number_of_turns += CalcTurns(direction, UP);
    //     return {current_position_x, current_position_y + 1};
    // }
    // if (maze_piece[current_position_x - 1][current_position_y] == '_' && visited.find({current_position_x - 1, current_position_y}) == visited.end()) {            // если клетка справа свободна и не посещена
    //     number_of_turns += CalcTurns(direction, LEFT);
    //     return {current_position_x - 1, current_position_y};
    // }
    // if (maze_piece[current_position_x][current_position_y - 1] == '_' && visited.find({current_position_x, current_position_y - 1}) == visited.end()) {            // если клетка справа свободна и не посещена
    //     number_of_turns += CalcTurns(direction, BOTTOM);
    //     return {current_position_x, current_position_y - 1};
    // }
    return {current_position_x, current_position_y};

}

int FindTotalTime(int x, int y, int x1, int y1, int A, int B, int C, int K) {
    int time_spend = 0;
    int direction = -1;

    DetectDirection(&direction, x, y, x1, y1);

    std::stack<std::pair<int, int> > positions;             // хранит клетки пути из начальной точки в текущую чтобы можно было вернуться и пройти по еще не пройденным клеткам
    positions.push({x, y});

    std::set<std::pair<int, int> > visited;                 // хранит посещенные клетки
    visited.insert({x, y});

    while(!positions.empty()) {
        std::pair<int, int> current_position = positions.top();

        // развести костер и осмотреться
        time_spend += C;

        int number_of_turns = 0;

        //std::pair<int, int> next_cell = FireNextCell(K, direction, visited, *number_of_turns);

        if (visited.find(next_cell) == visited.end()) {
            positions.push(next_cell);
            
            // если данная клетка лабиринта не была посещена, то сделать поворот
            time_spend += number_of_turns * B;
            //Turn(number_of_turns);

            // посетить данную клетку
            time_spend += A;
            //Go();
            continue;
        } 
        positions.pop();
    }

    return time_spend;


}

int main() {
    int x, y, x1, y1, A, B, C, K;
    std::cin >> x >> y >> x1 >> y1 >> A >> B >> C >> K;

    std::cout << "4 " << FindTotalTime(x, y, x1, y1, A, B, C, K);

    return 0;
    
}