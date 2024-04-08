#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
public:
    Game() {
        initWorld();
    }

    void start() {
        while (true) {
            cout << "You are in " << locations[currentLocation].description << "\n";
            if (locations[currentLocation].items.size() > 0) {
                cout << "You see ";
                for (auto item : locations[currentLocation].items) {
                    cout << item << " ";
                }
                cout << "\n";
            }
            cout << "Where do you want to go? ";
            string direction;
            cin >> direction;
            if (direction == "quit") {
                break;
            }
            move(direction);
        }
    }

private:
    struct Location {
        string description;
        map<string, string> exits;
        vector<string> items;
    };

    map<string, Location> locations;
    string currentLocation = "town";

    void initWorld() {
        locations["town"] = {"a small town", {{"north", "forest"}, {"east", "river"}}, {"sword", "shield"}};
        locations["forest"] = {"a spooky forest", {{"south", "town"}}, {"magic potion"}};
        locations["river"] = {"a fast flowing river", {{"west", "town"}}, {"fishing rod"}};
    }

    void move(const string& direction) {
        if (locations[currentLocation].exits.find(direction) != locations[currentLocation].exits.end()) {
            currentLocation = locations[currentLocation].exits[direction];
        } else {
            cout << "You can't go that way.\n";
        }
    }
};

int main() {
    srand(time(nullptr));
    Game game;
    game.start();

    return 0;
}
