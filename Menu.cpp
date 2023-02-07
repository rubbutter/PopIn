#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*This program defines a struct MenuItem that contains the name and price of a menu item. 
In the main function, it creates an empty vector of MenuItem, and then it opens a file called "menu.txt" using an ifstream object. 
If the file is successfully opened, it reads the file line by line and uses the std::getline function to read each line of the file into a string variable called line.
 Then it uses the std::string::find method to find the position of the delimiter (",") in the line. 
 Next, it uses the std::string::substr method to extract the name and price from the line. Finally, it pushes the MenuItem object into the vector.
Once the reading is done, it closes the file and iterates the vector and prints the menu items.*/

struct MenuItem {
    std::string name;
    double price;
};

int main() {
    std::vector<MenuItem> menu;
    std::string line;

    std::ifstream menuFile("menu.txt");
    if (!menuFile.is_open()) {
        std::cout << "Failed to open menu file" << std::endl;
        return 1;
    }

    while (std::getline(menuFile, line)) {
        // Split line into name and price
        std::size_t delimiterPos = line.find(",");
        std::string name = line.substr(0, delimiterPos);
        double price = std::stod(line.substr(delimiterPos + 1));

        // Add menu item to vector
        menu.push_back({name, price});
    }

    menuFile.close();

    // Print menu
    std::cout << "Menu:" << std::endl;
    for (const auto& item : menu) {
        std::cout << item.name << " - $" << item.price << std::endl;
    }

    return 0;
}

