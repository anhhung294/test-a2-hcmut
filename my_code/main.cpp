#include "knight2.h"

int main(int argc, char ** argv) {
    string file_armyknights, file_events;
    int std_id = 0;
    if (argc == 1) {
        file_armyknights = "tc1_armyknights"; // hard-code
        file_events = "tc1_events";
    }
    else if (argc == 4) {
        file_armyknights = argv[1];
        file_events = argv[2];
        std_id = atoi(argv[3]);
    }
    else {
        cout << "Error number of arguments" << endl;
        exit(1);
    }
    string path{};

    if(std_id){
        path = "../src/uploads/mssv"+to_string(std_id)+"/result.txt";
        file_armyknights = "../src/uploads/mssv" + to_string(std_id) + "/knights.txt";
        file_events = "../src/uploads/mssv" + to_string(std_id) + "/events.txt";
    }else{
        path = "./result.txt";
    }
    const char* cpath = path.c_str();
    freopen(cpath, "a", stdout);
    // BEBGIN
    KnightAdventure * knightAdventure = new KnightAdventure();
    knightAdventure->loadArmyKnights(file_armyknights);
    knightAdventure->loadEvents(file_events);
    knightAdventure->run();
    
    delete knightAdventure;
    knightAdventure = nullptr;
    return 0;
}