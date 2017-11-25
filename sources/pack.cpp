#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};

Person getInfo() {
	class Person file;
  file.first_name = "Sergey";
	file.last_name = "Borovkov";
	file.email.nickname = "sergborovkov@gmail.com";
	file.age = 23;
	file.phone = "8(800)555-35-35";
	return file;
}


int main(int argc, char* argv[]) {
  string Path = argv[1];
  Person Pers;
  ofstream fout(Path);

  Pers = getInfo();
  json j;
  j["first_name"] = Pers.first_name;
  j["last_name"] = Pers.last_name;
  j["email_nickname"] = Pers.email.nickname;
  j["age"] = Pers.age;
  j["phone"] = Pers.phone;
  fout << j;
  fout.close();
  return 0;
}
