#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

struct Point {
    int x;
    int y;

    Point(int xx, int yy) : x(xx), y(yy) {}

    bool operator== (const Point& other) { return (x == other.x && y == other.y); }

    int getValue() { return (std::abs(x) + std::abs(y)); }
};

bool operator< (const Point& a, const Point& b) {
    return (std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y));
}

std::vector<Point> getKeys(std::map<Point, int> map) {
    std::vector<Point> vec;
    for(std::map<Point, int>::iterator it = map.begin(); it != map.end(); it++) {
        vec.push_back(it->first);
    }
    
    return vec;
}

std::vector<Point> getIntersections(std::map<Point, int> firstPath, std::map<Point, int> secondPath) {
    std::vector<Point> firstKeys = getKeys(firstPath);
    std::vector<Point> secondKeys = getKeys(secondPath);
    std::vector<Point> vec;

    std::sort(firstKeys.begin(), firstKeys.end());
    std::sort(secondKeys.begin(), secondKeys.end());

    std::set_intersection(firstKeys.begin(), firstKeys.end(), secondKeys.begin(), secondKeys.end(), back_inserter(vec));

    return vec;
}

std::map<Point, int> getPath(std::string str) {
    std::map<Point, int> map;
    int x = 0;
    int y = 0;
    int pathLength = 0;
    std::string token;
    std::istringstream iss(str);
    while(std::getline(iss, token, ',')) {
        char dir = token[0];
        int dist = std::stoi(token.substr(1, token.size() -1));
        for(int i = 0; i < dist; i++) {
            switch(dir) {
                case 'U':
                    map[Point(x, ++y)] = ++pathLength;
                    break;
                case 'D':
                    map[Point(x, --y)] = ++pathLength;
                    break;
                case 'L':
                    map[Point(--x, y)] = ++pathLength;
                    break;
                case 'R':
                    map[Point(++x, y)] = ++pathLength;
                    break;
                default:
                    throw std::invalid_argument("Invalid direction");
            }
        }
    }

    return map;
}

Point min(std::vector<Point> vec) {
    Point p(9999999, 9999999);

    for(int i = 0; i < vec.size(); i++) {
        if(!(vec[i].x == 0 && vec[i].y == 0) && vec[i].getValue() <= p.getValue()) {
            p = vec[i];
        }
    }

    return p;
}

int main(void) {

    std::ifstream ifs("input.txt");
    std::map<Point, int> firstPath;
    std::map<Point, int> secondPath;

    if(ifs.is_open()) {
        for(int i = 1; i >= 0; i--) {
            std::string line;
            std::getline(ifs, line);
            if(i) {
                firstPath = getPath(line);
            } else {
                secondPath = getPath(line);
            }
        }

        ifs.close();
    } else {
        return -1;
    }

    std::vector<Point> intersections = getIntersections(firstPath, secondPath);

    Point a = min(intersections);

    std::cout << a.x << " " << a.y << std::endl;

    std::cout << (std::abs(a.x) + std::abs(a.y)) << std::endl;

    return 0;
}