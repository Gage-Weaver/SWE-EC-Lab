#include <iostream>
#include <iomanip>
#include <string>
#include <set>
using namespace std; //use the standard namespace to avoid typing std:: everytime
double extractNumeric(const std::string& str) { //define a function to extract the double numeric from user input
    int decimalcount = 0; //set a counter for the amount of decimals inputted
    int numcount = 0; //set a counter for the amount of numbers inputedd
    string result = ""; //set an empty string for the result
    set<char> numberset = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //declare a set to hold the char representation of each number
    
    for (size_t i = 0; i < str.length(); i++) { //for loop over input size
        char singleinput = str[i]; //declare single input as the current character in the string
        
        if (i == 0 && (singleinput == '+' || singleinput == '-')) { //if its the first character and its a + or - add it to the result this is checked with i=0 as any other place is invalid
            result += singleinput; //append the character to the result
            continue; //skip the rest of the loop
        }
        /*
        The below function uses the .find functionality of sets in c++ what it does
        is it iterates the set and tries to find the input character, and if it does it will
        not be equal to the pointer to after the set (numberset.end()) it also checks
        if the input is a decimal rather than a number which is valid also
        */
        
        else if (numberset.find(singleinput) != numberset.end() || singleinput == '.') {
            result += singleinput; //append the input to the result
            if (singleinput == '.') { //if the character is a decimal
                decimalcount ++; //increment decimal count
                if (decimalcount > 1) {
                    return -999999.99; //if we have more than one decimal this is invalid
                }
            }
            else {
                numcount++; //otherwise (didnt hit decimal if statement) increment the numcount
            }
        } 
        else {
            return -999999.99; //if none of the above conditions were hit return invalid
        }
    }
    if (result.length() > 0 && numcount > 0) { //if result is not empty and there is at least one numeric value
        return stod(result); //return stod(result) which converts a string number to a double
    }
    else {
        return -999999.99; //if the result is empty or contains no numeric values return invalid
    }
}
int main() { //define our main function
    string input; //declare a string to hold user input
    while (1) { //while loop forever
        cout << "Enter a string to extract from or type 'END' to quit: "; //prompt input
        cin >> input; //collect input
        if (input == "END") { 
            break; //if the input is END, then terminate the program
        }
        double number = extractNumeric(input); //call our extractNumeric function and store the result in a double variable
        if (number != -999999.99) { //if the number is not the invalid return show the user the output formatted in a nice way according to the problem statement
            cout << "Input is: " << fixed << setprecision(4) << number << endl;
        }
        else { //if the input was invalid for any reason let the user know
            cout << "Invalid Input" << endl;
        }
    }
}