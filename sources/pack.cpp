#include "pugixml.hpp"
#include <iostream>


struct Email {
    std::string nickname;
    std::string server;
};

struct Person {
    std::string first_name;
    std::string last_name;
    Email email;
    size_t age;
    std::string phone;
};


std::istream &operator>>(std::istream &is, Email &obj) {
    std::string BUFF;

    is >> BUFF;

    size_t i = BUFF.find_first_of('@');

    if (i >= 0) {
        obj.nickname = BUFF.substr(0, i);
        obj.server = BUFF.substr(i + 1, BUFF.size());
    }

    return is;
}

std::istream &operator>>(std::istream &is, Person &obj) {
    std::cout << "Enter data to fields of the Person structure." << std::endl;
    std::cout << "First name: ";
    is >> obj.first_name;
    std::cout << "Last name: ";
    is >> obj.last_name;
    std::cout << "Email: ";
    is >> obj.email;
    std::cout << "Age(optional): ";
    std::string age;
    std::cin.ignore();
    std::getline(is, age);
    if (!age.empty() && std::stoi(age) > 0)
        obj.age = std::stoi(age);
    else obj.age = 0;
    std::cout << "Phone(optional): ";
    std::getline(is, obj.phone);
    return is;
}

void SaveToFile(const Person &st, const char *path) {
    pugi::xml_document doc;

    pugi::xml_node node = doc.append_child("Person");

    pugi::xml_node first_name = node.append_child("first_name");
    first_name.append_child(pugi::node_pcdata).set_value(st.first_name.c_str());

    pugi::xml_node last_name = node.append_child("last_name");
    last_name.append_child(pugi::node_pcdata).set_value(st.last_name.c_str());

    pugi::xml_node node2 = node.append_child("Email");

    pugi::xml_node nickname = node2.append_child("nickname");
    nickname.append_child(pugi::node_pcdata).set_value(st.email.nickname.c_str());

    pugi::xml_node server = node2.append_child("server");
    server.append_child(pugi::node_pcdata).set_value(st.email.server.c_str());

    pugi::xml_node age = node.append_child("age");
    age.append_child(pugi::node_pcdata).set_value((std::to_string(st.age)).c_str());

    pugi::xml_node phone = node.append_child("phone");
    phone.append_child(pugi::node_pcdata).set_value(st.phone.c_str());

    std::cout << path;
    doc.save_file(path);
}

int main(int argc, char *argv[]) {
    char* path = argv[1];

    Person pr;
    std::cin >> pr;



    SaveToFile(pr, path);
    return 0;
}
