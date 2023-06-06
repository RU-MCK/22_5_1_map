#include <iostream>
#include <string>
#include <map>

void find(std::map<std::string, std::string> &book, std::string &request, int temp) {
  for (auto &item : book) {
    if (temp == 2) {
      if (request == item.first)
        std::cout << item.second << std::endl;
    } else if (request == item.second)
      std::cout << item.first << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::map<std::string, std::string> phonebook;
  int command = 5;
  do {
    std::cout << "Add the phone number and last name of the subscriber to the directory enter-< 1 > " << std::endl
              << "Find out the name of the subscriber by phone number enter-------------------< 2 > " << std::endl
              << "Find out the phone number of the subscriber by last name--------------------< 3 > " << std::endl
              << "For print Phone Book enter--------------------------------------------------< 4 > " << std::endl
              << "For exit enter--------------------------------------------------------------< 0 > " << std::endl;
    std::cin >> command;
    std::string lastname;
    std::string number;
    switch (command) {
      case 0:std::cout << "Exit";
        break;
      case 1:std::cout << "Enter phone number <99-99-99> :" << std::endl;
        std::cin >> number;
        std::cout << "Enter last name:" << std::endl;
        std::cin >> lastname;
        phonebook.insert(std::pair<std::string, std::string>(number, lastname));
        break;
      case 2:std::cout << "Enter phone number <99-99-99> :" << std::endl;
        std::cin >> number;
        find(phonebook, number, command);
        break;
      case 3:std::cout << "Enter last name:" << std::endl;
        std::cin >> lastname;
        find(phonebook, lastname, command);
        break;
      case 4:
        if (!phonebook.empty()) {
          for (auto &item : phonebook)
            std::cout << item.first << " " << item.second << std::endl;
        } else
          std::cout << "Phone book is empty!" << std::endl;
        break;
      default:std::cout << "Enter error!" << std::endl;
        break;
    }
  } while (command != 0);
  return 0;
}
