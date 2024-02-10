#include<bits/stdc++.h>
using namespace std;

void drawLineLow(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& line) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = 2 * dy - dx;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        line.push_back(std::make_pair(x, y));
        if (D > 0) {
            y += yi;
            D -= 2 * dx;
        }
        D += 2 * dy;
    }
}

void drawLineHigh(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& line) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = 2 * dx - dy;
    int x = x0;

    for (int y = y0; y <= y1; y++) {
        line.push_back(std::make_pair(x, y));
        if (D > 0) {
            x += xi;
            D -= 2 * dy;
        }
        D += 2 * dx;
    }
}

void drawLine(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& line) {
    if (std::abs(y1 - y0) < std::abs(x1 - x0)) {
        if (x0 > x1)
            drawLineLow(x1, y1, x0, y0, line);
        else
            drawLineLow(x0, y0, x1, y1, line);
    } else {
        if (y0 > y1)
            drawLineHigh(x1, y1, x0, y0, line);
        else
            drawLineHigh(x0, y0, x1, y1, line);
    }
}

void printGrid(const std::vector<std::pair<int, int>>& line) {
    int maxX = 0;
    int maxY = 0;
    for (const auto& point : line) {
        maxX = std::max(maxX, point.first);
        maxY = std::max(maxY, point.second);
    }

    std::vector<std::vector<char>> grid(maxY + 1, std::vector<char>(maxX + 1, '.'));

    for (const auto& point : line) {
        grid[point.second][point.first] = '*';
    }

    for (int y = maxY; y >= 0; y--) {
        for (int x = 0; x <= maxX; x++) {
            std::cout << grid[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void drawLineCoordinates(const std::vector<std::pair<int, int>>& line) {
    std::cout << "Coordinates: ";
    for (const auto& point : line) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    std::cout << std::endl;
}

int main() {
    // Case 1: 0 < m < 1
    std::cout << "Case 1: (1,1), (8,4)" << std::endl;
    std::vector<std::pair<int, int>> line1;
    drawLine(1, 1, 8, 4, line1);
    printGrid(line1);
    drawLineCoordinates(line1);

    // Case 2: m > 1
    std::cout << "\nCase 2: (1,1), (4,8)" << std::endl;
    std::vector<std::pair<int, int>> line2;
    drawLine(1, 1, 4, 8, line2);
    printGrid(line2);
    drawLineCoordinates(line2);

    return 0;
}
