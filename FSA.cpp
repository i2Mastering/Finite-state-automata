// Finite State Automaton (FSA) Implementation in C++
// Author: Ike Iloegbu

#include <iostream>
#include <string>

/**
 * A class representing a Finite State Automaton (FSA) that processes input strings
 * consisting of the characters {a, b, c} and determines whether the string is accepted.
 */
class FSA {
private:
    /**
     * Enumeration representing the possible states of the automaton.
     */
    enum State { Start, dotA, dotB, dotBB, retT, retF };

public:
    State currentState = Start; ///< The current state of the automaton.

    /**
     * Processes a single character and transitions between states accordingly.
     *
     * @param c The character to process.
     * @return True if the automaton reaches a terminal state (accepted or rejected), false otherwise.
     */
    bool ProcessChar(char c) {
        switch (currentState) {
            case Start:
                if (c == 'a') {
                    currentState = dotA;
                } else if (c == 'b') {
                    currentState = dotB;
                } else if (c == '.') {
                    currentState = retF;
                } else {
                    currentState = retF;
                }
                break;
            case dotA:
                if (c == 'a' || c == 'b') {
                    currentState = dotA;
                } else if (c == '.') {
                    currentState = retT;
                } else {
                    currentState = retF;
                }
                break;
            case dotB:
                if (c == 'b') {
                    currentState = dotBB;
                } else {
                    currentState = retF;
                }
                break;
            case dotBB:
                if (c == 'a') {
                    currentState = dotBB;
                } else if (c == 'b') {
                    currentState = retF;
                } else if (c == '.') {
                    currentState = retT;
                } else {
                    currentState = retF;
                }
                break;
            default:
                break;
        }
        return (currentState == retT) || (currentState == retF);
    }

    /**
     * Checks if the string is accepted based on the final state.
     *
     * @return True if the string is accepted, false otherwise.
     */
    bool IsAccepted() const {
        return currentState == retT;
    }
};

/**
 * Main function that prompts the user for input, processes the string using the FSA,
 * and prints whether the string is accepted or rejected.
 *
 * @return 0 upon successful execution.
 */
int main() {
    FSA fsa;
    std::string input;

    std::cout << "Enter a string (alphabet {a, b, c}) followed by '.': ";
    std::cin >> input;
    
    for (char c : input) {
        if (fsa.ProcessChar(c)) {
            if (fsa.IsAccepted()) {
                std::cout << "String is accepted!" << std::endl;
            } else {
                std::cout << "String is not accepted!" << std::endl;
            }
            break;
        }
    }
    return 0;
}
