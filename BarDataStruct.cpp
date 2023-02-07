#include <iostream>
#include <vector>
#include <algorithm>

/*The provided code is an implementation of a program that sorts a list of bars by rating, price, and distance.
 It defines a struct Bar which holds the data for each bar, including the bar name, rating, price, and distance. 
 The program then sorts the std::vector of Bar objects in three different ways, each time using a different sorting function (sortByRating, sortByPrice, and sortByDistance) 
 and prints out the sorted list of bars. The sorting functions are implemented using a lambda function and the std::sort algorithm. 
 The provided code is a valid implementation, although it could be made more concise by using a lambda function directly instead of defining separate sorting functions.*/

// Using the standard namespace to reduce the amount of code required
using namespace std;

// Define a struct 'Bar' that holds information about a bar
struct Bar {
    string name; // name of the bar
    double rating; // rating of the bar
    double price; // average price per drink at the bar
    double distance; // distance from some location
};

// A comparison function that compares the rating of two bars
// Used to sort the bars by rating
bool sortByRating(const Bar& a, const Bar& b) {
    return a.rating > b.rating;
}

// A comparison function that compares the price of two bars
// Used to sort the bars by price
bool sortByPrice(const Bar& a, const Bar& b) {
    return a.price < b.price;
}

// A comparison function that compares the distance of two bars
// Used to sort the bars by distance
bool sortByDistance(const Bar& a, const Bar& b) {
    return a.distance < b.distance;
}

int main() {
// Initialize a vector of bars with example data
    vector<Bar> bars = {
    {"Bar 1", 4.5, 10.0, 2.5},
    {"Bar 2", 4.0, 15.0, 3.0},
    {"Bar 3", 3.5, 12.0, 1.5},
    {"Bar 4", 4.0, 8.0, 2.0},
    {"Bar 5", 3.0, 20.0, 4.0},
    {"Bar 6", 4.2, 14.0, 3.2},
    {"Bar 7", 4.7, 9.0, 1.7},
    {"Bar 8", 3.9, 16.0, 2.9},
    {"Bar 9", 3.8, 11.0, 2.8},
    {"Bar 10", 4.1, 15.0, 3.1},
    {"Bar 11", 3.7, 12.0, 2.7},
    {"Bar 12", 3.5, 17.0, 4.5},
    {"Bar 13", 4.3, 13.0, 2.3},
    {"Bar 14", 3.2, 19.0, 5.2},
    {"Bar 15", 4.6, 10.0, 1.6}
};

int sort_choice;

cout << "Choose the attribute to sort the bars by:" << endl;
cout << "1. Rating" << endl;
cout << "2. Price" << endl;
cout << "3. Distance" << endl;
cin >> sort_choice;

    switch (sort_choice) {
        case 1:
            cout << "Bars sorted by rating:" << endl;
            sort(bars.begin(), bars.end(), sortByRating);
            for (const auto& bar : bars) {
                cout << bar.name << " - Rating: " << bar.rating << endl;
            }
        break;

        case 2:
            cout << "Bars sorted by price:" << endl;
            sort(bars.begin(), bars.end(), sortByPrice);
            for (const auto& bar : bars) {
                cout << bar.name << " - Price: $" << bar.price << endl;
            }
        break;

        case 3:
            cout << "Bars sorted by distance:" << endl;
            sort(bars.begin(), bars.end(), sortByDistance);
        for (const auto& bar : bars) {
            cout << bar.name << " - Distance: " << bar.distance << " miles" << endl;
        }
        break;

        default:
            cout << "Invalid choice" << endl;

    return 0;
    }
    
    return 0;
}