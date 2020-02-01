/**
    ECE250
    dequedriver.cpp
    Purpose: Provides commands such as creating a deque and inserting/removing data from it

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/


#include <iostream>
#include "Deque.h"
#include <sstream>
#include <exception>

bool has_space(const std::string& str);

/**
exception class with "failure" as error message
*/
class deque_empty: public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "failure";
    }
} empty_exp;

/**
main class handling user commands outputs
*/
int main() {

        Deque deque;
        std::string user_command;
        int user_param;
        std::string line;

        do {
            if (!std::getline(std::cin, line) || line.empty()) { // stops asking for input once it reaches EOF
                break;
            } else {
                std::istringstream iss(line);
                iss >> user_command;

                if (has_space(line)) {  // storing user parameter in a separate variable
                    iss >> user_param;
                }

                try { // different user commands
                    if (user_command == "enqueue_front") {

                        deque.enqueue_front(user_param);
                        std::cout << "success" << std::endl;

                    } else if (user_command == "enqueue_back") {

                        deque.enqueue_back(user_param);
                        std::cout << "success" << std::endl;

                    } else if (user_command == "dequeue_front") {

                        if (deque.is_empty()) {
                            throw empty_exp;
                        } else {
                            deque.dequeue_front();
                            std::cout << "success" << std::endl;
                        }

                    } else if (user_command == "dequeue_back") {

                        if (deque.is_empty()) {
                            throw empty_exp;
                        } else {
                            deque.dequeue_back();
                            std::cout << "success" << std::endl;
                        }

                    } else if (user_command == "clear") {

                        if (!deque.is_empty()) {
                            deque.clear();
                        }
                        std::cout << "success" << std::endl;

                    } else if (user_command == "front") {

                        if (deque.is_empty() || deque.get_front() != user_param) {
                            throw empty_exp;
                        } else {
                            std::cout << "success" << std::endl;
                        }

                    } else if (user_command == "back") {

                        if (deque.is_empty() || deque.get_back() != user_param) {
                            throw empty_exp;
                        } else {
                            std::cout << "success" << std::endl;
                        }

                    } else if (user_command == "empty") {

                        if (deque.is_empty()) {
                            std::cout << "success" << std::endl;
                        } else {
                            throw empty_exp;
                        }

                    } else if (user_command == "size") {

                        std::cout << "size is " << deque.get_size() << std::endl;

                    } else if (user_command == "print") {

                        if (!deque.is_empty()) {
                            deque.print_forward();
                            deque.print_backward();
                        }
                    }
                } catch (deque_empty& exception){
                    std::cout << exception.what() << std::endl;
                }
            }

        } while (true);

    return 0;
}

/**
Determines if the user input contains a parameter
by checking if there are any empty spaces in the command
*/
bool has_space(const std::string& str) {
    for (int c : str) {
        if (isspace(c))
            return true;
    }
    return false;
}