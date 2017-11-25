#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Email {
  string nickname;
  string server;
};

struct Person {
  string  first_name;
  string  last_name;
  Email   email;
  size_t  age;
  string  phone;
};

int main(int argc, char* argv[]) {
  string Path = argv[1];
  struct Person Back;
  json j;
  ifstream f;
  f.open(Path);
  f >> j;
  f.close();
  Back.first_name = j.at("first_name").get<std::string>();
  Back.last_name = j.at("last_name").get<std::string>();
  Back.email.nickname = j.at("email_nickname").get<std::string>();
  Back.age  = j.at("age").get<size_t>();
  Back.phone  = j.at("phone").get<std::string>();



  cout << "[Person]" << endl;
  cout << "First name: " << Back.first_name << endl;
  cout << "Last name: " << Back.last_name << endl;
  cout << "Email_nickname: " << Back.email.nickname << endl;
  cout << "Age: " << Back.age << endl;
  cout << "Phone: " << Back.phone << endl;

  return 0;
}
