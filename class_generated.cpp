#include <iostream>
#include <string>
#include <vector>

// Assuming FVector is a class with x, y, z coordinates
class FVector {
public:
    float x, y, z;

    FVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
};

class GameObject {
protected:
    std::string name;
    std::string description;
    FVector coordinates;
    int interactRadius;
    std::string uniqueString;

public:
    GameObject(std::string n, std::string d, FVector c, int ir, std::string u) : name(n), description(d), coordinates(c), interactRadius(ir), uniqueString(u) {}

    virtual void respondToInteraction(std::string string) {
        if (string == uniqueString) {
            std::cout << "You interacted with " << name << ".\n";
        } else {
            std::cout << "Nothing happens.\n";
        }
    }
};

class SpecificGameObject1 : public GameObject {
public:
    SpecificGameObject1(std::string n, std::string d, FVector c, int ir, std::string u) : GameObject(n, d, c, ir, u) {}

    void respondToInteraction(std::string string) override {
        if (string == uniqueString) {
            std::cout << "You did something unique with " << name << ".\n";
        } else {
            std::cout << "Nothing happens.\n";
        }
    }
};

class SpecificGameObject2 : public GameObject {
public:
    SpecificGameObject2(std::string n, std::string d, FVector c, int ir, std::string u) : GameObject(n, d, c, ir, u) {}

    void respondToInteraction(std::string string) override {
        if (string == uniqueString) {
            std::cout << "You did another unique thing with " << name << ".\n";
        } else {
            std::cout << "Nothing happens.\n";
        }
    }
};

class Player {
private:
    std::string name;
    std::string currentString;
    FVector coordinates;
    std::vector<GameObject*> inventory;

public:
    Player(std::string n, FVector c) : name(n), coordinates(c) {}

    void addToInventory(GameObject* obj) {
        inventory.push_back(obj);
    }

    void interact(std::string string) {
        currentString = string;
        for (auto& obj : inventory) {
            // Check if player is within the interaction radius
            if (obj->interactRadius >= sqrt(pow(obj->coordinates.x - coordinates.x, 2) + pow(obj->coordinates.y - coordinates.y, 2) + pow(obj->coordinates.z - coordinates.z, 2))) {
                obj->respondToInteraction(currentString);
            }
        }
    }
};
